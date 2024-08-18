// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Iterator/a_Body.hpp"
#include "../../../DirectProduct/AffineSpace/BIT/Debug/a_Body.hpp"

template <typename INT , template <typename...> typename DATA_STR> inline AbstractBoundedLineSubset<INT,DATA_STR>::AbstractBoundedLineSubset( const INT& lbound , const INT& ubound ) : m_lbound( lbound ) , m_ubound( ubound ) , m_ds( m_ubound - m_lbound + 1 , false ) , m_S()
{

  assert( m_lbound <= m_ubound + 1 );
  cerr << "BoundedLineSubsetをデバッグモードで実行します。" << endl;
  cerr << "各処理の計算量がO(size)増えることに注意してください。" << endl;
  Display();
  cerr << endl;

}

template <typename INT , template <typename...> typename DATA_STR> inline void AbstractBoundedLineSubset<INT,DATA_STR>::insert( const INT& i )
{

  assert( m_lbound <= i && i <= m_ubound );
  m_ds.Set( i - m_lbound , 1 );

  if( m_S.count( i ) == 1 ){

    cerr << "BoundedLineSubsetに" << i << "の挿入を試みましたが元々属していました。" << endl;

  } else {

    m_S.insert( i );
    cerr << "BoundedLineSubsetに" << i << "を挿入しました。" << endl;
    Display();
    cerr << endl;

  }

  return;

}

template <typename INT , template <typename...> typename DATA_STR> inline void AbstractBoundedLineSubset<INT,DATA_STR>::erase( const INT& i )
{

  m_ds.Set( i - m_lbound , 0 );

  if( m_S.count( i ) == 1 ){

    cerr << "BoundedLineSubsetから" << i << "を削除しました。" << endl;
    m_S.erase( i );
    Display();
    cerr << endl;

  } else {

    cerr << "BoundedLineSubsetから" << i << "の削除を試みましたが元々属していませんでした。" << endl;

  }

  return;

}

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR>& AbstractBoundedLineSubset<INT,DATA_STR>::erase( IteratorOfBoundedLineSubset<INT,DATA_STR>& itr )
{

  const INT i = *itr;
  assert( m_S.count( i ) == 1 );
  auto& itr_ref = itr.erase_from( *this );
  cerr << "BoundedLineSubsetから" << i << "を削除しました。" << endl;
  m_S.erase( i );
  Display();
  cerr << endl;
  return itr_ref;

}

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineSubset<INT,DATA_STR>::count( const INT& i ) noexcept { return m_lbound <= i && i <= m_ubound ? m_ds[i - m_lbound] : 0; }

template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractBoundedLineSubset<INT,DATA_STR>::find( const INT& i ) noexcept { return count( i ) == 1; }

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineSubset<INT,DATA_STR>::InitialSegmentSize( const INT& i_final ) noexcept { return m_ds.InitialSegmentSum( i_final - m_lbound ); }

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineSubset<INT,DATA_STR>::IntervalSize( const INT& i_start , const INT& i_final ) noexcept
{

  const INT answer = m_ds.IntervalSum( i_start - m_lbound , i_final - m_lbound );
  cerr << "BoundedLineSubsetの区間[" << i_start << "," << i_final << "]内の要素数は" << answer << "です。" << endl;
  return answer;

}

template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractBoundedLineSubset<INT,DATA_STR>::empty() noexcept { return InitialSegmentSize( m_ubound ) == 0; }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::begin() noexcept { return MinimumGeq( m_lbound ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::end() const noexcept { return IteratorOfBoundedLineSubset<INT,DATA_STR>( *this , m_ubound + 1 ); }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MaximumLeq( const INT& i ) noexcept { const INT num = InitialSegmentSize( i ); const INT l = m_ds.Search( [&]( const INT& sum , const int& j ){ return num <= sum; } ) + m_lbound; return find( l ) ? IteratorOfBoundedLineSubset<INT,DATA_STR>{ *this , l } : end(); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MaximumLt( const INT& i ) noexcept { return MaximumLeq( i - 1 ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MinimumGeq( const INT& i ) noexcept { return MinimumGt( i - 1 ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MinimumGt( const INT& i ) noexcept { const INT num = InitialSegmentSize( i ); const INT r = m_ds.Search( [&]( const INT& sum , const int& j ){ return num < sum; } ) + m_lbound; return find( r ) ? IteratorOfBoundedLineSubset<INT,DATA_STR>{ *this , r } : end(); }

template <typename INT , template <typename...> typename DATA_STR> inline INT AbstractBoundedLineSubset<INT,DATA_STR>::Maximum() { return *--end(); }
template <typename INT , template <typename...> typename DATA_STR> inline INT AbstractBoundedLineSubset<INT,DATA_STR>::Minimum() { return *begin(); }

template <typename INT , template <typename...> typename DATA_STR>
INT AbstractBoundedLineSubset<INT,DATA_STR>::RightEndPointOf( const INT& i , const bool& in ) noexcept
{

  if( !in && !find( i ) ){

    return i - 1;

  }

  const int d = i - m_lbound;
  const INT comp_minus = d - InitialSegmentSize( i );
  return m_ds.Search( [&]( const INT& sum , const int& j ){ return d <= j && sum + comp_minus < j; } ) + m_lbound - 1;

}

template <typename INT , template <typename...> typename DATA_STR>
INT AbstractBoundedLineSubset<INT,DATA_STR>::LeftEndPointOf( const INT& i , const bool& in ) noexcept
{

  if( !in && !find( i ) ){

    return i + 1;

  }

  const int d = i - m_lbound;
  const INT comp_minus = d - InitialSegmentSize( i );
  return m_ds.Search( [&]( const INT& sum , const int& j ){ return d <= j || ( find( j ) && sum + comp_minus == j ); } ) + m_lbound;

}

template <typename INT , template <typename...> typename DATA_STR> inline pair<INT,INT> AbstractBoundedLineSubset<INT,DATA_STR>::ConnectedComponentOf( const INT& i , bool in ) noexcept { if( !in ){ in = find( i ); } return { LeftEndPointOf( i , in ) , RightEndPointOf( i , in ) }; }


template <typename INT , template <typename...> typename DATA_STR>
vector<pair<INT,INT>> AbstractBoundedLineSubset<INT,DATA_STR>::GetConnectedComponent() noexcept
{

  vector<pair<INT,INT>> answer{};
  INT r;
  
  for( auto itr = begin() ; *itr <= m_ubound ; itr = MinimumGt( r ) ){

    answer.push_back( { *itr , r = RightEndPointOf( *itr ) } );

  }

  return answer;

}

template <typename INT , template <typename...> typename DATA_STR> inline const INT& AbstractBoundedLineSubset<INT,DATA_STR>::lbound() const noexcept { return m_lbound; }
template <typename INT , template <typename...> typename DATA_STR> inline const INT& AbstractBoundedLineSubset<INT,DATA_STR>::ubound() const noexcept { return m_ubound; }

template <typename INT , template <typename...> typename DATA_STR> void AbstractBoundedLineSubset<INT,DATA_STR>::Display() noexcept
{

  cerr << "要素数: " << m_S.size() << endl;
  cerr << "集合: " << m_S << endl;
  cerr << "区間列:";

  for( auto&& [l,r] : GetConnectedComponent() ){

    cerr << " [" << l << "," << r << "]";

  }

  cerr << endl;
  return;

}
