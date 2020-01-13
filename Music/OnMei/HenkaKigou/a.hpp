// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a.hpp

#pragma once

class HenkaKigou
{

private:
  string m_sym;
  int m_num;

public:
  inline HenkaKigou( const string& sym );
  inline HenkaKigou( const int& num);
  inline HenkaKigou( const HenkaKigou& S );

  inline const string& Display() const noexcept;
  inline const int& GetNum() const noexcept;

  static int StringToInt( const string& sym );
  static const string& IntToString( const int& num );

};
