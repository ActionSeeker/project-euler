#include <iostream>

int main()
{
    long int sum_of_3_or_5 = 0;
    for (int num = 3; num < 1000; num += 1)
    {
        if (!(num % 3) || !(num % 5))
        {
            sum_of_3_or_5 += num;
        }
    }
    std::cout << sum_of_3_or_5 << std::endl;
    return 0;
}