// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Iterator/a_Body.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/Debug/a_Body.hpp"

template <typename INT , typename RET_NOR , typename RET_DEN> inline VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::VirtualBoundedLineSubset() : Debug() , m_lbound() , m_ubound() , m_ds( 0 , false ) , m_name() , m_S() {}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::insert( const INT& i )
{

  assert( InRange( i ) );
  m_ds.Set( Normalise( i ) , 1 );

  if( m_output_mode ){

    if( m_S.count( i ) == 1 ){
  
      DERR( m_name , "に" , i , "の挿入を試みましたが元々属していました。" );

    } else {

      m_S.insert( i );

      DERR( m_name , "に" , i , "を挿入しました。" );
      Display();
      DERR( "" );

    }

  } else {

    m_S.insert( i );

  }

  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline void VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::erase( const INT& i ) noexcept
{

  if( InRange( i ) ){

    m_ds.Set( Normalise( i ) , 0 );

  }

  if( m_output_mode ){

    if( m_S.count( i ) > 0 ){

      DERR( m_name , "から" , i , "を削除しました。" );
      m_S.erase( i );
      Display();
      DERR( "" );

    } else {

      DERR( m_name , "から" , i , "の削除を試みましたが元々属していませんでした。" );

    }

  } else {

    m_S.erase( i );

  }

  return;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator& VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::erase( typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator& itr )
{

  const INT i = *itr;
  assert( m_S.count( i ) > 0 );
  auto& itr_ref = itr.erase_from( *this );
  m_S.erase( i );

  if( m_output_mode ){

    DERR( m_name , "から" , i , "を削除しました。" );
    Display();
    DERR( "" );

  }

  return itr_ref;

}

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline void VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN,DATA_STR>::clear()
{

  m_ds.Initialise( m_ds.size() );

  if( m_output_mode ){

    DERR( m_name , "から全ての要素を削除しました。" );
    Display();
    DERR( "" );

  }
  
}

template <typename INT , typename RET_NOR , typename RET_DEN> inline int VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::count( const INT& i ) noexcept { return InRange( i ) ? m_ds[Normalise( i )] : 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline bool VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::find( const INT& i ) noexcept { return count( i ) > 0; }

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline int VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::InitialSegmentCount( const INT& i_final ) { return i_final < m_lbound ? 0 : m_ds.InitialSegmentSum( Normalise( i_final ) ); }

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR> inline int VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::IntervalCount( const INT& i_start , const INT& i_final )
{

  auto&& l = Normalise( i_start );
  const INT answer = m_ds.IntervalSum( ( l < 0 || Denormalise( l ) < i_start ) ? l + 1 : l , Normalise( i_final ) );

  if( m_output_mode ){

    DERR( m_name , "の区間[" , i_start , "," , i_final , "]内の要素数は" , answer , "です。" );
    DERR( "" );

  }
  
  return answer;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline bool VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::empty() noexcept { return InitialSegmentCount( m_ubound ) == 0; }

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::begin() noexcept { return MinimumGeq( m_lbound ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::end() noexcept { return typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator( *this , m_ubound + 1 ); }

template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::MaximumLeq( const INT& i , const INT& k ) { const INT num = InitialSegmentCount( i ) - k; if( num >= 0 ){ const int d = m_ds.Search( [&]( const INT& sum , const int& j ){ return num <= sum; } ); if( d < m_ds.size() ){ auto&& l = Denormalise( d ); if( find( l ) ){ return typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , l }; } } } return end(); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::MaximumLt( const INT& i , const INT& k ) { const int d = Normalise( i ); if( d == 0 ){ return end(); } return MaximumLeq( Denormalise( d - 1 ) , k ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::MinimumGeq( const INT& i , const INT& k ) { const int c = count( i ); return c > k ? typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , i } : MinimumGt( i , k - c ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::MinimumGt( const INT& i , const INT& k ) { const INT num = InitialSegmentCount( i ) + k; const int d = m_ds.Search( [&]( const INT& sum , const int& j ){ return num < sum; } ); if( d < m_ds.size() ){ auto&& r = Denormalise( d ); if( find( r ) ){ typename VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::iterator{ *this , r }; } } return end(); }

template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::Maximum( const INT& k ) { return MaximumLeq( m_ubound , k ); }
template <typename INT , typename RET_NOR , typename RET_DEN> inline INT VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::Minimum( const INT& k ) { return MinimumGeq( m_lbound , k ); }

template <typename INT , typename RET_NOR , typename RET_DEN>
INT VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::RightEndPointOf( const INT& i , int d , int comp_minus , const bool& in )
{

  if( !in && !find( i ) ){

    return i - 1;

  }

  if( d == -1 ){

    d = Normalise( i );
    comp_minus = d - InitialSegmentCount( i );

  }

  // inがtrueなのでDenormaliseの引数が正であることに注意。
  return Denormalise( m_ds.Search( [&]( const INT& sum , const int& j ){ return d <= j && sum + comp_minus < j; } ) - 1 );

}

template <typename INT , typename RET_NOR , typename RET_DEN>
INT VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::LeftEndPointOf( const INT& i , int d , int comp_minus , const bool& in )
{

  if( !in && !find( i ) ){

    return i + 1;

  }

  if( d == -1 ){

    d = Normalise( i );
    comp_minus = d - InitialSegmentCount( i );

  }

  // inがtrueなのでDenormaliseの引数がm_ds.size()未満であることに注意。
  return Denormalise( m_ds.Search( [&]( const INT& sum , const int& j ){ return d <= j || ( find( j ) && sum + comp_minus == j ); } ) );

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline pair<INT,INT> VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::ConnectedComponentOf( const INT& i , bool in ) { if( !in ){ in = find( i ); } const int d = Normalise( i ) , comp_minus = d - InitialSegmentCount( i ); return { LeftEndPointOf( i , d , comp_minus , in ) , RightEndPointOf( i , d , comp_minus , in ) }; }

template <typename INT , typename RET_NOR , typename RET_DEN>
vector<pair<INT,INT>> VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::GetConnectedComponent() noexcept
{

  vector<pair<INT,INT>> answer{};
  INT r;
  
  for( auto itr = begin() ; *itr <= m_ubound ; itr = MinimumGt( r ) ){

    answer.push_back( { *itr , r = RightEndPointOf( *itr ) } );

  }

  return answer;

}

template <typename INT , typename RET_NOR , typename RET_DEN> inline const INT& VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::lbound() const noexcept { return m_lbound; }
template <typename INT , typename RET_NOR , typename RET_DEN> inline const INT& VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::ubound() const noexcept { return m_ubound; }


template <typename INT , typename RET_NOR , typename RET_DEN> void VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN>::Display() noexcept
{

  DERR( "要素数:" , m_S.size() );
  DERR( "集合:" , m_S );
  DERRNS( "区間列:" );

  for( auto&& [l,r] : GetConnectedComponent() ){

    DERRNS( " [" , l , "," , r , "]" );

  }

  DERR( "" );
  return;

}

template <typename INT> inline BoundedLineSubset<INT>::BoundedLineSubset( const INT& lbound , const INT& ubound , const bool& output_mode ) : VirtualBoundedLineSubset<INT,INT,INT>()
{

  assert( lbound <= ubound + 1 );
  this->m_output_mode = output_mode;
  this->m_lbound = lbound;
  this->m_ubound = ubound;
  static int count = 0;
  this->m_name = "BoundedLineSubset" + to_string( count++ );
  this->m_ds.Initialise( this->m_ubound - this->m_lbound + 1 , false );
  
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

template <typename INT> inline bool BoundedLineSubset<INT>::InRange( const INT& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT> inline INT BoundedLineSubset<INT>::Normalise( const INT& i ) { return i - this->m_lbound; }
template <typename INT> inline INT BoundedLineSubset<INT>::Denormalise( const INT& d ) { return d + this->m_lbound; }
