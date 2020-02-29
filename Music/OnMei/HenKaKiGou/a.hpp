// c:/Users/user/Documents/Programming/Music/OnMei/HenKaKiGou/a.hpp

#pragma once

class HenKaKiGou
{

private:
  int m_num;

public:
  inline HenKaKiGou( const int& num ) noexcept;

  HenKaKiGou& operator++() noexcept;
  HenKaKiGou& operator--() noexcept;
  
  inline string Display() const noexcept;
  inline const int& GetNum() const noexcept;

  static string IntToString( const int& num ) noexcept;

};

inline bool operator==( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept;
inline bool operator!=( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept;

inline HenKaKiGou operator+( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept;
inline HenKaKiGou operator-( const HenKaKiGou& S1 , const HenKaKiGou& S2 ) noexcept;
