#include "../Configuration.hpp"
#include "BitArray.hpp"

void Configuration::LERW_LR()
{
    const std::vector<int> thresholds = {8, 16, 32, 64, 128, 256, 512,
        1024, 2048, 4096, 8192, 16384, 32768};
    const std::vector<int> len_indices = {
        para.i_Len_8, para.i_Len_16, para.i_Len_32, para.i_Len_64,
        para.i_Len_128, para.i_Len_256, para.i_Len_512, para.i_Len_1024,
        para.i_Len_2048, para.i_Len_4096, para.i_Len_8192,
        para.i_Len_16384, para.i_Len_32768};
    std::vector<bool> recorded(thresholds.size(), false);
    const auto record_crossings = [&](int distance) {
        for (std::size_t i = 0; i < thresholds.size(); ++i)
        {
            if (!recorded[i] && thresholds[i] <= distance && thresholds[i] <= L_max)
            {
                recorded[i] = true;
                obs.Ob[len_indices[i]] = length_string;
            }
        }
    };

    length_string = 0;
    complete_length_string = 0;
    string.clear();
    visited_bit.resetAll();
    string_head = {0, 0};
    string.push_back(string_head);
    visited_bit.set(coordToIndex(0, 0, L_max + 1));

    while (true)
    {
        double u, v, w;
        do
        {
            u = rn.getRandomDouble();
            v = rn.getRandomDouble();
            if (u == 0.0) u = 1.0;
            if (v == 0.0) v = 1.0;
            w = u * u + v * v;
        } while (w >= 1.0);
        const long double factor = 1.0L / std::pow(static_cast<long double>(w),
            0.5L + 1.0L / static_cast<long double>(Sigma));
        std::array<long double, 2> raw_step = {
            std::floor(0.5L * std::sqrt(2.0L) * u * factor + 0.5L),
            std::floor(0.5L * std::sqrt(2.0L) * v * factor + 0.5L)};
        if (rn.getRandomDouble() < 0.5) raw_step[0] = -raw_step[0];
        if (rn.getRandomDouble() < 0.5) raw_step[1] = -raw_step[1];

        std::array<int, 2> candidate{};
        bool exits = false;
        for (std::size_t i = 0; i < candidate.size(); ++i)
        {
            if (!std::isfinite(raw_step[i]) ||
                raw_step[i] < static_cast<long double>(std::numeric_limits<std::int64_t>::min()) ||
                raw_step[i] > static_cast<long double>(std::numeric_limits<std::int64_t>::max()))
            {
                exits = true;
                break;
            }
            const std::int64_t value = static_cast<std::int64_t>(string_head[i]) +
                static_cast<std::int64_t>(raw_step[i]);
            if (value <= -static_cast<std::int64_t>(L_max) ||
                value >= static_cast<std::int64_t>(L_max))
            {
                exits = true;
                break;
            }
            candidate[i] = static_cast<int>(value);
        }
        if (exits)
        {
            record_crossings(L_max);
            return;
        }
        string_head = candidate;

        if (visited_bit.test(coordToIndex(string_head[0], string_head[1], L_max + 1)))
        {
            while (string_head != string.back())
            {
                const std::array<int, 2> removed = string.back();
                visited_bit.reset(coordToIndex(removed[0], removed[1], L_max + 1));
                string.pop_back();
                --length_string;
            }
        }
        else
        {
            string.push_back(string_head);
            ++length_string;
            visited_bit.set(coordToIndex(string_head[0], string_head[1], L_max + 1));
        }
        ++complete_length_string;
        record_crossings(std::max(std::abs(string_head[0]), std::abs(string_head[1])));
    }
}
