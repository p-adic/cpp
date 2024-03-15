// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/YoungDiagram/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2 , template <typename...> typename V> void SetCountingYoundDiagram( INT1& answer , const V<INT2>& type )
{
  
  answer = 1;

  if( ! type.empty() ){

    auto begin = type.begin() , itr = begin , end = type.end();
    vector<int> transpose_type( *itr , 1 );
    int size = *itr;

    while( ++itr != end ){

      for( int i = *itr - 1 ; i >= 0 ; i-- ){

	transpose_type[i]++;

      }

      size += *itr;
      
    }

    answer *= INT1::Factorial( size );
    itr = begin;

    while( itr != end ){

      for( int i = *itr - 1 ; i >= 0 ; i-- ){

	answer *= INT1::Inverse( *itr - i + transpose_type[i] - 1 );

      }
      
    }

  }

  return answer;
  
}
