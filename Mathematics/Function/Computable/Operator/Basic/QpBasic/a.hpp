// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Basic/QpBasic/a.hpp

#pragma once
#include "../../a.hpp"

// ハイパー演算子
inline const PrettyFunction<nat,nat,nat,nat>& ArrowSymbol() noexcept;
inline PrettyExpression<nat> Arrow( const PrettyExpression<nat>& a , const PrettyExpression<nat>& b , const PrettyExpression<nat>& c ) noexcept;

// チェーン表記
inline const PrettyVariadicFunction<nat,nat,nat>& ChainSymbol() noexcept;
template <typename... Args> inline PrettyExpression<nat> Chain( const PrettyExpression<nat>& a , const Args&... args ) noexcept;

// N原始
inline const PrettyVariadicFunction<string,nat,string>& NPrimitiveSymbol_Body_1() noexcept;
inline const PrettyFunction<nat,string,nat>& NPrimitiveSymbol_Body_2() noexcept;
template <typename... Args> inline PrettyExpression<nat> N( const ExpressionOfComputableFunction<string>& version , const PrettyExpression<nat>& a , const Args&... args ) noexcept;

