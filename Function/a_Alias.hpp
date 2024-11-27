// c:/Users/user/Documents/Programming/Mathematics/Function/a_Alias.hpp

#pragma once

template <typename Ret , typename... Args>
using FunctionType = Ret( Args&... );

template <typename Ret , typename... Args>
using FunctionPointerType = Ret(*)( Args&... );

template <typename Ret , typename... Args>
using NoexceptFunctionPointerType = Ret(*)( Args&... ) noexcept;

template <typename Ret , typename T , typename... Args>
using MemberFunctionPointerType = Ret( T::* )( Args&... );

template <typename Ret , typename T , typename... Args>
using ConstMemberFunctionPointerType = Ret( T::* )( Args&... ) const;

template <typename Ret , typename T , typename... Args>
using NoexceptMemberFunctionPointerType = Ret( T::* )( Args&... ) noexcept;

template <typename Ret , typename T , typename... Args>
using ConstNoexceptMemberFunctionPointerType = Ret( T::* )( Args&... ) const noexcept;
