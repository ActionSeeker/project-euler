#include <iostream>
#define REALLY_LONG_INT unsigned long int

int main()
{
    REALLY_LONG_INT sum_of_fibonnaci = 2;
    REALLY_LONG_INT f_n = 1;
    REALLY_LONG_INT f_nplus1 = 2;
    REALLY_LONG_INT f_nplus2 = 0;
    while ((f_nplus1 + f_n) <= 4000000)
    {
        f_nplus2 = f_nplus1 + f_n;
        if ((f_nplus2 & 1) == 0)
            sum_of_fibonnaci += f_nplus2;
        // Shift terms now
        f_n = f_nplus1;
        f_nplus1 = f_nplus2;
    }
    std::cout << sum_of_fibonnaci << std::endl;
    return 0;
}