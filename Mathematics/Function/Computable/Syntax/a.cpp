// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

#include "../../../../Error/FaultInCoding/a.hpp"

const string& SyntaxOfComputableFunction::Role() const
{

  if( m_syntax.IsLeaf() ){

    ERR_CODE;

  }

  auto itr = m_syntax.LeftMostNode();

  if( ! itr.IsValid() ){

    ERR_CODE;

  }

  return *itr;

}

const string& SyntaxOfComputableFunction::Name() const
{

  if( m_syntax.IsLeaf() ){

    ERR_CODE;

  }

  auto itr = m_syntax.LeftMostNode();
  itr++;

  if( ! itr.IsValid() ){

    ERR_CODE;

  }
  
  return *itr;

}
