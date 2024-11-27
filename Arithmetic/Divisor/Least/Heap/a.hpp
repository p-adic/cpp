// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Least/Heap/a.hpp

#pragma once
#include "a.hpp"

class HeapLeastDivisor
{

private:
  int m_val_limit;
  vector<int> m_val;

public:
  // O(val_limit log log val_limit)
  inline HeapLeastDivisor( const int& val_limit ) noexcept;

  inline const int& operator[]( const int& i ) const;
  inline const int& Get( const int& i ) const;
  inline const int& length() const noexcept;

};

