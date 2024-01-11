// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a.hpp

#pragma once
#include "../a.hpp"

// verify: https://yukicoder.me/submissions/942784

template <typename E>
class ZeroOneBreadthFirstSearch
{

protected:
  int m_V;
  E m_e;
  int m_init;
  list<int> m_next;

  // 0:未接続、1:前に接続、2:後ろに接続、3:探索済み
  vector<int> m_found;
  vector<int> m_prev;
  vector<int> m_weight;
  
public:
  inline ZeroOneBreadthFirstSearch( const int& V , E e );
  inline ZeroOneBreadthFirstSearch( const int& V , E e , const int& init );

  // m_foundとm_prevとm_weightを初期化
  inline void Reset( const int& init );
  // m_foundとm_prevとm_weightを非初期化
  inline void Shift( const int& init );

  inline const int& size() const;
  inline const int& init() const;
  inline int& found( const int& i );
  inline const int& prev( const int& i ) const;
  inline const int& weight( const int& i ) const;

  int Next();

  // Next()の反復でm_initから到達可能な頂点を全探索。
  // 計算量O((m_initの連結成分)+(m_initの連結成分におけるEのサイズの合計))
  inline void SetWeight();

  // Next()の反復でinitからgoalまでの最短経路を探索。
  // 計算量O((initの連結成分)+(m_initの連結成分におけるEのサイズの合計))
  inline const int& Solve( const int& init , const int& goal );

};
