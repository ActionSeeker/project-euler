#include <iostream>
#include <cmath>
#include <vector>

#define REALLY_LONG_INT unsigned long long int
#define THE_ONLY_EVEN_PRIME 2

std::vector<bool> sieveOfEratosthenes(REALLY_LONG_INT size)
{
    std::vector<bool> isPrime(size + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (REALLY_LONG_INT i = 4; i <= size; i += 2)
        isPrime[i] = false;
    for (REALLY_LONG_INT number = 3; number * number <= size; number += 2)
        if (isPrime[number])
            for (REALLY_LONG_INT multiplicand = number * number; multiplicand <= size; multiplicand += number)
                isPrime[multiplicand] = false;
    return isPrime;
}

int main()
{
    REALLY_LONG_INT biggest_array_size = 2 * pow(10, 6);
    std::vector<bool> isPrime = sieveOfEratosthenes(biggest_array_size);
    std::vector<int> primes(10000);

    for (int i = 0; i < isPrime.size(); i++)
        if (isPrime[i])
            primes.push_back(i);

    // Skipping 1 and 3 because 3 is the only prime triangular number
    for (int index = 3; index <= 2 * pow(10, 6); index++)
    {
        REALLY_LONG_INT even = index % 2 == 0 ? index : index + 1;
        REALLY_LONG_INT odd = index % 2 == 0 ? index + 1 : index;

        even /= 2;
        int number_of_divisors = 1;
        REALLY_LONG_INT triangular_number = even * odd;

        for (int pIdx = 0; pIdx < primes.size(); pIdx++)
        {
            int prime = primes.at(pIdx);
            int power_of_even_multiplicand = 0;
            int power_of_odd_multiplicand = 0;
            if (even % prime == 0 || odd % prime == 0)
            {
                // Browsing each component is easier than the product
                while (even % prime == 0)
                {
                    even /= prime;
                    power_of_even_multiplicand++;
                }

                while (odd % prime == 0)
                {
                    odd /= prime;
                    power_of_odd_multiplicand++;
                }

                /**
                 * This is explained as follows: Consider two numbers, x and y
                 * Let x = (2 ** α)(3 ** β)(5 ** γ)..
                 * Let y = (2 ** ε)(5 ** ω)
                 * Then xy = (2 ** (α+ε))(3 ** β)(5 ** (γ+ω))
                 */

                number_of_divisors *= (power_of_odd_multiplicand + power_of_even_multiplicand + 1);
            }
        }
        if (number_of_divisors >= 500)
        {
            std::cout << "triangular_number: " << triangular_number << std::endl;
            std::cout << "number_of_divisors: " << number_of_divisors << std::endl;
        }
    }
    return 0;
}