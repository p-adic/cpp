// c:/Users/user/Documents/Programming/Utility/Vector/Query/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename Query>
vector<pair<const Query*,int>> QuerySort( const vector<Query>& query , const bool& sorted )
{

  using SQuery = pair<const Query*,int>;
  const int Q = query.size();
  vector<SQuery> answer( Q );

  for( int q = 0 ; q < Q ; q++ ){

    answer[q] = { &( query[q] ) , q };

  }

  static auto comp = []( const SQuery& q0 , const SQuery& q1 ){ return *( q0.first ) < *( q1.first ) ? true : q0.second < q1.second && *( q0.first ) == *( q1.first ); };

  if( !sorted ){

    sort( answer.begin() , answer.end() , comp );

  }

  return answer;

}
