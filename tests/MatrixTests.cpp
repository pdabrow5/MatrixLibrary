#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "../lib/inc/Matrix.hpp"

using namespace Mat;

TEST_CASE("Test default constructor", "[Matrix]")
{
    CHECK_NOTHROW(Mat::Matrix<1, 1>());
    CHECK_NOTHROW(Mat::Matrix<1, 255>());
    CHECK_NOTHROW(Mat::Matrix<255, 1>());
    CHECK_NOTHROW(Mat::Matrix<255, 255>());
}

TEST_CASE("Test float constructor", "[Matrix]")
{
    CHECK_NOTHROW(Mat::Matrix<1, 1>(1.0f));
    CHECK_NOTHROW(Mat::Matrix<1, 255>(-1.0f));
    CHECK_NOTHROW(Mat::Matrix<255, 1>(-3.2f));
    CHECK_NOTHROW(Mat::Matrix<255, 255>(1000000.0f));
}

TEST_CASE("Test float constructor2", "[Matrix]")
{
    CHECK_NOTHROW(Mat::Matrix<1, 1>(1.0f));
    CHECK_NOTHROW(Mat::Matrix<1, 255>(-1.0f));
    CHECK_NOTHROW(Mat::Matrix<255, 1>(-3.2f));
    CHECK_NOTHROW(Mat::Matrix<255, 255>(1000000.0f));

    Matrix<5, 5> M1(1.0f), M2(1.0f);
    CHECK(M1 == M2);
    CHECK(M1.Equals(M2));
}