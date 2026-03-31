# LR_LERW

This Monte Carlo simulation program provides a numerical implementation of **long-range loop-erased random walks (LR-LERW)**.

A long-range loop-erased random walk is generated in two steps:

1. Propose a long-range jump according to a heavy-tailed distribution.
2. Erase loops chronologically whenever the walk revisits a previous site.

For long-range jumps in $d$ dimensions, the step-length distribution is

$$
P(r) \sim \frac{1}{r^{d + \sigma}},
$$

where $r$ is the jump length and $\sigma > 0$ controls the tail weight.

---

## How to use

1. **Clone the repository:**
    ```bash
    git clone https://github.com/Tensofermi/LR-LERW
    cd LR-LERW
    ```

2. **Configure model selection** in the `Makefile`:
    ```make
    SRC_DIR := 1d/src
    # SRC_DIR := 2d/src
    # SRC_DIR := 3d/src
    # SRC_DIR := 4d/src
    # SRC_DIR := 5d/src
    ```
    Uncomment the desired model and comment out the others.

3.  Set parameters in `input.txt` and run the simulation:
    ```
    ./run.sh
    ```

4. For advanced simulations, including job submissions on HPC systems, refer to the `/lsub`, `/qsub` and `/data` directories in our related project:  [Zoo_of_Classical_ON_Spin_Model.](https://github.com/Tensofermi/Zoo_of_Classical_ON_Spin_Model)


