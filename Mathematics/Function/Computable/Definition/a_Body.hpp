// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "Line/Void/a_Body.hpp"

template <typename Ret, typename... Args> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const int& dummy , const FunctionSymbol<Ret,Args...>& f , const LineOfDefinitionOfComputableFunction<Ret>& line ) : SyntaxOfComputableFunction( "" , "definition" , f.Get() , line.Get() ) {}

template <typename Ret, typename... Args> template <typename... Rets> inline DefinitionOfComputableFunction<Ret,Args...>::DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const FunctionSymbol<Ret,Args...>& f , const Rets&... lines ) : DefinitionOfComputableFunction( dummy , f , LineOfDefinitionOfComputableFunction<Ret>( dummy , lines... ) ) {}

template <typename Ret, typename... Args> inline const string& DefinitionOfComputableFunction<Ret,Args...>::Name() const { return *( Get().LeftMostLeaf() ); }

template <typename Ret, typename... Args>
void DefinitionOfComputableFunction<Ret,Args...>::Display() const noexcept
{

  string filename = "a.txt";
  ofstream ofs( filename , ios::trunc );

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

    InputDefinition( ofs );

  }
  catch( const ErrorType& e ){

    IGNORED_ERR( e );

  }
  
  cout << "………" << endl;
  cout << "書き込みが終了しました。" << endl;
  return;

}
