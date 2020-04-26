// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/List/Body/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a.hpp"
#include "../../Variable/a.hpp"
#include "../../a.hpp"

#include "../a_Body.hpp"
#include "../../Variable/a_Body.hpp"
#include "../../a_Body.hpp"
#include "../../../Type/Valid/a_Body.hpp"

template <typename VArg> inline ExpressionOfComputableFunction<void>::ExpressionOfComputableFunction( const WrappedTypes<VArg>& ) : SyntaxOfComputableFunction( ExpressionString() , VariableString() , LdotsString() , GetSyntax<VArg>().Get() ) {}

template <typename... VA>
ExpressionOfComputableFunction<void>::ExpressionOfComputableFunction( const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( ExpressionString() , ListString() , va.Get()... )
{

  VLTree<string>& t = Ref();

  VLTree<string>::iterator itr_insert = t.LeftMostNode();
  VLTree<string>::const_iterator itr = itr_insert;
  itr++;
  
  const uint& size = t.size();
  uint i = 1;
  
  string argument_name = "";
  string argument_type_name = "";

  if( size > 2 ){

    argument_name = "( ";

  }
  
  TRY_CATCH
    (

     {
       
       while( i < size ){

	 if( i > 1 ){

	   argument_name += " , ";
	   argument_type_name += " \\times ";

	 }

	 auto itr_copy = itr;
	 argument_name += SyntaxToString( itr_copy , 2 );
	 argument_type_name += SyntaxToString( itr_copy , 2 );
	 itr++;
	 i++;

       }

     } ,

     const ErrorType& e ,

     CALL_P( e , i , argument_name , argument_type_name )

     );

  if( size > 2 ){
    
    argument_name += " )";

  }

  t.insert( itr_insert , argument_type_name );
  t.insert( itr_insert , argument_name );

}
