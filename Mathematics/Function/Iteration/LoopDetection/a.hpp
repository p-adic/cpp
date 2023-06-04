// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T , typename U , U f(const T&) , int length_max>
class LoopDetectionBody
{

private:
  T m_init;
  map<T,int> m_memory;
  vector<T> m_memory_inv;

protected:
  int m_value[length_max];
  int m_length;
  int m_loop_start;
  int m_loop_length;

public:
  template <SFINAE_FOR_LOOP_DETECTION_BODY( = nullptr )> inline LoopDetectionBody( const T& init );
  template <typename INT> T IteratedComposition( const INT& n );

  inline const int& GetLength() const noexcept;
  inline const int& GetLoopStart() const noexcept;
  inline const int& GetLoopLength() const noexcept;
  void SearchLoopStart();
  
private:
  inline void SetInit();
  virtual T e( const int& i );
  virtual int e_inv( const T& t );
  virtual void SetValue( const int& i );

};

template <int f(const int&) , int length_max>
class LoopDetection :
  public LoopDetectionBody<int,int,f,length_max>
{

private:
  int m_value_inv[length_max];
  
public:
  inline LoopDetection( const int& init );

private:
  inline int e( const int& i );
  inline int e_inv( const int& t );
  void SetValue( const int& i );

};

template <typename T , typename U , U f(const T&) , int length_max>
class MemorisationLoopDetection :
  public LoopDetectionBody<T,U,f,length_max>
{

public:
  inline MemorisationLoopDetection( const T& init );

};

template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)>
class EnumerationLoopDetection :
  public LoopDetectionBody<T,U,f,length_max>
{

private:
  int m_value_inv[length_max];
  
public:
  inline EnumerationLoopDetection( const T& init );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );
  void SetValue( const int& i );

};

