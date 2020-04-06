// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a.hpp

#pragma once
#include "Line/Void/a.hpp"

template <typename Ret, typename... Args>
class DefinitionOfComputableFunction :
  public SyntaxOfComputableFunction
{

public:
  template <typename... Rets>
  using Dummy = typename enable_if<IsValidListOfLines<Ret,Rets...>::value,int>::type;

public:
  // decltype—p 
  inline DefinitionOfComputableFunction( const FunctionSymbol<Ret,Args...>& f );

  template <typename... Rets> inline DefinitionOfComputableFunction( const Rets&... lines );
  inline DefinitionOfComputableFunction( const int& dummy , const LineOfDefinitionOfComputableFunction<Ret>& line );
  template <typename... Rets> inline DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines );

  inline const string& Name() const;
  inline void Display( const FunctionSymbol<Ret,Args...>& f , const char* const & filename ) const noexcept;
  void Display( const FunctionSymbol<Ret,Args...>& f , const string& filename = "a.txt" ) const noexcept;

};

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Definition );
