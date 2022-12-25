// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Residue/a_Body.hpp"
#include "VLArray/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod() noexcept : m_n( 0 ) , m_inv( M ){}

template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( const INT_TYPE_FOR_MOD& n ) noexcept : m_n( Residue<INT_TYPE_FOR_MOD>( n , M ) ) , m_inv( 0 ){}

template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) , m_inv( n.m_inv ){}

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( n , M ); m_inv = 0; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator=( const Mod<M>& n ) noexcept { m_n = n.m_n; m_inv = n.m_inv; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator+=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n + Residue<INT_TYPE_FOR_MOD>( n , M ) , M ); m_inv = 0; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n + n.m_n , M ); m_inv = 0; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator-=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n - Residue<INT_TYPE_FOR_MOD>( n , M ) , M ); m_inv = 0; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n - n.m_n , M ); m_inv = 0; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator*=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n * Residue<INT_TYPE_FOR_MOD>( n , M ) , M ); m_inv = 0; return *this; }

 template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n * n.m_n , M ); m_inv = ( m_inv == M || n.m_inv == M ) ? M : Residue<INT_TYPE_FOR_MOD>( m_inv * n.m_inv , M ); return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( const INT_TYPE_FOR_MOD& n ) { return operator/=( Mod<M>( n ) ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( const Mod<M>& n ) { return operator*=( Inverse( n ) ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator%=( const INT_TYPE_FOR_MOD& n ) { m_n %= Residue<INT_TYPE_FOR_MOD>( n , M ); m_inv = 0; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator%=( const Mod<M>& n ) { m_n %= n.m_n; m_inv = 0; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::operator-() const noexcept { return Mod<M>( 0 ).operator-=( *this ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator++() noexcept { return operator+=( 1 ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator++( int ) noexcept { return operator++(); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator--() noexcept { return operator-=( 1 ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator--( int ) noexcept { return operator--(); }

template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }

template <INT_TYPE_FOR_MOD M>
void Mod<M>::Invert() noexcept
{

  if( CheckInvertible() ){

    INT_TYPE_FOR_MOD i = m_inv;
    m_inv = m_n;
    m_n = i;

  } else {

    // m_nがMになるのはここの処理に限るのでRepresent()の値を参照することで例外処理可能
    m_n = M;
    m_inv = M;

  }

  return;
  
}

template <INT_TYPE_FOR_MOD M>
bool Mod<M>::CheckInvertible() noexcept
{

  if( m_inv == 0 ){

    LazyEvaluationOfModularInverse( M , m_n , m_inv );

  }

  return m_inv != M;
  
}

template <INT_TYPE_FOR_MOD M> inline bool Mod<M>::IsSmallerThan( const INT_TYPE_FOR_MOD& n ) const noexcept { return m_n < Residue<INT_TYPE_FOR_MOD>( n , M ); }
template <INT_TYPE_FOR_MOD M> inline bool Mod<M>::IsBiggerThan( const INT_TYPE_FOR_MOD& n ) const noexcept { return m_n > Residue<INT_TYPE_FOR_MOD>( n , M ); }

template <INT_TYPE_FOR_MOD M> inline void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); std::swap( m_inv , n.m_inv ); }

template <INT_TYPE_FOR_MOD M> inline bool operator==( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0 == Mod<M>( n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator==( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return Mod<M>( n0 ) == n0; }
template <INT_TYPE_FOR_MOD M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0.Represent() == n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline bool operator!=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return !( n0 == n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator!=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return !( n0 == n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n0 == n1 ); }

template <INT_TYPE_FOR_MOD M> inline bool operator<( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0.IsSmallerThan( n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1.IsBiggerThan( n0 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0.Represent() < n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline bool operator<=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return !( n1 < n0 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return !( n1 < n0 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n1 < n0 ); }

template <INT_TYPE_FOR_MOD M> inline bool operator>( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n1 < n0; }
template <INT_TYPE_FOR_MOD M> inline bool operator>( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1 < n0; }
template <INT_TYPE_FOR_MOD M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n1 < n0; }

template <INT_TYPE_FOR_MOD M> inline bool operator>=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return !( n0 < n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator>=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 ); }
template <INT_TYPE_FOR_MOD M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return !( n0 < n1 ); }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator+( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept
{

  auto n = n0;
  n += n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator+( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1 + n0; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator+( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0 + n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator-( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0 + ( -n1 ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator-( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return Mod<M>( n0 - n1.Represent() ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator-( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept { return n0 - n1.Represent(); }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator*( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept
{

  auto n = n0;
  n *= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator*( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept { return n1 * n0; }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator*( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept
{

  auto n = n0;
  n *= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator/( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) { return n0 / Mod<M>( n1 ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator/( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) { return Mod<M>( n0 ) / n1; }

template <INT_TYPE_FOR_MOD M>
Mod<M> operator/( const Mod<M>& n0 , const Mod<M>& n1 )
{

  auto n = n0;
  n /= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M>
Mod<M> operator%( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 )
{

  auto n = n0;
  n %= n1;
  return n;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator%( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) { return Mod<M>( n0 ) % n1.Represent(); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> operator%( const Mod<M>& n0 , const Mod<M>& n1 ) { return n0 % n1.Represent(); }

template <INT_TYPE_FOR_MOD M>
Mod<M> Inverse( const Mod<M>& n )
{

  auto n_copy = n;
  n_copy.Invert();
  return n_copy;

}

template <INT_TYPE_FOR_MOD M>
Mod<M> Power( const Mod<M>& n , const INT_TYPE_FOR_MOD& p , const string& method )
{

  if( p >= 0 ){

    return Power<Mod<M>,INT_TYPE_FOR_MOD>( n , p , 1 , true , true , method );

  }

  return Inverse( Power<M>( n , -p , method ) );

}

template <> inline Mod<2> Power( const Mod<2>& n , const INT_TYPE_FOR_MOD& p , const string& method ) { return p == 0 ? 1 : n; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Power( const Mod<M>& n , const Mod<M>& p , const string& method ) { return Power<Mod<M>,INT_TYPE_FOR_MOD>( n , p.Represent() , method ); }

template <> inline Mod<2> Power( const Mod<2>& n , const Mod<2>& p , const string& method ) { return p == 0 ? 1 : n; }

template <> inline Mod<2> Square<Mod<2> >( const Mod<2>& t ) { return t; }

template <INT_TYPE_FOR_MOD M> inline void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.Represent() ) + " + MZ"; }

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.Represent(); }
