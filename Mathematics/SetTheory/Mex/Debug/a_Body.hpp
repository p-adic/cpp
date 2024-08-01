// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

inline MexSet::MexSet( const int& QuerySize ) : m_QuerySize( QuerySize ) , m_in( m_QuerySize + 1 ) , m_mex( 0 )
{

  cerr << "MexSetをデバッグモードで実行します。" << endl;
  cerr << "各種処理にO(m_QuerySize)の計算量がかかることに注意してください。" << endl;

}

inline void MexSet::insert( const int& i )
{

  assert( i >= 0 );

  cerr << "MexSetに " << i << " を追加します。" << endl;

  for( int j = 0 ; j < m_QuerySize ; j++ ){

    cerr << j << " : ";
    
    if( j == i ){

      cerr << m_in << " -> 1" << endl;

    } else {

      cerr << m_in << endl;

    }

  }

  cerr << "... : ..." << endl;

  if( i < m_QuerySize ){

    m_in[i] = true;

    while( m_in[m_mex] ){

      m_mex++;

    }

  }

}
inline const int& MexSet::Get() const noexcept
{

  cerr << "MexSetからmexを取得します。" << endl;

  for( int j = 0 ; j < m_QuerySize ; j++ ){

    cerr << j << " : " << m_in;

    if( j == m_mex ){

      cerr << " <- mex";

    }
      
    cerr << endl;

  }

  cerr << "... : ..." << endl;
  return m_mex;

}

