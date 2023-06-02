// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T>
class PairForDijkstra
{

private:
  T m_t;
  int m_i;

public:
  inline PairForDijkstra( const T& t = T() , const int& i = 0 );
  inline void Set( const T& t );
  inline const T& Get() const noexcept;
  inline const int& index() const noexcept;
  inline bool operator<( const PairForDijkstra& t ) const;

};

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,e_T:1->T)がbool operator<(const T&,const T&)に関して順序モノイドである。
// (2) dの値がe_T()以上またはinftyである。
// (3) inftyがe_T()以上の項size_max個以下の和で表せない。
// が成り立つ場合にのみサポート。
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const T ( &d )[size_max][size_max] , const int& i_start , const int& i_final , const int& size , const T& infty );
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const T ( &d )[size_max][size_max] , const int& i_start , const int& i_final , const int& size , const T& infty , list<int>& path );
