// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Iterator/a_Body.hpp"
#include "../../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp"

template <typename INT , typename RET_NOR , typename RET_DEN> inline VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::VirtualIntervalInsertBoundedLineMultiSubset() : Debug() , m_lbound() , m_ubound() , m_ds( 0 , false ) , m_name() , m_S() , m_S_comp() {}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::insert( const INT& i , const INT& c )
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

  if( m_output_mode ){
  
    DERR( m_name , "に" , i , "を" , c , "個挿入しました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalInsert( const INT& i_start , const INT& i_final , const INT& c )
{

  assert( InRange( i_start ) && InRange( i_final ) && c >= 0 );
  m_ds.IntervalAdd( Normalise( i_start ) , Normalise( i_final ) , c );

  for( INT i = i_start ; i <= i_final ; i++ ){
    
    auto itr = m_S_comp.find( i ) , end = m_S_comp.end();

    for( INT repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S_comp.erase( itr );

      } else {

        m_S.insert( i );

      }

    }

  }
  
  DERR( m_name , " に閉区間 [" , i_start , "," , i_final , "] の和集合を " , c , " 個取りました。" );
  Display();
  DERR( "" );
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::erase( const INT& i , const INT& c )
{

  assert( c >= 0 );

  if( InRange( i ) ){
    
    m_ds.Add( Normalise( i ) , -c );
    auto itr = m_S.find( i ) , end = m_S.end();

    for( INT repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S.erase( itr );

      } else {

        m_S_comp.insert( i );

      }

    }

  }

  if( m_output_mode ){

    DERR( m_name , "から" , i , "を" , c , "個削除挿入しました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator& VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::erase( typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator& itr )
{

  const INT i = *itr;
  assert( m_S.count( i ) > 0 && m_S_comp.empty() );
  auto& itr_ref = itr.erase_from( *this );

  if( m_output_mode ){

    DERR( m_name , "から" , i , "を" , 1 , "個削除しました。" );
    m_S.erase( i );
    Display();
    DERR( "" );

  }
  
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

  if( m_output_mode ){

    DERR( m_name , "から" , i , "を全て削除しました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalErase( const INT& i_start , const INT& i_final , const INT& c )
{

  assert( InRange( i_start ) && InRange( i_final ) && c >= 0 );
  m_ds.IntervalAdd( Normalise( i_start ) , Normalise( i_final ) , -c );

  for( INT i = i_start ; i <= i_final ; i++ ){
    
    auto itr = m_S.find( i ) , end = m_S.end();

    for( INT repetition = 0 ; repetition < c ; repetition++ ){

      if( itr != end && *itr == i ){

        itr = m_S.erase( itr );

      } else {

        m_S_comp.insert( i );

      }

    }

  }

  if( m_output_mode ){

    DERR( m_name , " から閉区間 [" , i_start , "," , i_final , "] の差集合を " , c , " 回取りました。" );
    Display();
    DERR( "" );

  }
  
  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::clear()
{
  
  m_ds.Initialise( m_ds.size() );
  m_S.clear();
  m_S_comp.clear();

  if( m_output_mode ){

    DERR( m_name , "から全ての要素を削除しました。" );
    Display();
    DERR( "" );

  }

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::count( const INT& i ) noexcept { return InRange( i ) ? m_ds[Normalise( i )] : 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline bool VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::find( const INT& i ) noexcept { return count( i ) > 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::InitialSegmentCount( const INT& i_final ) noexcept { return i_final < m_lbound ? 0 : m_ds.InitialSegmentSum( Normalise( i_final ) ); }
  
template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::IntervalCount( const INT& i_start , const INT& i_final ) noexcept
{

  auto&& l = Normalise( i_start );
  const INT answer = m_ds.IntervalSum( ( l < 0 || Denormalise( l ) < i_start ) ? l + 1 : l , Normalise( i_final ) );

  if( m_output_mode ){

    DERR( m_name , "の区間[" , i_start , "," , i_final , "]内の重複を込めた要素数は" , answer , "です。" );
    DERR( "\n" );

  }
  
  return answer;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline bool VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::empty() { assert( m_S_comp.empty() ); return InitialSegmentCount( m_ubound ) == 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::begin() { return MinimumGeq( m_lbound ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::end() { assert( m_S_comp.empty() ); return typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator( *this , m_ubound + 1 ); }

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MaximumLeq( const INT& i , const INT& k )
{

  assert( m_S_comp.empty() );
  const INT num = InitialSegmentCount( i ) - k;

  if( num >= 0 ){

    const INT d = m_ds.Search( [&]( const INT& sum , const int& j ){ return num <= sum; } );

    if( d < m_ds.size() ){

      auto&& l = Denormalise( d );

      if( find( l ) ){

        return typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , l };

      }

    }

  }

  return end(); 
  
}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MaximumLt( const INT& i , const INT& k )
{

  const INT d = Normalise( i );

  if( d == 0 ){

    return end();

  }

  return MaximumLeq( Denormalise( d - 1 ) , k );

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MinimumGeq( const INT& i , const INT& k )
{

  const INT c = count( i );
  return c > k ? typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , i } : MinimumGt( i , k - c );

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::MinimumGt( const INT& i , const INT& k )
{

  assert( m_S_comp.empty() );
  const INT num = InitialSegmentCount( i ) + k;
  const INT d = m_ds.Search( [&]( const INT& sum , const int& j ){ return num < sum; } );

  if( d < m_ds.size() ){

    auto&& r = Denormalise( d );

    if( find( r ) ){

      return typename VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , r };

    }

  }

  return end(); 

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::Maximum( const INT& k ) { return MaximumLeq( m_ubound , k ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::Minimum( const INT& k ) { return MinimumGeq( m_lbound , k ); }

template <typename INT , typename RET_NOR , typename RET_DEN> inline const INT& VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::lbound() const noexcept { return m_lbound; }
template <typename INT , typename RET_NOR , typename RET_DEN> inline const INT& VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::ubound() const noexcept { return m_ubound; }

template <typename INT , typename RET_NOR , typename RET_DEN> void VirtualIntervalInsertBoundedLineMultiSubset<INT,RET_NOR,RET_DEN>::Display() noexcept
{

  DERR( "重複を込めた要素数:" , int( m_S.size() ) - int( m_S_comp.size() ) );
  DERR( "集合:" , m_S , "-" , m_S_comp );
  return;

}


template <typename INT> inline IntervalInsertBoundedLineMultiSubset<INT>::IntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound ) : VirtualIntervalInsertBoundedLineMultiSubset<INT,INT,INT>()
{

  assert( lbound <= ubound + 1 );
  this->m_lbound = lbound;
  this->m_ubound = ubound;
  static INT count = 0;
  this->m_name = "IntervalInsertBoundedLineMultiSubset" + to_string( count++ );

  if( this->m_output_mode ){
    
    DERR( this->m_name , "をデバッグモードで実行します。" );

    static bool init = true;

    if( init ){

      init = true;
      DERR( "各処理の計算量がO(size)増えることに注意してください。" );

    }
    
    this->Display();
    DERR( "" );

  }
  
}

template <typename INT> inline bool IntervalInsertBoundedLineMultiSubset<INT>::InRange( const INT& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT> inline INT IntervalInsertBoundedLineMultiSubset<INT>::Normalise( const INT& i ) { return i - this->m_lbound; }
template <typename INT> inline INT IntervalInsertBoundedLineMultiSubset<INT>::Denormalise( const INT& d ) { return d + this->m_lbound; }
