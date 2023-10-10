// c:/Users/user/Documents/Programming/Error/BreakPoint/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../Utility/StdStream/a_Body.hpp"

inline FlagCounter::FlagCounter( const uint& i0 , const uint& i1 ) noexcept :
  m_i0( i0 ) ,
  m_i1( i1 ) ,
  m_count( 0 ) ,
  m_b( false )
{}

inline void FlagCounter::operator++( int ) noexcept { m_count++; }

inline const uint& FlagCounter::i0() const noexcept { return m_i0; }
inline const uint& FlagCounter::i1() const noexcept { return m_i1; }

inline const bool& FlagCounter::IsActive() const noexcept { return m_b; }

inline void B( const char* const FILE , const int& LINE , const char* const FUNC ) noexcept {}
template <typename... ARGS> inline void BreakPoint( const char* const FILE , const int& LINE , const char* const FUNC , const ARGS&... args ) noexcept { VariadicCout( cerr , "BreakPoint" , args... ) << endl; B( FILE , LINE , FUNC ); }

template <typename... ARGS>
void CountCall( const char* const FILE , const int& LINE , const char* const FUNC , const uint& i0 , const uint& i1 , const ARGS&... i2 ) noexcept
{

  if( CallFlagContainer( true , i2... ) ){
    
    CallFlagContainer( false , i0 , i1 , i2... );

  }

  if( CallFlagContainer( true , i0 , i1 , i2... ) ){
    
    BreakPoint( FILE , LINE , FUNC );

  }
  
  return;

}

inline bool CallFlagContainer( const bool& CalledForCheck ) noexcept { return true; }

template <typename... ARGS>
bool CallFlagContainer( const bool& CalledForCheck , const uint& i0 , const uint& i1 , const ARGS&... i2 ) noexcept
{

  static auto flag = FlagCounter( i0 , i1 );

  // FLAG以外での呼び出し（カウンターを増やさない）
  if( CalledForCheck ){

    flag.CheckActive();
    return flag.IsActive();

  }

  // FLAGでの呼び出し（カウンターを増やす）
  if( CallFlagContainer( true , i2... ) ){
    
    flag++;

  }

  if( flag.i1() == 0 ){

    flag.Set( i0 , i1 );

  }
  
  return false;

}
