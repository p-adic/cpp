// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT , typename INT> inline RollingHash<MODINT,INT>::RollingHash( MODINT r ) : m_size( 1 ) , m_r( move( r ) ) , m_r_inv( m_r ) , m_r_power{ 1 } { m_r_inv.Invert(); }

template <typename MODINT , typename INT> inline const MODINT& RollingHash<MODINT,INT>::r() const noexcept { return m_r; }
template <typename MODINT , typename INT> inline const MODINT& RollingHash<MODINT,INT>::r_inv() const noexcept { return m_r_inv; }
template <typename MODINT , typename INT> inline const vector<MODINT>& RollingHash<MODINT,INT>::r_power() const noexcept { return m_r_power; }

template <typename MODINT , typename INT> template <typename STR> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Encode( const STR& s , const bool& reversed ) { return Encode( s , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Encode( const STR& s , Enum& e , const bool& reversed )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
  const int size = s.size();
  CheckSize( size + 1 );
  
  MODINT answer = 0;

  for( int i = 0 ; i < size ; i++ ){

    answer += e( s[reversed ? size - 1 - i : i] ) * m_r_power[i];

  }

  return { answer , m_r_power[size] , size };

}


template <typename MODINT , typename INT> template <typename STR> inline vector<MODINT> RollingHash<MODINT,INT>::CumulativeEncode( const STR& s , const bool& reversed ) { return CumulativeEncode( s , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
vector<MODINT> RollingHash<MODINT,INT>::CumulativeEncode( const STR& s , Enum& e , const bool& reversed )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
  const int size = s.size();
  CheckSize( size + 1 );
  
  vector<MODINT> answer( size + 1 );

  for( int i = 0 ; i < size ; i++ ){

    answer[i+1] = answer[i] + e( s[reversed ? size - 1 - i : i] ) * m_r_power[i];

  }

  return answer;
  
}

template <typename MODINT , typename INT> template <typename STR> inline vector<tuple<MODINT,MODINT,INT>> RollingHash<MODINT,INT>::PointwiseEncode( const STR& s , const bool& reversed ) { return PointwiseEncode( s , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
vector<tuple<MODINT,MODINT,INT>> RollingHash<MODINT,INT>::PointwiseEncode( const STR& s , Enum& e , const bool& reversed )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
  const int size = s.size();
  CheckSize( size + 1 );
  
  vector<tuple<MODINT,MODINT,INT>> answer( size );

  for( int i = 0 ; i < size ; i++ ){

    answer[i] = { e( s[reversed ? size - 1 - i : i] ) , m_r , 1 };

  }

  return answer;
  
}

template <typename MODINT , typename INT> template <typename CHAR> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const { return Replace( code , i , c_prev , c_next , Enumeration<CHAR> ); }
template <typename MODINT , typename INT> template <typename CHAR , typename Enum>
tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next , Enum& e ) const
{

  auto& [h,p,s] = code;
  assert( i < s );
  h += ( e( c_next ) -= e( c_prev ) ) *= ( i < m_size ? m_r_power[i] : R_Power( m_r , i ) );
  return move( code );

}

template <typename MODINT , typename INT> template <typename STR> inline INT RollingHash<MODINT,INT>::CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , const bool& reversed ) { return CountContain( s , code , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR , typename Enum>
INT RollingHash<MODINT,INT>::CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , Enum& e , const bool& reversed )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
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

    ( i < size1 ? temp += e( s[reversed ? size0 - 1 - i : i] ) * m_r_power[i] : ( ( temp -= e( s[reversed ? size0 + size1 - 1 - i : i - size1] ) ) *= m_r_inv ) += e( s[reversed ? size0 - 1 - i : i] ) * r_power ) == n ? ++answer : answer;

  }

  return answer;

}

template <typename MODINT , typename INT> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Concatenate( tuple<MODINT,MODINT,INT> code0 , const tuple<MODINT,MODINT,INT>& code1 ) { auto& [h,p,s] = code0; h += get<0>( code1 ) * p; p *= get<1>( code1 ); s += get<2>( code1 ); return move( code0 ); }

template <typename MODINT , typename INT> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Fold( tuple<MODINT,MODINT,INT> code , INT n ) { assert( n >= 0 ); tuple<MODINT,MODINT,INT> answer{ 0 , 1 , 0 }; auto& [h,p,s] = code; while( n > 0 ){ ( n & 1 ) == 1 ? answer = Concatenate( answer , code ) : answer; h *= p + 1; p *= p; s += s; n >>= 1; } return answer; }

template <typename MODINT , typename INT> void RollingHash<MODINT,INT>::CheckSize( const INT& size ) { m_r_power.reserve( size ); while( m_size < size ){ m_r_power.push_back( m_r_power[m_size++ - 1] * m_r ); } }

template <typename MODINT , typename INT> template <typename CHAR> inline MODINT RollingHash<MODINT,INT>::Enumeration( const CHAR& c ) { return MODINT{ c }; }
