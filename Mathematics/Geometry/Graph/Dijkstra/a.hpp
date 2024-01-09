// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Function/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/942531
// https://yukicoder.me/submissions/942534

// メモリが不足する場合はEの定義を前計算しないでその都度計算させること。
// O((size+|E|)log size)が間に合わない場合は、
// 始点からの距離を格納して一番近い未訪問点を全探策で探し距離を更新するO(size^2)版を検討。
template <typename T , typename U , list<pair<T,U> > E(const T&)>
class DijkstraBody
{

private:
  int m_size;
  U m_infty;
  U m_found;

public:
  inline DijkstraBody( const int& size , const U& infty , const U& found );
  // 経路が存在しない場合の返り値はm_infty
  U Solve( const T& t_start , const T& t_final );
  U Solve( const T& t_start , const T& t_final , list<T>& path );
  void Solve( const T& t_start , vector<U>& weight );
  void Solve( const T& t_start , vector<U>& weight , vector<list<T>>& path );
  
  const U& Infty() const;
  
private:
  virtual const U& Unit() const = 0;
  virtual U Addition( const U& , const U& ) const = 0;
  virtual T e( const int& i ) = 0;
  virtual int e_inv( const T& t ) = 0;
  virtual void Reset() = 0;

};

// 入力の範囲内で要件
// (1) Eの値の各成分の第2成分が0以上である。
// (2) 2^{31}-1がEの値の各成分の第2成分size個以下の和で表せるいかなる数よりも大きい。
// (6) Vの各要素u,vに対し、辺u->vが複数存在する場合は重みが最小のものが前にpushされている。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO((size+|E|)log size)
// 単一始点単一終点最短経路探索／経路復元ありO((size+|E|)log size)
// 単一始点全終点最短経路探索／経路復元なしO((size+|E|)log size)
// 単一始点全終点最短経路探索／経路復元ありO(size^2 + |E| log size)
template <list<pair<int,ll> > E(const int&)>
class Dijkstra :
  public DijkstraBody<int,ll,E>
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
// (1) Eの値の各成分の第2成分がe_U()以上である。
// (2) inftyがEの値の各成分の第2成分size個以下の和で表せるいかなる項よりも大きい。
// (3) foundがEの値の各成分の第2成分size個以下の和で表せず、inftyとも異なる。
// (4) (U,m_U:U^2->U,e_U:1->U)がbool operator<(const U&,const U&)に関して全順序モノイドである。
// (6) Vの各要素u,vに対し、辺u->vが複数存在する場合は重みが最小のものが前にpushされている。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO((size+|E|)(log size)^2)
// 単一始点単一終点最短経路探索／経路復元ありO((size+|E|)(log size)^2)
// 単一始点全終点最短経路探索／経路復元なしO((size+|E|)(log size)^2)
// 単一始点全終点最短経路探索／経路復元ありO(size^2 log size + |E|(log size)^2)
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&)>
class MemorisationDijkstra :
  public DijkstraBody<T,U,E>
{

private:
  int m_length;
  Map<T,int> m_memory;
  vector<T> m_memory_inv;

public:
  inline MemorisationDijkstra( const int& size , const U& infty = 9223372036854775807 , const U& found = -1 );
  
private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;
  inline T e( const int& i );
  inline int e_inv( const T& t );
  inline void Reset();

};

// 入力の範囲内で要件
// (1) Eの値の各成分の第2成分がe_U()以上である。
// (2) inftyがEの値の各成分の第2成分size個以下の和で表せるいかなる項よりも大きい。
// (3) foundがEの値の各成分の第2成分size個以下の和で表せず、inftyとも異なる。
// (4) (U,m_U:U^2->U,e_U:1->U)がbool operator<(const U&,const U&)に関して全順序モノイドである。
// (5) (enum_T,enum_T_inv)が互いに逆写像である。
// (6) Vの各要素u,vに対し、辺u->vが複数存在する場合は重みが最小のものが前にpushされている。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO((size+|E|)log size)
// 単一始点単一終点最短経路探索／経路復元ありO((size+|E|)log size)
// 単一始点全終点最短経路探索／経路復元なしO((size+|E|)log size)
// 単一始点全終点最短経路探索／経路復元ありO(size^2 + |E| log size)
template <typename T , typename U , U m_U(const U&,const U&) , const U& e_U() , list<pair<T,U> > E(const T&) , T enum_T(const int&) , int enum_T_inv(const T&)>
class EnumerationDijkstra :
  public DijkstraBody<T,U,E>
{

public:
  inline EnumerationDijkstra( const int& size , const U& infty = 9223372036854775807 , const U& found = -1 );
  
private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;
  inline T e( const int& i );
  inline int e_inv( const T& t );
  inline void Reset();

};

