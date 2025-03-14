#include "Json.hpp"

#include <gtest/gtest.h>

using namespace brsbrd;

TEST(JsonString, construction)
{
  Json json{"test"};
  ASSERT_EQ("test", std::get<Json::String>(json.value()));
  ASSERT_EQ(R"("test")", json.serialize());
}

TEST(JsonString, assignation)
{
  Json json{};
  json = "test";
  ASSERT_EQ("test", std::get<Json::String>(json.value()));
  ASSERT_EQ(R"("test")", json.serialize());
}
