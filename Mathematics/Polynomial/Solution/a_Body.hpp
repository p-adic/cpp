// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Solution/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Multivariable/a_Body.hpp"
#include "../../Arithmetic/Mod/a_Body.hpp"

#include "../GroebnerBasis/a_Body.hpp"

template <INT_TYPE_FOR_MOD P , uint D>
void CheckSolvable( vector<MultivariablePolynomial<Mod<P>,D> >& F , bool& solvable )
{

  for( auto itr = F.begin() , end = F.end() ; itr != end ; itr++ ){

    itr->RecursivelyRemoveRedundantZero();

  }

  vector<MultivariablePolynomialIndex<D> > LT_F{};
  vector<Mod<P> >& LC_F{};
  uint size_F = F.size();
  SetLeadingTermsNoRedundantZero( F , LT_F , LC_F , size_F );
  CheckSolvable( F , LT_F , LC_F , size_F , solvable );
  return;
  
}

template <INT_TYPE_FOR_MOD P , uint D>
void CheckSolvableNoRedundantZero( vector<MultivariablePolynomial<Mod<P>,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<Mod<P> >& LC_F , uint& size_F , bool& solvable )
{
  
  F = ReducedGroebnerBasisNoRedundantZero( F , LT_F , LC_F , size_F );
  const Mod<P>& one = MultivariablePolynomial<Mod<P>,0>::c_one();
  
  if( size_F == 1 ? F.front() == one : false ){

    solvable = false;
    return;

  }

  solvable = true;
  return;
  
}

template <INT_TYPE_FOR_MOD P , uint D>
void Solve( vector<MultivariablePolynomial<Mod<P>,D> >& F , AffineSpace<Mod<P>,D>& x , bool& solvable )
{

  for( auto itr = F.begin() , end = F.end() ; itr != end ; itr++ ){

    itr->RecursivelyRemoveRedundantZero();

  }

  vector<MultivariablePolynomialIndex<D> > LT_F{};
  vector<Mod<P> > LC_F{};
  uint size_F = F.size();
  SetLeadingTermsNoRedundantZero( F , LT_F , LC_F , size_F );
  SolveNoRedundantZero( F , LT_F , LC_F , size_F , x , solvable );
  return;

}

template <INT_TYPE_FOR_MOD P , uint D>
void SolveNoRedundantZero( vector<MultivariablePolynomial<Mod<P>,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<Mod<P> >& LC_F , uint& size_F , AffineSpace<Mod<P>,D>& x , bool& solvable )
{

  CheckSolvableNoRedundantZero( F , LT_F , LC_F , size , solvable );

  if( solvable ){
    
    FindSolutionFromReducedGroebnerBasis( F , LT_F , LC_F , size_F , x );

  }

  return;
  
}

template <INT_TYPE_FOR_MOD P , uint D>
void FindSolutionFromReducedGroebnerBasis( vector<MultivariablePolynomial<Mod<P>,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<Mod<P> >& LC_F , uint& size_F , AffineSpace<Mod<P>,D>& x )
{
  
  const Mod<P>& one = MultivariablePolynomial<Mod<P>,0>::c_one();

  for( uint d = 0 ; d < D ; d++ ){

    bool searching = true;
    Mod<P> xd{};
    
    for( int i = 0 ; i < P && searching ; i++ ){

      vector<MultivariablePolynomial<Mod<P>,D> > G{ F };
      vector<MultivariablePolynomialIndex<D> > LT_G{ LT_F};
      vector<Mod<P>> LC_G{ LC_F };
      MultivariablePolynomialIndex<D> Id{};
      Id[d] = 1;
      G.push_back( MultivariablePolynomial<Mod<P>,D>( Id , one ) - xd );
      LT_G.push_back( Id );
      LC_G.push_back( one );
      uint size_G = size_F + 1;
      G = ReducedGroebnerBasisNoRedundantZero( G , LT_G , LC_G , size_G );

      if( size_G == 1 ? G.front() != one : true ){

	searching = false;
	x[d] = xd;
	F = G;
	LT_F = LT_G;
	LC_F = LC_G;
	size_F = size_G;

      } else {

	xd += 1;
	
      }
      
    }

  }

  return;

}
