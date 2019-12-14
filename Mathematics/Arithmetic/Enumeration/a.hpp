// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a.hpp

#pragma once
#include "../Dimension/a.hpp"

uint BijSum21( const uint& , const uint& );
uint BijSum21( const dim& , const dim& , const uint& , const uint& );
void BijSum12( const uint& , uint& , uint& );
void BijSum12( const dim& , const dim& , const uint& , uint& , uint& );

uint BijSumN1( const uint& , const uint& , const uint& );
uint BijSumN1( const list<dim>& , const uint&  , const uint&  );
void BijSum1N( const uint& , const uint& , uint& , uint& );
void BijSum1N( const list<dim>& , const uint& , uint& , uint& );

uint BijProd21( const uint& , const uint& );
uint BijProd21( const dim& , const dim& , const uint& , const uint& );
void BijProd12( const uint& , uint& , uint& );
void BijProd12( const dim& , const dim& , const uint& , uint& , uint& );

uint BijProdN1( const list<uint>& );
uint BijProdN1( const list<dim>& , const list<uint>& );
list<uint> BijProd1N( const uint& , const uint& );
void BijProd1N( const uint& , const uint& , list<uint>& );
list<uint> BijProd1N( const list<dim>& , const uint& );
void BijProd1N( const list<dim>& , const uint& , list<uint>& );
list<uint> BijProd1Infty( const uint& );
void BijProd1Infty( const uint& , list<uint>& );
