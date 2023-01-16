// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Operator/a.hpp

#pragma once
#include "../a_Alias.hpp"

#include "../../Constant/a.hpp"

template <INT_TYPE_FOR_MOD M>
class OperatorsForMod
{
  
public:
  OperatorsForMod() = delete;
  template <typename INT> static inline constexpr INT Residue( const INT& n ) noexcept;
  template <typename INT> static inline constexpr INT& Residue( INT& n ) noexcept;
  static inline constexpr uint& Residue( uint& n ) noexcept;
  static inline constexpr ull& Residue( ull& n ) noexcept;
  template <typename INT> static inline constexpr INT Residue( INT&& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& Normalise( INT_TYPE_FOR_MOD& n ) noexcept;
  
  static inline constexpr INT_TYPE_FOR_MOD& Add( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& Subtract( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& Multiply( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline INT_TYPE_FOR_MOD& Devide( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 );
  
  static inline constexpr INT_TYPE_FOR_MOD& LShift( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 ) noexcept;
  // Mが奇数である場合のみサポート。
  static inline constexpr INT_TYPE_FOR_MOD& RShift( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 ) noexcept;

  static inline constexpr INT_TYPE_FOR_MOD& LIncrement( INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD RIncrement( INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& LDecrement( INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD RDecrement( INT_TYPE_FOR_MOD& n ) noexcept;

  static inline constexpr INT_TYPE_FOR_MOD& SignInvert( INT_TYPE_FOR_MOD& n ) noexcept;  
  static inline constexpr INT_TYPE_FOR_MOD& Double( INT_TYPE_FOR_MOD& n ) noexcept;
  // Mが奇数である場合のみサポート。
  static inline constexpr INT_TYPE_FOR_MOD& Halve( INT_TYPE_FOR_MOD& n ) noexcept;
  // Mが素数である場合のみサポート。
  static inline INT_TYPE_FOR_MOD& Invert( INT_TYPE_FOR_MOD& n );

  template <typename T> static inline constexpr INT_TYPE_FOR_MOD& PositivePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept;
  template <typename T> static inline constexpr INT_TYPE_FOR_MOD& NonNegativePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept;
  // Mが素数であるかexponent>=0である場合にのみサポート。
  template <typename T> static inline constexpr INT_TYPE_FOR_MOD& Power( INT_TYPE_FOR_MOD& n , T&& exponent );

  // n>0である場合にのみサポート。
  static inline const INT_TYPE_FOR_MOD& Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline constexpr ull MontgomeryExpress( ull n ) noexcept;
  static inline constexpr ull& MontgomeryReduce( ull& n ) noexcept;
  static inline constexpr ull& MontgomeryMultiply( ull& n , const INT_TYPE_FOR_MOD& m ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& MontgomeryLIncrement( INT_TYPE_FOR_MOD& n ) noexcept;
  
  using type = ConstantsForMod<M>;

private:
  // 0 <= n <= ( 998244353 - 1 ) ^ 2 の場合のみサポート
  template <typename INT> static inline constexpr INT& Residue998244353( INT& n ) noexcept;
  
  static inline constexpr INT_TYPE_FOR_MOD& MultiplyEven( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& MultiplyOdd( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline const INT_TYPE_FOR_MOD& FactorialEven( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& FactorialOdd( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& FactorialInverseEven( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline const INT_TYPE_FOR_MOD& FactorialInverseOdd( const INT_TYPE_FOR_MOD& n ) noexcept;

};
