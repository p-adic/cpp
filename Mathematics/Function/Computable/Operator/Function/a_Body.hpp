// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Expression/Primitive/bool/a.hpp"
#include "../../Expression/Variable/Variadic/a.hpp"

#include "../Separator/a_Body.hpp"
#include "../Totality/a_Body.hpp"
#include "../../Type/Guide/Base/a_Body.hpp"
#include "../../Type/SubType/a_Body.hpp"
#include "../../Expression/Primitive/bool/a_Body.hpp"
#include "../../Expression/Variable/Variadic/a_Body.hpp"

template <typename Ret, typename... Args> inline FunctionSymbol<Ret,Args...>::FunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const TypeNameOfComputableFunction& return_type_name , const VariableSymbol<Args>&... args ) : FunctionSymbol( totality , f , SeparatorOfComputableFunction( f , sizeof...( Args ) ) , return_type_name , args... ) {}

template <typename Ret, typename... Args>
FunctionSymbol<Ret,Args...>::FunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& return_type_name , const VariableSymbol<Args>&... args ) :
  SyntaxOfComputableFunction
  (

   NestString() ,
   FunctionString() ,
   f ,
   return_type_name.Get() ,
   ListExpressionOfComputableFunction( args... ).Get() ,
   s.Get()
   
   ) ,
  m_totality( totality )
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

template <typename Ret, typename... Args> template <typename... Ts> inline FunctionSymbol<Ret,Args...>::FunctionSymbol( const string& f , const Ts&... ts ) : FunctionSymbol( Recursiveness() , f , ts... ) {}

template <typename Ret, typename... Args> inline FunctionSymbol<Ret,Args...>::FunctionSymbol( const FunctionSymbol<Ret,Args...>& f ) : SyntaxOfComputableFunction( f ) , m_totality( f.m_totality ) {}

template <typename Ret, typename... Args> inline void FunctionSymbol<Ret,Args...>::Set( const string& dummy , const string& f ) { SetSymbol( f ); }
template <typename Ret, typename... Args> template <typename... VA> inline auto FunctionSymbol<Ret,Args...>::Set( const SeparatorOfComputableFunction& dummy1 , const int& dummy2 , const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type { SetSeparator( SeparatorOfComputableFunction( dummy2 , va... ) ); }
template <typename Ret, typename... Args> inline void FunctionSymbol<Ret,Args...>::Set( const TotalityOfComputableFunction& dummy , const TotalityOfComputableFunction& totality ) noexcept { SetTotality( totality ); }
  

template <typename Ret, typename... Args> inline void FunctionSymbol<Ret,Args...>::RomaniseSymbol() { SyntaxOfComputableFunction::RomaniseSymbol(); SetSeparator( SeparatorOfComputableFunction( GetNodeString( 2 ) , sizeof...( Args ) ) ); }

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

template <typename Ret, typename... Args> inline const TotalityOfComputableFunction& FunctionSymbol<Ret,Args...>::GetTotality() const noexcept { return m_totality; }

template <typename Ret, typename... Args> inline void FunctionSymbol<Ret,Args...>::SetTotality( const TotalityOfComputableFunction& totality ) noexcept { m_totality = totality; }


template <typename Ret, typename... Args> inline ExpressionOfComputableFunction<Ret> FunctionSymbol<Ret,Args...>::operator()( const ExpressionOfComputableFunction<Args>&... args ) const { return ExpressionOfComputableFunction<Ret>( *this , args... ); }


template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL( Ret , Minus );
template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL( Ret , Slash );
template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL( Ret , Mod );
template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL( Ret , Power );

template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Minus , Symbol<Ret> );
template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Slash , Symbol<Ret> );
template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Mod , Symbol<Ret> );
template <typename Ret> inline DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Power , Symbol<Ret> );
