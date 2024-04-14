// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompress<INT>::CoordinateCompress() : m_r() , m_l() {}

template <typename INT> inline void CoordinateCompress<INT>::SetR( INT t ) { m_r.insert( move( t ) ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetR( V<U> a ) { for( auto& t : a ){ SetR( move( t ) ); } }

template <typename INT>
pair<vector<INT>,unordered_map<INT,int>> CoordinateCompress<INT>::GetR()
{

  pair<vector<INT>,unordered_map<INT,int>> answer{};
  answer.first.resize( m_r.size() );
  int i = 0;
    
  for( auto t : m_r ){

    answer.first[i] = t;
    answer.second[t] = i++;

  }

  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearR() { m_r.clear(); }

template <typename INT> inline void CoordinateCompress<INT>::SetL( INT& t ) { m_l.push_back( &t ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetL( V<U>& a ) { for( auto& t : a ){ SetL( t ); } }

template <typename INT>
int CoordinateCompress<INT>::GetL()
{

  int i = -1;

  if( !m_l.empty() ){

    auto comp = []( INT* const& p0 , INT* const& p1 ) { return *p0 < *p1; };
    sort( m_l.begin() , m_l.end() , comp );
    INT temp = *( m_l[0] ) - 1;

    for( auto p : m_l ){

      *p = temp == *p ? i : ( temp = *p , ++i );

    }

  }

  return ++i;

}

template <typename INT> inline void CoordinateCompress<INT>::clearL() { m_l.clear(); }

