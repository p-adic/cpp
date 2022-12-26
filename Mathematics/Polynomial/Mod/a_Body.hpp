// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "../../Analysis/FFT/a_Body.hpp"
// 0èúéZÇÃó·äOèàóù
#include "../../../Error/IllegalImput/a_Body.hpp"

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N ) : Polynomial<T>() , m_N( N ) { Polynomial<T>::m_f.reserve( m_N ); }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const TruncatedPolynomial<T>& f ) : Polynomial<T>( f ) , m_N( f.m_N ) { Polynomial<T>::m_f.reserve( m_N ); }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( TruncatedPolynomial<T>&& f ) : Polynomial<T>( move( f ) ) , m_N( move( f.m_N ) ) { Polynomial<T>::m_f.reserve( m_N ); }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const T& t ) : Polynomial<T>( t ) , m_N( N ) { Polynomial<T>::m_f.reserve( m_N ); }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const Polynomial<T>& f ) : Polynomial<T>() , m_N( N ) { Polynomial<T>::m_size = f.Polynomial<T>::m_size < m_N ? f.Polynomial<T>::m_size : m_N; Polynomial<T>::m_f = vector<T>( Polynomial<T>::m_size ); for( uint i = 0 ; i < Polynomial<T>::m_size ; i++ ){ Polynomial<T>::m_f[i] = f.Polynomial<T>::m_f[i]; } Polynomial<T>::m_f.reserve( m_N ); }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , Polynomial<T>&& f ) : Polynomial<T>() , m_N( N ) { if( f.Polynomial<T>::m_size < m_N * 2 ){ Polynomial<T>::operator=( move( f ) ); if( f.Polynomial<T>::m_size < m_N ){ Polynomial<T>::m_f.reserve( m_N ); } else { TruncateFinal( m_N ); } } else { Polynomial<T>::m_f = vector<T>( m_N ); for( uint i = 0 ; i < m_N ; i++ ){ Polynomial<T>::m_f[i] = move( f.Polynomial<T>::m_f[i] ); } Polynomial<T>::m_size = m_N; } }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const uint& i , const T& t ) : Polynomial<T>() , m_N( N ) { if( i < m_N ? t != Polynomial<T>::const_zero() : false ){ Polynomial<T>::operator[]( i ) = t; } Polynomial<T>::m_f.reserve( m_N ); }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , vector<T>&& f ) : Polynomial<T>() , m_N( N ) { const uint f_size = f.size(); if( f_size < m_N * 2 ){ Polynomial<T>::operator=( move( f ) ); if( f_size < m_N ){ Polynomial<T>::m_f.reserve( m_N ); } else { TruncateFinal( m_N ); } } else { Polynomial<T>::m_f = vector<T>( m_N ); for( uint i = 0 ; i < m_N ; i++ ){ Polynomial<T>::m_f[i] = move( f[i] ); } Polynomial<T>::m_f.reserve( m_N ); } }


template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const TruncatedPolynomial<T>& f ) { Polynomial<T>::operator=( f ); m_N = f.m_N; Polynomial<T>::m_f.reserve( m_N ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( TruncatedPolynomial<T>&& f ) { Polynomial<T>::operator=( move( f ) ); m_N = move( f.m_N ); Polynomial<T>::m_f.reserve( m_N ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const T& t ) { Polynomial<T>::operator=( t ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const Polynomial<T>& f ) { return operator=( TruncatedPolynomial<T>( m_N , f ) ); }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( Polynomial<T>&& f ) { return operator=( TruncatedPolynomial<T>( m_N , move( f ) ) ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const T& t ) { Polynomial<T>::operator+=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const Polynomial<T>& f ) { return TruncatedPolynomial<T>::TruncatedPlus( f , 0 , f.m_size ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const TruncatedPolynomial<T>& f ) { return m_N == 0 ? operator=( f ) : TruncatedPolynomial<T>::TruncatedPlus( f , 0 , f.Polynomial<T>::m_size ); }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncatedPlus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_limit )
{

  const uint& size = N_input_limit < m_N ? N_input_limit < f.Polynomial<T>::m_size ? N_input_limit : f.Polynomial<T>::m_size : m_N < f.Polynomial<T>::m_size ? m_N : f.Polynomial<T>::m_size;
  
  if( Polynomial<T>::m_size < size ){

    Polynomial<T>::m_f.reserve( size );

    for( uint i = N_input_start ; i < Polynomial<T>::m_size ; i++ ){

      Polynomial<T>::m_f[i] += f.Polynomial<T>::m_f[i];

    }

    for( uint i = Polynomial<T>::m_size ; i < size ; i++ ){
    
      Polynomial<T>::m_f.push_back( f.Polynomial<T>::m_f[i] );

    }

    Polynomial<T>::m_size = size;
    
  } else {

    for( uint i = N_input_start ; i < size ; i++ ){

      Polynomial<T>::m_f[i] += f.Polynomial<T>::m_f[i];

    }

  }
  
  return *this;

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const T& t ) { Polynomial<T>::operator-=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const Polynomial<T>& f ) { return TruncatedPolynomial<T>::TruncatedMinus( f , 0 , f.m_size ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator-=( const TruncatedPolynomial<T>& f ) { return m_N == 0 ? operator=( -f ) : TruncatedPolynomial<T>::TruncatedMinus( f , 0 , f.Polynomial<T>::m_size ); }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncatedMinus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_limit )
{

  const uint& size = N_input_limit < m_N ? N_input_limit < f.Polynomial<T>::m_size ? N_input_limit : f.Polynomial<T>::m_size : m_N < f.Polynomial<T>::m_size ? m_N : f.Polynomial<T>::m_size;

  if( Polynomial<T>::m_size < size ){

    Polynomial<T>::m_f.reserve( size );

    for( uint i = N_input_start ; i < Polynomial<T>::m_size ; i++ ){

      Polynomial<T>::m_f[i] -= f.Polynomial<T>::m_f[i];

    }

    for( uint i = Polynomial<T>::m_size ; i < size ; i++ ){
    
      Polynomial<T>::m_f.push_back( - f.Polynomial<T>::m_f[i] );

    }

    Polynomial<T>::m_size = size;
    
  } else {

    for( uint i = N_input_start ; i < size ; i++ ){

      Polynomial<T>::m_f[i] -= f.Polynomial<T>::m_f[i];

    }

  }

  return *this;

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const T& t ) { Polynomial<T>::operator*=( t ); return *this; }

// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 0 , 0 , 1 , 0 , 1 );
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 1 , 1 , 2 , 1 , 499122176 );
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 2 , 2 , 4 , 2 , 748683265 );

// intå^ìôÇÃconstéQè∆ÇäOÇµÇΩèÍçáÇÃÇRÇ¬ÇÃÉAÉãÉSÉäÉYÉÄÇÃç≈ìKï™äÚ
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 4 , 4 , 8 , 3 , 873463809 );

// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 8 , 8 , 16 , 4 , 935854081 );
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 16 , 16 , 32 , 3 , 967049217 );

// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 128 , 256 , 8 , 994344961 ); // 12.954 -- 13.215
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 256 , 512 , 9 , 996294657 ); // 12.939 -- 13.284

// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 15 , 512 , 1024 , 10 , 997269505 ); // 13.039 -- 13.270
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 16 , 512 , 1024 , 10 , 997269505 ); // 13.252 -- 13.393

// intå^ìôÇÃconstéQè∆ÇäOÇ≥Ç»Ç¢èÍçáÇÃÇRÇ¬ÇÃÉAÉãÉSÉäÉYÉÄÇÃç≈ìKï™äÚ
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 512 , 1024 , 10 , 997269505 ); // 12.886 -- 12.987

// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 18 , 512 , 1024 , 10 , 997269505 ); // 12.888 -- 12.985
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 19 , 512 , 1024 , 10 , 997269505 ); // 13.048 -- 13.063
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 20 , 512 , 1024 , 10 , 997269505 ); // 12.905 -- 13.138
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 21 , 512 , 1024 , 10 , 997269505 ); // 13.150 -- 13.337

// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 1024 , 2048 , 11 , 997756929 ); // 14.297 -- 15.765
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 2048 , 4096 , 12 , 998000641 ); // 12.902 -- 13.265
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 4096 , 8192 , 13 , 998122497 ); // 13.799 -- 14.025
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 8192 , 16384 , 14 , 998183425 );
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 16384 , 32768 , 15 , 998213889 );
// DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( Mod<998244353> , 17 , 32768 , 65536 , 16 , 998229121 );

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const Polynomial<T>& f )
{

  constexpr const uint border_0 = 21;
  const T& zero = Polynomial<T>::const_zero();
  bool searching = true;

  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){

    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( f.Polynomial<T>::m_size == 0 );
    DEFINITION_0_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;

  } else {

    DEFINITION_1_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( searching );
    DEFINITION_2_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    const uint N_output_lim_fixed = N_input_max_0_max_1 < m_N ? N_input_max_0_max_1 + 1 : m_N;
    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= m_N );
    DEFINITION_3_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;

  }

  return *this;

}

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::FFT_Multiplication( const Polynomial<T>& f )
{

  constexpr const uint& border_0 = FFT_Multiplication_border_0<T>;
  const T& zero = Polynomial<T>::const_zero();
  bool searching = true;

  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){

    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( f.Polynomial<T>::m_size == 0 );
    DEFINITION_0_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    
  } else {

    DEFINITION_1_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( searching );
    DEFINITION_2_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    const uint N_output_lim_fixed = N_input_max_0_max_1 < m_N ? N_input_max_0_max_1 + 1 : m_N;
    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed );
    const uint N_input_truncated_deg_0_deg_1 = N_input_max_0 - N_input_start_0 + N_input_max_1 - N_input_start_1;
    constexpr const uint& border_1 = FFT_Multiplication_border_1<T>;

    if( N_input_truncated_deg_0_deg_1 < border_1 ){
    
      DEFINITION_3_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    
    } else {

      DEFINITION_4_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
      Polynomial<T>::m_f = IFFT<T>( f0 , 0 , two_power , 0 , 0 , N_output_lim_fixed - N_input_start_0_start_1 , N_input_start_0_start_1 , two_power , two_power_inv , exponent );
      Polynomial<T>::m_size = Polynomial<T>::m_f.size();

    }

  }
  
  return *this;

}

template <typename T> 
TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim )
{

  constexpr const uint border_0 = 21;
  const T& zero = Polynomial<T>::const_zero();
  bool searching = true;

  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){

    DEFINITION_0_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    
  } else {

    DEFINITION_1_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    DEFINITION_2_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    uint N_output_lim_fixed = N_input_max_0_max_1 < m_N ? N_input_max_0_max_1 + 1 : m_N;

    if( N_output_lim_fixed > N_output_lim ){

      N_output_lim_fixed = N_output_lim;
    
    }
  
    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed );
    DEFINITION_3_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;

  }

  return *this;

}

template <typename T> 
TruncatedPolynomial<T>& TruncatedPolynomial<T>::FFT_TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim )
{

  constexpr const uint& border_0 = FFT_Multiplication_border_0<T>;
  const T& zero = Polynomial<T>::const_zero();
  bool searching = true;

  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){

    DEFINITION_0_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    
  } else {

    DEFINITION_1_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    DEFINITION_2_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    uint N_output_lim_fixed = N_input_max_0_max_1 < m_N ? N_input_max_0_max_1 + 1 : m_N;

    if( N_output_lim_fixed > N_output_lim ){

      N_output_lim_fixed = N_output_lim;
    
    }
  
    RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed );
    const uint N_input_truncated_deg_0_deg_1 = N_input_max_0 - N_input_start_0 + N_input_max_1 - N_input_start_1;
    constexpr const uint& border_1 = FFT_Multiplication_border_1<T>;

    if( N_input_truncated_deg_0_deg_1 < border_1 ){
    
      DEFINITION_3_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
    
    } else {

      DEFINITION_4_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL;
      uint N_output_start_shifted;
      uint N_output_shift_shifted;

      if( N_output_start < N_input_start_0_start_1 ){

	N_output_start_shifted = 0;
	N_output_shift_shifted = N_input_start_0_start_1;

      } else {
    
	N_output_start_shifted = N_output_start - N_input_start_0_start_1;
	N_output_shift_shifted = N_output_start;

      }

      const uint N_output_lim_shifted = N_output_lim_fixed - N_input_start_0_start_1;
      f0 = IFFT<T>( f0 , 0 , two_power , 0 , N_output_start_shifted , N_output_lim_shifted , N_output_shift_shifted , two_power , two_power_inv , exponent );
      SET_VECTOR_FOR_ANSWER_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( N_output_lim_fixed );

      for( uint i = N_output_start ; i < N_output_lim_fixed ; i++ ){
    
	Polynomial<T>::m_f[i] = f0[i];

      }

    }

  }

  return *this;
  
}

template <typename T> 
TruncatedPolynomial<T> TruncatedPolynomial<T>::TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const
{

  constexpr const uint border_0 = 21;
  const T& zero = Polynomial<T>::const_zero();
  bool searching = true;

  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){

    DEFINITION_0_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
    return TruncatedPolynomial<T>( m_N , move( answer ) );
    
  }

  DEFINITION_1_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
  DEFINITION_2_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
  uint N_output_lim_fixed = N_input_max_0_max_1 < m_N ? N_input_max_0_max_1 + 1 : m_N;

  if( N_output_lim_fixed > N_output_lim ){

    N_output_lim_fixed = N_output_lim;
    
  }
  
  RETURN_ZERO_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed );
  DEFINITION_3_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
  return TruncatedPolynomial<T>( m_N , move( answer ) );
  
}

template <typename T> 
TruncatedPolynomial<T> TruncatedPolynomial<T>::FFT_TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const
{

  constexpr const uint& border_0 = FFT_Multiplication_border_0<T>;
  const T& zero = Polynomial<T>::const_zero();
  bool searching = true;

  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){

    DEFINITION_0_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
    return TruncatedPolynomial<T>( m_N , move( answer ) );
    
  }

  DEFINITION_1_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
  DEFINITION_2_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
  uint N_output_lim_fixed = N_input_max_0_max_1 < m_N ? N_input_max_0_max_1 + 1 : m_N;

  if( N_output_lim_fixed > N_output_lim ){

    N_output_lim_fixed = N_output_lim;
    
  }
  
  RETURN_ZERO_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed );
  const uint N_input_truncated_deg_0_deg_1 = N_input_max_0 - N_input_start_0 + N_input_max_1 - N_input_start_1;
  constexpr const uint& border_1 = FFT_Multiplication_border_1<T>;

  if( N_input_truncated_deg_0_deg_1 < border_1 ){
    
    DEFINITION_3_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
    return TruncatedPolynomial<T>( m_N , move( answer ) );
    
  }

  DEFINITION_4_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL;
  uint N_output_start_shifted;
  uint N_output_shift_shifted;

  if( N_output_start < N_input_start_0_start_1 ){

    N_output_start_shifted = 0;
    N_output_shift_shifted = N_input_start_0_start_1;

  } else {
    
    N_output_start_shifted = N_output_start - N_input_start_0_start_1;
    N_output_shift_shifted = N_output_start;

  }

  const uint N_output_lim_shifted = N_output_lim_fixed - N_input_start_0_start_1;
  return TruncatedPolynomial<T>( m_N , IFFT<T>( f0 , 0 , two_power , 0 , N_output_start_shifted , N_output_lim_shifted , N_output_shift_shifted , two_power , two_power_inv , exponent ) );

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const T& t ) { Polynomial<T>::operator/=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const TruncatedPolynomial<T>& f ) { return operator*=( Inverse( m_N > f.m_N ? f : TruncatedPolynomial<T>( m_N , f ) ) ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator%=( const T& t ) { Polynomial<T>::operator%=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T> TruncatedPolynomial<T>::operator-() const { return move( TruncatedPolynomial<T>( m_N ) -= *this ); }


template <typename T> inline void TruncatedPolynomial<T>::SetTruncation( const UINT& N ) noexcept { if( N < m_N ){ TruncateFinal( m_N ); } else { Polynomial<T>::m_f.reserve( N ); } m_N = N; }
template <typename T> inline const uint& TruncatedPolynomial<T>::GetTruncation() const noexcept { return m_N; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncateInitial( const uint& N ) noexcept { const uint& size = N < Polynomial<T>::m_size ? N : Polynomial<T>::m_size; for( uint i = 0 ; i < size ; i++ ){ Polynomial<T>::m_f[i] = 0; } return *this; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncateFinal( const uint& N ) noexcept { while( Polynomial<T>::m_size > N ){ Polynomial<T>::m_f.pop_back(); Polynomial<T>::m_size--; } return *this; }

template <typename T , typename P> inline TruncatedPolynomial<T> operator+( const TruncatedPolynomial<T>& f0 , const P& f1 ) { return move( TruncatedPolynomial<T>( f0 ) += f1 ); }
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f ) { return move( TruncatedPolynomial<T>( f.GetTurncation() ) -= f ); }
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f0 , const P& f1 ) { return move( TruncatedPolynomial<T>( f0 ) -= f1 ); }
template <typename T , typename P> inline TruncatedPolynomial<T> operator*( const TruncatedPolynomial<T>& f0 , const P& f1 ) { return move( TruncatedPolynomial<T>( f0 ) *= f1 ); }
template <typename T , typename P> inline TruncatedPolynomial<T> operator/( const TruncatedPolynomial<T>& f0 , const P& f1 ) { return move( TruncatedPolynomial<T>( f0 ) /= f1 ); }
template <typename T> inline TruncatedPolynomial<T> operator%( const TruncatedPolynomial<T>& f0 , const T& t1 ) { return move( TruncatedPolynomial<T>( f0 ) %= t1 ); }


template <typename T> inline TruncatedPolynomial<T> Differential( const TruncatedPolynomial<T>& f ) { return TruncatedDifferential<T>( f , 1 ); }

template <typename T>
TruncatedPolynomial<T> Differential( const uint& n , const TruncatedPolynomial<T>& f )
{

  if( f.Polynomial<T>::m_size < n ){

    return TruncatedPolynomial( f.m_N - n , Polynomial<T>::zero() );

  }

  vector<T> df( f.Polynomial<T>::m_size - n );
  T coef = Polynomial<T>::factorial( n );
  uint i = n;

  while( i < f.Polynomial<T>::m_size ){

    df[i - n] = f[i] * coef;
    i++;
    ( coef *= i ) /= ( i - n );

  }

  return TruncatedPolynomial( f.m_N - n , move( df ) );

}

template <typename T>
TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one )
{

  if( f.m_N == 0 ){

    ERR_IMPUT( f , f.m_N );

  }

  TruncatedPolynomial<T> f_dif{ f.m_N - 1 };

  if( N_output_start_plus_one < f.Polynomial<T>::m_size ){

    const uint size = f.Polynomial<T>::m_size - 1;
    f_dif.Polynomial<T>::m_f = vector<T>( size );

    for( uint i = N_output_start_plus_one ; i < f.Polynomial<T>::m_size ; i++ ){

      f_dif.Polynomial<T>::m_f[i-1] = i * f.Polynomial<T>::m_f[i];

    }

    f_dif.Polynomial<T>::m_size = size;

  }

  return f_dif;

}

template <typename T> inline TruncatedPolynomial<T> Integral( const TruncatedPolynomial<T>& f ) { return TruncatedIntegral<T>( f , 1 ); }

template <typename T>
TruncatedPolynomial<T> TruncatedIntegral( const TruncatedPolynomial<T>& f , const uint& N_output_start )
{

  TruncatedPolynomial<T> f_int{ f.m_N + 1 };

  if( N_output_start <= f.Polynomial<T>::m_size ){

    const uint size = f.Polynomial<T>::m_size + 1;
    f_int.Polynomial<T>::m_f = vector<T>( size );
    
    for( uint i = N_output_start ; i <= f.Polynomial<T>::m_size ; i++ ){

      f_int.Polynomial<T>::m_f[i] = f.Polynomial<T>::m_f[i - 1] / T( i );

    }

    f_int.Polynomial<T>::m_size = size;
    
  }

  return f_int;

}

template <typename T>
TruncatedPolynomial<T> Inverse( const TruncatedPolynomial<T>& f )
{

  DEFINITION_OF_INVERSE_FOR_TRUNCATED_POLYNOMIAL( T , f_inv.TruncatedMinus( f_inv.TruncatedMultiplication_const( f , power , power_2 ).TruncatedMultiplication( f_inv , power , power_2 ) , power , power_2 ) );
  
}

template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f )
{

  DEFINITION_OF_EXP_FOR_TRUNCATED_POLYNOMIAL( T , f_exp.TruncatedMinus( ( TruncatedIntegral( Differential( f_exp ).TruncatedMultiplication_const( Inverse( f_exp ) , power - 1 , power_2 ) , power ).TruncatedMinus( f , power , power_2 ) ).TruncatedMultiplication( f_exp , power ) , power , power_2 ) );
  
}

template <typename T> inline TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f ) { return Integral<T>( Differential<T>( f ) /= f ); }

template <typename T> inline TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t ) { return Exp( Log( f ) *= t ); }
