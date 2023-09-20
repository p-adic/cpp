// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/StirlingNumber/SecondKind/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , int length> constexpr inline SecondStirlingNumberCalculator<T,length>::SecondStirlingNumberCalculator() : m_val() 
{
  
  m_val[0][0] = 1;

  for( int i = 1 ; i < length ; i++ ){

    auto& m_val_i = m_val[i];
    const auto& m_val_i_minus = m_val[i - 1];

    for( int j = 1 ; j < i ; j++ ){

      ( ( m_val_i[j] = m_val_i_minus[j] ) *= j ) += m_val_i_minus[j - 1];

    }

    m_val_i[i] = 1;

  }

}

template <typename T , int length> constexpr inline const T ( &SecondStirlingNumberCalculator<T,length>::operator[]( const int& i ) const )[length] { assert( i < length ); return m_val[i]; }

template <typename T , int length> constexpr inline T SecondStirlingNumberCalculator<T,length>::CountDisjointCover( const int& N , const int& i ) const { assert( N < length ); return i <= N ? m_val[N][i] : T(); }
template <typename T , int length> constexpr inline T SecondStirlingNumberCalculator<T,length>::CountDisjointSubset( const int& N , const int& i ) const { assert( N < length ); return i < N ? m_val[N][i] + m_val[N][i+1] : i == N ? m_val[N][i] : T(); }

template <typename T , int length> inline T SecondStirlingNumberCalculator<T,length>::CountDisjointCoverSequence( const int& N , const int& i ) const { return CountDisjointCover( N , i ) * T::Factorial( i ); }
template <typename T , int length> inline T SecondStirlingNumberCalculator<T,length>::CountDisjointSubsetSequence( const int& N , const int& i ) const { return CountDisjointSubset( N , i ) * T::Factorial( i ); }

template <typename T , int length> inline T SecondStirlingNumberCalculator<T,length>::CountDisjointCover( const int& N , const int& n , const int& i ) const { return CountDisjointCover( n , i ) * T::Combination( N , n ); }
template <typename T , int length> inline T SecondStirlingNumberCalculator<T,length>::CountDisjointCoverSequence( const int& N , const int& n , const int& i ) const { return CountDisjointCoverSequence( n , i ) * T::Combination( N , n ); }
