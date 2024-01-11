// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Function/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/942862（Dijstra）
// https://yukicoder.me/submissions/942864（MemorisationDijkstra）
// https://yukicoder.me/submissions/942865（EnumerationDijkstra）
// https://yukicoder.me/submissions/942866（EnumerationDijkstra）

// Eは写像edge:T->(T \times U)^{< \omega}に相当する型。
// メモリが不足する場合はEの定義を前計算しないでその都度計算させること。
// O((size+|edge|)log size)が間に合わない場合は、
// 始点からの距離を格納して一番近い未訪問点を全探策で探し距離を更新するO(size^2)版を検討。
template <typename T , typename U , typename E>
class Dijkstra_Body
{

protected:
  int m_size;

private:
  U m_infty;
  U m_found;
  E m_edge;

public:
  inline Dijkstra_Body( const int& size , const U& infty , const U& found , E edge );
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
  virtual void Reset();

};

// 入力の範囲内で要件
// (1) edgeの値の各成分の第2成分が0以上である。
// (2) 2^{31}-1がEの値の各成分の第2成分size個以下の和で表せるいかなる数よりも大きい。
// (6) Vの各要素u,vに対し、辺u->vが複数存在する場合は重みが最小のものが前にpushされている。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO((size+|edge|)log size)
// 単一始点単一終点最短経路探索／経路復元ありO((size+|edge|)log size)
// 単一始点全終点最短経路探索／経路復元なしO((size+|edge|)log size)
// 単一始点全終点最短経路探索／経路復元ありO(size^2 + |edge| log size)
template <typename E>
class Dijkstra :
  public Dijkstra_Body<int,ll,E>
{

public:
  inline Dijkstra( const int& size , E edge );
  
private:
  inline const ll& Unit() const;
  inline ll Addition( const ll& , const ll& ) const;
  inline int e( const int& i );
  inline int e_inv( const int& t );

};

template <typename T , typename U , typename M_U , typename E_U , typename E>
class MonoidForDijkstra :
  public Dijkstra_Body<T,U,E>
{

private:
  M_U m_m_U;
  E_U m_e_U;

public:
  inline MonoidForDijkstra( const int& size , M_U m_U , E_U e_U , const U& infty , const U& found , E edge );

private:
  inline const U& Unit() const;
  inline U Addition( const U& , const U& ) const;

};

// 入力の範囲内で要件
// (1) edgeの値の各成分の第2成分がe_U()以上である。
// (2) inftyがEの値の各成分の第2成分size個以下の和で表せるいかなる項よりも大きい。
// (3) foundがEの値の各成分の第2成分size個以下の和で表せず、inftyとも異なる。
// (4) (U,m_U:U^2->U,e_U:1->U)がbool operator<(const U&,const U&)に関して全順序モノイドである。
// (6) Vの各要素u,vに対し、辺u->vが複数存在する場合は重みが最小のものが前にpushされている。
// (7) edgeはデフォルト引数による呼び出し可能（推論補助に用いる）
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO((size+|edge|)(log size)^2)
// 単一始点単一終点最短経路探索／経路復元ありO((size+|edge|)(log size)^2)
// 単一始点全終点最短経路探索／経路復元なしO((size+|edge|)(log size)^2)
// 単一始点全終点最短経路探索／経路復元ありO(size^2 log size + |edge|(log size)^2)
template <typename T , typename U , typename M_U , typename E_U , typename E>
class MemorisationDijkstra :
  public MonoidForDijkstra<T,U,M_U,E_U,E>
{

private:
  int m_length;
  Map<T,int> m_memory;
  vector<T> m_memory_inv;

public:
  template <typename U2> inline MemorisationDijkstra( const int& size , M_U m_U , E_U e_U , const U& infty , const U2& found , E edge );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );
  inline void Reset();

};
template<typename U , typename U2 , typename M_U , typename E_U , typename E> MemorisationDijkstra( const int& , M_U , E_U , const U& , const U2& , E ) -> MemorisationDijkstra<decltype(declval<E>()(0).front().first),U,M_U,E_U,E>;

// 入力の範囲内で要件
// (1) edgeの値の各成分の第2成分がe_U()以上である。
// (2) inftyがEの値の各成分の第2成分size個以下の和で表せるいかなる項よりも大きい。
// (3) foundがEの値の各成分の第2成分size個以下の和で表せず、inftyとも異なる。
// (4) (U,m_U:U^2->U,e_U:1->U)がbool operator<(const U&,const U&)に関して全順序モノイドである。
// (5) (enum_T,enum_T_inv)が互いに逆写像である。
// (6) Vの各要素u,vに対し、辺u->vが複数存在する場合は重みが最小のものが前にpushされている。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO((size+|edge|)log size)
// 単一始点単一終点最短経路探索／経路復元ありO((size+|edge|)log size)
// 単一始点全終点最短経路探索／経路復元なしO((size+|edge|)log size)
// 単一始点全終点最短経路探索／経路復元ありO(size^2 + |edge| log size)
template <typename T , typename Enum_T , typename Enum_T_inv , typename U , typename M_U , typename E_U , typename E>
class EnumerationDijkstra :
  public MonoidForDijkstra<T,U,M_U,E_U,E>
{

private:
  Enum_T m_enum_T;
  Enum_T_inv m_enum_T_inv;
  
public:
  template <typename U2> inline EnumerationDijkstra( const int& size , Enum_T enum_T , Enum_T_inv enum_T_inv , M_U m_U , E_U e_U , const U& infty , const U2& found , E edge );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};
template<typename Enum_T , typename Enum_T_inv , typename U , typename U2 , typename M_U , typename E_U , typename E> EnumerationDijkstra( const int& , Enum_T , Enum_T_inv , M_U , E_U , const U& , const U2& , E ) -> EnumerationDijkstra<decltype(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,U,M_U,E_U,E>;
