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
    string_head = 0;
    string.push_back(string_head);
    visited_bit.set(coordToIndex(string_head, L_max + 1));

    while (true)
    {
        double u = rn.getRandomDouble();
        if (u == 0.0) u = 1.0;
        long double raw_step = std::floor(0.5L * std::pow(static_cast<long double>(u),
            -1.0L / static_cast<long double>(Sigma)) + 0.5L);
        if (rn.getRandomDouble() < 0.5) raw_step = -raw_step;

        if (!std::isfinite(raw_step) ||
            raw_step < static_cast<long double>(std::numeric_limits<std::int64_t>::min()) ||
            raw_step > static_cast<long double>(std::numeric_limits<std::int64_t>::max()))
        {
            record_crossings(L_max);
            return;
        }
        const std::int64_t candidate = static_cast<std::int64_t>(string_head) +
            static_cast<std::int64_t>(raw_step);
        if (candidate <= -static_cast<std::int64_t>(L_max) ||
            candidate >= static_cast<std::int64_t>(L_max))
        {
            record_crossings(L_max);
            return;
        }
        string_head = static_cast<int>(candidate);

        if (visited_bit.test(coordToIndex(string_head, L_max + 1)))
        {
            while (string_head != string.back())
            {
                visited_bit.reset(coordToIndex(string.back(), L_max + 1));
                string.pop_back();
                --length_string;
            }
        }
        else
        {
            string.push_back(string_head);
            ++length_string;
            visited_bit.set(coordToIndex(string_head, L_max + 1));
        }
        ++complete_length_string;
        record_crossings(std::abs(string_head));
    }
}
