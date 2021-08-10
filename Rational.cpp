#include "Rational.h"

// CONSTRUCTOR
Rational::Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if (m_denominator == 0) { m_denominator = 1; }  // Arbitrarily changes to a valid denominator
}
