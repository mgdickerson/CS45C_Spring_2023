#include <gtest/gtest.h>

#include <sstream>

#include "matrix.hpp"

TEST(MatrixTests, PrintFill) {
    Matrix<double> xs{2, 2};
    xs[0][0] = 1.23232;
    xs[0][1] = 2.5;
    xs[1][0] = 3;
    xs[1][1] = 0;

    std::stringstream out;
    out << xs;
    EXPECT_EQ(out.str(), "");
}
