#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time {
    public:

    Time(int hours = 0, int minutes = 0, int seconds = 0);
    void show() const;

    private :

    int m_hours;
    int m_minutes;
    int m_seconds;
};

#endif // TIME_H_INCLUDED
