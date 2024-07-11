// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

#include "a_Alias.hpp"

template <typename E>
class GridGraph :
  public EnumerationGraph<T2<int>,T2<int>(&)(const int&),int(&)(const T2<int>&),E>
{

public:
  inline GridGraph( E e );

};

int H , W , H_minus , W_minus;
ll HW;
vector<string> grid;
char walkable = '.' , unwalkable = '#';

inline T2<int> EnumHW( const int& v );
inline int EnumHW_inv( const T2<int>& ij );

vector<T2<int>> EdgeOnGrid( const T2<int>& v );
vector<pair<T2<int>,ll>> WEdgeOnGrid( const T2<int>& v );

inline void SetWallStringOnGrid( const int& i , vector<string>& S );

const string direction = "URDL";

inline int DirectionNumberOnGrid( const int& i , const int& j , const int& k , const int& h );
inline int DirectionNumberOnGrid( const T2<int>& v , const T2<int>& w );
inline int DirectionNumberOnGrid( const int& v , const int& w );
inline int ReverseDirectionNumberOnGrid( const int& n );

