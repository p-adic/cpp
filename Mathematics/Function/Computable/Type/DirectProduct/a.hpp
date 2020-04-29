// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/DirectProduct/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Guide/Base/a.hpp"

#include "../../Operator/a.hpp"
#include "../../../../SetTheory/DirectProduct/a.hpp"
#include "../../../../../Utility/WrappedType/a.hpp"
#include "../../../../../Utility/WrappedType/Int/a.hpp"

template <typename... Args>
class DirectProductTypeOfComputableFunction :
  public TypeOfComputableFunction
{

public:
  using base_type = DirectProductTypeOfComputableFunction<typename BaseTypeOf<Args>::type...>;

  template <uint i>
  using type = decltype( Projection<i,Args...>( declval<DirectProduct<Args...> >() ) );

public:
  inline DirectProductTypeOfComputableFunction() noexcept;
  
  static inline const string& GetName() noexcept;
  static inline const SyntaxOfComputableFunction& GetSyntax() noexcept;

};


template <>
class DirectProductTypeOfComputableFunction<> :
  public EmptySet
{};


inline string GetName_Body_ForDirectProduct( const WrappedTypes<>& ) noexcept;

template <typename Arg> inline string GetName_Body_ForDirectProduct( const WrappedTypes<Arg>& ) noexcept;

template <typename Arg1, typename Arg2, typename... Args> inline string GetName_Body_ForDirectProduct( const WrappedTypes<Arg1,Arg2,Args...>& ) noexcept;


  
template <uint i, typename... Args> const PrettyOperator<typename DirectProductTypeOfComputableFunction<Args...>::template type<i>,DirectProductTypeOfComputableFunction<Args...> >& ProjectionSymbol_Body( const WrappedUInt<i>& , const WrappedTypes<Args...>& );

template <uint i, typename... Args> inline const PrettyOperator<decltype( ProjectionSymbol_Body( WrappedUInt<i>() , WrappedTypes<Args...>() ) ),DirectProductTypeOfComputableFunction<Args...> >& ProjectionSymbol();

template <uint i, typename... Args> inline ExpressionOfComputableFunction<typename DirectProductTypeOfComputableFunction<Args...>::template type<i> > ProjectionSymbolApplication( const ExpressionOfComputableFunction<Args>&... args );

template <typename... Args> inline const FunctionSymbol<DirectProductTypeOfComputableFunction<Args...>,Args...>& TupleSymbol();

template <typename... Args> inline ExpressionOfComputableFunction<DirectProductTypeOfComputableFunction<Args...> > TupleSymbolApplication( const ExpressionOfComputableFunction<Args>&... args );




