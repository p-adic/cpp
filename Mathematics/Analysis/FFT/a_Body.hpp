// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Arithmetic/Mod/a_Body.hpp"

// 以下は"../../Arithmetic/Mod/a_Alias.hpp"内で
// using INT_TYPE_FOR_MOD = long long int;
// を選択している場合にのみ有効。
template <> inline constexpr const uint LimitOfPowerForFFT<Mod<998244353> > = 24;

// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 0; // 1.960 -- 2.014
// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 1; // 1.845 -- 1.994
// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 2; // 1.802 -- 1.809
// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 3; // 1.699 -- 1.746

// ２つのアルゴリズムの最適分岐
template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 4; // 1.694 -- 1.744

// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 5; // 1.805 -- 1.920
// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 6; // 2.237 -- 2.249
// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 7; // 3.195 -- 3.214
// template <> inline constexpr const uint BorderForFFT<Mod<998244353> > = 8; // 5.249 -- 5.518

template <> inline const Mod<998244353> ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Mod<998244353> >]
{

  static const Mod<998244353> PRT[ LimitOfPowerForFFT<Mod<998244353> > ] =
    {
      
      Mod<998244353>( 1 ) ,
      Mod<998244353>( 998244352 ) ,
      Mod<998244353>( 911660635 ) ,
      Mod<998244353>( 625715529 ) ,
      Mod<998244353>( 373294451 ) ,
      Mod<998244353>( 827987769 ) ,
      Mod<998244353>( 280333251 ) ,
      Mod<998244353>( 581015842 ) ,
      Mod<998244353>( 628092333 ) ,
      Mod<998244353>( 300892551 ) ,
      Mod<998244353>( 586046298 ) ,
      Mod<998244353>( 615001099 ) ,
      Mod<998244353>( 318017948 ) ,
      Mod<998244353>( 64341522 ) ,
      Mod<998244353>( 106061068 ) ,
      Mod<998244353>( 304605202 ) ,
      Mod<998244353>( 631920086 ) ,
      Mod<998244353>( 857779016 ) ,
      Mod<998244353>( 841431251 ) ,
      Mod<998244353>( 805775211 ) ,
      Mod<998244353>( 390359979 ) ,
      Mod<998244353>( 923521 ) ,
      Mod<998244353>( 961 ) ,
      Mod<998244353>( 31 )

    };

  return PRT;

}

template <> inline const Mod<998244353> ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Mod<998244353> >]
{

  static const Mod<998244353> PRT[ LimitOfPowerForFFT<Mod<998244353> > ] =
    {
      
      Mod<998244353>( 1 ) ,
      Mod<998244353>( 998244352 ) ,
      Mod<998244353>( 86583718 ) ,
      Mod<998244353>( 488723995 ) ,
      Mod<998244353>( 369330050 ) ,
      Mod<998244353>( 543653592 ) ,
      Mod<998244353>( 382946991 ) ,
      Mod<998244353>( 844956623 ) ,
      Mod<998244353>( 91420391 ) ,
      Mod<998244353>( 433414612 ) ,
      Mod<998244353>( 288894979 ) ,
      Mod<998244353>( 260490556 ) ,
      Mod<998244353>( 857007890 ) ,
      Mod<998244353>( 736054570 ) ,
      Mod<998244353>( 474649464 ) ,
      Mod<998244353>( 948509906 ) ,
      Mod<998244353>( 114942468 ) ,
      Mod<998244353>( 962405921 ) ,
      Mod<998244353>( 667573957 ) ,
      Mod<998244353>( 46809892 ) ,
      Mod<998244353>( 304321983 ) ,
      Mod<998244353>( 30429817 ) ,
      Mod<998244353>( 293967900 ) ,
      Mod<998244353>( 128805723 )

    };

  return PRT;

}

template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , 0 , two_power , two_power , exponent , PrimitiveRootOfTwoForFFT<T>() ); }
template <typename T> inline void FFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , N_output_start , N_output_lim , two_power , exponent , PrimitiveRootOfTwoForFFT<T>() ); }

template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& two_power , const T& two_power_inv , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , 0 , two_power , two_power , exponent , InversePrimitiveRootOfTwoForFFT<T>() ); const uint size = two_power + N_input_start; for( uint i = N_input_start ; i < size ; i++ ){ f[i] *= two_power_inv; } }

template <typename T> inline void IFFT( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const T& two_power_inv , const uint& exponent ) { CooleyTukey<T>( f , N_input_start , N_input_lim , N_output_start , N_output_lim , two_power , exponent , InversePrimitiveRootOfTwoForFFT<T>() ); const uint size = N_output_lim + N_input_start; for( uint i = N_output_start + N_input_start ; i < size ; i++ ){ f[i] *= two_power_inv; } }

template <typename T>
void CooleyTukey( vector<T>& f , const uint& N_input_start , const uint& N_input_lim , const uint& N_output_start , const uint& N_output_lim , const uint& two_power , const uint& exponent , const T ( &PRT )[LimitOfPowerForFFT<T>] )
{

  const uint length = two_power + N_input_start;
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
	T& f_j = f[j];
	T& f_j_butterfly = f[j_butterfly];
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
  
  return;

}
