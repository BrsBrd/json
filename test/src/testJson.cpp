#include "Json.hpp"

#include <gtest/gtest.h>
#include <iostream>

using namespace brsbrd;

TEST(Json, defaultConstruction)
{
  Json json{};
  ASSERT_EQ("null", json.serialize());
}

TEST(Json, nominalCase)
{
  Json json{};

  json["null"] = Json::null;
  json["string"] = "This is a string";
  json["number"] = 1.5f;
  json["bool"] = true;
  json["array"] = Json::Array{{"this"}, {"is"}, {1.0f}, {true}, {"array"}, {"not"}, {Json::null}};
  json["nested"]["object"] = true;
  json["nested"]["array"] = Json::Array{{"array in array:", {std::get<Json::Array>(json["array"].value())}}};

  std::string expected{R"({"array":["this","is",1,true,"array","not",null],"bool":true,"nested":{"array":["array in array:",["this","is",1,true,"array","not",null]],"object":true},"null":null,"number":1.5,"string":"This is a string"})"};
  ASSERT_EQ(expected, json.serialize());
}