#include "Json.hpp"

#include <gtest/gtest.h>

using namespace brsbrd;

TEST(JsonArray, construction)
{
  Json::Array array{{true}, {"toto"}, {1.5f}, Json::null};
  Json json{array};
  ASSERT_EQ(R"([true,"toto",1.5,null])", json.serialize());
}

TEST(JsonArray, assignation)
{
  Json json{};
  json = Json::Array{{true}, {"toto"}, {1.5f}, Json::null};
  ASSERT_EQ(R"([true,"toto",1.5,null])", json.serialize());
}

TEST(JsonArray, addToArray)
{
  Json json{};
  json.addToArray({true});
  json.addToArray({"toto"}).addToArray({1.5f}).addToArray({Json::null});
  ASSERT_EQ(R"([true,"toto",1.5,null])", json.serialize());
}
