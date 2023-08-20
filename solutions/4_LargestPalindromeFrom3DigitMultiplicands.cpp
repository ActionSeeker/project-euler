#include <iostream>
#include <cmath>
#include <vector>

bool isPalindrome(int number)
{
    int original_number = number;
    int reversed_number = 0;
    int last_digit = 0;
    while (original_number != 0)
    {
        reversed_number = reversed_number * 10 + (original_number % 10); // 65 * 10 = 650
        original_number /= 10;                                           // 1234
    }
    // std::cout << "Number " << number << " and the reversed: " << reversed_number << std::endl;
    return number == reversed_number;
}

int main()
{
    int first_multiplicand = 999;
    int second_multiplicand = 999;
    int largest_palindrome = 1;
    // Maximum digits of possible results: 6 digits
    for (int i = first_multiplicand; i >= 100; i--)
    {
        for (int j = second_multiplicand; j >= 100; j--)
        {
            if (isPalindrome(i * j))
            {
                std::cout << "Here comes the catch! " << i * j << std::endl;
                largest_palindrome = i * j > largest_palindrome ? i * j : largest_palindrome;
            }
        }
    }
    std::cout << largest_palindrome << std::endl;
    return 0;
}