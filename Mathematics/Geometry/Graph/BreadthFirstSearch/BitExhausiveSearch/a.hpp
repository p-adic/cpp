// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/BitExhausiveSearch/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// verify: https://yukicoder.me/submissions/942797（NextSubset）

class BitExhausiveSearch :
  public BreadthFirstSearch_Body
{

private:
  int m_digit;
  
public:
  // Vは最大の集合に対応する整数+1（digitの羃集合全体なら1<<digit）
  inline BitExhausiveSearch( const int& digit , const int& V );
  inline BitExhausiveSearch( const int& digit );

  // tに対応する部分集合に1つ要素を追加した部分集合で未到達なものを格納。
  inline list<int> UnreachedAdjacentSupsetOf( const int& t ) noexcept;
  // tに対応する部分集合に1つ要素を削除した部分集合で未到達なものを格納。
  inline list<int> UnreachedAdjacentSubsetOf( const int& t ) noexcept;

  // tに対応する部分集合を真に含む部分集合で未到達なものを格納。
  inline list<int> UnreachedProperSupsetOf( const int& t ) noexcept;
  // tに対応する部分集合の真部分集合で未到達なものを格納。
  inline list<int> UnreachedProperSubsetOf( const int& t ) noexcept;

  // tに対応する部分集合に1つ要素を追加した部分集合を格納。
  inline list<int> AdjacentSupsetOf( const int& t ) noexcept;
  // tに対応する部分集合を真に含む部分集合を格納。
  inline list<int> ProperSupsetOf( const int& t ) noexcept;

  // tに対応する部分集合に1つ要素を削除した部分集合を格納。
  static inline list<int> AdjacentSubsetOf( const int& t ) noexcept;
  // tに対応する部分集合の真部分集合を格納。
  static inline list<int> ProperSubsetOf( const int& t ) noexcept;

  // 対応する部分集合の濃度を変えずにtを昇順で後続に遷移させる。
  static inline bool NextSubset( int& t , const int& digit , const int& V ) noexcept;
  static inline bool NextSubset( int& t , const int& digit ) noexcept;

  // tの2進加法付値を返す。
  static inline const int& ValuationOf( const int& t ) noexcept;

private:
  inline list<int> e( const int& i );
  
};
