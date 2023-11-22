#include <iostream>
#include <algorithm>
#include <string>

#include "Fraction.hpp"

Fraction::Fraction(const int& nom, const int& den) {
    nominator = nom; // не использую для инициализации setNominator(), т.к. функция требуют инициализированные и числитель и знаменатель
    setDenominator(den);
}

void Fraction::checkSign() {
    if (nominator < 0 && denominator < 0) {
        nominator = abs(nominator);
        denominator = abs(denominator);
    }
    if (denominator < 0 && nominator > 0) {
        denominator = -denominator;
        nominator = -nominator;
    }
}

void Fraction::setNominator(const int& nom) {
    nominator = nom;
    updateFraction();
}
void Fraction::setDenominator(const int& den) {
    if (!den) {
        throw "division by zero when creating fraction";
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

int Fraction::gcf(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return std::max(a, b);
}

int Fraction::getCommonDivisor(const Fraction& af, const Fraction& bf) {
    int a = af.getDenominator();
    int b = bf.getDenominator();
    if (a % b == 0) {
        return a / b;
    }
    if (b % a == 0) {
        return b / a;
    }
    else {
        return a * b;
    }
}

Fraction Fraction::getReversed() const {
    if (getDenominator() == 0) {
        throw "division by zero when reversing fraction " + std::to_string(getNominator()) + " / " + std::to_string(getDenominator());
    }
    Fraction new_fr{getDenominator(), getNominator()};
    return new_fr;
};


Fraction operator -(const Fraction& a, const Fraction& b) {
    int common_div = Fraction::getCommonDivisor(a, b);
    return Fraction{ (a.getNominator() * (common_div / a.getDenominator())) -
                     (b.getNominator() * (common_div / b.getDenominator())),
                     common_div };
}

Fraction operator +(const Fraction& a, const Fraction& b) {
    int common_div = Fraction::getCommonDivisor(a, b);
    return Fraction{ (a.getNominator() * (common_div / a.getDenominator())) +
                     (b.getNominator() * (common_div / b.getDenominator())),
                     common_div };
}

Fraction operator *(const Fraction& a, const Fraction& b) {
    return Fraction{ a.getNominator() * b.getNominator(),
                     a.getDenominator() * b.getDenominator() };
}

Fraction operator /(const Fraction &a, const Fraction &b) {
    Fraction new_b = b.getReversed();
    return a * new_b;
};

Fraction operator -(const Fraction& a) {
    Fraction new_fr{ -a.nominator, a.denominator };
    return new_fr;
}

Fraction operator ++(Fraction& a) {
    Fraction new_fr{ 1 };
    a = a + new_fr;
    return a;
}

Fraction operator ++(Fraction& a, int d) {
    Fraction old_fr = a;
    Fraction new_fr{ 1 };
    a = a + new_fr;
    return old_fr;
}

Fraction operator --(Fraction& a) {
    Fraction new_fr{ 1 };
    a = a - new_fr;
    return a;
}

Fraction operator --(Fraction& a, int d) {
    Fraction old_fr = a;
    Fraction new_fr{ 1 };
    a = a - new_fr;
    return old_fr;
}

std::ostream& operator <<(std::ostream& out, const Fraction& obj) {
    if (obj.getNominator() == 0) {
        out << 0;
        return out;
    }
    out << obj.getNominator() << " / " << obj.getDenominator();
    return out;
}

std::istream& operator >>(std::istream& in, Fraction& obj) {
    std::string tmp{};
    std::getline(in, tmp, '/');
    obj.setNominator(stoi(tmp));
    in >> tmp;
    obj.setDenominator(stoi(tmp));
    return in;
}

bool Fraction::isProper() const {
    return getNominator() < getDenominator();
}

bool Fraction::isImproper() const {
    return !isProper();
}

bool Fraction::isInt() const {
    return getNominator() % getDenominator() == 0;
}

int Fraction::getWholePart() const {
    return getNominator() / getDenominator();
}

Fraction Fraction::getFractionalPart() const {
    Fraction new_fr{ getWholePart(), 1 };
    return *this - new_fr;
}