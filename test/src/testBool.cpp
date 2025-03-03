#include "Json.hpp"

#include <gtest/gtest.h>

using namespace brsbrd;

TEST(JsonBool, construction)
{
  Json json{false};
  ASSERT_EQ(false, std::get<bool>(json.value()));
  ASSERT_EQ("false", json.serialize());
}

TEST(JsonBool, assignation)
{
  Json json{};
  json = true;
  ASSERT_EQ(true, std::get<bool>(json.value()));
  ASSERT_EQ("true", json.serialize());
}
