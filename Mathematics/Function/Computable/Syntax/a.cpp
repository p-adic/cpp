// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

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


void SyntaxOfComputableFunction::InputDefinition( ofstream& ofs , const SyntaxOfComputableFunction& f , const string& language , const string& style ) const
{

  auto itr_function_symbol = f.m_syntax.LeftMostNode();
  auto itr_line = m_syntax.LeftMostNode();
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
  
  TRY_CATCH
    (

     {
       
       InputDeclaration( ofs , *p_function_name , *p_argument_type_name , *p_argument_name , *p_return_type_name , *p_function_expression_name , language , style );
       InputLine( ofs , *p_function_expression_name , *p_line_name , itr_line , 0 , language , style );

     },
     
     const ErrorType& e ,

     CALL( e )

     );

  return;
  
}

void SyntaxOfComputableFunction::InputDeclaration( ofstream& ofs , const string& function_name , const string& argument_type_name , const string& argument_name , const string& return_type_name , const string& function_expression_name , const string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "計算可能部分関数" << endl;
    ofs << "\\begin{eqnarray*}" << endl;
    ofs << function_name << " \\colon " << argument_type_name << " & \\to & " << return_type_name << " \\\\" << endl;
    ofs << argument_name << " & \\mapsto & " << function_expression_name << endl;
    ofs << "\\end{eqnarray*}" << endl;
    ofs << "を以下のように再帰的に定める：" << endl;
    return;

  }
  
  if( language == EnglishString() && style == FandomString() ){

    ofs << "I define a partial computable function" << endl;
    ofs << "\\begin{eqnarray*}" << endl;
    ofs << function_name << " \\colon " << argument_type_name << " & \\to & " << return_type_name << " \\\\" << endl;
    ofs << argument_name << " & \\mapsto & " << function_expression_name << endl;
    ofs << "\\end{eqnarray*}" << endl;
    ofs << "in the following recursive way:" << endl;
    return;

  }

  ERR_IMPUT( language , style );
  return;

}

void SyntaxOfComputableFunction::InputLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  if( line_name == ListString() ){

    TRY_CATCH
      (

       InputListLine( ofs , function_expression_name , itr_line , depth , language , style ) ,

       const ErrorType& e ,

       CALL_P( e , depth )

       );

    return;

  }

  InputIndent( ofs , depth , language , style );

  TRY_CATCH
    (

     InputNonListLine( ofs , function_expression_name , line_name , itr_line , depth , language , style ) ,
     
     const ErrorType& e ,

     CALL_P( e , line_name , depth )

     );
  
  return;
  
}

void SyntaxOfComputableFunction::InputListLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  TRY_CATCH
    (

     {
       
       while( itr_line.IsValid() ){

	 auto itr_line_copy = itr_line;
	 const string& line_name = SyntaxToString( itr_line_copy , 1 );
	 
	 InputLine( ofs , function_expression_name , line_name , itr_line_copy , depth , language , style );
	 itr_line++;
    
       }

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );

  return;

}

void SyntaxOfComputableFunction::InputNonListLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  TRY_CATCH
    (

     {
       
       if( line_name == IfString() ){

	 InputIfLine( ofs , function_expression_name , itr_line , depth , language , style );
	 return;

       }
    
       if( line_name == PutString() ){

	 InputPutLine( ofs , itr_line , depth , language , style );
	 return;

       }

       if( line_name == PrintString() ){

	 InputPrintLine( ofs , itr_line , language , style );
	 return;

       }

       if( line_name == ExitString() ){

	 InputExitLine( ofs , function_expression_name , language , style );
	 return;

       }

       if( line_name == ReturnString() ){

	 InputReturnLine( ofs , function_expression_name , itr_line , depth , language , style );
	 return;

       }

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );

  ERR_IMPUT( line_name );
  return;

}

void SyntaxOfComputableFunction::InputIndent( ofstream& ofs , const uint depth , const string& language , const string& style ) const noexcept
{

  if( style == FandomString() ){

    string s = "#";

    for( uint i = 0 ; i < depth ; i++ ){

      s += "#";

    }

    s += " ";

    ofs << s;
    return;

  }

  ERR_IMPUT( style );
  return;

}

void SyntaxOfComputableFunction::InputIfLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  auto itr_condition = itr_line;
  itr_line++;

  TRY_CATCH
    (

     {
	 
       const string& condition_name = ConditionToString( itr_condition , language , style );
       const string& line_name = SyntaxToString( itr_line , 1 );

       if( line_name == ListString() ){

	 InputIfListLine( ofs , function_expression_name , condition_name , itr_line , depth , language , style );
	 InputListLine( ofs , function_expression_name , itr_line , depth+1 , language , style );

       } else {
    
	 InputIfNonListLine( ofs , function_expression_name , condition_name , itr_line , depth , language , style );
	 InputNonListLine( ofs , function_expression_name , line_name , itr_line , depth+1 , language , style );

       }

     } ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  return;

}

void SyntaxOfComputableFunction::InputIfListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  if( language == JapaneseString() ){

    ofs << condition_name << "とする。" << endl;
    return;
      
  }

  if( language == EnglishString() ){

    ofs << "Suppose that " << condition_name << "." << endl;
    return;
	     
  }
  
  ERR_IMPUT( language );
  return;

}

void SyntaxOfComputableFunction::InputIfNonListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name ,  VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  if( language == JapaneseString() ){

    ofs << "もし" << condition_name << "ならば、";
    return;
    
  }

  if( language == EnglishString() ){

    ofs << "If " << condition_name << ", then " << endl;
    return;
      
  }
    
  ERR_IMPUT( language );
  return;

}

void SyntaxOfComputableFunction::InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  auto itr_variable = itr_line;
  itr_line++;

  const string* p_variable_name;
  const string* p_variable_type_name;
  
  TRY_CATCH
    (

     p_variable_name = &( SyntaxToString( itr_variable , 2 ) ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  TRY_CATCH
    (

     p_variable_type_name = &( *itr_variable ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  TRY_CATCH
    (

     {

       if( *p_variable_type_name == GetName<bool>() ){

	 InputPutConditionLine( ofs , itr_line , *p_variable_name , language , style );

       } else {

	 InputPutNonConditionLine( ofs , itr_line , *p_variable_name , *p_variable_type_name , language , style );

       }

     } ,

     const ErrorType& e ,

     CALL_P( e , depth )

     );


  return;

}

void SyntaxOfComputableFunction::InputPutConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "条件" << ConditionToString( itr_line , language , style ) << "を\\(" << variable_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "I abbreviate the condition " << ConditionToString( itr_line , language , style ) << " to \\(" << variable_name << "\\)." << endl;
    return;
      

  }

  ERR_IMPUT( language , style );
  return;
  
}

void SyntaxOfComputableFunction::InputPutNonConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , const string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "\\(" << variable_name << " := " << ExpressionToString( itr_line ) << " \\in " << variable_type_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "I put \\(" << variable_name << " := " << ExpressionToString( itr_line ) << " \\in " << variable_type_name << "\\)." << endl;
    return;
      
  }

  ERR_IMPUT( language , style );
  return;
  
}


void SyntaxOfComputableFunction::InputPrintLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& language , const string& style ) const
{

  const string* p_variable_name;
  
  TRY_CATCH
    (

     p_variable_name = &( SyntaxToString( itr_line , 2 ) ) ,
     
     const ErrorType& e ,

     CALL( e )

     );
  
  if( language == JapaneseString() && style == FandomString() ){

    ofs << "デバッグ時に\\(" << *p_variable_name << "\\)の標準出力を行う。この操作は計算結果に影響を与えない。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "When I debug this code, I stdout \\(" << *p_variable_name << "\\). This line does not effect the result of the computation." << endl;
    return;
      
  }

  ERR_IMPUT( language , style );
  return;

}

void SyntaxOfComputableFunction::InputExitLine( ofstream& ofs , const string& function_expression_name , const string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){
    
    ofs << "\\(" << function_expression_name << "\\)は未定義である。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){
    
    ofs << "\\(" << function_expression_name << "\\) is undefined." << endl;
    return;

  }

  ERR_IMPUT( language , style );
  return;

}

void SyntaxOfComputableFunction::InputReturnLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , const string& language , const string& style ) const
{

  const string* p_return_name;
  
  TRY_CATCH
    (

     p_return_name = &( SyntaxToString( itr_line , 2 ) ) ,
     
     const ErrorType& e ,

     CALL( e )

     );

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "\\(" << function_expression_name << " := " << *p_return_name << "\\)と定める。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "I set \\(" << function_expression_name << " := " << *p_return_name << "\\)." << endl;
    return;
      
  }

  ERR_IMPUT( language , style );
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

static bool IsPolishSeparator( const VLTree<string>::const_iterator& itr_sep );
static bool IsNonPolishFunctionExpression( const VLTree<string>::const_iterator& itr_arg );

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
  
  TRY_CATCH
    (

     polish_f = IsPolishSeparator( itr_f ) ,
     const ErrorType& e ,
     CALL( e )

     );
    
  while( itr_args.IsValid() ){

    if( variadic ){

      itr_f--;

    }
    
    if( ! itr_f.IsValid() ){

      ERR_IMPUT( s , *itr_args );
       
    }

    const string& sep_current = *itr_f;

    if( ! variadic && sep_current == LdotsString() ){

      itr_f++;

      if( ! itr_f.IsValid() ){

	ERR_IMPUT( s , *itr_args );

      }

      variadic = true;
      s += *itr_f;

    } else {

      s += sep_current;

    }

    bool ambiguous = ! polish_f;

    if( ambiguous ){
      
      TRY_CATCH
	(

	 ambiguous = IsNonPolishFunctionExpression( itr_args ) ,
	 const ErrorType& e ,
	 CALL( e )

	 );

    }

    string arg_current;

    TRY_CATCH
      (

       arg_current = ExpressionToString( itr_args ) ,
       const ErrorType& e ,
       CALL( e )

       );

    if( ambiguous ){

      arg_current = "( " + arg_current + " )";

    }
    
    s += arg_current;
    
    itr_f++;

  }

  const string& sep_current = *itr_f;
  
  if( ! variadic && sep_current == LdotsString() ){

    itr_f++;
    itr_f++;
      
    if( ! itr_f.IsValid() ){

      ERR_IMPUT( s );

    }
      
    variadic = true;
    s += *itr_f;

  } else {

    s += sep_current;

  }

  itr_f++;

  if( itr_f.IsValid() ){

    ERR_IMPUT( *itr_f , variadic );
       
  }
  
  return s;
  
}

static bool IsPolishSeparator( const VLTree<string>::const_iterator& itr_sep )
{

  const string* p_sep;

  TRY_CATCH
    (

     p_sep = &( *itr_sep ) ,
     const ErrorType& e ,
     CALL( e )

     );

  return *p_sep != EmptyString() && *p_sep != SpaceString();

}

static bool IsNonPolishFunctionExpression( const VLTree<string>::const_iterator& itr_arg )
{

  string s;

  auto itr_sep = itr_arg;
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

    return s == EmptyString() || s == SpaceString();

  }

  return false;

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

string ConditionToString( VLTree<string>::const_iterator& itr , const string& language , const string& style )
{

  auto itr_copy = itr;
  itr++;
  itr_copy[1];

  const string* p_type;

  TRY_CATCH
    (

     p_type = &( *itr_copy ) ,
     const ErrorType& e ,
     CALL( e )

     );

  itr_copy++;

  if( *p_type != FunctionString() ){

    const string* p_b;

    TRY_CATCH
      (

       p_b = &( *itr_copy ) ,
       const ErrorType& e ,
       CALL( e )

       );

    return "\\(" + *p_b + "\\)";

  }
  
  itr_copy++;
  itr_copy++;

  auto itr_f = itr_copy;
  itr_copy++;
  itr_f[2];

  const string* p_f;

  TRY_CATCH
    (

     {
       
       p_f = &( *itr_f );

       if( *p_f == NegString() ){

	 return NegationToString( itr_copy , language , style );
    
       }

       if( *p_f == ToString() ){

	 return ImplicationToString( itr_copy , language , style );

       }
       
       if( *p_f == EquivString() ){

	 return EquivalenceToString( itr_copy , language , style );

       }
       
       if( *p_f == LandString() ){

	 return LogicalAndToString( itr_copy , language , style );

       }
       
       if( *p_f == LorString() ){

	 return LogicalOrToString( itr_copy , language , style );

       }
       
     } ,
     
     const ErrorType& e ,
     
     CALL( e )

     );

  ERR_IMPUT( *p_f );
  
  return "dummy";
  
}

string NegationToString( VLTree<string>::const_iterator& itr , const string& language , const string& style )
{

  string b;

  TRY_CATCH
    (

     b = ConditionToString( itr , language , style ),
     const ErrorType& e ,
     CALL( e )

     );

  
  if( language == JapaneseString() && style == FandomString() ){

    return "「" + b + "でない」";

  }

  if( language == EnglishString() && style == FandomString() ){

    return "( " + b + " does not hold )";
      
  }

  ERR_IMPUT( b , language , style );
  return "dummy";
  
}

string ImplicationToString( VLTree<string>::const_iterator& itr , const string& language , const string& style )
{

  string b0;
  string b1;

  TRY_CATCH
    (

     b0 = ConditionToString( itr , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );
    
  TRY_CATCH
    (

     b1 = ConditionToString( itr , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );


  if( language == JapaneseString() && style == FandomString() ){

    return "「" + b0 + "ならば" + b1 + "」";

  }

  if( language == EnglishString() && style == FandomString() ){

    return "( " + b0 + " implies " + b1 + " )";
      
  }

  ERR_IMPUT( b0 , b1 , language , style );
  return "dummy";

}

string EquivalenceToString( VLTree<string>::const_iterator& itr , const string& language , const string& style )
{

  string b0;
  string b1;

  TRY_CATCH
    (

     b0 = ConditionToString( itr , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );
    
  TRY_CATCH
    (

     b1 = ConditionToString( itr , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  if( language == JapaneseString() && style == FandomString() ){

    return "「" + b0 + "と" + b1 + "が同値である」";

  }

  if( language == EnglishString() && style == FandomString() ){

    return "( " + b0 + " is equivalent to " + b1 + " )";
      
  }

  ERR_IMPUT( b0 , b1 , language , style );
  return "dummy";

}

string LogicalAndToString( VLTree<string>::const_iterator& itr , const string& language , const string& style )
{

  string b;

  TRY_CATCH
    (

     b = ConditionToString( itr , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  bool first = true;

  if( language == JapaneseString() && style == FandomString() ){

    while( itr.IsValid() ){

      if( first ){

	b = "「" + b;
	first = false;

      }

      b += "かつ";
      b += ConditionToString( itr , language , style );

    }

    if( ! first ){

      b += "」";

    }

    return b;

  }

  if( language == EnglishString() && style == FandomString() ){

    while( itr.IsValid() ){

      if( first ){

	b = "( " + b;
	first = false;

      }

      b += ", ";

      const string b_current = ConditionToString( itr , language , style );

      if( ! itr.IsValid() ){

	b += "and ";

      }

      b += b_current;

    }

    if( ! first ){

      b += " )";

    }

    return b;
      
  }

  ERR_IMPUT( b , language , style );
  return "dummy";
  
}

string LogicalOrToString( VLTree<string>::const_iterator& itr , const string& language , const string& style )
{

  string b;

  TRY_CATCH
    (

     b = ConditionToString( itr , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  bool first = true;

  if( language == JapaneseString() && style == FandomString() ){

    while( itr.IsValid() ){

      if( first ){

	b = "「" + b;
	first = false;

      }

      b += "または";
      b += ConditionToString( itr , language , style );

    }

    if( ! first ){

      b += "」";

    }

    return b;

  }

  if( language == EnglishString() && style == FandomString() ){

    while( itr.IsValid() ){

      if( first ){

	b = "( " + b;
	first = false;

      }

      b += ", ";

      const string b_current = ConditionToString( itr , language , style );

      if( ! itr.IsValid() ){

	b += "or ";

      }

      b += b_current;

    }

    if( ! first ){

      b += " )";

    }

    return b;
      
  }

  ERR_IMPUT( b , language , style );
  return "dummy";
  
}

