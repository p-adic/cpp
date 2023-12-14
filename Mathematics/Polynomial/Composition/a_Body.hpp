// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Composition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// MoeviusCompositionにPowerを使う。
// ExponentialCompositionにExponentialSumを使う。
#include "../Sum/a_Body.hpp"
// LogarithmCompositionにSetPointTreeなどを使う。
#include "../MultipointEvaluation/a_Body.hpp"

template <typename T>
TruncatedPolynomial<T> Composite( const TruncatedPolynomial<T>& f  , const TruncatedPolynomial<T>& g )
{

  const uint& N = f.GetTruncation();
  assert( N > 0 && g[0] == Polynomial<T>::const_zero() );
  const uint N_minus = N - 1;

  if( N_minus == 0 ){

    return *this;

  }

  const uint H = sqrt( N_minus );
  const uint K = N_minus / H;
  vector<TruncatedPolynomial<T> > g_power( K < 2 ? 2 : K );
  ( g_power[1] = g ).SetTruncation( N );
  
  for( uint k = 2 ; k < K ; k++ ){

    g_power[k] = g_power[k-1] * g_power[1];

  }

  vector<TruncatedPolynomial<T> > g_power2( H + 1 );
  g_power2[1] = K < 2 ? g_power[1] : g_power[K-1] * g_power[1];

  for( uint h = 2 ; h <= H ; h++ ){

    g_power2[h] = g_power2[h-1] * g_power2[1];

  }

  uint k = 0;
  uint h = 0;
  uint n_max = N_minus;
  TruncatedPolynomial<T> answer{ N };
  TruncatedPolynomial<T> answer_h{ N };

  for( uint d = 0 ; d < N ; d++ ){

    for( uint n = k ; n <= n_max ; n++ ){

      answer_h[n] += k == 0 ? n == 0 ? f[d] : T{} : f[d] * g_power[k][n];

    }
    
    if( ++k == K || d == N_minus ){

      answer += h == 0 ? answer_h : answer_h *= g_power2[h];
      k = 0;
      h++;
      n_max -= K;
      answer_h = TruncatedPolynomial<T>( N );

    }

  }

  return answer;

}

template <typename T>
void Reverse( const unt& N , Polynomial<T>& f )
{

  f.resize( N );
  const uint N_half = N / 2;
  
  for( uint d = 0 ; d < N_half ; d++ ){

    swap( f[d] , f[ N - 1 - d ] );

  }

  return;
  
}

template <typename T>
void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false )
{

  f.RemoveRedundantZero();
  const uint& size = f.size();
  
  if( size > 0 && t != Polynomial<T>::const_zero() ){

    TruncatedPolynomial<T> exp_t_transpose{ size * 2 };
    T power_t = Polynomial<T>::const_one();
  
    for( uint d = 0 ; d < size ; d++ ){

      exp_t_transpose[size - 1 - d] = power_t * T::FactorialInverse( d );
      power_t *= t;

    }

    if( exponential ){

      exp_t_transpose *= f;

      for( uint d = 0 ; d < size ; d++ ){

	f[d] = exp_t_transpose[d + size - 1];

      }

    } else {

      for( uint d = 0 ; d < size ; d++ ){

	f[d] *= T::Factorial( d );

      }

      exp_t_transpose *= f;

      for( uint d = 0 ; d < size ; d++ ){

	f[d] = exp_t_transpose[d + size - 1] * T::FactorialInverse( d );

      }

    }

  }

  return;
  
}

template <typename T>
void AffineTransformation( Polynomial<T>& f , const T& t , const T& u , const bool& exponential )
{

  Shift( f , u , exponential );
  const uint& size = f.size();
  T power = Polynomial<T>::const_one();

  for( uint d = 0 ; d < size ; d++ ){

    f[d] *= power;
    power *= t;

  }

  return;

}

template <typename T>
tuple<Polynomial<T>,T,T,uint> MoeviusComposition( Polynomial<T> f , T a , T b , T c , T d )
{

  const T& zero = Polynomial<T>::const_zero();
  const T& one = Polynomial<T>::const_one();
  
  if( c == zero ){

    d = one / d;
    AffineTransformation( f , a *= d , b *= d );
    return { move( f ) , zero , one , 0 };

  }
  
  a /= c;
  b -= a * d;
    
  if( b == zero ){

    return { f( a ) , zero , one , 0 };

  }

  b = one / b;
  c *= b;
  d *= b;
  Shift( f , a );
  const uint& size = f.size();
  Reverse( size , f );
  AffineTransformation( f , c , d );
  return { move( f ) , move( c ) , move( d ) , size - 1 };

}

template <typename T>
TrucatedPolynomial<T> MoeviusComposition( const uint& N , Polynomial<T> f , T a , T b , T c , T d )
{

  const T& zero = Polynomial<T>::const_zero();
  const T& one = Polynomial<T>::const_one();
  
  if( c == zero ){

    d = one / d;
    AffineTransformation( f , a *= d , b *= d );

  } else {
  
    a /= c;
    b -= a * d;
    
    if( b == zero ){

      f = f( a );

    } else {

      b = one / b;
      c *= b;
      d *= b;
      Shift( f , a );
      const uint& size = f.size();

      if( size > 0 ){
	
	Reverse( size , f );
	AffineTransformation( f , c , d );
	TruncatedPolynomial<T> g{ N };
	g[0] = move( d );
	g[1] = move( c );
	g = Inverse( Power( g , size - 1 ) );
	g *= f;
	f = move( g );

      }

    }

  }

  return TruncatedPolynomial<T>( N , f );

}

template <typename T>
TruncatedPolynomial<T> ExponentialComposition( const uint& N , const Polynomial<T>& f , const T& t )
{

  const uint& size = f.size();
  list<pair<T,T>> coef{};
  T temp = Polynomial<T>::const_zero();

  for( uint d = 0 ; d < size ; d++ ){

    coef.push_back( { f[d] , temp } );
    temp += t;

  }
  
  return ExponentialSum( N , coef );

}

template <typename T>
TruncatedPolynomial<T> MoeviusExponentialComposition( const uint& N , const Polynomial<T>& f , T a , T b , T c , T d , const T& t )
{

  auto [h,u,v,e] = MoeviusComposition( f , move( a ) , move( b ) , move( c ) , move( d ) );
  TruncatedPolynomial<T> g{ ExponentialComposition( N , h , t ) };
  h.resize( 2 );
  h[0] = move( v );
  h[1] = move( u );
  TruncatedPolynomial<T> r{ ExponentialComposition( N , h , t ) };
  r = Power( r , e );
  return move( g /= r );
  
}

template <typename T>
TruncatedPolynomial<T> LogarithmComposition( const uint& N , Polynomial<T> f , const T& t )
{

  const uint& f_size = f.size();

  if( f_size == 0 ){

    return TruncatedPolynomial<T>( N );
    
  }

  const T& zero = Polynomial<T>::const_zero();
  
  if( t == zero ){

    return TruncatedPolynomial<T>( N , f( t ) );
    
  }
  
  // 部分分数分解による復元のためにfの次数分も必要であることに注意。
  const uint size = max( f_size , N );
  list<T> point{};
  vector<T> coef{};

  for( uint d = 0 ; d < f_size ; d++ ){

    f[d] *= T::Factorial( d );

  }

  for( uint d = 1 ; d < size ; d++ ){

    point.push_back( t * T::Inverse( d ) );

  }

  SetPartialFractionDecomposition( size , f , point , coef );
  point.clear();
  f = move( coef );
  const T& one = Polynomial<T>::const_one();
  const T t_inv_minus = -one / t;
  T temp = t_inv_minus;
  
  for( uint d = 1 ; d < size ; d++ ){

    f[d] *= temp;
    temp += t_inv_minus;
    
  }
  
  Shift( f , one );
  return TruncatedPolynomial<T>( N , move( f ) );

}

template <typename T>
TruncatedPolynomial<T> MoeviusLogarithmComposition( const uint& N , Polynomial<T> f , T a , T b , T c , const T& t )
{

  const T& zero = Polynomial<T>::const_zero();
  assert( b != zero );
  f = LogarithmComposition( N , move( f ) , t );
  a -= c;
  return MoeviusComposition( N , f , a , zero , c , b );
  
}
