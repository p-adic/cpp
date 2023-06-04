// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/Doubling/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T , typename U , U f(const T&) , int size_max , int digit>
class DoublingBody
{

private:
  int m_size;
  int m_doubling[digit][size_max];
  
  int m_length;
  map<T,int> m_memory;
  T m_memory_inv[size_max];

public:
  template <SFINAE_FOR_DOUBLING_BODY( = nullptr )> inline DoublingBody( const int& size );

  // n < 2のdigit乗 の場合のみサポート
  template <typename INT> T IteratedComposition( T t , INT n );

private:
  virtual T e( const int& i );
  virtual int e_inv( const T& t );

};

template <int f(const int&) , int size_max , int digit = 64>
class Doubling :
  public DoublingBody<int,int,f,size_max,digit>
{

public:
  inline Doubling( const int& size );
  
private:
  inline int e( const int& i );
  inline int e_inv( const int& t );

};

template <typename T, typename U , U f(const T&) , int size_max , int digit = 64>
class MemorisationDoubling :
  public DoublingBody<T,U,f,size_max,digit>
{

public:
  inline Doubling( const int& size );

};

template <typename T, typename U , U f(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&) , int digit = 64>
class EnumerationDoubling :
  public DoublingBody<T,U,f,size_max,digit>
{

public:
  inline Doubling( const int& size );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};
