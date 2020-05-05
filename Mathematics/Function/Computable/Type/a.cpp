// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

#include "../Syntax/a_Body.hpp"

void TypeOfComputableFunction::WriteOn( const TypeOfComputableFunction& dummy , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept
{

  if( &dummy != this ){

    ERR_CODE;

  }
  
  ofstream ofs( filename , open_mode );

  if( language == JapaneseString() ){

    cout << " " << m_type_name << " の定義文の日本語訳を" << filename << "に書き込みます：" << endl;
    cout << "…" << endl;
  
    if( !ofs ){
      cout << "ファイルが開けませんでした。" << endl;
      cin.get();
      return;
    }

    cout << "……" << endl;

    try{

      InputDefinition( ofs , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "………" << endl;
    cout << "書き込みが終了しました。" << endl;
    return;

  }

  if( language == EnglishString() ){

    cout << "Writing an English translation of the definition of \\(" << m_type_name << "\\) on " << filename << ":" << endl;
    cout << "…" << endl;
  
    if( !ofs ){
      cout << "Error: Cannot open the file." << endl;
      cin.get();
      return;
    }

    cout << "……" << endl;

    try{

      InputDefinition( ofs , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "………" << endl;
    cout << "Finished writing." << endl;

    return;

  }

  if( language == ChineseString() ){

    cout << "在" << filename << "上寫" << m_type_name << "的定義的中文翻譯:" << endl;
    cout << "…" << endl;
  
    if( !ofs ){
      cout << "錯誤：無法打開文件。" << endl;
      cin.get();
      return;
    }

    cout << "……" << endl;

    try{

      InputDefinition( ofs , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "………" << endl;
    cout << "寫完了。" << endl;

    return;

  }

  if( language == FrenchString() ){

    cout << "\\'Ecrire une traduction en anglais de la d\\'efinition de \\(" << m_type_name << "\\) sur " << filename << ":" << endl;
    cout << "…" << endl;
  
    if( !ofs ){
      cout << "Erreur: impossible d'ouvrir le fichier." << endl;
      cin.get();
      return;
    }

    cout << "……" << endl;

    try{

      InputDefinition( ofs , language , style );

    }
    catch( const ErrorType& e ){

      IGNORED_ERR( e );

    }
  
    ofs << endl;

    cout << "………" << endl;
    cout << "\\'Ecriture termin\\'ee." << endl;

    return;

  }

  ERR_IMPUT( language );
  return;

}

void TypeOfComputableFunction::InputDefinition( ofstream& ofs , const string& language , const string& style ) const noexcept
{

  if( language == JapaneseString() && style == FandomString() ){

    ofs << "再帰的集合\\(" << m_type_name << "\\)を\\(" << m_definition << "\\)と定める。" << endl;
    return;

  }

  if( language == EnglishString() && style == FandomString() ){

    ofs << "I define a recursive set \\(" << m_type_name << "\\) as \\(" << m_definition << "\\)." << endl;
    return;

  }

  if( language == ChineseString() && style == FandomString() ){

    ofs << "我將遞歸集合\\(" << m_type_name << "\\)定義為\\(" << m_definition << "\\)。" << endl;
    return;

  }

  if( language == FrenchString() && style == FandomString() ){

    ofs << "Je d\\'efinis un ensemble r\\'ecursif \\(" << m_type_name << "\\) comme \\(" << m_definition << "\\)." << endl;
    return;

  }

  ERR_IMPUT( language , style );
  return;

}
