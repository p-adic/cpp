// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N ) : Polynomial<T>() , m_N( N ) {}
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const TruncatedPolynomial<T>& f ) : Polynomial<T>( f ) , m_N( f.m_N ) {}
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const T& t ) : Polynomial<T>( t ) , m_N( N ) {}

template <typename T>
TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const Polynomial<T>& f ) : Polynomial<T>() , m_N( N )
{

  const uint& f_size = f.Polynomial<T>::size();
  const uint& size = f_size < m_N ? f_size : m_N;
  
  for( uint i = 0 ; i < size ; i++ ){

    Polynomial<T>::m_f.push_back( f.Polynomial<T>::operator[]( i ) );
    Polynomial<T>::m_size++;
    
  }

}

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const uint& i , const T& t ) : Polynomial<T>() , m_N( N ) { if( i < m_N ? t != Polynomial<T>::const_zero() : false ){ Polynomial<T>::operator[]( i ) = t; } }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const TruncatedPolynomial<T>& f ) { Polynomial<T>::operator=( f ); m_N = f.m_N; return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const T& t ) { Polynomial<T>::operator=( t ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const Polynomial<T>& f ) { return operator=( TruncatedPolynomial<T>( m_N , f ) ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const T& t ) { Polynomial<T>::operator+=( t ); return *this; }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const Polynomial<T>& f )
{

  const uint& f_size = f.Polynomial<T>::size();
  const uint& size = f_size < m_N ? f_size : m_N;

  for( uint i = 0 ; i < size ; i++ ){

    Polynomial<T>::operator[]( i ) += f.Polynomial<T>::operator[]( i );

  }

  return *this;

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const T& t ) { Polynomial<T>::operator-=( t ); return *this; }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const Polynomial<T>& f )
{

  const uint& f_size = f.Polynomial<T>::size();
  const uint& size = f_size < m_N ? f_size : m_N;
  
  for( uint i = 0 ; i < size ; i++ ){

    Polynomial<T>::operator[]( i ) -= f.Polynomial<T>::operator[]( i );

  }

  return *this;

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const T& t ) { Polynomial<T>::operator*=( t ); return *this; }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const Polynomial<T>& f )
{

  if( ! Polynomial<T>::m_no_redundant_zero ){
    
    Polynomial<T>::RemoveRedundantZero();

  }

  if( Polynomial<T>::m_size == 0 ){

    return *this;

  }

  const uint& f_size = f.Polynomial<T>::size();
  
  if( f_size == 0 ){

    return operator=( Polynomial<T>::zero() );

  }
  
  uint size = Polynomial<T>::m_size + f_size - 1;

  if( size >= m_N ){

    size = m_N;

  }

  TruncatedPolynomial<T> product{ m_N , 0 };  
      
  for( uint i = 0 ; i < size ; i++ ){

    T& product_i = product[i];
    const uint j_min = Polynomial<T>::m_size <= i ? i - Polynomial<T>::m_size + 1 : 0;
    const uint j_lim = i < f_size ? i + 1 : f_size;
      
    for( uint j = j_min ; j < j_lim ; j++ ){
	
      product_i += Polynomial<T>::operator[]( i - j ) * f.Polynomial<T>::operator[]( j );

    }

  }

  product.Polynomial<T>::RemoveRedundantZero();
  return operator=( product );

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const T& t ) { Polynomial<T>::operator/=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const TruncatedPolynomial<T>& f ) { return operator*=( Inverse( m_N == f.m_N ? f : TruncatedPolynomial<T>( m_N , f ) ) ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator%=( const T& t ) { Polynomial<T>::operator%=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T> TruncatedPolynomial<T>::operator-() const { return TruncatedPolynomial<T>( m_N ).operator-=( *this ); }


template <typename T> inline void TruncatedPolynomial<T>::SetTruncation( const uint& N ) noexcept { m_N = N; Truncate(); }
template <typename T> inline const uint& TruncatedPolynomial<T>::GetTruncation() const noexcept { return m_N; }

template <typename T> inline void TruncatedPolynomial<T>::Truncate(){ while( Polynomial<T>::m_size > m_N ){ Polynomial<T>::m_f.pop_back(); Polynomial<T>::m_size--; } }


template <typename T , typename P> inline TruncatedPolynomial<T> operator+( const TruncatedPolynomial<T>& f0 , const P& f1 ) { TruncatedPolynomial<T> f = f0; f += f1; return f; }
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f ) { return TruncatedPolynomial<T>::zero() - f; }
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f0 , const P& f1 ) { TruncatedPolynomial<T> f = f0; return f.operator-=( f1 ); }
template <typename T , typename P> inline TruncatedPolynomial<T> operator*( const TruncatedPolynomial<T>& f0 , const P& f1 ) { TruncatedPolynomial<T> f = f0; return f.operator*=( f1 ); }
template <typename T , typename P> inline TruncatedPolynomial<T> operator/( const TruncatedPolynomial<T>& f0 , const P& f1 ) { TruncatedPolynomial<T> f = f0; return f.operator/=( f1 ); }
template <typename T> inline TruncatedPolynomial<T> operator%( const TruncatedPolynomial<T>& f0 , const T& t1 ) { TruncatedPolynomial<T> f = f0; return f.operator%=( t1 ); }


template <typename T>
TruncatedPolynomial<T> Differential( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();

  if( N == 0 ){

    return TruncatedPolynomial<T>();

  }

  TruncatedPolynomial<T> f_dif{ N - 1 };

  for( uint i = 1 ; i < N ; i++ ){

    f_dif[i - 1] = i * f[i];

  }

  return f_dif;

}

template <typename T>
TruncatedPolynomial<T> Integral( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();

  TruncatedPolynomial<T> f_int{ N + 1 };

  for( uint i = 1 ; i <= N ; i++ ){

    f_int[i] = f[i - 1] / T( i );

  }

  return f_int;

}

template <typename T> inline TruncatedPolynomial<T> Differential( const uint& i , const TruncatedPolynomial<T>& f ) { return i == 0 ? f : Differential<T>( i - 1 , Differential<T>( f ) ); }

template <typename T>
TruncatedPolynomial<T> Inverse( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();
  const T& one = Polynomial<T>::const_one();
  const T two = one + one;
  TruncatedPolynomial<T> f_inv{ N , one / f[0] };
  uint power = 1;
  
  while( power < N ){

    f_inv *= - f_inv * f + two;
    power *= 2;

  }

  return f_inv;
  
}

template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();
  const T& one = Polynomial<T>::const_one();
  TruncatedPolynomial<T> f_inv{ N , one };
  uint power = 1;
  
  while( power < N ){

    f_inv *= f - Log( f_inv ) + one;
    power *= 2;

  }

  return f_inv;
  
}

template <typename T> inline TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f ) { return Integral<T>( Differential<T>( f ) / f ); }

template <typename T> inline TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t ) { return Exp( Log( f ) * t ); }
