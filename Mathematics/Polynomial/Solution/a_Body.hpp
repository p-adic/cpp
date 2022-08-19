// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Solution/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Arithmetic/Mod/a_Body.hpp"

#include "../GroebnerBasis/a_Body.hpp"

template <INT_TYPE_FOR_MOD P uint D>
void Solve( vector<Polinomial<Mod<P>,D> >& F , AffineSpace<Mod<P>,D>& x , bool& solvable )
{

  uint size_F = F.size();
  vector<PolynomialIndex<D> > LT_F{};
  vector<Mod<P>> LC_F{};
  SetLeadingTermsNoRedundantZero( F , LT_F , LC_F , size_F );
  F = ReducedGroebnerBasisNoRedundantZero( F , LT_F , LC_F , size_F );
  const Mod<P>& one = Polynomial<Mod<P>,0>::const_one();
  
  if( size_F == 1 ? F.front() == one : false ){

    solvable = false;
    return;

  }

  solvable = true;

  for( uint d = 0 ; d < D ; d++ ){

    bool searching = true;
    Mod<P> xd{};
    
    for( int i = 0 ; i < P && searching ; i++ ){

      vector<Polinomial<Mod<P>,D> > G{ F };
      vector<PolynomialIndex<D> > LT_G{ LT_F};
      vector<Mod<P>> LC_G{ LC_F };
      PolynomialIndex<D> Id{};
      Id[d] = 1;
      G.push_back( Polynomial<Mod<P>,D>( Id , one ) - xd );
      LT_G.push_back( Id );
      LC_G.push_back( one );
      uint size_G = size_F + 1;
      G = ReducedGroebnerBasisNoRedundantZero( G , LT_G , LC_G , size_G );

      if( size_G == 1 ? G.front() != one : true ){

	searching = false;
	x[d] = xd;
	F = G;
	LT_F = LT_G;
	LC_F = LT_G;
	size = size_G;

      } else {

	xd += 1;
	
      }
      
    }

  }

  return;

}
