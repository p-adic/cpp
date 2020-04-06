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
  
  template <typename... Rets>
  using Dummy = typename enable_if<IsValidListOfLines<Ret,Rets...>::value,int>::type;

  
public:  
  inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<void>& line );
  inline LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction<Ret>& line ) = default;
  template <typename... Rets> inline LineOfDefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines );

  // IF
  inline LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const LineOfDefinitionOfComputableFunction<Ret>& line );
  template <typename Ret1 , typename Ret2 , typename... Rets> inline LineOfDefinitionOfComputableFunction( const Dummy<Ret1,Ret2,Rets...>& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const Rets&... lines );

  // RETURN
  inline LineOfDefinitionOfComputableFunction( const ExpressionOfComputableFunction<Ret>& ret );

};

// deduction guide
template <typename Ret1 , typename Ret2 , typename... Rets> LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const Rets&... lines ) -> LineOfDefinitionOfComputableFunction<typename CheckNonVoidTypeInLine<Ret1,Ret2,Rets...>::type>;


template <typename... Rets> inline auto IfLine( const ConditionOfComputableFunction& condition , const Rets&... lines ) -> typename enable_if< less_equal<uint>()( 1 , sizeof...( Rets ) ) && IsValidListOfLines<typename CheckNonVoidTypeInLine<Rets...>::type,Rets...>::value , LineOfDefinitionOfComputableFunction<typename CheckNonVoidTypeInLine<Rets...>::type> >::type;

template <typename Ret> inline LineOfDefinitionOfComputableFunction<Ret> ReturnLine( const ExpressionOfComputableFunction<Ret>& ret );

