#pragma once
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <random>

template <typename T>
struct Random_f
{
    static const u64 div_range = 100000;

    static T random_unit_0_to_1() { return (T)(rand() % div_range + 1) / (T)(div_range); }

    static T random_unit_minus_1_to_1() { return ((T)(rand() % div_range + 1) / (T)(div_range / 2)) - (T)(1); }

    static T distance_between_numbers(int64_t a, int64_t b)
    {
        double ret = a - b;
        return (ret > 0) ? ret : -ret;
    }

    // przemnożyć 0_1 przez range i dodać do najmniejszej
};

template <typename T>
struct Random_int
{
    static T distance_between_numbers(T a, T b)
    {
        int64_t ret = a - b;
        return (ret > 0) ? ret : -ret;
    }

    static T random_int_in_range(T a, T b)
    {
        T range = distance_between_numbers(a, b) + 1;

        T r = rand() % range;

        T smaller = (a < b) ? a : b;

        return r + smaller;
    }
};