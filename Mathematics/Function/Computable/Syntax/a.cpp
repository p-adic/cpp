// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

#include "../Expression/a_Body.hpp"
#include "../../../../Error/FaultInCoding/a.hpp"


void SyntaxOfComputableFunction::InputDefinition( ofstream& ofs ) const
{

  auto itr_function_symbol = m_syntax.LeftMostNode();
  itr_function_symbol++;
  auto itr_line = itr_function_symbol;
  itr_line++;

  const string* p_function_name;
  const string* p_return_type_name;
  const string* p_argument_name;
  const string* p_argument_type_name;
  const string* p_line_name = nullptr;
  const string* p_function_expression_name = nullptr;
  
  TRY_CATCH
    (

     {
     
       p_function_name = &( SyntaxToString( itr_function_symbol , 2 ) );

       if( ! itr_function_symbol.IsValid() ){

	 ERR_CODE;

       }

       p_return_type_name = &( *itr_function_symbol );

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );
  
  itr_function_symbol++;
  auto itr_function_expression = itr_function_symbol;
       
  TRY_CATCH
    (

     {

       p_argument_name = &( SyntaxToString( itr_function_symbol , 2 ) );

       if( ! itr_function_symbol.IsValid() ){

	 ERR_CODE;

       }

       p_argument_type_name = &( *itr_function_symbol );
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
  
  const string& function_name = *p_function_name;
  const string& return_type_name = *p_return_type_name;
  const string& argument_name = *p_argument_name;
  const string& argument_type_name = *p_argument_type_name;
  const string& line_name = *p_line_name;
  const string& function_expression_name = *p_function_expression_name;

  
  ofs << "計算可能関数" << endl;
  ofs << "\\begin{eqnarray*}" << endl;
  ofs << function_name << " \\colon " << argument_type_name << " & \\to & " << return_type_name << " \\\\" << endl;
  ofs << argument_name << " & \\mapsto & " << function_expression_name << endl;
  ofs << "\\end{eqnarray*}" << endl;
  ofs << "を以下のように再帰的に定める：" << endl;
  
  TRY_CATCH
    (

     InputLine( ofs , function_expression_name , line_name , itr_line , 0 ) ,
     
     const ErrorType& e ,

     CALL( e )

     );

  return;
  
}

void SyntaxOfComputableFunction::InputLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  if( line_name == ListString() ){

    TRY_CATCH
      (

       InputListLine( ofs , function_expression_name , itr_line , depth ) ,

       const ErrorType& e ,

       CALL_P( e , depth )

       );

    return;

  }

  InputIndent( ofs , depth );

  TRY_CATCH
    (

     InputNonListLine( ofs , function_expression_name , line_name , itr_line , depth ) ,
     
     const ErrorType& e ,

     CALL_P( e , line_name , depth )

     );
  
  return;
  
}

void SyntaxOfComputableFunction::InputListLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  TRY_CATCH
    (

     {
       
       while( itr_line.IsValid() ){

	 auto itr_line_copy = itr_line;
	 const string& line_name = SyntaxToString( itr_line_copy , 1 );
	 
	 InputLine( ofs , function_expression_name , line_name , itr_line_copy , depth );
	 itr_line++;
    
       }

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );

  return;

}

void SyntaxOfComputableFunction::InputNonListLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  TRY_CATCH
    (

     {
       
       if( line_name == "if" ){

	 InputIfLine( ofs , function_expression_name , itr_line , depth );
	 return;

       }
    
       if( line_name == "put" ){

	 InputPutLine( ofs , itr_line , depth );
	 return;

       }

       if( line_name == "print" ){

	 InputPrintLine( ofs , itr_line );
	 return;

       }

       if( line_name == "exit" ){

	 InputExitLine( ofs , function_expression_name );
	 return;

       }

       if( line_name == "return" ){

	 InputReturnLine( ofs , function_expression_name , itr_line , depth );
	 return;

       }

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );

  ERR_IMPUT( line_name );
  return;

}

void SyntaxOfComputableFunction::InputIfLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  auto itr_condition = itr_line;
  itr_line++;

  TRY_CATCH
    (

     {
	 
       const string& condition_name = SyntaxToString( itr_condition , 2 );
       const string& line_name = SyntaxToString( itr_line , 1 );

       if( line_name == "list" ){

	 ofs << "\\(" <<  condition_name << "\\)とする。" << endl;
	 InputListLine( ofs , function_expression_name , itr_line , depth+1 );
	 return;
      
       }
    
       ofs << "もし\\(" << condition_name << "\\)ならば、";
       InputNonListLine( ofs , function_expression_name , line_name , itr_line , depth );

     } ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  return;

}

void SyntaxOfComputableFunction::InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  auto itr_variable = itr_line;
  itr_line++;

  const string* p_variable_name;
  const string* p_expression_name;
  
  TRY_CATCH
    (

     p_variable_name = &( SyntaxToString( itr_variable , 2 ) ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  TRY_CATCH
    (

     p_expression_name = &( ExpressionToString( itr_line ) ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  ofs << "\\(" << *p_variable_name << " := " << *p_expression_name << "\\)と置く。" << endl;
  return;

}

void SyntaxOfComputableFunction::InputPrintLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line ) const
{

  const string* p_variable_name;
  
  TRY_CATCH
    (

     p_variable_name = &( SyntaxToString( itr_line , 2 ) ) ,
     
     const ErrorType& e ,

     CALL( e )

     );
  
  ofs << "デバッグ時に\\(" << *p_variable_name << "\\)の標準出力を行う。この操作は計算結果に影響を与えない。" << endl;
  return;

}

void SyntaxOfComputableFunction::InputReturnLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  const string* p_return_name;
  
  TRY_CATCH
    (

     p_return_name = &( SyntaxToString( itr_line , 2 ) ) ,
     
     const ErrorType& e ,

     CALL( e )

     );

  ofs << "\\(" << function_expression_name << " := " << *p_return_name << "\\)と定める。" << endl;
  return;

}

void SyntaxOfComputableFunction::InputIndent( ofstream& ofs , const uint depth ) const noexcept
{

  string s = "#";

  for( uint i = 0 ; i < depth ; i++ ){

    s += "#";

  }

  s += " ";

  ofs << s;
  return;

}

const string& SyntaxToString( VLTree<string>::const_iterator& itr , const int& n )
{

  const string* p;
  
  try{
    
    itr[n];
    p = &( *itr );

  }
  catch( const ErrorType& e ){

    CALL_P( e , n );

  }
  
  itr++;
  
  return *p;

}

string ListSyntaxToString( VLTree<VLTree<string>::const_iterator>& t , const int& n )
{

  VLTree<VLTree<string>::const_iterator>::iterator itr = t.LeftMostNode();
  const uint& size = t.size();
  uint i = 0;
  
  string s = "(";

  try{
       
    while( i < size ){

      if( i > 0 ){

	s += ",";

      }

      s += SyntaxToString( *itr , n );
      itr++;
      i++;

    }

  }
  catch( const ErrorType& e ){
     
    CALL_P( e , n , s );

  }

  s += ")";
  return s;

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


string FunctionExpressionToString( VLTree<string>::const_iterator& itr_f , VLTree<string>::const_iterator& itr_args )
{

  string s = "";

  itr_f++;
  itr_f++;
  itr_f++;
  itr_f++;
  itr_f[1];

  bool variadic = false;

  while( itr_args.IsValid() ){

    if( variadic ){

      itr_f--;

    }
    
    if( ! itr_f.IsValid() ){

      ERR_IMPUT( s , *itr_args );
       
    }

    const string& s_current = *itr_f;

    if( ! variadic && s_current == LdotsString() ){

      itr_f++;

      if( ! itr_f.IsValid() ){

	ERR_IMPUT( s , *itr_args );

      }

      variadic = true;
      s += *itr_f;

    } else {

      s += s_current;

    }
    
    s += *itr_args;
    
    itr_f++;
    itr_args++;

  }

  const string& s_current = *itr_f;
  
  if( ! variadic && s_current == LdotsString() ){

    itr_f++;
    itr_f++;
      
    if( ! itr_f.IsValid() ){

      ERR_IMPUT( s );

    }
      
    variadic = true;
    s += *itr_f;

  } else {

    s += s_current;

  }

  itr_f++;

  if( itr_f.IsValid() ){

    ERR_IMPUT( *itr_f , variadic );
       
  }
  
  return s;
  
}

const string& ExpressionToString( VLTree<string>::const_iterator& itr )
{

  itr[2];
  
  if( ! itr.IsValid() ){

    ERR_IMPUT( itr );
       
  }

  const string& s = *itr;

  itr++;
  return s;
  
}
