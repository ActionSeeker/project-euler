#include <iostream>
#include <cmath>
#include <vector>

#define REALLY_LONG_INT unsigned long long int
#define THE_ONLY_EVEN_PRIME 2
#define CHUNK_SIZE 13

bool substring_has_a_zero(std::string substring)
{
    return substring.find('0') != -1;
}

REALLY_LONG_INT product_of_numbers(std::string substring)
{
    REALLY_LONG_INT product = 1;
    char char_substring[substring.size() + 1];
    substring.copy(char_substring, substring.size());
    char_substring[substring.size()] = '\0';
    for (int i = 0; i < substring.size(); i++)
    {
        product *= (char_substring[i] - '0');
    }
    return product;
}

int main()
{
    std::string big_number = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    REALLY_LONG_INT product = 0;
    for (int begins_at = 0; begins_at < big_number.size(); begins_at += 1)
    {
        std::string substring = big_number.substr(begins_at, CHUNK_SIZE);
        if (substring.size() < CHUNK_SIZE)
            break;
        if (substring_has_a_zero(substring))
        {
            // We reset the iterator to the location + 1 of this zero
            begins_at += substring.find_last_of('0');
        }
        else
        {
            REALLY_LONG_INT substring_product = product_of_numbers(substring);
            if (substring_product > product)
                product = substring_product;
        }
    }
    std::cout << "Biggest product: " << product << std::endl;
    return 0;
}