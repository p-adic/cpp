// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Double/Grid/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Linear/a.hpp"
#include "../../../Grid/a.hpp"

// verify:
// https://yukicoder.me/submissions/982907（direction = 1）
// https://yukicoder.me/submissions/982914（direction = 2）

template <typename E>
class AcyclicGridGraph :
  public AcyclicDoubleGraph<int,LinearGraph,int,decldecay_t(declval<E>()({0,0}).front().second),GridGraph<E>,vector<int>(&)(const int&)>
{

public:
  // 1: 0->1->...->H-1
  // 2: 0<-1<-...<-H-1
  inline AcyclicGridGraph( E e , const int& direction = 1 );
  
};

inline vector<int> GridVertex( const int& i );
