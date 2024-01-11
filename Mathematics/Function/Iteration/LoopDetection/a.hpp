// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a.hpp

#pragma once
#include "../../Map/a.hpp"

// verify:
// https://yukicoder.me/submissions/942807（MemorisationLoopDetection）
// https://yukicoder.me/submissions/942806（EnumerationLoopDetection）

// Fはf:T->U(-->T)の型。
// fのループ検出を行う。

// 反復合成O(loop_start+(n-loop_start)%loop_length)
// 像の要素数取得O(1)（ただしループ検出前の時のみO(loop_start+loop_length)）
// ループ始点取得O(1)（ただしループ検出前の時のみO(loop_start+loop_length)）
// ループ長取得O(1)（ただしループ検出前の時のみO(loop_start+loop_length)）
template <typename T , typename F>
class LoopDetection_Body
{

private:
  T m_init;
  F m_f;
  
protected:
  int m_length;
  int m_loop_start;
  int m_loop_length;

public:
  inline LoopDetection_Body( const T& init , F f );
  
  template <typename INT> T IteratedComposition( const INT& n );

  // 像の要素数取得
  inline const int& GetLength() noexcept;
  // ループ始点取得
  inline const int& GetLoopStart() noexcept;
  // ループ長取得
  inline const int& GetLoopLength() noexcept;
  
private:
  inline void SetInit();
  inline void SearchLoop();
  virtual T e( const int& i ) = 0;
  virtual int e_inv( const T& t ) = 0;
  virtual void SetValue( const int& i ) = 0;
  virtual const int& GetValue( const int& i ) = 0;

};

template <typename T , typename F>
class ValueCalculatorForLoopDetection :
  public LoopDetection_Body<T,F>
{

private:
  unordered_map<int,int> m_value;
  unordered_map<int,int> m_value_inv;

public:
  inline ValueCalculatorForLoopDetection( const T& init , F f );

private:
  void SetValue( const int& i );
  int& RefValue( const int& i );
  const int& GetValue( const int& i );
  int& RefValue_inv( const int& i );

};

template <typename F>
class LoopDetection :
  public ValueCalculatorForLoopDetection<int,F>
{
  
public:
  inline LoopDetection( const int& init , F f );

private:
  inline int e( const int& i );
  inline int e_inv( const int& t );

};

template <typename T , typename F>
class MemorisationLoopDetection :
  public LoopDetection_Body<T,F>
{

private:
  Map<T,int> m_memory;
  vector<T> m_memory_inv;

public:
  inline MemorisationLoopDetection( const T& init , F f );
  inline T e( const int& i );
  inline int e_inv( const T& t );
  void SetValue( const int& i );
  const int& GetValue( const int& i );

};

template <typename T , typename Enum_T , typename Enum_T_inv , typename F>
class EnumerationLoopDetection :
  public ValueCalculatorForLoopDetection<T,F>
{

private:
  Enum_T m_enum_T;
  Enum_T_inv m_enum_T_inv;

public:
  inline EnumerationLoopDetection( const T& init , Enum_T enum_T , Enum_T_inv enum_T_inv , F f );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};

