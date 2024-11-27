// c:/Users/user/Documents/Programming/Utility/Set/ZobristHash/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/942404（対称差）

#include "../Mathematics/Function/Map/a.hpp"
#include "a_Alias.hpp"

template <typename T>
class ZobristHashBody
{

protected:
  ull m_hash;

public:
  inline ZobristHashBody( const ull& hash );

  ull Encode( const set<T>& S );
  template <template <typename...> typename V> inline ull Encode( const V<T>& S , const bool& non_overlapping = false );

  inline ull SymmetricDifference( const ull& code0 , const ull& code1 );
  inline ull Add( set<T>& S , const ull& code , const T& t );
  inline ull Erase( set<T>& S , const ull& code , const T& t );
  inline ull AddErase( const ull& code , const T& t );
  
private:
  template <template <typename...> typename V> ull OverlappingEncode( const V<T>& S );
  template <template <typename...> typename V> ull NonOverlappingEncode( const V<T>& S );
  virtual ull Hash( const T& t ) = 0;

};

// 集合のコードO(要素数)
// リストの像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）
// 配列の像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）

// 集合の対称差O(1)
// 要素追加O(log要素数)
// 要素削除O(log要素数)
// 要素がある場合は削除、ない場合は追加O(1)
class ZobristHash :
  public ZobristHashBody<ull>
{

public:
  inline ZobristHash( const ull& hash = 14177381365537266759ULL );
  
private:
  inline ull Hash( const ull& t );

};

// 集合のコードO(要素数 log_size)
// リストの像のコードO(要素数(log 要素数)(log size))（無重複保証畤はO(要素数 log size)）
// 配列の像のコードO(要素数(log 要素数)(log size))（無重複保証畤はO(要素数 log size)）

// 集合の対称差O(1)
// 要素追加O((log要素数)(log size))
// 要素削除O((log要素数)(log size))
// 要素がある場合は削除、ない場合は追加O(log size)
template <typename T>
class MemorisationZobristHash :
  public ZobristHashBody<T>
{

private:
  Map<T,ull> m_f;
  
public:
  inline MemorisationZobristHash( const ull& hash = 14177381365537266759ULL );
  
private:
  inline ull Hash( const T& t );

};

// 集合のコードO(要素数)
// リストの像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）
// 配列の像のコードO(要素数 log 要素数)（無重複保証畤はO(要素数)）

// 集合の対称差O(1)
// 要素追加O(log要素数)
// 要素削除O(log要素数)
// 要素がある場合は削除、ない場合は追加O(1)
template <typename T , int enum_T_inv(const T&)>
class EnumerationZobristHash :
  public ZobristHashBody<T>
{

public:
  inline EnumerationZobristHash( const ull& hash = 14177381365537266759ULL );
  
private:
  inline ull Hash( const T& t );

};

