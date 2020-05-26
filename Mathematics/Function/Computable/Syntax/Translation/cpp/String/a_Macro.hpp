// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/String/a_Macro.hpp

#pragma once

#define DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( OPER ) \
									\
  CppClassForString operator OPER ( const CppClassForString& arg1 , const CppClassForString& arg2 ) \
									\

#define DEFINITION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( OPER ) \
									\
  DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( OPER ) \
  {									\
									\
    return WrapInParenthesis( ArgumentString( arg1 ) ) + " " + TO_STRING( OPER ) + " " + WrapInParenthesis( ArgumentString( arg2 ) ); \
									\
  }									\



