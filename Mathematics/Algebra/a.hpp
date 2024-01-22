// c:/Users/user/Documents/Programming/Mathematics/Algebra/a.hpp

#pragma once

template <typename U>
class VirtualPointedSet
{

public:
  virtual const U& Point() const noexcept = 0;
  inline const U& Unit() const noexcept;
  inline const U& Zero() const noexcept;
  inline const U& One() const noexcept;
  inline const U& Infty() const noexcept;
  inline const U& size() const noexcept;

};

template <typename U>
class PointedSet :
  virtual public VirtualPointedSet<U>
{

private:
  U m_b_U;

public:
  inline PointedSet( const U& b_u = U() );
  inline const U& Point() const noexcept;

};

template <typename U>
class VirtualNSet
{

public:
  virtual U Transfer( const U& u ) = 0;
  inline U Inverse( const U& u );

};

template <typename U , typename F_U>
class AbstractNSet :
  virtual public VirtualNSet<U>
{

private:
  F_U m_f_U;

public:
  inline AbstractNSet( F_U f_U );
  inline U Transfer( const U& u );

};

template <typename U>
class VirtualMagma
{

public:
  virtual U Product( const U& u0 , const U& u1 ) = 0;
  inline U Sum( const U& u0 , const U& u1 );

};

template <typename U , typename M_U>
class AbstractMagma :
  virtual public VirtualMagma<U>
{

private:
  M_U m_m_U;

public:
  inline AbstractMagma( M_U m_U );
  inline U Product( const U& u0 , const U& u1 );

};
