#include "config/Configuration/Algorithm/BitArray.hpp"
#include "system/RandomNumGen/RandomNumGen.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <stdexcept>

int main()
{
    const std::uint32_t expected[] = {
        3120687069u, 648888036u, 180407624u, 258054113u,
        2602618097u, 573297273u, 555146359u, 1664810582u};
    RandomNumGen rng(1234);
    for (std::size_t i = 0; i < sizeof(expected) / sizeof(expected[0]); ++i)
        assert(static_cast<std::uint64_t>(rng.getRandomDouble() * 4294967296.0) == expected[i]);

    BitArray bits(65);
    bits.set(0);
    bits.set(64);
    assert(bits.test(0) && bits.test(64));
    bits.reset(64);
    assert(!bits.test(64));
    bool rejected = false;
    try { bits.set(65); } catch (const std::out_of_range&) { rejected = true; }
    assert(rejected);
    std::cout << "common regression tests passed\n";
}
