// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Hybrid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractHybridBIT<U,ABELIAN_GROUP>::AbstractHybridBIT( ABELIAN_GROUP M , const int& size ) : AbstractBIT<U,ABELIAN_GROUP>( move( M ) , size ) , m_a( size , this->m_fenwick[0] ) {}
template <typename U , typename ABELIAN_GROUP> inline AbstractHybridBIT<U,ABELIAN_GROUP>::AbstractHybridBIT( ABELIAN_GROUP M , vector<U> a ) : AbstractBIT<U,ABELIAN_GROUP>( move( M ) , a ) , m_a( move( a ) ) {}
template <typename U> template <typename...Args> inline HybridBIT<U>::HybridBIT( Args&&... args ) : AbstractHybridBIT<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<Args>( args )... ) { static_assert( ! is_same_v<U,int> );}

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractHybridBIT<U,ABELIAN_GROUP>::Reset( Args&&... args ) { *this = AbstractHybridBIT<U,ABELIAN_GROUP>( move( this->m_M ) , forward<Args>( args )... ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractHybridBIT<U,ABELIAN_GROUP>::Set( const int& i , const U& u ) { Add( i , this->m_M.Sum( u , this->m_M.Inverse( m_a[i] ) ) ); }
template <typename U , typename ABELIAN_GROUP> inline AbstractHybridBIT<U,ABELIAN_GROUP>& AbstractHybridBIT<U,ABELIAN_GROUP>::operator+=( const vector<U>& a ) { AbstractBIT<U,ABELIAN_GROUP>::operator+=( a ); for( int i = 0 ; i < this->m_size ; i++ ){ U& m_ai = m_a[i]; m_ai = this->m_M.Sum( m_ai , a[i] ); } return *this; }
template <typename U , typename ABELIAN_GROUP> inline void AbstractHybridBIT<U,ABELIAN_GROUP>::Add( const int& i , const U& u ) { AbstractBIT<U,ABELIAN_GROUP>::Add( i , u ); U& m_ai = m_a[i]; m_ai = this->m_M.Sum( m_ai , u ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractHybridBIT<U,ABELIAN_GROUP>::operator[]( const int& i ) const { assert( 0 <= i && i < this->m_size ); return m_a[i]; }
template <typename U , typename ABELIAN_GROUP> inline const U& AbstractHybridBIT<U,ABELIAN_GROUP>::Get( const int& i ) const { return operator[]( i ); }
