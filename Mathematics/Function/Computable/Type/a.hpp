// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a.hpp

#pragma once
#include "../Expression/Condition/a.hpp"

class TypeOfComputableFunction
{

private:
  const string m_type_name;
  const string m_definition;

public:
  inline TypeOfComputableFunction( const string& type_name , const string& definition ) noexcept;
  
  inline const string& Display() const noexcept;
  void WriteOn( const int& dummy , const string& language , const string& style , const string& filename , const ios_base::openmode& open_mode ) const noexcept;

private:
  void InputDefinition( ofstream& ofs , const string& language , const string& style ) const noexcept;

};

