// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Dimension/a.hpp

#pragma once

#include "a_Alias.hpp"

class dim
{

private:
  INT_TYPE_FOR_DIM m_d;
  bool m_is_infinity;

public:
  inline dim( const INT_TYPE_FOR_DIM& c = 0 ) noexcept;
  inline dim& operator=( const dim& c ) noexcept;
  inline dim& operator=( const INT_TYPE_FOR_DIM& c ) noexcept;
  inline dim& operator+=( const dim& c ) noexcept;
  inline dim& operator+=( const INT_TYPE_FOR_DIM& c ) noexcept;
  inline dim& operator-=( const dim& c );
  inline dim& operator-=( const INT_TYPE_FOR_DIM& c );
  inline dim& operator*=( const dim& c );
  inline dim& operator*=( const INT_TYPE_FOR_DIM& c );
  inline dim& operator/=( const dim& c );
  inline dim& operator/=( const INT_TYPE_FOR_DIM& c );
  inline dim& operator%=( const dim& c );
  inline dim& operator%=( const INT_TYPE_FOR_DIM& c );
  inline const INT_TYPE_FOR_DIM& Get() const;
  inline string Display() const noexcept;
  inline const bool& IsInfty() const noexcept;
  static inline const dim& Generate_infty() noexcept;

private:
  static inline dim Generate_infty_Body() noexcept;
  
};

const dim& infty() noexcept;

inline bool operator==( const dim& d_1 , const dim& d_2 ) noexcept;
inline bool operator==( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;
inline bool operator==( const INT_TYPE_FOR_DIM& c_1 , const dim& d_2 ) noexcept;

inline bool operator!=( const dim& d_1 , const dim& d_2 ) noexcept;
inline bool operator!=( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;
inline bool operator!=( const INT_TYPE_FOR_DIM& c_1 , const dim& d_2 ) noexcept;

inline bool operator<( const dim& d_1 , const dim& d_2 ) noexcept;
inline bool operator<( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;
inline bool operator<( const INT_TYPE_FOR_DIM& c_1 , const dim& d_2 ) noexcept;

inline bool operator>( const dim& d_1 , const dim& d_2 ) noexcept;
inline bool operator>( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;
inline bool operator>( const INT_TYPE_FOR_DIM& c_1 , const dim& d_2 ) noexcept;

inline bool operator<=( const dim& d_1 , const dim& d_2 ) noexcept;
inline bool operator<=( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;
inline bool operator<=( const INT_TYPE_FOR_DIM& c_1 , const dim& d_2 ) noexcept;

inline bool operator>=( const dim& d_1 , const dim& d_2 ) noexcept;
inline bool operator>=( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;
inline bool operator>=( const INT_TYPE_FOR_DIM& c_1 , const dim& d_2 ) noexcept;

dim operator+( const dim& d_1 , const dim& d_2 ) noexcept;
inline dim operator+( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;

dim operator-( const dim& d_1 , const dim& d_2 );
inline dim operator-( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 );

dim operator*( const dim& d_1 , const dim& d_2 );
inline dim operator*( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 );

dim operator/( const dim& d_1 , const dim& d_2 ) noexcept;
inline dim operator/( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;

dim operator%( const dim& d_1 , const dim& d_2 ) noexcept;
inline dim operator%( const dim& d_1 , const INT_TYPE_FOR_DIM& c_2 ) noexcept;

inline dim to_dim( const INT_TYPE_FOR_DIM& c ) noexcept;
inline const INT_TYPE_FOR_DIM& to_int( const dim& d ) noexcept;

inline const bool& CheckInfty( const dim& d ) noexcept;
