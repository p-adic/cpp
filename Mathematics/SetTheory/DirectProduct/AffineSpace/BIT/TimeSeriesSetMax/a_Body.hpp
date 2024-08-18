// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TimeSeriesSetMax/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"

#include "../a_Body.hpp"
#include "../../../../../../Utility/Vector/Query/a_Body.hpp"

template <typename R , typename U , typename Z_MODULE> inline AbstractTimeSeriesSetMaxBIT<R,U,Z_MODULE>::AbstractTimeSeriesSetMaxBIT( Z_MODULE M , const R& dummy , const int& N ) : m_M( move( M ) ) , m_N( N ) , m_a( N , m_M.Zero() ) , m_event() {}
template <typename R , typename U , typename Z_MODULE> inline AbstractTimeSeriesSetMaxBIT<R,U,Z_MODULE>::AbstractTimeSeriesSetMaxBIT( Z_MODULE M , const R& dummy , vector<U> a , const vector<pair<R,U>>& event ) : m_M( move( M ) ) , m_N( a.size() ) , m_a( move( a ) ) , m_event() { for( auto& [t,u] : event ){ Set( t , u ); } }

template <typename U> inline TimeSeriesSetMaxBIT<U>::TimeSeriesSetMaxBIT( const int& N ) : AbstractTimeSeriesSetMaxBIT<ll,U,Module<ll,U>>( Module<ll,U>() , 0 , N ) {}
template <typename U> template <typename...Args> inline TimeSeriesSetMaxBIT<U>::TimeSeriesSetMaxBIT( vector<U> a , Args&&... args ) : AbstractTimeSeriesSetMaxBIT<ll,U,Module<ll,U>>( Module<ll,U>() , 0 , move( a ) , forward<Args>( args )... ) {}
  
template <typename R , typename U , typename Z_MODULE> template <typename...Args> inline void AbstractTimeSeriesSetMaxBIT<R,U,Z_MODULE>::Initialise( Args&&... args ) { decltype( *this ) temp{ m_M , move( args )... }; m_N = temp.m_N; m_a = move( temp.m_a ); m_event = move( temp.m_event ); }

template <typename R , typename U , typename Z_MODULE> inline void AbstractTimeSeriesSetMaxBIT<R,U,Z_MODULE>::Set( const R& t , const U& u ) { const bool b = m_event.count( t ) == 1; auto& m_event_t = m_event[t]; m_event_t = b ? max( m_event_t , u ) : u; }

template <typename R , typename U , typename Z_MODULE> template <typename INT , typename ABSTRACT_BIT>
vector<U> AbstractTimeSeriesSetMaxBIT<R,U,Z_MODULE>::IntervalSum( const vector<tuple<R,INT,INT>>& query , const bool& sorted )
{

  if( m_N == 0 ){

    assert( query.size() == 0 );
    return {};

  }

  auto query_sorted = QuerySort( query , sorted );
  set<pair<U,int>> a_sorted{};

  for( int i = 0 ; i < m_N ; i++ ){

    a_sorted.insert( { m_a[i] , i } );

  }

  const U& zero = m_M.Zero();
  ABSTRACT_BIT a{ m_M , m_a };
  BIT<int> b{ m_N };
  auto itr = m_event.begin() , end = m_event.end();
  vector<U> answer( query.size() );
  U temp = a_sorted.begin()->first;

  for( auto& [p,q] : query_sorted ){

    auto& [t,l,r] = *p;

    while( itr != end && !( t < itr->first ) ){

      temp = max( temp , itr->second );
      itr++;

    }

    while( !a_sorted.empty() ){

      auto itr_a = a_sorted.begin();
      auto& [ai,i] = *itr_a;

      if( ai < temp ){

	a.Set( i , zero );
	b.Add( i , 1 );
	a_sorted.erase( itr_a );

      } else {

	break;

      }

    }

    answer[q] = m_M.Sum( a.IntervalSum( l , r ) , m_M.ScalarProduct( b.IntervalSum( l , r ) , temp ) );

  }

  return answer;

}


template <typename U , typename Z_MODULE , typename INT , typename ABSTRACT_BIT>
vector<U> AbstractMaxIntervalSum( Z_MODULE M , vector<U> a , const vector<tuple<U,INT,INT>>& query , const bool& sorted )
{

  AbstractTimeSeriesSetMaxBIT bit{ move( M ) , 0 , move( a ) };
  auto query_sorted = QuerySort( query , sorted );
  const int Q = query.size();
  vector<tuple<int,int,int>> query_time( Q );

  for( int q = 0 ; q < Q ; q++ ){

    auto& [u,l,r] = *( query_sorted[q].first );
    bit.Set( q , u );
    query_time[q] = { q , l , r };

  }

  auto answer_sorted = bit.template IntervalSum<int,ABSTRACT_BIT>( query_time , true );
  vector<U> answer( Q );
  
  for( int q = 0 ; q < Q ; q++ ){

    answer[query_sorted[q].second] = answer_sorted[q];

  }

  return answer;

}

template <typename U , typename INT , typename ABSTRACT_BIT> inline vector<U> MaxIntervalSum( vector<U> a , const vector<tuple<U,INT,INT>>& query , const bool& sorted ) { return AbstractMaxIntervalSum<U,Module<int,U>,INT,ABSTRACT_BIT>( Module<int,U>() , move( a ) , query , sorted ); }
