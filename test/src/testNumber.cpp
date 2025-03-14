#include "Json.hpp"

#include <gtest/gtest.h>

using namespace brsbrd;

TEST(JsonNumber, constructionFromFloat)
{
  Json json{2.0f};
  ASSERT_EQ(2.0f, std::get<Json::Number>(json.value()));
  ASSERT_EQ("2", json.serialize());
}

TEST(JsonNumber, assignationFromFloat)
{
  Json json{};
  json = 1.5f;
  ASSERT_EQ(1.5f, std::get<Json::Number>(json.value()));
  ASSERT_EQ("1.5", json.serialize());
}

TEST(JsonNumber, constructionFromDouble)
{
  Json json{2.0};
  ASSERT_EQ(2.0f, std::get<Json::Number>(json.value()));
  ASSERT_EQ("2", json.serialize());
}

TEST(JsonNumber, assignationFromDouble)
{
  Json json{};
  json = 2.0;
  ASSERT_EQ(2.0f, std::get<Json::Number>(json.value()));
  ASSERT_EQ("2", json.serialize());
}

TEST(JsonNumber, constructionFromInt)
{
  Json json{3};
  ASSERT_EQ(3.0f, std::get<Json::Number>(json.value()));
  ASSERT_EQ("3", json.serialize());
}

TEST(JsonNumber, assignationFromInt)
{
  Json json{};
  json = 3;
  ASSERT_EQ(3.0f, std::get<Json::Number>(json.value()));
  ASSERT_EQ("3", json.serialize());
}
