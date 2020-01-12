// c:/Users/user/Documents/Programming/Music/OnMei/a.hpp

#pragma once
#include "KanOn/a.hpp"
#include "../../Mathematics/Arithmetic/Mod/a.hpp"

class OnMei
{

private:
  KanOn m_N;
  int m_sharp;

public:
  inline OnMei( const KanOn& N );
  inline OnMei( const KanOn& N , const int& n );
  inline OnMei( const OnMei& N );

  inline const string& Display() const noexcept;
  Mod<12> GetNumber() const;
  
};
