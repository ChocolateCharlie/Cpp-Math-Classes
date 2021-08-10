#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

#include <iostream>

class Rational {
    public:

    Rational(int numerator, int denominator = 1);
    void show(std::ostream &stream = std::cout) const;

    private:

    int m_numerator;
    int m_denominator;

};

std::ostream& operator<<(std::ostream &stream, const Rational &r);

#endif // RATIONAL_H_INCLUDED
