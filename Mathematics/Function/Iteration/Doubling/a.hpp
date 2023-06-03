// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/Doubling/a.hpp

#pragma once

template <typename T, T f(const T&) , int size_max , int digit = 64>
class DoublingBody
{

private:
  int m_size;
  int m_doubling[digit][size_max];
  
  int m_length;
  map<T,int> m_memory;
  T m_memory_inv[size];

public:
  inline DoublingBody( const int& size );

  // n < 2のdigit乗 の場合のみサポート
  T IteratedComposition( T t , int n );

private:
  virtual T e( const int& i );
  virtual int e_inv( const T& t );

};

template <typename T, T f(const T&) , int size_max , int digit = 64>
class Doubling :
  public DoublingBody<T,f,size_max,digit>
{

public:
  inline Doubling( const int& size );

};

template <int f(const int&) , int size_max , int digit = 64>
class Doubling :
  public DoublingBody<int,f,size_max,digit>
{

public:
  inline Doubling( const int& size );
  
private:
  inline int e( const int& i );
  inline int e_inv( const int& t );

};

template <typename T, T f(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&) , int digit = 64>
class Doubling :
  public DoublingBody<T,f,size_max,digit>
{

public:
  inline Doubling( const int& size );
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};

