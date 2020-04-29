// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Separator/a.hpp"
#include "../../Type/Guide/Base/a.hpp"
#include "../../Type/SubType/a.hpp"

// #include "../../Expression/Primitive/bool/a.hpp"
// #include "../../Expression/Variable/Variadic/a.hpp"

template <typename Arg> class VariableSymbol;

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

#include "a_Alias.hpp"

template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL( Ret , Minus );
template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL( Ret , Slash );
template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL( Ret , Mod );
template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL( Ret , Power );

template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Minus );
template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Slash );
template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Mod );
template <typename Ret> inline DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( Ret , Power );


