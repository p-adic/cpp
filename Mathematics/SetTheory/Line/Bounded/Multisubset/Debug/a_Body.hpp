// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Iterator/a_Body.hpp"
#include "../../../../DirectProduct/AffineSpace/BIT/Debug/a_Body.hpp"

template <typename INT , template <typename...> typename DATA_STR> inline AbstractBoundedLineMultiSubset<INT,DATA_STR>::AbstractBoundedLineMultiSubset( const INT& lbound , const INT& ubound ) : m_lbound( lbound ) , m_ubound( ubound ) , m_ds( m_ubound - m_lbound + 1 , false ) , m_S()
{

  assert( m_lbound <= m_ubound + 1 );
  cerr << "BoundedLineMultiSubsetをデバッグモードで実行します。" << endl;
  cerr << "各処理の計算量がO(size)増えることに注意してください。" << endl;
  Display();
  cerr << endl;

}

template <typename INT , template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,DATA_STR>::insert( const INT& i , const int& c )
{

  assert( m_lbound <= i && i <= m_ubound && c >= 0 );
  m_ds.Add( i - m_lbound , c );
  auto itr = m_S_comp.find( i ) , end = m_S_comp.end();

  for( int repetition = 0 ; repetition < c ; repetition++ ){

    if( itr != end && *itr == i ){

      itr = m_S_comp.erase( itr );

    } else {

      m_S.insert( i );

    }

  }
  
  cerr << "BoundedLineMultiSubsetに" << i << "を" << c << "個挿入しました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,DATA_STR>::erase( const INT& i , const int& c )
{

  assert( m_lbound <= i && i <= m_ubound && c >= 0 );
  m_ds.Add( i - m_lbound , -c );
  auto itr = m_S.find( i ) , end = m_S.end();

  for( int repetition = 0 ; repetition < c ; repetition++ ){

    if( itr != end && *itr == i ){

      itr = m_S.erase( itr );

    } else {

      m_S_comp.insert( i );

    }

  }

  cerr << "BoundedLineMultiSubsetから" << i << "を" << c << "個削除しました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR>& AbstractBoundedLineMultiSubset<INT,DATA_STR>::erase( IteratorOfBoundedLineSubset<INT,DATA_STR>& itr )
{

  const INT i = *itr;
  assert( m_S.count( i ) == 1 && m_S_comp.empty() );
  auto& itr_ref = itr.erase_from( *this );
  cerr << "BoundedLineMultiSubsetから" << i << "を" << 1 << "個削除しました。" << endl;
  m_S.erase( i );
  Display();
  cerr << endl;
  return itr_ref;

}


template <typename INT , template <typename...> typename DATA_STR> inline void AbstractBoundedLineMultiSubset<INT,DATA_STR>::EraseAll( const INT& i )
{

  m_ds.Set( i - m_lbound , 0 );
  auto itr = m_S.find( i ) , end = m_S.end();

  while( itr != end && *itr == i ){

    itr = m_S.erase( itr );

  }

  auto itr_comp = m_S_comp.find( i ) , end_comp = m_S_comp.end();

  while( itr_comp != end_comp && *itr_comp == i ){

    itr_comp = m_S_comp.erase( itr_comp );

  }

  cerr << "BoundedLineMultiSubsetから" << i << "を全て削除しました。" << endl;
  Display();
  cerr << endl;
  return;

}

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineMultiSubset<INT,DATA_STR>::count( const INT& i ) noexcept { return m_lbound <= i && i <= m_ubound ? m_ds[i - m_lbound] : 0; }

template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractBoundedLineMultiSubset<INT,DATA_STR>::find( const INT& i ) noexcept { return count( i ) > 0; }

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineMultiSubset<INT,DATA_STR>::InitialSegmentCount( const INT& i_final ) noexcept { return m_ds.InitialSegmentSum( i_final - m_lbound ); }

template <typename INT , template <typename...> typename DATA_STR> inline int AbstractBoundedLineMultiSubset<INT,DATA_STR>::IntervalCount( const INT& i_start , const INT& i_final ) noexcept
{

  const INT answer = m_ds.IntervalSum( i_start - m_lbound , i_final - m_lbound );
  cerr << "BoundedLineMultiSubsetの区間[" << i_start << "," << i_final << "]内の重複を込めた要素数は" << answer << "です。" << endl;
  return answer;

}

template <typename INT , template <typename...> typename DATA_STR> inline bool AbstractBoundedLineMultiSubset<INT,DATA_STR>::empty() { assert( m_S_comp.empty() ); return InitialSegmentCount( m_ubound ) == 0; }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineMultiSubset<INT,DATA_STR>::begin() { return MinimumGeq( m_lbound ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineMultiSubset<INT,DATA_STR>::end() const { assert( m_S_comp.empty() ); return IteratorOfBoundedLineSubset<INT,DATA_STR>( *this , m_ubound + 1 ); }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineMultiSubset<INT,DATA_STR>::MaximumLeq( const INT& i , const int& k ) { assert( m_S_comp.empty() ); const INT num = InitialSegmentCount( i ) - k; const INT l = m_ds.Search( [&]( const INT& sum , const int& j ){ return num <= sum; } ) + m_lbound; return num >= 0 && find( l ) ? IteratorOfBoundedLineSubset<INT,DATA_STR>{ *this , l } : end(); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineMultiSubset<INT,DATA_STR>::MaximumLt( const INT& i , const int& k ) { return MaximumLeq( i - 1 , k ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineMultiSubset<INT,DATA_STR>::MinimumGeq( const INT& i , const int& k ) { return MinimumGt( i - 1 , k ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> AbstractBoundedLineMultiSubset<INT,DATA_STR>::MinimumGt( const INT& i , const int& k ) { assert( m_S_comp.empty() ); const INT num = InitialSegmentCount( i ) + k; const INT r = m_ds.Search( [&]( const INT& sum , const int& j ){ return num < sum; } ) + m_lbound; return find( r ) ? IteratorOfBoundedLineSubset<INT,DATA_STR>{ *this , r } : end(); }

template <typename INT , template <typename...> typename DATA_STR> inline INT AbstractBoundedLineMultiSubset<INT,DATA_STR>::Maximum( const int& k ) { return MaximumLeq( m_ubound , k ); }
template <typename INT , template <typename...> typename DATA_STR> inline INT AbstractBoundedLineMultiSubset<INT,DATA_STR>::Minimum( const int& k ) { return MinimumGeq( m_lbound , k ); }

template <typename INT , template <typename...> typename DATA_STR> inline const INT& AbstractBoundedLineMultiSubset<INT,DATA_STR>::lbound() const noexcept { return m_lbound; }
template <typename INT , template <typename...> typename DATA_STR> inline const INT& AbstractBoundedLineMultiSubset<INT,DATA_STR>::ubound() const noexcept { return m_ubound; }

template <typename INT , template <typename...> typename DATA_STR> void AbstractBoundedLineMultiSubset<INT,DATA_STR>::Display() noexcept
{

  cerr << "重複を込めた要素数: " << int( m_S.size() ) - int( m_S_comp.size() ) << endl;
  cerr << "集合: " << m_S << " - " << m_S_comp << endl;
  cerr << endl;
  return;

}
