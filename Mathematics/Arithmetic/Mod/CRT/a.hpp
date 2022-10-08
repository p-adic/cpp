// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/CRT/a.hpp

#pragma once

template <typename INT>
INT GCD( const INT& b_0 , const INT& b_1 );

template <typename INT> inline INT LCM( const INT& b_0 , const INT& b_1 );

template <typename INT>
INT ChineseReminderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 );

template <INT_TYPE_FOR_MOD B_0 , INT_TYPE_FOR_MOD B_1>
INT_TYPE_FOR_MOD ChineseReminderTheorem( const Mod<B_0>& c_0 , const Mod<B_1>& c_1 );

