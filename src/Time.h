/* ************************************************************************* */
/* Time.h                                                           CPP-MATH */
/* By: ChocolateCharlie                                                      */
/* Updated: 2021-11-11                                                       */
/* ************************************************************************* */
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <iomanip>
#include <iostream>

class Time {
	public:
		// Constructor
		Time(const int &hours = 0, const int &minutes = 0, const int &seconds = 0);
		// Accessors
		int get_hours() const;
		int get_minutes() const;
		int get_seconds() const;
		/*
		Time& operator+=(const Time &t);
		Time& operator-=(const Time &t);
		Time& operator*=(const int &n);	// Multiplies hours, minutes and seconds by n
		Time& operator/=(const int &n);	// Divides hours, minutes and seconds by n
		Time& operator%=(const int &n);	// Moduloes hours, minutes and seconds by n
		*/
	private:
		/*
		bool is_equal_to(const Time &t) const;
		bool is_smaller_than(const Time &t) const;
		void make_valid();
		void show(std::ostream &stream = std::cout) const;
		*/
		int m_hours;
		int m_minutes;
		int m_seconds;
		/*
		friend bool operator==(const Time &a, const Time &b);
		friend bool operator!=(const Time &a, const Time &b);
		friend bool operator< (const Time &a, const Time &b);
		friend bool operator<=(const Time &a, const Time &b);
		friend bool operator> (const Time &a, const Time &b);
		friend bool operator>=(const Time &a, const Time &b);
		friend std::ostream& operator<<(std::ostream &stream, const Time &t);
		*/
};
/*
Time operator+(const Time &a, const Time &b);
Time operator-(const Time &a, const Time &b);
*/
#endif	// TIME_H_INCLUDED

