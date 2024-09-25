// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename MODINT , typename INT> inline RollingHash<MODINT,INT>::RollingHash() : RollingHash( GetRand( ( ( MODINT{} - 1 ) / 11 ).Represent() , ( MODINT{} - 1 ).Represent() ) ) {}
template <typename MODINT , typename INT> inline RollingHash<MODINT,INT>::RollingHash( MODINT r ) : m_size( 1 ) , m_r( move( r ) ) , m_r_inv( m_r ) , m_r_power{ 1 } { m_r_inv.Invert(); }

template <typename MODINT , typename INT> inline const MODINT& RollingHash<MODINT,INT>::r() const noexcept { return m_r; }
template <typename MODINT , typename INT> inline const MODINT& RollingHash<MODINT,INT>::r_inv() const noexcept { return m_r_inv; }
template <typename MODINT , typename INT> inline const vector<MODINT>& RollingHash<MODINT,INT>::r_power() const noexcept { return m_r_power; }

template <typename MODINT , typename INT> template <typename STR> inline typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::Encode( const STR& s , const bool& reversed ) { return Encode( s , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::Encode( const STR& s , Enum& e , const bool& reversed )
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

template <typename MODINT , typename INT> template <typename STR> inline typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::CumulativeEncode( const STR& s , const bool& reversed ) { return CumulativeEncode( s , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::CumulativeEncode( const STR& s , Enum& e , const bool& reversed )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
  const int size = s.size();
  CheckSize( size + 1 );
  typename RollingHash<MODINT,INT>::Code answer( size + 1 );

  for( int i = 0 ; i < size ; i++ ){

    answer[i+1] = Concatenate( answer[i] , { e( s[reversed ? size - 1 - i : i] ) * m_r_power[i] , m_r , 1 } );

  }

  return answer;
  
}

template <typename MODINT , typename INT> template <typename STR> inline vector<typename RollingHash<MODINT,INT>::Code> RollingHash<MODINT,INT>::PointwiseEncode( const STR& s , const bool& reversed ) { return PointwiseEncode( s , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
vector<typename RollingHash<MODINT,INT>::Code> RollingHash<MODINT,INT>::PointwiseEncode( const STR& s , Enum& e , const bool& reversed )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
  const int size = s.size();
  CheckSize( size + 1 );
  vector<typename RollingHash<MODINT,INT>::Code> answer( size );

  for( int i = 0 ; i < size ; i++ ){

    answer[i] = { e( s[reversed ? size - 1 - i : i] ) , m_r , 1 };

  }

  return answer;
  
}

template <typename MODINT , typename INT> template <typename STR> inline vector<typename RollingHash<MODINT,INT>::Code> RollingHash<MODINT,INT>::FixedLengthEncode( const STR& s , const int& length , const bool& reversed ) { return FixedLengthEncode( s , length , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR, typename Enum>
vector<typename RollingHash<MODINT,INT>::Code> RollingHash<MODINT,INT>::FixedLengthEncode( const STR& s , const int& length , Enum& e , const bool& reversed )
{

  static_assert( is_invocable_r_v<MODINT,Enum,const decldecay_t( s[0] )&> );
  const int size = s.size();
  vector<typename RollingHash<MODINT,INT>::Code> answer{};

  if( length <= size ){

    CheckSize( length + 1 );
    answer.resize( size - length + 1 , { MODINT{} , m_r_power[length] , 1 } );

    for( int i = 0 ; i < length ; i++ ){

      get<0>( answer[0] ) += e( s[reversed ? size - 1 - i : i] ) * m_r_power[i];

    }

    const int size_shifted = size - length;

    for( int i = 1 ; i <= size_shifted ; i++ ){

      get<0>( answer[i] ) = ( get<0>( answer[i-1] ) - e( s[reversed ? size - i : i - 1] ) ) * m_r_inv + e( s[reversed ? size - i - length : i - 1 + length] ) * m_r_power[length-1];

    }

  }

  return answer;
  
}

template <typename MODINT , typename INT> template <typename CHAR> inline typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::Replace( typename RollingHash<MODINT,INT>::Code code , const INT& i , const CHAR& c_prev , const CHAR& c_next ) const { return Replace( move( code ) , i , c_prev , c_next , Enumeration<CHAR> ); }

template <typename MODINT , typename INT> template <typename CHAR , typename Enum>
typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::Replace( typename RollingHash<MODINT,INT>::Code code , const INT& i , const CHAR& c_prev , const CHAR& c_next , Enum& e ) const
{

  auto& [h,p,s] = code;
  assert( i < s );
  h += ( e( c_next ) -= e( c_prev ) ) *= ( i < m_size ? m_r_power[i] : R_Power( m_r , i ) );
  return move( code );

}

template <typename MODINT , typename INT> template <typename CHAR> inline typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::PopFront( typename RollingHash<MODINT,INT>::Code code , const CHAR& c_prev ) const { return PopFront( move( code ) , c_prev , Enumeration<CHAR> ); }

template <typename MODINT , typename INT> template <typename CHAR , typename Enum>
typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::PopFront( typename RollingHash<MODINT,INT>::Code code , const CHAR& c_prev , Enum& e ) const
{

  auto& [h,p,s] = code;
  assert( s-- > 0 );
  h -= e( c_prev ) * ( s < m_size ? m_r_power[s] : R_Power( m_r , s ) );
  r *= m_r_inv;
  return move( code );

}

template <typename MODINT , typename INT> template <typename CHAR> inline typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::PopBack( typename RollingHash<MODINT,INT>::Code code , const CHAR& c_prev ) const { return PopBack( move( code ) , c_prev , Enumeration<CHAR> ); }

template <typename MODINT , typename INT> template <typename CHAR , typename Enum>
typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::PopBack( typename RollingHash<MODINT,INT>::Code code , const CHAR& c_prev , Enum& e ) const
{

  auto& [h,p,s] = code;
  assert( s-- > 0 );
  ( h -= e( c_prev ) * m_r_power[0] ) *= m_r_inv;
  r *= m_r_inv;
  return move( code );

}

template <typename MODINT , typename INT> template <typename STR> inline INT RollingHash<MODINT,INT>::CountContain( const STR& s , const typename RollingHash<MODINT,INT>::Code& code , const bool& reversed ) { return CountContain( s , code , Enumeration<decldecay_t( s[0] )> , reversed ); }

template <typename MODINT , typename INT> template <typename STR , typename Enum>
INT RollingHash<MODINT,INT>::CountContain( const STR& s , const typename RollingHash<MODINT,INT>::Code& code , Enum& e , const bool& reversed )
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

template <typename MODINT , typename INT> inline typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::Concatenate( typename RollingHash<MODINT,INT>::Code code0 , const typename RollingHash<MODINT,INT>::Code& code1 ) { auto& [h,p,s] = code0; h += get<0>( code1 ) * p; p *= get<1>( code1 ); s += get<2>( code1 ); return move( code0 ); }

template <typename MODINT , typename INT> inline typename RollingHash<MODINT,INT>::Code RollingHash<MODINT,INT>::Fold( typename RollingHash<MODINT,INT>::Code code , INT n ) { assert( n >= 0 ); typename RollingHash<MODINT,INT>::Code answer{ 0 , 1 , 0 }; auto& [h,p,s] = code; while( n > 0 ){ ( n & 1 ) == 1 ? answer = Concatenate( move( answer ) , code ) : answer; h *= p + 1; p *= p; s += s; n >>= 1; } return answer; }

template <typename MODINT , typename INT> void RollingHash<MODINT,INT>::CheckSize( const INT& size ) { while( m_size < size ){ m_r_power.push_back( m_r_power[m_size++ - 1] * m_r ); } }

template <typename MODINT , typename INT> template <typename CHAR> inline MODINT RollingHash<MODINT,INT>::Enumeration( const CHAR& c ) { return MODINT{ c }; }
