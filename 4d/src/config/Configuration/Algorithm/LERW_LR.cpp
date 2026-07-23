#include "../Configuration.hpp"

void Configuration::randSphere(std::vector<double>& direction)
{
    double norm_squared;
    do
    {
        norm_squared = 0.0;
        for (std::size_t i = 0; i < direction.size(); ++i)
        {
            direction[i] = rn.getGaussian();
            norm_squared += direction[i] * direction[i];
        }
    } while (!(norm_squared > 0.0) || !std::isfinite(norm_squared));

    const double norm = std::sqrt(norm_squared);
    for (std::size_t i = 0; i < direction.size(); ++i) direction[i] /= norm;
}

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
    visited.clear();
    string_head = {0, 0, 0, 0};
    string.push_back(string_head);
    visited.insert(string_head);
    std::vector<double> direction(string_head.size(), 0.0);

    while (true)
    {
        double uniform = rn.getRandomDouble();
        if (uniform == 0.0) uniform = 1.0;
        const long double radius = std::pow(static_cast<long double>(uniform),
            -1.0L / static_cast<long double>(Sigma));
        randSphere(direction);

        std::array<int, 4> candidate{};
        bool exits = false;
        for (std::size_t i = 0; i < candidate.size(); ++i)
        {
            const long double raw_step = std::floor(radius * direction[i] + 0.5L);
            if (!std::isfinite(raw_step) ||
                raw_step < static_cast<long double>(std::numeric_limits<std::int64_t>::min()) ||
                raw_step > static_cast<long double>(std::numeric_limits<std::int64_t>::max()))
            {
                exits = true;
                break;
            }
            const std::int64_t value = static_cast<std::int64_t>(string_head[i]) +
                static_cast<std::int64_t>(raw_step);
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

        if (visited.find(string_head) != visited.end())
        {
            while (string_head != string.back())
            {
                visited.erase(string.back());
                string.pop_back();
                --length_string;
            }
        }
        else
        {
            string.push_back(string_head);
            ++length_string;
            visited.insert(string_head);
        }
        ++complete_length_string;
        int distance = 0;
        for (int coordinate : string_head) distance = std::max(distance, std::abs(coordinate));
        record_crossings(distance);
    }
}
