#include <iostream>

#include "Time.h"

// CONSTRUCTOR
Time::Time(int hours, int minutes, int seconds) : m_hours(hours), m_minutes(minutes), m_seconds(seconds) {
    if (m_seconds >= 60) {
        m_minutes += m_seconds / 60;
        m_seconds %= 60;
    }

    if (m_minutes >= 60) {
        m_hours += m_minutes / 60;
        m_minutes %= 60;
    }
}

// CONSTANT METHODS
void Time::show() const {
    std::cout << m_hours << ":" << m_minutes << ":" << m_seconds;
}
