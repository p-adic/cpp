// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/Offline/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U1 , typename MONOID , typename U2 , typename GROUP , typename ARRAY , typename HOM , typename T> inline OfflineCumulativeProduct<U1,MONOID,U2,GROUP,ARRAY,HOM,T>::OfflineCumulativeProduct( MONOID M1 , GROUP M2 , ARRAY a , HOM& h , const T& dummy ) : m_M1( move( M1 ) ) , m_M2( move( M2 ) ) , m_a( move( a ) ) , m_h( h ) { static_assert( is_same_v<U1,inner_t<MONOID>> && is_same_v<U2,inner_t<GROUP>> && is_invocable_r_v<U1,ARRAY,const int&> && is_invocable_r_v<U2,HOM,const T&,U1&> ); }

template <typename U1 , typename MONOID , typename U2 , typename GROUP , typename ARRAY , typename HOM , typename T> inline vector<U2> OfflineCumulativeProduct<U1,MONOID,U2,GROUP,ARRAY,HOM,T>::TotalIntervalProduct( const vector<tuple<int,int,T>>& query )
{

  const int Q = query.size();
  set<tuple<int,int>> event{};

  for( int q = 0 ; q < Q ; q++ ){

    auto& [l,r,t] = query[q];
    assert( 0 <= l && l <= r + 1 );
    event.insert( { l - 1 , q } );
    event.insert( { r , Q + q } );

  }

  int N = -1;
  U1 temp = m_M1.One();
  vector<U2> answer( Q , m_M2.One() );

  for( auto& [i,j] : event ){

    while( N < i ){

      temp = m_M1.Product( move( temp ) , m_a( ++N ) );

    }

    const bool left = j < Q;
    const int q = left ? j : j - Q;
    auto&& u = m_h( get<2>( query[q] ) , temp );
    answer[q] = left ? m_M2.Inverse( u ) : m_M2.Product( move( answer[q] ) , u );

  }

  return answer;

}
