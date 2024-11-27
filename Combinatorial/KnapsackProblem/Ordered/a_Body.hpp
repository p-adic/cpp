// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Ordered/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2 >
pair<U1,U2> AbstractOrderedUnstableCostKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const vector<U2>& cost0 , const vector<U2>& cost1 , const vector<bool>& chosen_zero , const vector<U2>& cost_bound )
{

  const int N = value.size();
  assert( int( cost0.size() ) == N );
  assert( int( cost1.size() ) == N );
  const int K = cost_bound.size();
  assert( int( chosen_zero.size() ) == K && K<= N );
  vector<pair<U2,int>> item0( N );
  vector<pair<U2,int>> item1( N );

  for( int i = 0 ; i < N ; i++ ){

    item0[i] = { cost0[i] , i };
    item1[i] = { cost1[i] , i };

  }

  vector<pair<U2,int>> choice0;
  vector<pair<U2,int>> choice1;

  for( int k = 0 ; k < K ; k++ ){

    ( chosen_zero[k] ? choice0 : choice1 ).push_back( { cost_bound[k] , k } );

  }

  sort( item0.begin() , item0.end() );
  sort( item1.begin() , item1.end() );
  sort( choice0.begin() , choice0.end() );
  sort( choice1.begin() , choice1.end() );
  set<tuple<U1,U2,int>> rest{};
  pair<U1,U2> answer = { M1.One() , M2.One() };

  for( int choice_type = 0 ; choice_type < 2 ; choice_type++ ){
    
    int j = 0;
    auto& item = choice_type == 0 ? item0 : item1;
    auto& choice = choice_type == 0 ? choice0 : choice1;

    for( auto& [cost_bound_k,k] : choice ){

      while( j < N && item[j].first <= cost_bound_k ){

	auto& i = item[j].second;
	// choice_type‚É‚æ‚ç‚¸cost1‚ð—p‚¢‚éB
	rest.insert( { value_i , cost1[i] , i } );
	j++;

      }

      if( rest.empty() ){

	return answer;

      }

      auto rbegin = rest.rbegin();
      auto& [v,c,i] = *rbegin;
      answer = { M1.Product( move( answer.first ) , v ) , M2.Product( move( answer.second ) , ( choice_type == 0 ? cost0 : cost1 )[i] ) };
      rest.erase( rbegin );

    }

  }

  return answer;

}

template <typename INT1 , typename INT2> inline INT2 OrderedUnstableCostKnapsack( const vector<INT1>& value , const vector<INT2>& cost0 , const vector<INT2>& cost1 , const vector<bool>& chosen_zero , const vector<INT2>& cost_bound ) { return AbstractOrderedUnstableCostKnapsack( AdditiveMoonid<INT1>() , AdditiveMonoid<INT2>() , value , cost0 , cost1 , chosen_zero , cost_bound ); }

template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2 >
pair<U1,U2> AbstractOrderedKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const vector<U2>& cost , const vector<U2>& cost_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  const int K = cost_bound.size();
  vector<pair<U2,int>> item( N );

  for( int i = 0 ; i < N ; i++ ){

    item[i] = { cost[i] , i };

  }

  vector<pair<U2,int>> choice( K );

  for( int k = 0 ; k < K ; k++ ){

    choice[k] = { cost_bound[k] , k };

  }

  sort( item.begin() , item.end() );
  sort( choice.begin() , choice.end() );
  set<tuple<U1,int>> rest{};
  pair<U1,U2> answer = { M1.One() , M2.One() };
  int j = 0;

  for( auto& [cost_bound_k,k] : choice ){

    while( j < N && item[j].first <= cost_bound_k ){

      auto& i = item[j].second;
      rest.insert( { value_i , i } );
      j++;

    }

    if( rest.empty() ){

      return answer;

    }

    auto rbegin = rest.rbegin();
    auto& [v,i] = *rbegin;
    answer = { M1.Product( move( answer.first ) , v ) , M2.Product( move( answer ) , cost[i] ) };
    rest.erase( rbegin );

  }

  return answer;

}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> OrderedKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const vector<INT2>& cost_bound ) { return AbstractOrderedKnapsack( AdditiveMonoid<INT1>() , AdditiveMonoid<INT2>() , value , cost , cost_bound ); }


