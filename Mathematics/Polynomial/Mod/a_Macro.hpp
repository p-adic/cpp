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


#define SET_SUM_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL	\
  Polynomial<T>::m_f[i] = sum					\



#define SET_SUM_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL \
  answer[i] = sum						    \

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


#define ZEROIFICATION_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL	\
  for( uint i = 0 ; i < N_input_start_0_start_1 ; i++ ){		\
									\
    Polynomial<T>::m_f[i] = 0;						\
									\
  }									\


#define ZEROIFICATION_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL \
  for( uint i = 0 ; i < N_input_start_0_start_1 ; i++ ){		\
									\
    answer[i] = 0;							\
									\
  }									\



#ifndef CONNECT

  #define CONNECT( S1 , S2 ) SUBSTITUTE_CONNECT( S1 , S2 ) 
  #define SUBSTITUTE_CONNECT( S1 , S2 ) S1 ## S2 

#endif


#define DEFINITION_0_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , ACCESS_ENTRY ) \
  CONNECT( CONNECT( RETURN_ZERO_FOR_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL_IF )( Polynomial<T>::m_size == 0 ); \
  uint N_output_max = Polynomial<T>::m_size + f.Polynomial<T>::m_size - 2; \
									\
  if( N_output_max >= m_N ){						\
									\
    N_output_max = m_N - 1;						\
									\
  }									\
									\
  const uint N_output_lim = N_output_max + 1;				\
  CONNECT( CONNECT( SET_VECTOR_FOR_ANSWER_OF_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL )( N_output_lim ); \
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
    CONNECT( CONNECT( SET_SUM_OF_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL ); \
    searching = i > 0;							\
									\
  }									\
  									\



#define DEFINITION_0_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL		\
  DEFINITION_0_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION , Polynomial<T>::m_f[j] ) \
									\
  

#define DEFINITION_0_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL	\
  DEFINITION_0_OF__FOR_TRUNCATED_POLYNOMIAL( TRUNCATED_MULTIPLICATION_CONST , Polynomial<T>::operator[]( j ) ) \
									\


#define DEFINITION_1_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION ) \
  SET_N_INPUT_START_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( Polynomial<T>::m_f , Polynomial<T>::m_size , N_input_start_0 ); \
  CONNECT( CONNECT( RETURN_ZERO_FOR_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL_IF )( searching ); \
  searching = true;							\
  SET_N_INPUT_START_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( f , f.Polynomial<T>::m_size , N_input_start_1 ); \
									\



#define DEFINITION_1_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL \
  DEFINITION_1_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION )	\
								\


#define DEFINITION_1_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL	\
  DEFINITION_1_OF__FOR_TRUNCATED_POLYNOMIAL( TRUNCATED_MULTIPLICATION_CONST )	\
									\
  

#define DEFINITION_2_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL		\
  SET_N_INPUT_MAX_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( Polynomial<T>::m_f , Polynomial<T>::m_size , N_input_max_0 ); \
  SET_N_INPUT_MAX_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( f , f.Polynomial<T>::m_size < m_N ? f.Polynomial<T>::m_size : m_N , N_input_max_1 ); \
  const uint N_input_max_0_max_1 = N_input_max_0 + N_input_max_1;	\
  const uint N_input_start_0_start_1 = N_input_start_0 + N_input_start_1; \
									\
  

#define DEFINITION_2_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL	\
  DEFINITION_2_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL		\
									\


#define DEFINITION_3_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION ) \
  const uint N_input_start_0_max_1 = N_input_start_0 + N_input_max_1;	\
  const uint N_input_max_0_start_1 = N_input_max_0 + N_input_start_1;	\
  const uint N_output_max_fixed = N_output_lim_fixed - 1;		\
  CONNECT( CONNECT( SET_VECTOR_FOR_ANSWER_OF_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL )( N_output_lim_fixed ); \
  									\
  for( uint i = N_output_max_fixed ; i > N_input_start_0_max_1 ; i-- ){	\
									\
    CONNECT( CONNECT( CONVOLUTION_FOR_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL )( i - N_input_max_1 ); \
									\
  }									\
									\
  searching = true;							\
									\
  for( uint i = N_input_start_0_max_1 < N_output_max_fixed ? N_input_start_0_max_1 : N_output_max_fixed ; searching ; i-- ){ \
									\
    CONNECT( CONNECT( CONVOLUTION_FOR_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL )( N_input_start_0 ); \
    searching = i > N_input_start_0_start_1;				\
									\
  }									\
									\
  CONNECT( CONNECT( ZEROIFICATION_FOR_ , MULTIPLICATION ) , _FOR_TRUNCATED_POLYNOMIAL ); \
									\



#define DEFINITION_3_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL \
  DEFINITION_3_OF__FOR_TRUNCATED_POLYNOMIAL( MULTIPLICATION )	\
								\
 

#define DEFINITION_3_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL	\
  DEFINITION_3_OF__FOR_TRUNCATED_POLYNOMIAL( TRUNCATED_MULTIPLICATION_CONST )	\
									\
 

#define DEFINITION_4_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL		\
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
  vector<T> f0{ move( FFT<T>( Polynomial<T>::m_f , N_input_start_0 , N_input_max_0 + 1 , 0 , two_power , exponent ) ) }; \
  const vector<T> f1{ move( FFT<T>( f.Polynomial<T>::m_f , N_input_start_1 , N_input_max_1 + 1 , 0 , two_power , exponent ) ) }; \
  									\
  for( uint i = 0 ; i < two_power ; i++ ){				\
									\
    f0[i] *= f1[i];							\
									\
  }									\
									\




#define DEFINITION_4_OF_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL	\
  DEFINITION_4_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL		\
									\
 


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
  return f_inv								\
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
  return f_exp								\
									\


#define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_TRUNCATED_POLYNOMIAL( TYPE , BORDER_0 , BORDER_1 , BORDER_1_2 , BORDER_1_2_EXPONENT , BORDER_1_2_INV ) \
  template <> constexpr const uint FFT_Multiplication_border_0< TYPE > = BORDER_0; \
  template <> constexpr const uint FFT_Multiplication_border_1< TYPE > = BORDER_1; \
  template <> constexpr const uint FFT_Multiplication_border_1_2< TYPE > = BORDER_1_2; \
  template <> constexpr const uint FFT_Multiplication_border_1_2_exponent< TYPE > = BORDER_1_2_EXPONENT; \
  template <> constexpr const uint FFT_Multiplication_border_1_2_inv< TYPE > = BORDER_1_2_INV; \
  template <> inline TruncatedPolynomial< TYPE >& TruncatedPolynomial< TYPE >::operator*=( const Polynomial< TYPE >& f ) { return TruncatedPolynomial< TYPE >::FFT_Multiplication( f ); } \
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
