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

  VLTree<string> t_args{};
  t_args.push_RightMost( args.Get()... );
  
  TRY_CATCH
    (
     
     Ref().push_RightMost( FunctionExpressionToString( *this , t_args ) ) ,

     const ErrorType& e ,

     CALL_P( e , r , s , args... , t_args )

     );

}

template <typename... Args>
void RelationSymbol<Args...>::SetSeparator( const SeparatorOfComputableFunction& s )
{

  if( sizeof...( Args ) + 1 != s.Get().size() ){

    ERR_IMPUT( s , sizeof...( Args ) + 1 , s.Get().size() );

  }

  TRY_CATCH
    (

     {
       
       VLTree<string>& t = Ref();
  
       t.pop_RightMost();
       t.pop_RightMost();

       VLTree<string>::const_iterator itr_args = t.RightMostNode();
       itr_args[4];

       VLTree<string> t_sub{};

       while( itr_args.IsValid() ){

	 t_sub.push_RightMost( VLTree<string>( itr_args , 0 ) );
	 itr_args++;

       }

       t.push_RightMost( s.Get() );
       t.push_RightMost( FunctionExpressionToString( *this , t_sub ) );

     } ,

     const ErrorType& e ,

     CALL( e )

     );
    
  return;

}

template <typename... Args> inline ConditionOfComputableFunction RelationSymbol<Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args ) const { return ConditionOfComputableFunction( *this , args... ); }


DEFINITION_OF_RELATION_SYMBOL( Eq );
DEFINITION_OF_RELATION_SYMBOL( Neq );
DEFINITION_OF_RELATION_SYMBOL( Leq );
DEFINITION_OF_RELATION_SYMBOL( Geq );
DEFINITION_OF_RELATION_SYMBOL( Lneq );
DEFINITION_OF_RELATION_SYMBOL( Gneq );

DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Eq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Neq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Leq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Geq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Lneq );
DEFINITION_OF_RELATION_SYMBOL_APPLICATION( Gneq );
