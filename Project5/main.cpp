#include <iostream>

#include "Fraction.hpp"

int main()
{
    Fraction fr{ -24, 32 };
    std::cout << fr.getNominator();
    return 0;
}