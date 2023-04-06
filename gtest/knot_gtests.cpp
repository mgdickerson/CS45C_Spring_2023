// ------------------------- Tests File - knot_test.cpp --------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

// Include all of your *.h files you want to unit test:
#include "convert_knots.h"

#include <gtest/gtest.h>
#include <cmath>

namespace {

/// Test the equality of two doubles within the precision of 0.01 (or two decimal places)
bool compare_eq(double v1, double v2) {
  return std::abs(v1 - v2) < std::pow(10, -2);
}

TEST(ConvertKnots, Two) {
  EXPECT_TRUE(compare_eq(0.0383593, knots_to_miles_per_minute(2)));
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
