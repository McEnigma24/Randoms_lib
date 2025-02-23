#include "__preprocessor__.h"
#include "__time_stamp__.h"

#include "Randoms.h"

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    CORE::clear_terminal();
    time_stamp("It just works");

    Randoms::Random_floating_point<double> rand;
    double r_value;
    for (;;)
    {
        r_value = rand.random_floating_in_range(-10.0f, 10.0f);
        var(r_value);
    }

    return 0;
}
#endif