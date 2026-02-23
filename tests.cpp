#define TESTING
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.cpp"

TEST_CASE("Bubble - One Pass", "[T1]")
{
    SECTION("One pass moves largest to end") {
        vector<int> v = {64, 34, 25, 12, 22};
        bubble(v, 5);
        REQUIRE(v[0] == 34);
        REQUIRE(v[1] == 25);
        REQUIRE(v[2] == 12);
        REQUIRE(v[3] == 22);
        REQUIRE(v[4] == 64);
    }

    SECTION("Second pass over first 4 elements") {
        vector<int> v = {34, 25, 12, 22, 64};
        bubble(v, 4);
        REQUIRE(v[0] == 25);
        REQUIRE(v[1] == 12);
        REQUIRE(v[2] == 22);
        REQUIRE(v[3] == 34);
        REQUIRE(v[4] == 64);
    }

    SECTION("Pass on already sorted portion") {
        vector<int> v = {1, 2, 3, 4, 5};
        bubble(v, 5);
        REQUIRE(v == vector<int>{1, 2, 3, 4, 5});
    }

    SECTION("Pass on two elements") {
        vector<int> v = {9, 1};
        bubble(v, 2);
        REQUIRE(v[0] == 1);
        REQUIRE(v[1] == 9);
    }
}

TEST_CASE("Selection - Find Min Index", "[T2]")
{
    SECTION("Find min in entire array") {
        vector<int> v = {40, 10, 30, 50, 20};
        int idx = selection(v, 0, 5);
        REQUIRE(idx == 1);
        REQUIRE(v[idx] == 10);
    }

    SECTION("Find min in subrange") {
        vector<int> v = {40, 10, 30, 50, 20};
        int idx = selection(v, 2, 5);
        REQUIRE(idx == 4);
        REQUIRE(v[idx] == 20);
    }

    SECTION("Find min when min is at start") {
        vector<int> v = {5, 10, 30, 50, 20};
        int idx = selection(v, 0, 5);
        REQUIRE(idx == 0);
    }

    SECTION("Find min in two-element range") {
        vector<int> v = {40, 10, 30, 50, 20};
        int idx = selection(v, 1, 3);
        REQUIRE(idx == 1);
        REQUIRE(v[idx] == 10);
    }

    SECTION("Find min with duplicates") {
        vector<int> v = {7, 7, 7, 7, 7};
        int idx = selection(v, 0, 5);
        REQUIRE(idx == 0);
    }
}

TEST_CASE("Insertion - Insert One Element", "[T3]")
{
    SECTION("Insert into sorted prefix step by step") {
        vector<int> v = {40, 10, 30, 50, 20};

        insertion(v, 1);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 40);

        insertion(v, 2);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 30);
        REQUIRE(v[2] == 40);

        insertion(v, 3);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 30);
        REQUIRE(v[2] == 40);
        REQUIRE(v[3] == 50);

        insertion(v, 4);
        REQUIRE(v == vector<int>{10, 20, 30, 40, 50});
    }

    SECTION("Insert element already in place") {
        vector<int> v = {10, 20, 30, 50, 40};
        insertion(v, 1);
        REQUIRE(v[0] == 10);
        REQUIRE(v[1] == 20);
    }

    SECTION("Insert element to front") {
        vector<int> v = {50, 40, 30, 20, 10};
        insertion(v, 1);
        REQUIRE(v[0] == 40);
        REQUIRE(v[1] == 50);
    }
}

TEST_CASE("Edge Cases", "[T4]")
{
    SECTION("Bubble on single element") {
        vector<int> v = {42};
        bubble(v, 1);
        REQUIRE(v[0] == 42);
    }

    SECTION("Selection on single element range") {
        vector<int> v = {42, 10};
        int idx = selection(v, 0, 1);
        REQUIRE(idx == 0);
    }

    SECTION("All identical elements") {
        vector<int> v = {5, 5, 5, 5, 5};
        bubble(v, 5);
        REQUIRE(v == vector<int>{5, 5, 5, 5, 5});

        int idx = selection(v, 0, 5);
        REQUIRE(idx == 0);

        insertion(v, 1);
        REQUIRE(v == vector<int>{5, 5, 5, 5, 5});
    }

    SECTION("Negative numbers") {
        vector<int> v = {3, -1, 4, -5, 2};
        bubble(v, 5);
        REQUIRE(v[4] == 4);

        vector<int> v2 = {3, -1, 4, -5, 2};
        int idx = selection(v2, 0, 5);
        REQUIRE(idx == 3);
        REQUIRE(v2[idx] == -5);

        vector<int> v3 = {3, -1, 4, -5, 2};
        insertion(v3, 1);
        REQUIRE(v3[0] == -1);
        REQUIRE(v3[1] == 3);
    }

    SECTION("Two elements reversed") {
        vector<int> v = {9, 1};
        bubble(v, 2);
        REQUIRE(v == vector<int>{1, 9});

        vector<int> v2 = {9, 1};
        int idx = selection(v2, 0, 2);
        REQUIRE(idx == 1);

        vector<int> v3 = {9, 1};
        insertion(v3, 1);
        REQUIRE(v3 == vector<int>{1, 9});
    }
}
