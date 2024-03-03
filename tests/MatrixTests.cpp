#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "../lib/inc/Matrix.hpp"

TEST_CASE("Test default constructor", "[Matrix]")
{
    CHECK_NOTHROW(Mat::Matrix<1, 1>());
    CHECK_NOTHROW(Mat::Matrix<1, 255>());
    CHECK_NOTHROW(Mat::Matrix<255, 1>());
    CHECK_NOTHROW(Mat::Matrix<255, 255>());
}

TEST_CASE("Test float constructor", "[Matrix]")
{
    CHECK_NOTHROW(Mat::Matrix<1, 1>());
    CHECK_NOTHROW(Mat::Matrix<1, 255>());
    CHECK_NOTHROW(Mat::Matrix<255, 1>());
    CHECK_NOTHROW(Mat::Matrix<255, 255>());
}