#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "../lib/inc/Matrix.hpp"

#include <iostream>

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

TEST_CASE("Test multiply", "[Matrix]")
{
    Matrix<4, 6> J
    {{
        1.0f, 2.0f, 3.0f, 4.0f,  5.0f,  6.0f,
        7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f, 17.0f, 18.0f,
        19.0f, 20.0f, 21.0f, 22.0f, 23.0f, 24.0f
    }};

    Matrix<6, 1>  F
    {{
        1.0f,
        2.0f,
        3.0f,
        4.0f,
        5.0f,
        6.0f
    }};
    auto R = J * F;
    Matrix<4, 1> Result
    {{
        91.0f,
        217.0f,
        343.0f,
        469.0f
    }};
    std::cout << "R: " << R(0,0) << ", " << R(1,0) << ", " << R(2,0) << ", " << R(3,0) << std::endl;
    CHECK(R.Equals(Result));
}