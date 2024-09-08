// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Multisubset/Debug/a_Body.hpp"

template <typename INT> inline NonNegativeLineMultiSubset<INT>::NonNegativeLineMultiSubset( const INT& ubound ) : VirtualBoundedLineMultiSubset<INT,const INT&,const INT&>()
{

  assert( -1 <= ubound );
  this->m_lbound = 0;
  this->m_ubound = ubound;
  this->m_name = "NonNegativeLineMultiSubset";
  this->m_ds.Initialise( this->m_ubound + 1 , false );
  cerr << this->m_name << "���f�o�b�O���[�h�Ŏ��s���܂��B" << endl;
  cerr << "�e�����̌v�Z�ʂ�O(size)�����邱�Ƃɒ��ӂ��Ă��������B" << endl;
  this->Display();
  cerr << endl;

}
template <typename INT> inline bool NonNegativeLineMultiSubset<INT>::InRange( const INT& i ) { return this->m_lbound <= i && i <= this->m_ubound; }
template <typename INT> inline constexpr const INT& NonNegativeLineMultiSubset<INT>::Normalise( const INT& i ) { return i; }
template <typename INT> inline constexpr const INT& NonNegativeLineMultiSubset<INT>::Denormalise( const INT& d ) { return d; }