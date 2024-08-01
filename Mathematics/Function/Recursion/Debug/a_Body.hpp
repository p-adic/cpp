// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/Random/a_Body.hpp"

string CURRENT_NAME_FOR_RECURSION = "";

template <typename REC> inline NonMemorisationRecursion<REC>::NonMemorisationRecursion( REC rec ) : REC( move( rec ) ) , m_name( CURRENT_NAME_FOR_RECURSION )
{

  static bool init = true;

  if( init ){
    
    cerr << "NonMemorisationRecursion " << m_name << " をデバッグモードで実行します。" << endl;
    cerr << "エラー出力以外に変更はありません。" << endl;
    init = false;

  }

}

template <typename REC> inline MemorisationRecursion<REC>::MemorisationRecursion( REC rec ) : REC( move( rec ) ) , m_name( CURRENT_NAME_FOR_RECURSION )
{

  static bool init = true;

  if( init ){
    
    cerr << "MemorisationRecursion " << m_name << " をデバッグモードで実行します。" << endl;
    cerr << "エラー出力以外に変更はありません。" << endl;
    init = false;

  }

}

template <typename REC> template <typename...Args>
inline ret_t<REC,NonMemorisationRecursion<REC>&,const Args&...> NonMemorisationRecursion<REC>::operator()( const Args&... args )
{

  auto answer = REC::operator()( *this , args... );
  cerr << "非メモ化再帰： " << m_name << "(" << tuple<Args...>{ args... } << ") = " << answer << endl;
  return answer;

}

template <typename REC> template <typename...Args>
inline const ret_t<REC,MemorisationRecursion<REC>&,const Args&...>& MemorisationRecursion<REC>::operator()( const Args&... args )
{

  static unordered_map<tuple<Args...>,ret_t<REC,MemorisationRecursion<REC>&,const Args&...>> memory{};
  const tuple<Args...> v{ args... };

  if( memory.count( v ) == 0 ){

    auto& answer = memory[v] = REC::operator()( *this , args... );
    cerr << "メモ化再帰： " << m_name << "(" << v << ") = " << answer << endl;
    return answer;

  }
  
  return memory[v];

}
