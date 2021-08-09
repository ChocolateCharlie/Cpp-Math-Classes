#include <iomanip>
#include <iostream>

#include "Time.h"

// CONSTRUCTOR
Time::Time(int hours, int minutes, int seconds) : m_hours(hours), m_minutes(minutes), m_seconds(seconds) {
    if (m_seconds < 0)  { m_seconds = 0; }
    if (m_minutes < 0)  { m_minutes = 0; }
    if (m_hours < 0)    { m_hours = 0; }

    if (m_seconds >= 60) {
        m_minutes += m_seconds / 60;
        m_seconds %= 60;
    }

    if (m_minutes >= 60) {
        m_hours += m_minutes / 60;
        m_minutes %= 60;
    }
}

// OPERATOR METHODS
Time& Time::operator+=(Time const &t) {
    m_seconds += t.m_seconds;
    m_minutes += t.m_minutes;
    m_hours += t.m_hours;

    if (m_seconds >= 60) {
        m_minutes += m_seconds / 60;
        m_seconds %= 60;
    }

    if (m_minutes >= 60) {
        m_hours += m_minutes / 60;
        m_minutes %= 60;
    }

    return(*this);
}

// CONSTANT METHODS
void Time::show() const {
    std::cout << std::setfill('0') << std::setw(2) << m_hours << ":";
    std::cout << std::setfill('0') << std::setw(2) << m_minutes << ":";
    std::cout << std::setfill('0') << std::setw(2) << m_seconds;
}

/* ---------- OUT OF CLASS ---------- */

// OPERATOR FUNCTIONS
Time operator+(const Time &a, const Time &b) {
    Time temp(a);
    temp += b;
    return(temp);
}