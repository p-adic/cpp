// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/Montgomery/a_Body.hpp

#pragma once
#include "Operator/a_Body.hpp"

// 以下をコンパイルするとクラステンプレートの部分特殊化となるので、
// 不完全型としてコンパイルエラーとなる。

// template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<M>::Montgomery( const T& n ) noexcept : m_n( OperatorsForMontgomery<M>::Express( OperatorsForMontgomery<M>::Residue( n ) ) ) {}
// // nの書き換えを防ぐために明示的にキャスト
// template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<M>::Montgomery( T&& n ) noexcept : m_n( OperatorsForMontgomery<M>::Express( OperatorsForMontgomery<M>::Residue( decay_t<T>( n ) ) ) ) {}
// template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Montgomery<M>::Montgomery( T&& n ) noexcept : m_n( OperatorsForMontgomery<M>::Express( OperatorsForMontgomery<M>::Residue( move<T>( n ) ) ) ) {}

// // クラスの部分特殊化であるため値返しに変更できない。
// // 返り値を左辺値参照に直接渡す時はtempやm_nの変化に注意する。
// template <> inline constexpr INT_TYPE_FOR_MOD Montgomery<MODULO>::Represent() const noexcept { return OperatorsForMontgomery<MODULO>::Reduce( m_n ); }
// template <> inline constexpr Montgomery<MODULO> Montgomery<MODULO>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { Montgomery<MODULO> n_copy{}; n_copy.m_n = OperatorsForMontgomery<MODULO>::Express( n ); return n_copy; }
