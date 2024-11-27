// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L1/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline INT L1( const INT& x , const INT& y ) { return abs( x ) + abs( y ); }
template <typename INT> inline INT L1( const pair<INT,INT>& v ) { return L1( v.first , v.second ); }

template <typename INT> inline INT L1_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 ) { return L1( x0 - x1 , y0 - y1 ); }
template <typename INT> inline INT L1_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { return L1( v0.first - v1.first , v0.second - v1.second ); }

template <typename INT> inline pair<INT,INT> L1_to_Linfty( const INT& x , const INT& y ) { return { x + y , x - y }; }
template <typename INT> inline pair<INT,INT> L1_to_Linfty( const pair<INT,INT>& v ) { return L1_to_Linfty( v.first , v.second ); }
template <typename INT> inline pair<INT,INT> Linfty_to_L1( const INT& x , const INT& y ) { assert( ( x & 1 ) == ( y & 1 ) ); return { ( x + y ) >> 1 , ( x - y ) >> 1 }; }
template <typename INT> inline pair<INT,INT> Linfty_to_L1( const pair<INT,INT>& v ) { return Linfty_to_L1( v.first , v.second ); }

// x軸と平行な直線上の点との距離の最小値の多点評価（O(#x0 log #x0 + #v1 log #v1)）
template <typename INT>
vector<set<pair<INT,int>>> Multipoint_L1_Distance( const vector<INT>& x0 , const INT& y0 , const vector<pair<INT,INT>>& v1 , const int& length )
{

  const int size0 = x0.size();
  const int size1 = v1.size();
  const int size = size0 + size1;
  vector<pair<INT,int>> x( size );

  for( int i = 0 ; i < size0 ; i++ ){

    x[i] = { x0[i] , i };
    
  }

  for( int i = 0 ; i < size1 ; i++ ){

    x[i + size0] = { v1[i].first , i + size0 };
    
  }

  sort( x.begin() , x.end() );
  vector<set<pair<INT,int>>> answer( size0 );
  set<pair<INT,int>> temp{};
  INT d_init = x.back().first;

  for( int n = 0 ; n < size ; n++ ){

    auto& [xn,i] = x[n];

    if( i < size0 ){

      const INT dx = xn - d_init;
      auto& answer_i = answer[i];

      for( auto& d : temp ){

	answer_i.insert( { d.first + dx , d.second } );

      }

    } else {

      temp.insert( { abs( v1[i - size0].second - y0 ) - ( xn - ( d_init = min( d_init , xn ) ) ) , i - size0 } );

      if( int( temp.size() ) > length ){

	temp.erase( --( temp.end() ) );

      }

    }

  }

  temp.clear();
  d_init = x.front().first;

  for( int n = size - 1 ; n >= 0 ; n-- ){

    auto& [xn,i] = x[n];

    if( i < size0 ){

      const INT dx = d_init - xn;
      auto& answer_i = answer[i];

      for( auto& d : temp ){

	answer_i.insert( { d.first + dx , d.second } );

	if( int( answer_i.size() ) > length ){

	  answer_i.erase( --( answer_i.end() ) );

	}

      }

    } else {

      temp.insert( { abs( v1[i - size0].second - y0 ) - ( ( d_init = max( d_init , xn ) ) - xn ) , i - size0 } );

      if( int( temp.size() ) > length ){

	temp.erase( --( temp.end() ) );

      }

    }

  }

  return answer;

}

template <typename INT> inline vector<set<pair<INT,int>>> Multipoint_L1_Distance( const INT& x0 , const vector<INT>& y0 , vector<pair<INT,INT>> v1 , const int& length ) { for( auto& [x,y] : v1 ){ swap( x , y ); } return Multipoint_L1_Distance( y0 , x0 , v1 , length ); }
