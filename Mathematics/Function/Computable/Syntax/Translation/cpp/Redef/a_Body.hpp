// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Redef/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Term/a_Body.hpp"
#include "../Type/a_Body.hpp"

template <typename Arg, typename... Args> inline PlusStringAplication( const Arg& arg , const Args&... args ) { return "GetPlus( " + ArgumentString( arg , args...  ) + " )"; }
template <typename T> inline T GetPlus( const T& arg ) { return arg; }
template <typename... Args> inline int GetPlus( const int& arg1 , const int& arg2 , const Args&... args ) { return GetPlus( arg1 + arg2 , args... ); }
template <typename... Args> inline string GetPlus( const string& arg1 , const string& arg2 , const Args&... args ) { return GetPlus( arg1 + arg2 , args... ); }
template <typename... Args> inline bool GetPlus( const bool& arg1 , const bool& arg2 , const Args&... args ) { return GetPlus( arg1 + arg2 , args... ); }

template <typename T, typename... Args>
VLArray<T> GetPlus( const VLArray<T>& arg1 , const VLArray<T>& arg2 , const Args&... args )
{

  auto a = arg1;

  for( auto itr = arg2.begin() , end = arg2.end() ; itr != end ; itr++ ){

    a.push_back( *itr );

  }
  
  return GetPlus( a , args... );

}

template <typename T, typename... Args>
VLTree<T> GetPlus( const VLTree<T>& arg1 , const VLTree<T>& arg2 , const Args&... args )
{

  auto t = arg1;

  auto itr = arg2.LeftMostNode();
  
  while( itr.IsValid() ){

    t.push_RightMost( arg2.GetBranchCopy( itr ) );
    itr++;

  }
  
  return GetPlus( t , args... );

}

template <typename Arg, typename... Args> inline DEFINITION_OF_VARIADIC_CPP_FUNCTION( Times );

template <typename Arg1, typename Arg2> inline DEFINITION_OF_TWO_ARY_CPP_FUNCTION( Minus );

template <typename Arg1, typename Arg2> inline DEFINITION_OF_TWO_ARY_CPP_FUNCTION( Slash );

template <typename Arg1, typename Arg2> inline DEFINITION_OF_TWO_ARY_CPP_FUNCTION( Mod );

template <typename Arg1, typename Arg2> inline CppClassForString PowerStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return "GetPower( " + ArgumentString( arg1 , arg2 ) + " )"; }

template <typename T>
T GetPower( const T& x , const T& y )
{

  if( y < 0 ){

    if( x == 1 || x == -1 ){

      return GetPower( x , -y );

    }

    ERR_IMPUT( x , y );

  }

  if( y == 0 ){

    return 1;

  }
  
  return GetPower( x , y - 1 ) * x;

}

template <typename Arg> inline DEFINITION_OF_ONE_ARY_CPP_FUNCTION( Neg );

template <typename Arg, typename... Args> inline DEFINITION_OF_VARIADIC_CPP_FUNCTION( Land );

template <typename Arg, typename... Args> inline DEFINITION_OF_VARIADIC_CPP_FUNCTION( Lor );

template <typename Arg1, typename Arg2> inline DEFINITION_OF_TWO_ARY_CPP_FUNCTION( To );

template <typename Arg, typename... Args> inline DEFINITION_OF_VARIADIC_CPP_FUNCTION( Equiv );



template <typename Arg> inline CppClassForString StringiseStringApplication( const Arg& arg ) { return "to_string( " + ArgumentString( arg ) + " )"; }

template <typename Arg> inline CppClassForString LengthStringApplication( const Arg& arg ) { return ArgumentString( arg ) + ".size()"; }

template <typename Arg1, typename Arg2> inline CppClassForString EntryAccessStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return "GetEntryAccess( " + ArgumentString( arg1 , arg2 ) + " )"; }
template <typename T> inline T GetEntryAccess( const VLArray<T>& a , const uint& n ) { return a[n]; }
template <typename T> inline VLTree<T> GetEntryAccess( const VLTree<T>& a , const uint& n ) { return a.GetBranchCopy( n ); }

template <typename Arg1, typename Arg2> inline CppClassForString InitialSegmentStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return "GetInitialSegment( " + ArgumentString( arg1 , arg2 ) + " )"; }

template <typename T>
VLArray<T> GetInitialSegment( const VLArray<T>& a , const uint& n )
{

  auto a_copy = a;
  const uint m = n+1;

  if( a_copy.size() < m ){

    ERR_IMPUT( a , n );

  }

  while( a_copy.size() > m ){

    a_copy.pop_back();
    
  }
  
  return a_copy;

}

template <typename T> VLTree<T> GetInitialSegment( const VLTree<T>& a , const uint& n )
{

  auto a_copy = a;
  const uint m = n+1;

  if( a_copy.size() < m ){

    ERR_IMPUT( a , n );

  }

  while( a_copy.size() > m ){

    a_copy.pop_RightMost();
    
  }
  
  return a_copy;

}


template <typename Arg1, typename Arg2> inline CppClassForString FinalSegmentStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return "GetFinalSegment( " + ArgumentString( arg1 , arg2 ) + " )"; }

template <typename T>
VLArray<T> GetFinialSegment( const VLArray<T>& a , const uint& n )
{

  auto a_copy = a;
  const uint m = n+1;

  if( a_copy.size() < m ){

    ERR_IMPUT( a , n );

  }

  while( a_copy.size() > m ){

    a_copy.pop_front();
    
  }
  
  return a_copy;

}

template <typename T> VLTree<T> GetFinalSegment( const VLTree<T>& a , const uint& n )
{

  auto a_copy = a;
  const uint m = n+1;

  if( a_copy.size() < m ){

    ERR_IMPUT( a , n );

  }

  while( a_copy.size() > m ){

    a_copy.pop_LeftMost();
    
  }
  
  return a_copy;

}


template <uint i, typename Arg> inline CppClassForString ProjectionStringApplication( const Arg& arg ) { return "Projection<" + to_string( i ) +">( " + ArgumentString( arg ) + " )"; }


template <typename Arg> inline CppClassForString WrapStringApplication( const Arg& arg ) { return "to_VLArray( " + ArgumentString( arg ) + " )"; }

template <typename Arg> inline CppClassForString NestedWrapStringApplication( const Arg& arg ) { return "GetNestedWrap( " + ArgumentString( arg ) + " )"; }

template <typename T>
VLTree<T> GetNestedWrap( const VLTree<T>& a )
{

  auto t = VLTree<T>();
  t.push_RightMost( a );
  return t;

}

template <typename Arg> inline CppClassForString NestifyStringApplication( const Arg& arg ) { return "GetNestify( " + ArgumentString( arg ) + " )"; }

template <typename T>
VLTree<T> GetNestify( const VLArray<T>& a )
{

  auto t = VLTree<T>();

  for( auto itr = a.begin() , end = a.end() ; itr != end ; itr++ ){

    t.push_RightMost( *itr );

  }

  return t;

}

template <typename T> inline VLTree<T> GetNestify( const VLTree<T>& t ) { return t; }

template <typename... Args> inline CppClassForString TupleStringApplication( const Args&... args ) { return "DirectProduct( " + ArgumentString( args... ) + " )"; }

template <typename Arg> inline CppClassForString ToTrivialNestedArrayStringApplication( const Arg& arg ) { return "GetToTrivialNestedArray( " + ArgumentString( arg ) + " )"; }

template <typename T>
VLTree<T> GetToTrivialNestedArray( const T& t )
{

  auto t_copy = VLTree<T>();
  t_copy.SetRoot( t );
  return t;

}

template <typename Arg> inline CppClassForString RemoveNestedArrayStringApplication( const Arg& arg ) { return "GetRemoveNestedArray( " + ArgumentString( arg ) + " )"; }

template <typename T>
T GetRemoveNestedArray( const VLTree<T>& t )
{

  if( ! t.empty() ){

    ERR_IMPUT( t );

  }

  return t.GetRoot();

}

template <typename Arg> inline CppClassForString RemovableNestedArrayStringApplication( const Arg& arg ) { return ArgumentString( arg ) + ".empty()"; }


template <typename Arg1, typename Arg2> inline CppClassForString EqStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return WrapInParenthesis( ArgumentString( arg1 ) ) + " == " + WrapInParenthesis( ArgumentString( arg2 ) ); }

template <typename Arg1, typename Arg2> inline CppClassForString NeqStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return WrapInParenthesis( ArgumentString( arg1 ) ) + " != " + WrapInParenthesis( ArgumentString( arg2 ) ); }

template <typename Arg1, typename Arg2> inline CppClassForString LeqStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return "GetLeq( " + ArgumentString( arg1 , arg2 ) + " )"; }

inline bool GetLeq( const int& x1 , const int& x2 ){ return x1 <= x2; }
inline bool GetLeq( const string& x1 , const string& x2 ){ return x2.find( x1 ) != string::npos; }

template <typename Arg1, typename Arg2> inline CppClassForString GeqStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return "GetLeq( " + ArgumentString( arg2 , arg1 ) + " )"; }

template <typename Arg1, typename Arg2> inline CppClassForString LneqStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return WrapInParenthesis( ArgumentString( arg1 ) ) + " < " + WrapInParenthesis( ArgumentString( arg2 ) ); }

template <typename Arg1, typename Arg2> inline CppClassForString GneqStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return WrapInParenthesis( ArgumentString( arg1 ) ) + " > " + WrapInParenthesis( ArgumentString( arg2 ) ); }

template <typename Arg> inline CppClassForString NonNegativeStringApplication( const Arg& arg ) { return WrapInParenthesis( ArgumentString( arg ) ) + " >= 0 "; }


template <typename Arg1, typename Arg2, typename... Args> inline CppClassForString IfStringApplication( const Arg1& arg1 , const Arg2& arg2 , const Args&... args )
{

  return
    "if( " + ArgumentString( arg1 ) + " ){\n\n  "
    
    + ConcatenateWithSeparator( EmptyString() , ArgumentString( arg2 ) , ArgumentString( args )... )

    + "}\n\n";

}

template <typename Arg1, typename Arg2> inline CppClassForString PutStringApplication( const Arg1& arg1 , const Arg2& arg2 ) { return ArgumentString( arg1 ) + " = " + WrapInParenthesis( ArgumentString( arg2 ) ) + ";\n\n"; }

template <typename Arg, typename... Args> inline CppClassForString PrintStringApplication( const Arg& arg , const Args&... args ) { return "cout << " + ConcatenateWithSeparator( " << " , ArgumentString( arg ) , ArgumentString( args )... ) + " << endl;\n\n"; }

inline CppClassForString ExitStringApplication() { return "ERR_CODE;\n\n"; }

template <typename Arg> inline CppClassForString ReturnStringApplication( const Arg& arg ) { return "return " + ArgumentString( arg ) + ";\n\n"; }

