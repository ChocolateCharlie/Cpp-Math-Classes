/* ************************************************************************* */
/* time.cpp                                                            TESTS */
/* By: ChocolateCharlie                                                      */
/* Updated: 2021-11-11                                                       */
/* ************************************************************************* */
#define BOOST_TEST_MODULE Time
#include <boost/test/included/unit_test.hpp>
#include "../src/Time.h"

// Valid Time instance
struct F {
	F() : f_hours(15), f_minutes(32), f_seconds(16), t(f_hours, f_minutes, f_seconds) {}
	~F() {}
	int f_hours, f_minutes, f_seconds;
	Time t;
};

BOOST_FIXTURE_TEST_SUITE(creates_valid_time, F)

BOOST_AUTO_TEST_CASE(hours_are_loaded) {
	BOOST_CHECK_EQUAL(t.get_hours(), f_hours);
}

BOOST_AUTO_TEST_CASE(minutes_are_loaded) {
	BOOST_CHECK_EQUAL(t.get_minutes(), f_minutes);
}

BOOST_AUTO_TEST_CASE(seconds_are_loaded) {
	BOOST_CHECK_EQUAL(t.get_seconds(), f_seconds);
}

BOOST_AUTO_TEST_SUITE_END()

