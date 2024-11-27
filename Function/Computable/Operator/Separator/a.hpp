// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Separator/a.hpp

#pragma once
#include "../../Syntax/a.hpp"

class SeparatorOfComputableFunction :
  public SyntaxOfComputableFunction
{

public:
  template <typename... Args>
  using Dummy = typename enable_if<conjunction<is_same<string,Args>...>::value,int>::type;
  
public:
  inline SeparatorOfComputableFunction( const string& f , const uint& arity , const bool& variadic = false );
  template <typename... Args> inline SeparatorOfComputableFunction( const Dummy<Args...>& dummy , const Args&... args );

};
