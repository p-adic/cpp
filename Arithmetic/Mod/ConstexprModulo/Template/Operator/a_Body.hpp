// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/Operator/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Constant/a_Body.hpp"

// 0除算用の例外
#include "../../../../Error/IllegalImput/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr INT OperatorsForMod<M>::Residue( const INT& n ) noexcept { return Residue( INT( n ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr INT& OperatorsForMod<M>::Residue( INT& n ) noexcept { return n < 0 ? ( ( ( ( ++n ) *= -1 ) %= M ) *= -1 ) += M - 1 : n %= M; }
template <INT_TYPE_FOR_MOD M> inline constexpr uint& OperatorsForMod<M>::Residue( uint& n ) noexcept { return n %= M; }
template <INT_TYPE_FOR_MOD M> inline constexpr ull& OperatorsForMod<M>::Residue( ull& n ) noexcept { return n %= M; }
// clangではこの定義をOperatorsForMod<998244353>::Residueより先に持ってこないとリンカエラーとなる。
template <> template <typename INT> inline constexpr INT& OperatorsForMod<998244353>::Residue998244353( INT& n ) noexcept { constexpr const uint trunc = ( 1 << 23 ) - 1; INT n_u = n >> 23; n &= trunc; INT n_uq = ( n_u / 7 ) / 17; n_u -= n_uq * 119; n += n_u << 23; return n < n_uq ? n += 998244353 - n_uq : n -= n_uq; }
template <> inline constexpr ull& OperatorsForMod<998244353>::Residue( ull& n ) noexcept { constexpr const ull Mull = 998244353; constexpr const ull Mull2 = ( Mull - 1 ) * ( Mull - 1 ); return Residue998244353( n > Mull2 ? n -= Mull2 : n ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr INT OperatorsForMod<M>::Residue( INT&& n ) noexcept { return move( Residue( n ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::Normalise( INT_TYPE_FOR_MOD& n ) noexcept { return n < M ? n : n -= M; }
  
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::Add( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return Normalise( n0 += n1 ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::Subtract( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return n0 < n1 ? ( n0 += M ) -= n1 : n0 -= n1; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::Multiply( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return type::g_even ? MultiplyEven( n0 , n1 ) : MultiplyOdd( n0 , n1 ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::MultiplyEven( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { ull n0_copy = n0; return n0 = INT_TYPE_FOR_MOD( move( Residue( n0_copy *= n1 ) ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::MultiplyOdd( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { ull n0_copy = n0; return n0 = INT_TYPE_FOR_MOD( move( MontgomeryMultiply( n0_copy , n1 ) ) ); }
template <INT_TYPE_FOR_MOD M> inline INT_TYPE_FOR_MOD& OperatorsForMod<M>::Devide( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 ) { return Multiply( n0 , Invert( n1 ) ); }
  
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::LShift( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 ) noexcept { while( n1-- > 0 ){ Normalise( n0 <<= 1 ); } return n0; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::RShift( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 ) noexcept { while( n1-- > 0 ){ ( ( n0 & 1 ) == 0 ? n0 : n0 += M ) >>= 1; } return n0; }

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::LIncrement( INT_TYPE_FOR_MOD& n ) noexcept { return n < type::g_M_minus ? ++n : n = 0; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD OperatorsForMod<M>::RIncrement( INT_TYPE_FOR_MOD& n ) noexcept { INT_TYPE_FOR_MOD n_copy{ n }; LIncrement( n ); return n_copy; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::LDecrement( INT_TYPE_FOR_MOD& n ) noexcept { return n == 0 ? n = type::g_M_minus : --n; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD OperatorsForMod<M>::RDecrement( INT_TYPE_FOR_MOD& n ) noexcept { INT_TYPE_FOR_MOD n_copy{ n }; LDecrement( n ); return n_copy; }


template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::SignInvert( INT_TYPE_FOR_MOD& n ) noexcept { return n == 0 ? n : n = M - n; }
template <INT_TYPE_FOR_MOD M> inline INT_TYPE_FOR_MOD& OperatorsForMod<M>::Invert( INT_TYPE_FOR_MOD& n ) { if( n == 0 ){ ERR_INPUT( n ); } INT_TYPE_FOR_MOD n_neg; return n < type::g_memory_length ? n = Inverse( n ) : ( n_neg = M - n < type::g_memory_length ) ? n = M - Inverse( n_neg ) : PositivePower( n , INT_TYPE_FOR_MOD( type::g_M_minus_2 ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::Double( INT_TYPE_FOR_MOD& n ) noexcept { return Normalise( n <<= 1 ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::Halve( INT_TYPE_FOR_MOD& n ) noexcept { return ( ( n & 1 ) == 0 ? n : n += M ) >>= 1; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::PositivePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept { INT_TYPE_FOR_MOD power{ n }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? Multiply( n , power ) : n; exponent >>= 1; Multiply( power , power ); } return n; }
template <> template <typename T> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<2>::PositivePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept { return n; }
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::NonNegativePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept { return exponent == 0 ? n = 1 : PositivePower( n , forward<T>( exponent ) ); }
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::Power( INT_TYPE_FOR_MOD& n , T&& exponent ) { bool neg = exponent < 0; if( n == 0 && neg ){ ERR_INPUT( n , exponent ); } return neg ? PositivePower( PositivePower( n , INT_TYPE_FOR_MOD( type::g_Montgomery_M_minus_2 ) ) , forward<T>( exponent *= -1 ) ) : NonNegativePower( n , forward<T>( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMod<M>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { 0 , 1 }; static INT_TYPE_FOR_MOD length_curr = 2; if( n == 0 ){ ERR_INPUT( n ); } while( length_curr <= n ){ memory[length_curr] = M - Multiply( memory[M % length_curr] , M / length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMod<M>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { return type::g_even ? FactorialEven( n ) : FactorialOdd( n ); }
template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMod<M>::FactorialEven( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { 1 , 1 }; static INT_TYPE_FOR_MOD length_curr = 2; static INT_TYPE_FOR_MOD val_curr_me = 1; while( length_curr <= n ){ memory[length_curr] = Multiply( val_curr_me , length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMod<M>::FactorialOdd( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { 1 , 1 }; static INT_TYPE_FOR_MOD length_curr = 2; static INT_TYPE_FOR_MOD length_prev_me = type::g_Montgomery_base_mod; static ull val_curr_me = type::g_Montgomery_base_mod; while( length_curr <= n ){ ull val_curr_me_copy = MontgomeryMultiply( val_curr_me , MontgomeryLIncrement( length_prev_me ) ); memory[length_curr++] = INT_TYPE_FOR_MOD( move( MontgomeryReduce( val_curr_me_copy ) ) ); } return memory[n]; }

template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMod<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { return type::g_even ? FactorialInverseEven( n ) : FactorialInverseOdd( n ); }
template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMod<M>::FactorialInverseEven( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { 1 , 1 }; static INT_TYPE_FOR_MOD length_curr = 2; static INT_TYPE_FOR_MOD val_curr = 1; while( length_curr <= n ){ memory[length_curr] = Multiply( val_curr , Inverse( length_curr ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M>  inline const INT_TYPE_FOR_MOD& OperatorsForMod<M>::FactorialInverseOdd( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { 1 , 1 }; static INT_TYPE_FOR_MOD length_curr = 2; static ull val_curr_me = type::g_Montgomery_base_mod; while( length_curr <= n ){ ull val_curr_me_copy = MontgomeryMultiply( val_curr_me , MontgomeryExpress( Inverse( length_curr ) ) ); memory[length_curr++] = INT_TYPE_FOR_MOD( move( MontgomeryReduce( val_curr_me_copy ) ) ); } return memory[n]; }

template <INT_TYPE_FOR_MOD M> inline constexpr ull OperatorsForMod<M>::MontgomeryExpress( ull n ) noexcept { return move( MontgomeryReduce( n *= type::g_Montgomery_base_square_mod ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr ull& OperatorsForMod<M>::MontgomeryReduce( ull& n ) noexcept { ull n_sub = n & type::g_Montgomery_base_minus; return ( ( n += ( ( n_sub *= type::g_Montgomery_M_neg_inverse ) &= type::g_Montgomery_base_minus ) *= M ) >>= type::g_Montgomery_digit ) < M ? n : n -= M; }
template <INT_TYPE_FOR_MOD M> inline constexpr ull& OperatorsForMod<M>::MontgomeryMultiply( ull& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { return MontgomeryReduce( MontgomeryReduce( n0 *= n1 ) *= type::g_Montgomery_base_square_mod ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMod<M>::MontgomeryLIncrement( INT_TYPE_FOR_MOD& n ) noexcept { return Add( n , type::g_Montgomery_base_mod ); }
