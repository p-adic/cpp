// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/a.hpp

#pragma once
#include "a_Macro.hpp"

#include <vector>

template <typename T> inline constexpr const uint LimitOfPowerForFFT;
template <typename T> inline constexpr const uint BorderForFFT;

template <typename T> inline const T ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];
template <typename T> inline const T ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<T>];

// 以下要件：
// (1) N_input_lim - N_in_start <= two_power
// (2) N_output_lim - N_output_start <= two_power
// (3) 任意の整数iに対し、N_input_lim <= i < f.size()ならばf[i] == 0;

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を高速フーリエ変換したものをgと置き、
// fの係数列を長さN_input_start + two_powerの配列
// (f[0],...,f[N_input_start - 1],g[0],...,g[two_power - 1])
// に置き換える。
template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const uint& exponent );

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を高速フーリエ変換したものをgと置き、
// fの係数列を長さN_input_start + N_output_limの配列
// (f[0],...,f[N_input_start - 1],N_output_shift個の0,g[N_output_start],...,g[N_output_lim])
// に置き換える。
template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent );

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を逆高速フーリエ変換したものをgと置き、
// fの係数列を長さN_input_start + two_powerの配列
// (f[0],...,f[N_input_start - 1],,g[0],...,g[two_power - 1])
// に置き換える。
template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const T& two_power_inv , const uint& exponent );

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を逆高速フーリエ変換したものをgと置き、
// fの係数列を長さN_input_start + N_output_limの配列
// (f[0],...,f[N_input_start - 1],N_output_shift個の0,g[N_output_start],...,g[N_output_lim])
// に置き換える。
template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const T& two_power_inv , const uint& exponent );

// 長さtwo_power = 2 ^ { exponent }の配列
// (f[N_input_start],...,f[N_input_lim - 1],0,...)
// を高速フーリエ変換したものをgと置き、
// fの係数列を長さN_input_start + two_powerの配列
// (f[0],...,f[N_input_start - 1],N_output_start個の0,g[N_output_start],...,g[N_output_lim - 1],0,...)
// に置き換える。
template <typename T>
void CooleyTukey( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent , const T ( &PRT )[LimitOfPowerForFFT<T>] );
