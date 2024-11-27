// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Tuple/a_Body.hpp"

template <typename REC> inline NonMemorisationRecursion<REC>::NonMemorisationRecursion( REC rec ) : REC( move( rec ) ) {}

template <typename REC> inline MemorisationRecursion<REC>::MemorisationRecursion( REC rec ) : REC( move( rec ) ) , m_num()
{

  static int num = -1;
  m_num = ++num;
  
}

template <typename REC> template <typename...Args> inline ret_t<REC,NonMemorisationRecursion<REC>&,const Args&...> NonMemorisationRecursion<REC>::operator()( const Args&... args ){ return REC::operator()( *this , args... ); }

template <typename REC> template <typename...Args> inline const ret_t<REC,MemorisationRecursion<REC>&,const Args&...>& MemorisationRecursion<REC>::operator()( const Args&... args )
{

  static unordered_map<tuple<Args...>,ret_t<REC,MemorisationRecursion<REC>&,const Args&...>> memory{};
  static int num = -1;

  if( num != m_num ){

    assert( num < m_num );
    num = m_num;
    memory.clear();

  }
  
  const tuple<Args...> v{ args... };
  return memory.count( v ) == 0 ? memory[v] = REC::operator()( *this , args... ) : memory[v];

}
