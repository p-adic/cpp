// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Function/a_Body.hpp"
#include "../Syntax/a_Body.hpp"

template <typename... Args> inline RelationSymbol<Args...>::RelationSymbol( const string& r , const VariableSymbol<Args>&... args ) : RelationSymbol( r , SeparatorOfComputableFunction( r , sizeof...( Args ) ) , args... ) {}

template <typename... Args>
RelationSymbol<Args...>::RelationSymbol( const string& r , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args ) :
  SyntaxOfComputableFunction
  (

   NestString() ,
   RelationString() ,
   r ,
   GetName<bool>() ,
   ListExpressionOfComputableFunction( args... ).Get() ,
   s.Get()
   
   )
{

  VLTree<string>& t = Ref();

  TRY_CATCH
    (
     
     t.push_RightMost( FunctionExpressionToString( *this , VLTree<string>( args.GetNodeString( 2 )... ) ) ) ,

     const ErrorType& e ,

     CALL_P( e , t )

     );

}

template <typename... Args> template <typename... VA>
auto RelationSymbol<Args...>::SetSeparator( const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type
{

  SyntaxOfComputableFunction s{ SeparatorString() , va... };

  TRY_CATCH
    (

     {

       if( sizeof...( Args ) + 1 != sizeof...( VA ) ){

	 ERR_CODE;

       }
       
       VLTree<string>& t = Ref();
  
       t.pop_RightMost();
       t.pop_RightMost();

       VLTree<string>::const_iterator itr_f = Get().LeftMostNode();
       VLTree<string>::const_iterator itr_args = t.RightMostNode();
       itr_args[1];

       t.push_RightMost( s );
       t.push_RightMost( FunctionExpressionToString( itr_f , itr_args ) );

     } ,

     const ErrorType& e ,

     CALL( e )

     );
    
  return;

}

template <typename... Args> inline ConditionOfComputableFunction RelationSymbol<Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args ) const { return ConditionOfComputableFunction( *this , args... ); }


DEFINITION_OF_RELATION_SYMBOL( Eq , eq );
DEFINITION_OF_RELATION_SYMBOL( Neq , neq );
DEFINITION_OF_RELATION_SYMBOL( Leq , leq );
DEFINITION_OF_RELATION_SYMBOL( Geq , geq );
DEFINITION_OF_RELATION_SYMBOL( Lneq , lneq );
DEFINITION_OF_RELATION_SYMBOL( Gneq , gneq );

DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Eq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Neq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Leq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Geq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Lneq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Gneq );


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Relation , relation );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Eq , = );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neq , \\neq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Leq , \\leq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Geq , \\geq );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Lneq , < );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Gneq , > );
