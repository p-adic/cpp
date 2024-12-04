// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Multisubset/IntervalInsert/Debug/a_Body.hpp"

template <typename INT> inline IntervalInsertNonNegativeLineMultiSubset<INT>::IntervalInsertNonNegativeLineMultiSubset( const INT& ubound ) : VirtualIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>()
{

  assert( -1 <= ubound );
  this->m_lbound = 0;
  this->m_ubound = ubound;
  static int count = 0;
  this->m_name = "IntervalInsertNonNegativeLineMultiSubset" + to_string( count++ );
  this->m_ds.Initialise( int( this->m_ubound + 1 ) , false );

  if( this->m_output_mode ){
    
    DERR( this->m_name , "���f�o�b�O���[�h�Ŏ��s���܂��B" );

    static bool init = true;

    if( init ){

      init = true;
      DERR( "�e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӂ��Ă��������B" );

    }
    
    this->Display();
    DERR( "" );

  }
    
}

template <typename INT> inline bool IntervalInsertNonNegativeLineMultiSubset<INT>::InRange( const INT& i ) { return 0 <= i && i <= this->m_ubound; }
template <typename INT> inline constexpr const INT& IntervalInsertNonNegativeLineMultiSubset<INT>::Normalise( const INT& i ) { return i; }
template <typename INT> inline constexpr const INT& IntervalInsertNonNegativeLineMultiSubset<INT>::Denormalise( const INT& d ) { return d; }