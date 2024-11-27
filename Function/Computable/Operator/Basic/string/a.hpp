// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/string/a.hpp

#pragma once
#include "../../a.hpp"
#include "../../../Type/Basic/a.hpp"


template <> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( string , Plus );

inline DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( string , + );


inline const PrettyFunction<nat,string>& LengthSymbol();
inline PrettyExpression<nat> LengthSymbolApplication( const ExpressionOfComputableFunction<string>& s );

inline const PrettyFunction<string,string,nat>& EntryAccessSymbol();
inline ExpressionOfComputableFunction<string> EntryAccessSymbolApplication( const ExpressionOfComputableFunction<string>& s , const PrettyExpression<nat>& n );

inline const PrettyFunction<string,string,nat>& InitialSegmentSymbol();
inline ExpressionOfComputableFunction<string> InitialSegmentSymbolApplication( const ExpressionOfComputableFunction<string>& s , PrettyExpression<nat> n );

inline const PrettyFunction<string,string,nat>& FinalSegmentSymbol();
inline ExpressionOfComputableFunction<string> FinalSegmentSymbolApplication( const ExpressionOfComputableFunction<string>& s , PrettyExpression<nat> n );
