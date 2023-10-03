#include <iostream>

#include "Fraction.hpp"

Fraction::Fraction(const int& nom, const int& den) {
    nominator = nom; // �� ��������� ��� ������������� setNominator(), �.�. ������� ������� ������������������ � ��������� � �����������
    setDenominator(den);
}

void Fraction::checkSign() {
    if (nominator < 0 && denominator < 0) {
        nominator = abs(nominator);
        denominator = abs(denominator);
    }
}

void Fraction::setNominator(const int& nom) {
    nominator = nom;
    updateFraction();
}
void Fraction::setDenominator(const int& den) {
    if (!den) {
        std::cerr << "division by zero";
        return;
    }
    denominator = den;
    updateFraction();
}
void Fraction::updateFraction() {
    int divider = gcf(abs(nominator), abs(denominator));
    nominator /= divider;
    denominator /= divider;
    checkSign();
}

inline int Fraction::gcf(int a, int b) {
    while (a != 0 && b != 0) {
        int& c = max(a, b);
        c %= min(a, b);
    }
    return max(a, b);
}

inline int& Fraction::max(int& a, int& b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

inline int& Fraction::min(int& a, int& b) {
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}