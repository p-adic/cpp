// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a.hpp

#pragma once

#include "a_Macro.hpp"

#include "../Expression/Condition/a.hpp"
#include "../Expression/Variable/Variadic/a.hpp"
#include "../Separator/a.hpp"
#include "../Type/Base/a.hpp"
#include "../Type/Basic/a.hpp"
#include "../Type/SubType/a.hpp"


template <typename Ret, typename... Args>
class FunctionSymbol :
  public SyntaxOfComputableFunction
{

public:
  inline FunctionSymbol( const string& f , const TypeNameOfComputableFunction& return_type_name , const VariableSymbol<Args>&... args );
  FunctionSymbol( const string& f , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& return_type_name , const VariableSymbol<Args>&... args );

  void SetSeparator( const SeparatorOfComputableFunction& s );
  template <typename... VA> inline auto SetSeparator( const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type;

  inline ExpressionOfComputableFunction<Ret> operator()( const ExpressionOfComputableFunction<Args>&... args ) const;

};


template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL( Ret , Minus );
template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL( Ret , Slash );
template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL( Ret , Mod );
template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL( Ret , Power );

template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Minus );
template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Slash );
template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Mod );
template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Power );


inline const FunctionSymbol<bool,bool>& NegSymbol();
DECLARATION_OF_LOGICAL_CONNECTIVE( To );
DECLARATION_OF_LOGICAL_CONNECTIVE( Equiv );

ConditionOfComputableFunction NegSymbolApplication( const ConditionOfComputableFunction& b );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Ot );
DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );

inline const FunctionSymbol<string,string,int>& EntryAccessSymbol();


