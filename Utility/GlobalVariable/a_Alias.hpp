// GlobalVariable/a_Alias.hpp

#include "../../Mathematics/Function/a.hpp"

template <typename T , typename Arg1 , typename... Arg2>
using OriginalToGlobalConstant = enable_if< is_same< Arg1 , FunctionType<T,Arg2...> >::value , const T* const >;

template <typename T , typename Arg1 , typename... Arg2>
using DeligatingToGlobalConstant = enable_if< ! is_same< Arg1 , FunctionType<T,Arg2...> >::value , const T* const >;

template <typename T , typename Arg1 , typename... Arg2>
using OriginalToGlobalVariable= enable_if< is_same< Arg1 , FunctionType<T,Arg2...> >::value , T* const >;

template <typename T , typename Arg1 , typename... Arg2>
using DeligatingToGlobalVariable = enable_if< ! is_same< Arg1 , FunctionType<T,Arg2...> >::value , T* const >;

template <typename T , typename Arg1 , typename... Arg2>
using OriginalToGlobalPointer = enable_if< is_same< Arg1 , FunctionType<T,Arg2...> >::value , T*>;

template <typename T , typename Arg1 , typename... Arg2>
using DeligatingToGlobalPointer = enable_if< ! is_same< Arg1 , FunctionType<T,Arg2...> >::value , T*>;
