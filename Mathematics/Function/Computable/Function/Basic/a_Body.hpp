// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Syntax/Basic/a_Body.hpp"

inline const FunctionSymbol<int,int,int,int>& ArrowSymbol() noexcept { static const FunctionSymbol<int,int,int,int> f{ ArrowString() , SeparatorOfComputableFunction( 0 , EmptyString() , SpaceString() + ArrowString() + SupString() + LbraceString() , RbraceString() + SpaceString() , EmptyString() ) , VariableSymbol<int>( "a" ) , VariableSymbol<int>( "c" ) , VariableSymbol<int>( "b" ) }; return f; }
inline ExpressionOfComputableFunction<int> Arrow( const ExpressionOfComputableFunction<int>& a , const ExpressionOfComputableFunction<int>& b , const ExpressionOfComputableFunction<int>& c ) noexcept { return ArrowSymbol()( a , c , b ); }

inline const VariadicFunctionSymbol<int,int>& ChainSymbol() noexcept { static const VariadicFunctionSymbol<int,int> f{ ToString() , SeparatorOfComputableFunction( 0 , EmptyString() , SpaceString() + ToString() + SupString() , LdotsString() , SpaceString() + ToString() + SupString() , EmptyString() ) , VariableSymbol<int>( "a" ) }; return f; }
template <typename... Args> inline ExpressionOfComputableFunction<int> Chain( const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept { return ChainSymbol()( a , args... ); }

inline const VariadicFunctionSymbol<int,string,int>& NPrimitiveSymbol() noexcept { static const VariadicFunctionSymbol<int,string,int> f{ ToString() , SeparatorOfComputableFunction( 0 , to_string( "N" ) , LbrackString() , RbrackString() + LparenString() , LdotsString() , CommaString() , RparenString() ) , VariableSymbol<string>( "version" ) , VariableSymbol<int>( "a" ) }; return f; }
template <typename... Args> inline ExpressionOfComputableFunction<int> N( const ExpressionOfComputableFunction<string>& version , const ExpressionOfComputableFunction<int>& a , const Args&... args ) noexcept { return NPrimitiveSymbol()( version , a , args... ); }
