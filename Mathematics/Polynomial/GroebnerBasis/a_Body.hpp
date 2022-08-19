// c:/Users/user/Documents/Programming/Mathematics/Polynomial/GroebnerBasis/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , uint D>
void DevideNoRedundantZero( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F )
{

  vector<PolynomialIndex<D> > LT_F{};
  vector<T> LC_F{};

  for( auto itr = F.begin() , end = F.end() ; itr != end ; itr++ ){

    Polynomial<T,D>& Fi = *itr;
    const PolynomialIndex<D> LT_Fi = LeadingTermNoRedundantZero( Fi );
    LT_F.push_back( LT_Fi );
    LC_F.push_back( Fi( LT_Fi ) );
    
  }

  DevideNoRedundantZero( f , F , LT_F , LC_F );
  return;

}

template <typename T , uint D>
static void DevideNoRedundantZero_Body( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F , const vector<PolynomialIndex<D> >& LT_F , const vector<T>& LC_F , uint& i , const PolynomialIndex<D>& LT , const T& LC , bool& undevided );

template <typename T , uint D>
void DevideNoRedundantZero( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F , const vector<PolynomialIndex<D> >& LT_F , const vector<T>& LC_F )
{
  
  const T& z = Polynomial<T,0>::const_zero();
  PolynomialIndex<D> LT = LeadingTermNoRedundantZero<T,D>( f );
  Polynomial<T,D> residue{};
  const uint& size_f = f.size();
  const uint size_F = F.size();
  
  while( size_f > 0 ){

    bool undevided = true;
    T& LC = f( LT );

    for( uint i = 0 ; i < size_F ; i++ ){

      DevideNoRedundantZero_Body( f , F , LT_F , LC_F , i , LT , LC , undevided );

    }

    if( undevided ){

      residue += Polynomial<T,D>( LT , LC );
      LC = z;

    }

    LT = LeadingTerm<T,D>( f );

  }

  residue.RecursivelyRemoveRedundantZero();
  f = residue;
  return;

}

template <typename T , uint D>
void DevideNoRedundantZero( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F , const vector<PolynomialIndex<D> >& LT_F , const vector<T>& LC_F , const vector<uint>& use )
{
  
  const T& z = Polynomial<T,0>::const_zero();
  PolynomialIndex<D> LT = LeadingTermNoRedundantZero<T,D>( f );
  Polynomial<T,D> residue{};
  const uint& size_f = f.size();
  const uint size_F = F.size();
  
  while( size_f > 0 ){

    T& LC = f( LT );
    bool undevided = true;

    for( uint i = 0 ; i < size_F ; i++ ){

      if( use[i] == 1 ){

	DevideNoRedundantZero_Body( f , F , LT_F , LC_F , i , LT , LC , undevided );
	
      }
      
    }

    if( undevided ){

      residue += Polynomial<T,D>( LT , LC );
      LC = z;

    }

    LT = LeadingTerm<T,D>( f );

  }

  residue.RecursivelyRemoveRedundantZero();
  f = residue;
  return;

}

template <typename T , uint D>
void DevideNoRedundantZero_Body( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F , const vector<PolynomialIndex<D> >& LT_F , const vector<T>& LC_F , uint& i , const PolynomialIndex<D>& LT , const T& LC , bool& undevided )
{

  bool divisible = true;
  const PolynomialIndex<D>& I_F = LT_F[i];

  for( uint d = 1 ; d < D && divisible ; d++ ){

    if( LT[d] < I_F[d] ){

      divisible = false;

    }

  }

  if( divisible ){

    PolynomialIndex<D> I{};

    for( uint d = 1 ; d < D ; i++ ){

      I[d] = LT[d] - I_F[d];

    }

    Polynomial<T,D> q{ I , LC / LC_F[i] };
    f -= q * F[i];
    i = D;
    undevided = false;

  }

  return;

}

template <typename T , uint D> inline auto LeadingTerm( Polynomial<T,D>& f ) -> typename enable_if< equal_to<uint>()( 0 , D ) , PolynomialIndex<D> >::type { return PolynomialIndex<D>(); }
template <typename T , uint D> inline auto LeadingTerm( Polynomial<T,D>& f ) -> typename enable_if< less_equal<uint>()( 1 , D ) , PolynomialIndex<D> >::type { f.RecursivelyRemoveRedundantZero(); return LeadingTermNoRedundantZero( f ); }

template <typename T , uint D> inline auto LeadingTermNoRedundantZero( const Polynomial<T,D>& f ) -> typename enable_if< equal_to<uint>()( 0 , D ) , PolynomialIndex<D> >::type { return PolynomialIndex<D>(); }
template <typename T , uint D>
auto LeadingTermNoRedundantZero( const Polynomial<T,D>& f ) -> typename enable_if< less_equal<uint>()( 1 , D ) , PolynomialIndex<D> >::type
{
  
  const uint& size = f.size();

  if( size > 0 ){

    PolynomialIndex<D> I = LeadingTermNoRedundantZero<T,D-1>( f[ size - 1 ] );
    I[D-1] = size - 1;
    return I;

  }

  return PolynomialIndex<D>();
  
}

template <typename T , uint D> 
SetLeadingTermsNoRedundantZero( const vector<Polynomial<T,D> >& F , vector<PolynomialIndex<D> >& LT_F , vector<T>& LC_F , const uint& size )
{
  
  for( uint i = 0 ; i < size ; i++ ){

    const Polynomial<T,D>& Fi = F[i];
    const PolynomialIndex<D> LT_Fi = LeadingTermNoRedundantZero( Fi );
    LT_F.push_back( LT_Fi );
    LC_F.push_back( Fi( LT_Fi ) );

  }

  return;

}

template <typename T , uint D> inline Polynomial<T,D> SPolynomial( Polynomial<T,D>& f0 , Polynomial<T,D>& f1 ) { f0.RecursivelyRemoveRedundantZero(); f1.RecursivelyRemoveRedundantZero(); SPolynomialNoRedundantZero( f0 , f1 ); }

template <typename T , uint D>
Polynomial<T,D> SPolynomialNoRedundantZero( const Polynomial<T,D>& f0 , const Polynomial<T,D>& f1 )
{

  Polynomial<T,D> LT0 = LeadingTermNoRedundantZero( f0 );
  Polynomial<T,D> LT1 = LeadingTermNoRedundantZero( f1 );
  const T& LC0 = f0( LT0 );
  const T& LC1 = f1( LT1 );
  return SPolynomialNoRedundantZero( f0 , f1 , LT0 , LT1 , LC0 , LC1 );
  
}

template <typename T , uint D>
Polynomial<T,D> SPolynomialNoRedundantZero( const Polynomial<T,D>& f0 , const Polynomial<T,D>& f1 , const PolynomialIndex<D>& LT0 , const PolynomialIndex<D>& LT1 , const T& LC0 , const T& LC1 )
{
  
  PolynomialIndex<D> I0{};
  PolynomialIndex<D> I1{};
  
  for( uint i = 0 ; i < D ; i++ ){

    const uint& LT0i = LT0[i];
    const uint& LT1i = LT1[i];

    if( LT0i < LT1i ){

      I0[i] += LT1i - LT0i;

    } else if( LT1i < LT0i ) {

      I1[i] += LT0i - LT1i;

    }

  }


  const T& zero = Polynomial<T,0>::const_zero();
  const T& one = Polynomial<T,0>::const_one();
  const Polynomial<T,D> g0 = ( LC0 == zero ? f0 : f0 * Polynomial<T,D>( I0 , one / LC0 ) );
  const Polynomial<T,D> g1 = ( LC1 == zero ? f1 : f1 * Polynomial<T,D>( I1 , one / LC1 ) );
  Polynomial<T,D> g = g0 - g1;
  g.RecursivelyRemoveRedundantZero();
  return g;

}

template <typename T , uint D>
vector<Polynomial<T,D> > GroebnerBasis( vector<Polynomial<T,D> >& F )
{

  for( auto itr = F.begin() , end = F.end() ; itr != end ; itr++ ){

    itr->RecursivelyRemoveRedundantZero();

  }

  return GroebnerBasisNoRedundantZero( F );

}

template <typename T , uint D>
vector<Polynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<Polynomial<T,D> >& F )
{

  vector<PolynomialIndex<D> > LT_F{};
  vector<T> LC_F{};
  uint size = F.size();
  SetLeadingTermsNoRedundantZero( F , LT_F , LC_F , size );

  vector<uint> i_F{};
  vector<uint> j_F{};
  
  for( uint i = 0 ; i < size ; i++ ){
    
    for( uint j = i + 1 ; j < size ; j++ ){

      i_F.push_back( i );
      j_F.push_back( j );

    }

  }

  return GroebnerBasisNoRedundantZero( F , LT_F , LC_F , i_F , j_F , size );

}

template <typename T , uint D>
vector<Polynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<Polynomial<T,D> >& F , vector<PolynomialIndex<D> >& LT_F , vector<T>& LC_F , vector<uint>& i_F , vector<uint>& j_F , uint& size )
{

  vector<Polynomial<T,D> > G{ F };
  const Polynomial<T,D>& zero = Polynomial<T,D>::zero();

  while( ! i_F.empty() ){

    const uint& i = i_F.back();
    const uint& j = j_F.back();
    Polynomial<T,D> f = SPolynomialNoRedundantZero( G[i] , G[j] , LT_F[i] , LT_F[j] , LC_F[i] , LC_F[j] );
    i_F.pop_back();
    j_F.pop_back();
    DevideNoRedundantZero( f , G , LT_F , LC_F );

    if( f != zero ){

      const PolynomialIndex<D> LT_f = LeadingTermNoRedundantZero( f );
      G.push_back( f );
      LT_F.push_back( LT_f );
      LC_F.push_back( f( LT_f ) );      

      for( uint k = 0 ; k < size ; k++ ){

	i_F.push_back( k );
	j_F.push_back( size );

      }

      size++;

    }
    
  }
  
  return G;

}

template <typename T , uint D> vector<Polynomial<T,D> > ReducedGroebnerBasis( vector<Polynomial<T,D> >& F )
{

  for( auto itr = F.begin() , end = F.end() ; itr != end ; itr++ ){

    itr->RecursivelyRemoveRedundantZero();

  }

  return ReducedGroebnerBasisNoRedundantZero( F );

}

template <typename T , uint D>
vector<Polynomial<T,D> > ReducedGroebnerBasisNoRedundantZero( const vector<Polynomial<T,D> >& F )
{

  vector<PolynomialIndex<D> > LT_F{};
  vector<T> LC_F{};
  uint size = F.size();
  SetLeadingTermsNoRedundantZero( F , LT_F , LC_F , size );
  return ReducedGroebnerBasisNoRedundantZero( F , LT_F , LC_F , size );

}

template <typename T , uint D>
vector<Polynomial<T,D> > ReducedGroebnerBasisNoRedundantZero( const vector<Polynomial<T,D> >& F , vector<PolynomialIndex<D> >& LT_F , vector<T>& LC_F , uint& size )
{

  vector<uint> i_F{};
  vector<uint> j_F{};
  
  for( uint i = 0 ; i < size ; i++ ){
    
    for( uint j = i + 1 ; j < size ; j++ ){

      i_F.push_back( i );
      j_F.push_back( j );

    }

  }

  const vector<Polynomial<T,D> > G = GroebnerBasisNoRedundantZero( F , LT_F , LC_F , i_F , j_F , size );

  // ã…è¨âª
  vector<uint> use{};
  use.reserve( size );

  for( uint i = 0 ; i < size ; i++ ){

    use.push_back( 1 );

  }

  for( uint i = 0 ; i < size ; i++ ){

    const PolynomialIndex<D>& LT_Fi = LT_F[i];
    uint& use_i = use[i];

    for( uint j = 0 ; j < size && use_i == 1 ; j++ ){

      if( use[j] == 1 ){

	if( i != j ){

	  bool divisible = true;
	  const PolynomialIndex<D>& LT_Fj = LT_F[j];

	  for( uint d = 0 ; d < D && divisible ; d++ ){

	    if( LT_Fi[d] < LT_Fj[d] ){

	      divisible = false;

	    }
	  
	  }

	  if( divisible ){

	    use_i = 0;

	  }
	  
	}
	
      }

    }

  }

  // ëäå›ä»ñÒâª
  vector<Polynomial<T,D> > G_min{};
  vector<T> LC_min{};
  LC_min.reserve( size );
  
  for( uint i = 0 ; i < size ; i++ ){

    if( use[i] == 1 ){

      vector<uint> use_current = use;
      use_current[i] = 0;
      G_min.push_back( G[i] );
      Polynomial<T,D>& f = G_min.back();
      DevideNoRedundantZero( f , G , LT_F , LC_F , use_current );
      const PolynomialIndex<D> I = LeadingTermNoRedundantZero( f );
      f /= f( I );

    }
    
  }

  return G_min;

}

