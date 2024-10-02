// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/Double/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename Dist , typename INT>
vector<int> TwoDimensionalAllNearestNeighbourRandomisedDouble( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const int& success_count_bound )
{

  DEFINITION_OF_RANDOMISED_DOUBLE_ANN( int success_count = 0 , success_count++ < success_count_bound , success_count = 0 );

}

template <typename Dist , typename INT>
vector<int> TwoDimensionalAllNearestNeighbourRandomisedDouble( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const double& time )
{

  DEFINITION_OF_RANDOMISED_DOUBLE_ANN( chrono::system_clock::time_point watch = chrono::system_clock::now() , static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 ) < time , );

}
