// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Body/a_Macro.hpp

#pragma once

#define DECLARATION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL ExpressionOfComputableFunction( const int& dummy , const string& x , const TypeNameOfComputableFunction& type_name ) 

#define DECLARATION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( ARG ) ExpressionOfComputableFunction( const ARG & t )  

#define DECLARATION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( RET ) ExpressionOfComputableFunction( const FunctionSymbol< RET ,Args...>& f , const ExpressionOfComputableFunction<Args>&... args ) 

#define DECLARATION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( RET ) ExpressionOfComputableFunction( const VariadicFunctionSymbol< RET ,Args...>& f , const ExpressionOfComputableFunction<VA>&... va ) 

#define DECLARATION_OF_EXPRESSION_FOR_RELATION_SYMBOL ExpressionOfComputableFunction( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<Args>&... args ) 

#define DECLARATION_OF_EXPRESSION_FOR_VARIADIC_RELATION_SYMBOL ExpressionOfComputableFunction( const VariadicRelationSymbol<bool,Args...>& r , const ExpressionOfComputableFunction<VA>&... va ) 

#define SIGNATURE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( RET ) PushFunctionExpression( const FunctionSymbol< RET ,Args...>& f , const ExpressionOfComputableFunction<VA>&... va ) 

#define DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( RET ) void SIGNATURE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( RET ) 

#define SIGNATURE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( RET ) PushFunctionExpression( const FunctionSymbol< RET ,Args...>& f , const VA&... va ) 

#define TYPE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY typename enable_if<conjunction<is_same<VLTree<string>,VA>...>::value,void>::type 

#define DECLARATION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( RET ) auto SIGNATURE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( RET ) -> TYPE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY 

#define SIGNATURE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION PushRelationExpression( const RelationSymbol<Args...>& r , const ExpressionOfComputableFunction<VA>&... va ) 

#define DECLARATION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION void SIGNATURE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION 

#define SIGNATURE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY PushRelationExpression( const RelationSymbol<Args...>& r , const VA&... va ) 

#define TYPE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY TYPE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY 

#define DECLARATION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY auto SIGNATURE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY -> TYPE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY 

#define SIGNATURE_OF_SET_SYMBOL_FOR_EXPRESSION Set( const string& dummy , const string& f ) 

#define DECLARATION_OF_SET_SYMBOL_FOR_EXPRESSION void SIGNATURE_OF_SET_SYMBOL_FOR_EXPRESSION 



#define DEFINITION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL( RET ) ExpressionOfComputableFunction< RET >:: DECLARATION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL : SyntaxOfComputableFunction( ExpressionString() , VariableString() , x , type_name.Get() ) {} 

#define DEFINITION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( RET , ARG , SYMB ) ExpressionOfComputableFunction< RET >:: DECLARATION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( ARG ) : SyntaxOfComputableFunction( ExpressionString(), ConstantString() , SYMB , GetTypeSyntax< RET >().Get() ) {} 

#define DEFINITION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( RET ) ExpressionOfComputableFunction< RET >:: DECLARATION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( RET ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , args... ); } 

#define DEFINITION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( RET ) ExpressionOfComputableFunction< RET >:: DECLARATION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( RET ) : SyntaxOfComputableFunction( ExpressionString() , FunctionString() ) { PushFunctionExpression( f , va... ); } 

#define DEFINITION_OF_EXPRESSION_FOR_RELATION_SYMBOL ExpressionOfComputableFunction<bool>:: DECLARATION_OF_EXPRESSION_FOR_RELATION_SYMBOL : SyntaxOfComputableFunction( ExpressionString() , RelationString() ) { PushRelationExpression( r , args... ); }  

#define DEFINITION_OF_EXPRESSION_FOR_VARIADIC_RELATION_SYMBOL ExpressionOfComputableFunction<bool>:: DECLARATION_OF_EXPRESSION_FOR_VARIADIC_RELATION_SYMBOL : SyntaxOfComputableFunction( ExpressionString() , RelationString() ) { PushRelationExpression( r , va... ); } 

#define DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( RET ) void ExpressionOfComputableFunction< RET >:: SIGNATURE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( RET ) { PushFunctionExpression( f , va.Get()... ); } 

#define DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY_BODY( FUNC ) \
  {									\
									\
    VLTree<string> t_va{};						\
    t_va.push_RightMost( va... );					\
									\
    TRY_CATCH								\
      (									\
									\
       Ref().push_RightMost( FunctionExpressionToString( FUNC , t_va ) , ( FUNC ).GetSubTree( 2 ) , ( FUNC ).Get() , va... ) , \
									\
       const ErrorType& e ,						\
									\
       CALL_P( e , FUNC , va... )					\
									\
									); \
									\
    return;								\
									\
  }									\


#define DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( RET ) auto ExpressionOfComputableFunction< RET >:: SIGNATURE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( RET ) -> TYPE_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY_BODY( f ) 

#define DEFINITION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION void ExpressionOfComputableFunction<bool>:: SIGNATURE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION{ PushRelationExpression( r , va.Get()... ); } 

#define DEFINITION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY auto ExpressionOfComputableFunction<bool>:: SIGNATURE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY -> TYPE_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY_BODY( r ) 


#define DEFINITION_OF_SET_SYMBOL_FOR_EXPRESSION( RET ) void ExpressionOfComputableFunction< RET >:: SIGNATURE_OF_SET_SYMBOL_FOR_EXPRESSION { SetSymbol( f ); }

