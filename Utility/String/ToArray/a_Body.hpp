// c:/Users/user/Documents/Programming/Utility/String/ToArray/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline char IntToChar( const INT& i , const bool& capital ) { return i + ( capital ? 'A' : 'a' ); }
template <typename INT> inline INT CharToInt( const char& i ) { return i - ( i < 'a' ? 'A' : 'a' ); }

template <typename INT>
string ArrayToString( const vector<INT>& A , const bool& capital )
{

  const int N = A.size();
  string S( N , 'a' );

  for( int i = 0 ; i < N ; i++ ){

    S[i] = IntToChar<INT>( A[i] , capital );

  }

  return S;

}

template <typename INT>
vector<INT> StringToArray( const string& S )
{

  const int N = S.size();
  vector<int> A( N );

  for( int i = 0 ; i < N ; i++ ){

    A[i] = CharToInt<INT>( S[i] );

  }

  return A;

}

