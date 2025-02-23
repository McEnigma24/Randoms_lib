#include "__preprocessor__.h"
#include "__time_stamp__.h"

#include "Randoms.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    CORE::clear_terminal();
    time_stamp("It just works");

    Random_int<u64> rand;
    u64 r_value;
    for (;;)
    {
        r_value = rand.random_int_in_range(10, 1);
        var(r_value);

        if (!(1 <= r_value && r_value <= 10)) { break; }
    }

    return 0;
}
#endif