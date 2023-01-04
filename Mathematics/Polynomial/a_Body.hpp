// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Body.hpp

#pragma once
#include "a.hpp"

#include "TruncatedPolynomial/a_Body.hpp"

template <typename T> inline Polynomial<T>::Polynomial() : m_f() , m_size( 0 ) {}
template <typename T> inline Polynomial<T>::Polynomial( const T& t ) : Polynomial() { if( t != const_zero() ){ operator[]( 0 ) = t; } }
template <typename T> inline Polynomial<T>::Polynomial( T&& t ) : Polynomial() { if( t != const_zero() ){ operator[]( 0 ) = move( t ); } }
template <typename T> template <SFINAE_FOR_POLYNOMIAL()> inline Polynomial<T>::Polynomial( const Arg& n ) : Polynomial( T( n ) ) {}
template <typename T> inline Polynomial<T>::Polynomial( const Polynomial<T>& f ) : m_f( f.m_f ) , m_size( f.m_size ) {}
template <typename T> inline Polynomial<T>::Polynomial( Polynomial<T>&& f ) : m_f( move( f.m_f ) ) , m_size( move( f.m_size ) ) {}
template <typename T> inline Polynomial<T>::Polynomial( const uint& i , const T& t ) : Polynomial() { if( t != const_zero() ){ operator[]( i ) = t; } }
template <typename T> inline Polynomial<T>::Polynomial( const uint& i , T&& t ) : Polynomial() { if( t != const_zero() ){ operator[]( i ) = move( t ); } }
template <typename T> template <SFINAE_FOR_POLYNOMIAL()> inline Polynomial<T>::Polynomial( const uint& i , const Arg& n ) : Polynomial( i , T( n ) ) {}
template <typename T> inline Polynomial<T>::Polynomial( const vector<T>& f ) : m_f( f ) , m_size( m_f.size() ) {}
template <typename T> inline Polynomial<T>::Polynomial( vector<T>&& f ) : m_f( move( f ) ) , m_size( m_f.size() ) {}


template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( const T& t ) { m_f.clear(); m_size = 0; operator[]( 0 ) = t; return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( T&& t ) { m_f.clear(); m_size = 0; operator[]( 0 ) = move( t ); return *this; }
template <typename T> template <SFINAE_FOR_POLYNOMIAL()> inline Polynomial<T>& Polynomial<T>::operator=( const Arg& n ) { return operator=( T( n ) ); }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( const Polynomial<T>& f ) { m_f = f.m_f; m_size = f.m_size; return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( Polynomial<T>&& f ) { m_f = move( f.m_f ); m_size = move( f.m_size ); return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( const vector<T>& f ) { m_f = f; m_size = f.m_size; return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( vector<T>&& f ) { m_f = move( f ); m_size = m_f.size(); return *this; }


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

  if( m_size <= i ){
    
    const T& z = const_zero();

    while( m_size <= i ){

      m_f.push_back( z );
      m_size++;
    
    }

  }

  return m_f[i];

}

template <typename T> inline T Polynomial<T>::operator()( const T& t ) const { return move( ( *this % ( Polynomial<T>( 1 , const_one() ) - t ) )[0] ); }

template <typename T>
Polynomial<T>& Polynomial<T>::operator+=( const Polynomial<T>& f )
{

  for( uint i = 0 ; i < f.m_size ; i++ ){

    operator[]( i ) += f.m_f[i];

  }

  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator-=( const Polynomial<T>& f )
{

  for( uint i = 0 ; i < f.m_size ; i++ ){

    operator[]( i ) -= f.m_f[i];

  }

  return *this;

}

DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL( Mod<998244353> );

template <typename T>
Polynomial<T>& Polynomial<T>::operator*=( const Polynomial<T>& f )
{
  
  if( m_size == 0 ){

    return *this;

  }

  if( f.m_size == 0 ){

    m_f.clear();
    m_size = 0;
    return *this;

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

  return operator=( move( product ) );

}

template <typename T> inline Polynomial<T>& Polynomial<T>::operator*=( Polynomial<T>&& f ) { return operator*=( f ); };

template <typename T>
Polynomial<T>& Polynomial<T>::operator/=( const T& t )
{
  
  if( t == const_one() ){

    return *this;

  }

  const T t_inv{ const_one() / t };
  
  for( uint i = 0 ; i < m_size ; i++ ){

    operator[]( i ) *= t_inv;

  }

  return *this;

}

template <typename T> inline Polynomial<T>& Polynomial<T>::operator/=( const Polynomial<T>& f ) { return m_size < f.m_size ? *this : operator=( Quotient( *this , f ) ); }

template <typename T>
Polynomial<T> Polynomial<T>::Quotient( const Polynomial<T>& f0 , const Polynomial<T>& f1 )
{

  if( f0.m_size < f1.m_size ){

    return f0;

  }

  if( f1.m_size == 0 ){

    ERR_IMPUT( f0 , f1 , f1.m_size );

  }

  const uint f0_transpose_size = f0.m_size - f1.m_size + 1;
  const uint f1_transpose_size = f0_transpose_size < f1.m_size ? f0_transpose_size : f1.m_size;
  return TransposeQuotient( f0 , f0_transpose_size , Inverse( TruncatedPolynomial<T>( f0_transpose_size , Transpose( f1 , f1_transpose_size ) ) ) , f1.m_size );

}

template <typename T>
Polynomial<T> Polynomial<T>::TransposeQuotient( const Polynomial<T>& f0 , const uint& f0_transpose_size , const Polynomial<T>& f1_transpose_inverse , const uint& f1_size )
{

  TruncatedPolynomial<T> f0_transpose{ f0_transpose_size , Transpose( f0 , f0_transpose_size ) };
  f0_transpose *= f1_transpose_inverse;

  for( uint d0 = ( f0_transpose_size + 1 ) / 2 ; d0 < f0_transpose_size ; d0++ ){

    ::swap( f0_transpose.Polynomial<T>::m_f[d0] , f0_transpose.Polynomial<T>::m_f[ f0_transpose_size - 1 - d0 ] );

  }

  return f0_transpose;

}

template <typename T>
Polynomial<T> Polynomial<T>::Transpose( const Polynomial<T>& f , const uint& f_transpose_size )
{

  vector<T> f_transpose( f_transpose_size );

  for( uint d = 0 ; d < f_transpose_size ; d++ ){

    f_transpose[d] = f.m_f[f.m_size - 1 - d];

  }

  return Polynomial<T>( move( f_transpose ) );

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator%=( const T& t )
{

  if( t == const_one() ){

    return operator=( zero() );

  }
  
  for( uint i = 0 ; i < m_size ; i++ ){

    m_f[i] %= t;

  }

  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator%=( const Polynomial<T>& f )
{

  if( m_size >= f.m_size ){

    operator-=( ( *this / f ) * f );
    RemoveRedundantZero();

  }

  return *this;

}

template <typename T> inline Polynomial<T> Polynomial<T>::operator-() const { return move( Polynomial<T>() -= *this ); }


template <typename T >
Polynomial<T>& Polynomial<T>::operator<<=( const T& t )
{

  if( m_size > 0 ){

    for( uint d = 0 ; d < m_size ; d++ ){

      m_f[d] *= T::Factorial( d );

    }

    TruncatedPolynomial<T> exp_t_transpose{ m_size * 2 };
    T power_t = const_one();
  
    for( uint d = 0 ; d < m_size ; d++ ){

      exp_t_transpose[m_size - 1 - d] = power_t * T::FactorialInverse( d );
      power_t *= t;

    }

    exp_t_transpose *= *this;
  
    for( uint d = 0 ; d < m_size ; d++ ){

      m_f[d] = exp_t_transpose.Polynomial<T>::m_f[d + m_size - 1] * T::FactorialInverse( d );

    }

  }

  return *this;

}

template <typename T> inline const vector<T>& Polynomial<T>::GetCoefficient() const noexcept { return m_f; }
template <typename T> inline const uint& Polynomial<T>::size() const noexcept { return m_size; }

template <typename T> inline void Polynomial<T>::swap( Polynomial<T>& f ) { m_f.swap( f.m_f ); swap( m_size , f.m_size ); }
template <typename T> inline void Polynomial<T>::swap( vector<T>& f ) { m_f.swap( f ); m_size = m_f.size(); }


template <typename T>
void Polynomial<T>::RemoveRedundantZero()
{

  const T& z = const_zero();
  
  while( m_size > 0 ? m_f[m_size - 1] == z : false ){

    m_f.pop_back();
    m_size--;

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

      s += ", " + to_string( m_f[i] );

    }

  }

  s += ")";
  return s;

}


template <typename T> inline const Polynomial<T>& Polynomial<T>::zero() { static const Polynomial<T> z{}; return z; }
template <typename T> inline const T& Polynomial<T>::const_zero() { static const T z{ 0 }; return z; }
template <typename T> inline const T& Polynomial<T>::const_one() { static const T o{ 1 }; return o; }
template <typename T> inline const T& Polynomial<T>::const_minus_one() { static const T m{ -1 }; return m; }

template <typename T>
bool operator==( const Polynomial<T>& f0 , const T& t1 )
{

  const uint& size = f0.size();
  const T& zero = Polynomial<T>::const_zero();

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

template <typename T , typename P> inline Polynomial<T> operator+( const Polynomial<T>& f0 , const P& f1 ) { return move( Polynomial<T>( f0 ) += f1 ); }
template <typename T , typename P> inline Polynomial<T> operator-( const Polynomial<T>& f ) { return Polynomial<T>::zero() - f; }
template <typename T , typename P> inline Polynomial<T> operator-( const Polynomial<T>& f0 , const P& f1 ) { return move( Polynomial<T>( f0 ) -= f1 ); }
template <typename T , typename P> inline Polynomial<T> operator*( const Polynomial<T>& f0 , const P& f1 ) { return move( Polynomial<T>( f0 ) *= f1 ); }
template <typename T> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const T& t1 ) { return move( Polynomial<T>( f0 ) /= t1 ); }
template <typename T> inline Polynomial<T> operator/( const Polynomial<T>& f0 , const Polynomial<T>& f1 ) { return Polynomial<T>::Quotient( f0 , f1 ); }
template <typename T , typename P> inline Polynomial<T> operator%( const Polynomial<T>& f0 , const P& f1 ) { return move( Polynomial<T>( f0 ) %= f1 ); }
template <typename T> Polynomial<T> operator<<( const Polynomial<T>& f , const T& t ) { return move( Polynomial<T>( f ) <<= t ); };

template <typename T , template <typename...> typename V>
T& Prod( V<T>& f )
{

  if( f.empty() ){

    f.push_back( T( 1 ) );

  }

  if( f.size() == 1 ){

    return f.front();

  }

  auto itr = f.begin() , end = f.end();
  
  while( itr != end ){

    T& t = *itr;
    itr++;

    if( itr != end ){

      t *= *itr;
      itr = f.erase( itr );
      
    }

  }

  return Prod( f );

}
