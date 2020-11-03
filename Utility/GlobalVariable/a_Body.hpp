// c:/Users/user/Documents/Programming/Utility/GlobalVariable/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../List/LabeledList/a_Body.hpp"
#include "../../SFINAE/MemberFunction/Constructor/a_Body.hpp"

template <typename T , typename... Args>
const T* const to_GlobalConstant( const string& name , const Args&... args )
{

  static auto g_t = LabeledList<const T*,string>();
  
  if( ! g_t.Contain( name ) ){
    
    const T* const p_t = new T( args... );
    g_t.Insert( name , p_t );

  }
  
  return g_t( name );

}

template <typename T , typename... Args>
T* const to_GlobalVariable( const string& name , const Args&... args )
{

  static auto g_t = LabeledList<T*,string>();
  
  if( ! g_t.Contain( name ) ){
    
    T* const p_t = new T( args... );
    g_t.Insert( name , p_t );

  }
  
  return g_t( name );

}

template <typename T , typename... Args>
T* to_GlobalPointer( const string& name , const Args&... args )
{

  static auto g_p_t = LabeledList<T*,string>();

  if( ! g_p_t.Contain( name ) ){
    
    T* p_t = new T( args... );
    g_p_t.Insert( name , p_t );

  }
  
  return g_p_t( name );

}
