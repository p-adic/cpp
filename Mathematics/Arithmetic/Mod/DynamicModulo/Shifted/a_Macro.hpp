// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Shifted/a_Macro.hpp

#pragma once

#define DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( OPR )		\
  inline bool operator OPR( const ShiftedMods<NUM>& n ) const noexcept	\

#define DECLARATION_OF_ARITHMETIC_FOR_SHIFTED_MOD( OPR , EX )		\
  inline ShiftedMods<NUM> operator OPR( ShiftedMods<NUM> n ) const EX;	\

#define DEFINITION_OF_COMPARISON_FOR_SHIFTED_MOD( OPR )			\
  template <int NUM> inline bool ShiftedMods<NUM>::operator OPR( const ShiftedMods<NUM>& n ) const noexcept { return m_n OPR n.m_n; } \

#define DEFINITION_OF_ARITHMETIC_FOR_SHIFTED_MOD( OPR , EX , LEFT , OPR2 ) \
  template <int NUM> inline ShiftedMods<NUM> ShiftedMods<NUM>::operator OPR( ShiftedMods<NUM> n ) const EX { return move( LEFT OPR2 ## = *this ); } \
  template <int NUM , typename T> inline ShiftedMods<NUM> operator OPR( T n0 , const ShiftedMods<NUM>& n1 ) EX { return move( ShiftedMods<NUM>( move( n0 ) ) OPR ## = n1 ); } \

