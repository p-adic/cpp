// c:/Users/user/Documents/Programming/Utility/GlobalVariable/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

template <typename T , typename Arg1 , typename... Arg2> auto to_GlobalConstant( const string& name , const Arg1& func , const Arg2&... args ) -> typename OriginalToGlobalConstant<T,Arg1,Arg2...>::type;
template <typename T , typename Arg1 , typename... Arg2> inline auto to_GlobalConstant( const string& name , const Arg1& arg1 , const Arg2&... arg2 ) -> typename DeligatingToGlobalConstant<T,Arg1,Arg2...>::type;

template <typename T , typename Arg1 , typename... Arg2> auto to_GlobalVariable( const string& name , const Arg1& func , const Arg2&... args ) -> typename OriginalToGlobalVariable<T,Arg1,Arg2...>::type;
template <typename T , typename Arg1 , typename... Arg2> inline auto to_GlobalVariable( const string& name , const Arg1& arg1 , const Arg2&... arg2 ) -> typename DeligatingToGlobalVariable<T,Arg1,Arg2...>::type;

template <typename T , typename Arg1 , typename... Arg2> auto to_GlobalPointer( const string& name , const Arg1& func , const Arg2&... args ) -> typename OriginalToGlobalPointer<T,Arg1,Arg2...>::type;
template <typename T , typename Arg1 , typename... Arg2> inline auto to_GlobalPointer( const string& name , const Arg1& arg1 , const Arg2&... arg2 ) -> typename DeligatingToGlobalPointer<T,Arg1,Arg2...>::type;
