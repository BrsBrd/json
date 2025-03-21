#include "Json.hpp"

#include <fmt/format.h>
#include <ranges>

// helper type for the visitor #4
template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

namespace brsbrd
{  
  Json& Json::addToArray(Value value)
  {
    if(!std::holds_alternative<Array>(m_value))
    {
      m_value = Array{};
    }
    std::get<Array>(m_value).emplace_back(value);
    return *this;
  }

  Json &Json::operator[](const String& key)
  {
    if(!std::holds_alternative<Object>(m_value))
    {
      m_value = Object{};
    }
    return std::get<Object>(m_value)[key];
  }

  std::string Json::serialize() const
  {
    std::string ret{};
    std::visit(overloaded{
      [&](String str){ ret = fmt::format("{:?}", str); },
      [&](Number f){ ret = fmt::format("{}", f); },
      [&](Bool b){ ret = fmt::format("{}", b); },
      [&](Array array)
      {
        ret = fmt::format("[{}]", fmt::join(std::views::transform(array, [](auto& v){return v.serialize();}), ","));
      },
      [&](Object object)
      {
        ret = fmt::format("{{{}}}", fmt::join(std::views::transform(object,
                                                                    [](auto& pair)
                                                                    {
                                                                      return fmt::format("{:?}:{}", pair.first, pair.second.serialize());
                                                                    }), ","));
      },
      [&](Null){ ret = "null"; },
    }, m_value);
    return ret; 
  }
}
