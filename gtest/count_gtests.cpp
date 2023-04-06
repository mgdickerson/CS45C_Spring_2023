// ------------------------- Tests File - stack_test.cpp -------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

// Include all of your *.h files you want to unit test:
#include "letter_count.h"

#include <gtest/gtest.h>
#include <string>

namespace {

TEST(Count, SimpleString) {
  // Push 'c' on the stack, and make sure we get 'c' back.
  std::string ts = "ABCDEF";
  int char_counts[26] = { 0 };
  count(ts.c_str(), char_counts);
  for (int i = 0; i < 6; ++i) {
    EXPECT_EQ(1, char_counts[i]);
  }
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
