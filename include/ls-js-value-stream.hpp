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
    case Value::t_string:
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

