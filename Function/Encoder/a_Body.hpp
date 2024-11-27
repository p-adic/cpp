// c:/Users/user/Documents/Programming/Mathematics/Function/Encoder/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max> inline FunctionEncoderBody<T,U,f,size_dom_max>::FunctionEncoderBody( const uint& size_dom , const uint& size_cod ) :
  m_size_dom( size_dom ) , m_size_cod( size_cod ) , m_size_min( min( m_size_dom , m_size_cod ) ) , m_size_cod_power() , m_length() , m_memory() , m_memory_inv()
{

  assert( m_size_cod == 0 ? true : m_size_dom <= ull( -1 ) / m_size_cod );
  assert( m_size_dom <= size_dom_max );
  ull power = 1;

  for( uint i = 0 ; i < m_size_dom ; i++ , power *= m_size_cod ){

    m_size_cod_power[i] = power;

  }

}

template <typename U , uint f(const U&,const uint&) , uint size_dom_max> inline FunctionEncoder<U,f,size_dom_max>::FunctionEncoder( const uint& size ) : FunctionEncoder<U,f,size_dom_max>( size , size ) {}
template <typename U , uint f(const U&,const uint&) , uint size_dom_max> inline FunctionEncoder<U,f,size_dom_max>::FunctionEncoder( const uint& size_dom , const uint& size_cod ) : FunctionEncoderBody<uint,U,f,size_dom_max>( size_dom , size_cod ) {}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max> inline MemorisationFunctionEncoder<T,U,f,size_dom_max>::MemorisationFunctionEncoder( const uint& size , const list<T>& a ) :
  FunctionEncoderBody<T,U,f,size_dom_max>( size , size )
{

  using base = FunctionEncoderBody<T,U,f,size_dom_max>;
  
  for( auto itr = a.begin() , end = a.end() ; itr != end ; itr++ ){

    base::e_inv( *itr );

  }

  assert( base::m_length == base::m_size_dom );

}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max , T enum_T(const uint&) , uint enum_T_inv(const T&)> inline EnumerationFunctionEncoder<T,U,f,size_dom_max,enum_T,enum_T_inv>::EnumerationFunctionEncoder( const uint& size ) : FunctionEncoderBody<T,U,f,size_dom_max>( size , size ) {}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max>
ull FunctionEncoderBody<T,U,f,size_dom_max>::Encode( const U& u )
{
  
  ull answer = 0;

  for( uint i = 0 ; i < m_size_dom ; i++ ){

    const uint f_i = e_inv( f( u , e( i ) ) );
    answer += f_i * m_size_cod_power[i];

  }
  
  return answer;

}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max>
ull FunctionEncoderBody<T,U,f,size_dom_max>::Encode( const uint ( &encoded_function )[size_dom_max] ) const
{
  
  ull answer = 0;
  
  for( uint i = 0 ; i < m_size_dom ; i++ ){

    const uint& encoded_function_i = encoded_function[i];
    assert( encoded_function_i < m_size_cod );
    answer += encoded_function_i * m_size_cod_power[i];

  }
  
  return answer;

}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max>
ull FunctionEncoderBody<T,U,f,size_dom_max>::Encode( uint ( *encoded_function )(const uint&) ) const
{
  
  ull answer = 0;

  for( uint i = 0 ; i < m_size_dom ; i++ ){

    const uint encoded_function_i = encoded_function( i );
    assert( encoded_function_i < m_size_cod );
    answer += encoded_function_i * m_size_cod_power[i];

  }
  
  return answer;

}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max> inline T FunctionEncoderBody<T,U,f,size_dom_max>::DirectApply( const U& u , const T& t ) const { return f( u , t ); }
template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max> inline T FunctionEncoderBody<T,U,f,size_dom_max>::DecodeApply( const ull& u , const T& t ) { return e( ( u / m_size_cod_power[ e_inv( t ) ] ) % m_size_cod ); }

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max>
ull FunctionEncoderBody<T,U,f,size_dom_max>::Composite( const ull& u0 , const ull& u1 )
{

  ull answer = 0;

  for( uint i = 0 ; i < m_size_dom ; i++ ){

    const uint u1i = DecodeApply( u1 , e( i ) );
    const uint u0u1i = DecodeApply( u0 , u1i );
    answer += e_inv( u0u1i ) * m_size_cod_power[i];
    
  }
  
  return answer;
}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max>
T FunctionEncoderBody<T,U,f,size_dom_max>::e( const uint& i )
{
  
  assert( i < min( m_length , m_size_dom ) );
  return m_memory_inv[i];

}

template <typename U , uint f(const U&,const uint&) , uint size_dom_max> inline uint FunctionEncoder<U,f,size_dom_max>::e( const uint& i )
{
  
  using base = FunctionEncoderBody<uint,U,f,size_dom_max>;
  assert( i < base::m_size_dom );
  return i;

}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max , T enum_T(const uint&) , uint enum_T_inv(const T&)> inline T EnumerationFunctionEncoder<T,U,f,size_dom_max,enum_T,enum_T_inv>::e( const uint& i )
{

  using base = FunctionEncoderBody<T,U,f,size_dom_max>;
  assert( i < base::m_size_dom );
  return enum_T( i );

}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max>
uint FunctionEncoderBody<T,U,f,size_dom_max>::e_inv( const T& t )
{

  if( m_memory.count( t ) == 0 ){

    assert( m_length < m_size_cod );
    m_memory_inv.push_back( t );
    return m_memory[t] = m_length++;

  }
  
  return m_memory[t];

}

template <typename U , uint f(const U&,const uint&) , uint size_dom_max> inline uint FunctionEncoder<U,f,size_dom_max>::e_inv( const uint& t )
{

  using base = FunctionEncoderBody<uint,U,f,size_dom_max>;
  assert( t < base::m_size_cod );
  return t;

}

template <typename T, typename U , T f(const U&,const T&) , uint size_dom_max , T enum_T(const uint&) , uint enum_T_inv(const T&)> inline uint EnumerationFunctionEncoder<T,U,f,size_dom_max,enum_T,enum_T_inv>::e_inv( const T& t )
{

  using base = FunctionEncoderBody<T,U,f,size_dom_max>;
  const uint i = enum_T_inv( t );
  assert( i < base::m_size_cod );
  return i;

}


