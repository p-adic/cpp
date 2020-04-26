// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Relation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Expression/Condition/a.hpp"
#include "../Expression/Variable/Variadic/a.hpp"

#include "../Separator/a_Body.hpp"
#include "../Type/Base/a_Body.hpp"
#include "../Type/SubType/a_Body.hpp"

#include "../Expression/Condition/a_Body.hpp"
#include "../Expression/Variable/Variadic/a_Body.hpp"

#include "../Syntax/a_Body.hpp"

template <typename... Args> inline RelationSymbol<Args...>::RelationSymbol( const string& r , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) : RelationSymbol( r , SeparatorOfComputableFunction( r , sizeof...( Args ) ) , type_name , args... ) {}

template <typename... Args>
RelationSymbol<Args...>::RelationSymbol( const string& r , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) :
  SyntaxOfComputableFunction
  (

   NestString() ,
   RelationString() ,
   r ,
   type_name.Get() ,
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


template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Eq );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Neq );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Leq );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Geq );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Lneq );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Gneq );

template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Eq , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Neq , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Leq , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Geq , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Lneq , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Gneq , Symbol<Ret> );

