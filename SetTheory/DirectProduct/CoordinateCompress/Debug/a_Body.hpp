// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline CoordinateCompress<INT>::CoordinateCompress() : m_r() , m_l()
{

  static bool init = true;

  if( init ){

    DERR( "CoordinateCompress���f�o�b�O���[�h�Ŏ��s���܂��B" );
    DERR( "�G���[�o�͈ȊO�͕ς��܂���B" );
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

  DERR( "CoordinateCompress::GetR()�ŁA�o�^���ꂽ�E�Ӓl�����W���k���܂��B" );
  DERR( "�o�^���ꂽ�E�Ӓl�S�̂̏W���� {" , m_r , "} �ł��B" );
  DERR( "���������ɂ��ꂼ��ȉ��̂悤�ɕϊ����܂��F" );

  for( auto t : m_r ){

    DERR( t , "->" , i );
    answer.first[i] = t;
    answer.second[t] = i++;

  }

  DERR( "���W���k���I�����܂��B" );
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
  DERR( "CoordinateCompress::GetR()�ŁA�o�^���ꂽ���Ӓl�����W���k���܂��B" );

  if( m_l.empty() ){

    DERR( "�o�^���ꂽ���Ӓl�͂���܂���ł����B" );

  } else {

    DERRNS( "�o�^���ꂽ���Ӓl�͓o�^���� ( " );
    int size = m_l.size();
  
    for( int j = 0 ; j < size ; j++ ){

      DERR( j == 0 ? "" : " " , *( m_l[j] ) );

    }
  
    DERR( " ) �ł��B" );
    auto comp = []( INT* const& p0 , INT* const& p1 ) { return *p0 < *p1; };
    sort( m_l.begin() , m_l.end() , comp );
    INT temp = *( m_l[0] ) - 1;
    DERR( "���������ɂ��ꂼ��ȉ��̂悤�ɕϊ����܂��F" );

    for( auto p : m_l ){

      DERRNS( *p , " -> " );
      *p = temp == *p ? i : ( answer.push_back( temp = *p ) , ++i );
      DERR( i );		    

    }

  }

  DERR( "�ϊ��O�̍��Ӓl�S�̂̏W���� { " << answer << " } �ł��B" );
  DERR( "���W���k���I�����܂��B" );
  return answer;

}

template <typename INT> inline void CoordinateCompress<INT>::clearL() { m_l.clear(); }
