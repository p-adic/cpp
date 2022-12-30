// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Macro.hpp

#pragma once

#define RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( CONDITION )	\
  if( CONDITION ){							\
									\
    return operator=( zero );						\
									\
  }									\
									\


#define RETURN_ZERO_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL_IF( CONDITION ) \
  if( CONDITION ){							\
									\
    return TruncatedPolynomial<T>( m_N );				\
									\
  }									\
									\

#define RETURN_ZERO_FOR__FOR_TRUNCATED_POLYNOMIAL_IF( MULTIPLICATION , CONDITION ) \
  RETURN_ZERO_FOR_ ## MULTIPLICATION ## _FOR_TRUNCATED_POLYNOMIAL_IF( CONDITION )	\


#define SET_VECTOR_FOR_ANSWER_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( N_OUTPUT_LIM ) \
  if( Polynomial<T>::m_size < N_OUTPUT_LIM ){				\
									\
    for( uint i = Polynomial<T>::m_size ; i < N_OUTPUT_LIM ; i++ ){	\
									\
      Polynomial<T>::m_f.push_back( 0 );				\
      									\
    }									\
    									\
    Polynomial<T>::m_size = N_OUTPUT_LIM;				\
    									\
  }									\


#define SET_VECTOR_FOR_ANSWER_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL( N_OUTPUT_LIM ) \
  vector<T> answer( N_OUTPUT_LIM )					\


#define SET_VECTOR_FOR_ANSWER_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , N_OUTPUT_LIM ) \
  SET_VECTOR_FOR_ANSWER_OF_ ## MULTIPLICATION ## _FOR_TRUNCATED_POLYNOMIAL( N_OUTPUT_LIM ) \

#define SET_SUM_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL	\
  Polynomial<T>::m_f[i] = sum					\


#define SET_SUM_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL \
  answer[i] = sum							\


#define SET_SUM_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION )	\
  SET_SUM_OF_ ## MULTIPLICATION ## _FOR_TRUNCATED_POLYNOMIAL	\


#define SET_N_INPUT_START_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( F , SIZE , N_INPUT_START_NUM ) \
  uint N_INPUT_START_NUM;						\
									\
  for( uint i = 0 ; i < SIZE && searching ; i++ ){			\
									\
    if( F[i] != zero ){							\
									\
      N_INPUT_START_NUM = i;						\
      searching = false;						\
									\
    }									\
									\
  }									\
									\


#define SET_N_INPUT_MAX_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( F , SIZE , N_INPUT_MAX_NUM ) \
  uint N_INPUT_MAX_NUM;							\
  searching = true;							\
									\
  for( uint i = ( SIZE ) - 1 ; searching ; i-- ){			\
									\
    if( F[i] != zero ){							\
									\
      N_INPUT_MAX_NUM = i;						\
      searching = false;						\
									\
    }									\
									\
  }									\
									\


#define CONVOLUTION_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( J_MIN ) \
  const uint j_max = i < N_input_max_0_start_1 ? i - N_input_start_1 : N_input_max_0; \
  T sum{ zero };							\
									\
  for( uint j = J_MIN ; j <= j_max ; j++ ){				\
									\
    sum += Polynomial<T>::m_f[j] * f.Polynomial<T>::m_f[i - j];		\
									\
  }									\
									\
  Polynomial<T>::m_f[i] = sum;						\
									\


#define CONVOLUTION_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL( J_MIN ) \
  const uint j_max = i < N_input_max_0_start_1 ? i - N_input_start_1 : N_input_max_0; \
  T& m_fi = answer[i]; \
									\
  for( uint j = J_MIN ; j <= j_max ; j++ ){				\
									\
    m_fi += Polynomial<T>::m_f[j] * f.Polynomial<T>::m_f[i - j];	\
									\
  }									\
									\


#define CONVOLUTION_FOR__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , J_MIN ) \
  CONVOLUTION_FOR_ ## MULTIPLICATION ## _FOR_TRUNCATED_POLYNOMIAL( J_MIN ) \


#define ZEROIFICATION_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL	\
  for( uint i = 0 ; i < N_input_start_0_start_1 ; i++ ){		\
									\
    Polynomial<T>::m_f[i] = 0;						\
									\
  }									\


#define ZEROIFICATION_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL \
  const uint& N_output_start_fixed = N_output_start < N_input_start_0_start_1 ? N_output_start : N_input_start_0_start_1; \
  									\
  for( uint i = 0 ; i < N_output_start_fixed ; i++ ){			\
									\
    answer[i] = 0;							\
									\
  }									\


#define ZEROIFICATION_FOR__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION )	\
  ZEROIFICATION_FOR_ ## MULTIPLICATION ## _FOR_TRUNCATED_POLYNOMIAL	\


#define DEFINITION_0_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , ACCESS_ENTRY , N_OUTPUT_START ) \
  RETURN_ZERO_FOR__FOR_TRUNCATED_POLYNOMIAL_IF( MULTIPLICATION , Polynomial<T>::m_size == 0 ); \
  uint N_output_max = Polynomial<T>::m_size + f.Polynomial<T>::m_size - 2; \
									\
  if( N_output_max >= m_N ){						\
									\
    N_output_max = m_N - 1;						\
									\
  }									\
									\
  const uint N_output_lim = N_output_max + 1;				\
  SET_VECTOR_FOR_ANSWER_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , N_output_lim ); \
									\
  for( uint i = N_output_max ; searching ; i-- ){			\
									\
    T sum{ zero };							\
									\
    for( uint j = 0 ; j <= i ; j++ ){					\
									\
      sum += ACCESS_ENTRY * f.Polynomial<T>::operator[]( i - j );	\
									\
    }									\
									\
    SET_SUM_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION );		\
    searching = i > N_OUTPUT_START;					\
									\
  }									\
  									\


#define DEFINITION_1_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION ) \
  SET_N_INPUT_START_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( Polynomial<T>::m_f , Polynomial<T>::m_size , N_input_start_0 ); \
  RETURN_ZERO_FOR__FOR_TRUNCATED_POLYNOMIAL_IF( MULTIPLICATION , searching ); \
  searching = true;							\
  SET_N_INPUT_START_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( f , f.Polynomial<T>::m_size , N_input_start_1 ); \
									\



#define SET_N_INPUT_RANGE						\
  SET_N_INPUT_MAX_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( Polynomial<T>::m_f , Polynomial<T>::m_size , N_input_max_0 ); \
  SET_N_INPUT_MAX_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( f , f.Polynomial<T>::m_size < m_N ? f.Polynomial<T>::m_size : m_N , N_input_max_1 ); \
  const uint N_input_max_0_max_1 = N_input_max_0 + N_input_max_1;	\
  const uint N_input_start_0_start_1 = N_input_start_0 + N_input_start_1; \
  uint N_output_lim_fixed = N_input_max_0_max_1 < m_N ? N_input_max_0_max_1 + 1 : m_N; \


#define DEFINITION_3_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION )	\
  const uint N_input_start_0_max_1 = N_input_start_0 + N_input_max_1;	\
  const uint N_input_max_0_start_1 = N_input_max_0 + N_input_start_1;	\
  const uint N_output_max_fixed = N_output_lim_fixed - 1;		\
  SET_VECTOR_FOR_ANSWER_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , N_output_lim_fixed ); \
  									\
  for( uint i = N_output_max_fixed ; i > N_input_start_0_max_1 ; i-- ){	\
									\
    CONVOLUTION_FOR__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , i - N_input_max_1 ); \
									\
  }									\
									\
  searching = true;							\
									\
  for( uint i = N_input_start_0_max_1 < N_output_max_fixed ? N_input_start_0_max_1 : N_output_max_fixed ; searching ; i-- ){ \
									\
    CONVOLUTION_FOR__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , N_input_start_0 ); \
    searching = i > N_input_start_0_start_1;				\
									\
  }									\
									\
  ZEROIFICATION_FOR__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION );	\
									\



#define SET_SHIFTED_VECTOR_FOR_MULTIPLICATION( V , F , I_START , I_MAX , I_SHIFT ) \
  vector<T> V( product_length );					\
									\
  for( uint i = I_START ; i <= I_MAX ; i++ ){			\
									\
    V[I_SHIFT + i] = F[i];						\
									\
  }									\



#define DEFINITION_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( RETURN_LINE_0 , RETURN_LINE_1 , RETURN_LINE_2 , RETURN_LINE_3 , RETURN_LINE_4 , MULTIPLICATION , ACCESS_ENTRY , N_OUTPUT_START , FIX_N_OUTPUT_LIM ) \
  constexpr const uint& border_0 = FFT_Multiplication_border_0<T>;	\
  const T& zero = Polynomial<T>::const_zero();				\
  bool searching = true;						\
									\
  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){ \
									\
    RETURN_LINE_0;							\
    DEFINITION_0_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , ACCESS_ENTRY , N_OUTPUT_START ); \
    RETURN_LINE_1;							\
									\
  }									\
									\
  DEFINITION_1_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION );		\
  RETURN_LINE_2;							\
  SET_N_INPUT_RANGE;							\
  FIX_N_OUTPUT_LIM;							\
  RETURN_LINE_3;							\
  DEFINITION_3_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION );		\
  RETURN_LINE_4;							\



#define DEFINITION_OF_FFT_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( RETURN_LINE_0 , RETURN_LINE_1 , RETURN_LINE_2 , RETURN_LINE_3 , RETURN_LINE_4 , RETURN_LINE_5 , MULTIPLICATION , ACCESS_ENTRY , N_OUTPUT_START , N_OUTPUT_START_SHIFTED , FIX_N_OUTPUT_LIM , DECLARATION_OF_F0 , N_INPUT_START_0 , N_INPUT_LIM_0 , DECLARATION_OF_F1 , N_INPUT_START_1 , N_INPUT_LIM_1 , VECTOR_FOR_IFFT , RESIZE_VECTOR_FOR_IFFT , I_START , MULTIPLICATiON_FORMULA , SET_ANSWER ) \
  constexpr const uint& border_0 = FFT_Multiplication_border_0<T>;	\
  const T& zero = Polynomial<T>::const_zero();				\
  bool searching = true;						\
									\
  if( Polynomial<T>::m_size < border_0 && f.Polynomial<T>::m_size < border_0 ){ \
									\
    RETURN_LINE_0;							\
    DEFINITION_0_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , ACCESS_ENTRY , N_OUTPUT_START ); \
    RETURN_LINE_1;							\
									\
  }									\
									\
  DEFINITION_1_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION );		\
  RETURN_LINE_2;							\
  SET_N_INPUT_RANGE;							\
  FIX_N_OUTPUT_LIM;							\
  RETURN_LINE_3;							\
  const uint N_input_truncated_deg_0_deg_1 = N_input_max_0 - N_input_start_0 + N_input_max_1 - N_input_start_1; \
  constexpr const uint& border_1 = FFT_Multiplication_border_1<T>;	\
									\
  if( N_input_truncated_deg_0_deg_1 < border_1 ){			\
									\
    DEFINITION_3_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION );	\
    RETURN_LINE_4;							\
									\
  }									\
									\
  uint two_power = FFT_Multiplication_border_1_2<T>;			\
  uint exponent = FFT_Multiplication_border_1_2_exponent<T>;		\
  T two_power_inv{ FFT_Multiplication_border_1_2_inv<T> };		\
									\
  while( N_input_truncated_deg_0_deg_1 >= two_power ){			\
									\
    two_power *= 2;							\
    two_power_inv /= 2;							\
    exponent++;								\
									\
  }									\
									\
  const uint product_length = N_input_start_0_start_1 + two_power;	\
  DECLARATION_OF_F0;							\
  FFT<T>( f0 , N_INPUT_START_0 , N_INPUT_LIM_0 , two_power , exponent ); \
  DECLARATION_OF_F1;							\
  FFT<T>( f1 , N_INPUT_START_1 , N_INPUT_LIM_1 , two_power , exponent ); \
  RESIZE_VECTOR_FOR_IFFT;						\
									\
  for( uint i = I_START + two_power - 1 ; true ; i-- ){				\
									\
    MULTIPLICATiON_FORMULA;						\
									\
    if( i == I_START ){							\
									\
      break;								\
									\
    }									\
									\
  }									\
									\
  const uint N_output_start_shifted = N_OUTPUT_START_SHIFTED;		\
  const uint N_output_lim_shifted = N_output_lim_fixed - N_input_start_0_start_1; \
  IFFT<T>( VECTOR_FOR_IFFT , N_input_start_0_start_1 , product_length , N_output_start_shifted , N_output_lim_shifted , two_power , two_power_inv , exponent ); \
  SET_ANSWER;								\
  RETURN_LINE_5;							\


#define DEFINITION_OF_INVERSE_FOR_TRUNCATED_POLYNOMIAL( TYPE , RECURSION ) \
  const uint& N = f.GetTruncation();					\
  uint power;								\
  uint power_2 = 1;							\
  TruncatedPolynomial< TYPE > f_inv{ power_2 , Polynomial< TYPE >::const_one() / f[0] }; \
									\
  while( power_2 < N ){							\
  									\
    power = power_2;							\
    power_2 *= 2;							\
    f_inv.SetTruncation( power_2 );					\
    RECURSION;								\
									\
  }									\
									\
  f_inv.SetTruncation( N );						\
  return f_inv							\
									\



#define DEFINITION_OF_EXP_FOR_TRUNCATED_POLYNOMIAL( TYPE , RECURSION )	\
  const uint& N = f.GetTruncation();					\
  uint power;								\
  uint power_2 = 1;							\
  TruncatedPolynomial< TYPE > f_exp{ power_2 , Polynomial< TYPE >::const_one() }; \
									\
  while( power_2 < N ){							\
  									\
    power = power_2;							\
    power_2 *= 2;							\
    f_exp.SetTruncation( power_2 );					\
    RECURSION;								\
									\
  }									\
									\
  f_exp.SetTruncation( N );						\
  return f_exp							\
									\


#define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( TYPE , BORDER_0 , BORDER_1 , BORDER_1_2 , BORDER_1_2_EXPONENT , BORDER_1_2_INV ) \
  template <> constexpr const uint FFT_Multiplication_border_0< TYPE > = BORDER_0; \
  template <> constexpr const uint FFT_Multiplication_border_1< TYPE > = BORDER_1; \
  template <> constexpr const uint FFT_Multiplication_border_1_2< TYPE > = BORDER_1_2; \
  template <> constexpr const uint FFT_Multiplication_border_1_2_exponent< TYPE > = BORDER_1_2_EXPONENT; \
  template <> constexpr const uint FFT_Multiplication_border_1_2_inv< TYPE > = BORDER_1_2_INV; \
  template <> inline TruncatedPolynomial< TYPE >& TruncatedPolynomial< TYPE >::operator*=( const Polynomial< TYPE >& f ) { return TruncatedPolynomial< TYPE >::FFT_Multiplication( f ); } \
  template <> inline TruncatedPolynomial< TYPE >& TruncatedPolynomial< TYPE >::operator*=( Polynomial< TYPE >&& f ) { return TruncatedPolynomial< TYPE >::FFT_Multiplication( move( f ) ); } \
									\
  template <>								\
  TruncatedPolynomial< TYPE > Inverse( const TruncatedPolynomial< TYPE >& f ) \
  {									\
									\
    DEFINITION_OF_INVERSE_FOR_TRUNCATED_POLYNOMIAL( TYPE , f_inv.TruncatedMinus( f_inv.FFT_TruncatedMultiplication_const( f , power , power_2 ).FFT_TruncatedMultiplication( f_inv , power , power_2 ) , power , power_2 ) ); \
									\
  }									\
									\
  template <>								\
  TruncatedPolynomial< TYPE > Exp( const TruncatedPolynomial< TYPE >& f ) \
  {									\
									\
    DEFINITION_OF_EXP_FOR_TRUNCATED_POLYNOMIAL( TYPE , f_exp.TruncatedMinus( ( TruncatedIntegral( Differential( f_exp ).FFT_TruncatedMultiplication_const( Inverse( f_exp ) , power - 1 , power_2 ) , power ).TruncatedMinus( f , power , power_2 ) ).FFT_TruncatedMultiplication( f_exp , power , power_2 ) , power , power_2 ) ); \
									\
  }									\
									\

