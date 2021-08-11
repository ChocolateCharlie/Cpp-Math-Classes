#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

class Rational {
    public:

    Rational(int numerator, int denominator = 1);
    Rational& operator+=(const int &n);
    Rational& operator+=(const Rational &r);
    Rational& operator-=(const int &n);
    Rational& operator-=(const Rational &r);
    Rational& operator*=(const int &n);
    Rational& operator*=(const Rational &r);
    Rational& operator/=(const int &n);
    Rational& operator/=(const Rational &r);    // WARNING: Dividing by 0 might lead to unexpected behavior
    bool is_equal_to(const int &n) const;
    bool is_equal_to(const Rational &r) const;
    bool is_smaller_than(const int &n) const;
    bool is_smaller_than(const Rational &r) const;
    Rational opposite() const;      // Additive inverse
    Rational reciprocal() const;    // Multiplicative inverse ; WARNING : Returns 1 when passing 0 (multiplicative inverse does not exist)
    void show(std::ostream &stream = std::cout) const;
    void to_canonical();
    float to_decimal() const;

    private:

    int m_numerator;
    int m_denominator;

};

bool operator==(const Rational &r, const int &n);
bool operator==(const Rational &a, const Rational &b);
bool operator!=(const Rational &r, const int &n);
bool operator!=(const Rational &a, const Rational &b);
bool operator< (const Rational &r, const int &n);
bool operator< (const Rational &a, const Rational &b);
bool operator<=(const Rational &r, const int &n);
bool operator<=(const Rational &a, const Rational &b);
bool operator> (const Rational &r, const int &n);
bool operator> (const Rational &a, const Rational &b);
bool operator>=(const Rational &r, const int &n);
bool operator>=(const Rational &a, const Rational &b);

std::ostream& operator<<(std::ostream &stream, const Rational &r);

Rational operator+(const Rational &r, const int &n);
Rational operator+(const Rational &a, const Rational &b);
Rational operator-(const Rational &r, const int &n);
Rational operator-(const Rational &a, const Rational &b);
Rational operator*(const Rational &r, const int &n);
Rational operator*(const Rational &a, const Rational &b);
Rational operator/(const Rational &r, const int &n);
Rational operator/(const Rational &a, const Rational &b);

#endif // RATIONAL_H_INCLUDED
