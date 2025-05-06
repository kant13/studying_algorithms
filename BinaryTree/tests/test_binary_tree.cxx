#include "catch.hpp"
#include "BinaryTree.h"

#include <iostream>
#include <string>


TEST_CASE("BinaryTree: empty method", "[BinaryTree]") {
    BinaryTree bt;
    REQUIRE(bt.empty() == true);

    bt.add(10);
    REQUIRE(bt.empty() == false);

    bt.clear();
    REQUIRE(bt.empty() == true);
}

TEST_CASE("BinaryTree: size method", "[BinaryTree]") {
    BinaryTree bt;
    REQUIRE(bt.size() == 0);

    bt.add(10);
    REQUIRE(bt.size() == 1);

    bt.add(20);
    REQUIRE(bt.size() == 2);

    bt.erase(10);
    REQUIRE(bt.size() == 1);

    bt.clear();
    REQUIRE(bt.size() == 0);
}

TEST_CASE("BinaryTree: add method (single value)", "[BinaryTree]") {
    BinaryTree bt;
    bt.add(10);
    REQUIRE(bt.size() == 1);
    REQUIRE(bt.find(10) == true);

    bt.add(20);
    REQUIRE(bt.size() == 2);
    REQUIRE(bt.find(20) == true);

    bt.add(10); // Adding duplicate value
    REQUIRE(bt.size() == 2); // Size should remain the same
}

TEST_CASE("BinaryTree: add method (multiple values)", "[BinaryTree]") {
    BinaryTree bt;
    std::vector<int> values = {10, 20, 5, 15};
    bt.add(values);

    REQUIRE(bt.size() == values.size());
    for (int val : values) {
        REQUIRE(bt.find(val) == true);
    }
}

TEST_CASE("BinaryTree: erase method", "[BinaryTree]") {
    BinaryTree bt;
    std::vector<int> values = {10, 20, 5, 15};
    bt.add(values);

    REQUIRE(bt.size() == values.size());

    bt.erase(10);
    REQUIRE(bt.size() == values.size() - 1);
    REQUIRE(bt.find(10) == false);

    bt.erase(5);
    REQUIRE(bt.size() == values.size() - 2);
    REQUIRE(bt.find(5) == false);

    bt.erase(100); // Erasing non-existent value
    REQUIRE(bt.size() == values.size() - 2); // Size should remain unchanged
}

TEST_CASE("BinaryTree: find method", "[BinaryTree]") {
    BinaryTree bt;
    REQUIRE(bt.find(10) == false); // Empty tree

    bt.add(10);
    REQUIRE(bt.find(10) == true);
    REQUIRE(bt.find(20) == false);

    bt.add(20);
    REQUIRE(bt.find(20) == true);

    bt.erase(10);
    REQUIRE(bt.find(10) == false);
}

TEST_CASE("BinaryTree: clear method", "[BinaryTree]") {
    BinaryTree bt;
    bt.add({10, 20, 5, 15});
    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 4);

    bt.clear();
    REQUIRE(bt.empty() == true);
    REQUIRE(bt.size() == 0);
}

TEST_CASE("BinaryTree: preOrder method", "[BinaryTree]") {
    BinaryTree bt;
    std::vector<int> values = {10, 5, 15, 2, 7, 12, 20};
    bt.add(values);

    std::vector<int> expectedPreOrder = {10, 5, 2, 7, 15, 12, 20};
    REQUIRE(bt.preOrder() == expectedPreOrder);

    bt.erase(7);
    expectedPreOrder = {10, 5, 2, 15, 12, 20};
    REQUIRE(bt.preOrder() == expectedPreOrder);
}

TEST_CASE("add, 1 node", "BinaryTree") {
    BinaryTree bt;
    bt.add(42);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 1);
}

TEST_CASE("add, 2 identical nodes", "BinaryTree") {
    BinaryTree bt;
    bt.add(42);
    bt.add(42);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 1);
}

TEST_CASE("add, 2 node", "BinaryTree") {
    BinaryTree bt;
    bt.add({ 1, 2 });

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 2);
}

TEST_CASE("find, bt is empty", "BinaryTree") {
    BinaryTree bt;
    const int inVal = 42;
    REQUIRE(bt.find(inVal) == false);
}

TEST_CASE("find, bt has 1 node", "BinaryTree") {
    BinaryTree bt;
    const int inVal = 42;
    bt.add(inVal);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 1);
    REQUIRE(bt.find(inVal));
}

TEST_CASE("find, bt has 2 node: 1, 2", "BinaryTree") {
    BinaryTree bt;
    bt.add({ 1, 2 });

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 2);

    REQUIRE(bt.find(0) == false);
    REQUIRE(bt.find(1));
    REQUIRE(bt.find(2));
}

/*
* Pre-order 10, 5, 2, 7, 15, 12, 20
       10
      /  \
     5    15
    /  \  /  \
    2  7  12  20
*/
TEST_CASE("find, 10 5 2 7 15 12 30", "BinaryTree") {
    BinaryTree bt;
    const std::vector<int> in{ 10, 5, 2, 7, 15, 12, 20 };
    bt.add(in);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 7);

    REQUIRE(bt.find(2));
    REQUIRE(bt.find(7));
    REQUIRE(bt.find(12));
    REQUIRE(bt.find(20));
}

/*
* Pre-order 10, 5, 2, 7, 15, 12, 20
       10
      /  \
     5    15
    /  \  /  \
    2  7  12  20
*/
TEST_CASE("erase last left-left 2 node, 10 5 2 7 15 12 30", "BinaryTree") {
    BinaryTree bt;
    const std::vector<int> in{ 10, 5, 2, 7, 15, 12, 20 };
    bt.add(in);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 7);

    // last left-left node
    REQUIRE(bt.find(2));
    bt.erase(2);
    REQUIRE(bt.size() == 6);
    REQUIRE(bt.find(2) == false);
}

/*
* Pre-order 10, 5, 2, 7, 15, 12, 20
       10
      /  \
     5    15
    /  \  /  \
    2  7  12  20
*/
TEST_CASE("erase right-right node 20, 10 5 2 7 15 12 30", "BinaryTree") {
    BinaryTree bt;
    const std::vector<int> in{ 10, 5, 2, 7, 15, 12, 20 };
    bt.add(in);

    const auto out = bt.preOrder();
    REQUIRE(in.size() == out.size());
    REQUIRE(in == out);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 7);

    // last right-right node
    REQUIRE(bt.find(20));
    bt.erase(20);
    REQUIRE(bt.size() == 6);
    REQUIRE(bt.find(20) == false);
}

/*
* Pre-order 15, 9, 3, 1, 8, 4, 12, 23, 17
        15
       /  \
      9    23
     / \    /
     3 12  17
    / \
    1 8
     /
    4
*/
TEST_CASE("erase 8 node, 15, 9, 3, 1, 8, 4, 12, 23, 17", "BinaryTree") {
    BinaryTree bt;
    std::vector<int> in{ 15, 9, 3, 1, 8, 4, 12, 23, 17 };
    bt.add(in);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 9);

    REQUIRE(bt.find(8));
    bt.erase(8);
    REQUIRE(bt.size() == 8);
    REQUIRE(bt.find(8) == false);

    const auto out = bt.preOrder();
    in.erase(std::remove(in.begin(), in.end(), 8), in.end());
    REQUIRE(in.size() == out.size());
    REQUIRE(in == out);
}

/*
* Pre-order 15, 9, 3, 1, 8, 4, 12, 23, 17
        15
       /  \
      9    23
     / \    /
     3 12  17
    / \
    1 8
     /
    4
*/
TEST_CASE("preOrder, 15, 9, 3, 1, 8, 4, 12, 23, 17", "BinaryTree") {
    BinaryTree bt;
    const std::vector<int> in{ 15, 9, 3, 1, 8, 4, 12, 23, 17 };
    bt.add(in);
    const auto out = bt.preOrder();
    REQUIRE(in.size() == out.size());
    REQUIRE(in == out);
}

/*
* Pre-order 15, 9, 3, 1, 8, 4, 12, 23, 17
        15
       /  \
      9    23
     / \    /
     3 12  17
    / \
    1 8
     /
    4
*/
TEST_CASE("erase 9, 15, 9, 3, 1, 8, 4, 12, 23, 17", "BinaryTree") {
    BinaryTree bt;
    const std::vector<int> in{ 15, 9, 3, 1, 8, 4, 12, 23, 17 };
    bt.add(in);

    std::cout << "pre order" << std::endl;
    bt.printPreOrder();
    std::cout << std::endl;

    std::cout << "post order" << std::endl;
    bt.printPostOrder();
    std::cout << std::endl;

    std::cout << "in order" << std::endl;
    bt.printInOrder();
    std::cout << std::endl;

    std::cout << "level order BFS" << std::endl;
    bt.printBFS();
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "DFS" << std::endl;
    bt.printDFS();
    std::cout << std::endl;

    REQUIRE(bt.isBalanced() == false);

    REQUIRE(bt.empty() == false);
    REQUIRE(bt.size() == 9);

    REQUIRE(bt.find(9));
    bt.erase(9);
    REQUIRE(bt.size() == 8);
    REQUIRE(bt.find(9) == false);

    const auto out = bt.preOrder();
    REQUIRE(std::vector<int>{ 15, 12, 3, 1, 8, 4, 23, 17} == out);
}

TEST_CASE("isBalanced 2, 3, 1, 0", "BinaryTree") {
    BinaryTree bt;
    const std::vector<int> in{ 2, 3, 1 };
    bt.add(in);

    REQUIRE(bt.isBalanced() == true);
}
