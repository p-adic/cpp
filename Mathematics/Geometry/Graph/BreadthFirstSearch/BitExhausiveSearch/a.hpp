// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

template <int digit>
class BitExhausiveSearch :
  public BASE_FOR_BIT_EXHAUSIVE_SEARCH
{

private:
  static map<int,int> g_v;
  
public:
  // V�͍ő�̏W���ɑΉ����鐮��+1�i�񕉐���n��㰏W���S�̂Ȃ�1<<n�j
  inline BitExhausiveSearch( const int& V );
  
  inline list<int> UnreachedAdjacentSupsetOf( const int& t ) noexcept;
  inline list<int> UnreachedAdjacentSubsetOf( const int& t ) noexcept;

  inline list<int> UnreachedProperSupsetOf( const int& t ) noexcept;
  inline list<int> UnreachedProperSubsetOf( const int& t ) noexcept;

  inline list<int> AdjacentSupsetOf( const int& t ) noexcept;
  inline list<int> ProperSupsetOf( const int& t ) noexcept;

  static inline list<int> AdjacentSubsetOf( const int& t ) noexcept;
  static inline list<int> ProperSubsetOf( const int& t ) noexcept;

  static inline const int& ValuationOf( const int& t ) noexcept;

private:
  inline list<int> e( const int& t );
  
};