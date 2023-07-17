// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a.hpp

#pragma once
#include "../../Expression/Primitive/a.hpp"
#include "int/a.hpp"
#include "string/a.hpp"
#include "bool/a.hpp"

namespace QpBasic
{

  #include "QpBasic/a.hpp"

}


template <typename Ret> inline FunctionSymbol<Ret,Ret> operator^( const FunctionSymbol<Ret,Ret>& f , const PrettyExpression<nat>& n );
inline RelationSymbol<bool> operator^( const RelationSymbol<bool>& r , const PrettyExpression<nat>& n );

template <typename Ret, typename Arg1, typename Arg2> FunctionSymbol<Ret,Arg2> CurryingSymbol( const FunctionSymbol<Ret,Arg1,Arg2>& f , const ExpressionOfComputableFunction<Arg1>& x , const string& style = CurryString() );

template <typename Arg1, typename Arg2> RelationSymbol<Arg2> CurryingSymbol( const RelationSymbol<Arg1,Arg2>& r , const ExpressionOfComputableFunction<Arg1>& x ,  const string& style = CurryString() );

template <typename... Args> inline DECLARATION_OF_BOUNDED_EXISTENCE( Exist , nat );
template <typename... Args> inline DECLARATION_OF_BOUNDED_EXISTENCE( Exist ,string );

// これらは許容される関数ではないが、実装のためにあえて採用している。
inline PrettyFunction<nat,nat,bool> MinimumSymbol( const PrettyVariable<nat>& n , const ExpressionOfComputableFunction<bool>& b );
inline PrettyFunction<nat,nat,nat,bool> BoundedMaximumSymbol( const PrettyVariable<nat>& n , const PrettyExpression<nat>& bound , const ExpressionOfComputableFunction<bool>& b );
template <typename... Args> inline DECLARATION_OF_BOUNDED_EXISTENCE( UniqueExist , nat );
template <typename... Args> inline DECLARATION_OF_BOUNDED_EXISTENCE( UniqueExist ,string );
