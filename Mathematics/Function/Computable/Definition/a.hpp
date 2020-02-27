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
  inline DefinitionOfComputableFunction( const int& dummy , const FunctionSymbol<Ret,Args...>& f , const LineOfDefinitionOfComputableFunction<Ret>& line );
  template <typename... Rets> inline DefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const FunctionSymbol<Ret,Args...>& f , const Rets&... lines );

  inline const string& Name() const;
  void Display() const noexcept;

};
