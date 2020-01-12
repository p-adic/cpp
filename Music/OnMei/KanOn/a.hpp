// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a.hpp

#pragma once
#include "a_Macro.hpp"

class KanOn
{

private:
  string m_N;

public:
  inline KanOn( const string& N );

  inline const string& Display() const noexcept;
  
};

bool operator==( const KanOn& N1 , const KanOn& N2 );
inline bool operator!=( const KanOn& N1 , const KanOn& N2 );

const KanOn& Do();
const KanOn& Re();
const KanOn& Mi();
const KanOn& Fa();
const KanOn& So();
const KanOn& La();
const KanOn& Ti();
