// ------------------------- Tests File - stack_test.cpp -------------------- //
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

TEST(Stack, PushPopEQ) {
  // Push 'c' on the stack, and make sure we get 'c' back.
  Stack st;
  st.push('c');
  EXPECT_EQ('c', st.pop());
}

TEST(Stack, PushPopNE) {
  // Push 'c' on the stack, make sure we dont get 'd' back.
  Stack st;
  st.push('c');
  EXPECT_NE('d', st.pop());
}

TEST(Stack, Empty) {
  Stack st;
  EXPECT_TRUE(st.isEmpty());
  st.push('c');
  EXPECT_FALSE(st.isEmpty());
  st.pop();
  EXPECT_TRUE(st.isEmpty());
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
