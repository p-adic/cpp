// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

// 末尾にinclude
// #include "../a_Body.hpp"

#include "../../Analysis/FFT/a_Body.hpp"
// 0除算の例外処理
#include "../../../Error/IllegalInput/a_Body.hpp"

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N ) : Polynomial<T>() , m_N( N ) { Polynomial<T>::m_f.reserve( m_N ); }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const TruncatedPolynomial<T>& f ) : Polynomial<T>( f ) , m_N( f.m_N ) { Polynomial<T>::m_f.reserve( m_N ); }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( TruncatedPolynomial<T>&& f ) : Polynomial<T>( move( f ) ) , m_N( move( f.m_N ) ) { Polynomial<T>::m_f.reserve( m_N ); }
template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const T& t ) : Polynomial<T>( t ) , m_N( N ) { Polynomial<T>::m_f.reserve( m_N ); }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const Polynomial<T>& f ) : Polynomial<T>() , m_N( N ) { Polynomial<T>::m_size = f.Polynomial<T>::m_size < m_N ? f.Polynomial<T>::m_size : m_N; Polynomial<T>::m_f = vector<T>( Polynomial<T>::m_size ); for( uint i = 0 ; i < Polynomial<T>::m_size ; i++ ){ Polynomial<T>::m_f[i] = f.Polynomial<T>::m_f[i]; } Polynomial<T>::m_f.reserve( m_N ); }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , Polynomial<T>&& f ) : Polynomial<T>() , m_N( N ) { if( f.Polynomial<T>::m_size < m_N * 2 ){ Polynomial<T>::operator=( move( f ) ); if( f.Polynomial<T>::m_size < m_N ){ Polynomial<T>::m_f.reserve( m_N ); } else { TruncateFinal( m_N ); } } else { Polynomial<T>::m_f = vector<T>( m_N ); for( uint i = 0 ; i < m_N ; i++ ){ Polynomial<T>::m_f[i] = move( f.Polynomial<T>::m_f[i] ); } Polynomial<T>::m_size = m_N; } }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const uint& i , const T& t ) : Polynomial<T>() , m_N( N ) { if( i < m_N ? t != Polynomial<T>::const_zero() : false ){ Polynomial<T>::operator[]( i ) = t; } Polynomial<T>::m_f.reserve( m_N ); }

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const uint& i , T&& t ) : Polynomial<T>() , m_N( N ) { if( i < m_N ? t != Polynomial<T>::const_zero() : false ){ Polynomial<T>::operator[]( i ) = move( t ); } Polynomial<T>::m_f.reserve( m_N ); }

template <typename T> template <SFINAE_FOR_POLYNOMIAL()> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , const uint& i , const Arg& n ) : TruncatedPolynomial( N , i , T( n ) ) {}

template <typename T> inline TruncatedPolynomial<T>::TruncatedPolynomial( const uint& N , vector<T>&& f ) : Polynomial<T>() , m_N( N ) { const uint f_size = f.size(); if( f_size < m_N * 2 ){ Polynomial<T>::operator=( move( f ) ); if( f_size < m_N ){ Polynomial<T>::m_f.reserve( m_N ); } else { TruncateFinal( m_N ); } } else { Polynomial<T>::m_f = vector<T>( m_N ); for( uint i = 0 ; i < m_N ; i++ ){ Polynomial<T>::m_f[i] = move( f[i] ); } Polynomial<T>::m_f.reserve( m_N ); } }


template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const TruncatedPolynomial<T>& f ) { Polynomial<T>::operator=( f ); m_N = f.m_N; Polynomial<T>::m_f.reserve( m_N ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( TruncatedPolynomial<T>&& f ) { Polynomial<T>::operator=( move( f ) ); m_N = move( f.m_N ); Polynomial<T>::m_f.reserve( m_N ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const T& t ) { Polynomial<T>::operator=( t ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( T&& t ) { Polynomial<T>::operator=( move( t ) ); return *this; }
template <typename T> template <SFINAE_FOR_POLYNOMIAL()> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const Arg& n ) { Polynomial<T>::operator=( T( n ) ); return *this; }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( const Polynomial<T>& f ) { return operator=( TruncatedPolynomial<T>( m_N , f ) ); }
template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator=( Polynomial<T>&& f ) { return operator=( TruncatedPolynomial<T>( m_N , move( f ) ) ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const T& t ) { Polynomial<T>::operator+=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const Polynomial<T>& f ) { return TruncatedPolynomial<T>::TruncatedPlus( f , 0 , f.m_size ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator+=( const TruncatedPolynomial<T>& f ) { return m_N == 0 ? operator=( f ) : TruncatedPolynomial<T>::TruncatedPlus( f , 0 , f.Polynomial<T>::m_size ); }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncatedPlus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_lim )
{

  const uint& size = N_input_lim < m_N ? N_input_lim < f.Polynomial<T>::m_size ? N_input_lim : f.Polynomial<T>::m_size : m_N < f.Polynomial<T>::m_size ? m_N : f.Polynomial<T>::m_size;
  
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
TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncatedMinus( const Polynomial<T>& f , const uint& N_input_start , const uint& N_input_lim )
{

  const uint& size = N_input_lim < m_N ? N_input_lim < f.Polynomial<T>::m_size ? N_input_lim : f.Polynomial<T>::m_size : m_N < f.Polynomial<T>::m_size ? m_N : f.Polynomial<T>::m_size;

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

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const Polynomial<T>& f )
{

  DEFINITION_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( f.Polynomial<T>::m_size == 0 ) , return *this , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( searching ) , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= m_N ) , return *this , MULTIPLICATION , Polynomial<T>::m_f[j] , 0 , );

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( Polynomial<T>&& f ){ return operator*=( f ); }

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::FFT_Multiplication( const Polynomial<T>& f )
{
  
  DEFINITION_OF_FFT_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( f.Polynomial<T>::m_size == 0 ) , return *this , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( searching ) , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return *this , return *this , MULTIPLICATION , Polynomial<T>::m_f[j] , 0 , 0 , , vector<T>& f0 = Polynomial<T>::m_f , N_input_start_0 , N_input_max_0 + 1 , SET_SHIFTED_VECTOR_FOR_MULTIPLICATION( f1 , f.Polynomial<T>::m_f , N_input_start_1 , N_input_max_1 , N_input_start_0 ) , N_input_start_0_start_1 , N_input_start_0 + N_input_max_1 + 1 , f1 , , N_input_start_0 , f1[N_input_start_1 + i] *= f0[i] , operator=( TruncatedPolynomial<T>( m_N , move( f1 ) ) ) );

}

template <typename T>
TruncatedPolynomial<T>& TruncatedPolynomial<T>::FFT_Multiplication( Polynomial<T>&& f )
{
  
  DEFINITION_OF_FFT_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( f.Polynomial<T>::m_size == 0 ) , return *this , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( searching ) , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return *this , return *this , MULTIPLICATION , Polynomial<T>::m_f[j] , 0 , 0 , , vector<T>& f0 = Polynomial<T>::m_f , N_input_start_0 , N_input_max_0 + 1 , vector<T>&& f1 = move( f.Polynomial<T>::m_f ) , N_input_start_1 , N_input_max_1 + 1 , f0 , f0.resize( product_length ) , 0 , f0[N_input_start_0_start_1 + i] = f0[N_input_start_0 + i] * f1[N_input_start_1 + i] , for( uint i = N_input_start_0 ; i < N_input_start_0_start_1 ; i++ ){ f0[i] = 0; } Polynomial<T>::m_size = f0.size(); SetTruncation( m_N ); );

}

template <typename T> 
TruncatedPolynomial<T>& TruncatedPolynomial<T>::TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim )
{
  
  DEFINITION_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( , return *this , , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return *this , MULTIPLICATION , Polynomial<T>::m_f[j] , N_output_start , if( N_output_lim_fixed > N_output_lim ){ N_output_lim_fixed = N_output_lim; } );

}

template <typename T> 
TruncatedPolynomial<T>& TruncatedPolynomial<T>::FFT_TruncatedMultiplication( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim )
{
  
  DEFINITION_OF_FFT_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( , return *this , , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return *this , return *this , MULTIPLICATION , Polynomial<T>::m_f[j] , N_output_start , N_output_start < N_input_start_0_start_1 ? 0 : N_output_start - N_input_start_0_start_1 , if( N_output_lim_fixed > N_output_lim ){ N_output_lim_fixed = N_output_lim; } , vector<T>& f0 = Polynomial<T>::m_f , N_input_start_0 , N_input_max_0 + 1 , SET_SHIFTED_VECTOR_FOR_MULTIPLICATION( f1 , f.Polynomial<T>::m_f , N_input_start_0 , N_input_max_1 , N_input_start_1 ) , N_input_start_0_start_1 , N_input_start_0 + N_input_max_1 + 1 , f1 , , N_input_start_0 , f1[N_input_start_1 + i] *= f0[i] , operator=( TruncatedPolynomial<T>( m_N , move( f1 ) ) ) );
  
}

template <typename T> 
TruncatedPolynomial<T>& TruncatedPolynomial<T>::FFT_TruncatedMultiplication( Polynomial<T>&& f , const uint& N_output_start , const uint& N_output_lim )
{

  DEFINITION_OF_FFT_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( , return *this , , RETURN_ZERO_FOR_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return *this , return *this , MULTIPLICATION , Polynomial<T>::m_f[j] , N_output_start , N_output_start < N_input_start_0_start_1 ? 0 : N_output_start - N_input_start_0_start_1 , if( N_output_lim_fixed > N_output_lim ){ N_output_lim_fixed = N_output_lim; } , vector<T>& f0 = Polynomial<T>::m_f , N_input_start_0 , N_input_max_0 + 1 , vector<T>&& f1 = move( f.Polynomial<T>::m_f ) , N_input_start_1 , N_input_max_1 + 1 , f0 , f0.reserve( product_length ) , 0 , f1[N_input_start_0_start_1 + i] = f0[N_input_start_0 + i] * f1[N_input_start_1 + i] , for( uint i = N_input_start_0 ; i < N_input_start_0_start_1 ; i++ ){ f0[i] = 0; } Polynomial<T>::m_size = f0.size(); SetTruncation( m_N ); );
  
}

template <typename T> 
TruncatedPolynomial<T> TruncatedPolynomial<T>::TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const
{
  
  DEFINITION_OF_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( , return TruncatedPolynomial<T>( m_N , move( answer ) ) , , RETURN_ZERO_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return TruncatedPolynomial<T>( m_N , move( answer ) ) , TRUNCATED_MULTIPLICATION_CONST , Polynomial<T>::operator[]( j ) , N_output_start , if( N_output_lim_fixed > N_output_lim ){ N_output_lim_fixed = N_output_lim; } );
  
}

template <typename T> 
TruncatedPolynomial<T> TruncatedPolynomial<T>::FFT_TruncatedMultiplication_const( const Polynomial<T>& f , const uint& N_output_start , const uint& N_output_lim ) const
{
  
  DEFINITION_OF_FFT_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( , return TruncatedPolynomial<T>( m_N , move( answer ) ) , , RETURN_ZERO_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return TruncatedPolynomial<T>( m_N , move( answer ) ) , return TruncatedPolynomial<T>( m_N , move( f0 ) ) , TRUNCATED_MULTIPLICATION_CONST , Polynomial<T>::operator[]( j ) , N_output_start , N_output_start < N_input_start_0_start_1 ? 0 : N_output_start - N_input_start_0_start_1 , if( N_output_lim_fixed > N_output_lim ){ N_output_lim_fixed = N_output_lim; } , SET_SHIFTED_VECTOR_FOR_MULTIPLICATION( f0 , Polynomial<T>::m_f , N_input_start_0 , N_input_max_0 , N_input_start_1 ) , N_input_start_0_start_1 , N_input_start_1 + N_input_max_0 + 1 , vector<T> f1 = f.Polynomial<T>::m_f , N_input_start_1 , N_input_max_1 + 1 , f0 , , N_input_start_1 , f0[N_input_start_0 + i] *= f1[i] , );

}

template <typename T> 
TruncatedPolynomial<T> TruncatedPolynomial<T>::FFT_TruncatedMultiplication_const( Polynomial<T>&& f , const uint& N_output_start , const uint& N_output_lim ) const
{
  
  DEFINITION_OF_FFT_MULTIPLICATION_FOR_TRUNCATED_POLYNOMIAL( , return TruncatedPolynomial<T>( m_N , move( answer ) ) , , RETURN_ZERO_FOR_TRUNCATED_MULTIPLICATION_CONST_FOR_TRUNCATED_POLYNOMIAL_IF( N_input_start_0_start_1 >= N_output_lim_fixed ) , return TruncatedPolynomial<T>( m_N , move( answer ) ) , return TruncatedPolynomial<T>( m_N , move( f0 ) ) , TRUNCATED_MULTIPLICATION_CONST , Polynomial<T>::operator[]( j ) , N_output_start , N_output_start < N_input_start_0_start_1 ? 0 : N_output_start - N_input_start_0_start_1 , if( N_output_lim_fixed > N_output_lim ){ N_output_lim_fixed = N_output_lim; } , SET_SHIFTED_VECTOR_FOR_MULTIPLICATION( f0 , Polynomial<T>::m_f , N_input_start_0 , N_input_max_0 , N_input_start_1 ) , N_input_start_0_start_1 , N_input_start_1 + N_input_max_0 + 1 , vector<T>&& f1 = move( f.Polynomial<T>::m_f ) , N_input_start_1 , N_input_max_1 + 1 , f0 , , N_input_start_1 , f0[N_input_start_0 + i] *= f1[i] , );

}

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const T& t ) { Polynomial<T>::operator/=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator/=( const TruncatedPolynomial<T>& f ) { return operator*=( Inverse( m_N > f.m_N ? f : TruncatedPolynomial<T>( m_N , f ) ) ); }

template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator%=( const T& t ) { Polynomial<T>::operator%=( t ); return *this; }

template <typename T> inline TruncatedPolynomial<T> TruncatedPolynomial<T>::operator-() const { return move( TruncatedPolynomial<T>( m_N ) -= *this ); }


template <typename T> inline void TruncatedPolynomial<T>::SetTruncation( const uint& N ) noexcept { if( N < m_N ){ TruncateFinal( m_N ); } else { Polynomial<T>::m_f.reserve( N ); } m_N = N; }
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

    return TruncatedPolynomial<T>( f.m_N - n , Polynomial<T>::zero() );

  }

  vector<T> df( f.Polynomial<T>::m_size - n );
  T coef = T::Factorial( n );
  uint i = n;

  while( i < f.Polynomial<T>::m_size ){

    df[i - n] = f[i] * coef;
    i++;
    ( coef *= i ) /= ( i - n );

  }

  return TruncatedPolynomial<T>( f.m_N - n , move( df ) );

}

template <typename T>
TruncatedPolynomial<T> TruncatedDifferential( const TruncatedPolynomial<T>& f , const uint& N_output_start_plus_one )
{

  if( f.m_N == 0 ){

    ERR_INPUT( f , f.m_N );

  }

  TruncatedPolynomial<T> f_dif{ f.m_N - 1 };

  if( N_output_start_plus_one < f.Polynomial<T>::m_size ){

    const uint size = f.Polynomial<T>::m_size - 1;
    f_dif.Polynomial<T>::m_f = vector<T>( size );

    for( uint i = N_output_start_plus_one ; i < f.Polynomial<T>::m_size ; i++ ){

      f_dif.Polynomial<T>::m_f[i-1] = f.Polynomial<T>::m_f[i] * i;

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


template <typename T> inline TruncatedPolynomial<T>& TruncatedPolynomial<T>::operator*=( const T& t ) { Polynomial<T>::operator*=( t ); return *this; }


DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_PROTH_MOD( 998244353 , 997269505 );
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_PROTH_MOD( 167772161 , 167608321 );
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_PROTH_MOD( 469762049 , 469303297 );
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_PROTH_MOD( 754974721 , 754237441 );

// プロス素数以外の法で畳み込みをFFTで計算したい場合、このマクロで完全特殊化する。
// - 2663300644以下の法で高々8388607次以下の多項式の積（高々16777214次）
// - 2^{32}    未満の法で高々6451200次以下の多項式の積（高々12902400次）
// が計算可能。一般には
// - 0以上31以下の整数を係数に持つ高々10^6次の多項式の積は998244353を法とする。
// - 0以上10^6以下の整数を係数に持つ高々10^6次の多項式の積はガーナーのアルゴリズムで
//   最後に法を取らないように変更する。
// など、このマクロそのものを使わない方法も検討。
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( 1000000007 );

#include "../a_Body.hpp"
