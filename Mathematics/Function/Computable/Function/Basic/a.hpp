// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a.hpp

#pragma once
#include "../../Syntax/Basic/a.hpp"

inline const FunctionSymbol<int,int,int,int>& ArrowSymbol() noexcept;
inline ExpressionOfComputableFunction<int> Arrow( const ExpressionOfComputableFunction<int>& a , const ExpressionOfComputableFunction<int>& b , const ExpressionOfComputableFunction<int>& c ) noexcept;

inline const VariadicFunctionSymbol<int,int>& ChainSymbol() noexcept;
template <typename... Args> inline ExpressionOfComputableFunction<int> Chain( const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept;

inline const VariadicFunctionSymbol<int,string,int>& NPrimitiveSymbol() noexcept;
template <typename... Args> inline ExpressionOfComputableFunction<int> N( const ExpressionOfComputableFunction<string>& version , const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept;

