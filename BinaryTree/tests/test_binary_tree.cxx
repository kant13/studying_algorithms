#include "catch.hpp"
#include "binary_tree.h"

#include <string>

TEST_CASE("empty, first call", "binary_tree") {
    binary_tree bt;
    REQUIRE(bt.empty() == true);
}

TEST_CASE("size, first call", "binary_tree") {
    binary_tree bt;
    REQUIRE(bt.size() == 0);
}

TEST_CASE("add, 1 node", "binary_tree") {
    binary_tree bt;
    bt.add(42);
    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 1);
}

TEST_CASE("add, 2 identical nodes", "binary_tree") {
    binary_tree bt;
    bt.add(42);
    bt.add(42);
    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 1);
}

TEST_CASE("add, 2 node", "binary_tree") {
    binary_tree bt;
    bt.add(1);
    bt.add(2);
    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 2);
}

TEST_CASE("find, bt is empty", "binary_tree") {
    binary_tree bt;
    const int inVal = 42;
    REQUIRE(bt.find(inVal) == false);
}

TEST_CASE("find, bt has 1 node", "binary_tree") {
    binary_tree bt;
    const int inVal = 42;
    bt.add(inVal);
    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 1);
    REQUIRE(bt.find(inVal));
}

TEST_CASE("find, bt has 2 node: 1, 2", "binary_tree") {
    binary_tree bt;
    bt.add(1);
    bt.add(2);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 2);

    REQUIRE(bt.find(0) == false);
    REQUIRE(bt.find(1));
    REQUIRE(bt.find(2));
}


/*
* Pre-order 10 → 5 → 2 → 7 → 15 → 12 → 20
       10
      /  \
     5    15
    /  \  /  \
    2  7  12  20
*/
TEST_CASE("find, 10 5 2 7 15 12 30", "binary_tree") {
    binary_tree bt;
    bt.add(10);
    bt.add(5);
    bt.add(2);
    bt.add(7);
    bt.add(15);
    bt.add(12);
    bt.add(20);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 7);

    REQUIRE(bt.find(2));
    REQUIRE(bt.find(7));
    REQUIRE(bt.find(12));
    REQUIRE(bt.find(20));
}

/*
* Pre-order 10 → 5 → 2 → 7 → 15 → 12 → 20
       10
      /  \
     5    15
    /  \  /  \
    2  7  12  20
*/
TEST_CASE("erase last left-left node, 10 5 2 7 15 12 30", "binary_tree") {
    binary_tree bt;
    bt.add(10);
    bt.add(5);
    bt.add(2);
    bt.add(7);
    bt.add(15);
    bt.add(12);
    bt.add(20);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 7);

    // last left-left node
    REQUIRE(bt.find(2));
    bt.erase(2);
    REQUIRE(bt.size() == 6);
    REQUIRE(bt.find(2) == false);

}

/*
* Pre-order 10 → 5 → 2 → 7 → 15 → 12 → 20
       10
      /  \
     5    15
    /  \  /  \
    2  7  12  20
*/
TEST_CASE("erase right-right node, 10 5 2 7 15 12 30", "binary_tree") {
    binary_tree bt;
    bt.add(10);
    bt.add(5);
    bt.add(2);
    bt.add(7);
    bt.add(15);
    bt.add(12);
    bt.add(20);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 7);

    // last right-right node
    REQUIRE(bt.find(20));
    bt.erase(20);
    REQUIRE(bt.size() == 6);
    REQUIRE(bt.find(20) == false);
}

/*
* Pre-order 10 → 5 → 2 → 7 → 15 → 12 → 20
       10
      /  \
     5    15
    /  \  /  \
    2  7  12  20
*/
TEST_CASE("erase 5 node, 10 5 2 7 15 12 30", "binary_tree") {
    binary_tree bt;
    bt.add(10);
    bt.add(5);
    bt.add(2);
    bt.add(7);
    bt.add(15);
    bt.add(12);
    bt.add(20);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 7);

    REQUIRE(bt.find(5));
    bt.erase(5);
    REQUIRE(bt.size() == 6);
    REQUIRE(bt.find(5) == false);
}