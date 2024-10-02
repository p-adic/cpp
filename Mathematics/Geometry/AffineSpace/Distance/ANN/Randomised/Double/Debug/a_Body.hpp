// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/Double/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename Dist2 , typename INT>
vector<int> TwoDimensionalAllNearestNeighbourRandomisedDouble( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const int& success_count_bound )
{

  static bool init = true;

  if( init ){

    init = false;
    DERR( "TwoDimensionalAllNearestNeighbourRandomisedDoubleをデバッグモードで実行します。" );
    DERR( "" );
  }
  
  const int S_size = S.size() , T_size = T.size();
  vector<vector<int>> answer( S_size );

  if( S_size == 0 ){

    DERR( "TwoDimensionalAllNearestNeighbourRandomisedDoubleの入力Sが空でした。" );
    DERR( answer );
    DERR( "" );
    return {};

  }

  assert( T_size > 0 );
  vector<unordered_set<int>> nn( S_size , { 0 } );
  vector<pair<double,int>> line( T_size );
  int total_count = 0 , success_count = 0;

  while( success_count++ < success_count_bound ){

    total_count++;
    const double theta = GetRand( -1000 , 1000 ) * 0.00314;
    const double dx = cos( theta ) , dy = sin( theta );
    auto proj = [&]( const pair<INT,INT>& v ){ return v.first * dx + v.second * dy; };

    for( int j = 0 ; j < T_size ; j++ ){

      line[j] = { proj( T[j] ) , j };

    }

    sort( line.begin() , line.end() );

    for( int i = 0 ; i < S_size ; i++ ){

      const pair<double,int> proj_i{ proj( S[i] ) , 0 };
      int l = 0 , r = T_size;

      while( l + 1 < r ){

        int m = ( l + r ) >> 1;
        ( proj_i < line[m] ? r : l ) = m;

      }

      const int j_min = max( 0 , l - bucket_size );
      const int j_max = min( T_size - 1 , l + bucket_size );
      double d_opt = d( S[i] , T[*nn[i].begin()] );

      for( int j = l - 1 ; j >= j_min ; j-- ){

        const double d_temp = d( S[i] , T[line[j].second] );
        
        if( d_opt > d_temp ){

          success_count = 0;
          d_opt = d_temp;
          answer[i] = line[j].second;

        } else if( abs( line[j].first - proj_i.first ) > d_opt ){

          break;

        }

      }

      for( int j = l ; j <= j_max ; j++ ){

        const INT d_temp = d( S[i] , T[line[j].second] );
        
        if( d_opt > d_temp ){

          success_count = 0;
          d_opt = d_temp;
          answer[i] = line[j].second;

        } else if( abs( line[i].first - proj_i.first ) > d_opt ){

          break;

        }

      }

    }

  }
  
  DERRNS( "TwoDimensionalAllNearestNeighbourRandomisedDoubleのループ回数は" , total_count , "回でした。\n" );
  DERR( answer );
  DERR( "" );
  return answer;

}

template <typename Dist2 , typename INT>
vector<int> TwoDimensionalAllNearestNeighbourRandomisedDouble( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const double& time )
{

  static bool init = true;

  if( init ){

    init = false;
    DERR( "TwoDimensionalAllNearestNeighbourRandomisedDoubleをデバッグモードで実行します。" );
    DERR( "" );
  }
  
  const int S_size = S.size() , T_size = T.size();
  vector<vector<int>> answer( S_size );

  if( S_size == 0 ){

    DERR( "TwoDimensionalAllNearestNeighbourRandomisedDoubleの入力Sが空でした。" );
    DERR( answer );
    DERR( "" );
    return {};

  }

  assert( T_size > 0 );
  vector<int> answer( S_size );
  vector<pair<double,int>> line( T_size );
  int total_count = 0;
  chrono::system_clock::time_point watch = chrono::system_clock::now();

  while( static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 ) < time ){

    total_count++;
    const double theta = GetRand( -1000 , 1000 ) * 0.00314;
    const double dx = cos( theta ) , dy = sin( theta );
    auto proj = [&]( const pair<INT,INT>& v ){ return v.first * dx + v.second * dy; };

    for( int j = 0 ; j < T_size ; j++ ){

      line[j] = { proj( T[j] ) , j };

    }

    sort( line.begin() , line.end() );

    for( int i = 0 ; i < S_size ; i++ ){

      const pair<double,int> proj_i{ proj( S[i] ) , 0 };
      int l = 0 , r = T_size;

      while( l + 1 < r ){

        int m = ( l + r ) >> 1;
        ( proj_i < line[m] ? r : l ) = m;

      }

      const int j_min = max( 0 , l - bucket_size );
      const int j_max = min( T_size - 1 , l + bucket_size );
      double d_opt = d( S[i] , T[*nn[i].begin()] );

      for( int j = l - 1 ; j >= j_min ; j-- ){

        const double d_temp = d( S[i] , T[line[j].second] );
        
        if( d_opt > d_temp ){

          success_count = 0;
          d_opt = d_temp;
          answer[i] = line[j].second;

        } else if( abs( line[i].first - proj_i.first ) > d_opt ){

          break;

        }

      }

      for( int j = l ; j <= j_max ; j++ ){

        const INT d_temp = d( S[i] , T[line[j].second] );
        
        if( d_opt > d_temp ){

          success_count = 0;
          d_opt = d_temp;
          answer[i] = line[j].second;

        } else if( abs( line[j].first - proj_i.first ) > d_opt ){

          break;

        }

      }

    }

  }

  DERRNS( "TwoDimensionalAllNearestNeighbourRandomisedDoubleのループ回数は" , total_count , "回でした。\n" );
  DERR( answer );
  DERR( "" );
  return answer;

}
