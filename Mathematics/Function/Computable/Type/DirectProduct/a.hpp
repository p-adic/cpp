// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/DirectProduct/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../Function/a.hpp"
#include "../../Relation/a.hpp"
#include "../../../../SetTheory/DirectProduct/a.hpp"
#include "../../../../../Utility/WrappedType/a.hpp"
#include "../../../../../Utility/WrappedType/Int/a.hpp"

template <typename... Args>
class DirectProductTypeOfComputableFunction :
  public TypeOfComputableFunction
{

public:
  template <uint i>
  using type = decltype( Projection<i,Args...>( declval<DirectProduct<Args...> >() ) );

public:
  inline DirectProductTypeOfComputableFunction() noexcept;
  
  static inline const string& GetName() noexcept;
  static inline const SyntaxOfComputableFunction& GetSyntax() noexcept;
  
  template <uint i> static auto ProjectionSymbol_Body( const WrappedUInt<i>& ) noexcept -> typename enable_if<! is_same<typename BaseTypeOf<type<i> >::type,bool>::value,const PrettyFunction<type<i>,DirectProductTypeOfComputableFunction<Args...> >&>::type;

  template <uint i> static auto ProjectionSymbol_Body( const WrappedUInt<i>& ) noexcept -> typename enable_if<is_same<typename BaseTypeOf<type<i> >::type,bool>::value,const PrettyRelation<DirectProductTypeOfComputableFunction<Args...> > &>::type;

};


template <>
class DirectProductTypeOfComputableFunction<> :
  public EmptySet
{};


inline string GetName_Body_ForDirectProduct( const WrappedTypes<>& ) noexcept;

template <typename Arg> inline string GetName_ForDirectProduct( const WrappedTypes<Arg>& ) noexcept;

template <typename Arg1, typename Arg2, typename... Args> inline string GetName_ForDirectProduct( const WrappedTypes<Arg1,Arg2,Args...>& ) noexcept;


template <uint i, typename... Args> inline auto ProjectionSymbol() noexcept -> decltype( DirectProductTypeOfComputableFunction<Args...>::ProjectionSymbol_Body( WrappedUInt<i>() ) );
