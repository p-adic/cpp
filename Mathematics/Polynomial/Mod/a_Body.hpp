// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N ) : Polynomial<T>() , m_N( N ) {}
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const TruncatedPolynomial<T>& f ) : Polynomial<T>( f ) , m_N( f.m_N ) {}
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const T& t ) : Polynomial<T>( t ) , m_N( N ) {}

template <typename T>
TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const Polynomial<T>& f ) : Polynomial<T>() , m_N( N )
{

  const uint& size = f.Polynomial<T>::m_size < m_N ? f.Polynomial<T>::m_size : m_N;

  for( uint i = 0 ; i < size ; i++ ){

    Polynomial<T>::m_f.push_back( f.Polynomial<T>::m_f[i] );
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

  const uint& size = f.Polynomial<T>::m_size < m_N ? f.Polynomial<T>::m_size : m_N;
  for( uint i = 0 ; i < size ; i++ ){

    Polynomial<T>::operator[]( i ) += f.Polynomial<T>::m_f[i];

  }

  return *this;

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const T& t ) { Polynomial<T>::operator-=( t ); return *this; }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const Polynomial<T>& f )
{

  const uint& size = f.Polynomial<T>::m_size < m_N ? f.Polynomial<T>::m_size : m_N;
  
  for( uint i = 0 ; i < size ; i++ ){

    Polynomial<T>::operator[]( i ) -= f.Polynomial<T>::m_f[i];

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

  if( f.Polynomial<T>::m_size == 0 ){

    return operator=( Polynomial<T>::zero() );

  }
  
  uint size = Polynomial<T>::m_size + f.Polynomial<T>::m_size - 1;

  if( size >= m_N ){

    size = m_N;

  }

  TruncatedPolynomial<T> product{ m_N , 0 };  
      
  for( uint i = 0 ; i < size ; i++ ){

    T& product_i = product[i];
    const uint j_min = Polynomial<T>::m_size <= i ? i - Polynomial<T>::m_size + 1 : 0;
    const uint j_lim = i < f.Polynomial<T>::m_size ? i + 1 : f.Polynomial<T>::m_size;
      
    for( uint j = j_min ; j < j_lim ; j++ ){
	
      product_i += Polynomial<T>::m_f[i - j] * f.Polynomial<T>::m_f[j];

    }

  }

  product.Polynomial<T>::RemoveRedundantZero();
  return operator=( product );

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const T& t ) { Polynomial<T>::operator/=( t ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator%=( const T& t ) { Polynomial<T>::operator%=( t ); return *this; }


template <typename T> inline void TruncatedPolynomial<T>::SetTruncation( const uint& N ) noexcept { m_N = N; Truncate(); }
template <typename T> inline const uint& TruncatedPolynomial<T>::GetTruncation() const noexcept { return m_N; }

template <typename T> inline void TruncatedPolynomial<T>::Truncate(){ while( Polynomial<T>::m_size > m_N ){ Polynomial<T>::m_f.pop_back(); Polynomial<T>::m_size--; } }

template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();
  TruncatedPolynomial<T> answer{ N , 1 };
  TruncatedPolynomial<T> power{ N , 1 };
  T factorial_inv = 1;

  for( uint i = 1 ; i < N ; i++ ){

    power *= f;
    factorial_inv /= i;
    answer += power * factorial_inv;

  }

  return answer;

}

template <typename T> inline TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f ) { return ShiftedLog<T>( f - TruncatedPolynomial<T>::const_one() ); }

template <typename T>
TruncatedPolynomial<T> ShiftedLog( const TruncatedPolynomial<T>& f )
{

  const uint& N = f.GetTruncation();
  TruncatedPolynomial<T> answer{ N };
  TruncatedPolynomial<T> power{ N , 1 };
  const uint& size = f.size();
  const T& zero = Polynomial<T>::const_zero();
  uint d_min = 0;

  for( uint i = 1 ; i < size && d_min == 0 ; i++ ){

    if( f[i] != zero ){

      d_min = i;

    }
    
  }

  const uint i_max = d_min == 0 ? 0 : N / d_min;
  
  for( uint i = 1 ; i <= i_max ; i++ ){

    power *= f;
    answer += power / T( i );

  }

  return answer;

}

template <typename T> inline TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t ) { return Exp( Log( f ) * t ); }
