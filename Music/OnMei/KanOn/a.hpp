// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Mathematics/Arithmetic/Mod/a.hpp"

class KanOn
{

private:
  Mod<7> m_num;

public:
  inline KanOn( const int& num ) noexcept;

  inline string Display() const noexcept;
  inline const int& GetNum() const noexcept;
  
  static const string& IntToString( const int& num ) noexcept;

};

bool operator==( const KanOn& N1 , const KanOn& N2 ) noexcept;
inline bool operator!=( const KanOn& N1 , const KanOn& N2 ) noexcept;

const KanOn& Do() noexcept;
const KanOn& Re() noexcept;
const KanOn& Mi() noexcept;
const KanOn& Fa() noexcept;
const KanOn& So() noexcept;
const KanOn& La() noexcept;
const KanOn& Ti() noexcept;
const KanOn& KanOnTable( const int& num ) noexcept;
