// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Enumeration/DirectProduct/VLArray/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../../Utility/VLArray/a.hpp"

// 濃度a_d[0],a_d[1],...の集合の直積の数え上げ
VLArray<INT_TYPE_FOR_EUINT> BijProd1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n );
void BijProd1N( const VLArray<euint>& a_d , const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a_n );

// 可算無限濃度の集合N個の直積の数え上げ
inline VLArray<INT_TYPE_FOR_EUINT> BijProd1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n );
inline void BijProd1N( const INT_TYPE_FOR_EUINT& N , const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a_n );

// BijProd1Nの逆
INT_TYPE_FOR_EUINT BijProdN1( const VLArray<euint>& a_d , const VLArray<INT_TYPE_FOR_EUINT>& a_n );
inline INT_TYPE_FOR_EUINT BijProdN1( const VLArray<INT_TYPE_FOR_EUINT>& a_n );


// 可算無限濃度の集合可算無限個の直積の本質的有限部分の数え上げ
void BijProd1Infty( const INT_TYPE_FOR_EUINT& n , VLArray<INT_TYPE_FOR_EUINT>& a );
VLArray<INT_TYPE_FOR_EUINT> BijProd1Infty( const INT_TYPE_FOR_EUINT& );
