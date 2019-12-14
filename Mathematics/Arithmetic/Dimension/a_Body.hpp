// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Dimension/a_Body.hpp

#pragma once
#include "a.hpp"

inline dim::dim() : dim( 0 ) {}
inline dim::dim( const uint& c ) : m_d( c ){}

inline dim& dim::operator=( const uint& c ){ return operator=( to_dim( c ) ); }
inline dim& dim::operator+=( const uint& c ){ return operator+=( to_dim( c ) ); }
inline dim& dim::operator-=( const uint& c ){ return operator-=( to_dim( c ) ); }
inline dim& dim::operator*=( const uint& c ){ return operator*=( to_dim( c ) ); }
inline dim& dim::operator/=( const uint& c ){ return operator/=( to_dim( c ) ); }
inline dim& dim::operator%=( const uint& c ){ return operator%=( to_dim( c ) ); }

inline bool dim::IsInfty() const { return m_d == m_infty; }

inline const dim* const infty(){ return dim::Generate_infty(); }

inline bool operator==( const dim& d_1 , const dim& d_2 ){ return ( d_1 <= d_2 ) && ( d_1 >= d_2 ); }
inline bool operator==( const dim& d_1 , const uint& c_2 ){ return d_1 == to_dim( c_2 ); }
inline bool operator==( const uint& c_1 , const dim& d_2 ){ return d_2 == c_1; }

inline bool operator!=( const dim& d_1 , const dim& d_2 ){ return ! ( d_1 == d_2 ); }
inline bool operator!=( const dim& d_1 , const uint& c_2 ){ return ! ( d_1 == c_2 ); }
inline bool operator!=( const uint& c_1 , const dim& d_2 ){ return ! ( c_1 == d_2 ); }

inline bool operator<( const dim& d_1 , const dim& d_2 ){ return ( d_1 <= d_2 ) && ( d_1 != d_2 ); }
inline bool operator<( const dim& d_1 , const uint& c_2 ){ return d_1 < to_dim( c_2 ); }
inline bool operator<( const uint& c_1 , const dim& d_2 ){ return to_dim( c_1 ) < d_2 ; }

inline bool operator>( const dim& d_1 , const dim& d_2 ){ return d_2 < d_1; }
inline bool operator>( const dim& d_1 , const uint& c_2 ){ return c_2 < d_1; }
inline bool operator>( const uint& c_1 , const dim& d_2 ){ return d_2 < c_1; }

inline bool operator<=( const dim& d_1 , const uint& c_2 ){ return d_1 <= to_dim( c_2 ); }
inline bool operator<=( const uint& c_1 , const dim& d_2 ){ return to_dim( c_1 ) <= d_2; }

inline bool operator>=( const dim& d_1 , const dim& d_2 ){ return d_2 <= d_1; }
inline bool operator>=( const dim& d_1 , const uint& c_2 ){ return c_2 <= d_1; }
inline bool operator>=( const uint& c_1 , const dim& d_2 ){ return d_2 <= c_1; }

inline dim operator+( const dim& d_1 , const uint& c_2 ){ return d_1 + to_dim( c_2 ); }
inline dim operator-( const dim& d_1 , const uint& c_2 ){ return d_1 - to_dim( c_2 ); }
inline dim operator*( const dim& d_1 , const uint& c_2 ){ return d_1 * to_dim( c_2 ); }
inline dim operator/( const dim& d_1 , const uint& c_2 ){ return d_1 / to_dim( c_2 ); }
inline dim operator%( const dim& d_1 , const uint& c_2 ){ return d_1 % to_dim( c_2 ); }

inline dim to_dim( const uint& c ){ return dim( c ); }
inline const uint& to_int( const dim& d ){ return d.Get(); }

inline bool CheckInfty( const dim& d ){ return d.IsInfty(); }
