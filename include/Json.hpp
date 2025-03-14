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
      using Null = std::monostate;
      using String = std::string;
      using Number = float;
      using Bool = bool;
      using Array = std::vector<Json>;
      using Object = std::map<String, Json>;
      using Value = std::variant<Null, String, Number, Object, Array, Bool>;
      static constexpr Null null{};

      Json() = default;     
      
      template<typename T>
      requires requires (T arg, Value value)
      {
        value = arg;
      }
      Json(T arg)
      : m_value(arg)
      {}

      // support non float numbers
      template<typename T>
      requires requires (T arg)
      {
        requires std::is_integral_v<T> || std::is_floating_point_v<T>;
        requires !std::is_same_v<Bool, T>;
        requires !std::is_same_v<Number, T>;
      }
      Json(T arg)
      : m_value(static_cast<Number>(arg))
      {}

      inline const Value& value() const
      {
        return m_value;
      }

      Json& addToArray(Value value);
      Json& operator[](const String& key);

      std::string serialize() const;
      
    private:
      Value m_value{null};
  };
}

#endif // JSON_HPP