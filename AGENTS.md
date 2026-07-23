# Repository guide for agents

This file applies to the whole repository. It explains the long-range loop-erased random walk, dimension-specific trees, parameter planning, and adaptation of the Zoo workflow.

## Scientific purpose

The code generates a long-range random walk with jump tail

$$P(r)\propto r^{-(D+\sigma)},$$

then erases loops chronologically whenever a site is revisited. The resulting self-avoiding path is a long-range loop-erased random walk (LR-LERW). `sigma` tunes nonlocality, `D` selects spatial dimension, and `L` is the maximum-norm exit radius.

Loop erasure turns an ordinary stochastic path into a geometrically nontrivial object related to spanning-tree paths and critical geometry. Comparing LR-LERW with `LR_RW` isolates how chronological loop removal changes path dimension, erased-loop statistics, and crossover between long-range and short-range behavior.

The primary observables are `Len_R`, the retained loop-erased length at threshold radius `R`, and `Lop_R`, the number of erased steps accumulated by that threshold, together with squared moments. Thresholds are powers of two from 8 through 32768. Some dimension trees may contain additional historical diagnostics; read their `Observable_config.hpp` rather than assuming identical columns.

## Dimension-specific source trees and invariants

- `1d/src` through `5d/src` are independent implementations specialized by coordinate type/dimension.
- `<dim>d/src/config/Inputor_config.hpp` requires input `D` to match the selected tree and validates `sigma`, `L`, and sampling controls.
- `<dim>d/src/config/Configuration/UpdataScheme.cpp` defaults to `LERW_LR()`.
- The algorithm maintains both the chronological path and a site-to-position lookup. On revisiting a site, all later vertices must be removed consistently from both structures.

The historical pop/remove ordering should remain robust: read any element before `pop_back()`. Coordinate and jump accumulation must use wide checked integers; validate a heavy-tailed proposal before any integer cast or addition. These are safety fixes and should not be used by themselves to invalidate historical release data, but future code must not rely on invalidated vector elements.

Arbitrary positive `L` now terminates once the maximum-norm radius reaches/exceeds `L`. However, only predefined thresholds have dedicated output columns. For scaling campaigns, use implemented powers of two or extend the threshold arrays, parameter labels, assignment logic, observable registration, and tests together.

## Build and single-run workflow

The Makefile defaults to `1d/src`. Select one dimension explicitly and clean between dimensions:

```bash
make clean
make -j SRC_DIR=3d/src
make test SRC_DIR=3d/src
./bin/a.out
```

Ensure root `input.txt` has matching `D`; a 3D binary must receive `D=3`. The model fields are `D,sigma,L`, followed by `Seed,N_Measure,N_Each,N_Therm,N_Total,NBlock,MaxNBin,NperBin`. The result file is `ouput.txt`.

Each update creates a fresh walk, so `N_Therm=0` is normally appropriate; verify the main loop if that architecture changes. `N_Each` and `N_Total` control the number of walk samples/blocks. Smoke tests must cover a small power-of-two `L`, an arbitrary non-tabulated `L`, a small sigma, and the largest practical jump range; verify exit, loop-map consistency, finite values, and absence of overflow diagnostics.

## Parameter planning

1. Choose one `D` and compile its source tree. Split campaigns by dimension.
2. Choose sigma values spanning strongly long-range through short-range-like behavior, with extra points near predicted crossover/marginal values.
3. Use geometric/power-of-two `L` so direct `Len_L` and `Lop_L` columns exist. Start at small sizes and extend only after timing/memory pilots.
4. Use many independent Seeds. Heavy-tailed jumps and loop erasure can produce broad distributions, so compare first and second moments and inspect anomalous outliers.
5. Estimate the fractal/growth exponent from fits such as $\langle\mathrm{Len}_L\rangle\sim L^{d_f}$ with correction terms and several `L_min`. Analyze erased length separately rather than assuming it has the same exponent.

For a concrete study, hold `D` and sigma fixed, use `L=64,128,256,512,1024,...`, and measure effective slopes between neighboring sizes before a global fit. Add sizes and statistics until the effective slope/correction trend is resolved. A dense sigma scan at only two sizes cannot distinguish crossover from asymptotic behavior.

Rare huge jumps can make runtime and overflow risk sigma-dependent. Time the largest planned `L` at each extreme sigma and size scheduler requests using upper-tail runtimes.

## Adapting the Zoo pipeline

Clone and copy the reference workflow:

```bash
git clone --depth 1 https://github.com/Tensofermi/Zoo_of_Classical_ON_Spin_Model.git ../Zoo_of_Classical_ON_Spin_Model
cp -R ../Zoo_of_Classical_ON_Spin_Model/lsub .
cp -R ../Zoo_of_Classical_ON_Spin_Model/qsub .
cp -R ../Zoo_of_Classical_ON_Spin_Model/data .
cp -R ../Zoo_of_Classical_ON_Spin_Model/fit .
cp -R ../Zoo_of_Classical_ON_Spin_Model/plot .
```

Required repository adaptations are:

- Replace Zoo model arrays with `D,sigma,L`, in that exact order, followed by the eight sampling fields.
- Generate matching input labels and a job name containing `D`, `sigma`, `L`, and Seed.
- Split task generation by dimension. Build with `SRC_DIR=<D>d/src`, clean first, and give jobs an immutable dimension-specific executable. A single binary cannot safely serve a Cartesian product containing several `D` values.
- Remove thermal-model assumptions from parameter names and resource estimates; these jobs sample independent paths rather than equilibrium temperatures.
- Update PBS/Slurm queue/account/partition, modules, memory, wall time, and local concurrency using pilot data.

The formatted model order is `D,sigma,L`. Set `header=10` and the 1-based `seed_index=6`; zero-based model columns are `D=0`, `sigma=1`, `L=2`. Inspect one formatted result per dimension because observable sets can differ. Configure splitting/grouping to combine only identical `D,sigma,L` points across Seeds.

Replace Zoo's thermodynamic fitting functions with log-log path-length/erasure fits. Select `Len_<L>` or `Lop_<L>` from header names, use its paired error column, update paths, fit range, corrections, bounds, labels, and cutoff scan. Because one run can fill multiple threshold columns up to its stopping `L`, decide explicitly whether analysis uses only the terminal column or correlated nested thresholds; do not treat nested measurements from one walk as independent data.

## Production workflow

1. Record `D`, source tree, sigma list, power-of-two sizes, Seeds, target observables/exponents, and correction hypotheses.
2. Build/test that dimension and run both tabulated and arbitrary-`L` smoke tests.
3. Generate one local/scheduler task; inspect input, immutable executable, resource directives, and output.
4. Pilot extreme sigma/size points, adjust statistics and resources, then submit production.
5. Format/collect/split/compress; verify row counts, columns, and Seed-only combination per dimension.
6. Fit effective/global exponents with cutoff scans, account for nested-threshold correlations, and compare with LR-RW where appropriate.

Archive commit, dimension tree, threshold table, parameter generator, jump convention, compiler, scheduler settings, Seeds, raw output, and analysis environment.

## Change and verification policy

- Run `make test` for every dimension changed; shared conceptual changes require all five trees.
- Add tests for revisit erasure, lookup/path synchronization, non-tabulated stopping radii, huge jumps, integer bounds, and deterministic seeded smoke cases.
- Treat jump-distribution, discretization, threshold, loop-erasure, or RNG-order changes as result-changing and document data compatibility.
- Keep Markdown formulas as `$...$` or `$$...$$`.
- Do not commit binaries, jobs, or bulk data unless requested. Keep commits focused and state motivation, implementation, validation, and scientific effect.
