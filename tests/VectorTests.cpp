#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "../lib/inc/Vector.hpp"

TEST_CASE("Test default constructor", "[Vector]")
{
    CHECK_NOTHROW(Mat::Vector<1>());
    CHECK_NOTHROW(Mat::Vector<65535>());
    Mat::Vector<65535> V1;
    Mat::Vector<1> V2;
    Mat::Vector<1234> V3;
    CHECK(V1.Size() == 65535);
    CHECK(V2.Size() == 1);
    CHECK(V3.Size() == 1234);
}

TEST_CASE("Test float constructor", "[Vector]")
{
    CHECK_NOTHROW(Mat::Vector<1>(5.0f));
    CHECK_NOTHROW(Mat::Vector<65535>(-1.0f));

    Mat::Vector<65535> V1(1.0f);
    Mat::Vector<1> V2(-5.5f);
    Mat::Vector<1234> V3(10001.0f);
    CHECK(V1.Size() == 65535);
    CHECK(V2.Size() == 1);
    CHECK(V3.Size() == 1234);

    CHECK(V1(0) == 1.0f);
    CHECK(V2(0) == -5.5f);
    CHECK(V3(1233) == 10001.0f);
}