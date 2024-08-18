// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TimeSeriesAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/Group/Module/Interval/a_Body.hpp"

#include "../a_Body.hpp"
#include "../../../../../../Utility/Vector/Query/a_Body.hpp"

template <typename R , typename U , typename C_MODULE> inline AbstractTimeSeriesAddBIT<R,U,C_MODULE>::AbstractTimeSeriesAddBIT( C_MODULE M , R init , const int& N ) : m_M( move( M ) ) , m_init( move( init ) ) , m_N( N ) , m_a( N , m_M.Zero() ) , m_event() {}
template <typename R , typename U , typename C_MODULE> inline AbstractTimeSeriesAddBIT<R,U,C_MODULE>::AbstractTimeSeriesAddBIT( C_MODULE M , R init , vector<U> a , const vector<tuple<R,int,U>>& event ) : m_M( move( M ) ) , m_init( move( init ) ) , m_N( a.size() ) , m_a( move( a ) ) , m_event() { for( auto& [t,i,du] : event ){ Set( t , i , du ); } }

template <typename U> inline TimeSeriesAddBIT<U>::TimeSeriesAddBIT( const int& N ) : AbstractTimeSeriesAddBIT<ll,U,IntervalModule<ll,U>>( IntervalModule<ll,U>() , 0 , N ) {}
template <typename U> template <typename...Args> inline TimeSeriesAddBIT<U>::TimeSeriesAddBIT( vector<U> a , Args&&... args ) : AbstractTimeSeriesAddBIT<ll,U,IntervalModule<ll,U>>( IntervalModule<ll,U>() , 0 , move( a ) , forward<Args>( args )... ) {}
  
template <typename R , typename U , typename C_MODULE> template <typename...Args> inline void AbstractTimeSeriesAddBIT<R,U,C_MODULE>::Initialise( Args&&... args ) { decltype( *this ) temp{ m_M , move( args )... }; m_init = move( temp.m_init ); m_N = temp.m_N; m_a = move( temp.m_a ); m_event = move( temp.m_event ); }

template <typename R , typename U , typename C_MODULE> inline void AbstractTimeSeriesAddBIT<R,U,C_MODULE>::Set( const R& t , const int& i , const U& du ) { assert( 0 <= i && i < m_N ); m_event[{ t , i }] = du; }

template <typename R , typename U , typename C_MODULE> template <typename INT>
vector<U> AbstractTimeSeriesAddBIT<R,U,C_MODULE>::IntervalSum( const vector<tuple<R,INT,INT>>& query , const bool& sorted )
{

  auto query_sorted = QuerySort( query , sorted );
  AbstractBIT a{ m_M , m_a };
  AbstractBIT da{ m_M , m_N };
  auto itr = m_event.begin() , end = m_event.end();
  vector<U> answer( query.size() );

  for( auto& [p,q] : query_sorted ){

    auto& [t,l,r] = *p;

    while( itr != end && itr->first.first < t ){

      auto& [s,i] = itr->first;
      auto& du = itr->second;
      const U ddu = m_M.Sum( du , m_M.Inverse( da[i] ) );
      a.Add( i , m_M.Inverse( m_M.VirtualRSet<pair<R,R>,U>::ScalarProduct( { m_init , s } , ddu ) ) );
      da.Add( i , ddu );
      itr++;

    }

    answer[q] = m_M.Sum( a.IntervalSum( l , r ) , m_M.VirtualRSet<pair<R,R>,U>::ScalarProduct( { m_init , t } , da.IntervalSum( l , r ) ) );

  }

  return answer;

}
