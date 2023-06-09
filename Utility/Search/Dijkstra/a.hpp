// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T , typename U , list<pair<T,U> > E(const T&) , int size_max>
class DijkstraBody
{

private:
  int m_size;
  U m_infty;
  U m_found;

  int m_length;
  map<T,int> m_memory;
  vector<T> m_memory_inv;
  
public:
  inline DijkstraBody( const int& size , const U& infty , const U& found );
  U Solve( const T& t_start , const T& t_final );
  U Solve( const T& t_start , const T& t_final , list<T>& path );
  
private:
  virtual const U& Unit() const = 0;
  virtual U Addition( const U& , const U& ) const = 0;
  virtual T e( const int& i );
  virtual int e_inv( const T& t );
  virtual void Reset();

};

// 入力の範囲内で要件
// (1) Eの値の各成分の第2成分が0以上である。
// (2) 2^{31}-1がEの値の各成分の第2成分size_max個以下の和で表せるいかなる数よりも大きい。
// が成り立つ場合にのみサポート。
template <list<pair<int,ll> > E(const int&) , int size_max>
class Dijkstra :
  public DijkstraBody<int,ll,E,size_max>
{

public:
  inline Dijkstra( const int& size );
  
private:
  inline const ll& Unit() const;
  inline ll Addition( const ll& , const ll& ) const;
  inline int e( const int& i );
  inline int e_inv( const int& t );
  inline void Reset();

};

// 入力の範囲内で要件
// (1) Eの値の各成分の第2成分がe_T()以上である。
// (2) inftyがEの値の各成分の第2成分size_max個以下の和で表せるいかなる項よりも大きい。
// (3) foundがEの値の各成分の第2成分size_max個以下の和で表せず、inftyとも異なる。
// (4) (U,m_U:U^2->U,e_U:1->U)がbool operator<(const U&,const U&)に関して順序モノイドである。
// が成り立つ場合にのみサポート。
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max>
class MemorisationDijkstra :
  public DijkstraBody<T,U,E,size_max>
{

public:
  inline MemorisationDijkstra( const int& size , const U& infty = 2147483647 , const U& found = -1 );
  
private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;

};

// 入力の範囲内で要件
// (1) Eの値の各成分の第2成分がe_T()以上である。
// (2) inftyがEの値の各成分の第2成分size_max個以下の和で表せるいかなる項よりも大きい。
// (3) foundがEの値の各成分の第2成分size_max個以下の和で表せず、inftyとも異なる。
// (4) (U,m_U:U^2->U,e_U:1->U)がbool operator<(const U&,const U&)に関して順序モノイドである。
// (5) (enum_T,enum_T_inv)が互いに逆写像である。
// が成り立つ場合にのみサポート。
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)>
class EnumerationDijkstra :
  public DijkstraBody<T,U,E,size_max>
{

public:
  inline EnumerationDijkstra( const int& size , const U& infty = 2147483647 , const U& found = -1 );
  
private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;
  inline T e( const int& i );
  inline int e_inv( const T& t );
  inline void Reset();

};

