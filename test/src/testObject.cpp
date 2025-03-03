#include "Json.hpp"

#include <gtest/gtest.h>

using namespace brsbrd;

TEST(JsonObject, construction)
{
  Json::Object map{};
  map["bool"] = true;
  map["string"] = "toto";

  Json json{map};
  ASSERT_EQ(R"({"bool":true,"string":"toto"})", json.serialize());
}

TEST(JsonObject, assignation)
{
  Json::Object map{};
  map["bool"] = true;
  map["string"] = "toto";

  Json json{};
  json = map;
  ASSERT_EQ(R"({"bool":true,"string":"toto"})", json.serialize());
}

TEST(JsonObject, Bracket)
{
  Json json{1.5f};
  ASSERT_EQ("1.5", json.serialize());

  json["nested"]["object"] = true;
  ASSERT_EQ(R"({"nested":{"object":true}})", json.serialize());
}