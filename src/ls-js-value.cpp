/*

Copyright (c) <2015> <Erich Horn and LaughingSun>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE


 */



#include "ls-js-value.hpp"

using namespace ls::js;

/*
 *  class Value constructors
 */


Value::Value ( ) : _type( t_null ), _value( { ._boolean = boolean_t( false ) } ) {
  std::cout << " <- Value ( )";
}

Value::Value ( bool val ) : _type( t_boolean ), _value( { ._boolean = val } ) {
  std::cout << " <- Value ( bool val )";
}

Value::Value ( const char* val ) : _type( t_string ), _value( { ._string = new string_t( val ) }  ) {
  std::cout << " <- Value ( const char* val )";
}

Value::Value ( string_t val ) : _type( t_string ), _value( { ._string = &val } ) {
  std::cout << " <- Value ( string_t val )";
}

Value::Value ( string_t* val ) : _type( t_string ), _value( { ._string = val } ) {
  std::cout << " <- Value ( string_t* val )";
}

Value::Value ( array_t val ) : _type( t_array ), _value( { ._array = &val } ) {
  std::cout << " <- Value ( array_t val )";
}

Value::Value ( array_t* val ) : _type( t_array ), _value( { ._array = val } ) {
  std::cout << " <- Value ( array_t* val )";
}

Value::Value ( object_t val ) : _type( t_object ), _value( { ._object = &val } ) {
  std::cout << " <- Value ( object_t val )";
}

Value::Value ( object_t* val ) : _type( t_object ), _value( { ._object = val } ) {
  std::cout << " <- Value ( object_t* val )";
}

Value::Value ( type_t val ) : _type( val ) {
  switch ( _type ) {
    case t_boolean:
      _value._boolean = false;
      break;
    case t_float:
      _value._float = 0;
      break;
    case t_string:
      _value._string = new string_t;
      break;
    case t_array:
      _value._array = new array_t;
      break;
    case t_object:
      _value._object = new object_t;
      break;
    case t_nan:
      _value._float = float_nan;
      break;
    case t_infinity:
      _value._float = float_infinity;
      break;
    case t_integral:
    case t_null:
    default:
      _value._integral = 0;
  }
  std::cout << " <- Value ( type_t val )";
}

//Value::Value ( Value& val ) : _type( val.type( ) ) {
//  std::cout << " <- Value ( Value& val )";
//}

/*
 *  class Value cast operators
 */

Value::operator boolean_t ( ) const {
  switch ( _type ) {
    case t_null:
      return false;
    case t_boolean:
      return _value._boolean;
    case t_integral:
      return _value._integral;
    case t_float:
      return _value._float;
    case t_string:
      return !! _value._string->length();
    case t_array:
    case t_object:
    case t_nan:
    case t_infinity:
      return true;
  }
  throw std::invalid_argument( "Not a boolean_t" );
}

Value::operator integral_t ( ) const {
  switch ( _type ) {
    case t_null:
      return 0;
    case t_boolean:
      return _value._boolean;
    case t_integral:
      return _value._integral;
    case t_float:
      return _value._float;
    case t_string:
      return std::stol( *_value._string );
    case t_array:
    case t_object:
    case t_nan:
    case t_infinity:
      return 0;
  }
  throw std::invalid_argument( "Not a integral_t" );
}

Value::operator float_t ( ) const {
  switch ( _type ) {
    case t_null:
      return 0.0;
    case t_boolean:
      return _value._boolean;
    case t_integral:
      return _value._integral;
    case t_infinity:
    case t_float:
      return _value._float;
    case t_string:
      return std::stod( *_value._string );
    case t_array:
    case t_object:
    case t_nan:
      return float_nan;
  }
  throw std::invalid_argument( "Not a float_t" );
}

Value::operator string_t ( ) const {
  switch ( _type ) {
    case t_boolean:
      return _value._boolean ? "true" : "false";
    case t_integral:
      return _IToS( _value._integral );
    case t_float:
      return _FToS( _value._float );
    case t_string:
      return *(_value._string);
    case t_array:
      return _Concat( _value._array );
    case t_object:
      return "[Object object]";
    case t_infinity:
      if ( _value._float < 0 ) return string_t( "-" ) + value_type_strs[_type];
    case t_null:
    case t_nan:
      return value_type_strs[_type];
  }
  throw std::invalid_argument( "Not a string_t" );
}

Value::operator array_t ( ) const {
  switch ( _type ) {
    case t_array:
      return *_value._array;
  }
  throw std::invalid_argument( "Not a array_t" );
}

Value::operator object_t ( ) const {
  switch ( _type ) {
    case t_object:
      return *_value._object;
  }
  throw std::invalid_argument( "Not a object_t" );
}

/*
 *  class Value equivalence methods
 */

bool Value::equivalent ( boolean_t val ) const {
  if ( _type != t_boolean ) return false;
  return val == _value._boolean;
}

bool Value::equivalent ( float_t val ) const {
  if ( _type != t_float ) return false;
  return val == _value._float;
}

bool Value::equivalent ( const char* val ) const {
  if ( _type != t_string ) return false;
  return _value._string->compare( val ) == 0;
}

bool Value::equivalent ( string_t val ) const {
  if ( _type != t_string ) return false;
  return val == *_value._string;
}

bool Value::equivalent ( string_t* val ) const {
  if ( _type != t_string ) return false;
  return *val == *_value._string;
}

bool Value::equivalent ( array_t val ) const {
  if ( _type != t_array ) return false;
  return val == *_value._array;
}

bool Value::equivalent ( array_t* val ) const {
  if ( _type != t_array ) return false;
  return *val == *_value._array;
}

bool Value::equivalent ( object_t val ) const {
  if ( _type != t_object ) return false;
  return val == *_value._object;
}

bool Value::equivalent ( object_t* val ) const {
  if ( _type != t_object ) return false;
  return *val == *_value._object;
}

/*
 *  class Value type methods
 */

bool Value::is_null ( ) const {
  return _type == t_null;
}

bool Value::is_bool ( ) const {
  return _type == t_boolean;
}

bool Value::is_int ( ) const {
  return _type == t_integral;
}

bool Value::is_float ( ) const {
  return _type == t_float;
}

bool Value::is_nan ( ) const {
  return _type == t_nan;
}

bool Value::is_infinity ( ) const {
  return _type == t_infinity;
}

bool Value::is_number ( ) const {
  return _type == t_integral || _type == t_float;
}

bool Value::is_string ( ) const {
  return _type == t_string;
}

bool Value::is_array ( ) const {
  return _type == t_array;
}

bool Value::is_object ( ) const {
  return _type == t_object;
}

Value::type_t Value::type ( ) const {
  return _type;
}

const Value::string_t Value::get_type ( ) const {
  return string_t( Value::value_type_strs[_type] );
}

//Value::type_t _type;
//Value::value_t _value;

/*
 *  static class Value helpers
 */

const Value::float_t Value::float_nan = std::nan("NaN");
const Value::float_t Value::float_infinity = std::numeric_limits<Value::float_t>::infinity();

const Value null( Value::t_null );
const Value NaN( Value::t_nan );
const Value infinity( Value::t_null );

const Value::string_t Value::value_type_strs[] = {
  "undefined"
  , "boolean"
  , "number"  // _integral
  , "number"  // _float
  , "string"
  , "array"
  , "object"
  , "null"
  , "NaN"
  , "infinity"
};

Value::string_t Value::_IToS ( integral_t val ) {
  std::stringstream ss;
  Value::string_t result;
  ss << val;
  result = ss.str();
  return result;
}

Value::string_t Value::_FToS ( float_t val ) {
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

/*
 *  external static class Value support
 */


