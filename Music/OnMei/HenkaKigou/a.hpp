// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a.hpp

#pragma once

class HenkaKigou
{

private:
  string m_S;
  int m_num;

public:
  inline HenkaKigou( const string& S );
  inline HenkaKigou( const int& num );

  inline const string& Display() const noexcept;
  inline const int& GetNum() const noexcept;

  static int StringToInt( const string& S );
  static const string& IntToString( const int& num );

};

inline bool operator==( const HenkaKigou& S1 , const HenkaKigou& S2 );
inline bool operator!=( const HenkaKigou& S1 , const HenkaKigou& S2 );

const HenkaKigou& Flat();
const HenkaKigou& Natural();
const HenkaKigou& Sharp();
inline const HenkaKigou& HenkaKigouTable( const string& S );
const HenkaKigou& HenkaKigouTable( const int& num );
