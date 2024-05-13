// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT , typename INT> inline RollingHash<MODINT,INT>::RollingHash( MODINT r ) : m_size( 1 ) , m_power{ 1 } , m_r( move( r ) ) , m_r_inv( m_r ) { m_r_inv.Invert(); }

template <typename MODINT , typename INT> template <typename STR> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Encode( const STR& s ) { return Encode( s , Enumeration<decldecay_t( s[0] )> ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Encode( const STR& s , Enum& e )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
  const int size = s.size();
  CheckSize( size + 1 );
  
  MODINT answer = 0;

  for( int i = 0 ; i < size ; i++ ){

    answer += e( s[i] ) * m_power[i];

  }

  return { answer , m_power[size] , size };

}

template <typename MODINT , typename INT> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Concatenate( const tuple<MODINT,MODINT,INT>& code0 , const tuple<MODINT,MODINT,INT>& code1 ) const { return { get<0>( code0 ) + get<0>( code1 ) * get<1>( code0 ) , get<1>( code0 ) * get<1>( code1 ) , get<2>( code0 ) + get<2>( code1 ) }; }

template <typename MODINT , typename INT> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Fold( tuple<MODINT,MODINT,INT> code , INT n ) const { assert( n >= 0 ); tuple<MODINT,MODINT,INT> answer{ 0 , 1 , 0 }; auto& [h,p,s] = code; while( n > 0 ){ ( n & 1 ) == 1 ? answer = Concatenate( answer , code ) : answer; h *= p + 1; p *= p; s += s; n >>= 1; } return answer; }

template <typename MODINT , typename INT> template <typename CHAR> inline tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const { return Replace( code , i , c_prev , c_next , Enumeration<CHAR> ); }
template <typename MODINT , typename INT> template <typename CHAR , typename Enum>
tuple<MODINT,MODINT,INT> RollingHash<MODINT,INT>::Replace( tuple<MODINT,MODINT,INT> code , const INT& i , const CHAR& c_prev , const CHAR& c_next , Enum& e ) const
{

  auto& [h,p,s] = code;
  assert( i < s );
  h += ( e( c_next ) -= e( c_prev ) ) *= ( i < m_size ? m_power[i] : Power( m_r , i ) );
  return move( code );

}

template <typename MODINT , typename INT> template <typename STR> inline INT RollingHash<MODINT,INT>::CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code ) { return CountContain( s , code , Enumeration<decldecay_t( s[0] )> ); }

template <typename MODINT , typename INT> template <typename STR , typename Enum>
INT RollingHash<MODINT,INT>::CountContain( const STR& s , const tuple<MODINT,MODINT,INT>& code , Enum& e )
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
  const MODINT& power = m_power[size1 - 1];
  INT answer = 0;
  MODINT temp = 0;

  for( INT i = 0 ; i < size0 ; i++ ){

    ( i < size1 ? temp += e( s[i] ) * m_power[i] : ( ( temp -= e( s[i - size1] ) ) *= m_r_inv ) += e( s[i] ) * power ) == n ? ++answer : answer;

  }

  return answer;

}

template <typename MODINT , typename INT> void RollingHash<MODINT,INT>::CheckSize( const INT& size ) { m_power.reserve( size ); while( m_size < size ){ m_power.push_back( m_power[m_size++ - 1] * m_r ); } }

template <typename MODINT , typename INT> template <typename CHAR> inline MODINT RollingHash<MODINT,INT>::Enumeration( const CHAR& c ) { return MODINT{ c }; }
