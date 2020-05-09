// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../Basic/nat/a.hpp"
#include "../../Operator/a.hpp"

template <typename Ret>
class ArrayTypeOfComputableFunction :
  public TypeOfComputableFunction
{

public:
  using base_type = ArrayTypeOfComputableFunction<typename BaseTypeOf<Ret>::type>;

public:
  inline ArrayTypeOfComputableFunction() noexcept;
  
  static inline const string& GetName() noexcept;
  static inline const SyntaxOfComputableFunction& GetSyntax() noexcept;
  
};


template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( ArrayTypeOfComputableFunction<Ret> , Concatenate );
template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( ArrayTypeOfComputableFunction<Ret> , Concatenate );
template <typename Ret, typename... Args> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( ArrayTypeOfComputableFunction<Ret> , Concatenate );


template <typename Ret> inline const PrettyFunction<nat,ArrayTypeOfComputableFunction<Ret> >& LengthSymbol();
template <typename Ret> inline PrettyExpression<nat> LengthSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a );

template <typename Ret> inline const PrettyOperator<Ret,ArrayTypeOfComputableFunction<Ret>,nat>& EntryAccessSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<Ret> EntryAccessSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , const PrettyExpression<nat>& n );

template <typename Ret> inline const PrettyFunction<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat>& InitialSegmentSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > InitialSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n );

template <typename Ret> inline const PrettyFunction<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat>& FinalSegmentSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > FinalSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n );

template <typename Ret> inline const PrettyFunction<ArrayTypeOfComputableFunction<Ret>,Ret>& WrapSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > WrapSymbolApplication( const ExpressionOfComputableFunction<Ret>& x );


template <typename Ret> inline PrettyFunction<ArrayTypeOfComputableFunction<Ret>,nat> ArrayiseSymbol( const FunctionSymbol<Ret,int>& f , const PrettyVariable<nat>& n );

inline PrettyFunction<ArrayTypeOfComputableFunction<bool>,nat> ArrayiseSymbol( const RelationSymbol<int>& r , const PrettyVariable<nat>& n );
