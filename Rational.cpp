#include "Rational.h"

// CONSTRUCTOR
Rational::Rational(int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator) {
    if (m_denominator == 0) { m_denominator = 1; }  // Arbitrarily changes to a valid denominator
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

/* ---------- OUT OF CLASS ---------- */

// OPERATOR FUNCTIONS
std::ostream& operator<<(std::ostream &stream, const Rational &r) {
    r.show(stream);
    return(stream);
}
