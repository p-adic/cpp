// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../../../Utility/StdStream/a_Body.hpp"

inline T2<int> EnumHW( const int& v ) { return { v / W , v % W }; }
inline int EnumHW_inv( const T2<int>& ij ) { auto& [i,j] = ij; return i * W + j; }

template <typename E> inline GridGraph<E>::GridGraph( E e ) : EnumerationGraph<T2<int>,T2<int>(&)(const int&),int(&)(const T2<int>&),E>( HW , EnumHW , EnumHW_inv , move( e ) ) { assert( HW >> 31 == 0 && H * W == HW ); }

vector<T2<int>> EdgeOnGrid( const T2<int>& v )
{

  vector<T2<int>> answer{};
  auto& [i,j] = v;

  if( grid[i][j] == walkable ){

    if( i > 0 && grid[i-1][j] == walkable ){

      answer.push_back( {i-1,j} );

    }

    if( i+1 < H && grid[i+1][j] == walkable ){

      answer.push_back( {i+1,j} );

    }

    if( j > 0 && grid[i][j-1] == walkable ){

      answer.push_back( {i,j-1} );

    }

    if( j+1 < W && grid[i][j+1] == walkable ){

      answer.push_back( {i,j+1} );

    }

  }

  return answer;

}

vector<pair<T2<int>,ll>> WEdgeOnGrid( const T2<int>& v ){

  vector<pair<T2<int>,ll>> answer{};
  auto& [i,j] = v;

  if( grid[i][j] == walkable ){
  
    if( i>0 && grid[i-1][j] == walkable ){

      answer.push_back( {{i-1,j},1} );

    }

    if( i+1 < H && grid[i+1][j] == walkable ){

      answer.push_back( {{i+1,j},1} );

    }

    if( j>0 && grid[i][j-1] == walkable ){

      answer.push_back( {{i,j-1},1} );

    }

    if( j+1 < W && grid[i][j+1] == walkable ){

      answer.push_back( {{i,j+1},1} );

    }

  }
  
  return answer;

}

inline void SetWallStringOnGrid(){ grid.resize( H ); for( int i = 0 ; i < H ; i++ ){ SET( grid[i] ); assert( int( grid[i].size() ) == W ); } }

inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h ) { return i < k ? 2 : i > k ? 0 : j < h ? 1 : ( assert( j > h ) , 3 ); }
inline int DirectionNumberOnGrid( const T2<int>& v , const T2<int>& w ) { auto& [i,j] = v; auto& [k,h] = w; return DirectionNumberOnGrid( i , j , k , h ); }
inline int DirectionNumberOnGrid( const int& v , const int& w ) { return DirectionNumberOnGrid( EnumHW( v ) , EnumHW( w ) ); }
inline int ReverseDirectionNumberOnGrid( const int& n ) { assert( 0 <= n && n<4 ); return n ^ 2; }

