
#include "ls-js-value.hpp"
#include "ls-js-value-stream.hpp"

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
/* CAST(a,boolean_t) \
CAST(a,integral_t) \
CAST(a,float_t) \
CAST(a,string_t) \
CAST(a,array_t) \
CAST(a,object_t) */ \
std::cout << std::endl; \
std::cout << "\x1b[32m[PASS]\x1b[0m; "; \
std::cout << "cout: " << a << "; "; \
std::cout << std::endl;

#define TEST1(a,b) \
std::cout << "== Value " << #a << "( " << #b << " ): "; \
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
CAST(a,float_t) \
CAST(a,string_t) \
/* CAST(a,array_t) \
CAST(a,object_t) */ \
std::cout << std::endl; \
try {  \
  switch ( a.type( ) ) { \
    case Value::t_boolean: \
    case Value::t_integral: \
    case Value::t_float: \
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



int test ( ) {

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
  TEST1(numi46,Value::float_t( 0 ));
  TEST1(numi47,Value::float_t( 21 ));
  TEST1(numi48,Value::float_t( 22.22 ));
  
// causes unavoidable memory leak:  TEST1(str50,"const char* #50");
  TEST1(str51,Value::string_t( "string_t #51" ));
  std::string s_52( "new std::string #52" );
  TEST1(str52,s_52);
  Value::string_t* s_53p = new Value::string_t( "new string_t #53" );
  TEST1(str53,s_53p); // line 108
  delete s_53p;
  
  Value::array_t a_60;
  TEST1(arr60,a_60);
  Value::array_t* a_61p = new Value::array_t;
  TEST1(arr61,a_61p);
  delete a_61p;
  
  Value::object_t o_0;
  TEST1(obj70,o_0);
  Value::object_t* o_71p = new Value::object_t;
  TEST1(obj71,o_71p);
  delete o_71p;
  
//  str50 = NULL;
//  free( (void*)&str52 );
//  free( (void*)&str53 );
}

int main ( int argc, char* argv[] ) {
  test( );
  return 0;
}

