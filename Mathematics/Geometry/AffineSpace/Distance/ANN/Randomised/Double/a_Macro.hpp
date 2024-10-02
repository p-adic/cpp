// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/Double/a_Macro.hpp

#pragma once

#define DEFINITION_OF_RANDOMISED_DOUBLE_ANN_BODY( RESET )       \
  const double d_temp = d( S[i] , T[line[j].second] );          \
                                                                \
  if( d_opt > d_temp ){                                         \
                                                                \
    RESET;                                                      \
    d_opt = d_temp;                                             \
    answer[i] = line[j].second;                                 \
                                                                \
  } else if( abs( line[j].first - proj_i.first ) > d_opt ){     \
                                                                \
    break;                                                      \
                                                                \
  }                                                             \

#define DEFINITION_OF_RANDOMISED_DOUBLE_ANN( SET_COUNT , CHECK_COUNT , RESET ) \
  const int S_size = S.size() , T_size = T.size();                      \
                                                                        \
  if( S_size == 0 ){                                                    \
                                                                        \
    return {};                                                          \
                                                                        \
  }                                                                     \
                                                                        \
  assert( T_size > 0 );                                                 \
  vector<int> answer( S_size );                                         \
  vector<pair<double,int>> line( T_size );                              \
  SET_COUNT;                                                            \
                                                                        \
  while( CHECK_COUNT ){                                                 \
                                                                        \
    const double theta = GetRand( -1000 , 1000 ) * 0.00314;             \
    const double dx = cos( theta ) , dy = sin( theta );                 \
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
      const pair<double,int> proj_i{ proj( S[i] ) , 0 };                \
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
      double d_opt = d( S[i] , T[answer[i]] );                          \
                                                                        \
      for( int j = l - 1 ; j >= j_min ; j-- ){                          \
                                                                        \
        DEFINITION_OF_RANDOMISED_DOUBLE_ANN_BODY( RESET );              \
                                                                        \
      }                                                                 \
                                                                        \
      for( int j = l ; j <= j_max ; j++ ){                              \
                                                                        \
        DEFINITION_OF_RANDOMISED_DOUBLE_ANN_BODY( RESET );              \
                                                                        \
      }                                                                 \
                                                                        \
    }                                                                   \
                                                                        \
  }                                                                     \
                                                                        \
  return answer                                                         \


