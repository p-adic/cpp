// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) GはTの等号付き半順序構造<=のグラフ（s<=t <=> s <- t）である。
// (2) G_invはGの辺を逆にしたグラフである。
// (3) RはUの（単位的でなくても良い）Z代数構造である。
// を満たす場合にのみサポート。
// ただし
// - 全体加算や一点取得を行わないならばRはダミーのZ作用を持つ非単位的環でも良い。
// - 全体乗算や畳み込み乗法を行わないならばRはダミーの積を持つZ加群でも良い。

// T上の関数f(t)を{-∞}∪T上の隣接代数の元F(s,t)=s==-∞?f(t):0に対応させてゼータ変換する。
// 例えば<=が倍数関係ならば倍数全体での総和、約数関係ならば約数全体での総和を取る。

// R.Zero()による初期化O(size)
// ゼータ変換前の配列による初期化O(size+始切片のサイズの総和)（可換加法モノイド性を使う）
// ゼータ変換後の配列による初期化O(1)

// 一点加算O(終切片[t,∞)のサイズ)（m_G_invと可換加法モノイド性を使う）
// 全体加算O(size)（可換加法モノイド性だけでも実装できるが高速化のために非単位的Z代数性を使う）
// 加法O(size)（m_G.Edgeが非参照ならばO(size + |m_G.Edge|)、可換加法モノイド性を使う）

// 全体乗算O(size)（半環性を使う）
// (T,<)がjoin半束である場合の畳み込み乗法O(size)（半環性を使う）

// 一点取得O(始切片(-∞,t]のサイズ * メビウス関数の計算量)（非単位的Z代数性を使う）
// 始切片和取得O(1)（可換加法モノイド性を使う）

// 逆像和取得O(始切片(-∞,r_max]のサイズ * メビウス関数の計算量)（非単位的Z代数性を使う）
// 始切片逆像和取得O(1)（可換加法モノイド性を使う）
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG>
class VirtualZetaTransform
{

protected:
  GRAPH m_G;
  GRAPH_INV m_G_inv;
  Z_ALG m_R;
  // Tの各要素tに対し、t以下の要素を渡る総和をm_val[m_G.Enumeration_inv( t )]に管理。
  vector<U> m_val;

public:
  inline VirtualZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R );
  inline VirtualZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R , vector<U> a , const bool& transformed = false );

  template <typename...Args> inline void Initialise( Args&&... args );

  inline void Add( const T& t , const U& u );
  inline void TotalAdd( const U& u );
  inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& operator+=( const VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& a );
  
  inline void TotalMultiply( const U& u );
  inline VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& operator*=( const VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>& a );

  // 半順序に付随するメビウス関数のデフォルトの再帰式を使うため、
  // 再帰深度が浅い場合にしか使えない。
  U operator[]( const T& t );
  inline U Get( const T& t );
  inline const U& InitialSegmentSum( const T& t );

  // 部分写像f_inv_max:T->Tと写像range:T->T^{<∞}と引数であるSの要素sが要件
  // (1) f_inv_maxは定義域にrange(s)を含む
  // (2) range(s)は重複を持たない。（よってSの部分集合とみなす）
  // (3) sはrange(s)の最大元である。
  // を満たし、かつ要件
  // (4) f_inv_max(s)を上界に持つTの要素全体R_sへのfの制限f_sは順序保存写像R_s->range(s)である。
  // (5) range(s)の任意の要素s'に対しf_inv_max(s')が逆像f_s^{-1}(s')の最大元である。
  //    （従って特にf_sは全射）
  // を満たす写像f:T->Tが存在する場合にのみ以下の２つをサポート。

  // f(t)=sを満たすR_sの要素t全体を渡るm_val[t]の総和取得。
  // 半順序に付随するメビウス関数のデフォルトの再帰式を使うため、
  // 再帰深度が浅い場合にしか使えない。
  template <typename F_INV_MAX , typename RANGE> U InverseImageSum( F_INV_MAX&& f_inv_max , RANGE&& range , const T& s );
  // 例１：T=int、<=:任意の等号つき半順序
  //      f=各点の逆像が「非空かつ上に有界」を満たす単調減少写像、
  //      f_inv_max=fの逆像の最大値、range(x)=[1,x]
  //      -> f^{-1}({f(s)})の各点tをわたるm_val[t]の総和取得。
  // 例２：T=[1,size)、s <= t: sはtの約数 
  //      f=gcd(lcm(a,-),b)（a,bはaがbの約数である定数in S）、f_inv_max=id_S、s=b、
  //      range=aの倍数であるbの約数全体の集合を返す定数関数
  //      -> lcm(a,t)がbの倍数であるsize未満の各正整数tをわたるm_val[t]の総和取得。
  // 例３：T=[1,size)、s <= t: sはtの倍数
  //      f=gcd(a,-)（aは定数in S）、f_inv_max=id_S、s=1、
  //      range=aの約数全体の集合を返す定数関数
  //      -> aと互いに素なsize未満の各正整数tをわたるm_val[t]の総和取得。
  
  // f(t) <= sを満たすR_sの要素t全体を渡るm_val[t]の総和取得。
  //（結果的にrangeは使わないが要件上はrangeの存在が必要） 
  template <typename F_INV_MAX> inline const U& InitialSegmentInverseImageSum( F_INV_MAX&& f_inv_max , const T& s );
 
private:
  virtual int Moevius( const T& t0 , const T& t1 );

};
template <typename GRAPH , typename GRAPH_INV , typename Z_ALG> VirtualZetaTransform( GRAPH& , GRAPH_INV& , Z_ALG ) -> VirtualZetaTransform<inner_t<GRAPH>,GRAPH,GRAPH_INV,inner_t<Z_ALG>,Z_ALG>;

// 入力の範囲内で要件
// (1) GはTの等号付き半順序構造<=のグラフ（s<=t <=> s <- t）である。
// (2) G_invはGの辺を逆にしたグラフである。
// (3) RはUの非単位的Z代数構造である。
// (4) muは(T,<=)のメビウス関数である。
// を満たす場合にのみサポート。一点取得と逆像和取得にのみmuを使う。
// ただし全体加算や一点取得を行わないならばRはダミーのZ作用を持つ非単位的環でも良い。

// R.Zero()による初期化O(size)
// ゼータ変換前の配列による初期化O(始切片のサイズの総和)
// ゼータ変換後の配列による初期化O(1)

// 一点加算O(終切片[t,∞)のサイズ)
// 全体加算O(size)
// 各点加法O(size)（m_G_invを用いる）
// 全体乗算O(size)
// (int,<=)がjoin半束である場合の畳み込み乗法O(size)

// 一点取得O(始切片(-∞,t]のサイズ)
// 始切片和取得O(1)

// 逆像和取得O(始切片(-∞,f_inv_max(r_max)]のサイズ)
// 始切片逆像和取得O(1)
template <typename T , typename GRAPH , typename GRAPH_INV , typename U , typename Z_ALG , typename MU>
class AbstractZetaTransform :
  // コンストラクタが非自明なので仮想継承を避ける。
  public VirtualZetaTransform<T,GRAPH,GRAPH_INV,U,Z_ALG>
{

private:
  MU m_mu;
  
public:
  template <typename...Args> inline AbstractZetaTransform( GRAPH G , GRAPH_INV G_inv , Z_ALG R , MU mu , Args&&... args );
  
private:
  inline int Moevius( const T& t0 , const T& t1 );

};
template <typename GRAPH , typename GRAPH_INV , typename Z_ALG , typename MU> AbstractZetaTransform( GRAPH& , GRAPH_INV& , Z_ALG , MU ) -> AbstractZetaTransform<inner_t<GRAPH>,GRAPH,GRAPH_INV,inner_t<Z_ALG>,Z_ALG,MU>;
