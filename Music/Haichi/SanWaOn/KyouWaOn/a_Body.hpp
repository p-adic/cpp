// c:/Users/user/Documents/Programming/Music/Haichi/SanWaOn/KyouWaOn/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Chou/a_Body.hpp"

inline KyouWaOn::KyouWaOn( const Chou& N , const KaiMei& n ) noexcept : SanWaOn( N.OnMeiTable( n ) , N.OnMeiTable( n + 2 ) , N.OnMeiTable( n + 4 ) ) {}

inline bool KyouWaOn::IsValid() const noexcept { return OnDo( Pitch( GetOnMei( 0 ) , 0 ) , Pitch( GetOnMei( 2 ) , 1 ) ) != OnDo( Pitch( Ti() , 0 ) , Pitch( Fa() , 1 ) ); }

inline const OnMei& KyouWaOn::GetNeOn() const noexcept { return GetOnMei( 0 ); }
inline const OnMei& KyouWaOn::GetDaiSanOn() const noexcept { return GetOnMei( 1 ); }
inline const OnMei& KyouWaOn::GetDaiGoOn() const noexcept { return GetOnMei( 2 ); }

inline bool operator==( const KyouWaOn& H1 , const KyouWaOn& H2 ) noexcept { return H1.GetNeOn() == H2.GetNeOn() && H1.GetDaiSanOn() == H2.GetDaiSanOn() && H1.GetDaiGoOn() == H2.GetDaiGoOn(); }
inline bool operator!=( const KyouWaOn& H1 , const KyouWaOn& H2 ) noexcept { return !( H1 == H2 ); }
