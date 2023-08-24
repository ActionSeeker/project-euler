#include <iostream>
#include <cmath>
#include <vector>

#define REALLY_LONG_INT unsigned long int
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
    REALLY_LONG_INT long_integer = 600851475143;
    REALLY_LONG_INT intergal_sqrt_of_long_integer = ceil(sqrt(long_integer));
    std::vector<bool> primes = sieveOfEratosthenes(intergal_sqrt_of_long_integer);
    REALLY_LONG_INT first_prime_factor = 1;
    REALLY_LONG_INT other_factor = 1;
    for (int i = primes.size(); i >= 0; i--)
    {
        if (primes[i] && long_integer % i == 0)
        {
            first_prime_factor = i;
            other_factor = long_integer / i;
            break;
        }
    }
    std::cout << first_prime_factor << std::endl;
    std::cout << other_factor << std::endl;
    std::cout << other_factor * first_prime_factor - long_integer;
    return 0;
}