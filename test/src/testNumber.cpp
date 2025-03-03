#include "Json.hpp"

#include <gtest/gtest.h>

using namespace brsbrd;

TEST(JsonNumber, construction)
{
  Json json{2.0f};
  ASSERT_EQ(2.0f, std::get<float>(json.value()));
  ASSERT_EQ("2", json.serialize());
}

TEST(JsonNumber, assignation)
{
  Json json{};
  json = 1.5f;
  ASSERT_EQ(1.5f, std::get<float>(json.value()));
  ASSERT_EQ("1.5", json.serialize());
}
