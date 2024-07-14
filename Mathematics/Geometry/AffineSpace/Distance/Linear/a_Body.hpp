// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linear/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
INT Distance( const INT& x0 , const set<INT>& x1 )
{

  assert( !x1.empty() );
  auto itr = x1.lower_bound( x0 );

  if( itr == x1.end() ){

    return x0 - *( x1.rbegin() );

  }

  INT answer = *itr - x0;
  return itr == x1.begin() ? answer : min( answer , x0 - *( --itr ) );

}

template <typename INT>
vector<set<pair<INT,int>>> Multipoint_Distance( const vector<INT>& x0 , const vector<INT>& x1 , const int& length )
{

  const int size0 = x0.size();
  const int size1 = x1.size();
  const int size = size0 + size1;
  vector<pair<INT,int>> x( size );

  for( int i = 0 ; i < size0 ; i++ ){

    x[i] = { x0[i] , i };
    
  }

  for( int i = 0 ; i < size1 ; i++ ){

    x[i + size0] = { x1[i] , i + size0 };
    
  }

  sort( x.begin() , x.end() );
  vector<set<pair<INT,int>>> answer( size0 );
  set<pair<INT,int>> temp{};
  INT d_init = x.back();

  for( int n = 0 ; n < size ; n++ ){

    auto& [xn,i] = x[n];

    if( i < size0 ){

      const INT dx = xn - d_init;
      auto& answer_i = answer[i];

      for( auto& d : temp ){

	answer_i.insert( { d.first + dx , d.second } );

      }

    } else {

      temp.insert( { ( d_init = min( d_init , xn ) ) - xn , i - size0 } );

      if( int( temp.size() ) > length ){

	temp.erase( --( temp.end() ) );

      }

    }

  }

  d_init = x.front();

  for( int n = size - 1 ; n >= 0 ; n-- ){

    auto& [xn,i] = x[n];

    if( i < size0 ){

      const INT dx = d_init - xn;
      auto& answer_i = answer[i];

      for( auto& d : temp ){

	answer_i.insert( { d.first + dx , d.second } );

	if( answer_i.size() > length ){

	  answer_i.erase( --( answer_i.end() ) );

	}

      }

    } else {

      temp.insert( { xn - ( d_init = max( d_init , xn ) ) , i - size0 } );

      if( int( temp.size() ) > length ){

	temp.erase( --( temp.end() ) );

      }

    }

  }

  return answer;

}
