#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

class Rational {
    public:

    Rational(int numerator, int denominator = 1);
    Rational& operator+=(const int n);
    Rational& operator-=(const int n);
    Rational& operator*=(const int n);
    Rational& operator/=(const int n);
    bool is_equal_to(const int &n) const;
    bool is_equal_to(const Rational &r) const;
    void show(std::ostream &stream = std::cout) const;
    void to_canonical();
    // int to_decimal();

    private:

    int m_numerator;
    int m_denominator;

};

bool operator==(const Rational &r, const int &n);
bool operator==(const Rational &a, const Rational &b);
bool operator!=(const Rational &r, const int &n);
bool operator!=(const Rational &a, const Rational &b);

std::ostream& operator<<(std::ostream &stream, const Rational &r);

Rational operator+(const Rational &r, const int &n);
Rational operator-(const Rational &r, const int &n);
Rational operator*(const Rational &r, const int &n);
Rational operator/(const Rational &r, const int &n);

#endif // RATIONAL_H_INCLUDED
