// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/a.hpp

#pragma once

template <typename T , uint D>
class AffineSpace
{

private:
  T m_v[D];

public:
  inline AffineSpace();
  template<uint E> inline AffineSpace( const T (&v)[E] );
  template<uint E> inline AffineSpace<T,D>& operator=( const AffineSpace<T,E>& x );
  T& operator[]( const uint& i );
  const T& operator[]( const uint& i ) const;
  
private:
  template<uint E> void Set( const T (&v)[E] );
  template<uint E> void Substitute( const T (&v)[E] );

};
