// c:/Users/user/Documents/Programming/Utility/Search/LoopDetection/a.hpp

#pragma once

template <typename T, T f(const T&) , int size>
class LoopDetection
{

private:
  int m_length;
  int m_value[size];
  int m_loop_start;
  map<T,int> m_memory;

public:
  inline LoopDetection();
  inline void SetInit( const T& init );
  T IteratedComposition( const int& n );

private:
  virtual T e( const int& i );
  virtual int e_inv( const T& t );
  virtual void SetValue( const Tnt& i );

};

template <typename T, T f(const T&) , int size , T enum_T(const int&) , int enum_T_inv(const T&)>
class LoopDetection :
  public LoopDetection<T,f,size>
{

private:
  int m_value_inv[size];
  
public:
  inline LoopDetection();
  
private:
  T e( const int& i );
  int e_inv( const T& t );
  void SetValue( const int& i );

};

