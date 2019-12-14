// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Dimension/a.hpp

#pragma once

class dim
{

private:
  uint m_d;
  static const uint m_infty;

public:
  dim();
  dim( const uint& );
  dim& operator=( const dim& );
  dim& operator=( const uint& );
  dim& operator+=( const dim& );
  dim& operator+=( const uint& );
  dim& operator-=( const dim& );
  dim& operator-=( const uint& );
  dim& operator*=( const dim& );
  dim& operator*=( const uint& );
  dim& operator/=( const dim& );
  dim& operator/=( const uint& );
  dim& operator%=( const dim& );
  dim& operator%=( const uint& );
  const uint& Get() const;
  string Display() const;
  bool IsInfty() const;
  static const dim* const Generate_infty();
  
};

const dim* const infty();

bool operator==( const dim& , const dim& );
bool operator==( const dim& , const uint& );
bool operator==( const uint& , const dim& );

bool operator!=( const dim& , const dim& );
bool operator!=( const dim& , const uint& );
bool operator!=( const uint& , const dim& );

bool operator<( const dim& , const dim& );
bool operator<( const dim& , const uint& );
bool operator<( const uint& , const dim& );

bool operator>( const dim& , const dim& );
bool operator>( const dim& , const uint& );
bool operator>( const uint& , const dim& );

bool operator<=( const dim& , const dim& );
bool operator<=( const dim& , const uint& );
bool operator<=( const uint& , const dim& );

bool operator>=( const dim& , const dim& );
bool operator>=( const dim& , const uint& );
bool operator>=( const uint& , const dim& );

dim operator+( const dim& , const dim& );
dim operator+( const dim& , const uint& );

dim operator-( const dim& , const dim& );
dim operator-( const dim& , const uint& );

dim operator*( const dim& , const dim& );
dim operator*( const dim& , const uint& );

dim operator/( const dim& , const dim& );
dim operator/( const dim& , const uint& );

dim operator%( const dim& , const dim& );
dim operator%( const dim& , const uint& );

dim Sum( const list<dim>& );
dim Prod( const list<dim>& );

dim to_dim( const uint& );
const uint& to_int( const dim& );

bool CheckInfty( const dim& );
