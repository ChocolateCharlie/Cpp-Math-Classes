#include <stdexcept>

#include "basic-functions.h"
#include "Rational.h"

// CONSTRUCTOR
Rational::Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if (m_denominator == 0) { throw std::domain_error("Denominator cannot be zero."); }
    to_canonical();
}

// OPERATOR METHODS
Rational& Rational::operator+=(const int &n) {
    m_numerator += n * m_denominator;
    to_canonical();
    return(*this);
}

Rational& Rational::operator+=(const Rational &r) {
    m_numerator = m_numerator * r.m_denominator + r.m_numerator * m_denominator;
    m_denominator *= r.m_denominator;
    to_canonical();
    return(*this);
}

Rational& Rational::operator-=(const int &n) {
    m_numerator -= n * m_denominator;
    to_canonical();
    return(*this);
}

Rational& Rational::operator-=(const Rational &r) {
    m_numerator = m_numerator * r.m_denominator - r.m_numerator * m_denominator;
    m_denominator *= r.m_denominator;
    to_canonical();
    return(*this);
}

Rational& Rational::operator*=(const int &n) {
    m_numerator *= n;
    to_canonical();
    return(*this);
}

Rational& Rational::operator*=(const Rational &r) {
    m_numerator *= r.m_numerator;
    m_denominator *= r.m_denominator;
    to_canonical();
    return(*this);
}

Rational& Rational::operator/=(const int &n) {
    if (n == 0) { throw std::domain_error("Cannot divide by zero."); }
    m_numerator /= n;
    to_canonical();
    return(*this);
}

Rational& Rational::operator/=(const Rational &r) {
    Rational temp(m_numerator * r.m_denominator, m_denominator * r.m_numerator);
    to_canonical();
    m_numerator = temp.m_numerator;
    m_denominator = temp.m_denominator;
    return(*this);
}

// CONSTANT METHODS
Rational Rational::opposite() const {
    Rational opp(m_numerator * (-1), m_denominator);
    return(opp);
}

Rational Rational::reciprocal() const {
    Rational rec(m_denominator, m_numerator);
    return(rec);
}

float Rational::to_decimal() const {
    return((float)m_numerator / (float)m_denominator);
}

// PRIVATE METHODS
// CONSTANT PRIVATE METHODS
bool Rational::is_equal_to(const int &n) const {
    return(m_denominator == 1 && m_numerator == n);
}

bool Rational::is_equal_to(const Rational &r) const {
    return(m_numerator == r.m_numerator && m_denominator == r.m_denominator);
}

bool Rational::is_smaller_than(const int &n) const {
    return(m_numerator < n * m_denominator);
}

bool Rational::is_smaller_than(const Rational &r) const {
    return(m_numerator * r.m_denominator < r.m_numerator * m_denominator);
}

void Rational::show(std::ostream &stream) const {
    stream << m_numerator;
    // Denominator shall not be printed if it is equal to 1
    if (m_denominator != 1) { stream << "/" << m_denominator; }
}

// OTHER PRIVATE METHODS
void Rational::to_canonical() {
    if (m_denominator < 0) {    // Denominator is always positive
        m_numerator *= -1;
        m_denominator *= -1;
    }
    // Simplify by the greatest common divisor
    int d = Basic::gcd(Basic::max(Basic::abs(m_numerator), m_denominator),
                       Basic::min(Basic::abs(m_numerator), m_denominator));
    m_numerator /= d;
    m_denominator /= d;
}

/* ---------- OUT OF CLASS ---------- */

// FRIEND FUNCTIONS
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
    return(!a.is_equal_to(b));
}

bool operator< (const Rational &r, const int &n) {
    return(r.is_smaller_than(n));
}

bool operator< (const Rational &a, const Rational &b) {
    return(a.is_smaller_than(b));
}

bool operator<=(const Rational &r, const int &n) {
    return(r.is_smaller_than(n) || r.is_equal_to(n));
}

bool operator<=(const Rational &a, const Rational &b) {
    return(!b.is_smaller_than(a));
}

bool operator> (const Rational &r, const int &n) {
    return(!r.is_smaller_than(n) && !r.is_equal_to(n));
}

bool operator> (const Rational &a, const Rational &b) {
    return(b.is_smaller_than(a));
}

bool operator>=(const Rational &r, const int &n) {
    return(!r.is_smaller_than(n));
}

bool operator>=(const Rational &a, const Rational &b) {
    return(!a.is_smaller_than(b));
}

std::ostream& operator<<(std::ostream &stream, const Rational &r) {
    r.show(stream);
    return(stream);
}

// OPERATOR FUNCTIONS
Rational operator+(const Rational &r, const int &n) {
    Rational temp(r);
    temp += n;
    return(temp);
}

Rational operator+(const Rational &a, const Rational &b) {
    Rational temp(a);
    temp += b;
    return(temp);
}

Rational operator-(const Rational &r, const int &n) {
    Rational temp(r);
    temp -= n;
    return(temp);
}

Rational operator-(const Rational &a, const Rational &b) {
    Rational temp(a);
    temp -= b;
    return(temp);
}

Rational operator*(const Rational &r, const int &n) {
    Rational temp(r);
    temp *= n;
    return(temp);
}

Rational operator*(const Rational &a, const Rational &b) {
    Rational temp(a);
    temp *= b;
    return(temp);
}

Rational operator/(const Rational &r, const int &n) {
    Rational temp(r);
    temp /= n;
    return(temp);
}

Rational operator/(const Rational &a, const Rational &b) {
    Rational temp(a);
    temp /= b;
    return(temp);
}
