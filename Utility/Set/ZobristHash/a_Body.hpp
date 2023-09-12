// c:/Users/user/Documents/Programming/Utility/Set/ZobristHash/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline ZobristHashBody<T>::ZobristHashBody( const ull& hash ) : m_hash( hash ) {}
inline ZobristHash::ZobristHash( const ull& hash ) : ZobristHashBody<ull>( hash ) {}
template <typename T> inline MemorisationZobristHash<T>::MemorisationZobristHash( const ull& hash ) : ZobristHashBody<T>( hash ) {}
template <typename T , int enum_T_inv(const T&)> inline EnumerationZobristHash<T,enum_T_inv>::EnumerationZobristHash( const ull& hash ) : ZobristHashBody<T>( hash ) {}


template <typename T> ull ZobristHashBody<T>::Encode( const set<T>& S )
{

  ull answer = 0;

  for( auto itr = S.begin() , end = S.end() ; itr != end ; itr++ ){

    answer ^= Hash( *itr );

  }

  return answer;

}

template <typename T> inline ull ZobristHashBody<T>::Encode( const list<T>& S , const bool& non_overlapping ) { return non_overlapping ? NonOverlappingEncode( S ) : OverlappingEncode( S ); }

template <typename T> template <int length_max> inline ull ZobristHashBody<T>::Encode( const T ( &a )[length_max] , const int& length , const bool& non_overlapping ) { return non_overlapping ? NonOverlappingEncode( a , length ) : OverlappingEncode( a , length ); }

template <typename T> ull ZobristHashBody<T>::OverlappingEncode( const list<T>& S )
{

  set<T> S_set{};

  for( auto itr = S.begin() , end = S.end() ; itr != end ; itr++ ){

    S_set.insert( *itr );

  }

  return Encode( S_set );

}

template <typename T> template <int length_max> ull ZobristHashBody<T>::OverlappingEncode( const T ( &a )[length_max] , const int& length )
{

  set<T> S_set{};

  for( int i = 0 ; i < length ; i++ ){

    S_set.insert( a[i] );

  }

  return Encode( S_set );

}

template <typename T> ull ZobristHashBody<T>::NonOverlappingEncode( const list<T>& S )
{

  ull answer = 0;

  for( auto itr = S.begin() , end = S.end() ; itr != end ; itr++ ){

    answer ^= Hash( *itr );

  }

  return answer;
  
}

template <typename T> template <int length_max> ull ZobristHashBody<T>::NonOverlappingEncode( const T ( &a )[length_max] , const int& length )
{

  ull answer = 0;

  for( int i = 0 ; i < length ; i++ ){

    answer ^= Hash( a[i] );

  }

  return answer;

}

template <typename T> inline ull ZobristHashBody<T>::SymmetricDifference( const ull& code0 , const ull& code1 ) { return code0 ^ code1; }
template <typename T> inline ull ZobristHashBody<T>::Add( set<T>& S , const ull& code , const T& t ) { return S.count( t ) == 0 ? ( S.insert( t ) , code ^ Hash( t ) ) : code; }
template <typename T> inline ull ZobristHashBody<T>::Erase( set<T>& S , const ull& code , const T& t ) { return S.count( t ) == 0 ? code : ( S.erase( t ) , code ^ Hash( t ) ); }
template <typename T> inline ull ZobristHashBody<T>::AddErase( const ull& code , const T& t ){ return code ^ Hash( t ); }

inline ull ZobristHash::Hash( const ull& t ) { return t * ZobristHashBody<ull>::m_hash; }
template <typename T> inline ull MemorisationZobristHash<T>::Hash( const T& t ) { if( m_f.count( t ) == 0 ){ const ull size = m_f.size() + 1; return m_f[t] = size * ZobristHashBody<ull>::m_hash; } return m_f[t]; }
template <typename T , int enum_T_inv(const T&)> inline ull EnumerationZobristHash<T,enum_T_inv>::Hash( const T& t ) { return enum_T_inv( t ) * ZobristHashBody<T>::m_hash; }
