#pragma once
#include <iostream>
#include <vector>
#include <cstddef>
#include <cassert>
#include <stdexcept>

class BitArray
{
public:
    static const size_t BITS_PER_UNIT = sizeof(unsigned int) * 8;
    BitArray(size_t size)
        : m_bits((size + BITS_PER_UNIT - 1) / BITS_PER_UNIT, 0), m_size(size) {}

    void initialize(size_t size)
    {
        m_bits.assign((size + BITS_PER_UNIT - 1) / BITS_PER_UNIT, 0);
        m_size = size;
    }

    void set(size_t index)
    {
        if (index >= m_size) throw std::out_of_range("BitArray::set");
        m_bits[index / BITS_PER_UNIT] |= (1U << (index % BITS_PER_UNIT));
    }

    void reset(size_t index)
    {
        if (index >= m_size) throw std::out_of_range("BitArray::reset");
        m_bits[index / BITS_PER_UNIT] &= ~(1U << (index % BITS_PER_UNIT));
    }

    void resetAll()
    {
        std::fill(m_bits.begin(), m_bits.end(), 0);
    }

    bool test(size_t index) const
    {
        if (index >= m_size) throw std::out_of_range("BitArray::test");
        return (m_bits[index / BITS_PER_UNIT] & (1U << (index % BITS_PER_UNIT))) != 0;
    }

    size_t memorySize() const
    {
        return sizeof(BitArray) + (m_bits.capacity() * sizeof(unsigned int));
    }

private:
    std::vector<unsigned int> m_bits;
    size_t m_size;
};


// 将 (x, y, z) 映射到一维 BitArray 索引
inline size_t coordToIndex(int x, int y, int z, int L) {
    int WIDTH = 2 * L + 1;
    assert(x >= -L && x <= L);
    assert(y >= -L && y <= L);
    assert(z >= -L && z <= L);
    // 三维索引公式: (z + L) * (WIDTH^2) + (y + L) * WIDTH + (x + L)
    size_t layerSize = static_cast<size_t>(WIDTH) * WIDTH; // 每层(z)的大小
    return static_cast<size_t>(z + L) * layerSize 
         + static_cast<size_t>(y + L) * WIDTH 
         + static_cast<size_t>(x + L);
}
