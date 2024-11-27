// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "Line/Void/a_Body.hpp"

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Rets&... lines ) : DefinitionOfComputableFunction( 0 , lines... ) {}

template <typename Ret, typename... Args> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const int& dummy , const LineOfDefinitionOfComputableFunction<Ret>& line ) : SyntaxOfComputableFunction( EmptyString() , DefinitionString() , line.Get() ) {}

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines ) : DefinitionOfComputableFunction( dummy , LineOfDefinitionOfComputableFunction<Ret>( dummy , lines... ) ) {}

template <typename Ret, typename... Args> inline const string& DefinitionOfComputableFunction<Ret,Args...>::Name() const { return *( Get().LeftMostLeaf() ); }

template <typename Ret, typename... Args>
void DefinitionOfComputableFunction<Ret,Args...>::WriteTo( const OperatorSymbol<Ret,Args...>& f , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept
{

  ofstream ofs( filename , open_mode );
  auto itr_f = f.Get().LeftMostNode();

  try{

    const string& function_name = SyntaxToString( itr_f , 2 );

    DisplayTreeStructureOfDefinition( function_name , language );
    cout << Get().Display() << endl;
    cout << endl;
    DisplayWritingTranslationOfDefinition( function_name , filename , language );
    cout << "…" << endl;

    if( !ofs ){

      DisplayFileOpenError( language );
      cin.get();
      return;
      
    }

    cout << "……" << endl;

    InputDefinition( ofs , f.GetTotality().Get() , function_name , itr_f , language , style );

  }
  catch( const ErrorType& e ){

    IGNORED_ERR( e );

  }
  
  ofs << endl;

  cout << "………" << endl;
  DisplayFinishedWriting( language );
  return;

}

