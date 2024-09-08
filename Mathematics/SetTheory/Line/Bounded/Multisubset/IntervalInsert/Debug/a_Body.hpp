// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Iterator/a_Body.hpp"
#include "../../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp"

template <typename INT , typename RET_NOR , typename RET_DEN> inline VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::VirtualIntervalInsertBoundedLineMultiSubset() : m_lbound() , m_ubound() , m_ds( 0 , false ) , m_name() , m_S() , m_S_comp() {}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::insert( const INT& i , const int& c )
{

  assert( InRange( i ) && c >= 0 );
  m_ds.Add( Normalise( i ) , c );
  auto itr = m_S_comp.find( i ) , end = m_S_comp.end();

  for( int repetition = 0 ; repetition < c ; repetition++ ){

    if( itr != end && *itr == i ){

      itr = m_S_comp.erase( itr );

    } else {

      m_S.insert( i );

    }

  }
  
  cerr << m_name << "に" << i << "を" << c << "個挿入しました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalInsert( const INT& i_start , const INT& i_final , const int& c )
{

  assert( InRange( i_start ) && InRange( i_final ) && c >= 0 );
  m_ds.IntervalAdd( Normalise( i_start ) , Normalise( i_final ) , c );

  for( int i = i_start ; i <= i_final ; i++ ){
    
    auto itr = m_S_comp.find( i ) , end = m_S_comp.end();

    for( int repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S_comp.erase( itr );

      } else {

        m_S.insert( i );

      }

    }

  }
  
  cerr << m_name << "に閉区間[" << i_start << "," << i_final << "]の和集合を" << c << "個取りました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::erase( const INT& i , const int& c )
{

  assert( c >= 0 );

  if( InRange( i ) ){
    
    m_ds.Add( Normalise( i ) , -c );
    auto itr = m_S.find( i ) , end = m_S.end();

    for( int repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S.erase( itr );

      } else {

        m_S_comp.insert( i );

      }

    }

  }

  cerr << m_name << "から" << i << "を" << c << "個削除挿入しました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator& VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::erase( typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator& itr )
{

  const INT i = *itr;
  assert( m_S.count( i ) > 0 && m_S_comp.empty() );
  auto& itr_ref = itr.erase_from( *this );
  cerr << m_name << "から" << i << "を" << 1 << "個削除しました。" << endl;
  m_S.erase( i );
  Display();
  cerr << endl;
  return itr_ref;

}


template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::EraseAll( const INT& i )
{

  if( InRange( i ) ){
    
    m_ds.Set( Normalise( i ) , 0 );
    auto itr = m_S.find( i ) , end = m_S.end();

    while( itr != end && *itr == i ){

      itr = m_S.erase( itr );

    }

    auto itr_comp = m_S_comp.find( i ) , end_comp = m_S_comp.end();

    while( itr_comp != end_comp && *itr_comp == i ){

      itr_comp = m_S_comp.erase( itr_comp );

    }

  }

  cerr << m_name << "から" << i << "を全て削除しました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalErase( const INT& i_start , const INT& i_final , const int& c )
{

  assert( InRange( i_start ) && InRange( i_final ) && c >= 0 );
  m_ds.IntervalAdd( Normalise( i_start ) , Normalise( i_final ) , -c );

  for( int i = i_start ; i <= i_final ; i++ ){
    
    auto itr = m_S.find( i ) , end = m_S.end();

    for( int repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S.erase( itr );

      } else {

        m_S_comp.insert( i );

      }

    }

  }

  cerr << m_name << "から閉区間[" << i_start << "," << i_final << "]の差集合を" << c << "回取りました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline int VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::count( const INT& i ) noexcept { return InRange( i ) ? m_ds[Normalise( i )] : 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline bool VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::find( const INT& i ) noexcept { return count( i ) > 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline int VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::InitialSegmentCount( const INT& i_final ) noexcept { assert( InRange( i_final ) ); return m_ds.InitialSegmentSum( Normalise( i_final ) ); }
  
template <typename INT , typename RET_NOR , typename RET_DEN> inline int VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalCount( const INT& i_start , const INT& i_final ) noexcept
{

  assert( InRange( i_final ) && InRange( i_final ) ); 
  const INT answer = m_ds.IntervalSum( Normalise( i_start ) , Normalise( i_final ) );
  cerr << m_name << "の区間[" << i_start << "," << i_final << "]内の重複を込めた要素数は" << answer << "です。" << endl;
  return answer;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline bool VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::empty() { assert( m_S_comp.empty() ); return InitialSegmentCount( m_ubound ) == 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::begin() { return MinimumGeq( m_lbound ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::end() const { assert( m_S_comp.empty() ); return typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator( *this , m_ubound + 1 ); }

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MaximumLeq( const INT& i , const int& k )
{

  assert( m_S_comp.empty() );
  const INT num = InitialSegmentCount( i ) - k;
  const INT l = Denormalise( m_ds.Search( [&]( const INT& sum , const int& j ){ return num <= sum; } ) );
  return num >= 0 && find( l ) ? typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , l } : end();
  
}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MaximumLt( const INT& i , const int& k )
{

  const int d = Normalise( i );

  if( d == 0 ){

    return end();

  }

  return MaximumLeq( Denormalise( d - 1 ) , k );

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MinimumGeq( const INT& i , const int& k )
{

  const int c = count( i );
  return c > k ? typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , i } : MinimumGt( i , k - c );

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MinimumGt( const INT& i , const int& k )
{

  assert( m_S_comp.empty() );
  const INT num = InitialSegmentCount( i ) + k;
  const INT r = Denormalise( m_ds.Search( [&]( const INT& sum , const int& j ){ return num < sum; } ) );
  return find( r ) ? typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , r } : end();

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::Maximum( const int& k ) { return MaximumLeq( m_ubound , k ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::Minimum( const int& k ) { return MinimumGeq( m_lbound , k ); }

template <typename INT , typename RET_NOR , typename RET_DEN> inline const INT& VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::lbound() const noexcept { return m_lbound; }
template <typename INT , typename RET_NOR , typename RET_DEN> inline const INT& VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::ubound() const noexcept { return m_ubound; }

template <typename INT , typename RET_NOR , typename RET_DEN> void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::Display() noexcept
{

  cerr << "重複を込めた要素数: " << int( m_S.size() ) - int( m_S_comp.size() ) << endl;
  cerr << "集合: " << m_S << " - " << m_S_comp << endl;
  cerr << endl;
  return;

}


template <typename INT> inline IntervalInsertBoundedLineMultiSubset<INT>::IntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound ) : VirtualIntervalInsertBoundedLineMultiSubset<INT,INT,INT>()
{

  assert( lbound <= ubound + 1 );
  this->m_lbound = lbound;
  this->m_ubound = ubound;
  this->m_name = "IntervalInsertBoundedLineMultiSubset";
  this->m_ds.Initialise( this->m_ubound - this->m_lbound + 1 , false );
  cerr << this->m_name << "をデバッグモードで実行します。" << endl;
  cerr << "各処理の計算量がO(size)増えることに注意してください。" << endl;
  this->Display();
  cerr << endl;
  
}

template <typename INT> inline bool IntervalInsertBoundedLineMultiSubset<INT>::InRange( const INT& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT> inline INT IntervalInsertBoundedLineMultiSubset<INT>::Normalise( const INT& i ) { return i - this->m_lbound; }
template <typename INT> inline INT IntervalInsertBoundedLineMultiSubset<INT>::Denormalise( const INT& d ) { return d + this->m_lbound; }
