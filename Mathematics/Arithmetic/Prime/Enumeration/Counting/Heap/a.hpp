// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/Counting/Heap/a.hpp

#pragma once
#include "../Heap/a.hpp"

class HeapPrimeCounting
{

private:
  int m_p_max;
  vector<int> m_val;

public:
  inline HeapPrimeCounting( const HeapPrimeEnumeration& pe );

  // min(iˆÈ‰º‚Ì‘f”‚ÌŒÂ”,length_max)‚ğ•Ô‚·B
  inline const int& operator[]( const int& i ) const;
  inline const int& Pi( const int& i ) const;
  inline const int& Get( const int& i ) const;

};
