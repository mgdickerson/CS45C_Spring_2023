#include <gtest/gtest.h>

#include <sstream>

#include "array.hpp"

TEST(ArrayTests, PrintFill) {
    {
        Array<double> xs{3};
        xs[0] = 1.23232;
        xs[1] = 5.0;
        xs[2] = 3.141592;

        std::stringstream out;
        out << xs;
        EXPECT_EQ(out.str(), "");
    }

    {
        Array<int> xs{3};
        xs[0] = 1;
        xs[1] = 2;
        xs[2] = 3;

        std::stringstream out;
        out << xs;
        EXPECT_EQ(out.str(), "");
    }
}
