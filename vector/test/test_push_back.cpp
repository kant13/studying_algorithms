#include <vector>
#include "catch.hpp"
#include "vector.h"


TEST_CASE("push_back", "vector") {
  std::vector<int> sample;
  dsa::vector<int> verifiable;
  const int kN = 10'000;
  for(int i = 0; i < kN ; ++i) {
    sample.push_back(i);
    verifiable.push_back(i);
    REQUIRE_NOTHROW(sample.size() == verifiable.size());
    REQUIRE_NOTHROW(sample.at(i) == verifiable.at(i));
  }
}
