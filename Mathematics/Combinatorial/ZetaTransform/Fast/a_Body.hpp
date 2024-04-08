// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Fast/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a_Body.hpp"

inline vector<int> SubsetEdge::operator()( const int& t ) const
{

  assert( 0 <= t && t <= *m_p_size_minus );
  vector<int> sub( 1 << __builtin_popcount( t ) , t );
  int s = t , power = 1;
  
  while( s > 0 ){

    const int lsb = s & ~s;

    for( int i = 0 ; i < power ; i++ ){

      sub[i | power] = sub[i] ^ lsb;

    }

    s ^= lsb; power <<= 1;

  }
  
  return sub;

}

inline vector<int> SupsetEdge::operator()( const int& t ) const
{

  assert( 0 <= t && t <= *m_p_size_minus );
  vector<int> sup( *m_p_size_minus >> __builtin_popcount( t ) , t );
  int s = ( ~t ) & *m_p_size_minus , power = 1;
  
  while( s > 0 ){

    const int lsb = s & ~s;

    for( int i = 0 ; i < power ; i++ ){

      sup[i | power] = sup[i] | lsb;

    }

    s ^= lsb; power <<= 1;

  }

  return sup;

}

template <typename U , typename Z_ALG> inline AbstractFastZetaTransform<U,Z_ALG>::AbstractFastZetaTransform( Z_ALG R , const int& digit ) : VirtualZetaTransform<int,Graph<SubsetEdge>,Graph<SupsetEdge>,U,Z_ALG>( Graph( 1 << digit , SubsetEdge() ) , Graph( 1 << digit , SupsetEdge() ) , move( R ) ) , m_digit( digit ) , m_size_minus( this->m_G.size() - 1 ) { this->m_G.edge().m_p_size_minus = this->m_G_inv.edge().m_p_size_minus = &m_size_minus; }
template <typename U , typename Z_ALG> inline AbstractFastZetaTransform<U,Z_ALG>::AbstractFastZetaTransform( Z_ALG R , vector<U> a , const bool& transformed ) : AbstractFastZetaTransform( move( R ) , a.size() , a , transformed ) {}
template <typename U , typename Z_ALG> inline AbstractFastZetaTransform<U,Z_ALG>::AbstractFastZetaTransform( Z_ALG R , const int& size , vector<U>& a , const bool& transformed ) : VirtualZetaTransform<int,Graph<SubsetEdge>,Graph<SupsetEdge>,U,Z_ALG>( Graph( size , SubsetEdge() ) , Graph( size , SupsetEdge() ) , move( R ) , move( a ) , true ) , m_digit() , m_size_minus( size - 1 )
{

  int power = 1;
  
  while( power < size ){

    m_digit++;
    power <<= 1;

  }

  assert( power == size );
  
  if( ! transformed ){

    power = 1;

    for( int d = 0 ; d < m_digit ; d++ , power <<= 1 ){

      int i = power;

      while( i < size ){

	U& m_val_i = this->m_val[i];
	m_val_i = this->m_R.Sum( move( m_val_i ) , this->m_val[i ^ power] );
	( ++i ) |= power;
      
      }

    }

  }
  
}

template <typename U> template <typename...Args> inline FastZetaTransform<U>::FastZetaTransform( const U& one , Args&&... args ) : AbstractFastZetaTransform<U,Algebra<int,U>>( Algebra<int,U>( one ) , forward<Args>( args )... ) {}

template <typename U , typename Z_ALG>
vector<U> AbstractFastZetaTransform<U,Z_ALG>::TotalGet()
{

  const int& size = this->m_G.size();
  auto answer = this->m_val;

  int power = 1;

  for( int d = 0 ; d < m_digit ; d++ , power <<= 1 ){

    int i = power;

    while( i < size ){

      U& answer_i = answer[i];
      answer_i = this->m_R.Sum( move( answer_i ) , this->m_R.Inverse( answer[i ^ power] ) );
      ( ++i ) |= power;

    }
      
  }

  return answer;

}

template <typename U , typename Z_ALG> inline int AbstractFastZetaTransform<U,Z_ALG>::Moevius( const int& t0 , const int& t1 ) { return ( __builtin_popcount( t0 ^ t1 ) & 1 ) == 0 ? 1 : -1; }
