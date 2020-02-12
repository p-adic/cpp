// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/a.hpp

#pragma once
#include "Order/a.hpp"

template <typename Ret>
class ComputableFunction
{

private:
  VLTree<string> m_syntax;
  
public:
  ComputableFunction( const OrderOfComputableFunction<Ret>& definition );
  template <typename T, typename... ARGS> ComputableFunction( const OrderOfComputableFunction<Ret>& definition , const VariableSymbol<T>& t , const ARGS&... args );

  string Display( const string& mode ) const noexcept;

};
