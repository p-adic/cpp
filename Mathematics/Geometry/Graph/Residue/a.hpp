// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Residue/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/977606

template <typename T , typename E>
class ResidueGraph :
  public EdgeImplimentation<T,T,int,E>
{
  
public:
  inline ResidueGraph( const int& size , const T& dummy , E edge );
  inline T Enumeration( const int& i );
  template <typename F> inline ResidueGraph<T,F> GetGraph( F edge ) const;

private:
  inline int Enumeration_inv_Body( const T& t );

};
