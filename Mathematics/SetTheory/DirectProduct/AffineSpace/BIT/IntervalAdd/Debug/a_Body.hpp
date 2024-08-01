// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"

template <typename U , typename Z_MODULE> AbstractIntervalAddBIT<U,Z_MODULE>::AbstractIntervalAddBIT( Z_MODULE M , const int& size ) : AbstractIntervalAddBIT( M , vector<U>( size , m_M.Zero() ) ) {}
template <typename U , typename Z_MODULE> AbstractIntervalAddBIT<U,Z_MODULE>::AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a ) : m_M( move( M ) ) , m_size( a.size() ) , m_a( a )
{

  static bool init = true;

  if( init ){

    cerr << "IntervalAddBITをデバッグモードで実行します。" << endl;
    cerr << "通常のIntervalBITと比べると一点取得にconst修飾がつき各種操作にO(N)かかる" << endl;
    cerr << "ことにご注意ください。" << endl;
    cerr << endl;
    init = false;

  }

  cerr << "IntervalAddBITの初期値：" << endl;
  cerr << *this << endl;
  cerr << endl;
  
}

template <typename U>  template <typename...Args> inline IntervalAddBIT<U>::IntervalAddBIT( const Args&... args ) : AbstractIntervalAddBIT<U,Module<int,U>>( Module<int,U>() , args... ) {}

template <typename U , typename Z_MODULE> template <typename...Args> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Initialise( const Args&... args ) { AbstractIntervalAddBIT<U,Z_MODULE> temp{ m_M , args... }; m_a = move( temp.m_a ); }
template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Set( const int& i , const U& u ) { Add( i , m_M.Sum( m_M.Inverse( IntervalSum( i , i ) ) , u ) ); }

template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Add( const int& i , const U& u ) { assert( 0 <= i && i < size() ); IntervalAdd( i , i , u ); }
template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::IntervalAdd( const int& i_start , const int& i_final , const U& u )
{

  cerr << "IntervalAddBITの区間[" << i_start << "," << i_final << "]に" << u << "を加算します。" << endl;

  for( int i = max( 0 , i_start ) ; i <= min( i_final , m_size - 1 ) ; i++ ){

    m_a[i] = m_M.Sum( move( m_a[i] ) , u );

  }

  cerr << "IntervalAddBITの更新後の成分：" << endl;
  cerr << *this << endl;
  cerr << endl;
  return;
  
}


template <typename U , typename Z_MODULE> inline const int& AbstractIntervalAddBIT<U,Z_MODULE>::size() const noexcept { return m_size; }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[i]; }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::Get( const int& i ) const { return operator[]( i ); }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::InitialSegmentSum( const int& i_final ) { return IntervalSum( 0 , i_final ); }

template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::IntervalSum( const int& i_start , const int& i_final )
{

  U answer = m_M.Zero();

  for( int i = max( 0 , i_start ) ; i <= min( i_final , m_size - 1 ) ; i++ ){

    answer = m_M.Sum( move( answer ) , m_a[i] );

  }

  cerr << "IntervalAddBITの区間[" << i_start << "," << i_final << "] における総和： " << answer << endl;
  cerr << endl;
  return answer;

}


template <class Traits , typename U , typename Z_MODULE> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractIntervalAddBIT<U,Z_MODULE>& bit )
{

  auto&& size = bit.size();
  os << "{ ";

  for( int i = 0 ; i < size ; i++ ){

    os << bit[i] << " ";

  }

  return os << "}";

}
