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
// 以下はEntryOfVLArray<T>なども拾ってしまうので削除。
// template <template <typename...> typename V , typename T> inline string to_string( const V<T>& a );
template <typename T> inline string to_string( const vector<T>& a );
template <typename T> inline string to_string( const list<T>& a );
template <typename T> inline string to_string( const set<T>& a );
template <typename ARG1 , typename ARG2 , typename... ARGS> inline string to_string( const ARG1& arg1 , const ARG2& arg2 , const ARGS&... args );

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

int to_int( const string& s );

bool CheckEmpty( const string& s ) noexcept;
// 全角に対応（恐らくstring::npos != s0.find( s1 )でも問題ないが念のため）
bool CheckContain( const string& s0 , const string& s1 );
bool CheckContainInt( const string& s );

bool Equal( const char* const& c0 , const char* const& c1 );

inline bool IsKaigyou( const unsigned char& c ) noexcept;
inline bool IsFirstHalfOfZenkaku( const unsigned char& c ) noexcept;

// string::substr( 位置 , サイズ )と異なり全角か半角かを反映する
string InitialSegmentOf( const string& s , const uint& n );
string FinalSegmentOf( const string& s , const uint& n );
uint FirstBitOf( const string& s );
inline string FirstLetterOf( const string& s );
inline string LongestProperFinalSegmentOf( const string& s );
inline uint LengthOf( const string& s );

void Separate( const string& s , const string& separator , string& s_front , string& s_back );
