#pragma once

#ifndef FRACTION_HPP
#define FRACTION_HPP

class Fraction {
protected:
    int nominator;
    int denominator;

    void checkSign();
    void updateFraction();

    static int gcf(int a, int b);
    static int getCommonDivisor(const Fraction& af, const Fraction& bf);

public:
    explicit Fraction(const int& nom = 1, const int& den = 1);
    int getNominator() const {
        return nominator;
    }
    int getDenominator() const {
        return denominator;
    }

    void setNominator(const int& nom);
    void setDenominator(const int& den);
    
    int getWholePart() const;
    Fraction getFractionalPart() const;

    Fraction getReversed() const;
    bool isProper() const;
    bool isImproper() const;
    bool isInt() const;

    friend Fraction operator -(const Fraction& a, const Fraction& b);
    friend Fraction operator +(const Fraction& a, const Fraction& b);
    friend Fraction operator *(const Fraction& a, const Fraction& b);
    friend Fraction operator /(const Fraction& a, const Fraction& b);
    friend std::ostream& operator <<(std::ostream& out, const Fraction& obj);
    friend std::istream& operator >>(std::istream& in, Fraction& obj);
    friend Fraction operator +(const Fraction& a) { return a; };
    friend Fraction operator -(const Fraction& a);
    friend Fraction operator ++(Fraction& a); // ++a
    friend Fraction operator ++(Fraction& a, int d); // a++
    friend Fraction operator --(Fraction& a); // --a
    friend Fraction operator --(Fraction& a, int d); // a--
    
};
#endif