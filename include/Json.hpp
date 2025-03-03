#ifndef JSON_HPP
#define JSON_HPP

#include <map>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

namespace brsbrd
{
  class Json;
  class Json
  {
    public:
      using Array = std::vector<Json>;
      using Object = std::map<std::string, Json>;
      using Value = std::variant<std::monostate, std::string, float, Object, Array, bool>;
      static constexpr std::monostate null{};

      Json() = default;     
      
      template<typename T>
      requires requires (T arg, Value value)
      {
        value = arg;
      }
      Json(T arg)
      : m_value(arg)
      {}

      inline const Value& value() const
      {
        return m_value;
      }

      Json& addToArray(Value value);
      Json& operator[](const std::string& key);

      std::string serialize() const;
      
    private:
      Value m_value{std::monostate{}};
  };
}

#endif // JSON_HPP