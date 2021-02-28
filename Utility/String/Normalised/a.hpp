// String/Normalised.hpp

#pragma once

#include "../a.hpp"
#include "../../../SFINAE/NonMemberFunction/Constified/a.hpp"
#include "../../../SFINAE/NonMemberFunction/ToValue/a.hpp"

#include "a_Alias.hpp"

// THREE_WAYS_SFINAE_NON_MEMBER_CONSTIFIED( to_string );
DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( ConstTrue_ , to_string , _Constified ) noexcept;
DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( NonConstTrue_ , to_string , _Constified ) noexcept;
DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( False_ , to_string , _Constified ) noexcept;
DECLARATION_OF_NON_MEMBER_WITH_AT_LEAST_ONE_VARIABLE( Invalid_ , to_string , _Constified ) noexcept;

inline string to_string_Normalised() noexcept;
template <typename T0> inline string to_string_Normalised( const T0& t0 ) noexcept;
template <typename T0 , typename T1 , typename... T2> inline string to_string_Normalised( const T0& t0 , const T1& t1 , const T2&... t2 ) noexcept;

template <typename T> inline void echo( const T& ) noexcept;
template <typename Arg1 , typename... Arg2> void IndicateArguments( const string& VARIABLE_NAMES , const Arg1& , const Arg2&... ) noexcept;
