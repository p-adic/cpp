// c:/Users/user/Documents/Programming/Mathematics/Function/a_Alias.hpp

#pragma once

template <typename Ret , typename... Args>
using FunctionType = Ret( const Args&... );

template <typename Ret , typename... Args>
using FunctionPointerType = Ret(*)( const Args&... );

template <typename Ret , typename T , typename... Args>
using MemberFunctionPointerType = Ret( T::* )( const Args&... );

template <typename Ret , typename T , typename... Args>
using ConstMemberFunctionPointerType = Ret( T::* )( const Args&... ) const;

template <typename Ret , typename T , typename... Args>
using NoexceptMemberFunctionPointerType = Ret( T::* )( const Args&... ) noexcept;

template <typename Ret , typename T , typename... Args>
using ConstNoexceptMemberFunctionPointerType = Ret( T::* )( const Args&... ) const noexcept;
