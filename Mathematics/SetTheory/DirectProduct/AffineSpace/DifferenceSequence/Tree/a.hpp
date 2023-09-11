// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/Tree/a.hpp

#pragma once
#include "../a.hpp"

// 森上の階差数列。

// 入力の範囲内で要件
// (1) グラフ(V,E)は有向グラフとして各連結成分が根つき木である。
// (2) (V,E)の各辺v0->v1に対しv0 = E_inv(v1)が成り立つ。
// (3) (V,E)の各連結成分の根vに対しE_inv(v) = vが成り立つ。
// (4) (enum_V:N->V,enum_V_inv:V->N)は互いに逆写像である。
// (5) (V,E)の各辺v0->v1に対しe_inv(v0) < e_inv(v1)が成り立つ。
// (6) (T,m_T:T^2->T,e_T:1->T)は可換モノイドである。
// (7) (U,inv_U:U->U)は羃等演算つき集合である。
// (8) o_U:U×T->Tは(U,inv_U)から(T,m_T,e_T)の可逆元全体の群への準同型とm_Tの合成である。
// が成り立つ場合にのみサポート。（例えばTが可換群でU=Tでo_UがただのTの演算）

// e_T()による初期化O(size_max)

// 一点代入O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）
// 一点取得O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）

// 一点加算O(1)（作用を遅延評価しない）
// 部分木加算O(1+t_finalのサイズ)（作用を遅延評価する）
// 加法O(size)（作用の遅延評価を解消する）
template <typename V , list<V> E(const V&) , V E_inv(const V&) , V enum_V(const int&) , int enum_V_inv(const V&) , typename T , T& m_T(const T&,T&) , const T& e_T() , typename U , U inv_U(const U&) , T& o_U(const U&,T&) , int size_max>
class DifferenceSequenceOnTree :
  public DifferenceSequenceBody<V,T,U,size_max>
{

public:
  inline DifferenceSequenceOnTree( const int& size );
  
private:
  inline list<V> Edge( const V& v ) const;
  inline V Edge_inv( const V& v ) const;
  inline V e( const int& i ) const;
  inline int e_inv( const V& v ) const;
  inline const T& Unit() const;
  inline T& Addition( const T& t0 , T& t1 ) const;
  inline U Inverse( const U& u ) const;
  inline T& Action( const U& u , T& t ) const;

};
