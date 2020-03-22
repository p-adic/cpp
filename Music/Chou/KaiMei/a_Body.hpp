// c:/Users/user/Documents/Programming/Music/Chou/KaiMei/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Mathematics/Arithmetic/Mod/a_Body.hpp"

inline KaiMei::KaiMei( const int& n ) noexcept : Mod<7>( n ) {}

inline const KaiMei& KaiMei::I() noexcept { static const KaiMei n{ 0 }; return n; }
inline const KaiMei& KaiMei::II() noexcept { static const KaiMei n{ 1 }; return n; }
inline const KaiMei& KaiMei::III() noexcept { static const KaiMei n{ 2 }; return n; }
inline const KaiMei& KaiMei::IV() noexcept { static const KaiMei n{ 3 }; return n; }
inline const KaiMei& KaiMei::V() noexcept { static const KaiMei n{ 4 }; return n; }
inline const KaiMei& KaiMei::VI() noexcept { static const KaiMei n{ 5 }; return n; }
inline const KaiMei& KaiMei::VII() noexcept { static const KaiMei n{ 6 }; return n; }
