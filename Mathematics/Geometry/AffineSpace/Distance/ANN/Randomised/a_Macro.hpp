// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/a_Macro.hpp

#pragma once
#define DEFINITION_OF_RANDOMISED_ANN( SET_COUNT , CHECK_COUNT , RESET ) \
  const int S_size = S.size() , T_size = T.size();                      \
                                                                        \
  if( S_size == 0 ){                                                    \
                                                                        \
    return {};                                                          \
                                                                        \
  }                                                                     \
                                                                        \
  assert( T_size > 0 );                                                 \
  vector<unordered_set<int>> nn( S_size , { 0 } );                      \
  vector<pair<INT,int>> line( T_size );                                 \
  SET_COUNT;                                                            \
                                                                        \
  while( CHECK_COUNT ){                                                 \
                                                                        \
    const double theta = GetRand( -1000 , 1000 ) * 0.00314;             \
    const INT dx = 1000 * cos( theta ) , dy = 1000 * sin( theta );      \
    auto proj = [&]( const pair<INT,INT>& v ){ return v.first * dx + v.second * dy; }; \
                                                                        \
    for( int j = 0 ; j < T_size ; j++ ){                                \
                                                                        \
      line[j] = { proj( T[j] ) , j };                                   \
                                                                        \
    }                                                                   \
                                                                        \
    sort( line.begin() , line.end() );                                  \
                                                                        \
    for( int i = 0 ; i < S_size ; i++ ){                                \
                                                                        \
      const pair<INT,int> proj_i{ proj( S[i] ) , 0 };                   \
      int l = 0 , r = T_size;                                           \
                                                                        \
      while( l + 1 < r ){                                               \
                                                                        \
        int m = ( l + r ) >> 1;                                         \
        ( proj_i < line[m] ? r : l ) = m;                               \
                                                                        \
      }                                                                 \
                                                                        \
      const int j_min = max( 0 , l - bucket_size );                     \
      const int j_max = min( T_size - 1 , l + bucket_size );            \
      INT d_opt = d2( S[i] , T[*nn[i].begin()] );                       \
                                                                        \
      for( int j = j_min ; j <= j_max ; j++ ){                          \
                                                                        \
        const INT d_temp = d2( S[i] , T[line[j].second] );              \
                                                                        \
        if( d_opt > d_temp ){                                           \
                                                                        \
          RESET;                                                        \
          d_opt = d_temp;                                               \
          nn[i] = { line[j].second };                                   \
                                                                        \
        } else if( d_opt == d_temp && nn[i].count( line[j].second ) == 0 ){ \
                                                                        \
          RESET;                                                        \
          nn[i].insert( line[j].second );                               \
                                                                        \
        }                                                               \
                                                                        \
      }                                                                 \
                                                                        \
    }                                                                   \
                                                                        \
  }                                                                     \
                                                                        \
  vector<vector<int>> answer( S_size );                                 \
                                                                        \
  for( int i = 0 ; i < S_size ; i++ ){                                  \
                                                                        \
    answer.reserve( nn[i].size() );                                     \
                                                                        \
    for( auto& j : nn[i] ){                                             \
                                                                        \
      answer[i].push_back( j );                                         \
                                                                        \
    }                                                                   \
                                                                        \
  }                                                                     \
                                                                        \
  return answer                                                         \


