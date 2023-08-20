#include <iostream>
#include <cmath>
#include <vector>
#define THE_ONLY_EVEN_PRIME 2

std::vector<bool> sieveOfEratosthenes(int size)
{
    std::vector<bool> isPrime(size + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 4; i <= size; i += 2)
        isPrime[i] = false;
    for (int number = 3; number * number <= size; number += 2)
        if (isPrime[number])
            for (int multiplicand = number * number; multiplicand <= size; multiplicand += number)
                isPrime[multiplicand] = false;
    return isPrime;
}

int main()
{
    int limit = 20;
    std::vector<bool> primes = sieveOfEratosthenes(limit);
    int smallest_factor = 1;
    for (int i = primes.size(); i >= 0; i--)
    {
        if (primes[i])
        {
            // Check for the highest power of the number
            int highest_power = floor((log(limit) / log(i)));
            std::cout << i << " " << highest_power << std::endl;
            smallest_factor *= pow(i, highest_power);
        }
    }
    std::cout << smallest_factor << std::endl;
    return 0;
}