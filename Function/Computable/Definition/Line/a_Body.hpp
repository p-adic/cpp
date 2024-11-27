// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../../Expression/Primitive/bool/a_Body.hpp"
#include "../../Operator/a_Body.hpp"

template <typename Ret> DEFINITION_OF_LIST_OF_LINES( Ret );

template <typename Ret> inline LineOfDefinitionOfComputableFunction<Ret>::LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line ) : SyntaxOfComputableFunction( line.Get() ) {}

// IF
template <typename Ret> DEFINITION_OF_IF_LINE( Ret );
template <typename Ret> DEFINITION_OF_SUPPOSE_LINE( Ret );

template <typename... Rets> inline auto IfLine( const ConditionOfComputableFunction& condition , const Rets&... lines ) -> typename enable_if< less_equal<uint>()( 1 , sizeof...( Rets ) ) && IsValidListOfLines<typename CheckNonVoidTypeInLine<Rets...>::type,Rets...>::value , LineOfDefinitionOfComputableFunction<typename CheckNonVoidTypeInLine<Rets...>::type> >::type { return LineOfDefinitionOfComputableFunction<typename CheckNonVoidTypeInLine<Rets...>::type>( 0 , condition , lines... ); }


// RETURN
template <typename Ret> inline LineOfDefinitionOfComputableFunction<Ret>::LineOfDefinitionOfComputableFunction( const ExpressionOfComputableFunction<Ret>& ret ) : SyntaxOfComputableFunction( LineString() , ReturnString() , ret.Get() ) {}

template <typename Ret> inline LineOfDefinitionOfComputableFunction<Ret> ReturnLine( const ExpressionOfComputableFunction<Ret>& ret ){ return LineOfDefinitionOfComputableFunction( ret ); }
