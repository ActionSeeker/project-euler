// Sourceforthishppavailableunderhttps://faheel.github.io/BigInt/
// Works with C++ 17
// g++ 16_PowerDigitSum.cpp --std=c++17 -o output
#include "iostream"
#include "BigInt.hpp"

int main()
{

    BigInt big_power = 1;
    for (int index = 0; index < 1000; index++)
    {
        big_power *= 2;
    }
    std::string power_in_string = big_power.to_string();
    unsigned long long int sum = 0;
    for (int i = 0; i < power_in_string.size(); i++)
    {
        std::cout << power_in_string[i] - '0' << std::endl;
        sum += (power_in_string[i] - '0');
    }
    std::cout << sum << std::endl;
    return 0;
}