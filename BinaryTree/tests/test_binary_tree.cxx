#include "catch.hpp"
#include "binary_tree.h"

#include <string>

TEST_CASE("empty, first call", "binary_tree") {
    binary_tree bt;
    REQUIRE(bt.empty());
}

TEST_CASE("size, first call", "binary_tree") {
    binary_tree bt;
    REQUIRE(bt.size() == 0);
}

TEST_CASE("add", "binary_tree") {
    binary_tree bt;
    const int inVal = 42;
    bt.add(inVal);
    REQUIRE(!bt.empty());
    REQUIRE(bt.size() == 1);
}

TEST_CASE("find, bt is empty", "binary_tree") {
    binary_tree bt;
    const int inVal = 42;
    int* out = bt.find(inVal);
    REQUIRE(out == nullptr);
}

TEST_CASE("find, bt is not empty", "binary_tree") {
    binary_tree bt;
    const int inVal = 42;
    bt.add(inVal);
    REQUIRE(!bt.empty());
    REQUIRE(bt.size() == 1);

    int* out = bt.find(inVal);
    REQUIRE(out != nullptr);
    REQUIRE(*out == inVal);
}
