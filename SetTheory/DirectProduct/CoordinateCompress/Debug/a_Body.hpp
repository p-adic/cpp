// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompress<INT>::CoordinateCompress() : m_r() , m_l()
{

  static bool init = true;

  if( init ){

    cerr << "CoordinateCompressをデバッグモードで実行します。" << endl;
    cerr << "エラー出力以外は変わりません。" << endl;
    init = false;

  }

}

template <typename INT> inline void CoordinateCompress<INT>::SetR( INT t ) { m_r.insert( move( t ) ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetR( V<U> a ) { for( auto& t : a ){ SetR( move( t ) ); } }

template <typename INT>
pair<vector<INT>,unordered_map<INT,int>> CoordinateCompress<INT>::GetR()
{

  pair<vector<INT>,unordered_map<INT,int>> answer{};
  answer.first.resize( m_r.size() );
  int i = 0;

  cerr << "CoordinateCompress::GetR()で、登録された右辺値を座標圧縮します。" << endl;
  cerr << "登録された右辺値全体の集合は { " << m_r << " } です。" << endl;
  cerr << "小さい順にそれぞれ以下のように変換します：" << endl;

  for( auto t : m_r ){

    cerr << t << " -> " << i << endl;
    answer.first[i] = t;
    answer.second[t] = i++;

  }

  cerr << "座標圧縮を終了します。" << endl;
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearR() { m_r.clear(); }

template <typename INT> inline void CoordinateCompress<INT>::SetL( INT& t ) { m_l.push_back( &t ); }
template <typename INT> template <typename U , template <typename...> typename V > inline void CoordinateCompress<INT>::SetL( V<U>& a ) { for( auto& t : a ){ SetL( t ); } }

template <typename INT>
vector<INT> CoordinateCompress<INT>::GetL()
{

  int i = -1;
  vector<INT> answer{};
  cerr << "CoordinateCompress::GetR()で、登録された左辺値を座標圧縮します。" << endl;

  if( m_l.empty() ){

    cerr << "登録された左辺値はありませんでした。";

  } else {

    cerr << "登録された左辺値は登録順に ( ";
    int size = m_l.size();
  
    for( int j = 0 ; j < size ; j++ ){

      ( j == 0 ? cerr : cerr << " " ) << *( m_l[j] );

    }
  
    cerr << " ) です。" << endl;
    auto comp = []( INT* const& p0 , INT* const& p1 ) { return *p0 < *p1; };
    sort( m_l.begin() , m_l.end() , comp );
    INT temp = *( m_l[0] ) - 1;
    cerr << "小さい順にそれぞれ以下のように変換します：" << endl;

    for( auto p : m_l ){

      cerr << *p << " -> ";
      *p = temp == *p ? i : ( answer.push_back( temp = *p ) , ++i );
      cerr << i << endl;		    

    }

  }

  cerr << "変換前の左辺値全体の集合は { " << answer << " } です。" << endl;
  cerr << "座標圧縮を終了します。" << endl;
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearL() { m_l.clear(); }

