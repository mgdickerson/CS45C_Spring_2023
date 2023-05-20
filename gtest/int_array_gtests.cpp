#include <gtest/gtest.h>

#include <sstream>

#include "alloc.hpp"
#include "int_array.hpp"

using namespace std;

TEST(IntArrayTests, Length) {
    Array arr{10};
    EXPECT_EQ(arr.length(), 10);
    EXPECT_EQ(Array{}.length(), 0);
}

TEST(IntArrayTests, Subscript) {
    Array arr{10};
    arr[0] = 3;
    arr[3] = 5;
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[3], 5);
}

TEST(IntArrayTests, Print) {
    stringstream out;

    Array arr{3};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    out << arr;

    EXPECT_EQ(out.str(), "       0       1       2");
}

TEST(IntArrayTests, Read) {
    stringstream in{"1 2 3 4"};

    Array arr{3};
    in >> arr;

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}
