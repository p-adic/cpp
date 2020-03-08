// c:/Users/user/Documents/Programming/Utility/GlobalVariable/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../List/LabeledList/a_Body.hpp"
#include "../../SFINAE/MemberFunction/Constructor/a_Body.hpp"

template <typename T , typename Arg1 , typename... Arg2>
auto to_GlobalConstant( const string& name , const Arg1& func , const Arg2&... args ) -> typename OriginalToGlobalConstant<T,Arg1,Arg2...>::type
{

  static auto g_t = LabeledList<const T*,string>();
  
  if( ! g_t.Contain( name ) ){
    
    const T* const p_t = new T( func( args... ) );
    g_t.Insert( name , p_t );

  }
  
  return g_t( name );

}

template <typename T , typename Arg1 , typename... Arg2> inline auto to_GlobalConstant( const string& name , const Arg1& arg1 , const Arg2&... arg2 ) -> typename DeligatingToGlobalConstant<T,Arg1,Arg2...>::type { return to_GlobalConstant<T,FunctionType<T,Arg1,Arg2...>,Arg1,Arg2...>( name , Construct<T,Arg1,Arg2...> , arg1 , arg2... ); }

template <typename T , typename Arg1 , typename... Arg2>
auto to_GlobalVariable( const string& name , const Arg1& func , const Arg2&... args ) -> typename OriginalToGlobalVariable<T,Arg1,Arg2...>::type
{

  static auto g_t = LabeledList<T*,string>();
  
  if( ! g_t.Contain( name ) ){
    
    T* const p_t = new T( func( args... ) );
    g_t.Insert( name , p_t );

  }
  
  return g_t( name );

}

template <typename T , typename Arg1 , typename... Arg2> inline auto to_GlobalVariable( const string& name , const Arg1& arg1 , const Arg2&... arg2 ) -> typename DeligatingToGlobalVariable<T,Arg1,Arg2...>::type { return to_GlobalVariable<T,FunctionType<T,Arg1,Arg2...>,Arg1,Arg2...>( name , Construct<T,Arg1,Arg2...> , arg1 , arg2... ); }

template <typename T , typename Arg1 , typename... Arg2>
auto to_GlobalPointer( const string& name , const Arg1& func , const Arg2&... args ) -> typename OriginalToGlobalPointer<T,Arg1,Arg2...>::type
{

  static auto g_p_t = LabeledList<T*,string>();

  if( ! g_p_t.Contain( name ) ){
    
    T* p_t = new T( func( args... ) );
    g_p_t.Innsert( name , p_t );

  }
  
  return g_p_t( name );

}

template <typename T , typename Arg1 , typename... Arg2> inline auto to_GlobalPointer( const string& name , const Arg1& arg1 , const Arg2&... arg2 ) -> typename DeligatingToGlobalPointer<T,Arg1,Arg2...>::type { return to_GlobalPointer<T,FunctionType<T,Arg1,Arg2...>,Arg1,Arg2...>( name , Construct<T,Arg1,Arg2...> , arg1 , arg2... ); }
