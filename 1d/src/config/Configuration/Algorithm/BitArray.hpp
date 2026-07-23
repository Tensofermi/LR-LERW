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
        // std::cout<< (m_bits[index >> SHIFT] & (1U << (index & MASK))) << std::endl;
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


// 将 (x) 映射到一维 BitArray 索引
inline size_t coordToIndex(int x, int L) {
    if(x < -L || x > L)
    {
        std::cout<<" x = "<<x<<std::endl;
    }

    assert(x >= -L && x <= L);
    return static_cast<size_t> (x + L);
}
