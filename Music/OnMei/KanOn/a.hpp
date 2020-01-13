// c:/Users/user/Documents/Programming/Music/OnMei/KanOn/a.hpp

#pragma once
#include "a_Macro.hpp"

class KanOn
{

private:
  string m_N;
  uint m_num;

public:
  inline KanOn( const string& N );
  inline KanOn( const uint& num );

  inline const string& Display() const noexcept;
  inline const uint& GetNum() const noexcept;
  
  static uint StringToInt( const string& N );
  static const string& IntToString( const uint& num );

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
inline const KanOn& KanOnTable( const string& N );
const KanOn& KanOnTable( const uint& num );
