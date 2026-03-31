#pragma once
#include <iostream>
#include <vector>
#include <cstddef>
#include <cassert>

class BitArray
{
public:
    static const size_t BITS_PER_UNIT = sizeof(unsigned int) * 8;
    static const size_t SHIFT = __builtin_ctz(BITS_PER_UNIT); // Computes the number of trailing zeros in BITS_PER_UNIT
    static const unsigned int MASK = BITS_PER_UNIT - 1;

    BitArray(size_t size)
        : m_bits((size + BITS_PER_UNIT - 1) >> SHIFT, 0) {} // Use bit shift for size calculation

    void initialize(size_t size)
    {
        m_bits.resize((size + BITS_PER_UNIT - 1) >> SHIFT, 0);
    }

    void set(size_t index)
    {
        m_bits[index >> SHIFT] |= (1U << (index & MASK));
    }

    void reset(size_t index)
    {
        m_bits[index >> SHIFT] &= ~(1U << (index & MASK));
    }

    void resetAll()
    {
        std::fill(m_bits.begin(), m_bits.end(), 0);
    }

    bool test(size_t index) const
    {
        return (m_bits[index >> SHIFT] & (1U << (index & MASK))) != 0;
    }

    size_t memorySize() const
    {
        return sizeof(BitArray) + (m_bits.capacity() * sizeof(unsigned int));
    }

private:
    std::vector<unsigned int> m_bits;
};


// 将 (x, y) 映射到一维 BitArray 索引
inline size_t coordToIndex(int x, int y, int L) {
    int WIDTH = 2 * L + 1;
    if(x < -L || x > L)
    {
        std::cout<<" x = "<<x<<std::endl;
    }
    if(y < -L || y > L)
    {
        std::cout<<" y = "<<x<<std::endl;
    }
    assert(x >= -L && x <= L);
    assert(y >= -L && y <= L);
    return static_cast<size_t>(y + L) * WIDTH + (x + L);
}