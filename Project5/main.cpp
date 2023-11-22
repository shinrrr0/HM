#include <iostream>

#include "Fraction.hpp"


int main()
{
    Fraction fr1{ 1, 4 };
    Fraction fr2{ 1, 25 };

    Fraction fr3;
    std::cin >> fr3;
    std::cout << fr3 << std::endl;
    std::cout << +fr3 << std::endl;
    std::cout << -fr3 << std::endl;
    std::cout << ++fr3 << std::endl;
    std::cout << fr3++ << std::endl;
    std::cout << --fr3 << std::endl;
    std::cout << fr3-- << std::endl;
    
    std::cout << fr1 * fr2 << std::endl;
    std::cout << fr1 / fr2 << std::endl;
    std::cout << fr1 + fr2 << std::endl;
    std::cout << fr1 - fr2 << std::endl;

    std::cout << fr1.isProper() << std::endl;
    std::cout << fr2.isImproper() << std::endl;
    std::cout << fr2.isInt() << std::endl;

    std::cout << fr1.getWholePart() << std::endl;
    std::cout << fr2.getFractionalPart() << std::endl;
    std::cout << fr2.getReversed() << std::endl;

    return 0;
}