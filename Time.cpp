#include <iomanip>
#include <iostream>

#include "Time.h"

// CONSTRUCTOR
Time::Time(int hours, int minutes, int seconds) : m_hours(hours), m_minutes(minutes), m_seconds(seconds) {
    make_valid();
}

// OPERATOR METHODS
Time& Time::operator+=(const Time &t) {
    m_seconds += t.m_seconds;
    m_minutes += t.m_minutes;
    m_hours += t.m_hours;
    make_valid();

    return(*this);
}

Time& Time::operator-=(const Time &t) {
    m_seconds -= t.m_seconds;
    m_minutes -= t.m_minutes;
    m_hours -= t.m_hours;
    make_valid();

    return(*this);
}

Time& Time::operator*=(const int n) {
    m_seconds *= n;
    m_minutes *= n;
    m_hours *= n;
    make_valid();

    return(*this);
}

Time& Time::operator/=(const int n) {
    m_seconds /= n;
    m_minutes /= n;
    m_hours /= n;
    make_valid();

    return(*this);
}

Time& Time::operator%=(const int n) {
    m_seconds %= n;
    m_minutes %= n;
    m_hours %= n;
    make_valid();

    return(*this);
}

// CONSTANT METHODS
bool Time::is_equal_to(const Time &t) const {
    return(m_hours == t.m_hours && m_minutes == t.m_minutes && m_seconds == t.m_seconds);
}

bool Time::is_smaller_than(const Time &t) const {
    return(m_hours < t.m_hours || (m_hours == t.m_hours && (m_minutes < t.m_minutes || (m_minutes == t.m_minutes && m_seconds < t.m_seconds))));
}

void Time::show(std::ostream &stream) const {
    stream << std::setfill('0') << std::setw(2) << m_hours << ":";
    stream << std::setfill('0') << std::setw(2) << m_minutes << ":";
    stream << std::setfill('0') << std::setw(2) << m_seconds;
}

// OTHER METHODS
void Time::make_valid() {
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

/* ---------- OUT OF CLASS ---------- */

// OPERATOR FUNCTIONS
bool operator==(const Time &a, const Time &b) {
    return(a.is_equal_to(b));
}

bool operator!=(const Time &a, const Time &b) {
    return(! a.is_equal_to(b));
}

bool operator<(const Time &a, const Time &b) {
    return(a.is_smaller_than(b));
}

bool operator<=(const Time &a, const Time &b) {
    return(a.is_smaller_than(b) || a.is_equal_to(b));
}

bool operator>(const Time &a, const Time &b) {
    return(b.is_smaller_than(a));
}

bool operator>=(const Time &a, const Time &b) {
    return(b.is_smaller_than(a) || b.is_equal_to(a));
}

std::ostream& operator<<(std::ostream &stream, const Time &t) {
    t.show(stream);
    return(stream);
}

Time operator+(const Time &a, const Time &b) {
    Time temp(a);
    temp += b;
    return(temp);
}

Time operator-(const Time &a, const Time &b) {
    Time temp(a);
    temp -= b;
    return(temp);
}
