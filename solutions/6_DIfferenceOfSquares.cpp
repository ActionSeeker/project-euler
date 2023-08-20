#include <iostream>
#include <cmath>
#include <vector>
#define REALLY_LONG_INT unsigned long int

int main()
{
    int limit = 100;
    // 1**2 + 2**2 + 3**2 + ....
    REALLY_LONG_INT sum_of_squares = (limit * (limit + 1) * (2 * limit + 1)) / 6;
    // (1 + 2 + 3 + 4) ** 2
    REALLY_LONG_INT square_of_sums = pow(limit * (limit + 1) / 2, 2);
    std::cout << square_of_sums - sum_of_squares << std::endl;
    return 0;
}