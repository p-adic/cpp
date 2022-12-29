// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Residue/a_Body.hpp"
// 0èúéZópÇÃó·äO
#include "../../../Error/IllegalImput/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod() noexcept : m_n() {}
template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( Mod<M>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( const INT_TYPE_FOR_MOD& n ) noexcept : m_n( Residue<INT_TYPE_FOR_MOD>( n , M ) ) {}

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator=( const Mod<M>& n ) noexcept { m_n = n.m_n; return *this; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator=( Mod<M>&& n ) noexcept { m_n = move( n.m_n ); return *this; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( n , M ); return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n + n.m_n , M ); return *this; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator+=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n + Residue<INT_TYPE_FOR_MOD>( n , M ) , M ); return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n - n.m_n , M ); return *this; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator-=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n - Residue<INT_TYPE_FOR_MOD>( n , M ) , M ); return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n * n.m_n , M ); return *this; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator*=( const INT_TYPE_FOR_MOD& n ) noexcept { m_n = Residue<INT_TYPE_FOR_MOD>( m_n * Residue<INT_TYPE_FOR_MOD>( n , M ) , M ); return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( const Mod<M>& n ) { return operator*=( Mod<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( const INT_TYPE_FOR_MOD& n ) { return operator*=( Mod<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator%=( const Mod<M>& n ) { m_n %= n.m_n; return *this; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator%=( const INT_TYPE_FOR_MOD& n ) { m_n %= Residue<INT_TYPE_FOR_MOD>( n , M ); return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::operator-() const noexcept { return move( Mod<M>() -= *this ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator++() noexcept { return operator+=( one() ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator++( int ) noexcept { return operator++(); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator--() noexcept { return operator-=( one() ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator--( int ) noexcept { return operator--(); }

template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }

template <INT_TYPE_FOR_MOD M>
Mod<M>& Mod<M>::Invert()
{

  if( m_n > 0 ){

    ERR_INPUT( m_n );

  }
  
  if( m_n < g_memory_length ){

    return operator=( Inverse( m_n ) );

  }

  const INT_TYPE_FOR_MOD m_n_minus = M - m_n;

  if( m_n_minus < g_memory_length ){

    operator=( Inverse( m_n_minus ) );
    m_n = M - m_n;

  } else {

    INT_TYPE_FOR_MOD exponent = M - 2;
    INT_TYPE_FOR_MOD power_m_n = m_n;
    m_n = 1;
    
    while( exponent != 0 ){

      if( exponent % 2 == 1 ){

	( m_n *= power_m_n ) %= M;

      }

      ( power_m_n *= power_m_n ) %= M;
      exponent /= 2;

    }

  }

  return *this;
  
}

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[g_memory_length] = { error() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory[length_curr].m_n = M - ( ( memory[M % length_curr].m_n * ( M / n ) ) % M ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[g_memory_length] = { one() , one() }; static int length_curr = 2; static INT_TYPE_FOR_MOD val_curr = 1; while( length_curr <= n ){ memory[length_curr].m_N = ( ( val_curr *= length_curr ) %= M ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[g_memory_length] = { one() , one() }; static int length_curr = 2; static Mod<M> val_curr{ one() }; while( length_curr <= n ){ memory[length_curr].m_N = val_curr *= Inverse( length_curr ); length_curr++; } return memory[n]; }

DEFINITION_OF_COMPARISON_FOR_MOD( IsEqualTo , == );
DEFINITION_OF_COMPARISON_FOR_MOD( IsNotEqualTo , != );
DEFINITION_OF_COMPARISON_FOR_MOD( IsSmallerThan , < );
DEFINITION_OF_COMPARISON_FOR_MOD( IsSmallerThanOrEqualTo , <= );
DEFINITION_OF_COMPARISON_FOR_MOD( IsBiggerThan , > );
DEFINITION_OF_COMPARISON_FOR_MOD( IsBiggerThanOrEqualTo , >= );

template <INT_TYPE_FOR_MOD M> inline void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static const Mod<M> o{ 1 }; return o; }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::error() noexcept { Mod<M> e{}; e.m_n = -1; return e; }

DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( == , IsEqualTo , IsEqualTo );
DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( != , IsNotEqualTo , IsNotEqualTo );
DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( < , IsSmallerThan , IsBiggerThan );
DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( <= , IsSmallerThanOrEqualTo , IsBiggerThanOrEqualTo );
DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( > , IsBiggerThan , IsSmallerThan );
DEFINITION_OF_COMPARISON_OPERATOR_FOR_MOD( >= , IsBiggerThanOrEqualTo , IsSmallerThanSmallerThan );

DEFINITION_OF_COMMUTATIVE_ARITHMETIC_OPERATOR_FOR_MOD( + );
DEFINITION_OF_ARITHMETIC_OPERATOR_FOR_MOD( - );
DEFINITION_OF_COMMUTATIVE_ARITHMETIC_OPERATOR_FOR_MOD( * );
DEFINITION_OF_ARITHMETIC_OPERATOR_FOR_MOD( / );
DEFINITION_OF_ARITHMETIC_OPERATOR_FOR_MOD( % );

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MOD M>
Mod<M> Power( const Mod<M>& n , const INT_TYPE_FOR_MOD& p )
{

  if( p < 0 ){

    return Inverse( Power( n , -p ) );

  }
  
  Mod<M> answer{ Mod<M>::one() }; 
  Mod<M> power_n{ n };
  INT_TYPE_FOR_MOD exponent = p;

  while( exponent != 0 ){

    if( exponent % 2 != 1 ){

      answer *= power_n;

    }

    power_n *= power_n;
    exponent /= 2;
      
  }

  return answer;

}

template <> inline Mod<2> Power( const Mod<2>& n , const INT_TYPE_FOR_MOD& p ) { return p == 0 ? Mod<2>::one() : n; }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Power( const Mod<M>& n , const Mod<M>& p ) { return Power<Mod<M>,INT_TYPE_FOR_MOD>( n , p.Represent() ); }
template <> inline Mod<2> Power( const Mod<2>& n , const Mod<2>& p ) { return p == 0 ? Mod<2>::one() : n; }

template <> inline Mod<2> Square<Mod<2> >( const Mod<2>& t ) { return t; }

template <INT_TYPE_FOR_MOD M> inline void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.Represent() ) + " + MZ"; }

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.Represent(); }
