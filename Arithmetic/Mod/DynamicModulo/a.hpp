// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Constant/a.hpp"

// verify:
// https://yukicoder.me/submissions/965301�i+=,*,/,Power�j
// https://yukicoder.me/submissions/965343�iDerepresent,+=,-=,*,Combination,one�j
// https://yukicoder.me/submissions/965376�iDerepresent,+=,-=,*=,SignInvert,+,*,^,++,--,Combination,zero,one�j

template <int NUM>
class DynamicMods
{

private:
  uint m_n;

public:
  inline DynamicMods() noexcept;
  inline DynamicMods( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods( DynamicMods<NUM>&& n ) noexcept;
  template <typename T> inline DynamicMods( T n ) noexcept;

  inline DynamicMods<NUM>& operator=( DynamicMods<NUM> n ) noexcept;
  inline DynamicMods<NUM>& operator+=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator-=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator*=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator/=( DynamicMods<NUM> n );
  // n>=0�ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(log n)��2^n�{����B
  template <typename INT> inline DynamicMods<NUM>& operator<<=( INT n );
  // n>=0����M����ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(n)��2^{-n}�{����B
  template <typename INT> inline DynamicMods<NUM>& operator>>=( INT n );

  inline DynamicMods<NUM>& operator++() noexcept;
  inline DynamicMods<NUM> operator++( int ) noexcept;
  inline DynamicMods<NUM>& operator--() noexcept;
  inline DynamicMods<NUM> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( / , );
  // exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�Bexponent�悷��B
  template <typename INT> inline DynamicMods<NUM> operator^( INT exponent ) const;
  // n>=0�ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(log n)��2^n�{��Ԃ��B
  template <typename INT> inline DynamicMods<NUM> operator<<( INT n ) const;
  // n>=0����M����ł���ꍇ�̂݃T�|�[�g�B�v�Z��O(n)��2^{-n}�{��Ԃ��B
  template <typename INT> inline DynamicMods<NUM> operator>>( INT n ) const;

  inline DynamicMods<NUM> operator-() const noexcept;
  // -1�{����B
  inline DynamicMods<NUM>& SignInvert() noexcept;
  // -1�悷��B
  inline DynamicMods<NUM>& Invert();
  // exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�Bexponent�悷��B
  template <typename INT> inline DynamicMods<NUM>& Power( INT exponent );
  // �O���[�o���X�R�[�v��swap���`���邽�߂̂��́B
  inline void swap( DynamicMods<NUM>& n ) noexcept;

  inline const uint& Represent() const noexcept;
  // 0 <= n < M�̏ꍇ�̂݃T�|�[�g�B�萔�{�������̂��߂�assert�Ȃ��B
  static inline DynamicMods<NUM> Derepresent( uint n ) noexcept;
  
  // M==1�ł��邩�A�܂���0 < n < M����n��M�ƌ݂��ɑf�ł���ꍇ�̂݃T�|�[�g�B
  static inline const DynamicMods<NUM>& Inverse( const uint& n );
  static inline const DynamicMods<NUM>& Factorial( const uint& n );
  // 0 < n < M����M���f���ł���ꍇ�̂݃T�|�[�g�B
  static inline const DynamicMods<NUM>& FactorialInverse( const uint& n );
  // 0 < n < M����M���f���ł���ꍇ�̂݃T�|�[�g�B
  static inline DynamicMods<NUM> Combination( const uint& n , const uint& i );

  static inline const DynamicMods<NUM>& zero() noexcept;
  static inline const DynamicMods<NUM>& one() noexcept;

  static inline const uint& GetModulo() noexcept;
  static inline void SetModulo( const uint& M , const int& order_minus_1 = -1 ) noexcept;
  
private:
  template <typename INT> inline DynamicMods<NUM>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline DynamicMods<NUM>& NonNegativePower( INT exponent ) noexcept;

  using Constants = ConstantsForDynamicMods<NUM>;

};

#include "a_Alias.hpp"

// M���f���ł���n��0�łȂ��ꍇ�ɂ̂݃T�|�[�g�B
template <int NUM> inline DynamicMods<NUM> Inverse( const DynamicMods<NUM>& n );
// M���f���ł��邩exponent>=0�ł���ꍇ�ɂ̂݃T�|�[�g�B
template <int NUM , typename T> inline DynamicMods<NUM> Power( DynamicMods<NUM> n , T exponent );

template <int NUM> inline void swap( DynamicMods<NUM>& n0 , DynamicMods<NUM>& n1 ) noexcept;

template <int NUM> inline string to_string( const DynamicMods<NUM>& n ) noexcept;

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DynamicMods<NUM>& n );
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DynamicMods<NUM>& n );

#include "../Hash/a.hpp"
template <int NUM> DECLARATION_OF_HASH( DynamicMods<NUM> );