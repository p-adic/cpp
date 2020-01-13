// c:/Users/user/Documents/Programming/Music/OnMei/HenkaKigou/a.hpp

#pragma once

class HenkaKigou
{

private:
  int m_num;

public:
  inline HenkaKigou( const int& num ) noexcept;

  inline string Display() const noexcept;
  inline const int& GetNum() const noexcept;

  static const string& Sharp() noexcept;
  static const string& Flat() noexcept;
  static string IntToString( const int& num ) noexcept;

};

inline bool operator==( const HenkaKigou& S1 , const HenkaKigou& S2 ) noexcept;
inline bool operator!=( const HenkaKigou& S1 , const HenkaKigou& S2 ) noexcept;
