// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Iterator/a_Body.hpp"

template <typename INT> inline LineSubset<INT>::LineSubset() :
  m_l() , m_size() , m_set()
{

  cerr << "LineSubsetをデバッグモードで実行します。" << endl;
  cerr << "各計算量にO(m_size)が加わることに注意してください。" << endl;
  Display();

}

template <typename INT>
void LineSubset<INT>::insert( const INT& i ) noexcept
{

  auto itr0 = m_l.lower_bound( i - 1 ) , end = m_l.end();

  if( itr0 == end ){

    m_l[i] = i;
    m_size++;
    assert( m_set.count( i ) == 0 );
    m_set.insert( i );
    cerr << "LineSubsetに" << i << "が挿入されました。" << endl;
    Display();
    return;

  }

  auto& [r0,l0] = *itr0;

  if( l0 <= i && i <= r0 ){

    assert( m_set.count( i ) == 1 );
    cerr << "LineSubsetに" << i << "の挿入を試みましたが元々属していました。" << endl;
    cerr << endl;
    return;

  }

  m_size++;

  if( i + 1 == l0 ){

    l0--;
    assert( m_set.count( i ) == 0 );
    m_set.insert( i );
    cerr << "LineSubsetに" << i << "が挿入されました。" << endl;
    Display();
    return;

  }

  if( i + 1 < l0 ){

    m_l[i] = i;
    assert( m_set.count( i ) == 0 );
    m_set.insert( i );
    cerr << "LineSubsetに" << i << "が挿入されました。" << endl;
    Display();
    return;

  }
  
  auto itr1 = m_l.lower_bound( i + 1 );

  if( itr1 == end ){

    m_l[i] = l0;

  } else {
    
    auto& [r1,l1] = *itr1;

    if( i + 1 < l1 ){

      m_l[i] = l0;

    } else {
    
      l1 = l0;

    }

  }
  
  m_l.erase( itr0 );
  assert( m_set.count( i ) == 0 );
  m_set.insert( i );
  cerr << "LineSubsetに" << i << "が挿入されました。" << endl;
  Display();
  return;

}

template <typename INT>
void LineSubset<INT>::erase( const INT& i ) noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    assert( m_set.count( i ) == 0 );
    cerr << "LineSubsetから" << i << "の削除を試みましたが元々属していませんでした。" << endl;
    return;

  }

  auto& [r,l] = *itr;

  if( i < l ){

    assert( m_set.count( i ) == 0 );
    cerr << "LineSubsetから" << i << "の削除を試みましたが元々属していませんでした。" << endl;
    return;

  }

  m_size--;

  if( l < i ){

    m_l[i-1] = l;

  }

  if( i == r ){

    m_l.erase( itr );

  } else {

    l = i + 1;

  }
  
  assert( m_set.count( i ) == 1 );
  m_set.erase( i );
  cerr << "LineSubsetから" << i << "が削除されました。" << endl;
  Display();
  return;

}

template <typename INT> inline IteratorOfLineSubset<INT>& LineSubset<INT>::erase( IteratorOfLineSubset<INT>& itr )
{

  m_size--;
  INT i = *itr;
  auto [l,r] = itr.ConnectedComponent();
  auto& itr_ref = itr.erase_from( m_l );
  assert( m_set.count( i ) == 1 );
  m_set.erase( i );
  cerr << "LineSubsetから" << i << "in [" << l << "," << r << "]が削除されました。" << endl;
  Display();

}

template <typename INT> inline int LineSubset<INT>::count( const INT& i ) const noexcept { return find( i ) ? 1 : 0; }

template <typename INT>
bool LineSubset<INT>::find( const INT& i ) const noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    return false;

  }

  return itr->second <= i;

}

template <typename INT> inline const int& LineSubset<INT>::size() const noexcept { return m_size; }
template <typename INT> inline bool LineSubset<INT>::empty() const noexcept { return m_size == 0; }

template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::begin() const noexcept { return IteratorOfLineSubset<INT>{ m_l , m_l.begin() , m_l.empty() ? 0 : m_l.begin()->second }; }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::end() const noexcept { return IteratorOfLineSubset<INT>{ m_l , m_l.end() , 0 }; }

template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MaximumLeq( const INT& i ) const noexcept { auto itr = m_l.lower_bound( i ); if( itr != m_l.end() && itr->second <= i ){ return IteratorOfLineSubset<INT>( m_l , itr , i ); } if( itr == m_l.begin() ){ return end(); } --itr; return IteratorOfLineSubset<INT>{ m_l , itr , itr->first }; }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MaximumLt( const INT& i ) const noexcept { auto itr = m_l.lower_bound( i ); if( itr != m_l.end() && itr->second < i ){ return IteratorOfLineSubset<INT>( m_l , itr , i - 1 ); } if( itr == m_l.begin() ){ return end(); } --itr; return IteratorOfLineSubset<INT>{ m_l , itr , itr->first }; }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MinimumGeq( const INT& i ) const noexcept { auto itr = m_l.lower_bound( i ); return itr == m_l.end() ? end() : IteratorOfLineSubset<INT>( m_l , itr , max( i , itr->second ) ); }
template <typename INT> inline IteratorOfLineSubset<INT> LineSubset<INT>::MinimumGt( const INT& i ) const noexcept { auto itr = m_l.upper_bound( i ); return itr == m_l.end() ? end() : IteratorOfLineSubset<INT>( m_l , itr , max( i + 1 , itr->second ) ); }

template <typename INT> inline INT LineSubset<INT>::Maximum() const { assert( !m_l.empty() ); return ( --m_l.end() )->first; }
template <typename INT> inline INT LineSubset<INT>::Minimum() const { assert( !m_l.empty() ); return m_l.begin()->second; }

template <typename INT>
pair<INT,INT> LineSubset<INT>::ConnectedComponentOf( const INT& i ) const noexcept
{

  auto itr = m_l.lower_bound( i );

  if( itr == m_l.end() ){

    return {i+1,i-1};

  }

  return itr->second <= i ? pair<INT,INT>{itr->second,itr->first} : pair<INT,INT>{i+1,i-1};

}

template <typename INT> inline const map<INT,INT>& LineSubset<INT>::GetConnectedComponent() const noexcept { return m_l; }


template <typename INT> inline void LineSubset<INT>::Display() const noexcept
{

  cerr << "要素数: " << m_size << endl;
  cerr << "集合: " << m_set << endl;
  cerr << "区間列:";

  for( auto& [r,l] : m_l ){

    cerr << " [" << l << "," << r << "]";

  }
  
  cerr << endl;
  cerr << endl;

}
