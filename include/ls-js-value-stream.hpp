
#ifndef LS_JS_VALUE_STREAM_HPP
#define LS_JS_VALUE_STREAM_HPP

#include "ls-js-value.hpp"

std::ostream& operator<< ( std::ostream& os, ls::js::Value val )
{
  using namespace ls::js;
  
//  std::cout << "[[[operator<< ( std::ostream& os, ls::js::Value val )]]]";
  switch ( val.type() ) {
    case Value::t_null:
    case Value::t_boolean:
    case Value::t_integral:
    case Value::t_float:
      return os << Value::string_t( val );
    case Value::t_string:
      return os << Value::string_t( val );
    case Value::t_array:
    case Value::t_object:
      return os << Value::string_t( val );
  }
  return os << "undefined";
}

//std::ostream& operator<< ( std::ostream& os, ls::js::Value* val )
//{
//  using namespace ls::js;
//  
////  std::cout << "[[[operator<< ( std::ostream& os, ls::js::Value* val )]]]";
//  switch ( val->type() ) {
//    case Value::t_null:
//    case Value::t_boolean:
//    case Value::t_integral:
//    case Value::t_float:
//    case Value::t_string:
//    case Value::t_array:
//    case Value::t_object:
//      return os << Value::string_t( *val );
//  }
//  return os << "undefined";
//}


#endif  // LS_JS_VALUE_STREAM_HPP

