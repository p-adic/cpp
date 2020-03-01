// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../Expression/Condition/a_Body.hpp"
#include "../Expression/Variable/Variadic/a_Body.hpp"
#include "../Separator/a_Body.hpp"
#include "../Type/Basic/a_Body.hpp"

template <typename Ret, typename... Args> inline FunctionSymbol<Ret,Args...>::FunctionSymbol( const string& f , const VariableSymbol<Args>&... args ) : FunctionSymbol( f , SeparatorOfComputableFunction( f , sizeof...( Args ) ) , args... ) {}

template <typename Ret, typename... Args>
FunctionSymbol<Ret,Args...>::FunctionSymbol( const string& f , const SeparatorOfComputableFunction& s , const VariableSymbol<Args>&... args ) :
  SyntaxOfComputableFunction
  (

   NestString() ,
   FunctionString() ,
   f ,
   GetName<Ret>() ,
   ListExpressionOfComputableFunction( args... ).Get() ,
   s.Get()
   
   )
{

  VLTree<string>& t = Ref();

  TRY_CATCH
    (
     
     t.push_RightMost( FunctionExpressionToString( *this , args.GetNodeString( 2 )... ) ) ,

     const ErrorType& e ,

     CALL_P( e , t )

     );

}

template <typename Ret, typename... Args> template <typename... VA>
auto FunctionSymbol<Ret,Args...>::SetSeparator( const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type
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

       auto itr = t.RightMostNode();
       itr[1];

       t.push_RightMost( s );
       t.push_RightMost( FunctionExpressionToString( *this , itr ) );

     } ,

     const ErrorType& e ,

     CALL( e )

     );
    
  return;

}

template <typename Ret, typename... Args> inline ExpressionOfComputableFunction<Ret> FunctionSymbol<Ret,Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args ) const { return ExpressionOfComputableFunction<Ret>( *this , args... ); }


DEFINITION_OF_FUNCTION_SYMBOL( Minus , MinusString() );
DEFINITION_OF_FUNCTION_SYMBOL( Slash , SlashString() );
DEFINITION_OF_FUNCTION_SYMBOL( Mod , ModString() );

DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Minus );
DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Slash );
DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Mod );

inline const FunctionSymbol<bool,bool>& NegSymbol() { static const FunctionSymbol<bool,bool> f( NegString() , VariableSymbol<bool>( "x" ) ); return f; }
DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Nest , nest );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Function , function );

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Minus , - );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Slash , \\slash );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Mod , % );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Neg , \\neg );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( To , \\rightarrow );
DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Equiv , \\equiv );
