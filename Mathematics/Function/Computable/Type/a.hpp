// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a.hpp

#pragma once
#include <string>
#include <fstream>

#include "a_Macro.hpp"

class TypeOfComputableFunction
{

private:
  const string m_type_name;
  const string m_definition;

public:
  inline TypeOfComputableFunction( const string& type_name , const string& definition ) noexcept;
  
  inline const string& Display() const noexcept;
  void WriteTo( const TypeOfComputableFunction& dummy , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept;

private:
  inline void InputDefinition( ofstream& ofs , const string& language , const string& style ) const noexcept;

};

