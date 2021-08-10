#include "basic-functions.h"
#include "Rational.h"

// CONSTRUCTOR
Rational::Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if (m_denominator == 0) { m_denominator = 1; }  // Arbitrarily changes to a valid denominator
    to_canonical();
}

// OPERATOR METHODS
Rational& Rational::operator+=(const int n) {
    m_numerator += n * (m_denominator > 0 ? m_denominator : m_denominator * -1);
    to_canonical();
    return(*this);
}

Rational& Rational::operator-=(const int n) {
    m_numerator -= n * (m_denominator > 0 ? m_denominator : m_denominator * -1);
    to_canonical();
    return(*this);
}

Rational& Rational::operator*=(const int n) {
    m_numerator *= n;
    to_canonical();
    return(*this);
}

Rational& Rational::operator/=(const int n) {
    if (n != 0) { m_numerator /= n; }
    to_canonical();
    return(*this);
}

// CONSTANT METHODS
void Rational::show(std::ostream &stream) const {
    // Checks if the number is simply zero
    if (!m_numerator)   { stream << "0"; }
    else {
        // If the number is negative then prints "-" at the beginning
        if ((m_numerator < 0 && m_denominator > 0)
         || (m_numerator > 0 && m_denominator < 0)) {
            stream << "-";
        }
        stream << (m_numerator > 0 ? m_numerator : m_numerator * -1);   // Print absolute value
        // Denominator shall not be printed if it is equal to +/- 1
        if (m_denominator != 1 && m_denominator != -1) {
            stream << "/" << (m_denominator > 0 ? m_denominator : m_denominator * -1);  // Print absolute value
        }
    }
}

// MORE METHODS
void Rational::to_canonical() {
    int d;
    do {
        d = gcd(max((m_numerator > 0 ? m_numerator : m_numerator * -1), (m_denominator > 0 ? m_denominator : m_denominator * -1)),
                min((m_numerator > 0 ? m_numerator : m_numerator * -1), (m_denominator > 0 ? m_denominator : m_denominator * -1)));
        m_numerator /= d;
        m_denominator /= d;
    } while(d != 1);
}

/* ---------- OUT OF CLASS ---------- */

// OPERATOR FUNCTIONS
std::ostream& operator<<(std::ostream &stream, const Rational &r) {
    r.show(stream);
    return(stream);
}

Rational operator+(const Rational &r, const int &n) {
    Rational temp(r);
    temp += n;
    return(temp);
}

Rational operator-(const Rational &r, const int &n) {
    Rational temp(r);
    temp -= n;
    return(temp);
}

Rational operator*(const Rational &r, const int &n) {
    Rational temp(r);
    temp *= n;
    return(temp);
}

Rational operator/(const Rational &r, const int &n) {
    Rational temp(r);
    temp *= n;
    return(temp);
}
