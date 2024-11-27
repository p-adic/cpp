// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/String/a_Body.hpp

#pragma once
#include "a.hpp"


inline CppClassForString operator+( const CppClassForString& arg1 , const CppClassForString& arg2 ) { return "GetPlus( " + ArgumentString( arg1 , arg2 ) + " )"; }

inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( - );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( * );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( / );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( % );

inline CppClassForString operator^( const CppClassForString& arg1 , const CppClassForString& arg2 ) { return "GetPower( " + ArgumentString( arg1 , arg2 ) + " )"; }

inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( == );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( != );

inline CppClassForString operator<=( const CppClassForString& arg1 , const CppClassForString& arg2 ) { return "GetLeq( " + ArgumentString( arg1 , arg2 ) + " )"; }
inline CppClassForString operator>=( const CppClassForString& arg1 , const CppClassForString& arg2 ) { return arg2 <= arg1; }

inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( < );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( > );

inline CppClassForString operator!( const CppClassForString& arg ) { return "!" + WrapInParenthesis( ArgumentString( arg ) ); }

inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( && );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( || );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( ->* );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( >> );
inline DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( << );

