// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/Multicost/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Costwise/a_Body.hpp"
#include "../../../../Loop/a_Body.hpp"
#include "../../../../../SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a_Body.hpp"

template <typename U , typename COMM_MONOID , typename INT , typename VALID> U AbstractNegativeValueMulticostKnapsack( COMM_MONOID M , const vector<vector<U>>& value , const U& exceptional , const vector<vector<INT>>& cost , const vector<INT>& cost_sum_bound , VALID valid )
{

  static_assert( is_invocable_r_v<vector<pair<INT,INT>>,VALID,const vector<INT>&> );
  const int D = cost_sum_bound.size();
  assert( D >= 2 );
  vector value_max( D , vector<U>() );

  for( int d = 0 ; d < D ; d++ ){

    value_max[d] = AbstractNegativeValueCostwiseKnapsack( M , value[d] , exceptional , cost[d] , cost_sum_bound[d] );

  }

  const U& one = M.One();
  const int D_minus = D - 1;
  IntervalMaxBIT bit{ one , value_max[D_minus] };
  vector<INT> index( D_minus , 0 ) , lower_bound = index;

  U answer = one;
  bool b = true;

  while( b ){

    U temp = one;

    for( int d = 0 ; d < D_minus ; d++ ){

      value_max[d][index[d]] == exceptional ? temp = exceptional : temp = M.Product( move( temp ) , value_max[d][index[d]] );

    }

    if( temp != exceptional ){
      
      for( auto& [l,r] : valid( index ) ){

	assert( l <= r );
	answer = max( answer , M.Product( bit.IntervalMax( l , r ) , temp ) );

      }

    }

    b = NextLoopEq( D_minus , lower_bound , cost_sum_bound , index );
    
  }

  return answer;

}

template <typename U , typename COMM_MONOID , typename INT1 , typename INT2 , typename VALID> U AbstractNegativeValueMulticostKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT1>& coord , const vector<INT2>& cost , const vector<INT2>& cost_sum_bound , VALID valid )
{

  const int N = value.size();
  const INT1 D = cost_sum_bound.size();
  assert( int( coord.size() ) == N && int( cost.size() ) == N );
  vector value_copy( D , vector<U>() );
  vector cost_copy( D , vector<INT2>() );

  for( int i = 0 ; i < N ; i++ ){

    auto& coord_i = coord[i];
    assert( 0 <= coord_i && coord_i < D );
    value_copy[coord_i].push_back( value[i] );
    cost_copy[coord_i].push_back( cost[i] );

  }

  return AbstractNegativeValueMulticostKnapsack( move( M ) , value_copy , exceptional , cost_copy , cost_sum_bound , move( valid ) );

}

template <typename INT1 , typename INT2 , typename INT3 , typename VALID> inline INT1 NegativeValueMulticostKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& coord , const vector<INT3>& cost , const vector<INT3>& cost_sum_bound , VALID valid ) { return AbstractNegativeValueMulticostKnapsack( AdditiveMonoid<INT1>() , value , exceptional , coord , cost , cost_sum_bound , move( valid ) ); }
