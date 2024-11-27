// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../Algebra/a.hpp"
#include "../../Utility/Set/Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/957306（Graph、E:int->list<int>）
// https://yukicoder.me/submissions/957304（Graph、E:int->list<pair<int,dummy>>）
// https://yukicoder.me/submissions/957307（EnumerationGraph、E:int->list<int>）
// https://yukicoder.me/submissions/957308（MemorisationGraph、E:T->list<T>）

// Enumeration:N->R1-->TとEnumeration_inv:T->R2-->Nは互いに逆写像である仮想関数。
template <typename T , typename R1 , typename R2 , typename E>
class VirtualGraph :
  virtual public UnderlyingSet<T>
{

public:
  virtual R1 Enumeration( const int& i ) = 0;
  inline R2 Enumeration_inv( const T& t );
  template <typename PATH> inline R2 Enumeration_inv( const PATH& p );
  inline void Reset();
  virtual const int& size() const noexcept = 0;
  virtual E& edge() noexcept = 0;
  virtual ret_t<E,T> Edge( const T& t ) = 0;
  template <typename PATH> inline ret_t<E,T> Edge( const PATH& p );

  static inline const T& Vertex( const T& t ) noexcept;
  template <typename PATH> static inline const T& Vertex( const PATH& e ) noexcept;

private:
  virtual R2 Enumeration_inv_Body( const T& t ) = 0;

};

template <typename T , typename R1 , typename R2 , typename E>
class EdgeImplimentation :
  virtual public VirtualGraph<T,R1,R2,E>
{

private:
  int m_size;
  // 配列への参照を返す関数オブジェクトを構築して返す関数の返り値などの右辺値を受け取ることを
  // 許容したいので左辺値参照にはしない。
  E m_edge;

public:
  inline EdgeImplimentation( const int& size , E edge );
  inline const int& size() const noexcept;
  inline E& edge() noexcept;
  inline ret_t<E,T> Edge( const T& t );

};

template <typename E>
class Graph :
  public EdgeImplimentation<int,const int&,const int&,E>
{
  
public:
  inline Graph( const int& size , E edge );
  inline const int& Enumeration( const int& i );
  template <typename F> inline Graph<F> GetGraph( F edge ) const;

private:
  inline const int& Enumeration_inv_Body( const int& t );

};

template <typename T , typename Enum_T , typename Enum_T_inv , typename E>
class EnumerationGraph :
  public EdgeImplimentation<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>
{

private:
  Enum_T m_enum_T;
  Enum_T_inv m_enum_T_inv;
  
public:
  inline EnumerationGraph( const int& size , Enum_T enum_T , Enum_T_inv enum_T_inv , E edge );
  inline ret_t<Enum_T,int> Enumeration( const int& i );
  template <typename F> inline EnumerationGraph<T,Enum_T,Enum_T_inv,F> GetGraph( F edge ) const;

private:
  inline ret_t<Enum_T_inv,T> Enumeration_inv_Body( const T& t );

};
template <typename Enum_T , typename Enum_T_inv , typename E> EnumerationGraph( const int& size , Enum_T enum_T , Enum_T_inv enum_T_inv , E edge ) -> EnumerationGraph<decldecay_t(declval<Enum_T>()(0)),Enum_T,Enum_T_inv,E>;

template <typename T , typename E>
class MemorisationGraph :
  public EdgeImplimentation<T,T,const int&,E>
{

private:
  int m_length;
  vector<T> m_memory;
  Map<T,int> m_memory_inv;
  
public:
  // 型推論のためにdummyを渡す。Eの戻り値の型から推論させると重み付き辺の時に機能しない。
  inline MemorisationGraph( const int& size , const T& dummy , E edge );
  // push_backする可能性のあるvectorなので参照にしないように注意
  inline T Enumeration( const int& i );
  inline void Reset();
  template <typename F> inline MemorisationGraph<T,F> GetGraph( F edge ) const;

private:
  inline const int& Enumeration_inv_Body( const T& t );
  
};
