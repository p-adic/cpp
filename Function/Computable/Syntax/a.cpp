// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

#include "../Type/Basic/a_Body.hpp"
#include "../Expression/a_Body.hpp"
#include "../../../../Error/FaultInCoding/a.hpp"


void SyntaxOfComputableFunction::SetSymbol( const string& symbol )
{

  auto itr = m_syntax.LeftMostNode();
  itr++;
  *itr = symbol;
  return;

}

void SyntaxOfComputableFunction::RomaniseSymbol()
{

  auto itr = m_syntax.LeftMostNode();
  itr++;
  *itr = Plainise( *itr );
  return;

}

void SyntaxOfComputableFunction::InputDefinition( ofstream& ofs , const string& totality , const string& function_name , ConstIteratorOfVLTree<string>& itr_f , const string& language , const string& style ) const
{

  auto itr_line = m_syntax.LeftMostNode();
  itr_line++;

  const string* p_return_type_name;
  const string* p_argument_name;
  const string* p_argument_type_name;
  const string* p_line_name = nullptr;
  const string* p_function_expression_name = nullptr;
  
  TRY_CATCH
    (

     {
     
       if( ! itr_f.IsValid() ){

	 ERR_CODE;

       }

       auto itr_return_type_name = itr_f;
       itr_return_type_name[2];
       p_return_type_name = &( *itr_return_type_name );

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );
  
  itr_f++;
  auto itr_function_expression = itr_f;
       
  TRY_CATCH
    (

     {

       p_argument_name = &( SyntaxToString( itr_f , 2 ) );

       if( ! itr_f.IsValid() ){

	 ERR_CODE;

       }

       p_argument_type_name = &( *itr_f );
       p_line_name = &( SyntaxToString( itr_line , 1 ) );
       
     } ,
     
     const ErrorType& e ,

     CALL( e )

     );
  
  itr_function_expression++;
  itr_function_expression++;
    
  TRY_CATCH
    (

     {
       
       if( ! itr_function_expression.IsValid() ){

	 ERR_CODE;

       }

       p_function_expression_name = &( *itr_function_expression );

     } ,
     
     const ErrorType& e ,
     
     CALL( e )

     );

  TRY_CATCH
    (

     {
       
       InputTotality( ofs , totality , language , style );
       InputSignatureOfFunction( ofs , function_name , *p_argument_type_name , *p_argument_name , *p_return_type_name , *p_function_expression_name , language , style );

       const string line_name =  *p_line_name;

       if( line_name == ReturnString() ){

	 string form = *p_function_expression_name + " := " + SyntaxToString( itr_line , 2 );
	 PutMathJax( form , style );
	 InputInlineWay( ofs , form , language , style );

       } else {

	 string language_copy = language;

	 InputRecursiveWay( ofs , language , style );
	 InputLine( ofs , *p_function_expression_name , line_name , itr_line , 0 , language_copy , style );

       }
       
     },
     
     const ErrorType& e ,

     CALL( e )

     );

  return;
  
}

string FunctionExpressionToString( const SyntaxOfComputableFunction& f , const VLTree<string>& args )
{

  VLTree<string>::const_iterator itr_f = f.Get().LeftMostNode();
  VLTree<string>::const_iterator itr_args = args.LeftMostNode();

  TRY_CATCH
    (

     return FunctionExpressionToString( itr_f , itr_args ) ,
     const ErrorType& e ,
     CALL_P( e , f , args )

     );
  
  return "dummy";

}

static bool IsPolishSeparator( const VLTree<string>::const_iterator& itr_sep );
static const string& CurrentSeparator( bool& variadic , VLTree<string>::const_iterator& itr_f );
static string CurrentArgument( const bool& polish_f , VLTree<string>::const_iterator& itr_f , VLTree<string>::const_iterator& itr_args );
static bool IsAmbiguous( const bool& polish_f , const VLTree<string>::const_iterator& itr_f );
static bool IsPolishFunctionExpression( const VLTree<string>::const_iterator& itr_f );
static const string& LastSeparator( bool& variadic , VLTree<string>::const_iterator& itr_f );

string FunctionExpressionToString( VLTree<string>::const_iterator& itr_f , VLTree<string>::const_iterator& itr_args )
{

  string s = "";

  itr_f++;
  itr_f++;
  itr_f++;
  itr_f++;
  itr_f[1];

  bool variadic = false;
  bool polish_f;
  
  TRY_CATCH( polish_f = IsPolishSeparator( itr_f ) , const ErrorType& e , CALL( e ) );
    
  while( itr_args.IsValid() ){

    TRY_CATCH( s += CurrentSeparator( variadic , itr_f ) + CurrentArgument( polish_f , itr_f , itr_args ) , const ErrorType& e , CALL_P( e , s ) );
    itr_f++;

  }

  TRY_CATCH( s += LastSeparator( variadic , itr_f ) , const ErrorType& e , CALL( e ) );
  itr_f++;

  if( itr_f.IsValid() ){

    ERR_INPUT( *itr_f , variadic );
       
  }
  
  return s;
  
}

static bool IsPolishSeparator( const VLTree<string>::const_iterator& itr_sep )
{

  const string* p_sep;
  TRY_CATCH( p_sep = &( *itr_sep ) , const ErrorType& e , CALL( e ) );
  return *p_sep != EmptyString() && *p_sep != SpaceString();

}

static const string& CurrentSeparator( bool& variadic , VLTree<string>::const_iterator& itr_f )
{

  if( variadic ){

    itr_f--;

  } 

  if( ! itr_f.IsValid() ){

    ERR_INPUT( variadic );
       
  }

  const string& sep_current = *itr_f;

  if( ! variadic && sep_current == LdotsString() ){

    itr_f++;

    if( ! itr_f.IsValid() ){

      ERR_CODE;

    }

    variadic = true;
    return *itr_f;

  }

  return sep_current;

}

static string CurrentArgument( const bool& polish_f , VLTree<string>::const_iterator& itr_f , VLTree<string>::const_iterator& itr_args )
{
    
  string arg_current = ExpressionToString( itr_args );

  if( IsAmbiguous( polish_f , itr_f ) ){

    arg_current = "( " + arg_current + " )";

  }
    
  return arg_current;

}

bool IsAmbiguous( const bool& polish_f ,  const VLTree<string>::const_iterator& itr_f )
{
      
  if( polish_f ){

    return false;

  }

  TRY_CATCH
    (

     if( IsPolishFunctionExpression( itr_f ) ){ return false; } ,
     const ErrorType& e ,
     CALL( e )

     );



  return true;

}

static bool IsPolishFunctionExpression( const VLTree<string>::const_iterator& itr_f )
{

  string s;

  auto itr_sep = itr_f;
  itr_sep[1];

  TRY_CATCH
    (

     s = *itr_sep ,
     const ErrorType& e ,
     CALL( e )

     );

  if( s == FunctionString() || s == RelationString() ){

    itr_sep++;
    itr_sep++;
    itr_sep++;
    itr_sep[5];
    itr_sep[1];

    TRY_CATCH
      (

       s = *itr_sep ,
       const ErrorType& e ,
       CALL( e )

       );

    return s != EmptyString() && s != SpaceString();

  }

  return true;

}

static const string& LastSeparator( bool& variadic , VLTree<string>::const_iterator& itr_f )
{
    
  const string& sep_current = *itr_f;
  
  if( ! variadic && sep_current == LdotsString() ){

    itr_f++;
    itr_f++;
      
    if( ! itr_f.IsValid() ){

      ERR_CODE;

    }
      
    variadic = true;
    return *itr_f;

  }

  return sep_current;

}

const string& ExpressionToString( VLTree<string>::const_iterator& itr )
{

  auto itr_copy = itr;
  itr_copy[2];
  
  const string* p_e;

  TRY_CATCH
    (

     p_e = &( *itr_copy ) ,
     const ErrorType& e ,
     CALL( e )

     );

  itr++;
  return *p_e;
  
}


