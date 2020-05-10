// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

#include "../Syntax/a_Body.hpp"

void TypeOfComputableFunction::WriteTo( const TypeOfComputableFunction& dummy , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept
{

  if( &dummy != this ){

    ERR_CODE;

  }
  
  ofstream ofs( filename , open_mode );

  try{
    
    DisplayWritingTranslationOfDefinition( m_type_name , filename , language );
    cout << "…" << endl;
  
    if( !ofs ){

      DisplayFileOpenError( language );
      cin.get();
      return;

    }

    cout << "……" << endl;

    InputDefinition( ofs , language , style );
    ofs << endl;

    cout << "………" << endl;
    DisplayFinishedWriting( language );

  }
  catch( const ErrorType& e ){

    IGNORED_ERR( e );

  }

  return;

}


void TypeOfComputableFunction::InputDefinition( ofstream& ofs , const string& language , const string& style ) const noexcept
{

  try{

    if( m_construction == ArrayString() ){

      InputDefinitionOfArraySet( ofs , m_type_name , m_description , language , style );
      return;

    }
  
    if( m_construction == NestedArrayString() ){

      InputDefinitionOfNestedArraySet( ofs , m_type_name , m_description , language , style );
      return;

    }

    InputDefinitionOfRecursiveSet( ofs , m_type_name , m_description , language , style );
    return;

  }
  catch( const ErrorType& e ){

    IGNORED_ERR( e );

  };

}
