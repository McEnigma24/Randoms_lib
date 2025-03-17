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
        static T random_unit_0_to_1() { return ((T)(rand()) / (T)RAND_MAX); }
        static T random_unit_minus_1_to_1() { return ((T)(rand() / (T)(RAND_MAX / 2)) - (T)(1)); }

        static T random_unit_0_to_1_range(const u64 div_range) { return (T)(rand() % div_range + 1) / (T)(div_range); }
        static T random_unit_minus_1_to_1_range(const u64 div_range) { return ((T)(rand() % div_range + 1) / (T)(div_range / 2)) - (T)(1); }

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

    // potem mogę tutaj, dorzucić ten softmax, na stworzenie rozkładu prawdopodobieństwa, dla obiektów //

    // WolframAlpha -> a = 5.0, e^490/a /e^500/a + e^480/a+e^490/a * 100

    // template <class obj_t>
    // class Choose_random_obj_by_assigned_chance
    // {
    //     struct

    //     vector<>
    // };

} // namespace Randoms