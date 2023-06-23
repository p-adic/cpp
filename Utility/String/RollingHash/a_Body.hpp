// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a_Body.hpp

#pragma once
#include "a.hpp"

template <ll p , ll r , int length_max> inline constexpr RollingHash<p,r,length_max>::RollingHash() : m_power() , m_p_inv( 1 )
{

  ll power = 1;
  
  for( int i = 0 ; i <= length_max ; i++ ){

    m_power[i] = power;
    ( power *= r ) %= p;

  }

  power = r;
  ll exponent = p - 2;
  
  while( exponent > 0 ){

    ( exponent & 1 ) == 1 ? ( m_p_inv *= power ) %= p : m_p_inv;
    ( power *= power ) %= p;
    exponent >>= 1;

  }

}

template <ll p , ll r , int length_max>
tuple<ll,ll,int> RollingHash<p,r,length_max>::Encode( const string& s ) const
{

  int size = s.size();
  assert( size <= length_max );
  
  ll answer = 0;

  for( int i = 0 ; i < size ; i++ ){

    ( answer += s[i] * m_power[i] ) %= p;

  }

  return { answer , m_power[size] , size };

}

template <ll p , ll r , int length_max>
inline tuple<ll,ll,int> RollingHash<p,r,length_max>::Concatenate( const tuple<ll,ll,int>& code0 , const tuple<ll,ll,int>& code1 ) const { return { ( get<0>( code0 ) + get<0>( code1 ) * get<1>( code0 ) ) % p , ( get<1>( code0 ) * get<1>( code1 ) ) % p , get<2>( code0 ) + get<2>( code1 ) }; }

template <ll p , ll r , int length_max>
int RollingHash<p,r,length_max>::CountContain( const string& s , const tuple<ll,ll,int>& code ) const
{

  const int& size0 = s.size();
  assert( size0 <= length_max );
  const ll& n = get<0>( code );
  const int& size1 = get<2>( code );

  if( size1 == 0 ){

    return 1;
    
  }
  
  const ll& power = m_power[size1 - 1];
  int answer = 0;
  ll temp = 0;

  for( int i = 0 ; i < size0 ; i++ ){

    ( ( i < size1 ? temp += s[i] * m_power[i] : ( ( ( temp -= s[i - size1] ) < 0 ? temp += p : temp ) *= m_p_inv ) += s[i] * power ) %= p ) == n ? ++answer : answer;

  }

  return answer;

}
