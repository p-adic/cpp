// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/VLArray/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#include "VLArray/a_Body.hpp"

inline void BijSum1N( const uint& N , const uint& n , uint& n_1 , uint& n_2 ) { return BijSum1N( to_VLArray<dim>( N , infty() ) , n , n_1 , n_2 ); }
inline uint BijSumN1( const uint& N , const uint& n_1 , const uint& n_2 ) { return BijSumN1( to_VLArray<dim>( N , infty() ) , n_1 , n_2 ); }

inline VLArray<uint> BijProd1N( const uint& N , const uint& n ) { return BijProd1N( to_VLArray<dim>( N , infty() ) , n ); }
inline void BijProd1N( const uint& N , const uint& n , VLArray<uint>& a_n ) { BijProd1N(to_VLArray<dim>( N , infty() ) , n , a_n ); }

inline uint BijProdN1( const VLArray<uint>& a_n ) { return BijProdN1( to_VLArray<dim>( a_n.size() , infty() ) , a_n ); }
