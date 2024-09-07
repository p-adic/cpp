// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Iterator/a_Body.hpp"

#ifdef DEBUG
  #include "../../DirectProduct/AffineSpace/BIT/Debug/a_Body.hpp"
#else
  #include "../../DirectProduct/AffineSpace/BIT/a_Body.hpp"
#endif

template <typename INT , template <typename...> typename DATA_STR> inline AbstractBoundedLineSubset<INT,DATA_STR>::AbstractBoundedLineSubset( const INT& lbound , const INT& ubound ) : m_lbound( lbound ) , m_ubound( ubound ) , m_ds( m_ubound - m_lbound + 1 ) { assert( m_lbound <= m_ubound + 1 ); }

template <typename INT , template <typename...> typename DATA_STR> inline void AbstractBoundedLineSubset<INT,DATA_STR>::insert( const INT& i ) { assert( m_lbound <= i && i <= m_ubound ); m_ds.Set( i - m_lbound , 1 ); }

template <typename INT , template <typename...> typename DATA_STR> inline void AbstractBoundedLineSubset<INT,DATA_STR>::erase( const INT& i ) { m_ds.Set( i - m_lbound , 0 ); }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR>& AbstractBoundedLineSubset<INT,DATA_STR>::erase( IteratorOfBoundedLineSubset<INT,DATA_STR>& itr ) { return itr.erase_from( *this ); }

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineSubset<INT,DATA_STR>::count( const INT& i ) noexcept { return m_lbound <= i && i <= m_ubound ? m_ds[i - m_lbound] : 0; }

template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractBoundedLineSubset<INT,DATA_STR>::find( const INT& i ) noexcept { return count( i ) > 0; }

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineSubset<INT,DATA_STR>::InitialSegmentCount( const INT& i_final ) noexcept { return m_ds.InitialSegmentSum( i_final - m_lbound ); }
template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineSubset<INT,DATA_STR>::IntervalCount( const INT& i_start , const INT& i_final ) noexcept { return m_ds.IntervalSum( i_start - m_lbound , i_final - m_lbound ); }
template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractBoundedLineSubset<INT,DATA_STR>::empty() noexcept { return InitialSegmentCount( m_ubound ) == 0; }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::begin() noexcept { return MinimumGeq( m_lbound ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::end() noexcept { return IteratorOfBoundedLineSubset<INT,DATA_STR>( *this , m_ubound + 1 ); }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MaximumLeq( const INT& i , const int& k ) noexcept { const INT num = InitialSegmentCount( i ) - k; const INT l = m_ds.Search( [&]( const INT& sum , const int& j ){ return num <= sum; } ) + m_lbound; return num >= 0 && find( l ) ? IteratorOfBoundedLineSubset<INT,DATA_STR>{ *this , l } : end(); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MaximumLt( const INT& i , const int& k ) noexcept { return MaximumLeq( i - 1 , k ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MinimumGeq( const INT& i , const int& k ) noexcept { return MinimumGt( i - 1 , k ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineSubset<INT,DATA_STR>::MinimumGt( const INT& i , const int& k ) noexcept { const INT num = InitialSegmentCount( i ) + k; const INT r = m_ds.Search( [&]( const INT& sum , const int& j ){ return num < sum; } ) + m_lbound; return find( r ) ? IteratorOfBoundedLineSubset<INT,DATA_STR>{ *this , r } : end(); }

template <typename INT , template <typename...> typename DATA_STR> inline INT AbstractBoundedLineSubset<INT,DATA_STR>::Maximum( const int& k ) { return MaximumLeq( m_ubound , k ); }
template <typename INT , template <typename...> typename DATA_STR> inline INT AbstractBoundedLineSubset<INT,DATA_STR>::Minimum( const int& k ) { return MinimumGeq( m_lbound , k ); }

template <typename INT , template <typename...> typename DATA_STR>
INT AbstractBoundedLineSubset<INT,DATA_STR>::RightEndPointOf( const INT& i , const bool& in ) noexcept
{

  if( !in && !find( i ) ){

    return i - 1;

  }

  const int d = i - m_lbound;
  const INT comp_minus = d - InitialSegmentCount( i );
  return m_ds.Search( [&]( const INT& sum , const int& j ){ return d <= j && sum + comp < j; } ) + m_lbound - 1;

}

template <typename INT , template <typename...> typename DATA_STR>
INT AbstractBoundedLineSubset<INT,DATA_STR>::LeftEndPointOf( const INT& i , const bool& in ) noexcept
{

  if( !in && !find( i ) ){

    return i + 1;

  }

  const int d = i - m_lbound;
  const INT comp_minus = d - InitialSegmentCount( i );
  return m_ds.Search( [&]( const INT& sum , const int& j ){ return d <= j || ( find( j ) && sum + comp == j ); } ) + m_lbound;

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

