// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Constexpr/Counting/a.hpp

#pragma once

template <typename INT , INT val_limit , int length_max = val_limit>
class PrimeCounting
{

private:
  int m_val[val_limit];

public:
  inline constexpr PrimeCounting( const PrimeEnumeration<INT,val_limit,length_max>& pe );

  // min(i以下の素数の個数,length_max)を返す。
  inline constexpr const int& Pi( const int& i ) const;
  inline constexpr const int& Get( const int& i ) const;
  inline constexpr const int& operator[]( const int& i ) const;

};
