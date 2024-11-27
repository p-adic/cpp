// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/Montgomery/Operator/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Operator/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD OperatorsForMontgomery<M>::Express( const INT_TYPE_FOR_MOD& n ) noexcept { return INT_TYPE_FOR_MOD( OperatorsForMod<M>::MontgomeryExpress( ull( n ) ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD OperatorsForMontgomery<M>::Reduce( ull n ) noexcept { return INT_TYPE_FOR_MOD( move( OperatorsForMod<M>::MontgomeryReduce( n ) ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::Multiply( INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { ull n0_copy = n0; return n0 = Reduce( n0_copy *= n1 ); }
template <INT_TYPE_FOR_MOD M> inline INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::Devide( INT_TYPE_FOR_MOD& n0 , INT_TYPE_FOR_MOD n1 ) { return Multiply( n0 , Invert( n1 ) ); }
  
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::LIncrement( INT_TYPE_FOR_MOD& n ) noexcept { return OperatorsForMod<M>::MontgomeryLIncrement( n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD OperatorsForMontgomery<M>::RIncrement( INT_TYPE_FOR_MOD& n ) noexcept { INT_TYPE_FOR_MOD n_copy = n; LIncrement( n ); return n_copy; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::LDecrement( INT_TYPE_FOR_MOD& n ) noexcept { return OperatorsForMod<M>::Subtract( n , type::g_Montgomery_base_mod ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD OperatorsForMontgomery<M>::RDecrement( INT_TYPE_FOR_MOD& n ) noexcept { INT_TYPE_FOR_MOD n_copy = n; LDecrement( n ); return n_copy; }

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::Invert( INT_TYPE_FOR_MOD& n ) { if( n == 0 ){ ERR_INPUT( n ); } return PositivePower( n , INT_TYPE_FOR_MOD( type::g_Montgomery_M_minus_2 ) ); }

temtemplate <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::PositivePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept { INT_TYPE_FOR_MOD power = n; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? Multiply( n , power ) : n; Multiply( power , power ); } return n; }
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::NonNegativePower( INT_TYPE_FOR_MOD& n , T&& exponent ) noexcept { return exponent == 0 ? n = type::g_Montgomery_base_mod : Power( n , forward<T>( exponent ) ); }
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::Power( INT_TYPE_FOR_MOD& n , T&& exponent ) { return exponent < 0 ? PositivePower( Invert( n ) , forward<T>( exponent *= -1 ) ) : NonNegativePower( n , forward<T>( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::Expression( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { 0 , type::g_Montgomery_base_mod }; static INT_TYPE_FOR_MOD length_curr = 2; static INT_TYPE_FOR_MOD length_prev_me = type::g_Montgomery_base_mod; static INT_TYPE_FOR_MOD val_curr = type::g_Montgomery_base_mod; while( length_curr <= n ){ memory[length_curr++] = LIncrement( length_prev_me ); } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { type::g_Montgomery_base_mod , type::g_Montgomery_base_mod }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr] = Express( OperatorsForMod<M>::Inverse( length_curr ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { type::g_Montgomery_base_mod , type::g_Montgomery_base_mod }; static INT_TYPE_FOR_MOD length_curr = 2; static INT_TYPE_FOR_MOD val_curr = type::g_Montgomery_base_mod; while( length_curr <= n ){ memory[length_curr] = Multiply( val_curr , Expression( length_curr ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& OperatorsForMontgomery<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { static INT_TYPE_FOR_MOD memory[type::g_memory_length] = { type::g_Montgomery_base_mod , type::g_Montgomery_base_mod }; static INT_TYPE_FOR_MOD length_curr = 2; static INT_TYPE_FOR_MOD val_curr = type::g_Montgomery_base_mod; while( length_curr <= n ){ memory[length_curr] = Multiply( val_curr , Express( Inverse( length_curr ) ) ); length_curr++; } return memory[n]; }
