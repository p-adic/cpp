// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a.hpp

#pragma once

template <typename T, T f(const T&) , int length_max>
class LoopDetection
{

private:
  int m_length;
  int m_value[length_max];
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

template <typename T, T f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)>
class LoopDetection :
  public LoopDetection<T,f,length_max>
{

private:
  int m_value_inv[length_max];
  
public:
  inline LoopDetection();
  
private:
  T e( const int& i );
  int e_inv( const T& t );
  void SetValue( const int& i );

};

