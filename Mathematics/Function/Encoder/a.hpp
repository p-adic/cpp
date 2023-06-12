// c:/Users/user/Documents/Programming/Mathematics/Function/Encoder/a.hpp

#pragma once

// m_size_domのm_size_cod乗が2^64未満の場合のみサポート。
// 特にm_size_dom = m_size_codならば、m_size_dom<=15の場合のみサポート。
template <typename T , typename U , T f(const U&,const T&) , uint size_dom_max>
class FunctionEncoderBody
{

public:
  uint m_size_dom;
  uint m_size_cod;
  uint m_size_min;
  ull m_size_cod_power[size_dom_max];
  
  uint m_length;
  map<T,uint> m_memory;
  vector<T> m_memory_inv;

public:
  inline FunctionEncoderBody( const uint& size_dom , const uint& size_cod );

  ull Encode( const U& u );
  ull Encode( const uint ( &encoded_function )[size_dom_max] ) const;
  ull Encode( uint ( *encoded_function )(const uint&) ) const;
  inline T DirectApply( const U& u , const T& t ) const;
  inline T DecodeApply( const ull& u , const T& t );
  ull Composite( const ull& u0 , const ull& u1 );

protected:
  virtual T e( const uint& i );
  virtual uint e_inv( const T& t );
  
};

// fによるエンコードO(size)
// コードによる関数適用O(1)
// コードの合成O(size)
template <typename U , uint f(const U&,const uint&) , uint size_dom_max>
class FunctionEncoder :
  public FunctionEncoderBody<uint,U,f,size_dom_max>
{

public:
  inline FunctionEncoder( const uint& size );
  inline FunctionEncoder( const uint& size_dom , const uint& size_cod );
  
private:
  inline uint e( const uint& i );
  inline uint e_inv( const uint& t );

};

// fによるエンコードO(size log size)
// コードによる関数適用O(log size)
// コードの合成O(size)
template <typename T , typename U , T f(const U&,const T&) , uint size_dom_max>
class MemorisationFunctionEncoder :
  public FunctionEncoderBody<T,U,f,size_dom_max>
{

public:
  inline MemorisationFunctionEncoder( const uint& size , const list<T>& a );

};

// fによるエンコードO(size)
// コードによる関数適用O(1)
// コードの合成O(size)
template <typename T , typename U , T f(const U&,const T&) , uint size_dom_max , T enum_T(const uint&) , uint enum_T_inv(const T&)>
class EnumerationFunctionEncoder :
  public FunctionEncoderBody<T,U,f,size_dom_max>
{

public:
  inline EnumerationFunctionEncoder( const uint& size );
  
private:
  inline T e( const uint& i );
  inline uint e_inv( const T& t );

};
