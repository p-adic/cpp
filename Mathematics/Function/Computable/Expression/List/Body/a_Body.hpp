// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/List/Body/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a.hpp"

#include "../a_Body.hpp"
#include "../../Variable/a_Body.hpp"
#include "../../../Type/Valid/a_Body.hpp"

inline ExpressionOfComputableFunction<void>::ExpressionOfComputableFunction() : SyntaxOfComputableFunction( ExpressionString() , VariableString() , LdotsString() , GetName<void>() ) {}

template <typename... VA>
ExpressionOfComputableFunction<void>::ExpressionOfComputableFunction( const ExpressionOfComputableFunction<VA>&... va ) : SyntaxOfComputableFunction( ExpressionString() , ListString() , va.Get()... )
{

  VLTree<string>& t = Ref();

  VLTree<string>::iterator itr_insert = t.LeftMostNode();
  VLTree<string>::const_iterator itr = itr_insert;
  itr++;
  
  const uint& size = t.size();
  uint i = 1;
  
  string argument_name = "( ";
  string argument_type_name = "";

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
	 argument_type_name += *itr_copy;
	 itr++;
	 i++;

       }

     } ,

     const ErrorType& e ,

     CALL_P( e , i , argument_name , argument_type_name )

     );

  argument_name += " )";

  t.insert( itr_insert , argument_type_name );
  t.insert( itr_insert , argument_name );

}


DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Ldots , \\ldots );
