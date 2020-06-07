// c:/Users/user/Documents/Programming/Music/WaOn/YonWaOn/Seventh/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Chou/a_Body.hpp"

inline Seventh::Seventh( const Chou& N , const KaiMei& n ) noexcept : YonWaOn( N.OnMeiTable( n ) , N.OnMeiTable( n + 2 ) , N.OnMeiTable( n + 4 ) , N.OnMeiTable( n + 6 ) ){}

inline const OnMei& Seventh::GetNeOn() const noexcept { return GetOnMei( 0 ); }
inline const OnMei& Seventh::GetDaiSanOn() const noexcept { return GetOnMei( 1 ); }
inline const OnMei& Seventh::GetDaiGoOn() const noexcept { return GetOnMei( 2 ); }
inline const OnMei& Seventh::GetDaiNanaOn() const noexcept { return GetOnMei( 3 ); }

inline bool operator==( const Seventh& H1 , const Seventh& H2 ) noexcept { return H1.GetNeOn() == H2.GetNeOn() && H1.GetDaiSanOn() == H2.GetDaiSanOn() && H1.GetDaiGoOn() == H2.GetDaiGoOn() && H1.GetDaiNanaOn() == H2.GetDaiNanaOn(); }
inline bool operator!=( const Seventh& H1 , const Seventh& H2 ) noexcept { return !( H1 == H2 ); }
