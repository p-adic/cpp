// String/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Error/IgnoredError/a_Body.hpp"
#include "../../Error/UnknownError/a_Body.hpp"
#include "../../SFINAE/MemberFunction/a_Body.hpp"

inline string to_string( const string& s ) noexcept { return s; }
inline string to_string( const char* const & s ) noexcept { return s; }
inline string to_string( char* const & s ) noexcept { return s; }
inline string to_string( const bool& b ) noexcept { return b ? "true" : "false"; }
template <template <typename...> typename V , typename T> inline string to_string( const V<T>& a ) { string answer = "("; auto itr = a.begin() , end = a.end(); while( itr != end ){ answer += to_string( *itr ); answer += ",)"[++itr == end]; } return answer; }
template <typename ARG1 , typename ARG2 , typename... ARGS> inline string to_string( const ARG1& arg1 , const ARG2& arg2 , const ARGS&... args ) { return to_string( arg1 ) + "," + to_string( arg2 , args... ); }

// 例外を送出するようなメンバ関数Displayを実装してはならない。
DECLARATION_OF_MEMBER_CONST_TRUE( to_string ) noexcept
{

  return ( t. Display )( args... );

}

DECLARATION_OF_MEMBER_NON_CONST_TRUE_LVALUE( to_string ) noexcept
{

  return ( t. Display )( args... );

}

DECLARATION_OF_MEMBER_NON_CONST_TRUE_RVALUE( to_string ) noexcept
{

  return ( t. Display )( args... );

}

DECLARATION_OF_MEMBER_FALSE( to_string ) noexcept
{

  return "NaN_F";

}

DECLARATION_OF_MEMBER_INVALID( to_string ) noexcept
{
  
  return "NaN_I";

}

template <typename T>
string to_string( T* const & p ) noexcept
{
  
  if( p == nullptr ){

    return "nullptr";
    
  }
  
  return to_string( *p );

}

template <typename T0>
string to_string_Body() noexcept
{

  return to_string( typeid( T0 ) );

}

template <typename T0 , typename T1 , typename... T2>
string to_string_Body() noexcept
{

  return to_string_Body<T0>() + "," + to_string_Body<T1,T2...>();

}

template <typename... T0>
auto to_string() noexcept -> typename enable_if< equal_to<uint>()( sizeof...( T0 ) , 0 ) , string >::type
{

  return "";
  
}

template <typename... T0>
auto to_string() noexcept -> typename enable_if< equal_to<uint>()( sizeof...( T0 ) , 1 ) , string >::type
{

  return to_string_Body<T0...>();

}

template <typename... T0>
auto to_string() noexcept -> typename enable_if< less_equal<uint>()( 2 , sizeof...( T0 ) ) , string >::type
{

  return "(" + to_string_Body<T0...>() + ")";

}

inline bool CheckEmpty( const string& s ) noexcept { return s == ""; }

inline bool IsKaigyou( const unsigned char& c ) noexcept { return c == '\n'; }
inline bool IsFirstHalfOfZenkaku( const unsigned char& c ) noexcept { return ( 0x81 <= c && c <= 0x9f ) || ( 0xe0 <= c && c <= 0xfc ); }

inline string FirstLetterOf( const string& s ) { const uint d = FirstBitOf( s ); return s.substr( 0 , d ); }
inline string LongestProperFinalSegmentOf( const string& s ) { const uint d = FirstBitOf( s ); return s.substr( d , s.size() - d ); }
inline uint LengthOf( const string& s ) { return s.empty() ? 0 : 1 + LengthOf( LongestProperFinalSegmentOf( s ) ); }
