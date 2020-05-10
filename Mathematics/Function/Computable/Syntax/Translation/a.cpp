// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../Type/Guide/TypeName/a_Body.hpp"
#include "../../Type/Basic/a_Body.hpp"

void DisplayTreeStructureOfDefinition( const string& function_name , const string& language )
{

  if( language == JapaneseString() ){

    cout << " " << function_name << " の定義文の木構造を出力します：" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Display the tree structure of the definition of " << function_name << ":" << endl;
    return;
    
  }

  if( language == ChineseString() ){

    cout << "顯示 " << function_name << " 的定義的樹状結構:" << endl;
    return;

  }

  if( language == FrenchString() ){

    cout << "Affichez l'arborescence de la d\\'efinition de " << function_name << ":" << endl;
    return;

  }

  if( language == GermanString() ){

    cout << "Zeigen Sie die Baumstruktur der Definition von " << function_name << " an:" << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void DisplayWritingTranslationOfDefinition( const string& function_name , const string& filename , const string& language )
{

  if( language == JapaneseString() ){

    cout << " " << function_name << " の定義文の日本語訳を " << filename << " に書き込みます：" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Writing an English translation of the definition of " << function_name << " to " << filename << ":" << endl;
    return;
    
  }

  if( language == ChineseString() ){

    cout << "將 " << function_name << " 的定義的中文翻譯到 " << filename << " 上寫" << endl;
    return;

  }

  if( language == FrenchString() ){

    cout << "\\'Ecrire une traduction en anglais de la d\\'efinition de " << function_name << " dans " << filename << ":" << endl;
    return;

  }

  if( language == GermanString() ){

    cout << "Verfassen einer englischen \\\"Ubersetzung der Definition von " << function_name << " auf " << filename << ":" << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void DisplayFileOpenError( const string& language ){

  if( language == JapaneseString() ){

    cout << "エラー：ファイルが開けませんでした。" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Error: Cannot open the file." << endl;
    return;
    
  }

  if( language == ChineseString() ){

    cout << "錯誤：無法打開文件。" << endl;
    return;

  }

  if( language == FrenchString() ){

    cout << "Erreur: impossible d'ouvrir le fichier." << endl;
    return;

  }

  if( language == GermanString() ){

    cout << "Fehler: Die Datei kann nicht ge\\\"offnet werden." << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void DisplayFinishedWriting( const string& language )
{

  if( language == JapaneseString() ){

    cout << "書き込みが終了しました。" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Finished writing." << endl;
    return;
    
  }

  if( language == ChineseString() ){

    cout << "寫完了。" << endl;
    return;

  }

  if( language == FrenchString() ){

    cout << "\\'Ecriture termin\\'ee." << endl;
    return;

  }

  if( language == GermanString() ){

    cout << "Fertiges Schreiben." << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void InputDefinitionOfRecursiveSet( ofstream& ofs , const string& type_name , const string& definition , const string& language , const string& style )
{

  string type_name_copy = type_name;
  string definition_copy = definition;

  SetDefinitionOfRecursiveSet( type_name_copy , definition_copy , language , style );
  InputSignatureOfRecursiveSet( ofs , type_name_copy , language , style );
  InputInlineWay( ofs , definition_copy , language , style );
  return;

}

void SetDefinitionOfRecursiveSet( string& type_name , string& definition , const string& language , const string& style )
{
  
  PutMathJax( type_name , style );
  PutMathJax( definition , style );
  return;
  
}

void InputSignatureOfRecursiveSet( ofstream& ofs , const string& type_name , const string& language , const string& style )
{

  if( language == JapaneseString() ){

    ofs << "集合" << type_name;
    return;

  }

  if( language == EnglishString() ){

    ofs << "I define a set " << type_name;
    return;
  }

  if( language == ChineseString() ){

    ofs << "我將集合" << type_name << "定義";
    return;

  }

  if( language == FrenchString() ){

    ofs << "Je d\\'efinis un ensemble " << type_name;
    return;

  }

  if( language == GermanString() ){

    ofs << "Ich definiere eine Menge " << type_name;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void InputInlineWay( ofstream& ofs , const string& definition , const string& language , const string& style )
{

  if( language == JapaneseString() ){

    ofs << "を" << definition << "と定める。" << endl;
    return;

  }

  if( language == EnglishString() ){

    ofs << " as " << definition << "." << endl;
    return;
  }

  if( language == ChineseString() ){

    ofs << "為" << definition << "。" << endl;
    return;

  }

  if( language == FrenchString() ){

    ofs << " comme " << definition << "." << endl;
    return;

  }

  if( language == GermanString() ){

    ofs << " als " << definition << "." << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void InputDefinitionOfArraySet( ofstream& ofs , const string& type_name , const string& description , const string& language , const string& style )
{

  string type_name_copy = type_name;
  string description_copy = description;

  SetDefinitionOfArraySet( type_name_copy , description_copy , language , style );
  InputSignatureOfRecursiveSet( ofs , type_name_copy , language , style );
  InputInlineWay( ofs , description_copy , language , style );
  return;

}

void SetDefinitionOfArraySet( string& type_name , string& description , const string& language , const string& style )
{

  SetDefinitionOfRecursiveSet( type_name , description , language , style );

  if( language == JapaneseString() ){

    description = description + "の元の配列全体の集合";
    return;

  }

  if( language == EnglishString() ){

    description = "the set of arrays of elements of " + description;
    return;
    
  }

  if( language == ChineseString() ){

    description = description + "的元素的數組的集合";
    return;

  }

  if( language == FrenchString() ){

    description = "l'ensemble des tableaux d'\\'el\\'ements de " + description;
    return;

  }

  if( language == GermanString() ){

    description = "die Menge von Arrays von Elementen der Menge " + description;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void InputDefinitionOfNestedArraySet( ofstream& ofs , const string& type_name , const string& description , const string& language , const string& style )
{

  string type_name_copy = type_name;
  string form11;
  string form12;
  string form21;
  string form22;
  string form23;

  SetDefinitionOfNestedArraySet( type_name_copy , description , form11 , form12 , form21 , form22 , form23 , language , style );

  InputSignatureOfRecursiveSet( ofs , type_name_copy , language , style );
  InputRecursiveWay( ofs , language , style );
  InputIndent( ofs , 0 , language , style );
  InputFirstRuleOfNestedArraySet( ofs , form11 , form12 , language , style );
  InputIndent( ofs , 0 , language , style );
  InputSecondRuleOfNestedArraySet( ofs , form21 , form22 , form23 , language , style );
  return;

}

void SetDefinitionOfNestedArraySet( string& type_name , const string& description , string& form11 , string& form12 ,  string& form21 , string& form22 , string& form23 , const string& language , const string& style )
{

  form11 = "x" + SpaceString() + InString() + SpaceString() + description;
  form12 = "x" + SpaceString() + InString() + SpaceString() + type_name;
  form21 = "n";
  form22 = "x_1" + CommaString() + LdotsString() + CommaString() + "x_n" + SpaceString() + InString() + SpaceString() + type_name;
  form23 = LparenString() + "x_1" + CommaString() + LdotsString() + CommaString() + "x_n" + RparenString() + SpaceString() + InString() + SpaceString() + type_name;

  PutMathJax( type_name , style );
  PutMathJax( form11 , style );
  PutMathJax( form12 , style );
  PutMathJax( form21 , style );
  PutMathJax( form22 , style );
  PutMathJax( form23 , style );
  return;

}

void InputRecursiveWay( ofstream& ofs , const string& language , const string& style )
{

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

    ofs << "de la mani\\`ere r\\'ecursive suivante:" << endl;
    return;

  }

  if( language == GermanString() ){

    ofs << "auf die folgende rekursive Weise:" << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void InputIndent( ofstream& ofs , const uint depth , const string& language , const string& style )
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

void InputFirstRuleOfNestedArraySet( ofstream& ofs , const string& form11 , const string& form12 , const string& language , const string& style )
{

  if( language == JapaneseString() ){

    ofs << "任意の" << form11 << "に対し、" << form12 << "である。" << endl;
    return;

  }

  if( language == EnglishString() ){

    ofs << "For any " << form11 << ", " << form12 << "." << endl;
    return;
  }

  if( language == ChineseString() ){

    ofs << "對于任意" << form11 << ", " << form12 << "成立。" << endl;
    return;

  }

  if( language == FrenchString() ){

    ofs << " Pour tout " << form11 << ", " << form12 << "." << endl;
    return;

  }

  if( language == GermanString() ){

    ofs << "Die Aussage " << form12 << " gilt f\\\"ur alle " << form11 << "." << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void InputSecondRuleOfNestedArraySet( ofstream& ofs , const string& form21 , const string& form22 , const string& form23 , const string& language , const string& style )
{

  if( language == JapaneseString() ){

    ofs << "任意の非負整数" << form21 << "と" << form22 << "に対し、" << form23 << "である。" << endl;
    return;

  }

  if( language == EnglishString() ){

    ofs << "For any non-negative integer " << form21 << " and " << form22 << ", " << form23 << "." << endl;
    return;
  }

  if( language == ChineseString() ){

    ofs << "對于任意非負整數" << form21 << "和" << form22 << ", " << form23 << "成立。" << endl;
    return;

  }

  if( language == FrenchString() ){

    ofs << " Pour tout entier non n\\'egatif " << form21 << " et " << form22 << ", " << form23 << "." << endl;
    return;

  }

  if( language == GermanString() ){

    ofs << "Die Aussage " << form23 << " gilt f\\\"ur alle nicht negative ganze Zahl " << form21 << " und " << form22 << "." << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}


void DisplayTreeStructure( const string& name , const string& language )
{

  if( language == JapaneseString() ){

    cout << " " << name << " の木構造を出力します：" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Display the tree structure of " << name << ":" << endl;
    return;
    
  }

  if( language == ChineseString() ){

    cout << "顯示" << name << "的樹状結構:" << endl;
    return;

  }

  if( language == FrenchString() ){

    cout << "Affichez l'arborescence de " << name << ":" << endl;
    return;

  }

  if( language == GermanString() ){

    cout << "Zeigen Sie die Baumstruktur von " << name << " an:" << endl;
    return;

  }

  ERR_IMPUT( language );
  return;

}

void InputTotality( ofstream& ofs , const string& totality , const string& language , const string& style )
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

    ofs << "Je d\\'efinis une fonction ";
    
    if( totality == RecursiveString() ){

      ofs << "r\\'ecursive" << endl;
      return;

    }

    if( totality == PartialString() ){

      ofs << "partielle r\\'ecursive" << endl;
      return;

    }

    if( totality == TotalString() ){

      ofs << "totale r\\'ecursive" << endl;
      return;

    }
    
    if( totality == PrimitiveString() ){

      ofs << "r\\'ecursive primitive" << endl;
      return;

    }

  }
  

  if( language == GermanString() ){

    ofs << "Ich definiere eine ";
    
    if( totality == RecursiveString() ){

      ofs << "rekursive Funktion" << endl;
      return;

    }

    if( totality == PartialString() ){

      ofs << "rekursive partielle Funktion" << endl;
      return;

    }

    if( totality == TotalString() ){

      ofs << "rekursive Gesamtfunktion" << endl;
      return;

    }
    
    if( totality == PrimitiveString() ){

      ofs << "primitive rekursive Funktion" << endl;
      return;

    }

  }

  ERR_IMPUT( totality ,  language );
  return;

}

void InputSignatureOfFunction( ofstream& ofs , const string& function_name , const string& argument_type_name , const string& argument_name , const string& return_type_name , const string& function_expression_name , const string& language , const string& style )
{

  if( style == FandomString() ){

    ofs << "\\begin{eqnarray*}" << endl;
    ofs << function_name << " \\colon " << argument_type_name << " & \\to & " << return_type_name << " \\\\" << endl;
    ofs << argument_name << " & \\mapsto & " << function_expression_name << endl;
    ofs << "\\end{eqnarray*}" << endl;
    return;

  }
  
  ERR_IMPUT( style );
  return;

}


void InputLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style )
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

void InputListLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style )
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

void InputNonListLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style )
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

	 InputReturnLine( ofs , function_expression_name , itr_line , language , style );
	 return;

       }

     } ,
     
     const ErrorType& e ,

     CALL( e )

     );

  ERR_IMPUT( line_name );
  return;

}

void InputIfLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style )
{

  auto itr_condition = itr_line;
  itr_line++;

  TRY_CATCH
    (

     {

       bool complicated = false;
       string condition_name = ConditionToString( itr_condition , complicated , language , style );

       if( complicated ){

	 PutWrap( condition_name , language );
    
       }
       
       const string& line_name = SyntaxToString( itr_line , 1 );

       if( line_name == ListString() ){

	 InputIfListLine( ofs , function_expression_name , condition_name , itr_line , language , style );
	 InputListLine( ofs , function_expression_name , itr_line , depth + 1 , language , style );

       } else {
    
	 InputIfNonListLine( ofs , function_expression_name , condition_name , itr_line , language , style );
	 InputNonListLine( ofs , function_expression_name , line_name , itr_line , depth + 1 , language , style );

       }

     } ,
     
     const ErrorType& e ,

     CALL_P( e , depth )

     );

  return;

}

void InputIfListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , string& language , const string& style )
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

    language = EnglishString();
    ofs << "suppose that " << condition_name << "." << endl;
    return;
    
  }
  
  if( language == ChineseString() ){

    ofs << "設想" << condition_name << "成立。" << endl;
    return;
    
  }
  
  if( language == FrenchString() ){

    ofs << "Supposons que " << condition_name << "." << endl;
    return;
    
  }
  
  if( language == frenchString() ){

    language = FrenchString();
    ofs << "supposons que " << condition_name << "." << endl;
    return;
    
  }
  
  if( language == GermanString() ){

    ofs << "Angenommen, " << condition_name << "." << endl;
    return;
    
  }
  
  if( language == germanString() ){

    language = GermanString();
    ofs << "angenommen, " << condition_name << "." << endl;
    return;
    
  }

  ERR_IMPUT( language );
  return;

}

void InputIfNonListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , string& language , const string& style )
{

  if( language == JapaneseString() ){

    ofs << "もし" << condition_name << "ならば、";
    return;
    
  }

  if( language == EnglishString() ){

    language = englishString();
    ofs << "If " << condition_name << ", then ";
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

    language = frenchString();
    ofs << "Si " << condition_name << ", alos ";
    return;
      
  }
    
  if( language == frenchString() ){

    ofs << "si " << condition_name << ", alos ";
    return;
      
  }
  
  if( language == GermanString() ){

    language = germanString();
    ofs << "Wenn " << condition_name << ", dann ";
    return;
      
  }
    
  if( language == germanString() ){

    ofs << "wenn " << condition_name << ", dann ";
    return;
      
  }

  ERR_IMPUT( language );
  return;

}


void InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style )
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

void InputPutConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_cond , const string& variable_name , string& language , const string& style )
{

  bool complicated = false;
  string b = ConditionToString( itr_cond , complicated , language , style );

  if( complicated ){

    PutWrap( b , language );
    
  }

  InputPutConditionLine_Body( ofs , b , variable_name , language , style );
  return;
  
}

void InputPutConditionLine_Body( ofstream& ofs , const string& b , const string& variable_name , string& language , const string& style )
{

  if( language == JapaneseString() ){

    if( style == FandomString() ){
    
      ofs << "条件" << b << "を\\(" << variable_name << "\\)と置く。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == EnglishString() ){

    if( style == FandomString() ){

      ofs << "Abbreviate the condition " << b << " to \\(" << variable_name << "\\)." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){

      ofs << "abbreviate the condition " << b << " to \\(" << variable_name << "\\)." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == ChineseString() ){

    if( style == FandomString() ){

      ofs << "令" << b << "為條件\\(" << variable_name << "\\)。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == FrenchString() ){

    if( style == FandomString() ){

      ofs << "Abr\\'eger la condition " << b << " \\`a \\(" << variable_name << "\\)." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){

      ofs << "abr\\'eger la condition " << b << " \\`a \\(" << variable_name << "\\)." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == GermanString() ){

    if( style == FandomString() ){

      ofs << "K\\\"urzen Sie die Bedingung " << b << " auf \\(" << variable_name << "\\) ab." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){

      ofs << "k\\\"urzen Sie die Bedingung " << b << " auf \\(" << variable_name << "\\) ab." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  ERR_IMPUT( language );
  return;

}

void InputPutNonConditionLine_Body( ofstream& ofs , const string& e , const string& variable_name , const string& variable_type_name , string& language , const string& style )
{

  if( language == JapaneseString() ){

    if( style == FandomString() ){

      ofs << "\\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)と置く。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == EnglishString() ){

    if( style == FandomString() ){

      ofs << "Put \\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)." << endl;
      return;

    }
    
    ERR_IMPUT( style );

  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){

      ofs << "put \\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)." << endl;
      return;

    }
    
    ERR_IMPUT( style );

  }

  if( language == ChineseString() ){

    if( style == FandomString() ){

      ofs << "令\\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == FrenchString() ){

    if( style == FandomString() ){

      ofs << "Pose \\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)." << endl;
      return;

    }
    
    ERR_IMPUT( style );

  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){

      ofs << "pose \\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == GermanString() ){

    if( style == FandomString() ){

      ofs << "Definieren \\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){

      ofs << "definieren \\(" << variable_name << " := " << e << " \\in " << variable_type_name << "\\)." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  ERR_IMPUT( language );
  return;
  
}

void InputCharacterisationLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style )
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

void InputUniqueExistenceLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style )
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

void InputUniqueExistenceNaturalNumberLine( ofstream& ofs , const string& local_variable , const string& bound , const string& condition , const string& variable_name , const string& variable_type_name , string& language , const string& style )
{
  
  if( language == JapaneseString() ){

    if( style == FandomString() ){

      ofs << condition << "を満たす\\(" << bound << "\\)以下の一意な\\(" << local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == EnglishString() ){

    if( style == FandomString() ){

      ofs << "Denote by \\(" << variable_name << "\\) the unique \\(" << local_variable << " \\in " << variable_type_name << "\\) smaller than or equal to \\(" << bound << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){

      ofs << "denote by \\(" << variable_name << "\\) the unique \\(" << local_variable << " \\in " << variable_type_name << "\\) smaller than or equal to \\(" << bound << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == ChineseString() ){

    if( style == FandomString() ){

      ofs << "定義\\(" << variable_name << "\\)是小於或等於\\(" << bound << "\\)且滿足條件" << condition << "的唯一\\(" << local_variable << " \\in " << variable_type_name << "\\)。" << endl;
      return;
    
    }

    ERR_IMPUT( style );

  }

  if( language == FrenchString() ){

    if( style == FandomString() ){

      ofs << "Notons \\(" << variable_name << "\\) l'unique \\(" << local_variable << " \\in " << variable_type_name << "\\) inf\\'erieur ou \\'egal \\`a \\(" << bound << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){

      ofs << "notons \\(" << variable_name << "\\) l'unique \\(" << local_variable << " \\in " << variable_type_name << "\\) inf\\'erieur ou \\'egal \\`a \\(" << bound << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == GermanString() ){

    if( style == FandomString() ){

      ofs << "Bezeichne mit \\(" << variable_name << "\\) die Einheit \\(" << local_variable << " \\in " << variable_type_name << "\\) kleiner oder gleich \\(" << bound << "\\), das " << condition << " erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){

      ofs << "bezeichne mit \\(" << variable_name << "\\) die Einheit \\(" << local_variable << " \\in " << variable_type_name << "\\) kleiner oder gleich \\(" << bound << "\\), das " << condition << " erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  ERR_IMPUT( language );
  return;
  
}

void InputUniqueExistenceStringLine( ofstream& ofs , const string& local_variable , const string& bound , const string& condition , const string& variable_name , const string& variable_type_name , string& language , const string& style )
{

  if( language == JapaneseString() ){

    if( style == FandomString() ){

      ofs << condition << "を満たす\\(" << bound << "\\)の一意な部分文字列\\(" << local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == EnglishString() ){

    if( style == FandomString() ){

      ofs << "Denote by \\(" << variable_name << "\\) the unique substring \\(" << local_variable << " \\in " << variable_type_name << "\\) of \\(" << bound << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){

      ofs << "denote by \\(" << variable_name << "\\) the unique substring \\(" << local_variable << " \\in " << variable_type_name << "\\) of \\(" << bound << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == ChineseString() ){

    if( style == FandomString() ){

      ofs << "定義\\(" << variable_name << "\\)是滿足條件" << condition << "的\\(" << bound << "\\)的唯一子串\\(" << local_variable << " \\in " << variable_type_name << "\\)。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == FrenchString() ){

    if( style == FandomString() ){

      ofs << "Notons \\(" << variable_name << "\\) la sous-cha\\^ine unique \\(" << local_variable << " \\in " << variable_type_name << "\\) sup\\'erieur ou \\'egal \\`a \\(" << bound << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){

      ofs << "notons \\(" << variable_name << "\\) la sous-cha\\^ine unique \\(" << local_variable << " \\in " << variable_type_name << "\\) sup\\'erieur ou \\'egal \\`a \\(" << bound << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == GermanString() ){

    if( style == FandomString() ){

      ofs << "Bezeichne mit \\(" << variable_name << "\\) den eindeutigen Teilstring \\(" << local_variable << " \\in " << variable_type_name << "\\) von \\(" << bound << "\\), das " << condition << " erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){

      ofs << "bezeichne mit \\(" << variable_name << "\\) den eindeutigen Teilstring \\(" << local_variable << " \\in " << variable_type_name << "\\) von \\(" << bound << "\\), das " << condition << " erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  ERR_IMPUT( language );
  return;
  
}

void InputMinimumLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style )
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

     InputMinimumLine_Body( ofs , ConditionToString( itr_line , complicated , language , style ) , *p_local_variable , variable_name , variable_type_name , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  return;

}

void InputMinimumLine_Body( ofstream& ofs , const string& condition , const string& local_variable , const string& variable_name , const string& variable_type_name , string& language , const string& style )
{
    
  if( language == JapaneseString() ){

    if( style == FandomString() ){

      ofs << condition << "を満たす最小の\\(" << local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == EnglishString() ){

    if( style == FandomString() ){

      ofs << "Denote by \\(" << variable_name << "\\) the smallest \\(" << local_variable << " \\in " << variable_type_name << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){

      ofs << "denote by \\(" << variable_name << "\\) the smallest \\(" << local_variable << " \\in " << variable_type_name << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == ChineseString() ){

    if( style == FandomString() ){

      ofs << "定義\\(" << variable_name << "\\)是滿足條件" << condition << "的最小的\\(" << local_variable << " \\in " << variable_type_name << "\\)。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == FrenchString() ){

    if( style == FandomString() ){

      ofs << "Notons \\(" << variable_name << "\\) le moins \\(" << local_variable << " \\in " << variable_type_name << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){

      ofs << "notons \\(" << variable_name << "\\) le moins \\(" << local_variable << " \\in " << variable_type_name << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == GermanString() ){

    if( style == FandomString() ){

      ofs << "Bezeichne mit \\(" << variable_name << "\\) das kleinste \\(" << local_variable << " \\in " << variable_type_name << "\\), das " << condition << " erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){

      ofs << "bezeichne mit \\(" << variable_name << "\\) das kleinste \\(" << local_variable << " \\in " << variable_type_name << "\\), das " << condition << " erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  ERR_IMPUT( language );
  return;

}

void InputMaximumLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style )
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

     p_bound = &( ExpressionToString( itr_line ) ) ,
     const ErrorType& e ,
     CALL( e )

     );

  TRY_CATCH
    (

     InputMaximumLine_Body( ofs , ConditionToString( itr_line , complicated , language , style ) , *p_local_variable , *p_bound , variable_name , variable_type_name , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );
  
  return;

}

void InputMaximumLine_Body( ofstream& ofs , const string& condition , const string& bound , const string& local_variable , const string& variable_name , const string& variable_type_name , string& language , const string& style )
{

  if( language == JapaneseString() ){

    if( style == FandomString() ){

      ofs << condition << "を満たす\\(" << bound << "\\)以下の最大の\\(" << local_variable << " \\in " << variable_type_name << "\\)を\\(" << variable_name << "\\)と置く。" << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == EnglishString() ){

    if( style == FandomString() ){

      ofs << "Denote by \\(" << variable_name << "\\) the greatest \\(" << local_variable << " \\in " << variable_type_name << "\\) smaller than or equal to \\(" << bound << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){

      ofs << "denote by \\(" << variable_name << "\\) the greatest \\(" << local_variable << " \\in " << variable_type_name << "\\) smallest than or equal to \\(" << bound << "\\) satisfying " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == ChineseString() ){

    if( style == FandomString() ){

      ofs << "定義\\(" << variable_name << "\\)是小於或等於\\(" << bound << "\\)且滿足條件" << condition << "的最大的\\(" << local_variable << " \\in " << variable_type_name << "\\)。" << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == FrenchString() ){

    if( style == FandomString() ){

      ofs << "Notons \\(" << variable_name << "\\) le plus grand \\(" << local_variable << " \\in " << variable_type_name << "\\) inf\\'erieur ou \\'egal \\`a \\(" << bound << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){

      ofs << "notons \\(" << variable_name << "\\) le plus grand \\(" << local_variable << " \\in " << variable_type_name << "\\) inf\\'erieur ou \\'egal \\`a \\(" << bound << "\\) satisfaisant " << condition << "." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == GermanString() ){

    if( style == FandomString() ){

      ofs << "Bezeichne mit \\(" << variable_name << "\\) das gr\\\"o{\\ss}te \\(" << local_variable << " \\in " << variable_type_name << "\\) Y, das kleiner oder gleich \\(" << bound << "\\) ist und " << condition << "erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){

      ofs << "bezeichne mit \\(" << variable_name << "\\) das gr\\\"o{\\ss}te \\(" << local_variable << " \\in " << variable_type_name << "\\) Y, das kleiner oder gleich \\(" << bound << "\\) ist und " << condition << "erf\\\"ullt." << endl;
      return;

    }

    ERR_IMPUT( style );
    
  }

  ERR_IMPUT( language );
  return;
  
}

void InputPrintLine_Body( ofstream& ofs , const string& variable_name , string& language , const string& style )
{

  if( language == JapaneseString() ){

    if( style == FandomString() ){

      ofs << "\\(" << variable_name << "\\)の標準出力を行う。この操作は計算結果に影響を与えない。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == EnglishString() ){

    if( style == FandomString() ){

      ofs << "Stdout \\(" << variable_name << "\\). This line does not affect the result of the computation." << endl;
      return;

    }

    ERR_IMPUT( style );
      
  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){

      ofs << "stdout \\(" << variable_name << "\\). This line does not affect the result of the computation." << endl;
      return;

    }

    ERR_IMPUT( style );
      
  }

  if( language == ChineseString() ){

    if( style == FandomString() ){

      ofs << "標準輸出\\(" << variable_name << "\\)。這行不影響計算結果。" << endl;
      return;

    }

    ERR_IMPUT( style );
      
  }

  if( language == FrenchString() ){

    if( style == FandomString() ){

      ofs << "Stdout \\(" << variable_name << "\\). Cette ligne n'affecte pas le r\\'esultat du calcul." << endl;
      return;

    }

    ERR_IMPUT( style );
      
  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){

      ofs << "stdout \\(" << variable_name << "\\). Cette ligne n'affecte pas le r\\'esultat du calcul." << endl;
      return;

    }

    ERR_IMPUT( style );
      
  }

  if( language == GermanString() ){

    if( style == FandomString() ){

      ofs << "Stdout \\(" << variable_name << "\\). Diese Zeile hat keinen Einfluss auf das Ergebnis der Berechnung." << endl;
      return;

    }

    ERR_IMPUT( style );
      
  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){

      ofs << "stdout \\(" << variable_name << "\\). Diese Zeile hat keinen Einfluss auf das Ergebnis der Berechnung." << endl;
      return;

    }

    ERR_IMPUT( style );
      
  }

  ERR_IMPUT( language );
  return;

}

void InputExitLine( ofstream& ofs , const string& function_expression_name , string& language , const string& style )
{

  if( language == JapaneseString() ){

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\)は未定義である。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == EnglishString() ){

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\) is undefined." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == englishString() ){

    language = EnglishString();

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\) is undefined." << endl;
      return;
    
    }

    ERR_IMPUT( style );

  }

  if( language == ChineseString() ){

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\)未定義。" << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == FrenchString() ){

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\) n'est pas d\\'efini." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == frenchString() ){

    language = FrenchString();

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\) n'est pas d\\'efini." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == GermanString() ){

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\) ist undefiniert." << endl;
      return;

    }

    ERR_IMPUT( style );

  }

  if( language == germanString() ){

    language = GermanString();

    if( style == FandomString() ){
    
      ofs << "\\(" << function_expression_name << "\\) ist undefiniert." << endl;
      return;
    
    }

    ERR_IMPUT( style );

  }

  ERR_IMPUT( language );
  return;

}

void InputReturnLine_Body( ofstream& ofs , const string& function_expression_name , const string& return_name , string& language , const string& style )
{

  string return_expression = function_expression_name + " := " + return_name;

  TRY_CATCH
    (

     PutMathJax( return_expression , style ) ,
     const ErrorType& e ,
     CALL_P( e , return_expression )

     );

  if( language == JapaneseString() ){

    ofs << return_expression << "と定める。" << endl;
    return;

  }

  if( language == EnglishString() ){

    ofs << "Set " << return_expression << "." << endl;
    return;

  }

  if( language == englishString() ){

    language = EnglishString();
    ofs << "set " << return_expression << "." << endl;
    return;

  }

  if( language == ChineseString() ){

    ofs << "定義" << return_expression << "。" << endl;
    return;

  }

  if( language == FrenchString() ){

    ofs << "D\\'efinissez " << return_expression << "." << endl;
    return;

  }

  if( language == frenchString() ){

    ofs << "d\\'efinissez " << return_expression << "." << endl;
    language = FrenchString();
    return;

  }

  if( language == GermanString() ){

    ofs << "Definiere " << return_expression << "." << endl;
    return;

  }

  if( language == germanString() ){

    language = GermanString();
    ofs << "definiere " << return_expression << "." << endl;
    return;

  }

  ERR_IMPUT( language );
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

    string b;

    TRY_CATCH
      (

       b = *itr_copy ,
       const ErrorType& e ,
       CALL( e )

       );

    PutMathJax( b , style );
    return b;

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
  
  TRY_CATCH
    (

     {
       
       bool complicated = false;
       string b = ConditionToString( itr , complicated , language , style );
       
       if( complicated ){

	 PutWrap( b , language );
    
       }

       return NegationToString_Body( b , language , style );

     } ,
     
     const ErrorType& e ,
     
     CALL( e )

     );

  ERR_CODE;
  return "dummy";
  
}

string NegationToString_Body( const string& b , string& language , const string& style )
{

  if( language == JapaneseString() ){

    return b + "でない";

  }

  if( language == EnglishString() ){

    return b + " does not hold";
      
  }

  if( language == ChineseString() ){

    return b + "不成立";
      
  }

  if( language == FrenchString() ){

    return b + " ne tient pas";
      
  }

  if( language == GermanString() ){

    return b + " gilt nicht";
      
  }

  ERR_IMPUT( b , language );
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

  if( complicated0 ){

    PutWrap( b0 , language );
    
  }

  if( complicated1 ){

    PutWrap( b1 , language );
    
  }

  TRY_CATCH
    (
     
     return ImplicationToString_Body( b0 , b1 , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  ERR_CODE;
  return "dummy";

}

string ImplicationToString_Body( const string& b0 , const string& b1 , string& language , const string& style )
{

  if( language == JapaneseString() ){

    return b0 + "ならば" + b1;

  }

  if( language == EnglishString() ){

    return b0 + " implies " + b1;
      
  }


  if( language == ChineseString() ){

    return "若" + b0 + "則" + b1;

  }

  if( language == FrenchString() ){

    return "si " + b0 + " alors " + b1;
      
  }

  if( language == GermanString() ){

    return "wenn " + b0 + " dann " + b1;
      
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

  if( complicated0 ){

    PutWrap( b0 , language );
    
  }

  if( complicated1 ){

    PutWrap( b1 , language );
    
  }

  TRY_CATCH
    (

     return EquivalenceToString_Body( b0 , b1 , language , style ) ,
     const ErrorType& e ,
     CALL( e )

     );

  ERR_CODE;
  return "dummy";

}

string EquivalenceToString_Body( const string& b0 , const string& b1 , string& language , const string& style )
{

  if( language == JapaneseString() ){

    return b0 + "と" + b1 + "が同値である";

  }

  if( language == EnglishString() ){

    return b0 + " is equivalent to " + b1;
      
  }

  if( language == ChineseString() ){

    return b0 + "和" + b1 + "彼此等价";

  }

  if( language == FrenchString() ){

    return b0 + " est \\'equivalent \\`a " + b1;
      
  }

  if( language == GermanString() ){

    return b0 + " ist \\\"aquivalent zu " + b1;
      
  }

  ERR_IMPUT( b0 , b1 , language );
  return "dummy";

}

string LogicalConnectiveToString( VLTree<string>::const_iterator& itr , const string& connective , string& language , const string& style )
{

  string b = "";
  bool first = true;
  bool second = false;

  TRY_CATCH
    (

     {
	 
       while( itr.IsValid() ){

	 bool complicated = false;
	 string b_current = ConditionToString( itr , complicated , language , style );
	   
	 if( first ){

	   first = false;
	   second = true;

	   if( complicated && itr.IsValid() ){

	     PutWrap( b_current , language );

	   }

	 } else {
	     
	   if( complicated ){

	     PutWrap( b_current , language );

	   }

	   AddCommaForLogicalConnective( b , connective , second , itr , language , style );

	 }

	 b += b_current;

       }

     } ,

     const ErrorType& e ,
     
     CALL( e )

     );

  return b;

}

void AddCommaForLogicalConnective( string& b , const string& connective ,  bool& second , const VLTree<string>::const_iterator& itr , string& language , const string& style )
{

  if( language == JapaneseString() ){

    b += LogicalConnectiveSymbolToString( connective , language , style );
    return;

  }
  
  if( language == EnglishString() ){

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

      b += LogicalConnectiveSymbolToString( connective , language , style );

    }

    return;

  }

  if( language == ChineseString() ){

    if( itr.IsValid() ){

      b += ", ";

    } else {

      b += LogicalConnectiveSymbolToString( connective , language , style );

    }

    return;

  }

  if( language == FrenchString() ){

    if( itr.IsValid() ){

      b += ", ";

    } else {

      b += LogicalConnectiveSymbolToString( connective , language , style );

    }

    return;

  }

  if( language == GermanString() ){

    if( itr.IsValid() ){

      b += ", ";

    } else {

      b += LogicalConnectiveSymbolToString( connective , language , style );

    }

    return;

  }

  ERR_IMPUT( b , language );
  return;

}

string LogicalConnectiveSymbolToString( const string& connective , string& language , const string& style )
{

  if( language == JapaneseString() ){

    if( connective == LandString() ){
      
      return "かつ";

    }

    if( connective == LorString() ){
      
      return "または";

    }

    ERR_IMPUT( connective );

  }

  if( language == EnglishString() ){

    if( connective == LandString() ){
      
      return "and ";

    }

    if( connective == LorString() ){
      
      return "or ";

    }

    ERR_IMPUT( connective );

  }

  if( language == ChineseString() ){

    if( connective == LandString() ){
      
      return "和";

    }

    if( connective == LorString() ){
      
      return "或";

    }

    ERR_IMPUT( connective );

  }

  if( language == FrenchString() ){

    if( connective == LandString() ){
      
      return " et ";

    }

    if( connective == LorString() ){
      
      return " ou ";

    }

    ERR_IMPUT( connective );

  }

  if( language == GermanString() ){

    if( connective == LandString() ){
      
      return " und ";

    }

    if( connective == LorString() ){
      
      return " oder ";

    }

    ERR_IMPUT( connective );

  }

  ERR_IMPUT( language );
  return "dummy";

}

void PutMathJax( string& s , const string& style )
{

  if( style == FandomString() ){

    PutFandomMathJax( s );
    return;

  }

  ERR_IMPUT( style );
  return;

}

void PutWrap( string& s , const string& language )
{

  if( language == JapaneseString() ){

    PutKagi( s );
    return;

  }

  if( language == EnglishString() ){

    PutParenthesis( s );
    return;

  }

  if( language == englishString() ){

    PutParenthesis( s );
    return;

  }

  if( language == ChineseString() ){

    PutKagi( s );
    return;

  }

  if( language == FrenchString() ){

    PutParenthesis( s );
    return;

  }

  if( language == frenchString() ){

    PutParenthesis( s );
    return;

  }

  if( language == GermanString() ){

    PutParenthesis( s );
    return;

  }

  if( language == germanString() ){

    PutParenthesis( s );
    return;

  }
  
  ERR_IMPUT( s , language );
  return;
  
}
