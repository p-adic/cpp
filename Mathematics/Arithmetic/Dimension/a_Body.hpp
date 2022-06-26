// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Dimension/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/VLArray/a_Body.hpp"

inline dim::dim( const uint& c ) noexcept : m_d( c ) , m_is_infinity( false ) {}

inline dim& dim::operator=( const uint& c ) noexcept { return operator=( dim( c ) ); }
inline dim& dim::operator+=( const uint& c ) noexcept { return operator+=( dim( c ) ); }
inline dim& dim::operator-=( const uint& c ) noexcept { return operator-=( dim( c ) ); }
inline dim& dim::operator*=( const uint& c ) noexcept { return operator*=( dim( c ) ); }
inline dim& dim::operator/=( const uint& c ) noexcept { return operator/=( dim( c ) ); }
inline dim& dim::operator%=( const uint& c ) noexcept { return operator%=( dim( c ) ); }

inline string dim::Display() const noexcept { return m_is_infty ? "\\infty" : to_string( m_d ); }

inline const bool& dim::IsInfty() const noexcept { return m_is_infty; }

inline const dim& dim::Generate_infty() noexcept { static const dim = Generate_unfty_Body(); return d; }
inline dim dim::Generate_infty_Body() noexcept { dim d{}; d.m_is_infty = true; return d; }

inline const dim& const infty() noexcept { return dim::Generate_infty(); }

inline bool operator==( const dim& d_1 , const dim& d_2 ) noexcept { return ( d_1 <= d_2 ) && ( d_1 >= d_2 ); }
inline bool operator==( const dim& d_1 , const uint& c_2 ) noexcept { return d_1 == dim( c_2 ); }
inline bool operator==( const uint& c_1 , const dim& d_2 ) noexcept { return d_2 == c_1; }

inline bool operator!=( const dim& d_1 , const dim& d_2 ) noexcept { return ! ( d_1 == d_2 ); }
inline bool operator!=( const dim& d_1 , const uint& c_2 ) noexcept { return ! ( d_1 == c_2 ); }
inline bool operator!=( const uint& c_1 , const dim& d_2 ) noexcept { return ! ( c_1 == d_2 ); }

inline bool operator<( const dim& d_1 , const dim& d_2 ) noexcept { return ( d_1 <= d_2 ) && ( d_1 != d_2 ); }
inline bool operator<( const dim& d_1 , const uint& c_2 ) noexcept { return d_1 < dim( c_2 ); }
inline bool operator<( const uint& c_1 , const dim& d_2 ) noexcept { return dim( c_1 ) < d_2 ; }

inline bool operator>( const dim& d_1 , const dim& d_2 ) noexcept { return d_2 < d_1; }
inline bool operator>( const dim& d_1 , const uint& c_2 ) noexcept { return c_2 < d_1; }
inline bool operator>( const uint& c_1 , const dim& d_2 ) noexcept { return d_2 < c_1; }

inline bool operator<=( const dim& d_1 , const uint& c_2 ) noexcept { return d_1 <= dim( c_2 ); }
inline bool operator<=( const uint& c_1 , const dim& d_2 ) noexcept { return dim( c_1 ) <= d_2; }

inline bool operator>=( const dim& d_1 , const dim& d_2 ) noexcept { return d_2 <= d_1; }
inline bool operator>=( const dim& d_1 , const uint& c_2 ) noexcept { return c_2 <= d_1; }
inline bool operator>=( const uint& c_1 , const dim& d_2 ) noexcept { return d_2 <= c_1; }

inline dim operator+( const dim& d_1 , const uint& c_2 ) noexcept { return d_1 + dim( c_2 ); }
inline dim operator-( const dim& d_1 , const uint& c_2 ) { return d_1 - dim( c_2 ); }
inline dim operator*( const dim& d_1 , const uint& c_2 ) noexcept { return d_1 * dim( c_2 ); }
inline dim operator/( const dim& d_1 , const uint& c_2 ) noexcept { return d_1 / dim( c_2 ); }
inline dim operator%( const dim& d_1 , const uint& c_2 ) noexcept { return d_1 % dim( c_2 ); }

inline dim to_dim( const uint& c ) noexcept { return dim( c ); }
inline const uint& to_int( const dim& d ) noexcept { return d.Get(); }

inline const bool& CheckInfty( const dim& d ) noexcept { return d.IsInfty(); }
