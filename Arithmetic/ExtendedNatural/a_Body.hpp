// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedNatural/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/VLArray/a_Body.hpp"

inline euint::euint( const INT_TYPE_FOR_EUINT& c ) noexcept : m_d( c ) , m_is_infinity( false ) {}

inline euint& euint::operator=( const euint& d ) noexcept { m_d = d.m_d; m_is_infty = d.m_is_infty; return *this; }
inline euint& euint::operator=( const INT_TYPE_FOR_EUINT& c ) noexcept { return operator=( euint( c ) ); }
inline euint& euint::operator+=( const euint& d ) noexcept { return ( m_is_infty || d.m_is_infty ) ? *this = Generate_infty() : ( m_d += d.m_d ) < d.m_d ? *this = Generate_infty() : *this; }
inline euint& euint::operator+=( const INT_TYPE_FOR_EUINT& c ) noexcept { return operator+=( euint( c ) ); }
inline euint& euint::operator-=( const INT_TYPE_FOR_EUINT& c ) noexcept { return operator-=( euint( c ) ); }
inline euint& euint::operator*=( const INT_TYPE_FOR_EUINT& c ) noexcept { return operator*=( euint( c ) ); }
inline euint& euint::operator/=( const INT_TYPE_FOR_EUINT& c ) noexcept { return operator/=( euint( c ) ); }
inline euint& euint::operator%=( const INT_TYPE_FOR_EUINT& c ) noexcept { return operator%=( euint( c ) ); }

inline const INT_TYPE_FOR_EUINT& euint::Get() const noexcept { return m_d; }
inline string euint::Display() const noexcept { return m_is_infty ? "\\infty" : to_string( m_d ); }

inline const bool& euint::IsInfty() const noexcept { return m_is_infty; }

inline const euint& euint::Generate_infty() noexcept { static const euint = Generate_infty_Body(); return d; }
inline euint euint::Generate_infty_Body() noexcept { euint d{}; d.m_is_infty = true; return d; }

inline const euint& const infty() noexcept { return euint::Generate_infty(); }

inline bool operator==( const euint& d_1 , const euint& d_2 ) noexcept { return d_1.IsInfty() ? d_2.IsInfty() : d_2.IsInfty() ? false : d_1.Get() == d_2.Get(); }
inline bool operator==( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return d_1 == euint( c_2 ); }
inline bool operator==( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept { return d_2 == c_1; }

inline bool operator!=( const euint& d_1 , const euint& d_2 ) noexcept { return ! ( d_1 == d_2 ); }
inline bool operator!=( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return ! ( d_1 == c_2 ); }
inline bool operator!=( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept { return ! ( c_1 == d_2 ); }

inline bool operator<( const euint& d_1 , const euint& d_2 ) noexcept { return d_1.IsInfty() ? false : d_2.IsInfty() ? true : d_1.Get() < d_2.Get(); }
inline bool operator<( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return d_1 < euint( c_2 ); }
inline bool operator<( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept { return euint( c_1 ) < d_2 ; }

inline bool operator>( const euint& d_1 , const euint& d_2 ) noexcept { return d_2 < d_1; }
inline bool operator>( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return c_2 < d_1; }
inline bool operator>( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept { return d_2 < c_1; }

inline bool operator<=( const euint& d_1 , const euint& d_2 ) noexcept { return d_2.IsInfty() ? true : d_1.IsInfty() ? false : d_1.Get() <= d_2.Get(); }
inline bool operator<=( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return d_1 <= euint( c_2 ); }
inline bool operator<=( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept { return euint( c_1 ) <= d_2; }

inline bool operator>=( const euint& d_1 , const euint& d_2 ) noexcept { return d_2 <= d_1; }
inline bool operator>=( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return c_2 <= d_1; }
inline bool operator>=( const INT_TYPE_FOR_EUINT& c_1 , const euint& d_2 ) noexcept { return d_2 <= c_1; }

inline euint operator+( const euint& d_1 , const euint& d_2 ) noexcept { euint d = d_1; d += d_2; return d; }
inline euint operator+( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return d_1 + euint( c_2 ); }
inline euint operator-( const euint& d_1 , const euint& d_2 ) { euint d = d_1; d -= d_2; return d; }
inline euint operator-( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) { return d_1 - euint( c_2 ); }
inline euint operator*( const euint& d_1 , const euint& d_2 ) { euint d = d_1; d *= d_2; return d; }
inline euint operator*( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return d_1 * euint( c_2 ); }
inline euint operator/( const euint& d_1 , const euint& d_2 ) { euint d = d_1; d /= d_2; return d; }
inline euint operator/( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return d_1 / euint( c_2 ); }
inline euint operator%( const euint& d_1 , const euint& d_2 ) { euint d = d_1; d %= d_2; return d; }
inline euint operator%( const euint& d_1 , const INT_TYPE_FOR_EUINT& c_2 ) noexcept { return d_1 % euint( c_2 ); }

inline euint to_euint( const INT_TYPE_FOR_EUINT& c ) noexcept { return euint( c ); }
inline const INT_TYPE_FOR_EUINT& to_int( const euint& d ) noexcept { return d.Get(); }

inline const bool& CheckInfty( const euint& d ) noexcept { return d.IsInfty(); }
