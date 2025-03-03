#include "Json.hpp"

#include <gtest/gtest.h>

using namespace brsbrd;

TEST(Json, defaultConstruction)
{
    Json json{};

    ASSERT_EQ("null", json.toString());
}

TEST(Json, string)
{
    Json json{"tata"};
    ASSERT_EQ(R"("tata")", json.toString());
    json = std::string("toto");
    ASSERT_EQ(R"("toto")", json.toString());
}

TEST(Json, float)
{
    Json json{2.0f};
    ASSERT_EQ("2", json.toString());
    json = 1.5f;
    ASSERT_EQ("1.5", json.toString());
}

TEST(Json, bool)
{
    Json json{false};
    ASSERT_EQ("false", json.toString());
    json = true;
    ASSERT_EQ("true", json.toString());
}

TEST(Json, Array)
{
    Json json{std::vector<Json>{}};
    ASSERT_EQ("[]", json.toString());
    json = Json::Array{{true}, {"toto"},{1.5f}, Json::null};
    ASSERT_EQ(R"([true,"toto",1.5,null])", json.toString());
}

TEST(Json, Object)
{
    Json::Object map{};
    Json json{map};
    ASSERT_EQ("{}", json.toString());

    map["bool"] = true;
    map["string"] = "toto";
    json = map;    
    ASSERT_EQ(R"({"bool":true,"string":"toto"})", json.toString());
}

TEST(Json, ObjectBracket)
{
    Json json{1.5f};
    ASSERT_EQ("1.5", json.toString());

    json["nested"]["object"] = true;    
    ASSERT_EQ(R"({"nested":{"object":true}})", json.toString());
}