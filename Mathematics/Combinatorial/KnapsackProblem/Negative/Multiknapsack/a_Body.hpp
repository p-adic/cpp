// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Multiknapsack/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Subsetwise/a_Body.hpp"
#include "../a_Body.hpp"

template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeBoundedValueSumMultiknapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const vector<U2>& cost_sum_bound )
{

  const int K = cost_sum_bound.size();

  if( K == 0 ){

    return { M1.One() , M2.One() };
    
  } else if( K == 1 ){

    return AbstractNegativeBoundedValueSumKnapsack( move( M1 ) , move( M2 ) , value , value_sum_bound , cost , cost_sum_bound[0] );

  }
  
  const int N = value.size();
  assert( int( cost.size() ) == N && N < 30 );
  auto total_product = AbstractNegativeBitExhausiveSeachForKnapsack( M1 , M2 , N , value , cost );
  vector<vector<pair<U1,U2>>> product( K );

  for( int k = 0 ; k < K ; k++ ){
    
    product[k] = AbstractNegativeFastZetaTransformForKnapsack( N , M1.One() , total_product , value_sum_bound , cost_sum_bound[k] );

  }

  const int ambient = ( 1 << N ) - 1;
  vector<int> S( K , ambient );
  S[0] = 0;
  const int& S1 = S[1];
  auto [answer1,answer2] = product[0][ambient];

  while( S1 > 0 ){

    auto [temp1,temp2] = product[0][ambient ^ S1];

    for( int k = 1 ; k < K ; k++ ){

      auto& [v,w] = product[k][S[k-1] ^ S[k]];
      temp1 = M1.Product( move( temp1 ) , v );
      temp2 = M2.Product( move( temp2 ) , w );

    }

    value_sum_bound < temp1 || temp1 < answer1 || ( answer1 == temp1 && !( temp2 < answer2 ) ) ? answer2 : answer1 < temp1 ? ( answer1 = move( temp1 ) , answer2 = move( temp2 ) ) : answer2 = move( temp2 );

    int layer = K - 1;

    while( S[layer] == 0 ){

      layer--;

    }

    auto& s = --S[layer];

    for( int i = layer + 1 ; i < K ; i++ ){

      S[i] = s;

    }

  }

  return { move( answer1 ) , move( answer2 ) };

}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeBoundedValueSumMultiknapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const vector<INT2>& cost_sum_bound ) { return AbstractNegativeBoundedValueSumMultiknapsack( AdditiveMonoid<INT1>() , AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound ); }
