// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial() : Polynomial<T>() , m_N( 0 ) {}
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const TruncatedPolynomial<T>& f ) : Polynomial<T>( f ) , m_N( f.m_N ) {}
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const T& t ) : Polynomial<T>( t ) , m_N( N ) {}

template <typename T>
TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const Polynomial<T>& f ) : Polynomial<T>() , m_N( N )
{

  const uint& size = f.m_size < m_N ? f.m_size : m_N;
  for( uint i = 0 ; i < size ; i++ ){

    m_f.push_back( f.m_f[i] );
    m_size++;
    
  }

  return *this;

}

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const uint& i , const T& t ) : Polynomial<T>() , m_N( N ) { if( i < m_N ? t != const_zero() : false ){ operator[]( i ) = t; } }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial<T>& operator=( const TruncatedPolynomial<T>& f ) { Polynomial<T>::operator=( f ); m_N = f.m_N; return *this; }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial<T>& operator=( const T& t ) { Polynomial<T>::operator=( t ); return *this; }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial<T>& operator=( const Polynomial<T>& f ) { return operator=( TruncatedPolynomial<T>( m_N , f ) ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const T& t ) { Polynomial<T>::operator+=( t ); return *this; }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const Polynomial<T>& f )
{

  const uint& size = f.m_size < m_N ? f.m_size : m_N;
  for( uint i = 0 ; i < size ; i++ ){

    operator[]( i ) += f.m_f[i];

  }

  return *this;

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const T& t ) { Polynomial<T>::operator-=( t ); return *this; }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const Polynomial<T>& f )
{

  const uint& size = f.m_size < m_N ? f.m_size : m_N;
  for( uint i = 0 ; i < size ; i++ ){

    operator[]( i ) -= f.m_f[i];

  }

  return *this;

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const T& t ) { Polynomial<T>::operator*=( t ); return *this; }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const Polynomial<T>& f )
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  if( m_size == 0 ){

    return *this;

  }

  if( f.m_size == 0 ){

    return operator=( Polynomial<T>::zero() );

  }
  
  uint size = m_size + f.m_size - 1;

  if( size >= m_N ){

    size = m_N;

  }

  TruncatedPolynomial<T> product{ m_N , 0 };  
      
  for( uint i = 0 ; i < size ; i++ ){

    T& product_i = product[i];
    const uint j_min = m_size <= i ? i - m_size + 1 : 0;
    const uint j_lim = i < f.m_size ? i + 1 : f.m_size;
      
    for( uint j = j_min ; j < j_lim ; j++ ){
	
      product_i += m_f[i - j] * f.m_f[j];

    }

  }

  product.RemoveRedundantZero();
  return operator=( product );

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const T& t ) { Polynomial<T>::operator/=( t ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator%=( const T& t ) { Polynomial<T>::operator%=( t ); return *this; }


template <typename T> inline void TruncatedPolynomial<T>::SetTruncation( const uint& N ) noexcept { m_N = N; Truncate(); }
template <typename T> inline const uint& TruncatedPolynomial<T>::GetTruncation() const noexcept { return m_N; }

template <typename T> inline void TruncatedPolynomial<T>::Truncate(){ while( m_size > m_N ){ m_f.pop_back(); m_size--; } }

template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();
  TruncatedPolynomial<T> answer{ N , 1 };
  TruncatedPolynomial<T> power{ N , 1 };
  T factorial_inv = 1;

  for( uint i = 1 , i < N ; i++ ){

    power *= f;
    factorial_inv /= i;
    answer += power * factorial_inv;

  }

  return answer;

}

template <typename T>
TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();
  TruncatedPolynomial<T> e = f - 1;
  TruncatedPolynomial<T> answer{ N , 1 };
  TruncatedPolynomial<T> power{ N , 1 };

  for( uint i = 1 , i < N ; i++ ){

    power *= f;
    answer += power / i;

  }

  return answer;

}

template <typename T> inline TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t ) { return Exp( Log( f ) * t ); }
