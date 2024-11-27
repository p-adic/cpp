// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/DepthFirstSearch/a.hpp

#pragma once
#include "../BreadthFirstSearch/a.hpp"

// verify:
// https://yukicoder.me/submissions/955873（一始点のShiftによる多点DFSでの全探索）
// https://yukicoder.me/submissions/953239（SetConnectedComponent）
// https://yukicoder.me/submissions/953242（TopologicalSort）

template <typename T , typename GRAPH>
class DepthFirstSearch :
  public VirtualBreadthFirstSearch<T,GRAPH>
{
  
public:
  // ArgsはTかlist<T>
  template <typename...Args> inline DepthFirstSearch( GRAPH& G , const T& not_found , Args&&... args );

private:
  inline void Push( list<T>& next , const T& t );

};
