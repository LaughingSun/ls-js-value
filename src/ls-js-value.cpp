
#ifndef VALUE_HPP
#define VALUE_HPP

#include <cstdlib>
#include <cstring>
#include <cctype>
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
      typedef double floating_t;
      typedef std::string string_t;
      typedef std::vector<Value*> array_t;
      typedef std::unordered_map<string_t,Value*> object_t;
      
      typedef enum value_type {
        t_undefined
        , t_null
        , t_boolean
        , t_integral
        , t_floating
        , t_string
        , t_array
        , t_object
      } type_t;
      
      static const string_t value_type_strs[];
      
      typedef union value {
        boolean_t   _boolean;
        integral_t  _integral;
        floating_t  _floating;
        string_t*   _string;
        array_t*    _array;
        object_t*   _object;
        
      } value_t;
      
      /*
       *  class Value constructors
       */
        
      Value ( ) : _type( t_null ), _value( { ._boolean = boolean_t( false ) } ) {
        std::cout << " <- Value ( )";
      }
      
      explicit Value ( bool val ) : _type( t_boolean ), _value( { ._boolean = val } ) {
        std::cout << " <- Value ( bool val )";
      }
      
      template <typename T>
      explicit Value ( T val, typename std::enable_if<std::is_integral<T>::value, T>::type=0 )
        : _type( t_integral ), _value( { ._integral = integral_t( val ) } ) {
        std::cout << " <- Value ( integral_t val )";
      }
      
      template <typename T>
      explicit Value ( T val, typename std::enable_if<std::is_floating_point<T>::value, T>::type=0 )
        : _type( t_floating ), _value( { ._floating = floating_t( val ) } ) {
        std::cout << " <- Value ( integral_t val )";
      }
      
      Value ( const char* val ) : _type( t_string ), _value( { ._string = new string_t( val ) }  ) {
        std::cout << " <- Value ( const char* val )";
      }
      
      Value ( string_t val ) : _type( t_string ), _value( { ._string = &val } ) {
        std::cout << " <- Value ( string_t val )";
      }
      
      Value ( string_t* val ) : _type( t_string ), _value( { ._string = val } ) {
        std::cout << " <- Value ( string_t* val )";
      }
      
      Value ( array_t val ) : _type( t_array ), _value( { ._array = &val } ) {
        std::cout << " <- Value ( array_t val )";
      }
      
      Value ( array_t* val ) : _type( t_array ), _value( { ._array = val } ) {
        std::cout << " <- Value ( array_t* val )";
      }
      
      Value ( object_t val ) : _type( t_object ), _value( { ._object = &val } ) {
        std::cout << " <- Value ( object_t val )";
      }
      
      Value ( object_t* val ) : _type( t_object ), _value( { ._object = val } ) {
        std::cout << " <- Value ( object_t* val )";
      }
      
//      Value ( Value& val ) : _type( val.type( ) ) {
//        std::cout << " <- Value ( object_t& val )";
//      }
      
      /*
       *  class Value cast operators
       */
      
      operator boolean_t ( ) const {
        switch ( _type ) {
          case t_null:
          case t_boolean:
            return _value._boolean;
          case t_integral:
            return _value._integral;
          case t_floating:
            return _value._floating;
          case t_string:
            return !! _value._string->length();
          case t_array:
          case t_object:
            return true;
        }
        throw std::invalid_argument( "Not a boolean_t" );
      }
      
      operator integral_t ( ) const {
        switch ( _type ) {
          case t_null:
          case t_boolean:
            return _value._boolean;
          case t_integral:
            return _value._integral;
          case t_floating:
            return _value._floating;
          case t_string:
            return std::stol( *_value._string );
        }
        throw std::invalid_argument( "Not a integral_t" );
      }
      
      operator floating_t ( ) const {
        switch ( _type ) {
          case t_null:
          case t_boolean:
            return _value._boolean;
          case t_integral:
            return _value._integral;
          case t_floating:
            return _value._floating;
          case t_string:
            return std::stod( *_value._string );
        }
        throw std::invalid_argument( "Not a floating_t" );
      }
      
      operator string_t ( ) const {
        switch ( _type ) {
          case t_null:
            return "null";
          case t_boolean:
            return _value._boolean ? "true" : "false";
          case t_integral:
            return _IToS( _value._integral );
          case t_floating:
            return _FToS( _value._floating );
          case t_string:
            return *_value._string;
          case t_array:
            return _Concat( _value._array );
        }
        throw std::invalid_argument( "Not a string_t" );
      }
      
      operator array_t ( ) const {
        switch ( _type ) {
          case t_array:
            return *_value._array;
        }
        throw std::invalid_argument( "Not a array_t" );
      }
      
      operator object_t ( ) const {
        switch ( _type ) {
          case t_object:
            return *_value._object;
        }
        throw std::invalid_argument( "Not a object_t" );
      }
      
      /*
       *  class Value equivalence methods
       */
      
      bool equivalent ( boolean_t val ) const {
        if ( _type != t_boolean ) return false;
        return val == _value._boolean;
      }
      
      template <typename T>
      bool equivalent ( T val, typename std::enable_if<std::is_integral<T>::value, T>::type=0 ) const {
        if ( _type == t_integral ) return val == _value._integral;
        if ( _type == t_floating ) return floating_t( val ) == _value._floating;
        return false;
      }
      
      bool equivalent ( floating_t val ) const {
        if ( _type != t_floating ) return false;
        return val == _value._floating;
      }
      
      bool equivalent ( const char* val ) const {
        if ( _type != t_string ) return false;
        return _value._string->compare( val ) == 0;
      }
      
      bool equivalent ( string_t val ) const {
        if ( _type != t_string ) return false;
        return val == *_value._string;
      }
      
      bool equivalent ( string_t* val ) const {
        if ( _type != t_string ) return false;
        return *val == *_value._string;
      }
      
      bool equivalent ( array_t val ) const {
        if ( _type != t_array ) return false;
        return val == *_value._array;
      }
      
      bool equivalent ( array_t* val ) const {
        if ( _type != t_array ) return false;
        return *val == *_value._array;
      }
      
      bool equivalent ( object_t val ) const {
        if ( _type != t_object ) return false;
        return val == *_value._object;
      }
      
      bool equivalent ( object_t* val ) const {
        if ( _type != t_object ) return false;
        return *val == *_value._object;
      }
      
      /*
       *  class Value type methods
       */
      
      bool is_null ( ) const {
        return _type == t_null;
      }
      
      bool is_bool ( ) const {
        return _type == t_boolean;
      }
      
      bool is_number ( ) const {
        return _type == t_integral || _type == t_floating;
      }
      
      bool is_string ( ) const {
        return _type == t_string;
      }
      
      bool is_array ( ) const {
        return _type == t_array;
      }
      
      bool is_object ( ) const {
        return _type == t_object;
      }
      
      type_t type ( ) const {
        return _type;
      }
      
      const string_t get_type ( ) const {
        return string_t( Value::value_type_strs[_type] );
      }
      
protected:
      
      type_t _type;
      value_t _value;
      
      /*
       *  static class Value helpers
       */
      
      static string_t _IToS ( integral_t val );
      static string_t _FToS ( floating_t val );
      static string_t _Concat ( array_t* val );
      
    };  // class Value
    
    const Value::string_t Value::value_type_strs[] = {
      "undefined"
      , "null"
      , "boolean"
      , "number"  // _integral
      , "number"  // _floating
      , "string"
      , "array"
      , "object"
    };
    
    Value::string_t Value::_IToS ( integral_t val ) {
      std::stringstream ss;
      Value::string_t result;
      ss << val;
      result = ss.str();
      return result;
    }

    Value::string_t Value::_FToS ( floating_t val ) {
      std::stringstream ss;
      Value::string_t result;
      ss << val;
      result = ss.str();
      return result;
    }

    Value::string_t Value::_Concat ( array_t* val ) {
      std::stringstream ss;
      size_t n = val->size(), i = 0;
      Value::string_t result;
      
      while ( i < n ) {
        if ( i ) ss << ',';
        ss << val->at( i++ );
      }
      result = ss.str();
      return result;
    }
  
    std::ostream& operator<< ( std::ostream& os, Value val )
    {
      switch ( val.type() ) {
        case Value::t_null:
        case Value::t_boolean:
        case Value::t_integral:
        case Value::t_floating:
        case Value::t_string:
        case Value::t_array:
          return os << Value::string_t( val );
        case Value::t_object:
          return os << "[Object object]";
        
      }
      return os << "undefined";
    }
    
  
  };  // namespace js

};  // namespace ls

#endif  // VALUE_HPP

#define CAST(a,b) \
try { \
  auto a ## _cast_ ## b = Value::b(a); \
  std::cout << #b << "( " << #a << " ) => " << a ## _cast_ ## b << "; "; \
} catch ( std::exception& e ) { \
  std::cout << #b << "( " << #a << " ) => \x1b[33m[EXCEPTION]\x1b[0m; "; \
}

#define TEST0(a,b) \
std::cout << "== Value " << #a << ": "; \
Value a; \
std::cout << "; .get_type(): " << a.get_type( ) << '(' << a.type() << ')' << "; " << std::endl; \
std::cout << ".is_null(): " << a.is_null( ) << "; "; \
std::cout << ".is_bool(): " << a.is_bool() << "; "; \
std::cout << ".is_number(): " << a.is_number() << "; "; \
std::cout << ".is_string(): " << a.is_string() << "; "; \
std::cout << ".is_array(): " << a.is_array() << "; "; \
std::cout << ".is_object(): " << a.is_object() << "; "; \
std::cout << std::endl; \
CAST(a,boolean_t) \
CAST(a,integral_t) \
CAST(a,floating_t) \
CAST(a,string_t) \
/* CAST(a,array_t) \
CAST(a,object_t) */ \
std::cout << std::endl; \
std::cout << "\x1b[32m[PASS]\x1b[0m; "; \
std::cout << "cout: " << a << "; "; \
std::cout << std::endl;

#define TEST1(a,b) \
std::cout << "== Value " << #a << "( " << #b << " ): "; \
auto a ## Arg = b; \
Value a( b ); \
std::cout << "; .get_type(): " << a.get_type( ) << '(' << a.type() << ')' << "; " << std::endl; \
std::cout << ".is_null(): " << a.is_null( ) << "; "; \
std::cout << ".is_bool(): " << a.is_bool() << "; "; \
std::cout << ".is_number(): " << a.is_number() << "; "; \
std::cout << ".is_string(): " << a.is_string() << "; "; \
std::cout << ".is_array(): " << a.is_array() << "; "; \
std::cout << ".is_object(): " << a.is_object() << "; "; \
std::cout << std::endl; \
CAST(a,boolean_t) \
CAST(a,integral_t) \
CAST(a,floating_t) \
CAST(a,string_t) \
/* CAST(a,array_t) \
CAST(a,object_t) */ \
std::cout << std::endl; \
try {  \
  switch ( a.type( ) ) { \
    case Value::t_boolean: \
    case Value::t_integral: \
    case Value::t_floating: \
    case Value::t_string: \
    case Value::t_array: \
    case Value::t_object: \
      std::cout << ( a.equivalent( b ) ? "\x1b[32m[PASS]" : "\x1b[31m[FAIL]" ) << "\x1b[0m " << #b << " == " << #a << "; "; \
      break; \
  } \
} catch ( std::exception& e ) { \
  std::cout << "\x1b[33m[EXCEPTION] " << #b << " == " << #a << "\x1b[0m"; \
} \
std::cout << "cout: " << a << "; "; \
std::cout << std::endl;



int main ( int argc, char* argv[] ) {
  using namespace ls::js;
  
  std::cout << "sizeof( value_t ): " << sizeof( Value::value_t ) << std::endl;
  
  TEST0(null1,void)
  
  TEST1(bool20,false)
  TEST1(bool21,true)
  
  TEST1(numi30,0)
  TEST1(numi31,char( 0 ))
  TEST1(numi32,char( ' ' ));
  TEST1(numi33,short( 0 ));
  TEST1(numi34,short( 34 ));
  TEST1(numi35,int( 0 ));
  TEST1(numi36,int( 36 ));
  TEST1(numi37,long( 0 ));
  TEST1(numi38,long( 38 ));
  TEST1(numi39,Value::integral_t( 39 ));
  
  TEST1(numi40,float( 0 ));
  TEST1(numi41,float( 41 ));
  TEST1(numi42,float( 42.42 ));
  TEST1(numi43,double( 0 ));
  TEST1(numi44,double( 44 ));
  TEST1(numi45,double( 45.45 ));
  TEST1(numi46,Value::floating_t( 0 ));
  TEST1(numi47,Value::floating_t( 21 ));
  TEST1(numi48,Value::floating_t( 22.22 ));
  
  TEST1(str50,"const char* #50");
  TEST1(str51,Value::string_t( "string_t #51" ));
  TEST1(str52,new std::string( "new std::string #52" ));
  TEST1(str53,new Value::string_t( "new string_t #53" ));
  
  Value::array_t a_0;
  TEST1(arr60,a_0);
  TEST1(arr61,new Value::array_t);
  
  Value::object_t o_0;
  TEST1(obj70,o_0);
  TEST1(obj71,new Value::object_t);
  
  return 0;
}

