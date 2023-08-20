#include <iostream>
#include <cmath>
#include <vector>

#define REALLY_LONG_INT unsigned long long int

int main()
{
    int max_a = 1000;
    int max_b = 1000;
    REALLY_LONG_INT product = 1;
    bool solution_found = false;
    for (int a = 1; a <= max_a; a++)
    {
        for (int b = 1; b <= max_b; b++)
        {
            double c = 500 - (((double)a * (double)b) / 1000);
            if (c - int(c) == 0 && a * a + b * b == ((int)c * (int)c))
            {
                std::cout << "The magical values: " << a << ", " << b << ", " << c << std::endl;
                std::cout << "Does it satisfy pythagoream triplet? " << a * a + b * b << std::endl;
                std::cout << "Does it satisfy pythagoream triplet? " << c * c << std::endl;
                std::cout << "Does it satisfy the equation a+b+c = 1000? " << a + b + c << std::endl;
                product = a * b * (REALLY_LONG_INT)c;
                solution_found = !solution_found;
                break;
            }
        }
        if (solution_found)
            break;
    }
    std::cout << "Product " << product << std::endl;
    return 0;
}