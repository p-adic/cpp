// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/VLArray/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../Utility/VLArray/a.hpp"

// 濃度a_d[0],a_d[1],...の集合の排他的和集合の数え上げ
void BijSum1N( const VLArray<dim>& a_d , const uint& n , uint& n_1 , uint& n_2 );

// BijSum1Nの逆
uint BijSumN1( const VLArray<dim>& a_d , const uint& n_1 , const uint& n_2 );

// 濃度a_d[0],a_d[1],...の集合の直積の数え上げ
VLArray<uint> BijProd1N( const VLArray<dim>& a_d , const uint& n );
void BijProd1N( const VLArray<dim>& a_d , const uint& n , VLArray<uint>& a_n );

// 可算無限濃度の集合N個の直積の数え上げ
inline VLArray<uint> BijProd1N( const uint& N , const uint& n );
inline void BijProd1N( const uint& N , const uint& n , VLArray<uint>& a_n );

// BijProd1Nの逆
uint BijProdN1( const VLArray<dim>& a_d , const VLArray<uint>& a_n );
inline uint BijProdN1( const VLArray<uint>& a_n );


// 可算無限濃度の集合可算無限個の直積の本質的有限部分の数え上げ
void BijProd1Infty( const uint& , VLArray<uint>& );
VLArray<uint> BijProd1Infty( const uint& );
