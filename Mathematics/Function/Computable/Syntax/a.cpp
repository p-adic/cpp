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

string SyntaxOfComputableFunction::Display( const string& name , const string& language ) const noexcept
{

  if( language == JapaneseString() ){

    const string s = " " + name + " の木構造を出力します：";
    cout << s << endl;
    return m_syntax.Display();

  }

  if( language == EnglishString() ){

    const string s = "Displaying the tree structure of " + name + " :";
    cout << s << endl;
    return m_syntax.Display();

  }

  if( language == ChineseString() ){

    const string s = "顯示 " + name + " 的樹状結構：";
    cout << s << endl;
    return m_syntax.Display();

  }

  if( language == FrenchString() ){

    const string s = u8"Affichage de la structure arborescente de " + name + u8" :";
    cout << s << endl;
    return m_syntax.Display();

  }

  ERR_IMPUT( language );
  return "dummy";

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

     InputTotality( ofs , totality , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );
    
  string language_copy = language;
  
  TRY_CATCH
    (

     {
       
       InputDeclaration( ofs , function_name , *p_argument_type_name , *p_argument_name , *p_return_type_name , *p_function_expression_name , language , style );
       InputLine( ofs , *p_function_expression_name , *p_line_name , itr_line , 0 , language_copy , style );

     },
     
     const ErrorType& e ,

     CALL( e )

     );

  return;
  
}

void SyntaxOfComputableFunction::InputTotality( ofstream& ofs , const string& totality , const string& language , const string& style ) const
{

  if( language == JapaneseString() ){

    if( totality == RecursiveString() ){

      ofs << "計算可能関数" << endl;
      return;

    }

    if( totality == PartialString() ){

      ofs << "計算可能部分関数" << endl;
      return;

    }

    if( totality == TotalString() ){

      ofs << "計算可能全域関数" << endl;
      return;

    }

    if( totality == PrimitiveString() ){

      ofs << "原始再帰的関数" << endl;
      return;

    }

  }

  if( language == EnglishString() ){

    ofs << "I define a " << totality << " function" << endl;
    return;

  }

  if( language == ChineseString() ){

    ofs << "我定義一個";
    
    if( totality == RecursiveString() ){

      ofs << "可計算函數" << endl;
      return;

    }

    if( totality == PartialString() ){

      ofs << "可計算偏函數" << endl;
      return;

    }

    if( totality == TotalString() ){

      ofs << "可計算全函數" << endl;
      return;

    }

    if( totality == PrimitiveString() ){

      ofs << "原始遞歸函數" << endl;
      return;

    }

  }


  if( language == FrenchString() ){

    ofs << u8"Je définis une fonction";
    
    if( totality == RecursiveString() ){

      ofs << u8"récursive" << endl;
      return;

    }

    if( totality == PartialString() ){

      ofs << u8"partielle récursive" << endl;
      return;

    }

    if( totality == TotalString() ){

      ofs << u8"totale récursive" << endl;
      return;

    }

    if( totality == PrimitiveString() ){

      ofs << u8"récursive primitive" << endl;
      return;

    }

  }

  ERR_IMPUT( totality ,  language );
  return;

}

void SyntaxOfComputableFunction::InputDeclaration( ofstream& ofs , const string& function_name , const string& argument_type_name , const string& argument_name , const string& return_type_name , const string& function_expression_name , const string& language , const string& style ) const
{

  if( style == FandomString() ){

    ofs << "\\begin{eqnarray*}" << endl;
    ofs << function_name << " \\colon " << argument_type_name << " & \\to & " << return_type_name << " \\\\" << endl;
    ofs << argument_name << " & \\mapsto & " << function_expression_name << endl;
    ofs << "\\end{eqnarray*}" << endl;

  } else {

    ERR_IMPUT( style );

  }

  if( language == JapaneseString() ){

    ofs << "を以下のように再帰的に定める：" << endl;
    return;

  }
  
  if( language == EnglishString() ){

    ofs << "in the following recursive way:" << endl;
    return;

  }

  if( language == ChineseString() ){

    ofs << "用遞歸方法如下:" << endl;
    return;

  }


  if( language == FrenchString() ){

    ofs << u8"de la manière récursive suivante:" << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void SyntaxOfComputableFunction::InputLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
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

void SyntaxOfComputableFunction::InputListLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
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

void SyntaxOfComputableFunction::InputNonListLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
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
       
       if( line_name == CharacteriseString() ){

	 InputCharacterisationLine( ofs , itr_line , depth , language , style );
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

void SyntaxOfComputableFunction::InputIndent( ofstream& ofs , const uint depth , string& language , const string& style ) const noexcept
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

void SyntaxOfComputableFunction::InputIfLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
{

  auto itr_condition = itr_line;
  itr_line++;

  TRY_CATCH
    (

     {

       bool complicated = false;
       const string& condition_name = ConditionToString( itr_condition , complicated , language , style );
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

void SyntaxOfComputableFunction::InputIfListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
{

  if( language == JapaneseString() ){

    ofs << condition_name << "とする。" << endl;
    return;
      
  }

  if( language == EnglishString() ){

    ofs << "Suppose that " << condition_name << "." << endl;
    return;
    
  }
  
  if( language == englishString() ){

    ofs << "suppose that " << condition_name << "." << endl;
    language = EnglishString();
    return;
    
  }
  
  if( language == ChineseString() ){

    ofs << "設想" << condition_name << "成立。" << endl;
    return;
    
  }
  
  if( language == FrenchString() ){

    ofs << u8"Supposons que " << condition_name << u8"." << endl;
    return;
    
  }
  
  if( language == frenchString() ){

    ofs << u8"supposons que " << condition_name << u8"." << endl;
    language = FrenchString();
    return;
    
  }
  
  ERR_IMPUT( language );
  return;

}

void SyntaxOfComputableFunction::InputIfNonListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name ,  VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
{

  if( language == JapaneseString() ){

    ofs << "もし" << condition_name << "ならば、";
    return;
    
  }

  if( language == EnglishString() ){

    ofs << "If " << condition_name << ", then ";
    language = englishString();
    return;
      
  }
    
  if( language == englishString() ){

    ofs << "if " << condition_name << ", then ";
    return;
      
  }

  if( language == ChineseString() ){

    ofs << "如果" << condition_name << ", 則";
    return;
      
  }
    
  if( language == FrenchString() ){

    ofs << u8"Si" << condition_name << u8", alos ";
    language = frenchString();
    return;
      
  }
    
  if( language == frenchString() ){

    ofs << u8"si " << condition_name << u8", then ";
    return;
      
  }
  
  ERR_IMPUT( language );
  return;

}

void SyntaxOfComputableFunction::InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
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

     itr_variable[2];
     p_variable_type_name = &( *itr_variable ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  TRY_CATCH
    (

     {

       if( *p_variable_type_name == GetTypeString<bool>() ){

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

void SyntaxOfComputableFunction::InputPutConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_cond , const string& variable_name , string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){

    bool complicated = false;
    string b = ConditionToString( itr_cond , complicated , language , style );
    
    if( complicated ){

      PutKagi( b );

    }
    
    ofs << "条件" << b << "を\\(" << variable_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    bool complicated = false;
    string b = ConditionToString( itr_cond , complicated , language , style );

    if( complicated ){

      PutParenthesis( b );

    }
    
    ofs << "Abbreviate the condition " << b << " to \\(" << variable_name << "\\)." << endl;
    return;

  }

  if( language == englishString() && style == FandomString() ){

    bool complicated = false;
    string b = ConditionToString( itr_cond , complicated , language , style );

    if( complicated ){

      PutParenthesis( b );

    }
    
    ofs << "abbreviate the condition " << b << " to \\(" << variable_name << "\\)." << endl;
    language = EnglishString();
    return;

  }

  if( language == ChineseString() && style == FandomString() ){

    bool complicated = false;
    string b = ConditionToString( itr_cond , complicated , language , style );
    
    if( complicated ){

      PutKagi( b );

    }
    
    ofs << "令" << b << "為條件\\(" << variable_name << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    bool complicated = false;
    string b = ConditionToString( itr_cond , complicated , language , style );

    if( complicated ){

      PutParenthesis( b );

    }
    
    ofs << u8"Abréger la condition " << b << u8" à \\(" << variable_name << u8"\\)." << endl;
    return;

  }

  if( language == frenchString() && style == FandomString() ){

    bool complicated = false;
    string b = ConditionToString( itr_cond , complicated , language , style );

    if( complicated ){

      PutParenthesis( b );

    }
    
    ofs << u8"abréger la condition " << b << u8" à \\(" << variable_name << u8"\\)." << endl;
    language = FrenchString();
    return;

  }

  ERR_IMPUT( language , style );
  return;
  
}

void SyntaxOfComputableFunction::InputPutNonConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_e , const string& variable_name , const string& variable_type_name , string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "\\(" << variable_name << " := " << ExpressionToString( itr_e ) << " \\in " << variable_type_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "Put \\(" << variable_name << " := " << ExpressionToString( itr_e ) << " \\in " << variable_type_name << "\\)." << endl;
    return;
      
  }

  if( language == englishString() && style == FandomString() ){

    ofs << "put \\(" << variable_name << " := " << ExpressionToString( itr_e ) << " \\in " << variable_type_name << "\\)." << endl;
    language = EnglishString();
    return;
      
  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "令\\(" << variable_name << " := " << ExpressionToString( itr_e ) << " \\in " << variable_type_name << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << u8"Pose \\(" << variable_name << u8" := " << ExpressionToString( itr_e ) << u8" \\in " << variable_type_name << u8"\\)." << endl;
    return;
      
  }

  if( language == frenchString() && style == FandomString() ){

    ofs << u8"pose \\(" << variable_name << u8" := " << ExpressionToString( itr_e ) << u8" \\in " << variable_type_name << u8"\\)." << endl;
    language = FrenchString();
    return;
      
  }

  ERR_IMPUT( language , style );
  return;
  
}

void SyntaxOfComputableFunction::InputCharacterisationLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
{

  auto itr_variable = itr_line;
  itr_line++;

  const string* p_variable_name;
  const string* p_variable_type_name;
  const string* p_characterisation;
  
  TRY_CATCH
    (

     p_variable_name = &( SyntaxToString( itr_variable , 2 ) ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  TRY_CATCH
    (

     itr_variable[2];
     p_variable_type_name = &( *itr_variable ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  TRY_CATCH
    (

     p_characterisation = &( *itr_line ) ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  const string& characterisation = *p_characterisation;
  
  TRY_CATCH
    (

     {

       if( characterisation == UExistString() ){

	 InputUniqueExistenceLine( ofs , itr_line , *p_variable_name , *p_variable_type_name , language , style );
	 return;
	 
       }

       if( characterisation == MinString() ){

	 InputMinimumLine( ofs , itr_line , *p_variable_name , *p_variable_type_name , language , style );
	 return;
	 
       }

       if( characterisation == MaxString() ){

	 InputMaximumLine( ofs , itr_line , *p_variable_name , *p_variable_type_name , language , style );
	 return;
	 
       }
       
     } ,

     const ErrorType& e ,

     CALL_P( e , depth )

     );


  ERR_IMPUT( characterisation );
  return;

}

void SyntaxOfComputableFunction::InputUniqueExistenceLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style ) const
{

  const string* p_local_variable;
  const string* p_bound;
  string condition;
  bool complicated = false;

  itr_line++;
  
  TRY_CATCH
    (

     p_local_variable = &( ExpressionToString( itr_line ) ) ,
     const ErrorType& e ,
     CALL( e )

     );

  TRY_CATCH
    (

     p_bound = &( ExpressionToString( itr_line ) ) ,
     const ErrorType& e ,
     CALL( e )
     
     );

  TRY_CATCH
    (

     condition = ConditionToString( itr_line , complicated , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  TRY_CATCH
    (
     
     {
       
       if( variable_type_name == GetTypeString<nat>() ){

	 InputUniqueExistenceNaturalNumberLine( ofs , *p_local_variable , *p_bound , condition , variable_name , variable_type_name , language , style );
	 return;

       }

       if ( variable_type_name == GetTypeString<string>() ){

	 InputUniqueExistenceStringLine( ofs , *p_local_variable , *p_bound , condition , variable_name , variable_type_name , language , style );
	 return;

       }

     } ,

     const ErrorType& e ,

     CALL( e )

     );

  ERR_IMPUT( variable_type_name );
  return;
  
}

void SyntaxOfComputableFunction::InputUniqueExistenceNaturalNumberLine( ofstream& ofs , const string& local_variable , const string& bound , const string& condition , const string& variable_name , const string& variable_type_name , string& language , const string& style ) const
{
  
  if( language == JapaneseString() && style == FandomString() ){

    ofs << condition << "を満たす\\(" << bound << "\\)以下の一意な\\(" << local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "Denote by \\(" << variable_name << "\\) the unique \\(" << local_variable << " \\in " << variable_type_name << "\\) greater than or equal to \\(" << bound << "\\) satisfying " << condition << "." << endl;
    return;
    
  }

  if( language == englishString() && style == FandomString() ){

    ofs << "denote by \\(" << variable_name << "\\) the unique \\(" << local_variable << " \\in " << variable_type_name << "\\) greater than or equal to \\(" << bound << "\\) satisfying " << condition << "." << endl;
    language = EnglishString();
    return;
      
  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "定義\\(" << variable_name << "\\)是小於或等於\\(" << bound << "\\)且滿足條件" << condition << "的唯一\\(" << local_variable << " \\in " << variable_type_name << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << u8"Notons \\(" << variable_name << u8"\\) l'unique \\(" << local_variable << u8" \\in " << variable_type_name << u8"\\) supérieur ou égal à \\(" << bound << u8"\\) satisfaisant " << condition << u8"." << endl;
    return;
    
  }

  if( language == frenchString() && style == FandomString() ){

    ofs << u8"notons \\(" << variable_name << u8"\\) l'unique \\(" << local_variable << u8" \\in " << variable_type_name << u8"\\) supérieur ou égal à \\(" << bound << u8"\\) satisfaisant " << condition << u8"." << endl;
    language = FrenchString();
    return;
      
  }

  ERR_IMPUT( language , style );
  return;
  
}

void SyntaxOfComputableFunction::InputUniqueExistenceStringLine( ofstream& ofs , const string& local_variable , const string& bound , const string& condition , const string& variable_name , const string& variable_type_name , string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << condition << "を満たす\\(" << bound << "\\)の一意な部分文字列\\(" << local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "Denote by \\(" << variable_name << "\\) the unique substring \\(" << local_variable << " \\in " << variable_type_name << "\\) of \\(" << bound << "\\) satisfying " << condition << "." << endl;
    return;
      
  }

  if( language == englishString() && style == FandomString() ){

    ofs << "denote by \\(" << variable_name << "\\) the unique substring \\(" << local_variable << " \\in " << variable_type_name << "\\) of \\(" << bound << "\\) satisfying " << condition << "." << endl;
    return;
      
  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "定義\\(" << variable_name << "\\)是滿足條件" << condition << "的\\(" << bound << "\\)的唯一子串\\(" << local_variable << " \\in " << variable_type_name << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << u8"Notons \\(" << variable_name << u8"\\) la sous-chaîne unique \\(" << local_variable << u8" \\in " << variable_type_name << u8"\\) supérieur ou égal à \\(" << bound << u8"\\) satisfaisant " << condition << u8"." << endl;
    return;
    
  }

  if( language == frenchString() && style == FandomString() ){

    ofs << u8"notons \\(" << variable_name << u8"\\) la sous-chaîne unique \\(" << local_variable << u8" \\in " << variable_type_name << u8"\\) supérieur ou égal à \\(" << bound << u8"\\) satisfaisant " << condition << u8"." << endl;
    language = FrenchString();
    return;
      
  }
  
  ERR_IMPUT( language , style );
  return;
  
}

void SyntaxOfComputableFunction::InputMinimumLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style ) const
{

  if( variable_type_name != GetTypeString<nat>() ){

    ERR_IMPUT( variable_type_name );

  }

  const string* p_local_variable;
  string condition;
  bool complicated = false;

  itr_line++;

  TRY_CATCH
    (

     p_local_variable = &( ExpressionToString( itr_line ) ) ,
     const ErrorType& e ,
     CALL( e )

     );

  itr_line++;

  TRY_CATCH
    (

     condition = ConditionToString( itr_line , complicated , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  
  if( language == JapaneseString() && style == FandomString() ){

    ofs << condition << "を満たす最小の\\(" << *p_local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "Denote by \\(" << variable_name << "\\) the smallest \\(" << *p_local_variable << " \\in " << variable_type_name << "\\) satisfying " << condition << "." << endl;
    return;
    
  }

  if( language == englishString() && style == FandomString() ){

    ofs << "denote by \\(" << variable_name << "\\) the smallest \\(" << *p_local_variable << " \\in " << variable_type_name << "\\) satisfying " << condition << "." << endl;
    language = EnglishString();
    return;
      
  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "定義\\(" << variable_name << "\\)是滿足條件" << condition << "的最小的\\(" << *p_local_variable << " \\in " << variable_type_name << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << u8"Notons \\(" << variable_name << u8"\\) le moins \\(" << *p_local_variable << u8" \\in " << variable_type_name << u8"\\) satisfaisant " << condition << u8"." << endl;
    return;
    
  }

  if( language == frenchString() && style == FandomString() ){

    ofs << u8"notons \\(" << variable_name << u8"\\) le moins \\(" << *p_local_variable << u8" \\in " << variable_type_name << u8"\\) satisfaisant " << condition << u8"." << endl;
    language = FrenchString();
    return;
      
  }

  ERR_IMPUT( language , style );
  return;

}

void SyntaxOfComputableFunction::InputMaximumLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style ) const
{

  if( variable_type_name != GetTypeString<nat>() ){

    ERR_IMPUT( variable_type_name );

  }

  const string* p_local_variable;
  const string* p_bound;
  string condition;
  bool complicated = false;

  itr_line++;

  TRY_CATCH
    (

     p_local_variable = &( ExpressionToString( itr_line ) ) ,
     const ErrorType& e ,
     CALL( e )

     );

  TRY_CATCH
    (

     p_local_variable = &( ExpressionToString( itr_line ) ) ,
     const ErrorType& e ,
     CALL( e )

     );

  TRY_CATCH
    (

     condition = ConditionToString( itr_line , complicated , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );
  
  if( language == JapaneseString() && style == FandomString() ){

    ofs << condition << "を満たす\\(" << *p_bound << "\\)以下の最大の\\(" << *p_local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "Denote by \\(" << variable_name << "\\) the greatest \\(" << *p_local_variable << " \\in " << variable_type_name << "\\) smaller than or equal to \\(" << *p_bound << "\\) satisfying " << condition << "." << endl;
    return;
    
  }

  if( language == englishString() && style == FandomString() ){

    ofs << "denote by \\(" << variable_name << "\\) the greatest \\(" << *p_local_variable << " \\in " << variable_type_name << "\\) smallest than or equal to \\(" << *p_bound << "\\) satisfying " << condition << "." << endl;
    language = EnglishString();
    return;
      
  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "定義\\(" << variable_name << "\\)是小於或等於\\(" << *p_bound << "\\)且滿足條件" << condition << "的最大的\\(" << *p_local_variable << " \\in " << variable_type_name << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << u8"Notons \\(" << variable_name << u8"\\) le plus grand \\(" << *p_local_variable << u8" \\in " << variable_type_name << u8"\\) inférieur ou égal à \\(" << *p_bound << u8"\\) satisfaisant " << condition << u8"." << endl;
    return;
    
  }

  if( language == frenchString() && style == FandomString() ){

    ofs << u8"notons \\(" << variable_name << u8"\\) le plus grand \\(" << *p_local_variable << u8" \\in " << variable_type_name << u8"\\) inférieur ou égal à \\(" << *p_bound << u8"\\) satisfaisant " << condition << u8"." << endl;
    language = FrenchString();
    return;
      
  }

  ERR_IMPUT( language , style );
  return;

}


void SyntaxOfComputableFunction::InputPrintLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , string& language , const string& style ) const
{

  const string* p_variable_name;
  
  TRY_CATCH
    (

     p_variable_name = &( SyntaxToString( itr_line , 2 ) ) ,
     
     const ErrorType& e ,

     CALL( e )

     );
  
  if( language == JapaneseString() && style == FandomString() ){

    ofs << "\\(" << *p_variable_name << "\\)の標準出力を行う。この操作は計算結果に影響を与えない。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "Stdout \\(" << *p_variable_name << "\\). This line does not affect the result of the computation." << endl;
    return;
      
  }

  if( language == englishString() && style == FandomString() ){

    ofs << "stdout \\(" << *p_variable_name << "\\). This line does not affect the result of the computation." << endl;
    language = EnglishString();
    return;
      
  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "標準輸出\\(" << *p_variable_name << "\\)。這行不影響計算結果。" << endl;
    return;
      
  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << u8"Stdout \\(" << *p_variable_name << u8"\\). Cette ligne n'affecte pas le résultat du calcul." << endl;
    return;
      
  }

  if( language == frenchString() && style == FandomString() ){

    ofs << u8"stdout \\(" << *p_variable_name << u8"\\). Cette ligne n'affecte pas le résultat du calcul." << endl;
    language = FrenchString();
    return;
      
  }

  ERR_IMPUT( language , style );
  return;

}

void SyntaxOfComputableFunction::InputExitLine( ofstream& ofs , const string& function_expression_name , string& language , const string& style ) const
{

  if( language == JapaneseString() && style == FandomString() ){
    
    ofs << "\\(" << function_expression_name << "\\)は未定義である。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){
    
    ofs << "\\(" << function_expression_name << "\\) is undefined." << endl;
    return;

  }

  if( language == englishString() && style == FandomString() ){
    
    ofs << "\\(" << function_expression_name << "\\) is undefined." << endl;
    language = EnglishString();
    return;

  }

  if( language == ChineseString() && style == FandomString() ){
    
    ofs << "\\(" << function_expression_name << "\\)未定義。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){
    
    ofs << u8"\\(" << function_expression_name << u8"\\) n'est pas défini." << endl;
    return;

  }

  if( language == frenchString() && style == FandomString() ){
    
    ofs << u8"\\(" << function_expression_name << u8"\\) n'est pas défini." << endl;
    language = FrenchString();
    return;

  }

  ERR_IMPUT( language , style );
  return;

}

void SyntaxOfComputableFunction::InputReturnLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style ) const
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

    ofs << "Set \\(" << function_expression_name << " := " << *p_return_name << "\\)." << endl;
    return;
      
  }

  if( language == englishString() && style == FandomString() ){

    ofs << "set \\(" << function_expression_name << " := " << *p_return_name << "\\)." << endl;
    language = EnglishString();
    return;
      
  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "定義\\(" << function_expression_name << " := " << *p_return_name << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << u8"Définissez \\(" << function_expression_name << u8" := " << *p_return_name << u8"\\)." << endl;
    return;
      
  }

  if( language == frenchString() && style == FandomString() ){

    ofs << u8"définissez \\(" << function_expression_name << u8" := " << *p_return_name << u8"\\)." << endl;
    language = FrenchString();
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

    ERR_IMPUT( *itr_f , variadic );
       
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

    ERR_IMPUT( variadic );
       
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

string ConditionToString( VLTree<string>::const_iterator& itr , bool& complicated , string& language , const string& style )
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

  complicated = true;
  
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

string NegationToString( VLTree<string>::const_iterator& itr , string& language , const string& style )
{

  string b;
  bool complicated = false;
  
  TRY_CATCH
    (

     b = ConditionToString( itr , complicated , language , style ),
     const ErrorType& e ,
     CALL( e )

     );

  
  if( language == JapaneseString() ){

    if( complicated ){

      PutKagi( b );

    }
    
    return b + "でない";

  }

  if( language == EnglishString() ){

    if( complicated ){

      PutParenthesis( b );

    }

    return b + " does not hold";
      
  }

  if( language == ChineseString() ){

    if( complicated ){

      PutKagi( b );

    }

    return b + "不成立";
      
  }

  if( language == FrenchString() ){

    if( complicated ){

      PutParenthesis( b );

    }

    return b + u8" ne tient pas";
      
  }

  ERR_IMPUT( b , language , style );
  return "dummy";
  
}

string ImplicationToString( VLTree<string>::const_iterator& itr , string& language , const string& style )
{

  string b0;
  string b1;
  bool complicated0 = false;
  bool complicated1 = false;

  TRY_CATCH
    (

     b0 = ConditionToString( itr , complicated0 , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );
    
  TRY_CATCH
    (

     b1 = ConditionToString( itr , complicated1 , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );


  if( language == JapaneseString() ){

    if( complicated0 ){

      PutKagi( b0 );

    }

    if( complicated1 ){

      PutKagi( b1 );

    }

    return b0 + "ならば" + b1;

  }

  if( language == EnglishString() ){

    if( complicated0 ){

      PutParenthesis( b0 );

    }

    if( complicated1 ){

      PutParenthesis( b1 );

    }

    return b0 + " implies " + b1;
      
  }


  if( language == ChineseString() ){

    if( complicated0 ){

      PutKagi( b0 );

    }

    if( complicated1 ){

      PutKagi( b1 );

    }

    return "若" + b0 + "則" + b1;

  }

  if( language == FrenchString() ){

    if( complicated0 ){

      PutParenthesis( b0 );

    }

    if( complicated1 ){

      PutParenthesis( b1 );

    }

    return u8"si" + b0 + u8" alors " + b1;
      
  }

  ERR_IMPUT( b0 , b1 , language );
  return "dummy";

}

string EquivalenceToString( VLTree<string>::const_iterator& itr , string& language , const string& style )
{

  string b0;
  string b1;
  bool complicated0 = false;
  bool complicated1 = false;

  TRY_CATCH
    (

     b0 = ConditionToString( itr , complicated0 , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );
    
  TRY_CATCH
    (

     b1 = ConditionToString( itr , complicated1 , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  if( language == JapaneseString() ){

    if( complicated0 ){

      PutKagi( b0 );

    }

    if( complicated1 ){

      PutKagi( b1 );

    }

    return b0 + "と" + b1 + "が同値である";

  }

  if( language == EnglishString() ){

    if( complicated0 ){

      PutParenthesis( b0 );

    }

    if( complicated1 ){

      PutParenthesis( b1 );

    }

    return b0 + " is equivalent to " + b1;
      
  }

  if( language == ChineseString() ){

    if( complicated0 ){

      PutKagi( b0 );

    }

    if( complicated1 ){

      PutKagi( b1 );

    }

    return b0 + "和" + b1 + "彼此等价";

  }

  if( language == FrenchString() ){

    if( complicated0 ){

      PutParenthesis( b0 );

    }

    if( complicated1 ){

      PutParenthesis( b1 );

    }

    return b0 + u8" est équivalent à " + b1;
      
  }

  ERR_IMPUT( b0 , b1 , language , style );
  return "dummy";

}

string LogicalAndToString( VLTree<string>::const_iterator& itr , string& language , const string& style )
{

  string b = "";

  TRY_CATCH
    (

     {
       
       if( language == JapaneseString() ){

	 bool first = true;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;

	     if( complicated && itr.IsValid() ){

	       PutKagi( b_current );

	     }

	   } else {

	     if( complicated ){

	       PutKagi( b_current );

	     }

	     b += "かつ";

	   }

	   b += b_current;

	 }

	 return b;
	   
       }

       if( language == EnglishString() ){

	 bool first = true;
	 bool second = false;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;
	     second = true;

	     if( complicated && itr.IsValid() ){

	       PutParenthesis( b_current );

	     }

	   } else {
	     
	     if( complicated ){

	       PutParenthesis( b_current );

	     }

	     if( itr.IsValid() ){

	       b += ", ";

	       if( second ){

		 second = false;

	       }

	     } else {

	       if( second ){

		 b += " ";
		 second = false;

	       } else {

		 b += ", ";

	       }

	       b += "and ";

	     }

	   }

	   b += b_current;

	 }

	 return b;

       }

       if( language == ChineseString() ){

	 bool first = true;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;

	     if( complicated && itr.IsValid() ){

	       PutKagi( b_current );

	     }

	   } else {
	     
	     if( complicated ){

	       PutKagi( b_current );

	     }

	     if( itr.IsValid() ){

	       b += ", ";

	     } else {

	       b += "和";

	     }

	   }

	   b += b_current;

	 }

	 return b;

       }

       if( language == FrenchString() ){

	 bool first = true;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;

	     if( complicated && itr.IsValid() ){

	       PutParenthesis( b_current );

	     }

	   } else {
	     
	     if( complicated ){

	       PutParenthesis( b_current );

	     }

	     if( itr.IsValid() ){

	       b += u8", ";

	     } else {

	       b += u8"et ";

	     }

	   }

	   b += b_current;

	 }

	 return b;

       }       

     } ,

     const ErrorType& e ,
     
     CALL( e )

     );


  ERR_IMPUT( b , language , style );
  return "dummy";
  
}

string LogicalOrToString( VLTree<string>::const_iterator& itr , string& language , const string& style )
{

  string b = "";

  TRY_CATCH
    (

     {
       
       if( language == JapaneseString() && style == FandomString() ){

	 bool first = true;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;

	     if( complicated && itr.IsValid() ){

	       PutKagi( b_current );

	     }

	   } else {

	     if( complicated ){

	       PutKagi( b_current );

	     }

	     b += "または";

	   }

	   b += b_current;

	 }

	 return b;
	   
       }

       if( language == EnglishString() && style == FandomString() ){

	 bool first = true;
	 bool second = false;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;
	     second = true;

	     if( complicated && itr.IsValid() ){

	       PutParenthesis( b_current );

	     }

	   } else {
	     
	     if( complicated ){

	       PutParenthesis( b_current );

	     }

	     if( itr.IsValid() ){

	       b += ", ";

	       if( second ){

		 second = false;

	       }

	     } else {

	       if( second ){

		 b += " ";
		 second = false;

	       } else {

		 b += ", ";

	       }

	       b += "or ";

	     }

	   }

	   b += b_current;

	 }

	 return b;

       }

       if( language == ChineseString() ){

	 bool first = true;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;

	     if( complicated && itr.IsValid() ){

	       PutKagi( b_current );

	     }

	   } else {
	     
	     if( complicated ){

	       PutKagi( b_current );

	     }

	     if( itr.IsValid() ){

	       b += ", ";

	     } else {

	       b += "或";

	     }

	   }

	   b += b_current;

	 }

	 return b;

       }

       if( language == FrenchString() ){

	 bool first = true;
	 
	 while( itr.IsValid() ){

	   bool complicated = false;
	   string b_current = ConditionToString( itr , complicated , language , style );
	   
	   if( first ){

	     first = false;

	     if( complicated && itr.IsValid() ){

	       PutParenthesis( b_current );

	     }

	   } else {
	     
	     if( complicated ){

	       PutParenthesis( b_current );

	     }

	     if( itr.IsValid() ){

	       b += u8", ";

	     } else {

	       b += u8"ou ";

	     }

	   }

	   b += b_current;

	 }

	 return b;

       }
       
     } ,

     const ErrorType& e ,
     
     CALL( e )

     );

  ERR_IMPUT( b , language , style );
  return "dummy";
  
}

