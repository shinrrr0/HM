#pragma once

#ifndef FRACTION_HPP
#define FRACTION_HPP

class Fraction {
private:
    int nominator;
    int denominator;

    void checkSign();
public:
    Fraction(const int& nom = 1, const int& den = 1);
    int getNominator() {
        return nominator;
    }
    int getDenominator() {
        return denominator;
    }
    void setNominator(const int& nom);
    void setDenominator(const int& den);
    void updateFraction();
    inline static int gcf(int a, int b); // наибольший общий делитель
    inline static int& max(int& a, int& b);
    inline static int& min(int& a, int& b);
};
#endif