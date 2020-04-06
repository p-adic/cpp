// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "Line/Void/a_Body.hpp"

template <typename Ret, typename... Args> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const FunctionSymbol<Ret,Args...>& f ) : DefinitionOfComputableFunction( 0 ) {}

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Rets&... lines ) : DefinitionOfComputableFunction( 0 , lines... ) {}

template <typename Ret, typename... Args> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const int& dummy , const LineOfDefinitionOfComputableFunction<Ret>& line ) : SyntaxOfComputableFunction( EmptyString() , DefinitionString() , line.Get() ) {}

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines ) : DefinitionOfComputableFunction( dummy , LineOfDefinitionOfComputableFunction<Ret>( dummy , lines... ) ) {}

template <typename Ret, typename... Args> inline const string& DefinitionOfComputableFunction<Ret,Args...>::Name() const { return *( Get().LeftMostLeaf() ); }

template <typename Ret, typename... Args> inline void DefinitionOfComputableFunction<Ret,Args...>::Display( const FunctionSymbol<Ret,Args...>& f , const char* const & filename ) const noexcept { Display( f , to_string( filename ) ); }

template <typename Ret, typename... Args>
void DefinitionOfComputableFunction<Ret,Args...>::Display( const FunctionSymbol<Ret,Args...>& f , const string& filename ) const noexcept
{

  ofstream ofs( filename , ios::trunc );

  cout << "宣言文の木構造を出力します：" << endl;
  cout << f.Display() << endl;
  cout << endl;
  cout << "定義文の木構造を出力します：" << endl;
  cout << Get().Display() << endl;
  cout << endl;
  cout << "定義文の日本語訳を" << filename << "に書き込みます：" << endl;
  cout << "…" << endl;
  
  if( !ofs ){
    cout << "ファイルが開けませんでした。" << endl;
    cin.get();
    return;
  }

  cout << "……" << endl;

  try{

    InputDefinition( ofs , f );

  }
  catch( const ErrorType& e ){

    IGNORED_ERR( e );

  }
  
  cout << "………" << endl;
  cout << "書き込みが終了しました。" << endl;
  return;

}

DEFINITION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Definition , definition );
