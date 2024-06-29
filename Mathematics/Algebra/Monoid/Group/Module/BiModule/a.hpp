// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a.hpp

#pragma once
#include "../../a.hpp"

template <typename L , typename R , typename U>
class VirtualBiModule :
  virtual public UnderlyingSet<U>
{

public:
  virtual U LAction( const L& l , U u ) = 0;
  virtual U RAction( U u , const R& r ) = 0;
  inline U ScalarProduct( const L& l , U u );
  inline U Power( U u , const R& r );

};

template <typename L , typename R , typename U , typename O_U_L , typename O_U_R , typename GROUP>
class AbstractBiModule :
  public VirtualBiModule<L,R,U> ,
  public GROUP
{

private:
  O_U_L m_o_U_L;
  O_U_R m_o_U_R;

public:
  // 型推論のために余計な引数dummyが必要
  inline AbstractBiModule( const L& dummy_l , const R& dummy_r , O_U_L o_U_L , O_U_R o_U_R , GROUP M );
  inline AbstractBiModule<L,R,U,O_U_L,O_U_R,GROUP>& operator=( const AbstractBiModule<L,R,U,O_U_L,O_U_R,GROUP>& ) noexcept;
  inline U LAction( const L& l , U u );
  inline U RAction( U u , const R& r );

};
template <typename L , typename R , typename O_U_L , typename O_U_R , typename GROUP> AbstractBiModule( const L& dummy_l , const R& dummy_r , O_U_L o_U_L , O_U_R o_U_R , GROUP M ) -> AbstractBiModule<L,R,inner_t<GROUP>,O_U_L,O_U_R,GROUP>;

template <typename L , typename R , typename U>
class BiModule :
  virtual public VirtualBiModule<L,R,U> ,
  public AdditiveGroup<U>
{

public:
  inline U LAction( const L& r , U u );
  inline U RAction( U u , const R& r );
  
};
