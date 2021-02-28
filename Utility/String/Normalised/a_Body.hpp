// String/Normalised_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../SFINAE/MetaFunction/IsList/a.hpp"
#include "../../../SFINAE/NonMemberFunction/Constified/a_Body.hpp"
#include "../../../SFINAE/NonMemberFunction/ToValue/a_Body.hpp"

// THREE_WAYS_SFINAE_NON_MEMBER_CONSTIFIED_BODY( to_string , string )
DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( ConstTrue_ , to_string , _Constified ) noexcept
{

  return ( to_string )( arg1 , arg2... );

}

DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( NonConstTrue_ , to_string , _Constified ) noexcept
{

  Arg1 copy_arg1 = arg1;
  return ( to_string )( copy_arg1 , arg2... );

}
  
DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( False_ , to_string , _Constified ) noexcept
{

  return "NaN_FC";

}

DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Invalid_ , to_string , _Constified ) noexcept
{

  return "NaN_IC";

}

template <typename T0> static auto to_string_Normalised_Body( const T0& t0 ) noexcept -> typename enable_if< ! is_List<T0>::value , string >::type;
template <typename T0> static auto to_string_Normalised_Body( const T0& t0 ) noexcept -> typename enable_if< is_List<T0>::value , string >::type;
template <typename T0 , typename T1 , typename... T2> static inline string to_string_Normalised_Body( const T0& t0 , const T1& t1 , const T2&... t2 ) noexcept;

inline string to_string_Normalised() noexcept { return "()"; }
template <typename T0> inline string to_string_Normalised( const T0& t0 ) noexcept { return to_string_Normalised_Body( t0 ); }
template <typename T0 , typename T1 , typename... T2> inline string to_string_Normalised( const T0& t0 , const T1& t1 , const T2&... t2 ) noexcept { return "( " + to_string_Normalised_Body( t0 , t1 , t2... ) + " )"; }


template <typename T0>
auto to_string_Normalised_Body( const T0& t0 ) noexcept -> typename enable_if< ! is_List<T0>::value , string >::type
{

  if( is_same<T0,string>::value || is_same<T0,char*>::value || is_same<T0,const char*>::value ){

    return "\"" + to_string_Constified( t0 ) + "\"";

  }

  return to_string_Constified( t0 );

}

template <typename T0>
auto to_string_Normalised_Body( const T0& t0 ) noexcept -> typename enable_if< is_List<T0>::value , string >::type
{
  
  string s = "( ";
  
  for( typename T0::const_iterator begin = t0.begin() , itr = begin , end = t0.end() ; itr != end ; itr++ ){

    if( itr != begin ){

      s += " , ";

    }

    s += to_string_Normalised_Body( *itr );

  }

  s += " )";
  
  return s;

}

template <typename T0 , typename T1 , typename... T2> inline string to_string_Normalised_Body( const T0& t0 , const T1& t1 , const T2&... t2 ) noexcept {  return to_string_Normalised_Body( t0 ) + " , " + to_string_Normalised_Body( t1 , t2... ); }


template <typename T> inline void echo( const T& t ) noexcept { cout << to_string_Normalised( t ) << endl; }

template <typename Arg1 , typename... Arg2>
void IndicateArguments_Body( const string& VARIABLE_NAMES , string& s , const Arg1& arg1 , const Arg2&... arg2 ) noexcept
{

  s = "";

  if( sizeof...( arg2 ) == 0 && ! CheckContain( VARIABLE_NAMES , "," ) ){

    s += VARIABLE_NAMES;
    s += " == ";
    s += to_string_Normalised( arg1 );

  } else {

    s += "( ";
    s += VARIABLE_NAMES;
    s += " ) == ";
    s += to_string_Normalised( arg1 , arg2... );
    
  }

  return;

}

template <typename Arg1 , typename... Arg2>
void IndicateArguments( const string& VARIABLE_NAMES , const Arg1& arg1 , const Arg2&... arg2 ) noexcept
{

  string s;
  IndicateArguments_Body( VARIABLE_NAMES , s , arg1 , arg2... );

  cout << s << endl;
  return;

}
