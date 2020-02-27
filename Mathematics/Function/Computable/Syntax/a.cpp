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
  const string* p_line_name;

  TRY_CATCH
    (

     {
     
       p_function_name = &( SyntaxToSecondString( itr_function_symbol ) );

       if( ! itr_function_symbol.IsValid() ){

	 ERR_CODE;

       }

       p_return_type_name = &( *itr_function_symbol );

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );
  
  itr_function_symbol++;

  TRY_CATCH
    (

     {
       
       p_argument_name = &( SyntaxToSecondString( itr_function_symbol ) );

       if( ! itr_function_symbol.IsValid() ){

	 ERR_CODE;

       }

       p_argument_type_name = &( *itr_function_symbol );
       p_line_name = &( SyntaxToFirstString( itr_line ) );
       
     } ,
     
     const ErrorType& e ,

     CALL( e )

   )

  
  const string& function_name = *p_function_name;
  const string& return_type_name = *p_return_type_name;
  const string& argument_name = *p_argument_name;
  const string& argument_type_name = *p_argument_type_name;
  const string& line_name = *p_line_name;
  string function_expression_name = function_name + argument_name;

  
  ofs << "計算可能関数" << endl;
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
	 const string& line_name = SyntaxToFirstString( itr_line_copy );
	 
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

  if( line_name == "finish" ){

    InputFinishLine( ofs );
    return;
    
  }
  
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

  const string& condition_name = SyntaxToSecondString( itr_condition );
  const string& line_name = SyntaxToFirstString( itr_line );

  if( line_name == "list" ){

    TRY_CATCH
      (

       {
	 
	 ofs << "\\(" <<  condition_name << "\\)とする。" << endl;
	 InputListLine( ofs , function_expression_name , itr_line , depth+1 );
	 return;

       } ,

       const ErrorType& e ,

       CALL_P( e , depth )

       );
      
  }
    
  TRY_CATCH
    (

     {
       
       ofs << "もし\\(" << condition_name << "\\)ならば、";
       InputNonListLine( ofs , function_expression_name , line_name , itr_line , depth );

     } ,
     
     const ErrorType& e ,

     CALL_P( e , line_name , depth )

     );

  return;

}

void SyntaxOfComputableFunction::InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  auto itr_variable = itr_line;
  itr_line++;

  const string& variable_name = SyntaxToSecondString( itr_variable );
  const string& expression_name = SyntaxToSecondString( itr_line );

  ofs << "\\(" << variable_name << " := " << expression_name << "\\)と置く。" << endl;
  return;

}

void SyntaxOfComputableFunction::InputReturnLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth ) const
{

  const string& return_name = SyntaxToSecondString( itr_line );
  
  ofs << "\\(" << function_expression_name << " := " << return_name << "\\)と定める。" << endl;
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

const string& SyntaxToFirstString( VLTree<string>::const_iterator& itr )
{

  const string* p;
  
  try{
    
    itr[1];
    p = &( *itr );

  }
  catch( const ErrorType& e ){

    CALL( e );

  }
  
  itr++;
  
  return *p;

}

const string& SyntaxToSecondString( VLTree<string>::const_iterator& itr )
{

  const string* p;

  try{
    
    itr[2];
    p = &( *itr );

  }
  catch( const ErrorType& e ){

    CALL( e );

  }
  
  itr++;
  
  return *p;

}

string ListSyntaxToSecondString( VLTree<VLTree<string>::const_iterator>& t )
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

      s += SyntaxToSecondString( *itr );
      itr++;
      i++;

    }

  }
  catch( const ErrorType& e ){
     
    CALL_P( e , i , s );

  }

  s += ")";
  return s;

}
