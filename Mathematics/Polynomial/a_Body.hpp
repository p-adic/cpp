// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline Polynomial<T>::Polynomial() : m_f() , m_size( 0 ) , m_no_redundant_zero( true ) {}
template <typename T> inline Polynomial<T>::Polynomial( const T& t ) : Polynomial() { if( t != const_zero() ){ operator[]( 0 ) = t; } }
template <typename T> inline Polynomial<T>::Polynomial( const Polynomial<T>& f ) : m_f( f.m_f ) , m_size( f.m_size ) , m_no_redundant_zero( f.m_no_redundant_zero ) {}
template <typename T> inline Polynomial<T>::Polynomial( const uint& i , const T& t ) : Polynomial() { if( t != const_zero() ){ operator[]( i ) = t; } }


template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( const T& t ) { m_f.clear(); m_size = 0; operator[]( 0 ) = t; return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( const Polynomial<T>& f ) { m_f = f.m_f; m_size = f.m_size; m_no_redundant_zero = f.m_no_redundant_zero; return *this; }


template <typename T>
const T& Polynomial<T>::operator[]( const uint& i ) const
{

  if( m_size <= i ){

    return const_zero();

  }
  
  return m_f[i];

}

template <typename T> inline T& Polynomial<T>::operator[]( const uint& i )
{

  m_no_redundant_zero = false;
  const T& z = const_zero();

  while( m_size <= i ){

    m_f.push_back( z );
    m_size++;
    
  }

  return m_f[i];

}

template <typename T> inline Polynomial<T>& Polynomial<T>::operator+=( const T& t ) { operator[]( 0 ) += t; return *this; }

template <typename T>
Polynomial<T>& Polynomial<T>::operator+=( const Polynomial<T>& f )
{

  for( uint i = 0 ; i < f.m_size ; i++ ){

    operator[]( i ) += f.m_f[i];

  }

  return *this;

}

template <typename T> inline Polynomial<T>& Polynomial<T>::operator-=( const T& t ) { operator[]( 0 ) -= t; return *this; }

template <typename T>
Polynomial<T>& Polynomial<T>::operator-=( const Polynomial<T>& f )
{

  for( uint i = 0 ; i < f.m_size ; i++ ){

    operator[]( i ) -= f.m_f[i];

  }

  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator*=( const T& t )
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  if( m_size == 0 || t == const_one() ){

    return *this;

  }

  if( t == const_zero() ){

    return operator=( zero() );

  }
  
  for( uint i = 0 ; i < m_size ; i++ ){

    operator[]( i ) *= t;

  }

  // Tが体である場合は省略可能
  RemoveRedundantZero();
  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator*=( const Polynomial<T>& f )
{
  
  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  if( m_size == 0 ){

    return *this;

  }

  if( f.m_size == 0 ){

    return operator=( zero() );

  }
  
  const uint size = m_size + f.m_size - 1;
  Polynomial<T> product{};  
      
  for( uint i = 0 ; i < size ; i++ ){

    T& product_i = product[i];
    const uint j_min = m_size <= i ? i - m_size + 1 : 0;
    const uint j_lim = i < f.m_size ? i + 1 : f.m_size;
      
    for( uint j = j_min ; j < j_lim ; j++ ){
	
      product_i += m_f[i - j] * f.m_f[j];

    }

  }

  product.RemoveRedundantZero();
  return operator=( product );

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator/=( const T& t )
{
  
  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }
  
  for( uint i = 0 ; i < m_size ; i++ ){

    operator[]( i ) /= t;

  }

  // Tが体である場合は省略可能
  RemoveRedundantZero();
  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator%=( const T& t )
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }

  for( uint i = 0 ; i < m_size ; i++ ){

    operator[]( i ) %= t;

  }

  RemoveRedundantZero();
  return *this;

}

template <typename T> inline const uint& Polynomial<T>::size() const noexcept { return m_size; }

template <typename T>
void Polynomial<T>::RemoveRedundantZero()
{

  if( m_no_redundant_zero ){
    
    return;

  }
  
  const T& z = const_zero();
  
  while( m_size > 0 ? m_f[m_size - 1] == z : false ){

    m_f.pop_back();
    m_size--;

  }

  m_no_redundant_zero = true;
  return;

}

template <typename T>
void Polynomial<T>::RecursivelyRemoveRedundantZero()
{

  if( ! m_no_redundant_zero ){
    
    RemoveRedundantZero();

  }
  
  for( uint i = 0 ; i < m_size ; i++ ){

    m_f[i].RecursivelyRemoveRedundantZero();
    
  }

  return;

}

template <typename T>
string Polynomial<T>::Display() const noexcept
{

  string s = "(";

  if( m_size > 0 ){

    s += to_string( m_f[0] );

    for( uint i = 1 ; i < m_size ; i++ ){

      s += "," + to_string( m_f[i] );

    }

  }

  s += ")";
  return s;

}


template <typename T> inline const Polynomial<T>& Polynomial<T>::zero() { static const Polynomial<T> z{}; return z; }


template <typename T>
bool operator==( const Polynomial<T>& f0 , const T& t1 )
{

  const uint& size = f0.size();
  const T& zero = const_zero();

  for( uint i = 1 ; i < size ; i++ ){

    if( f0[i] != zero ){

      return false;

    }

  }

  return f0[0] == t1;

}

template <typename T>
bool operator==( const Polynomial<T>& f0 , const Polynomial<T>& f1 )
{

  const uint& size0 = f0.size();
  const uint& size1 = f1.size();
  const uint& size = size0 < size1 ? size1 : size0;

  for( uint i = 0 ; i < size ; i++ ){

    if( f0[i] != f1[i] ){

      return false;

    }

  }

  return true;

}

template <typename T , typename P> inline bool operator!=( const Polynomial<T>& f0 , const P& f1 ) { return !( f0 == f1 ); }

template <typename T , typename P> inline Polynomial<T> operator+( const Polynomial<T>& f0 , const P& f1 ) { Polynomial<T> f = f0; f += f1; return f; }
template <typename T , typename P> inline Polynomial<T> operator-( const Polynomial<T>& f0 , const P& f1 ) { Polynomial<T> f = f0; f -= f1; return f; }
template <typename T , typename P> inline Polynomial<T> operator*( const Polynomial<T>& f0 , const P& f1 ) { Polynomial<T> f = f0; f *= f1; return f; }
template <typename T> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const T& t1 ) { Polynomial<T> f = f0; f /= t1; return f; }
template <typename T> inline Polynomial<T> operator%( const Polynomial<T>& f0 , const T& t1 ) { Polynomial<T> f = f0; f %= t1; return f; }
