#pragma once
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <random>

namespace Randoms
{
    template <typename T>
    struct Random_floating_point
    {
        static const u64 div_range = 1000000;

        static T random_unit_0_to_1() { return (T)(rand() % div_range + 1) / (T)(div_range); }

        static T random_unit_minus_1_to_1() { return ((T)(rand() % div_range + 1) / (T)(div_range / 2)) - (T)(1); }

        static T distance_between_numbers(T a, T b)
        {
            double ret = a - b;
            return (ret > 0) ? ret : -ret;
        }

        static T random_floating_in_range(T a, T b)
        {
            T range = distance_between_numbers(a, b);

            range *= random_unit_0_to_1();

            T smaller = (a < b) ? a : b;

            return range + smaller;
        }
    };

    template <typename T>
    struct Random_integer
    {
        static T distance_between_numbers(T a, T b)
        {
            int64_t ret = a - b;
            return (ret > 0) ? ret : -ret;
        }

        static T random_integer_in_range(T a, T b)
        {
            T range = distance_between_numbers(a, b) + 1;

            T r = rand() % range;

            T smaller = (a < b) ? a : b;

            return r + smaller;
        }
    };
} // namespace Randoms