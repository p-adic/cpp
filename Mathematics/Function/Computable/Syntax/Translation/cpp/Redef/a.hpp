// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Redef/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Term/a.hpp"
#include "../Type/a.hpp"


template <typename Arg, typename... Args> inline PlusStringAplication( const Arg& arg , const Args&... args );
template <typename T> inline T GetPlus( const T& arg );
template <typename... Args> inline int GetPlus( const int& arg1 , const int& arg2 , const Args&... args );
template <typename... Args> inline string GetPlus( const string& arg1 , const string& arg2 , const Args&... args );
template <typename... Args> inline bool GetPlus( const bool& arg1 , const bool& arg2 , const Args&... args );
template <typename T, typename... Args> VLArray<T> GetPlus( const VLArray<T>& arg1 , const VLArray<T>& arg2 , const Args&... args );
template <typename T, typename... Args> VLNestedArray<T> GetPlus( const VLNestedArray<T>& arg1 , const VLNestedArray<T>& arg2 , const Args&... args );

template <typename Arg, typename... Args> inline DECLARATION_OF_VARIADIC_CPP_FUNCTION( Times );

template <typename Arg1, typename Arg2> inline DECLARATION_OF_TWO_ARY_CPP_FUNCTION( Minus );

template <typename Arg1, typename Arg2> inline DECLARATION_OF_TWO_ARY_CPP_FUNCTION( Slash );

template <typename Arg1, typename Arg2> inline DECLARATION_OF_TWO_ARY_CPP_FUNCTION( Mod );

template <typename Arg1, typename Arg2> inline CppClassForString PowerStringApplication( const Arg1& arg1 , const Arg2& arg2 );
template <typename T> T GetPower( const T& x , const T& y );

template <typename Arg> inline DECLARATION_OF_ONE_ARY_CPP_FUNCTION( Neg );

template <typename Arg, typename... Args> inline DECLARATION_OF_VARIADIC_CPP_FUNCTION( Land );

template <typename Arg, typename... Args> inline DECLARATION_OF_VARIADIC_CPP_FUNCTION( Lor );

template <typename Arg1, typename Arg2> inline DECLARATION_OF_TWO_ARY_CPP_FUNCTION( To );

template <typename Arg, typename... Args> inline DECLARATION_OF_VARIADIC_CPP_FUNCTION( Equiv );


template <typename Arg> inline CppClassForString StringiseStringApplication( const Arg& arg );

template <typename Arg> inline CppClassForString LengthStringApplication( const Arg& arg );
template <typename T> inline const uint& LengthOf( const VLArray<T>& a );
template <typename T> inline const uint& LengthOf( const VLNestedArray<T>& t );

template <typename Arg1, typename Arg2> inline CppClassForString EntryAccessStringApplication( const Arg1& arg1 , const Arg2& arg2 );
template <typename T> inline T GetEntryAccess( const VLArray<T>& a , const uint& n );
template <typename T> inline VLNestedArray<T> GetEntryAccess( const VLNestedArray<T>& a , const uint& n );

template <typename Arg1, typename Arg2> inline CppClassForString InitialSegmentStringApplication( const Arg1& arg1 , const Arg2& arg2 );
template <typename T> VLArray<T> GetInitialSegment( const VLArray<T>& a , const uint& n );
template <typename T> VLNestedArray<T> GetInitialSegment( const VLNestedArray<T>& a , const uint& n );
inline string GetInitialSegment( const string& a , const uint& n );

template <typename Arg1, typename Arg2> inline CppClassForString FinalSegmentStringApplication( const Arg1& arg1 , const Arg2& arg2 );
template <typename T> VLArray<T> GetFinialSegment( const VLArray<T>& a , const uint& n );
template <typename T> VLNestedArray<T> GetFinalSegment( const VLNestedArray<T>& a , const uint& n );
inline string GetFinalSegment( const string& a , const uint& n );

template <uint i, typename Arg> inline CppClassForString ProjectionStringApplication( const Arg& arg );

template <typename Arg> inline CppClassForString WrapStringApplication( const Arg& arg );

template <typename Arg> inline CppClassForString NestedWrapStringApplication( const Arg& arg );
template <typename T> inline VLNestedArray<T> GetNestedWrap( const VLNestedArray<T>& a );


template <typename Arg> inline CppClassForString NestifyStringApplication( const Arg& arg );
template <typename T> inline VLNestedArray<T> GetNestify( const VLArray<T>& a );
template <typename T> inline VLNestedArray<T> GetNestify( const VLNestedArray<T>& t );

template <typename... Args> inline CppClassForString TupleStringApplication( const Args&... args );

template <typename Arg> inline CppClassForString ToTrivialNestedArrayStringApplication( const Arg& arg );
template <typename T> inline VLNestedArray<T> GetToTrivialNestedArray( const T& t );
inline VLNestedArray<string> GetToTrivialNestedArray( const char* const & t );

template <typename Arg> inline CppClassForString RemoveNestedArrayStringApplication( const Arg& arg );
template <typename T> T GetRemoveNestedArray( const VLNestedArray<T>& t );

template <typename Arg> inline CppClassForString RemovableNestedArrayStringApplication( const Arg& arg );

template <typename Arg1, typename Arg2> inline CppClassForString EqStringApplication( const Arg1& arg1 , const Arg2& arg2 );

template <typename Arg1, typename Arg2> inline CppClassForString NeqStringApplication( const Arg1& arg1 , const Arg2& arg2 );

template <typename Arg1, typename Arg2> inline CppClassForString LeqStringApplication( const Arg1& arg1 , const Arg2& arg2 );

inline bool GetLeq( const int& x1 , const int& x2 );
inline bool GetLeq( const string& x1 , const string& x2 );

template <typename Arg1, typename Arg2> inline CppClassForString GeqStringApplication( const Arg1& arg1 , const Arg2& arg2 );

template <typename Arg1, typename Arg2> inline CppClassForString LneqStringApplication( const Arg1& arg1 , const Arg2& arg2 );

template <typename Arg1, typename Arg2> inline CppClassForString GneqStringApplication( const Arg1& arg1 , const Arg2& arg2 );

template <typename Arg> inline CppClassForString NonNegativeStringApplication( const Arg& arg );


template <typename Arg1, typename Arg2, typename... Args> inline CppClassForString IfStringApplication( const Arg1& arg1 , const Arg2& arg2 , const Args&... args );

template <typename Arg1, typename Arg2> inline CppClassForString PutStringApplication( const Arg1& arg1 , const Arg2& arg2 );

template <typename Arg, typename... Args> inline CppClassForString PrintStringApplication( const Arg& arg , const Args&... args );

inline CppClassForString ExitStringApplication();

template <typename Arg> inline CppClassForString ReturnStringApplication( const Arg& arg );



