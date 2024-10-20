// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Random/a_Body.hpp"

template <typename MODINT , typename INT , typename CODE> inline RollingHash<MODINT,INT,CODE>::RollingHash() : RollingHash( GetRand() ) {}
template <typename MODINT , typename INT , typename CODE> inline RollingHash<MODINT,INT,CODE>::RollingHash( MODINT r ) : m_size( 1 ) , m_r( move( r ) ) , m_r_inv( m_r ) , m_r_power{ 1 } { m_r_inv.Invert(); }

template <typename MODINT , typename INT , typename CODE> inline const MODINT& RollingHash<MODINT,INT,CODE>::r() const noexcept { return m_r; }
template <typename MODINT , typename INT , typename CODE> inline const MODINT& RollingHash<MODINT,INT,CODE>::r_inv() const noexcept { return m_r_inv; }
template <typename MODINT , typename INT , typename CODE> inline const vector<MODINT>& RollingHash<MODINT,INT,CODE>::r_power() const noexcept { return m_r_power; }

template <typename MODINT , typename INT , typename CODE> template <typename STR> inline CODE RollingHash<MODINT,INT,CODE>::Encode( const STR& s , const bool& reversed )
{

  const int size = s.size();
  CheckSize( size + 1 );
  MODINT answer = 0;

  for( int i = 0 ; i < size ; i++ ){

    answer += Twist( s[reversed ? size - 1 - i : i] ) * m_r_power[i];

  }

  return { answer , m_r_power[size] , size };

}

template <typename MODINT , typename INT , typename CODE> template <typename STR> inline vector<CODE> RollingHash<MODINT,INT,CODE>::CumulativeEncode( const STR& s , const bool& reversed )
{

  const int size = s.size();
  CheckSize( size + 1 );
  vector<CODE> answer( size + 1 );

  for( int i = 0 ; i < size ; i++ ){

    answer[i+1] = Concatenate( answer[i] , { Twist( s[reversed ? size - 1 - i : i] ) * m_r_power[i] , m_r , 1 } );

  }

  return answer;
  
}

template <typename MODINT , typename INT , typename CODE> template <typename STR> inline vector<CODE> RollingHash<MODINT,INT,CODE>::PointwiseEncode( const STR& s , const bool& reversed )
{

  const int size = s.size();
  CheckSize( size + 1 );
  vector<CODE> answer( size );

  for( int i = 0 ; i < size ; i++ ){

    answer[i] = { Twist( s[reversed ? size - 1 - i : i] ) , m_r , 1 };

  }

  return answer;
  
}

template <typename MODINT , typename INT , typename CODE> template <typename STR> inline vector<CODE> RollingHash<MODINT,INT,CODE>::FixedLengthEncode( const STR& s , const int& length , const bool& reversed )
{

  const int size = s.size();
  vector<CODE> answer{};

  if( length <= size ){

    CheckSize( length + 1 );
    answer.resize( size - length + 1 , { MODINT{} , m_r_power[length] , 1 } );

    for( int i = 0 ; i < length ; i++ ){

      get<0>( answer[0] ) += Twist( s[reversed ? size - 1 - i : i] ) * m_r_power[i];

    }

    const int size_shifted = size - length;

    for( int i = 1 ; i <= size_shifted ; i++ ){

      get<0>( answer[i] ) = ( get<0>( answer[i-1] ) - e( s[reversed ? size - i : i - 1] ) ) * m_r_inv + e( s[reversed ? size - i - length : i - 1 + length] ) * m_r_power[length-1];

    }

  }

  return answer;
  
}

template <typename MODINT , typename INT , typename CODE> template <typename CHAR> inline CODE RollingHash<MODINT,INT,CODE>::Replace( CODE code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const
{

  auto& [h,p,s] = code;
  assert( i < s );
  h += ( Twist( c_next ) -= Twist( c_prev ) ) *= ( i < m_size ? m_r_power[i] : R_Power( m_r , i ) );
  return move( code );

}

template <typename MODINT , typename INT , typename CODE> template <typename CHAR> inline CODE RollingHash<MODINT,INT,CODE>::PopFront( CODE code , const CHAR& c_prev ) const
{

  auto& [h,p,s] = code;
  assert( s-- > 0 );
  h -= Twist( c_prev ) * ( s < m_size ? m_r_power[s] : R_Power( m_r , s ) );
  r *= m_r_inv;
  return move( code );

}

template <typename MODINT , typename INT , typename CODE> template <typename CHAR> inline CODE RollingHash<MODINT,INT,CODE>::PopBack( CODE code , const CHAR& c_prev ) const
{

  auto& [h,p,s] = code;
  assert( s-- > 0 );
  ( h -= Twist( c_prev ) * m_r_power[0] ) *= m_r_inv;
  r *= m_r_inv;
  return move( code );

}

template <typename MODINT , typename INT , typename CODE> template <typename STR> inline INT RollingHash<MODINT,INT,CODE>::CountContain( const STR& s , const CODE& code , const bool& reversed )
{

  const INT size0 = s.size();
  CheckSize( size0 );
  const MODINT& n = get<0>( code );
  const INT& size1 = get<2>( code );

  if( size1 == 0 ){

    return 1;
    
  }
  
  CheckSize( size1 );
  const MODINT& r_power = m_r_power[size1 - 1];
  INT answer = 0;
  MODINT temp = 0;

  for( INT i = 0 ; i < size0 ; i++ ){

    ( i < size1 ? temp += e( s[reversed ? size0 - 1 - i : i] ) * m_r_power[i] : ( ( temp -= Twist( s[reversed ? size0 + size1 - 1 - i : i - size1] ) ) *= m_r_inv ) += Twist( s[reversed ? size0 - 1 - i : i] ) * r_power ) == n ? ++answer : answer;

  }

  return answer;

}

template <typename MODINT , typename INT , typename CODE> inline CODE RollingHash<MODINT,INT,CODE>::Concatenate( CODE code0 , const CODE& code1 ) { auto& [h,p,s] = code0; h += get<0>( code1 ) * p; p *= get<1>( code1 ); s += get<2>( code1 ); return move( code0 ); }

template <typename MODINT , typename INT , typename CODE> inline CODE RollingHash<MODINT,INT,CODE>::Fold( CODE code , INT n ) { assert( n >= 0 ); CODE answer{ 0 , 1 , 0 }; auto& [h,p,s] = code; while( n > 0 ){ ( n & 1 ) == 1 ? answer = Concatenate( move( answer ) , code ) : answer; h *= p + 1; p *= p; s += s; n >>= 1; } return answer; }

template <typename MODINT , typename INT , typename CODE> MODINT RollingHash<MODINT,INT,CODE>::GetRand() { return ::GetRand( ( ( MODINT{} - 1 ) / 11 ).Represent() , ( MODINT{} - 1 ).Represent() ); }

template <typename MODINT , typename INT , typename CODE> void RollingHash<MODINT,INT,CODE>::CheckSize( const INT& size ) { while( m_size < size ){ m_r_power.push_back( m_r_power[m_size++ - 1] * m_r ); } }

template <typename MODINT , typename INT , typename CODE> MODINT RollingHash<MODINT,INT,CODE>::Twist( const ll& c ) { return MODINT( c ); }
