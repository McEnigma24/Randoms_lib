#include "__preprocessor__.h"
#include "__time_stamp__.h"

#include "Randoms.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    CORE::clear_terminal();
    time_stamp("It just works");

    double r_value;
    for (;;)
    {
        // r_value = Randoms::Random_floating_point<double>::random_floating_in_range(-10.0f, 10.0f);
        // r_value = Randoms::Random_floating_point<double>::random_unit_0_to_1();
        r_value = Randoms::Random_floating_point<double>::random_unit_minus_1_to_1_range(10);

        var(r_value);
    }

    return 0;
}
#endif