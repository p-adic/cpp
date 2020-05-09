// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Array/Nest/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

template <typename Ret>
class NestedArrayTypeOfComputableFunction :
  public TypeOfComputableFunction
{

public:
  using base_type = NestedArrayTypeOfComputableFunction<typename BaseTypeOf<Ret>::type>;

public:
  inline NestedArrayTypeOfComputableFunction() noexcept;
  
  static inline const string& GetName() noexcept;
  static inline const SyntaxOfComputableFunction& GetSyntax() noexcept;
  
};


template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( NestedArrayTypeOfComputableFunction<Ret> , NestedConcatenate );
template <typename Ret> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( NestedArrayTypeOfComputableFunction<Ret> , NestedConcatenate );
template <typename Ret, typename... Args> inline DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( NestedArrayTypeOfComputableFunction<Ret> , NestedConcatenate );

template <typename Ret> inline DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( NestedArrayTypeOfComputableFunction<Ret> , + );


template <typename Ret> inline const PrettyFunction<nat,NestedArrayTypeOfComputableFunction<Ret> >& NestedLengthSymbol();
template <typename Ret> inline PrettyExpression<nat> NestedLengthSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a );

template <typename Ret> inline const PrettyOperator<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat>& NestedEntryAccessSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret>> NestedEntryAccessSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a , const PrettyExpression<nat>& n );

template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat>& NestedInitialSegmentSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > NestedInitialSegmentSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n );

template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret>,nat>& NestedFinalSegmentSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > NestedFinalSegmentSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a , PrettyExpression<nat> n );

template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,Ret>& ToTrivialNestedArraySymbol();
template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > ToTrivialNestedArrayApplication( const ExpressionOfComputableFunction<Ret>& x );

template <typename Ret> inline const PrettyFunction<Ret,NestedArrayTypeOfComputableFunction<Ret> >& RemoveNestedArraySymbol();
template <typename Ret> inline ExpressionOfComputableFunction<Ret> RemoveNestedArraySymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a );

template <typename Ret> inline const PrettyRelation<NestedArrayTypeOfComputableFunction<Ret> >& RemovableNestedArraySymbol();
template <typename Ret> inline ConditionOfComputableFunction RemovableNestedArraySymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a );


template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,ArrayTypeOfComputableFunction<Ret> >& NestifySymbol();
template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > NestifySymbolApplication( const ExpressionOfComputableFunction<ArrayTypeOfComputableFunction<Ret> >& a );

template <typename Ret> inline const PrettyFunction<NestedArrayTypeOfComputableFunction<Ret>,NestedArrayTypeOfComputableFunction<Ret> >& NestedWrapSymbol();
template <typename Ret> inline ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> > NestedWrapSymbolApplication( const ExpressionOfComputableFunction<NestedArrayTypeOfComputableFunction<Ret> >& a );
