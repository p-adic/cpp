// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/WalshHadamardTransform/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename T , typename INT>
tuple<T,T,INT> AffineTraceProduct( const vector<tuple<T,T,INT>>& f , const INT& order )
{

  const T m{ order };
  T a{0} , b{1};
  INT c = 0;

  for( auto& [a_i,b_i,c_i] : f ){

    assert( 0 <= c_i && c_i < order );
    a = a * b_i + a_i * b + a * a_i * m;
    b *= b_i;
    ( c += c_i ) < order ? c : c -= order;

  }

  return { move( a ) , move( b ) , c };

}

template <typename T>
vector<T> AffineShiftProduct( const vector<tuple<T,T,int>>& f , const int digit )
{

  assert( 0 <= digit && digit < 30 );
  const int N = 1 << digit;
  assert( int( f.size() ) <= N );
  auto [a,b,c] = AffineTraceProduct( f , N );
  vector<T> answer( N );

  for( int j = 0 ; j < N ; j++ ){

    answer[j] = N * a + ( ( __builtin_popcount( c & j ) & 1 ) == 0 ? b : -b );

  }

  return answer;
  
}

template <typename T>
vector<T> WalshHadamardTransform( vector<T> f , const int& digit )
{

  assert( 0 <= digit && digit < 30 );
  const int N = 1 << digit;
  assert( int( f.size() ) <= N );
  f.resize( N );

  for( int d = 0 ; d < digit ; d++ ){

    const int p = 1 << d , q = p << 1;

    for( int j = 0 ; j < N ; j += q ){

      assert( j < ( j | p ) );

      for( int i = j ; i < ( j | p ) ; i++ ){

        T temp = f[i];
        f[i] = temp + f[i|p];
        f[i|p] = temp - f[i|p];

      }

    }

  }

  return move( f );

}

template <typename T>
vector<T> InverseWalshHadamardTransform( vector<T> f , const int& digit )
{

  f = WalshHadamardTransform( move( f ) , digit );
  const int N = 1 << digit;
  const T scale = T{ 1 } / N;

  for( int i = 0 ; i < N ; i++ ){

    f[i] *= scale;

  }

  return move( f );
  
}

template <typename COMM_SEMIGRP , typename T>
vector<pair<T,T>> AbstractWalshHadamardTransform( COMM_SEMIGRP M , vector<pair<T,T>> f , const int& digit )
{

  static_assert( is_same_v<inner_t<COMM_SEMIGRP>,T> );
  assert( 0 <= digit && digit < 30 );
  const int N = 1<<digit;
  assert( int( f.size() ) <= N );
  const T& one = M.One();
  f.resize( N , {one,one} );

  for( int d = 0 ; d < digit ; d++ ){

    const int p = 1 << d , q = p << 1;

    for( int j = 0 ; j < N ; j += q ){

      assert( j < ( j | p ) );

      for( int i = j ; i < ( j | p ) ; i++ ){

        auto [a,b] = f[i];
        auto& [c,d] = f[i|p];
        f[i] = { M.Product( a , c ) , M.Product( b , d ) };
        f[i|p] = { M.Product( move( a ) , d ) , M.Product( move( b ) , c ) };;

      }

    }

  }

  return move( f );

}

template <typename COMM_SEMIGRP , typename T>
vector<pair<T,T>> AbstractTwistedWalshHadamardTransform( COMM_SEMIGRP M , vector<tuple<T,T,int>> f , const int& digit )
{

  static_assert( is_same_v<inner_t<COMM_SEMIGRP>,T> );
  const T& one = M.One();
  const int N = 1 << digit;
  vector<pair<T,T>> g( N , {one,one} );

  for( auto& [a,b,c] : f ){

    assert( 0 <= c && c < N );
    auto& [u,v] = g[c];
    u = M.Product( move( u ) , a );
    v = M.Product( move( v ) , b );

  }

  return AbstractWalshHadamardTransform( move( M ) , g , digit );

}
