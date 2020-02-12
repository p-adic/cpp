// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Guide/a.hpp"
#include "../../Function/Variadic/a.hpp"
#include "../../Relation/Variadic/a.hpp"
#include "../../Expression/Condition/a.hpp"

template <typename Ret>
class LineOfDefinitionOfComputableFunction :
  public SyntaxOfComputableFunction
{

public:
  using type = Ret;
  
  template <typename Ret1 , typename Ret2 , typename... ARGS> using Dummy = typename enable_if<IsSameOrVoidInLine<Ret,Ret1>::value && IsSameOrVoidInLine<Ret,Ret2>::value && conjunction<IsSameOrVoidInLine<Ret,ARGS>...>::value && is_same<Ret,typename CheckNonVoidTypeInLine<Ret1,Ret2,ARGS...>::type>::value ,int>::type;

  
public:
  inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line );
  inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<Ret>& line ) = default;
  template <typename... ARGS> inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<Ret>& line1 , const LineOfDefinitionOfComputableFunction<Ret>& line2 , const LineOfDefinitionOfComputableFunction<ARGS>&... args );

  // IF
  inline LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const LineOfDefinitionOfComputableFunction<Ret>& line );
  template <typename Ret1 , typename Ret2 , typename... ARGS> inline LineOfDefinitionOfComputableFunction( const Dummy<Ret1,Ret2,ARGS...>& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const ARGS&... lines );

  // RETURN
  inline LineOfDefinitionOfComputableFunction( const ExpressionOfComputableFunction<Ret>& ret );

};

// deduction guide
template <typename Ret1 , typename Ret2 , typename... ARGS> LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const ARGS&... lines ) -> LineOfDefinitionOfComputableFunction<typename CheckNonVoidTypeInLine<Ret1,Ret2,ARGS...>::type>;
