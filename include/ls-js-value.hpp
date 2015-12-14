
#ifndef LS_JS_VALUE_HPP
#define LS_JS_VALUE_HPP

#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <limits>
#include <exception>
#include <type_traits>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
//#include <cuchar>
#include <uchar.h>

namespace ls
{
  namespace js
  {
    
    
    class Value
    {
public:
      
      typedef bool boolean_t;
      typedef long integral_t;
      typedef double float_t;
      typedef std::string string_t;
      typedef std::vector<Value*> array_t;
      typedef std::unordered_map<string_t,Value*> object_t;
      
      typedef enum value_type {
        t_undefined
        , t_boolean
        , t_integral
        , t_float
        , t_string
        , t_array
        , t_object
        , t_null
        , t_nan
        , t_infinity
      } type_t;
      
      static const float_t float_nan;
      static const float_t float_infinity;
      static const Value null;
      static const Value NaN;
      static const Value infinity;
      static const string_t value_type_strs[];
      
      typedef union value {
        boolean_t   _boolean;
        integral_t  _integral;
        float_t  _float;
        string_t*   _string;
        array_t*    _array;
        object_t*   _object;
        
      } value_t;
      
      /*
       *  class Value constructors
       */
        
      Value ( );
      
      explicit Value ( bool val );
      
      template <typename T>
      explicit Value ( T val, typename std::enable_if<std::is_integral<T>::value, T>::type=0 )
        : _type( t_integral ), _value( { ._integral = integral_t( val ) } ) {
        std::cout << " <- Value ( integral_t val )";
      }
      
      template <typename T>
      explicit Value ( T val, typename std::enable_if<std::is_floating_point<T>::value, T>::type=0 )
        : _type( t_float ), _value( { ._float = float_t( val ) } ) {
        std::cout << " <- Value ( integral_t val )";
      }
      
      Value ( const char* val );
      
      Value ( string_t val );
      
      Value ( string_t* val );
      
      Value ( array_t val );
      
      Value ( array_t* val );
      
      Value ( object_t val );
      
      Value ( object_t* val );
      
      explicit Value ( type_t val );
      
//      Value ( Value& val );
      
      /*
       *  class Value cast operators
       */
      
      operator boolean_t ( ) const;
      
      operator integral_t ( ) const;
      
      operator float_t ( ) const;
      
      operator string_t ( ) const;
      
      operator array_t ( ) const;
      
      operator object_t ( ) const;
      
      /*
       *  class Value equivalence methods
       */
      
      bool equivalent ( boolean_t val ) const;
      
      template <typename T>
      bool equivalent ( T val, typename std::enable_if<std::is_integral<T>::value, T>::type=0 ) const {
        if ( _type == t_integral ) return val == _value._integral;
        if ( _type == t_float ) return float_t( val ) == _value._float;
        return false;
      }

      
      bool equivalent ( float_t val ) const;
      
      bool equivalent ( const char* val ) const;
      
      bool equivalent ( string_t val ) const;
      
      bool equivalent ( string_t* val ) const;
      
      bool equivalent ( array_t val ) const;
      
      bool equivalent ( array_t* val ) const;
      
      bool equivalent ( object_t val ) const;
      
      bool equivalent ( object_t* val ) const;
      
      /*
       *  class Value type methods
       */
      
      bool is_null ( ) const;
      
      bool is_bool ( ) const;
      
      bool is_int ( ) const;
      
      bool is_float ( ) const;
      
      bool is_nan ( ) const;

      bool is_infinity ( ) const;

      bool is_number ( ) const;
      
      bool is_string ( ) const;
      
      bool is_array ( ) const;
      
      bool is_object ( ) const;
      
      type_t type ( ) const;
      
      const string_t get_type ( ) const;
      
protected:
      
      type_t _type;
      value_t _value;
      
      /*
       *  static class Value helpers
       */
      
      static string_t _IToS ( integral_t val );
      static string_t _FToS ( float_t val );
      static string_t _Concat ( array_t* val );
      
    };  // class Value

//    const Value::float_t Value::float_nan = std::nan("NaN");
//    const Value::float_t Value::float_infinity = std::numeric_limits<float_t>::infinity();

    /*
     *  external static class Value support
     */

//    std::ostream& operator<< ( std::ostream& os, Value val );
    
  };  // namespace js

};  // namespace ls

/*
 *  external static class Value support
 */

//std::ostream& operator<< ( std::ostream& os, ls::js::Value val )
//{
//  using namespace ls::js;
//  
//  switch ( val.type() ) {
//    case Value::t_null:
//    case Value::t_boolean:
//    case Value::t_integral:
//    case Value::t_float:
//    case Value::t_string:
//    case Value::t_array:
//    case Value::t_object:
//      return os << Value::string_t( val );
//  }
//  return os << "undefined";
//}


#endif  // LS_JS_VALUE_HPP


