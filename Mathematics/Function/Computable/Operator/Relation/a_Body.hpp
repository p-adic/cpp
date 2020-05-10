// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Relation/a_Body.hpp

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

#include "../../Syntax/a_Body.hpp"

template <typename... Args> inline RelationSymbol<Args...>::RelationSymbol( const TotalityOfComputableFunction& totality , const string& r , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) : RelationSymbol( totality , r , SeparatorOfComputableFunction( r , sizeof...( Args ) ) , type_name , args... ) {}

template <typename... Args>
RelationSymbol<Args...>::RelationSymbol( const TotalityOfComputableFunction& totality , const string& r , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) :
  SyntaxOfComputableFunction
  (

   NestString() ,
   RelationString() ,
   r ,
   type_name.Get() ,
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

     CALL_P( e , r , s , args... , t_args )

     );

}

template <typename... Args> template <typename... Ts> inline RelationSymbol<Args...>::RelationSymbol( const string& r , const Ts&... ts ) : RelationSymbol( Recursiveness() , r , ts... ) {}

template <typename... Args> inline RelationSymbol<Args...>::RelationSymbol( const RelationSymbol<Args...>& r ) : SyntaxOfComputableFunction( r ) , m_totality( r.m_totality ) {}


template <typename... Args> inline void RelationSymbol<Args...>::Set( const string& dummy , const string& f ) { SetSymbol( f ); }
template <typename... Args> template <typename... VA> inline auto RelationSymbol<Args...>::Set( const SeparatorOfComputableFunction& dummy1 , const int& dummy2 , const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type { SetSeparator( SeparatorOfComputableFunction( dummy2 , va... ) ); }
template <typename... Args> inline void RelationSymbol<Args...>::Set( const TotalityOfComputableFunction& dummy , const TotalityOfComputableFunction& totality ) noexcept { SetTotality( totality ); }


template <typename... Args> inline void RelationSymbol<Args...>::RomaniseSymbol() { SyntaxOfComputableFunction::RomaniseSymbol(); SetSeparator( SeparatorOfComputableFunction( GetNodeString( 2 ) , sizeof...( Args ) ) ); }

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

	 t_sub.push_RightMost( VLTree<string>( 0 , itr_args ) );
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

template <typename... Args> inline const TotalityOfComputableFunction& RelationSymbol<Args...>::GetTotality() const noexcept { return m_totality; }

template <typename... Args> inline void RelationSymbol<Args...>::SetTotality( const TotalityOfComputableFunction& totality ) noexcept { m_totality = totality; }


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

