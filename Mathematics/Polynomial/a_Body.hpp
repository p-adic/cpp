// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Truncate/a_Body.hpp"

template <typename T> inline Polynomial<T>::Polynomial() : m_f() , m_size( 0 ) {}
template <typename T> inline Polynomial<T>::Polynomial( const Polynomial<T>& f ) : m_f( f.m_f ) , m_size( f.m_size ) {}
template <typename T> inline Polynomial<T>::Polynomial( Polynomial<T>&& f ) : m_f( move( f.m_f ) ) , m_size( f.m_size ) {}
template <typename T> inline Polynomial<T>::Polynomial( vector<T> f ) : m_f( move( f ) ) , m_size( m_f.size() ) {}
template <typename T> inline Polynomial<T>::Polynomial( T t ) : Polynomial() { if( t != c_zero() ){ operator[]( 0 ) = move( t ); } }
template <typename T> inline Polynomial<T>::Polynomial( const uint& i , T t ) : Polynomial() { if( t != c_zero() ){ operator[]( i ) = move( t ); } }

template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( T n ) { m_f.clear(); m_size = 0; operator[]( 0 ) = move( n ); return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( Polynomial<T> f ) { m_f = move( f.m_f ); m_size = f.m_size; return *this; }
template <typename T> inline Polynomial<T>& Polynomial<T>::operator=( vector<T> f ) { m_f = move( f ); m_size = m_f.size(); return *this; }

template <typename T> inline const T& Polynomial<T>::operator[]( const uint& i ) const { return m_size <= i ? c_zero() : m_f[i]; }

template <typename T> inline T& Polynomial<T>::operator[]( const uint& i )
{

  if( m_size <= i ){
    
    const T& z = c_zero();

    while( m_size <= i ){

      m_f.push_back( z );
      m_size++;
    
    }

  }

  return m_f[i];

}

template <typename T> inline T Polynomial<T>::operator()( const T& t ) const { return move( ( *this % ( Polynomial<T>( 1 , c_one() ) - t ) )[0] ); }

template <typename T>
Polynomial<T>& Polynomial<T>::operator+=( const Polynomial<T>& f )
{

  if( m_size < f.m_size ){

    m_f.reserve( f.m_size );

    for( uint i = 0 ; i < m_size ; i++ ){

      m_f[i] += f.m_f[i];

    }

    for( uint i = m_size ; i < f.m_size ; i++ ){

      m_f.push_back( f.m_f[i] );

    }

    m_size = f.m_size;

  } else {

    for( uint i = 0 ; i < f.m_size ; i++ ){

      m_f[i] += f.m_f[i];

    }

  }

  return *this;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator-=( const Polynomial<T>& f )
{

  if( m_size < f.m_size ){

    m_f.reserve( f.m_size );

    for( uint i = 0 ; i < m_size ; i++ ){

      m_f[i] -= f.m_f[i];

    }

    for( uint i = m_size ; i < f.m_size ; i++ ){

      m_f.push_back( - f.m_f[i] );

    }

    m_size = f.m_size;

  } else {

    for( uint i = 0 ; i < f.m_size ; i++ ){

      m_f[i] -= f.m_f[i];

    }

  }

  return *this;

}

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
    const uint j_min = m_size > i ? 0 : i - m_size + 1;
    const uint j_lim = i < f.m_size ? i + 1 : f.m_size;
      
    for( uint j = j_min ; j < j_lim ; j++ ){
	
      product_i += m_f[i - j] * f.m_f[j];

    }

  }

  return *this = move( product );

}

template <typename T> inline Polynomial<T>& Polynomial<T>::operator*=( Polynomial<T>&& f ) { return *this *= f; };

template <typename T>
Polynomial<T>& Polynomial<T>::operator/=( const T& t )
{
  
  if( t == c_one() ){

    return *this;

  }

  const T t_inv{ c_one() / t };
  
  for( uint i = 0 ; i < m_size ; i++ ){

    operator[]( i ) *= t_inv;

  }

  return *this;

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

  if( t == c_one() ){

    return *this = zero();

  }
  
  for( uint i = 0 ; i < m_size ; i++ ){

    m_f[i] %= t;

  }

  return *this;

}

template <typename T>
bool Polynomial<T>::operator==( const Polynomial<T>& f ) const
{

  const uint& size0 = size();
  const uint& size1 = f.size();
  const uint& size_max = size0 < size1 ? size1 : size0;

  for( uint i = 0 ; i < size_max ; i++ ){

    if( operator[]( i ) != f[i] ){

      return false;

    }

  }

  return true;

}

template <typename T>
bool Polynomial<T>::operator==( const T& t ) const
{

  const uint& size_max = size();
  const T& zero = Polynomial<T>::c_zero();

  for( uint i = 1 ; i < size_max ; i++ ){

    if( m_f[i] != zero ){

      return false;

    }

  }

  return operator[]( 0 ) == t;

}

template <typename T> template<typename P> inline bool Polynomial<T>::operator!=( const P& f ) const { return !( *this == f ); }

DEFINITION_OF_ARITHMETIC_FOR_POLYNOMIAL( + , f += *this );
template <typename T> inline Polynomial<T>& Polynomial<T>::SignInvert() { RemoveRedundantZero(); for( auto& fi : m_f ){ fi = -fi; } return *this; }
template <typename T> inline Polynomial<T> Polynomial<T>::operator-() const { return move( Polynomial<T>( *this ).SignInvert() ); }
DEFINITION_OF_ARITHMETIC_FOR_POLYNOMIAL( - , f.SignInvert() += *this );
DEFINITION_OF_ARITHMETIC_FOR_POLYNOMIAL( * , f *= *this );
template <typename T> inline Polynomial<T> Polynomial<T>::operator/( const T& t ) const { return move( Polynomial<T>( *this ) /= t ); }
template <typename T> inline Polynomial<T> Polynomial<T>::operator%( const T& t ) const { return move( Polynomial<T>( *this ) %= t ); }

template <typename T> inline const vector<T>& Polynomial<T>::GetCoefficient() const noexcept { return m_f; }
template <typename T> inline const uint& Polynomial<T>::size() const noexcept { return m_size; }
template <typename T> inline void Polynomial<T>::resize( const uint& deg_plus ) noexcept { m_f.resize( m_size = deg_plus ); }

template <typename T> inline void Polynomial<T>::swap( Polynomial<T>& f ) { m_f.swap( f.m_f ); swap( m_size , f.m_size ); }
template <typename T> inline void Polynomial<T>::swap( vector<T>& f ) { m_f.swap( f ); m_size = m_f.size(); }


template <typename T>
void Polynomial<T>::RemoveRedundantZero()
{

  const T& z = c_zero();
  
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
template <typename T> inline const Polynomial<T>& Polynomial<T>::one() { static const Polynomial<T> o{ c_one() }; return o; }
template <typename T> inline const Polynomial<T>& Polynomial<T>::x() { static const Polynomial<T> f{ 1 , c_one() }; return f; }
template <typename T> inline const T& Polynomial<T>::c_zero() { static const T z{ 0 }; return z; }
template <typename T> inline const T& Polynomial<T>::c_one() { static const T o{ 1 }; return o; }
template <typename T> inline const T& Polynomial<T>::c_minus_one() { static const T m{ -1 }; return m; }

template <typename T>
Polynomial<T> Differential( const uint& n , const Polynomial<T>& f )
{

  const uint& size = f.size();

  if( size < n ){

    return Polynomial<T>::zero();

  }

  vector<T> df( size - n );
  T coef = T::Factorial( n );
  uint i = n;

  while( i < size ){

    df[i - n] = f[i] * coef;
    i++;
    ( coef *= i ) /= ( i - n );

  }

  return Polynomial<T>( move( df ) );

}

// à»â∫TruncatedPolynomial<T>ÇégópÅB
template <typename T> inline Polynomial<T>& Polynomial<T>::operator/=( const Polynomial<T>& f ) { return *this = Quotient( *this , f ); }

template <typename T>
Polynomial<T> Polynomial<T>::Quotient( const Polynomial<T>& f0 , const Polynomial<T>& f1 )
{

  assert( f1.m_size == 0 || f1[f1.m_size-1] != c_zero() );
  
  if( f0.m_size < f1.m_size ){

    return Polynomial<T>::zero();

  }

  assert( f1.m_size != 0 );
  const uint f0_transpose_size = f0.m_size - f1.m_size + 1;
  const uint f1_transpose_size = f0_transpose_size < f1.m_size ? f0_transpose_size : f1.m_size;
  const TruncatedPolynomial<T> f1_transpose_inverse = Inverse( TruncatedPolynomial<T>( f0_transpose_size , Transpose( f1 , f1_transpose_size ) ) );
  TruncatedPolynomial<T> f0_transpose{ f0_transpose_size , Transpose( f0 , f0_transpose_size ) };
  f0_transpose *= f1_transpose_inverse;

  for( uint d0 = ( f0_transpose_size + 1 ) / 2 ; d0 < f0_transpose_size ; d0++ ){

    ::swap( f0_transpose[d0] , f0_transpose[ f0_transpose_size - 1 - d0 ] );

  }

  return f0_transpose;

}

template <typename T>
Polynomial<T>& Polynomial<T>::operator%=( const Polynomial<T>& f )
{

  if( m_size >= f.m_size ){

    *this -= ( *this / f ) * f;
    RemoveRedundantZero();

  }

  return *this;

}

template <typename T> inline Polynomial<T> Polynomial<T>::operator/( const Polynomial<T>& f ) const { return Polynomial<T>::Quotient( *this , f ); }
template <typename T> inline Polynomial<T> Polynomial<T>::operator%( const Polynomial<T>& f ) const { return move( Polynomial<T>( *this ) %= f ); }
