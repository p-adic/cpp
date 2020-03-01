// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Separator/a.hpp

#pragma once
#include "../Syntax/a.hpp"

class SeparatorOfComputableFunction :
  public SyntaxOfComputableFunction
{

public:
  template <typename... Args>
  using Dummy = typename enable_if<conjunction<is_same<string,Args>...>::value,int>::type;
  
public:
  inline SeparatorOfComputableFunction( const string& f , const uint& arity );
  template <typename... Args> inline SeparatorOfComputableFunction( const Dummy<Args...>& dummy , const Args&... args );

};

DECLARATION_OF_GLOBAL_CONSTANT_STRING_FOR_SYMBOL( Separator );
