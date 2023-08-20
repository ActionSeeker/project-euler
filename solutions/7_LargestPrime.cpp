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
    REALLY_LONG_INT biggest_array_size = pow(10, 6);
    std::vector<bool> isPrime = sieveOfEratosthenes(biggest_array_size);
    std::vector<int> primes[20000];
    int count = 0;
    for (int i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i])
            primes->push_back(i);
    }
    std::cout << primes->at(10000) << std::endl;
    return 0;
}