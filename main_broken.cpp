#include <cstdint>
#include <stdio.h>
#include <vector>
#include <catch2/catch_all.hpp>

struct A {
  std::vector<float> fields;
};

static A createA() {
  printf("createA called\n");
  A result;
  result.fields.push_back(16);
  return result;
};

static A transformA(const A &other) {
  printf("transformA called\n");
  A result = other;
  result.fields.push_back(3);
  return result;
}

static inline A GlobalA = createA();

struct Struct {
  static inline A StructA = transformA(GlobalA);
};

TEST_CASE("Check") {
  CHECK(Struct::StructA.fields.size() == 2);
  CHECK(Struct::StructA.fields[0] == 16);
  CHECK(Struct::StructA.fields[1] == 3);
}
