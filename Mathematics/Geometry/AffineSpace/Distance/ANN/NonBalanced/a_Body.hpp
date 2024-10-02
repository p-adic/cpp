// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/NonBalanced/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename Dist2 , typename INT>
vector<vector<int>> TwoDimensionalAllNearestNeighbourNonBalanced( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T )
{

  const int S_size = S.size();

  if( S_size == 0 ){

    return {};

  }

  const int T_size = T.size();
  assert( T_size > 0 );

  if( T_size == 1 ){

    return vector( S_size , vector<int>{ 0 } );

  }
  
  auto [x_min,y_min] = T[0];
  auto [x_max,y_max] = T[0];

  for( int j = 1 ; j < T_size ; j++ ){

    auto& [x,y] = T[j];
    x_min = min( x_min , x ); x_max = max( x , x_max ); 
    y_min = min( y_min , y ); y_max = max( y , y_max );

  }

  using Block = tuple<INT,INT,INT,INT,vector<int>>;
  vector<vector<pair<bool,int>>> neighbours( S_size , { { true , 0 } } );
  vector<bool> updatable( S_size , true );
  vector<Block> divisible_block = { { x_min , x_max , y_min , y_max , vector<int>( T_size ) } };

  for( int j = 0 ; j < T_size ; j++ ){

    get<4>( divisible_block[0] )[j] = j;

  }

  vector<Block> indivisible_block = {};

  // 最悪O(T_size)回のループ、良いケースではO(log T_size)回のループ
  while( !divisible_block.empty() ){

    const int divisible_block_size = divisible_block.size();
    vector<Block> next_divisible_block{};
    vector<vector<pair<bool,int>>> Partition( divisible_block_size );

    // 分割可能ブロックの分割の計算
    // 合計O(T_size)
    for( int num = 0 ; num < divisible_block_size ; num++ ){

      auto& [x_min,x_max,y_min,y_max,t] = divisible_block[num];
      const INT x_sum = x_min + x_max , x_mid = ( x_sum < 0 ? x_sum - 1 : x_sum ) / 2;
      const INT y_sum = y_min + y_max , y_mid = ( y_sum < 0 ? y_sum - 1 : y_sum ) / 2;
      Block block_sub[2][2]{};

      for( auto& j : t ){

        auto& [x,y] = T[j];
        auto& [x_min_sub,x_max_sub,y_min_sub,y_max_sub,t_sub] = block_sub[x <= x_mid ? 0 : 1][y <= y_mid ? 0 : 1];

        if( t_sub.empty() ){

          x_min_sub = x_max_sub = x; y_min_sub = y_max_sub = y;

        } else {

          x_min_sub = min( x_min_sub , x ); x_max_sub = max( x , x_max_sub );
          y_min_sub = min( y_min_sub , y ); y_max_sub = max( y , y_max_sub );

        }

        t_sub.push_back( j );
      
      }

      for( int num_x = 0 ; num_x <= 1 ; num_x++ ){

        for( int num_y = 0 ; num_y <= 1 ; num_y++ ){

          Block& block_xy = block_sub[num_x][num_y];
          const int t_size = get<4>( block_xy ).size();

          if( t_size != 0 ){

            if( t_size == 1 ){

              Partition[num].push_back( { false , indivisible_block.size() } );
              indivisible_block.push_back( move( block_xy ) );

            } else {

              Partition[num].push_back( { true , next_divisible_block.size() } );
              next_divisible_block.push_back( move( block_xy ) );

            }

          }

        }

      }

    }

    divisible_block = move( next_divisible_block );

    // 近傍の再計算
    // 合計O(近傍数総和)
    for( int i = 0 ; i < S_size ; i++ ){

      if( !updatable[i] ){

        continue;

      }
        
      updatable[i] = false;
      vector<pair<bool,int>> neighbour_partition{};

      for( auto& coord : neighbours[i] ){

        auto& [divisible,num] = coord;
          
        if( divisible ){

          for( auto& coord_sub : Partition[num] ){

            neighbour_partition.push_back( coord_sub );

          }

        } else {

          neighbour_partition.push_back( coord );

        }

      }

      auto& [x,y] = S[i];
        
      auto d2_max = [&]( const pair<bool,int>& coord ){

        auto& [divisible,num] = coord;
        auto& [x_min,x_max,y_min,y_max,t] = ( divisible ? divisible_block : indivisible_block )[num];
        return d2( { 0 , 0 } , { max( abs( x - x_min ) , abs( x_max - x ) ) , max( abs( y - y_min ) , abs( y_max - y ) ) } );

      };
        
      auto d2_min = [&]( const pair<bool,int>& coord ){

        auto& [divisible,num] = coord;
        auto& [x_min,x_max,y_min,y_max,t] = ( divisible ? divisible_block : indivisible_block )[num];
        return d2( S[i] , { x < x_min ? x_min : x_max < x ? x_max : x , y < y_min ? y_min : y_max < y ? y_max : y } );

      };

      const int neighbour_partition_size = neighbour_partition.size();
      assert( neighbour_partition_size > 0 );
        
      decltype( d2({0,0},{0,0}) ) d2_max_min = d2_max( neighbour_partition[0] );

      for( int num = 1 ; num < neighbour_partition_size ; num++ ){

        d2_max_min = min( d2_max_min , d2_max( neighbour_partition[num] ) );

      }

      neighbours[i].clear();

      for( int num = 0 ; num < neighbour_partition_size ; num++ ){

        if( d2_min( neighbour_partition[num] ) <= d2_max_min ){

          updatable[i] = updatable[i] || neighbour_partition[num].first;
          neighbours[i].push_back( move( neighbour_partition[num] ) );

        }
      
      }

    }

  }

  vector<vector<int>> answer( S_size );
  // 最近点の計算
  // 合計O(最近接数の総和)
  for( int i = 0 ; i < S_size ; i++ ){

    for( auto& [divisible,num] : neighbours[i] ){

      assert( !divisible );
      auto& [x_min,x_max,y_min,y_max,t] = indivisible_block[num];
      assert( t.size() == 1 && x_min == x_max && x_min == T[t[0]].first && y_min == y_max && y_min == T[t[0]].second );
      answer[i].push_back( t[0] );

    }

  }

  return answer;

}
