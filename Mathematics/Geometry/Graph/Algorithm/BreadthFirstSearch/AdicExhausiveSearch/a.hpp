// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/AdicExhausiveSearch/a.hpp

#pragma once
//verify:
// https://yukicoder.me/submissions/976478（Next, Shift）
// https://yukicoder.me/submissions/976469（NextPermutation）
// https://yukicoder.me/submissions/976492（Power, to_vec）

#include "../../a.hpp"

class AdicExhausiveSearch;

class AdicExhausiveEdge
{

  friend class AdicExhausiveSearch;
  
private:
  const int* m_p_V;
  const int* m_p_N;
  const int* m_p_N_minus;
  bool m_reversed;

public:
  inline vector<int> operator()( const int& t );

};

// N進法表記の桁でN-1未満の値を1増やす方向に有向辺を貼ったグラフに対するBFS
class AdicExhausiveSearch :
  public BreadthFirstSearch<int,Graph<AdicExhausiveEdge>>
{

private:
  Graph<AdicExhausiveEdge> m_G;
  const int* m_p_V;
  int m_N;
  int m_N_minus;
  int m_digit;
  vector<int> m_N_power;
  vector<int> m_valuation;
  
public:
  // Vは最大の整数+1（N進法表記でdigit桁の整数全体ならN^digit）
  inline AdicExhausiveSearch( const int& N , const int& V , const bool& reversed = false );
  inline AdicExhausiveSearch( const int& N , const int& digit , const int& dummy , const bool& reversed = false );

  // 1+d桁目をanswer[d]に格納する。
  inline vector<int> to_vec( int t );
  inline int to_int( const vector<int>& a );

  // tのN進法表記の桁でN-1未満の値を1増やした数で未到達なものを格納し到達済みにマーク。
  inline vector<int> UnreachedAdjacentUpperboundOf( const int& t );
  // tのN進法表記の桁で1以上の値を1減らした数で未到達なものを格納し到達済みにマーク。
  // O(log_N t)かかり、多点BFSではこれを使えばO(N^digit)で抑えられる。
  inline vector<int> UnreachedAdjacentLowerboundOf( const int& t );

  // tからN進法表記の桁を真に増やした数で未到達なものを格納し到達済みにマーク。
  inline vector<int> UnreachedProperUpperboundOf( const int& t );
  // tからN進法表記の桁を真に減らした数で未到達なものを格納し到達済みにマーク。
  // tのオーダーがかかるので、多点BFSでこれを使うと最悪3^digitのオーダーになることに注意。
  inline vector<int> UnreachedProperLowerboundOf( const int& t );

  // tのN進法表記の桁でN-1未満の値を1増やした数を格納。
  inline vector<int> AdjacentUpperboundOf( const int& t );
  // tからN進法表記の桁を真に増やした数を格納。
  inline vector<int> ProperUpperboundOf( const int& t );

  // tのN進法表記の桁でN-1未満の値を1減らした数を格納。
  inline vector<int> AdjacentLowerboundOf( const int& t );
  // tからN進法表記の桁を真に減らした数を格納。
  inline vector<int> ProperLowerboundOf( const int& t );

  // N進法表記の桁の分布を変えずにtを昇順で後続に遷移させる。
  inline bool NextPermutation( int& t );
  inline bool NextPermutation( vector<int>& S );

  // tのN進表記における桁数を返す。（O(log_N(t))）
  inline int DigitOf( const int& t );
  // tがN羃の時のみサポート。
  // tのNで割り切れる回数をメモ化して返す。（合計O(max log_N t)）
  inline const int& ValuationOf( const int& t );
  inline const int& Power( const int& digit ) const;
  static inline int Power( int N , int digit );
  
};

