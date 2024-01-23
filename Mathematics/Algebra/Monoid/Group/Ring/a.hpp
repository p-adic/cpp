// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Ring/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/945877（Ring）
// https://yukicoder.me/submissions/945876（AbstractRing）

template <typename U , typename GROUP , typename MONOID>
class VirtualRing
{

private:
  GROUP m_R0;
  MONOID m_R1;

protected:
    inline VirtualRing( GROUP R0 , MONOID R1 );

public:
  inline U Sum( const U& u0 , const U& u1 );
  inline const U& Zero() const noexcept;
  inline U Inverse( const U& u );
  inline U Product( const U& u0 , const U& u1 );
  inline const U& One() const noexcept;
  inline GROUP& AdditiveGroup() noexcept;
  inline MONOID& MultiplicativeMonoid() noexcept;

};

template <typename U = ll>
class Ring :
  virtual public VirtualRing<U,AdditiveGroup<U>,MultiplicativeMonoid<U>>
{
  
public:
  inline Ring( const U& one_U );

};

template <typename U , typename A_U , typename I_U , typename M_U>
class AbstractRing :
  virtual public VirtualRing<U,AbstractGroup<U,A_U,I_U>,AbstractMonoid<U,M_U>>
{
  
public:
  inline AbstractRing( A_U& a_U , const U& z_U , I_U& i_U , M_U& m_U , const U& e_U );

};
