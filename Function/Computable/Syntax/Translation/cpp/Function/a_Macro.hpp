// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Function/a_Macro.hpp

#pragma once

#define DECLARATION_OF_CPP_FUNCTION_PREPARATION( FUNC ) \
									\
  auto CONNECT( FUNC , StringApplication )( const Args&... args ) -> typename enable_if<! conjunction<is_same<Args,CppClassForString>...>::value,CppClassForString>::type \
									\
    
#define DEFINITION_OF_CPP_FUNCTION_PREPARATION( FUNC ) \
									\
  DECLARATION_OF_CPP_FUNCTION_PREPARATION( FUNC ){ return CONNECT( FUNC , StringApplication )( ArgumentString( args... ) ); } \

#define DECLARATION_OF_VARIADIC_CPP_FUNCTION( FUNC ) \
									\
  auto CONNECT( FUNC , StringApplication )( const Arg& arg , const Args&... args ) -> typename enable_if<is_same<Arg,CppClassForString>::value && conjunction<is_same<Args,CppClassForString>...>::value,CppClassForString>::type; \
									\
  template <typename... Args> inline DECLARATION_OF_CPP_FUNCTION_PREPARATION( FUNC ); \


#define DEFINITION_OF_VARIADIC_CPP_FUNCTION( FUNC ) \
									\
  auto CONNECT( FUNC , StringApplication )( const Arg& arg , const Args&... args ) -> typename enable_if<is_same<Arg,CppClassForString>::value && conjunction<is_same<Args,CppClassForString>...>::value,CppClassForString>::type { return ConcatenateWithSeparator( CONNECT( FUNC , String )() , WrapInParenthesis( arg ) , WrapInParenthesis( args )... ); } \
									\
  template <typename... Args> inline DEFINITION_OF_CPP_FUNCTION_PREPARATION( FUNC ); \


#define DECLARATION_OF_TWO_ARY_CPP_FUNCTION( FUNC ) \
									\
  auto CONNECT( FUNC , StringApplication )( const Arg1& arg1 , const Arg2& arg2 ) -> typename enable_if<is_same<Arg1,CppClassForString>::value && is_same<Arg2,CppClassForString>::value,CppClassForString>::type; \
									\
  template <typename... Args> inline DECLARATION_OF_CPP_FUNCTION_PREPARATION( FUNC ); \


#define DEFINITION_OF_TWO_ARY_CPP_FUNCTION( FUNC ) \
									\
  auto CONNECT( FUNC , StringApplication )( const Arg1& arg1 , const Arg2& arg2 ) -> typename enable_if<is_same<Arg1,CppClassForString>::value && is_same<Arg2,CppClassForString>::value,CppClassForString>::type { return ConcatenateWithSeparator( CONNECT( FUNC , String )() , WrapInParenthesis( arg1 ) , WrapInParenthesis( arg2 ) ); } \
									\
  template <typename... Args> inline DEFINITION_OF_CPP_FUNCTION_PREPARATION( FUNC ); \


#define DECLARATION_OF_ONE_ARY_CPP_FUNCTION( FUNC ) \
									\
  auto CONNECT( FUNC , StringApplication )( const Arg& arg ) -> typename enable_if<is_same<Arg,CppClassForString>::value,CppClassForString>::type; \
									\
  template <typename... Args> inline DECLARATION_OF_CPP_FUNCTION_PREPARATION( FUNC ); \


#define DEFINITION_OF_ONE_ARY_CPP_FUNCTION( FUNC ) \
									\
  auto CONNECT( FUNC , StringApplication )( const Arg& arg ) -> typename enable_if<is_same<Arg,CppClassForString>::value,CppClassForString>::type { return CONNECT( FUNC , String )() + WrapInParenthesis( arg ); } \
									\
  template <typename... Args> inline DEFINITION_OF_CPP_FUNCTION_PREPARATION( FUNC ); \


