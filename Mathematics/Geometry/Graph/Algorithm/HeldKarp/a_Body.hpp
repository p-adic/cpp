// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HeldKarp/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../../Algebra/Monoid/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename COMM_MONOID> inline AbstractHeldKarp<T,GRAPH,U,COMM_MONOID>::AbstractHeldKarp( GRAPH& G , COMM_MONOID M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) { static_assert( is_same_v<T,inner_t<GRAPH>> ); }
template <typename T , typename GRAPH> inline HeldKarp<T,GRAPH>::HeldKarp( GRAPH& G , const ll& infty ) : AbstractHeldKarp<T,GRAPH,ll,AdditiveMonoid<ll>>( G , AdditiveMonoid<ll>() , infty ) {}

template <typename T , typename GRAPH , typename U , typename COMM_MONOID> inline U AbstractHeldKarp<T,GRAPH,U,COMM_MONOID>::GetDistance( const T& t_start , const vector<T>& t_factor , const T& t_final , const bool& revisitable ) { return move( GetDistance( t_start , t_factor , revisitable )[m_G.Enumeration_inv( t_final )] ); }

template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
vector<U> AbstractHeldKarp<T,GRAPH,U,COMM_MONOID>::GetDistance( const T& t_start , const vector<T>& t_factor , const bool& revisitable )
{

  const int& size = m_G.size();
  const int& factor_size = t_factor.size();
  assert( factor_size < 30 );
  vector<int> t_factor_inv( size , -1 );

  for( int i = 0 ; i < factor_size ; i++ ){

    assert( t_factor_inv[t_factor[i]] == -1 );
    t_factor_inv[t_factor[i]] = i;

  }

  const int power = 1 << factor_size;
  const U& infty = this->Infty();
  vector dp( power , vector<U>( size , infty ) );
  auto&& i_start = m_G.Enumeration_inv( t_start );
  dp[t_factor_inv[i_start] == -1 ? 0 : 1 << t_factor_inv[i_start]][i_start] = m_M.One();

  for( int S = 0 ; S < power ; S++ ){

    for( int i = 0 ; i < size ; i++ ){

      if( dp[S][i] < infty ){
        
        for( auto& [t,w] : m_G.Edge( m_G.Enumeration( i ) ) ){

          auto&& j = m_G.Enumeration_inv( t );
          auto&& k = t_factor_inv[j];

          if( revisitable || k == -1 || ( ( S >> k ) & 1 ) == 0 ){

            const int S_sup = S | ( k == -1 ? 0 : ( 1 << k ) );
            dp[S_sup][j] = min( move( dp[S_sup][j] ) , m_M.Product( dp[S][i] , w ) );

          }

        }

      }

    }

  }

  vector<U> weight( size , infty );

  for( int i = 0 ; i < size ; i++ ){

    weight[i] = dp[power - 1][i];

  }
  
  return weight;

}
