// c:/Users/user/Documents/Programming/Utility/Extended_ull/a_Alias.hpp

#pragma once
using ulll = Extended_ull<ull,64>;
using ullll = Extended_ull<ulll,128>;
using ulllll = Extended_ull<ullll,256>;

using ul2 = ull;
using ul3 = Extended_ull<ul2,64*1>;
using ul4 = Extended_ull<ul3,64*2>;
using ul5 = Extended_ull<ul4,64*4>;
using ul6 = Extended_ull<ul5,64*8>;
using ul7 = Extended_ull<ul6,64*16>;
using ul8 = Extended_ull<ul7,64*32>;
using ul9 = Extended_ull<ul8,64*64>;
using ul10 = Extended_ull<ul9,64*128>;
