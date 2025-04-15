#include "catch.hpp"
#include "binary_tree.h"

#include <string>

TEST_CASE("empty", "binary_tree") {
    binary_tree<int, std::string> bt;
    REQUIRE(bt.empty());
}

TEST_CASE("count", "binary_tree") {
    binary_tree<int, std::string> bt;
    REQUIRE(bt.count() == 0);
}

TEST_CASE("find", "binary_tree") {
    const int key = 1;
    const std::string key_value = "foo";

    binary_tree<int, std::string> bt;
    REQUIRE(bt.empty());
    REQUIRE(bt.count() == 0);

    bt.insert(key, key_value);
    REQUIRE(!bt.empty());
    REQUIRE(bt.count() == 1u);

    std::string* n = bt.find(key);
    REQUIRE(n != nullptr);
    REQUIRE(*n == key_value);
}

TEST_CASE("Node to be deleted is left", "erase") {
    binary_tree<int, int> bt;
    bt.insert(50, 50);
    bt.insert(30, 30);
    bt.insert(70, 70);
    bt.insert(20, 20);
    bt.insert(40, 40);
    bt.insert(60, 60);
    bt.insert(80, 80);

    REQUIRE(!bt.empty());
    REQUIRE(bt.count() == 7);

    bt.print_infix_travers(); std::cout << std::endl;
    bt.erase(20);
    bt.print_infix_travers(); std::cout << std::endl;
    std::cout << std::endl;

    int* n = bt.find(20);
    REQUIRE(n == nullptr);

    REQUIRE(!bt.empty());
    REQUIRE(bt.count() == 6);
}

TEST_CASE("Node to be deleted has only one child", "erase") {
    binary_tree<int, int> bt;
    REQUIRE(bt.empty());
    REQUIRE(bt.count() == 0u);

    bt.insert(50, 50);
    bt.insert(30, 30);
    bt.insert(70, 70);
    bt.insert(40, 40);
    bt.insert(60, 60);
    bt.insert(80, 80);

    REQUIRE(!bt.empty());
    REQUIRE(bt.count() == 6);

    bt.print_infix_travers(); std::cout << std::endl;
    bt.erase(30);
    bt.print_infix_travers(); std::cout << std::endl;
    std::cout << std::endl;

    int* n = bt.find(30);
    REQUIRE(n == nullptr);

    REQUIRE(!bt.empty());
    REQUIRE(bt.count() == 5);
}

TEST_CASE("Node to be deleted has only two child", "erase") {
    binary_tree<int, int> bt;
    REQUIRE(bt.empty());
    REQUIRE(bt.count() == 0u);

    bt.insert(8, 8);
    bt.insert(10, 10);
    bt.insert(14, 14);
    bt.insert(2, 2);
    bt.insert(5, 5);
    bt.insert(3, 3);
    bt.insert(7, 7);
    bt.insert(9, 9);
    bt.insert(12, 12);
    bt.insert(4, 4);

    bt.print_infix_travers(); std::cout << std::endl;
    bt.erase(12);
    bt.print_infix_travers(); std::cout << std::endl;
    std::cout << std::endl;

    REQUIRE(!bt.empty());
}
