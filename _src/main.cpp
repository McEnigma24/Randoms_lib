#include "__preprocessor__.h"
#include "__time_stamp__.h"

#include "Randoms.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    CORE::clear_terminal();
    time_stamp("It just works");

    // double r_value;
    // for (;;)
    // {
    //     // r_value = Randoms::Random_floating_point<double>::random_floating_in_range(-10.0f, 10.0f);
    //     // r_value = Randoms::Random_floating_point<double>::random_unit_0_to_1();
    //     r_value = Randoms::Random_floating_point<double>::random_unit_minus_1_to_1_range(10);

    //     var(r_value);
    // }

    u32 r_value = rand();

    //                    Znak  Wykładnik Mantysa Szerokość
    // IEEE-754 single	    1	    8	    23	    32
    // IEEE-754 double	    1	    11	    52	    64

    for (;;)
    {
        float f = 0;
        r_value = rand();

        *((u32*)&f) |= (r_value & 0x007FFFFF); // mantysa
        *((u32*)&f) |= (r_value & 0x7E) << 23; // exponent

        // *((u32*)&f) |= (4294967295u & 0x80000000); // sign

        var(f);
        cin.get();
    }

    return 0;
}
#endif