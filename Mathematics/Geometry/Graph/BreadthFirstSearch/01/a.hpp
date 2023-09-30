// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a.hpp

#pragma once
#include "../a.hpp"



template <int V_max>
class ZeroOneBreadthFirstSearch_Body
{

protected:
  int m_V;
  int m_init;
  list<int> m_next;
  int m_found[V_max];
  int m_prev[V_max];
  int m_weight[V_max];
  
public:
  inline ZeroOneBreadthFirstSearch_Body( const int& V );
  inline ZeroOneBreadthFirstSearch_Body( const int& V , const int& init );

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

private:
  virtual list<pair<int,bool> > e( const int& t ) = 0;

};

template <int V_max,list<pair<int,bool> > E(const int&)>
class ZeroOneBreadthFirstSearch :
  public ZeroOneBreadthFirstSearch_Body<V_max>
{
  
public:
  template<typename... Args> inline ZeroOneBreadthFirstSearch( const Args&... args );

private:
  inline list<pair<int,bool> > e( const int& t );

};
