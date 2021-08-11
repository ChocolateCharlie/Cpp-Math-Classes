#include "basic-functions.h"
#include "Rational.h"

// CONSTRUCTOR
Rational::Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if (m_denominator == 0) { m_denominator = 1; }  // Arbitrarily changes to a valid denominator
    if (m_denominator < 0) {    // Denominator is always positive
        m_numerator *= -1;
        m_denominator *= -1;
    }
    to_canonical();
}

// OPERATOR METHODS
Rational& Rational::operator+=(const int &n) {
    m_numerator += n * m_denominator;
    to_canonical();
    return(*this);
}

Rational& Rational::operator-=(const int &n) {
    m_numerator -= n * m_denominator;
    to_canonical();
    return(*this);
}

Rational& Rational::operator*=(const int &n) {
    m_numerator *= n;
    to_canonical();
    return(*this);
}

Rational& Rational::operator/=(const int &n) {
    if (n != 0) { m_numerator /= n; }
    to_canonical();
    return(*this);
}

// CONSTANT METHODS
bool Rational::is_equal_to(const int &n) const {
    return(m_denominator == 1 && m_numerator == n);
}

bool Rational::is_equal_to(const Rational &r) const {
    return(m_numerator == r.m_numerator && m_denominator == r.m_denominator);
}

void Rational::show(std::ostream &stream) const {
    if (!m_numerator)   { stream << "0"; }  // Zero
    else {
        stream << m_numerator;
        // Denominator shall not be printed if it is equal to 1
        if (m_denominator != 1) { stream << "/" << m_denominator; }
    }
}

// MORE METHODS
void Rational::to_canonical() {
    int d;
    do {
        d = gcd(max((m_numerator > 0 ? m_numerator : m_numerator * -1), m_denominator),
                min((m_numerator > 0 ? m_numerator : m_numerator * -1), m_denominator));
        m_numerator /= d;
        m_denominator /= d;
    } while(d != 1);
}

/* ---------- OUT OF CLASS ---------- */

// OPERATOR FUNCTIONS
bool operator==(const Rational &r, const int &n) {
    return(r.is_equal_to(n));
}

bool operator==(const Rational &a, const Rational &b) {
    return(a.is_equal_to(b));
}

bool operator!=(const Rational &r, const int &n) {
    return(r.is_equal_to(n));
}

bool operator!=(const Rational &a, const Rational &b) {
    return(! a.is_equal_to(b));
}

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
    temp /= n;
    return(temp);
}
