// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename U , int size_max> inline ZetaTransformBody<T,U,size_max>::ZetaTransformBody( const int& size ) : m_length() , m_memory() , m_memory_inv() , m_size( size ) , m_val() {}
template <typename T , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max>::SemiRingForZetaTransform( const int& dummy ) :
  ZetaTransformBody<T,U,size_max>( dummy )
{

  using base = ZetaTransformBody<T,U,size_max>;
  const U& zero = z_U();

  if( base::m_val[0] != zero ){

    for( int i = 0 ; i < base::m_size ; i++ ){

      base::m_val[i] = zero;

    }

  }

}

template <list<int> E(const int&) , list<int> E_inv(const int&) , int size_max> inline ZetaTransform<E,E_inv,size_max>::ZetaTransform( const int& size ) :
  ZetaTransformBody<int,ll,size_max>( size ) ,
  PartiallyOrderedSetForZetaTransform<int,E,E_inv,ll,size_max>()
{}

template <list<int> E(const int&) , list<int> E_inv(const int&) , int size_max> inline ZetaTransform<E,E_inv,size_max>::ZetaTransform( const int& size , const ll ( &a )[size_max] , const bool& transformed ) :
  ZetaTransformBody<int,ll,size_max>( size ) ,
  PartiallyOrderedSetForZetaTransform<int,E,E_inv,ll,size_max>() ,
  EnumerationForZetaTransform<ll,size_max>()
{

  using base = ZetaTransformBody<int,ll,size_max>;

  if( transformed ){

    for( int i = 0 ; i < base::m_size ; i++ ){

      base::m_val[i] = a[i];

    }
    
  } else {
  
    for( int i = 0 ; i < base::m_size ; i++ ){

      ll& m_val_i = base::m_val[i] = a[i];
      list<int> sub_i = E( i );

      while( ! sub_i.empty() ){

	m_val_i += a[sub_i.front()];
	sub_i.pop_front();

      }

    }

  }

}

template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline FastZetaTransform<U,a_U,z_U,m_U,size_max>::FastZetaTransform( const int& digit ) :
  ZetaTransformBody<int,U,size_max>( size ) ,
  SemiRingForZetaTransform<int,U,a_U,z_U,m_U,size_max>( size ) ,
  EnumerationForZetaTransform<U,size_max>() ,
  m_digit( digit )
{}

template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline FastZetaTransform<U,a_U,z_U,m_U,size_max>::FastZetaTransform( const int& digit , const U ( &a )[size_max] , const bool& transformed ) :
  ZetaTransformBody<int,U,size_max>( 1 << digit ) ,
  SemiRingForZetaTransform<int,U,a_U,z_U,m_U,size_max>( size )
{

  using base = ZetaTransformBody<int,U,size_max>;
  
  for( int i = 0 ; i < base::m_size ; i++ ){

    base::m_val[i] = a[i];

  }

  if( ! transformed ){

    int power = 1;

    for( int d = 0 ; d < m_digit ; d++ , power <<= 1 ){

      for( int i = 0 ; i < base::m_size ; i++ ){

	if( ( i & power ) != 0 ){

	  U& m_val_i = base::m_val[i];
	  m_val_i = a_U( m_val_i , base::m_val[i ^ power] );

	}
      
      }

    }

  }
  
}

template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline MemorisationZetaTransform<T,E,E_inv,U,a_U,z_U,m_U,size_max>::MemorisationZetaTransform( const int& size ) :
  ZetaTransformBody<T,U,size_max>( size ) ,
  SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max>( size ) ,
  PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>()
{}

template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline EnumerationZetaTransform<T,E,E_inv,U,a_U,z_U,m_U,size_max,enum_T,enum_T_inv>::EnumerationZetaTransform( const int& size ) :
  ZetaTransformBody<T,U,size_max>( size ) ,
  SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max>( size ) ,
  PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>()
{}

template <typename T , typename U , int size_max> inline void ZetaTransformBody<T,U,size_max>::Add( const T& t , const U& u )
{

  list<T> sup = Sup( t );
  sup.push_front( t );

  while( ! sup.empty() ){

    U& m_val_i = m_val[e_inv( sup.front() )];
    m_val_i = Sum( m_val_i , u );
    sup.pop_front();

  }

  return;

}

template <typename T , typename U , int size_max> inline void ZetaTransformBody<T,U,size_max>::AddAll( const U& u )
{

  for( int i = 0 ; i < m_size ; i++ ){

    U& m_val_i = m_val[i];
    m_val_i = Sum( m_val_i , Prod( Sub( e( i ) ).size() , u ) );

  }
  
  return;

}

template <typename T , typename U , int size_max> inline ZetaTransformBody<T,U,size_max>& ZetaTransformBody<T,U,size_max>::operator+=( const ZetaTransformBody<T,U,size_max>& a )
{

  for( int i = 0 ; i < m_size ; i++ ){

    U& m_val_i = m_val[i];
    m_val_i = Sum( m_val_i , a.m_val[i] );

  }
  
  return *this;

}

template <typename T , typename U , int size_max> inline void ZetaTransformBody<T,U,size_max>::MultiplyAll( const U& u )
{

  for( int i = 0 ; i < m_size ; i++ ){

    U& m_val_i = m_val[i];
    m_val_i = Prod( m_val_i , u );
    
  }
  
  return;

}

template <typename T , typename U , int size_max> inline ZetaTransformBody<T,U,size_max>& ZetaTransformBody<T,U,size_max>::operator*=( const ZetaTransformBody<T,U,size_max>& a )
{

  for( int i = 0 ; i < m_size ; i++ ){

    U& m_val_i = m_val[i];
    m_val_i = Prod( m_val_i , a.m_val[i] );

  }
  
  return *this;

}

template <typename T , typename U , int size_max> inline U ZetaTransformBody<T,U,size_max>::Get( const T& t ) { DEFINITION_OF_GET_FOR_ZETA_TRANSFORM( Moevius ); }
template <typename T , typename U , int size_max> template <int mu(const T&,const T&)> inline U ZetaTransformBody<T,U,size_max>::Get( const T& t ) { DEFINITION_OF_GET_FOR_ZETA_TRANSFORM( mu ); }

template <typename T , typename U , int size_max> inline const U& ZetaTransformBody<T,U,size_max>::InitialSegmentSum( const T& t ) { return m_val[e_inv( t )]; }

template <typename T , typename U , int size_max> template <typename S , T f_inv_max(const S&) , list<S> r(const S&)> inline U ZetaTransformBody<T,U,size_max>::InverseImageSum( const S& s ) { DEFINITION_OF_INVERSE_IMAGE_SUM_FOR_ZETA_TRANSFORM( Moevius ); }
template <typename T , typename U , int size_max> template <typename S , T f_inv_max(const S&) , list<S> r(const S&) , int mu(const T&,const T&)> inline U ZetaTransformBody<T,U,size_max>::InverseImageSum( const S& s ) { DEFINITION_OF_INVERSE_IMAGE_SUM_FOR_ZETA_TRANSFORM( mu ); }

template <typename T , typename U , int size_max> template <typename S , T f_inv_max(const S&)> inline const U& ZetaTransformBody<T,U,size_max>::InitialSegmentInverseImageSum( const S& s ) { return m_val[e_inv( f_inv_max( s ) )]; }


template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline void FastZetaTransform<U,a_U,z_U,m_U,size_max>::FastMoeviusTransform( U ( &a )[size_max] )
{

  using base = ZetaTransformBody<int,U,size_max>;
  
  for( int i = 0 ; i < base::m_size ; i++ ){

    a[i] = base::m_val[i];

  }

  int power = 1;

  for( int d = 0 ; d < m_digit ; d++ , power <<= 1 ){

    for( int i = 0 ; i < base::m_size ; i++ ){

      if( ( i & power ) != 0 ){

	U& a_i = a[i];
	a_i = a_U( a_i , m_U( -1 , a[i ^ power] ) );

      }
      
    }

  }

}


template <typename T , typename U , int size_max>
T ZetaTransformBody<T,U,size_max>::e( const int& i )
{
  
  assert( i < m_length );
  return m_memory_inv[i];

}

template <typename U , int size_max> inline int EnumerationForZetaTransform<U,size_max>::e( const int& i ) { return i; }
template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline T EnumerationZetaTransform<T,E,E_inv,U,a_U,z_U,m_U,size_max,enum_T,enum_T_inv>::e( const int& i ) { return enum_T( i ); }

template <typename T , typename U , int size_max>
int ZetaTransformBody<T,U,size_max>::e_inv( const T& t )
{

  if( m_memory.count( t ) == 0 ){

    assert( m_length < m_size );
    m_memory_inv.push_back( t );
    return m_memory[t] = m_length++;

  }
  
  return m_memory[t];

}

template <typename U , int size_max> inline int EnumerationForZetaTransform<U,size_max>::e_inv( const int& t ) { return t; }
template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline int EnumerationZetaTransform<T,E,E_inv,U,a_U,z_U,m_U,size_max,enum_T,enum_T_inv>::e_inv( const T& t ) { return enum_T_inv( t ); }


template <typename T , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline const U& SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max>::Zero() const { return z_U(); }
template <list<int> E(const int&) , list<int> E_inv(const int&) , int size_max> inline const ll& ZetaTransform<E,E_inv,size_max>::Zero() const { static const ll zero = 0; return zero; }

template <typename T , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline U SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max>::Sum( const U& u0 , const U& u1 ) const { return a_U( u0 , u1 ); }
template <list<int> E(const int&) , list<int> E_inv(const int&) , int size_max> inline ll ZetaTransform<E,E_inv,size_max>::Sum( const ll& u0 , const ll& u1 ) const { return u0 + u1; }

template <typename T , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline U SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max>::Prod( const U& u0 , const U& u1 ) const { return m_U( u0 , u1 ); }
template <list<int> E(const int&) , list<int> E_inv(const int&) , int size_max> inline ll ZetaTransform<E,E_inv,size_max>::Prod( const ll& u0 , const ll& u1 ) const { return u0 * u1; }


template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , int size_max> inline list<T> PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>::Sub( const T& t ) const { return E( t ); }
template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline list<int> FastZetaTransform<U,a_U,z_U,m_U,size_max>::Sub( const int& t ) const
{

  list<int> sub{};
  sub.push_back( t );
  int sub_size = 1;
  int power = 1;
  
  for( int d = 0 ; d < m_digit ; d++ , power <<= 1 ){

    if( ( t & power ) != 0 ){

      auto itr = sub.begin();

      for( int i = 0 ; i < sub_size ; i++ , itr++ ){

	sub.push_back( *itr ^ power );

      }

      sub_size <<= 1;

    }

  }
  
  return sub;

}


template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , int size_max> inline list<T> PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>::Sup( const T& t ) const { return E_inv( t ); }

template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> inline list<int> FastZetaTransform<U,a_U,z_U,m_U,size_max>::Sup( const int& t ) const
{

  list<int> sup{};
  sup.push_back( t );
  int sup_size = 1;
  int power = 1;
  
  for( int d = 0 ; d < m_digit ; d++ , power <<= 1 ){

    if( ( t & power ) == 0 ){

      auto itr = sup.begin();

      for( int i = 0 ; i < sup_size ; i++ , itr++ ){

	sup.push_back( *itr | power );

      }

      sup_size <<= 1;

    }

  }
  
  return sup;

}


template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , int size_max> inline int PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>::Moevius( const T& t0 , const T& t1 )
{

  using base = ZetaTransformBody<T,U,size_max>;
  const int i = base::e_inv( t0 );
  const int j = base::e_inv( t1 );
  map<int,int>& moevius_t0 = m_moevius[i];
  bool found = moevius_t0.count( j ) == 1;
  int& answer = moevius_t0[j];

  if( ! found ){

    if( i == j ){

      answer = 1;

    } else {

      list<T> sub = E( t1 );

      while( ! sub.empty() ){

	cerr << "メビウス関数のデフォルトの再帰式が呼ばれています。" << endl;
	cerr << "このエラー出力回数が多い場合、再帰深度が深過ぎる可能性があります。" << endl;
	answer -= Moevius( t0 , sub.front() );
	sub.pop_front();

      }

    }

  }

  return answer;

}

template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max> int FastZetaTransform<U,a_U,z_U,m_U,size_max>::Moevius( const int& t0 , const int& t1 )
{

  int t = t1 ^ t0;
  int count = 0;
  
  while( t != 0 ){

    t -= t & -t;
    count++;

  }
  
  return ( count & 1 ) == 0 ? 1 : -1;

}
