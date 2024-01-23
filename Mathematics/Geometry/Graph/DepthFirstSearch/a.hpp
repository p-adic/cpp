// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/a.hpp

#pragma once
#include "../BreadthFirst/a.hpp"

// verify:
// https://yukicoder.me/submissions/945933（多点DFSによる全探索）
// https://yukicoder.me/submissions/945935（多点DFSによる連結成分取得）

template <typename GRAPH>
class DepthFirstSearch :
  public VirtualBreadthFirstSearch<GRAPH>
{

public:
  template <typename...Args> inline DepthFirstSearch( GRAPH& G , const Args&... args );

private:
  inline void Push( list<int>& next , const int& i );

};
