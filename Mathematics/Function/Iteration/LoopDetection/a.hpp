// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T , typename U , U f(const T&) , int length_max>
class LoopDetectionBody
{

private:
  int m_length;
  int m_value[length_max];
  int m_loop_start;
  map<T,int> m_memory;

public:
  template <SFINAE_FOR_LOOP_DETECTION_BODY( = nullptr )> inline LoopDetection();
  inline void SetInit( const T& init );
  template <typename INT> T IteratedComposition( const INT& n );

private:
  virtual T e( const int& i );
  virtual int e_inv( const T& t );
  virtual void SetValue( const Tnt& i );

};

template <typename T , typename U , U f(const T&) , int length_max>
class LoopDetection :
  public LoopDetectionBody<T,U,f,length_max>
{

public:
  inline LoopDetection();

};

template <int f(const int&) , int length_max>
class LoopDetection :
  public LoopDetectionBody<int,int,f,length_max>
{

private:
  int m_value_inv[length_max];
  
public:
  inline LoopDetection();

private:
  inline T e( const int& i );
  inline int e_inv( const T& t );
  void SetValue( const Tnt& i );

};

template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)>
class LoopDetection :
  public LoopDetectionBody<T,U,f,length_max>
{

private:
  int m_value_inv[length_max];
  
public:
  inline LoopDetection();
  
private:
  inline T e( const int& i );
  inline int e_inv( const T& t );
  void SetValue( const int& i );

};

