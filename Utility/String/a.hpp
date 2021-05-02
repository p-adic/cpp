// String/a.hpp

#pragma once

#include "a_Macro.hpp"

#include <typeinfo>
#include "../../SFINAE/MemberFunction/a.hpp"

#include "a_Alias.hpp"

inline string to_string( const string& s ) noexcept;
inline string to_string( const char* const & s ) noexcept;
inline string to_string( char* const & s ) noexcept;
inline string to_string( const bool& ) noexcept;

// to_string( typeid( T ) )で"T"を出力
string to_string( const type_info& ) noexcept;

// THREE_WAYS_SFINAE_MEMBER( to_string );
DECLARATION_OF_MEMBER_CONST_TRUE( to_string ) noexcept;
DECLARATION_OF_MEMBER_NON_CONST_TRUE_LVALUE( to_string ) noexcept;
DECLARATION_OF_MEMBER_NON_CONST_TRUE_RVALUE( to_string ) noexcept;
DECLARATION_OF_MEMBER_FALSE( to_string ) noexcept;
DECLARATION_OF_MEMBER_INVALID( to_string ) noexcept;

template <typename T> string to_string( T* const & ) noexcept;

// to_string<T0,...,Tn>() noexcept { return "(T0,...,Tn)";}
template <typename... T0> auto to_string() noexcept -> typename enable_if< equal_to<uint>()( sizeof...( T0 ) , 0 ) , string >::type;
template <typename... T0> auto to_string() noexcept -> typename enable_if< equal_to<uint>()( sizeof...( T0 ) , 1 ) , string >::type;
template <typename... T0> auto to_string() noexcept -> typename enable_if< less_equal<uint>()( 2 , sizeof...( T0 ) ) , string >::type;

string Sum( const list<string>& ) noexcept;

bool CheckEmpty( const string& ) noexcept;
bool CheckContain( const string& , const string& ) noexcept;
bool CheckContainInt( const string& ) noexcept;

bool Equal( const char* const& c0 , const char* const& c1 );

inline bool IsKaigyou( const unsigned char& c ) noexcept;
inline bool IsFirstHalfOfZenkaku( const unsigned char& c ) noexcept;

// string::substr( 位置 , サイズ )と異なり全角か半角かを反映する
string InitialSegmentOf( const string& s , const uint& n );
string FinalSegmentOf( const string& s , const uint& n );
string FirstBitOf( const string& s );
inline string FirstLetterOf( const string& s );
inline string LongestProperFinalSegmentOf( const string& s );
inline uint LengthOf( const string& s );
