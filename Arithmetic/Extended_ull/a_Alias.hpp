// c:/Users/user/Documents/Programming/Utility/Extended_ull/a_Alias.hpp

#pragma once
using ulll = Extended_ull<ull,64>;
using ullll = Extended_ull<ulll,128>;
using ulllll = Extended_ull<ullll,256>;

using ul2 = ull;
using ul3 = Extended_ull<ul2,64*1>;
using ul4 = Extended_ull<ul3,64*2>; // 十進法で36桁、64bit整数2個の積まで対応
using ul5 = Extended_ull<ul4,64*4>;
using ul6 = Extended_ull<ul5,64*8>; // 十進法で144桁、64bit整数8個の積まで対応
using ul7 = Extended_ull<ul6,64*16>;
using ul8 = Extended_ull<ul7,64*32>;
using ul9 = Extended_ull<ul8,64*64>; // 十進法で1152桁、64bit整数64個の積まで対応
using ul10 = Extended_ull<ul9,64*128>;
using ul11 = Extended_ull<ul10,64*256>;
using ul12 = Extended_ull<ul11,64*512>; // 十進法で10^5桁オーバー
using ul13 = Extended_ull<ul12,64*1024>; // 手元の環境だと小さい数の演算でも実行時メモリ不足
using ul14 = Extended_ull<ul13,64*2048>;
using ul15 = Extended_ull<ul14,64*4096>;
using ul16 = Extended_ull<ul15,64*8192>;
using ul17 = Extended_ull<ul16,64*16384>;
using ul18 = Extended_ull<ul17,64*32768>;
using ul19 = Extended_ull<ul18,64*65536>; // 手元の環境だとコンストラクタでも実行時メモリ不足
using ul20 = Extended_ull<ul19,64*131072>; // 手元の環境だとコンパイル時メモリ不足
using ul21 = Extended_ull<ul20,64*262144>;
using ul22 = Extended_ull<ul21,64*524288>;
using ul23 = Extended_ull<ul22,64*1048576>;

