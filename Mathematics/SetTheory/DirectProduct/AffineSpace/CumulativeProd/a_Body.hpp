// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , int size_max> inline CumulativeProd_Body<T,m_T,i_T,size_max>::CumulativeProd_Body( const int& size ) : m_size( size ) , m_a() , m_a_reverse() { assert( size <= size_max ); }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline CumulativeProd<T,m_T,e_T,i_T,size_max>::CumulativeProd( const T ( &a )[size_max] , const int& size ) : CumulativeProd_Body<T,m_T,i_T,size_max>( size )
{

  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  T temp , temp_reverse;
  base::m_a[0] = base::m_a_reverse[0] = temp = temp_reverse = a[0];

  for( int i = 1 ; i < size ; i++ ){

    base::m_a[i] = temp = m_T( temp , a[i] );
    base::m_a_reverse[i] = temp_reverse = m_T( a[i] , temp_reverse );

  }

}

template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , int size_max> inline  T CumulativeProd_Body<T,m_T,i_T,size_max>::PathProd( const int& i , const int& j ) { assert( 0 <= i && i < m_size && 0 <= j && j < m_size ); const int k = LCA( i , j ); return m_T( m_T( m_a_reverse[i] , i_T( m_a_reverse[k] ) ) , k == 0 ? m_a[j] : m_T( i_T( m_a[Parent( k ) ] ) , m_a[j] )); }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline T CumulativeProd<T,m_T,e_T,i_T,size_max>::RightProd( const int& i , const int& j )
{
  
  assert( i - 1 <= j );
  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  return i <= j ? i == 0 ? base::m_a[j] : m_T( i_T( base::m_a[i-1] ) , base::m_a[j] ) : e_T();

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline T CumulativeProd<T,m_T,e_T,i_T,size_max>::LeftProd( const int& i , const int& j )
{
  
  assert( i - 1 <= j );
  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  return i <= j ? i == 0 ? base::m_a_reverse[j] : m_T( base::m_a_reverse[j] , i_T( base::m_a_reverse[i - 1] ) ) : e_T();

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> ll CumulativeProd<T,m_T,e_T,i_T,size_max>::CountUnitProdRange()
{

  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  map<T,ll> f{};
  f[e_T()]++;

  for( int i = 0 ; i < base::m_size ; i++ ){

    f[base::m_a[i]]++;

  }

  ll answer = 0;

  for( auto itr_f = f.begin() , end_f = f.end() ; itr_f != end_f ; itr_f++ ){

    const ll& num = itr_f->second;
    answer += num * ( num - 1 ) / 2;

  }

  return answer;

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> list<pair<int,int> > CumulativeProd<T,m_T,e_T,i_T,size_max>::UnitProdRange()
{

  using base = CumulativeProd_Body<T,m_T,i_T,size_max>;
  map<T,list<int> > f{};
  f[e_T()].push_back( -1 );

  for( int i = 0 ; i < base::m_size ; i++ ){

    f[base::m_a[i]].push_back( i );

  }

  list<pair<int,int> > answer{};

  for( auto itr_f = f.begin() , end_f = f.end() ; itr_f != end_f ; itr_f++ ){

    const auto& a = itr_f->second;

    for( auto itr_a_L = a.begin() , end_a = a.end() ; itr_a_L != end_a ; itr_a_L++ ){

      const int i = *itr_a_L + 1;
      auto itr_a_R = itr_a_R;
      itr_a_R++;

      while( itr_a_R != end_a ){

	answer.push_back( i , *itr_a_R );

      }

    }

  }

  return answer;

}

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline int CumulativeProd<T,m_T,e_T,i_T,size_max>::Parent( const int& i ) { return i - 1; }

template <typename T , T m_T(const T&,const T&) , const T& e_T() , T i_T(const T&) , int size_max> inline int CumulativeProd<T,m_T,e_T,i_T,size_max>::LCA( const int& i , const int& j ) { return min( i , j ); }
