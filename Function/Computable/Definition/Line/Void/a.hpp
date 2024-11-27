// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Void/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../../Utility/WrappedType/a.hpp"

template <>
class LineOfDefinitionOfComputableFunction<void> :
  public SyntaxOfComputableFunction
{

public:
  using type = void;

  template <typename... Rets>
  using Dummy = typename enable_if<IsValidListOfLines<void,Rets...>::value,int>::type;


public:
  inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line ) = default;
  template <typename... Rets> inline LineOfDefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines );


  // PUT
  template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction( const VariableSymbol<T1>& x , const T2& t );
  template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction( const VariableSymbol<T1>& x , const string& characterisation , const VariableSymbol<T2>& n , const VariableSymbol<T2>& bound , const ConditionOfComputableFunction& b );
  
  // PRINT
  template <typename... ARGS> inline LineOfDefinitionOfComputableFunction( const ListExpressionOfComputableFunction<ARGS...>& args );

  // IF
  inline LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const LineOfDefinitionOfComputableFunction<void>& line );
  template <typename Ret1 , typename Ret2 , typename... Rets> inline LineOfDefinitionOfComputableFunction( const Dummy<Ret1,Ret2,Rets...>& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const Rets&... lines );

  // EXIT
  inline LineOfDefinitionOfComputableFunction();
  
};

template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void> PutLineOfComputableFunction( const VariableSymbol<T1>& x , const T2& t );
template <typename T1, typename T2> inline LineOfDefinitionOfComputableFunction<void> PutLineOfComputableFunction( const VariableSymbol<T1>& x , const string& characterisation , const WrappedType<VariableSymbol<T2> >& n , const WrappedType<VariableSymbol<T2> >& bound , const WrappedType<ConditionOfComputableFunction>& b );

template <typename... ARGS> inline LineOfDefinitionOfComputableFunction<void> PrintLineOfComputableFunction( const ARGS&... args );

