// c:/Users/user/Documents/Programming/Mathematics/Function/MaxLinearFunction/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline MaxLinearFunction<INT>::MaxLinearFunction( const INT& llim_c , const INT& ulim_c , const INT& a , const INT& b ) : m_abc() , m_ca() , m_llim_c( llim_c ) , m_ulim_c( ulim_c ) { static_assert( !is_same<INT,int>::value ); assert( m_llim_c <= m_ulim_c ); m_abc[a] = { b , m_llim_c }; m_ca[m_llim_c] = a; }
template <typename INT> inline MinLinearFunction<INT>::MinLinearFunction( const INT& llim_c , const INT& ulim_c , const INT& a , const INT& b ) : MaxLinearFunction<INT>( llim_c , ulim_c , a , b ) { static_assert( !is_same<INT,unsigned int>::value && !is_same<INT,unsigned long long>::value ); }

template <typename INT>
void MaxLinearFunction<INT>::SetMax( const INT& a , const INT& b )
{

  assert( !m_abc.empty() );
  auto itr_right = m_abc.lower_bound( a ) , begin = m_abc.begin();
  const auto end = m_abc.end();

  if( itr_right != end ){

    const INT& a0 = itr_right->first;
    const auto& [b0,c0] = itr_right->second;

    if( a == a0 ){

      if( b <= b0 ){

	return;
	
      }
      
      m_ca.erase( c0 );

      if( itr_right == begin ){

	begin++;

      }
	
      itr_right = m_abc.erase( itr_right );

    }

  }

  auto itr_left = itr_right;

  if( itr_left == begin ){

    const INT& a0 = itr_left->first;
    const auto& [b0,c0] = itr_left->second;

    if( m_llim_c >= Intersection( a , b , a0 , b0 ) ){

      return;

    }

    itr_left = end;

  } else if( itr_left == end ){

    itr_left = m_abc.lower_bound( m_abc.rbegin()->first );
    const INT& a0 = itr_left->first;
    const auto& [b0,c0] = itr_left->second;

    if( Intersection( a0 , b0 , a , b ) >= m_ulim_c ){

      return;

    }

  } else {

    --itr_left;
    const INT& a0 = itr_left->first;
    const auto& [b0,c0] = itr_left->second;
    const INT& a1 = itr_right->first;
    const auto& [b1,c1] = itr_right->second;

    if( Intersection( a0 , b0 , a , b ) >= Intersection( a , b , a1 , b1 ) ){

      return;

    }

  }

  if( itr_right != end ){

    while( true ){

      const auto itr_right_copy = itr_right++;
      const INT& a0 = itr_right_copy->first;
      auto& [b0,c0] = itr_right_copy->second;
      m_ca.erase( c0 );
      c0 = Intersection( a , b , a0 , b0 );

      if( itr_right == end || c0 < itr_right->second.second ){

	m_ca[c0] = a0;
	break;
	
      }
	
      m_abc.erase( itr_right_copy );

    }

  }

  INT c = m_llim_c;

  if( itr_left != end ){

    while( true ){

      const INT& a1 = itr_left->first;
      const auto& [b1,c1] = itr_left->second;

      if( c1 < ( c = Intersection( a1 , b1 , a , b ) ) ){

	break;
	
      }

      m_ca.erase( c1 );

      if( itr_left == begin ){

	m_abc.erase( itr_left );
	break;

      }
      
      m_abc.erase( itr_left-- );

    }

  }

  m_abc[a] = { b , c = min( max( m_llim_c , c ) , m_ulim_c ) };
  m_ca[c] = a;
  return;

}

template <typename INT>
void MinLinearFunction<INT>::SetMin( const INT& a , const INT& b ) { MaxLinearFunction<INT>::SetMax( -a , -b ); }

template <typename INT>
INT MaxLinearFunction<INT>::Get( const INT& x ) const
{

  assert( !m_abc.empty() );
  assert( m_llim_c <= x && x <= m_ulim_c );
  auto itr_next = m_ca.upper_bound( x );
  const auto& [c,a] = itr_next == m_ca.end() ? *( m_ca.rbegin() ) : *( --itr_next );
  auto itr = m_abc.lower_bound( a );
  const INT& a1 = itr->first;
  const auto& [b1,c1] = itr->second;
  return a1 * x + b1;
  
}

template <typename INT>
INT MinLinearFunction<INT>::Get( const INT& x ) const { return -MaxLinearFunction<INT>( x ); }

template <typename INT> inline INT MaxLinearFunction<INT>::Intersection( const INT& a0 , const INT& b0 , const INT& a1 , const INT& b1 ) { const INT diff_a = a1 - a0; assert( diff_a > 0 ); return ( b0 - b1 + diff_a - 1 ) / diff_a; }

