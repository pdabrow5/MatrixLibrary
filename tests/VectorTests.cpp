#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

#include "../lib/inc/Vector.hpp"

#include <iostream>
#include <cmath>

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

TEST_CASE("Test array constructor", "[Vector]")
{
    CHECK_NOTHROW(Mat::Vector<3>({1.0f, 2.0f, 3.0f}));
    CHECK_NOTHROW(Mat::Vector<1>({3.0f}));

    Mat::Vector<1> V1({1.0f});
    Mat::Vector<3> V2({1.0f, -1.0f}); //important point!!!
    Mat::Vector<12> V3({1, 2, 3,
                        4, 5, 6,
                        7, 8, 9,
                        10, 11, 12});
    CHECK(V1.Size() == 1);
    CHECK(V2.Size() == 3);
    CHECK(V3.Size() == 12);

    CHECK(V1(0) == 1.0f);

    CHECK(V2(0) == 1.0f);
    CHECK(V2(1) == -1.0f);
    CHECK(V2(2) == 0.0f); // unspecified element in initalizer list will have default value!!!

    for(int i = 0; i < V3.Size(); ++i)
    {
        CHECK(V3(i) == (float)(i + 1));
    }
}

TEST_CASE("Test operator()", "[Vector]")
{
    Mat::Vector<65535> V(123.0f);

    CHECK(V(0) == V(65534));
    CHECK(V(0) == 123.0f);

    V(0) = 0.0f;
    V(65534) = 1.0f;

    CHECK(V(65534) == 1.0f);
    CHECK(V(0) == 0.0f);
}

TEST_CASE("Test operator+=(const Vector<length>& other)", "[Vector]")
{
    Mat::Vector<5> V1({1, 2, 3, 4, 5});
    const Mat::Vector<5> V2({5, 4, 3, 2, 1});
    const Mat::Vector<5> V3(6);
    V1 += V2;
    CHECK(V1 == V3);

    const Mat::Vector<5> V4({-1, -2, -3, -2, -1});
    const Mat::Vector<5> V5({5, 4, 3, 4, 5});
    V1 += V4;
    CHECK(V1 == V5);
}

TEST_CASE("Test operator+=(float val)", "[Vector]")
{
    Mat::Vector<5> V1({1, 2, 3, 4, 5});
    const Mat::Vector<5> V2({2.5, 3.5, 4.5, 5.5, 6.5});
    V1 += 1.5f;
    CHECK(V1 == V2);

    Mat::Vector<5> V3({-1, -2, -3, -2, -1});
    const Mat::Vector<5> V4({-3, -4, -5, -4, -3});
    V3 += -2.0f;
    CHECK(V3 == V4);
}

TEST_CASE("Test Equals()", "[Vector]")
{
    const Mat::Vector<5> V1({1, 2, 3, 4, 5});
    const Mat::Vector<5> V2({2.5, 3.5, 4.5, 5.5, 6.5});
    CHECK(V1.Equals(V2) == false);
    CHECK(V1.Equals(V2, 1.6) == true);
    CHECK(V1.Equals((V2 - 3.0f), 1.5001) == true); // V2 - 3 = {-0.5, 0.5, 1.5, 2.5, 3.5}
    CHECK(V1.Equals((V2 - 3.0f), 1.4999) == false); // V2 - 3 = {-0.5, 0.5, 1.5, 2.5, 3.5}
}

TEST_CASE("Test operator*=(float val)", "[Vector]")
{
    Mat::Vector<5> V1({1.5, 2.5, 3.5, 4.5, 5.5});
    Mat::Vector<5> V2({4.5, 7.5, 10.5, 13.5, 16.5});
    V1 *= 2.0f;
    V1 *= 3.0f;
    V2 *= (2.0f / 3.0f);
    V2 *= 3.0f;
    CHECK(V1.Equals(V2));
}

TEST_CASE("Test operator*(const Vector<length>& other)", "[Vector]")
{
    Mat::Vector<5> V1({1.5, 2.5, 3.5, 4.5, 5.5});
    Mat::Vector<5> V2({4.5, 7.5, 10.5, 13.5, 16.5});
    CHECK((V1 * V2) == 213.75);

    Mat::Vector<2> V3(-1.0f);
    Mat::Vector<2> V4(3.5);
    CHECK((V3 * V4) == -7.0f);
}

TEST_CASE("Test Norm()", "[Vector]")
{
    Mat::Vector<100> V(1);
    CHECK(V.Norm() == 10.0f);

    Mat::Vector<5> V1({1.5, 2.5, 3.5, 4.5, 5.5});
    CHECK(std::sqrt(V1 * V1) == V1.Norm());

    Mat::Vector<5> V2({4.5, 7.5, 10.5, 13.5, 16.5});
    CHECK(std::sqrt(V2 * V2) == V2.Norm());
}