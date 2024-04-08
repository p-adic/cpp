// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Subsetwise/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
vector<pair<U1,U2>> AbstractNegativeBitExhausiveSeachForKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const int& N , const vector<U1>& value , const vector<U2>& cost )
{

  int power = 1 << N;
  vector<pair<U1,U2>> product( power , { M1.One() , M2.One() } );

  for( int i = 0 ; i < N ; i++ ){

    int p = 1 << i;

    for( int j = p ; j < power ; ( ++j ) |= p ){

      auto& [v,w] = product[j ^ p];
      product[j] = { M1.Product( v , value[i] ) , M2.Product( w , cost[i] ) };

    }

  }

  return product;

};

template <typename U1 , typename U2>
vector<pair<U1,U2>> AbstractNegativeFastZetaTransformForKnapsack( const int& N , const U1& one1 , vector<pair<U1,U2>> product , const U1& value_sum_bound , const U2& cost_sum_bound )
{

  for( auto& [v,w] : product ){

    value_sum_bound < v || cost_sum_bound < w ? v = one1 : v;

  }

  const int power = 1 << N;
  int p = 1;

  for( int i = 0 ; i < N ; i++ , p <<= 1 ){

    int j = p;

    while( j < power ){

      auto& [v_j,w_j] = product[j];
      auto& [v_j_prev,w_j_prev] = product[j ^ p];
      v_j < v_j_prev ? ( v_j = v_j_prev , w_j = w_j_prev ) : v_j == v_j_prev && w_j_prev < w_j ? w_j = w_j_prev : w_j;
      ( ++j ) |= p;
      
    }

  }

  return product;

}

template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
vector<pair<U1,U2>> AbstractNegativeBoundedValueSumSubsetwiseKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N && N < 30 );
  const U1 one1 = M1.One();
  auto product = AbstractNegativeBitExhausiveSeachForKnapsack( move( M1 ) , move( M2 ) , N , value , cost );
  return AbstractNegativeFastZetaTransformForKnapsack( N , one1 , move( product ) , value_sum_bound , cost_sum_bound );

}

template <typename INT1 , typename INT2> inline vector<pair<INT1,INT2>> NegativeBoundedValueSumSubsetwiseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractNegativeBoundedValueSumSubsetwiseKnapsack( AdditiveMonoid<INT1>() , AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound ); }

#include "../../ValueSumBound/a_Body.hpp"
