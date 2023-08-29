// c:/Users/user/Documents/Programming/Mathematics/Function/MaxLinearFunction/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c> inline MaxLinearFunction<INT,llim_a,ulim_a,llim_b,ulim_b,llim_c,ulim_c>::MaxLinearFunction() : m_abc() , m_ca()
{

  static_assert( ! is_same<INT,int>::value );
  static_assert( llim_a <= ulim_a && llim_b <= ulim_b && llim_c <= ulim_c );
  static_assert( min( min( ulim_a * llim_c , ulim_a * ulim_c ) , min( llim_a * llim_c , llim_a * ulim_c ) ) + llim_b <= max( max( ulim_a * llim_c , ulim_a * ulim_c ) , max( llim_a * llim_c , llim_a * ulim_c ) ) + ulim_b );

}

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c> inline MinLinearFunction<INT,llim_a,ulim_a,llim_b,ulim_b,llim_c,ulim_c>::MinLinearFunction() : MaxLinearFunction<INT,-ulim_a,-llim_a,-ulim_b,-llim_b,llim_c,ulim_c>() { static_assert( ! is_same<INT,unsigned int>::value && ! is_same<INT,unsigned long long>::value ); }

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c>
void MaxLinearFunction<INT,llim_a,ulim_a,llim_b,ulim_b,llim_c,ulim_c>::SetMax( const INT& a , const INT& b )
{

  assert( llim_a <= a && a <= ulim_a );

  if( m_abc.empty() ){

    m_abc[a] = { b , llim_c };
    m_ca[llim_c] = a;
    return;
    
  }
  
  auto itr_right = m_abc.lower_bound( a ) , begin = m_abc.begin();
  const auto end = m_abc.end();

  if( itr_right != end ){

    const INT& a0 = itr_right->first;
    const auto& [b0,c0] = itr_right->second;

    if( a == a0 ){

      if( b < b0 ){

	m_ca.erase( c0 );

	if( itr_right == begin ){

	  begin++;

	}
	
	itr_right = m_abc.erase( itr_right );

      } else {

	return;

      }

    }

  }

  auto itr_left = itr_right;

  if( itr_left == begin ){

    const INT& a0 = itr_left->first;
    const auto& [b0,c0] = itr_left->second;

    if( llim_c >= Intersection( a , b , a0 , b0 ) ){

      return;

    }

    itr_left = end;

  } else if( itr_left == end ){

    itr_left = m_abc.lower_bound( m_abc.rbegin()->first );
    const INT& a0 = itr_left->first;
    const auto& [b0,c0] = itr_left->second;

    if( Intersection( a0 , b0 , a , b ) >= ulim_c ){

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

      if( itr_right == end ){

	m_ca[c0] = a0;
	break;
      
      }

      const auto& [b1,c1] = itr_right->second;

      if( c0 < c1 ){

	m_ca[c0] = a0;
	break;
	
      } else {
	
	m_abc.erase( itr_right_copy );

      }

    }

  }

  INT c;

  if( itr_left == end ){

    c = llim_c;

  } else {

    while( true ){

      const INT& a1 = itr_left->first;
      const auto& [b1,c1] = itr_left->second;
      c = Intersection( a1 , b1 , a , b );

      if( c1 >= c ){

	m_ca.erase( c1 );

	if( itr_left == begin ){

	  m_abc.erase( itr_left );
	  break;

	} else {
	  
	  m_abc.erase( itr_left-- );

	}

      } else {

	break;

      }

    }

  }

  if( c < llim_c ){

    c = llim_c;

  } else if( c > ulim_c ){

    c = ulim_c;

  }
  
  m_abc[a] = { b , c };
  m_ca[c] = a;
  return;

}

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c>
void MinLinearFunction<INT,llim_a,ulim_a,llim_b,ulim_b,llim_c,ulim_c>::SetMin( const INT& a , const INT& b ) { MaxLinearFunction<INT,-ulim_a,-llim_a,-ulim_b,-llim_b,llim_c,ulim_c>::SetMax( -a , -b ); }

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c>
INT MaxLinearFunction<INT,llim_a,ulim_a,llim_b,ulim_b,llim_c,ulim_c>::Get( const INT& x ) const
{

  assert( !m_abc.empty() );
  assert( llim_c <= x && x <= ulim_c );
  auto itr_next = m_ca.upper_bound( x );
  const auto& [c,a] = itr_next == m_ca.end() ? *( m_ca.rbegin() ) : *( --itr_next );
  auto itr = m_abc.lower_bound( a );
  const INT& a1 = itr->first;
  const auto& [b1,c1] = itr->second;
  return a1 * x + b1;
  
}

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c>
INT MinLinearFunction<INT,llim_a,ulim_a,llim_b,ulim_b,llim_c,ulim_c>::Get( const INT& x ) const { return -MaxLinearFunction<INT,-ulim_a,-llim_a,-ulim_b,-llim_b,llim_c,ulim_c>( x ); }

template <typename INT , INT llim_a , INT ulim_a , INT llim_b , INT ulim_b , INT llim_c , INT ulim_c> inline INT MaxLinearFunction<INT,llim_a,ulim_a,llim_b,ulim_b,llim_c,ulim_c>::Intersection( const INT& a0 , const INT& b0 , const INT& a1 , const INT& b1 ) { const INT diff_a = a1 - a0; assert( diff_a > 0 ); return ( b0 - b1 + diff_a - 1 ) / diff_a; }

