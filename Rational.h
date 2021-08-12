#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

class Rational {
    public:

    Rational(int numerator = 0, int denominator = 1);   // WARNING: Throws a domain_error exception if denominator is 0
    Rational& operator+=(const int &n);
    Rational& operator+=(const Rational &r);
    Rational& operator-=(const int &n);
    Rational& operator-=(const Rational &r);
    Rational& operator*=(const int &n);
    Rational& operator*=(const Rational &r);
    Rational& operator/=(const int &n);         // WARNING : Throws a domain_error exception when trying to divide by 0
    Rational& operator/=(const Rational &r);    // WARNING: Throws a domain_error exception when trying to divide by 0
    Rational opposite() const;      // Additive inverse
    Rational reciprocal() const;    // Multiplicative inverse ; WARNING: Throws a domain_error exception when trying to compute reciprocal of 0
    float to_decimal() const;

    private:

    bool is_equal_to(const int &n) const;
    bool is_equal_to(const Rational &r) const;
    bool is_smaller_than(const int &n) const;
    bool is_smaller_than(const Rational &r) const;
    void show(std::ostream &stream = std::cout) const;
    void to_canonical();

    int m_numerator;
    int m_denominator;

    friend bool operator==(const Rational &r, const int &n);
    friend bool operator==(const Rational &a, const Rational &b);
    friend bool operator!=(const Rational &r, const int &n);
    friend bool operator!=(const Rational &a, const Rational &b);
    friend bool operator< (const Rational &r, const int &n);
    friend bool operator< (const Rational &a, const Rational &b);
    friend bool operator<=(const Rational &r, const int &n);
    friend bool operator<=(const Rational &a, const Rational &b);
    friend bool operator> (const Rational &r, const int &n);
    friend bool operator> (const Rational &a, const Rational &b);
    friend bool operator>=(const Rational &r, const int &n);
    friend bool operator>=(const Rational &a, const Rational &b);
    friend std::ostream& operator<<(std::ostream &stream, const Rational &r);
};

Rational operator+(const Rational &r, const int &n);
Rational operator+(const Rational &a, const Rational &b);
Rational operator-(const Rational &r, const int &n);
Rational operator-(const Rational &a, const Rational &b);
Rational operator*(const Rational &r, const int &n);
Rational operator*(const Rational &a, const Rational &b);
Rational operator/(const Rational &r, const int &n);        // WARNING: Throws a domain_error exception when trying to divide by 0
Rational operator/(const Rational &a, const Rational &b);   // WARNING: Throws a domain_error exception when trying to divide by 0

#endif // RATIONAL_H_INCLUDED
