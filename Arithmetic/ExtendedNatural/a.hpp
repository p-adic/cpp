// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedNatural/a.hpp

#pragma once
#include "a_Alias.hpp"

class euint
{

private:
  INT_TYPE_FOR_EUINT m_d;
  bool m_is_infinity;

public:
  inline euint( const INT_TYPE_FOR_EUINT& c = 0 ) noexcept;
  inline euint& operator=( const euint& c ) noexcept;
  inline euint& operator=( const INT_TYPE_FOR_EUINT& c ) noexcept;
  inline euint& operator+=( const euint& c ) noexcept;
  inline euint& operator+=( const INT_TYPE_FOR_EUINT& c ) noexcept;
  euint& operator-=( const euint& c );
  inline euint& operator-=( const INT_TYPE_FOR_EUINT& c );
  euint& operator*=( const euint& c );
  inline euint& operator*=( const INT_TYPE_FOR_EUINT& c );
  euint& operator/=( const euint& c );
  inline euint& operator/=( const INT_TYPE_FOR_EUINT& c );
  euint& operator%=( const euint& c );
  inline euint& operator%=( const INT_TYPE_FOR_EUINT& c );
  inline const INT_TYPE_FOR_EUINT& Get() const noexcept;
  inline string Display() const noexcept;
  inline const bool& IsInfty() const noexcept;
  static inline const euint& Generate_infty() noexcept;

private:
  static inline euint Generate_infty_Body() noexcept;
  
};

inline const euint& infty() noexcept;

inline bool operator==( const euint& d_1 , const euint& d_2 ) noexcept;
inline bool operator==( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;
inline bool operator==( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept;

inline bool operator!=( const euint& d_1 , const euint& d_2 ) noexcept;
inline bool operator!=( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;
inline bool operator!=( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept;

inline bool operator<( const euint& d_1 , const euint& d_2 ) noexcept;
inline bool operator<( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;
inline bool operator<( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept;

inline bool operator>( const euint& d_1 , const euint& d_2 ) noexcept;
inline bool operator>( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;
inline bool operator>( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept;

inline bool operator<=( const euint& d_1 , const euint& d_2 ) noexcept;
inline bool operator<=( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;
inline bool operator<=( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept;

inline bool operator>=( const euint& d_1 , const euint& d_2 ) noexcept;
inline bool operator>=( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;
inline bool operator>=( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept;

euint operator+( const euint& d_1 , const euint& d_2 ) noexcept;
inline euint operator+( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;

euint operator-( const euint& d_1 , const euint& d_2 );
inline euint operator-( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 );

euint operator*( const euint& d_1 , const euint& d_2 );
inline euint operator*( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 );

euint operator/( const euint& d_1 , const euint& d_2 ) noexcept;
inline euint operator/( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;

euint operator%( const euint& d_1 , const euint& d_2 ) noexcept;
inline euint operator%( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept;

inline euint to_euint( const INT_TYPE_FOR_EUINT& c ) noexcept;
inline const INT_TYPE_FOR_EUINT& to_int( const euint& d ) noexcept;

inline const bool& CheckInfty( const euint& d ) noexcept;
