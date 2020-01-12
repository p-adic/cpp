// c:/Users/user/Documents/Programming/Music/OnMei/a.hpp

#pragma once

#include "../../Mathematics/Arithmetic/Mod/a.hpp"

class OnMei
{

private:
  KanOn m_N;
  int m_sharp;

public:
  OnMei( const KanOn& N );
  OnMei( const KanOn& N , const int& n );
  OnMei( const OnMei& N );

  string Display() const;
  Mod<12> GetInt() const;
  
};
