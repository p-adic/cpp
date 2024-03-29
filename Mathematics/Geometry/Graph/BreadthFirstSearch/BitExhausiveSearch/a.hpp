// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/955871（NextSubset）

class BitExhausiveEdge
{

public:
  const int* m_p_V;
  inline vector<int> operator()( const int& t );

};

// bitを0から1に変更する方向に有向辺を貼ったグラフに対するBFS
class BitExhausiveSearch :
  public BreadthFirstSearch<int,Graph<BitExhausiveEdge>>
{

private:
  Graph<BitExhausiveEdge> m_G;
  const int* m_p_V;
  int m_digit;
  
public:
  // Vは最大の集合に対応する整数+1（digitの羃集合全体なら1<<digit）
  inline BitExhausiveSearch( const int& V , const int& digit );
  inline BitExhausiveSearch( const int& V );

  // tに対応する部分集合に1つ要素を追加した部分集合で未到達なものを格納し到達済みにマーク。
  inline vector<int> UnreachedAdjacentSupsetOf( const int& t ) noexcept;
  // tに対応する部分集合に1つ要素を削除した部分集合で未到達なものを格納し到達済みにマーク。
  // O(log_2 t)かかり、多点BFSではこれを使えばO(2^digit)で抑えられる。
  inline vector<int> UnreachedAdjacentSubsetOf( const int& t ) noexcept;

  // tに対応する部分集合を真に含む部分集合で未到達なものを格納し到達済みにマーク。
  inline vector<int> UnreachedProperSupsetOf( const int& t ) noexcept;
  // tに対応する部分集合の真部分集合で未到達なものを格納し到達済みにマーク。
  // tのオーダーがかかるので、多点BFSでこれを使うと最悪3^digitのオーダーになることに注意。
  inline vector<int> UnreachedProperSubsetOf( const int& t ) noexcept;

  // tに対応する部分集合に1つ要素を追加した部分集合を格納。
  inline vector<int> AdjacentSupsetOf( const int& t ) noexcept;
  // tに対応する部分集合を真に含む部分集合を格納。
  inline vector<int> ProperSupsetOf( const int& t ) noexcept;

  // tに対応する部分集合に1つ要素を削除した部分集合を格納。
  static inline vector<int> AdjacentSubsetOf( const int& t ) noexcept;
  // tに対応する部分集合の真部分集合を格納。
  static inline vector<int> ProperSubsetOf( const int& t ) noexcept;

  // 対応する部分集合の濃度を変えずにtを昇順で後続に遷移させる。
  inline bool NextSubset( int& t ) noexcept;

  // tの2進表記における桁数を返す。
  static inline int DigitOf( const int& t ) noexcept;
  // tの2進加法付値をメモ化して返す。（合計O(max t)）
  static inline const int& ValuationOf( const int& t ) noexcept;
  
};
