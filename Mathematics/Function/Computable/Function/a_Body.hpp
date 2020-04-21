// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../Expression/Condition/a_Body.hpp"
#include "../Expression/Variable/Variadic/a_Body.hpp"
#include "../Separator/a_Body.hpp"
#include "../Type/Base/a_Body.hpp"
#include "../Type/Basic/a_Body.hpp"

template <typename Ret, typename... Args> inline FunctionSymbol<Ret,Args...>::FunctionSymbol( const string& f , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) : FunctionSymbol( f , SeparatorOfComputableFunction( f , sizeof...( Args ) ) , type_name , args... ) {}

template <typename Ret, typename... Args>
FunctionSymbol<Ret,Args...>::FunctionSymbol( const string& f , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) :
  SyntaxOfComputableFunction
  (

   NestString() ,
   FunctionString() ,
   f ,
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
     CALL_P( e , f , s , args... , t_args )

     );

}

template <typename Ret, typename... Args>
void FunctionSymbol<Ret,Args...>::SetSeparator( const SeparatorOfComputableFunction& s )
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

	 t_sub.push_RightMost( VLTree<string>( 0 , itr_args ) );
	 itr_args++;

       }

       t.push_RightMost( s.Get() );
       t.push_RightMost( FunctionExpressionToString( *this , t_sub ) );

     } ,

     const ErrorType& e ,

     CALL_P( e , s )

     );
    
  return;

}

template <typename Ret, typename... Args> template <typename... VA> inline auto FunctionSymbol<Ret,Args...>::SetSeparator( const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type { TRY_CATCH( SetSeparator( SeparatorOfComputableFunction( 0 , va... ) ) , const ErrorType& e , CALL_P( e , va... ) ); }

template <typename Ret, typename... Args> inline ExpressionOfComputableFunction<Ret> FunctionSymbol<Ret,Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args ) const { return ExpressionOfComputableFunction<Ret>( *this , args... ); }


template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL( Ret , Minus );
template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL( Ret , Slash );
template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL( Ret , Mod );
template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL( Ret , Power );

template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Minus , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Slash , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Mod , Symbol<Ret> );
template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Power , Symbol<Ret> );

inline const FunctionSymbol<bool,bool>& NegSymbol() { static const FunctionSymbol<bool,bool> f( NegString() , GetTypeName<bool>() , VariableSymbol<bool>( "x" ) ); return f; }

DEFINITION_OF_LOGICAL_CONNECTIVE( To );
DEFINITION_OF_LOGICAL_CONNECTIVE( Equiv );

DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Ot ){ return ToSymbolApplication( e2 , e1 ); }
DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );
