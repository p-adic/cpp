// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Relation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Separator/a.hpp"
#include "../../Type/Guide/Base/a.hpp"
#include "../../Type/SubType/a.hpp"

// #include "../../Expression/Primitive/bool/a.hpp"
// #include "../../Expression/Variable/Variadic/a.hpp"

template <typename... Args>
class RelationSymbol :
  public SyntaxOfComputableFunction
{

public:
  inline RelationSymbol( const string& r , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );
  RelationSymbol( const string& r , const SeparatorOfComputableFunction& s , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );

  void SetSeparator( const SeparatorOfComputableFunction& s );

  inline ConditionOfComputableFunction operator()( const ExpressionOfComputableFunction<Args>&... args ) const;

};

#include "a_Alias.hpp"

template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Eq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Neq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Leq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Geq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Lneq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL( Ret , Gneq );

template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Eq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Neq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Leq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Geq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Lneq );
template <typename Ret> DECLARATION_OF_TWO_ARY_RELATION_SYMBOL_APPLICATION( Ret , Gneq );
