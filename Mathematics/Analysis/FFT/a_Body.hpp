// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Arithmetic/Mod/ConstexprModulo/Montgomery/a_Body.hpp"
#include "../../Arithmetic/Power/Constexpr/PowerPower/a_Body.hpp"


// 998244353 = 2^{23} * 7 * 17 + 1
// 167772161 = 2^{25} * 5 + 1
// 469762049 = 2^{26} * 7 + 1
// 754974721 = 2^{24} * 3^2 * 5 + 1
PARTIAL_SPECIALISATION_FOR_FFT( 998244353 , 24 , 4 , 31 , 128805723 );
PARTIAL_SPECIALISATION_FOR_FFT( 167772161 , 26 , 4 , 17 , 29606852 );
PARTIAL_SPECIALISATION_FOR_FFT( 469762049 , 27 , 4 , 30 , 15658735 );
PARTIAL_SPECIALISATION_FOR_FFT( 754974721 , 25 , 4 , 362 , 415027540 );

template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , 0 , two_power , two_power , exponent , PrimitiveRootOfTwoForFFT<T>() ); }
template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , N_output_start , N_output_lim , two_power , exponent , PrimitiveRootOfTwoForFFT<T>() ); }

template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const T& two_power_inv , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , 0 , two_power , two_power , exponent , InversePrimitiveRootOfTwoForFFT<T>() ); const uint size = two_power + N_input_start; for( uint i = N_input_start ; i < size ; i++ ){ f[i] *= two_power_inv; } }

template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const T& two_power_inv , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , N_output_start , N_output_lim , two_power , exponent , InversePrimitiveRootOfTwoForFFT<T>() ); const uint size = N_output_lim + N_input_start; for( uint i = N_output_start + N_input_start ; i < size ; i++ ){ f[i] *= two_power_inv; } }

template <typename T>
void CooleyTukey( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent , const T ( &PRT )[LimitOfPowerForFFT<T>] )
{

  const uint length = two_power + N_input_start + N_output_start;
  f.reserve( length );

  while( f.size() < length ){

    f.push_back( 0 );

  }

  // bit逆のメモ化（２回目以降の呼び出しを高速化するための非inplace処理）
  static vector<uint> bit_reverse[32] = { vector<uint>( 1 ) };
  static uint e_next = 1;
  static uint two_power_next = 1;
  static uint two_power_next2 = 2;
  static vector<uint>* p_bit_reverse_prev = bit_reverse;
  static vector<uint>* p_bit_reverse_curr = p_bit_reverse_prev + 1;

  while( e_next <= exponent ){

    *p_bit_reverse_curr = vector<uint>( two_power_next2 );
    uint* p_bit_reverse_curr_i = &( ( *p_bit_reverse_curr )[0] );
    uint* p_bit_reverse_curr_i_plus = p_bit_reverse_curr_i + two_power_next;
    uint* p_bit_reverse_prev_i = &( ( *p_bit_reverse_prev )[0] );
    
    for( uint i = 0 ; i < two_power_next ; i++ ){

      ( *( p_bit_reverse_curr_i_plus++ ) = *( p_bit_reverse_curr_i++ ) = *( p_bit_reverse_prev_i++ ) * 2 ) += 1;

    }

    e_next++;
    swap( two_power_next , two_power_next2 );
    two_power_next2 *= 4;
    p_bit_reverse_prev++;
    p_bit_reverse_curr++;

  }

  const vector<uint>& bit_reverse_exponent = bit_reverse[exponent];
  uint bit_num = 0;
  const uint* p_bit_num_reverse = &( bit_reverse_exponent[bit_num] );

  // bit逆順にfをソート
  while( bit_num < two_power ){
    
    if( *p_bit_num_reverse < bit_num ){

      swap( f[*p_bit_num_reverse + N_input_start] , f[bit_num + N_input_start] );

    }

    bit_num++;
    p_bit_num_reverse++;

  }
  
  uint two_power_curr = 1;
  uint two_power_curr_2 = 2;
  const T& zeta_0 = PRT[0];
  T zeta , diff;
  const T* p_zeta_i;
  uint bit_num_copy , i , j , j_butterfly , j_lim;
  
  // バタフライ演算
  while( two_power_curr < two_power ){

    bit_num = 0;
    i = 0;
    
    while( i < two_power ){

      zeta = zeta_0;
      p_zeta_i = &zeta_0 + 2;
      bit_num_copy = bit_num;

      // 1の羃根の計算
      // zeta[exponent]^{*p_bit_num_reverse = bit_num % 2^{exponent - 1}のbit_reverse}
      // = prod( uint i = 0 ; i < exponent - 1 ; i++ ) zeta[exponent]^[2^i * (*p_bit_num_reverseの2^iの位)]
      // = prod( uint i = 0 ; i < exponent - 1 ; i++ ) zeta[exponent - i]^{bit_numの2^{exponent - 2 - i}の位}
      // = prod( uint i = 2 ; i < exponent ; i++ ) zeta[i]^{bit_numの2^{i - 2}の位}
      while( bit_num_copy != 0 ){

	if( bit_num_copy % 2 == 1 ){

	  zeta *= *p_zeta_i;

	}

	bit_num_copy /= 2;
	p_zeta_i++;	
	
      }
      
      j = i;
      j_lim = i + two_power_curr;

      // バタフライルーチン
      while( j < j_lim ){

	j_butterfly = j + two_power_curr;
	T& f_j = f[j + N_input_start];
	T& f_j_butterfly = f[j_butterfly + N_input_start];
	diff = f_j - f_j_butterfly;
	f_j += f_j_butterfly;
	f_j_butterfly = zeta * diff;
	j++;
	
      }

      bit_num++;
      i += two_power_curr_2;
      
    }

    swap( two_power_curr , two_power_curr_2 );
    two_power_curr_2 *= 4;
    
  }

  const uint length_fixed = N_output_lim + N_input_start;

  while( f.size() > length_fixed ){

    f.pop_back();
    
  }

  for( uint i = 0 ; i < N_output_start ; i++ ){

    f[N_input_start + i] = 0;
    
  }

  return;

}
