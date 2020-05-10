// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Separator/a.hpp"
#include "../Totality/a.hpp"
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
  TotalityOfComputableFunction m_totality;

public:
  inline FunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const TypeNameOfComputableFunction& return_type_name , const VariableSymbol<Args>&... args );
  FunctionSymbol( const TotalityOfComputableFunction& totality , const string& f , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& return_type_name , const VariableSymbol<Args>&... args );
  template <typename... Ts> inline FunctionSymbol( const string& f , const Ts&... ts );

  inline FunctionSymbol( const FunctionSymbol<Ret,Args...>& f );

  inline void Set( const string& dummy , const string& f );
  template <typename... VA> inline auto Set( const SeparatorOfComputableFunction& dummy1 , const int& dummy2 , const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type;
  inline void Set( const TotalityOfComputableFunction& dummy , const TotalityOfComputableFunction& totality ) noexcept;
  
  inline void SetSymbol( const string& f );
  inline void RomaniseSymbol();

  void SetSeparator( const SeparatorOfComputableFunction& s );
  template <typename... VA> inline auto SetSeparator( const VA&... va ) -> typename enable_if<conjunction<is_same<VA,string>...>::value,void>::type;

  inline const TotalityOfComputableFunction& GetTotality() const noexcept;
  inline void SetTotality( const TotalityOfComputableFunction& totality ) noexcept;

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


