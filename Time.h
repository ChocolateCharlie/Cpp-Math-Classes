#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time {
    public:

    Time(int hours = 0, int minutes = 0, int seconds = 0);
    Time& operator+=(const Time &t);
    void show() const;

    private :

    int m_hours;
    int m_minutes;
    int m_seconds;
};

Time operator+(const Time &a, const Time &b);

#endif // TIME_H_INCLUDED
