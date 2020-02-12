// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a.hpp

#pragma once
#include "../../../../Utility/VLTree/a.hpp"

class SyntaxOfComputableFunction
{

private:
  VLTree<string> m_syntax;

public:
  template <typename... ARGS> SyntaxOfComputableFunction( const ARGS&... args );
  
  inline const VLTree<string>& Get() const noexcept;
  inline VLTree<string>& Ref() noexcept;
  const string& Role() const;
  const string& Name() const;

};
