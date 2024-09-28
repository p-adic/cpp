// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/Counting/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/971476

template <int val_limit , int length_max = val_limit>
class PrimeCounting
{

private:
  int m_val[val_limit];

public:
  inline constexpr PrimeCounting( const PrimeEnumeration<val_limit,length_max>& pe );

  // min(iˆÈ‰º‚Ì‘f”‚ÌŒÂ”,length_max)‚ğ•Ô‚·B
  inline const int& operator[]( const int& i ) const;
  inline constexpr const int& Pi( const int& i ) const;
  inline constexpr const int& Get( const int& i ) const;

};
