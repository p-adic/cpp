// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/FloydWarshall/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/Semirng/MeetSemirng/a_Body.hpp"

template <typename U , typename IDEMPOTENT_SEMIRNG> inline AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::AbstractFloydWarshall( IDEMPOTENT_SEMIRNG R , const vector<vector<U>>& d ) : m_R( move( R ) ) , m_size() , m_p_d() { static_assert( is_same_v<U,inner_t<IDEMPOTENT_SEMIRNG>> ); Initialise( d ); }
template <typename U> inline FloydWarshall<U>::FloydWarshall( U infty_U , const vector<vector<U>>& d ) : AbstractFloydWarshall<U,AdditiveTropicalSemirng<U>>( move( infty_U ) , d ) {}

template <typename U , typename IDEMPOTENT_SEMIRNG> inline void AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::Initialise( const vector<vector<U>>& d ) { m_p_d = ( m_size = d.size() ) == 0 ? nullptr : &d; assert( m_size == 0 || m_size == int( d[0].size() ) ); }

template <typename U , typename IDEMPOTENT_SEMIRNG>
vector<vector<U>> AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::GetDistance()
{

  auto& d = *m_p_d;
  auto answer = d;
  const U& infty = m_R.Infty();

  for( int k = 0 ; k < m_size ; k++ ){

    auto& answer_k = answer[k];

    for( int i = 0 ; i < m_size ; i++ ){

      auto& answer_i = answer[i];
      const U& answer_ik = answer_i[k];
    
      if( i != k && answer_ik != infty ){
	
	for( int j = 0 ; j < m_size ; j++ ){

	  const U& answer_kj = answer_k[j];

	  if( i != j && k != j && answer_kj != infty ){

	    U& answer_ij = answer_i[j];
	    answer_ij = m_R.Meet( move( answer_ij ) , m_R.Product( answer_ik , answer_kj ) );

	  }

	}

      }

    }

  }

  return answer;

}

template <typename U , typename IDEMPOTENT_SEMIRNG>
pair<vector<vector<U>>,vector<vector<int>>> AbstractFloydWarshall<U,IDEMPOTENT_SEMIRNG>::GetPath()
{

  auto& d = *m_p_d;
  auto weight = d;
  auto path = vector( m_size , vector( m_size , -1 ) );
  const U& infty = m_R.Infty();

  for( int k = 0 ; k < m_size ; k++ ){

    auto& weight_k = weight[k];

    for( int i = 0 ; i < m_size ; i++ ){

      auto& weight_i = weight[i];
      auto& path_i = path[i];
      const U& weight_ik = weight_i[k];
    
      if( i != k && weight_ik != infty ){
	
	for( int j = 0 ; j < m_size ; j++ ){

	  const U& weight_kj = weight_k[j];

	  if( i != j && k != j && weight_kj != infty ){

	    U& weight_ij = weight_i[j];
	    U weight_curr = m_R.Product( weight_ik , weight_kj );

	    if( weight_ij > weight_curr ){

	      weight_ij = move( weight_curr );
	      path_i[j] = k;

	    }

	  }

	}

      }

    }

  }

  return { move( weight ) , move( path ) };

}
