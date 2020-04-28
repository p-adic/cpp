// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../Basic/nat/a.hpp"
#include "../../Function/Variadic/a.hpp"

template <typename Ret>
class ArrayTypeOfComputableFunction :
  public TypeOfComputableFunction
{

public:
  using base_type = ArrayTypeOfComputableFunction<Ret>;

public:
  inline ArrayTypeOfComputableFunction() noexcept;
  
  static inline const string& GetName() noexcept;
  static inline const SyntaxOfComputableFunction& GetSyntax() noexcept;
  
};


template <typename Ret> DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( ArrayTypeOfComputableFunction<Ret> , Plus );

template <typename Ret> inline const FunctionSymbol<nat,ArrayTypeOfComputableFunction<Ret> >& LengthSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<nat> LengthSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a );

template <typename Ret> inline const PrettyOperator<Ret,ArrayTypeOfComputableFunction<Ret>,nat>& EntryAccessSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<Ret> EntryAccessSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , const ExpressionOfComputableFunction<nat>& n );

template <typename Ret> inline const FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat>& InitialSegmentSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > InitialSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , ExpressionOfComputableFunction<nat> n );

template <typename Ret> inline const FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret>,nat>& FinalSegmentSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> > FinalSegmentSymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a , ExpressionOfComputableFunction<nat> n );

template <typename Ret> inline FunctionSymbol<ArrayTypeOfComputableFunction<Ret>,nat> ArrayiseSymbol( const FunctionSymbol<Ret,nat>& f );
