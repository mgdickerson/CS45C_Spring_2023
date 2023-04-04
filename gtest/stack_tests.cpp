// ------------------------- Tests File - knot_test.cpp --------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

// Include all of your *.h files you want to unit test:
#include "stack.h"

#include <gtest/gtest.h>
#include <cmath>

namespace {

TEST(Stack, PushPop) {
  // Compares two "strings" or `char *` for equality.
  Stack st;
  st.push('c')
  EXPECT_STREQ('c', st.pop());
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
