// c:/Users/user/Documents/Programming/Mathematics/Polynomial/GroebnerBasis/a.hpp

#pragma once
#include "../Multivariable/a.hpp"

template <typename T , uint D>
void DevideNoRedundantZero( MultivariablePolynomial<T,D>& f , const vector<MultivariablePolynomial<T,D> >& F );
template <typename T , uint D>
void DevideNoRedundantZero( MultivariablePolynomial<T,D>& f , const vector<MultivariablePolynomial<T,D> >& F , const vector<MultivariablePolynomialIndex<D> >& LT_F , const vector<T>& LC_F );
template <typename T , uint D>
void DevideNoRedundantZero( MultivariablePolynomial<T,D>& f , const vector<MultivariablePolynomial<T,D> >& F , const vector<MultivariablePolynomialIndex<D> >& LT_F , const vector<T>& LC_F , const vector<uint>& use );


template <typename T , uint D> inline auto LeadingTerm( MultivariablePolynomial<T,D>& f ) -> typename enable_if< equal_to<uint>()( 0 , D ) , MultivariablePolynomialIndex<D> >::type;
template <typename T , uint D> inline auto LeadingTerm( MultivariablePolynomial<T,D>& f ) -> typename enable_if< less_equal<uint>()( 1 , D ) , MultivariablePolynomialIndex<D> >::type;
template <typename T , uint D> inline auto LeadingTermNoRedundantZero( const MultivariablePolynomial<T,D>& f ) -> typename enable_if< equal_to<uint>()( 0 , D ) , MultivariablePolynomialIndex<D> >::type;
template <typename T , uint D> inline auto LeadingTermNoRedundantZero( const MultivariablePolynomial<T,D>& f ) -> typename enable_if< less_equal<uint>()( 1 , D ) , MultivariablePolynomialIndex<D> >::type;


template <typename T , uint D> 
void SetLeadingTermsNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<T>& LC_F , const uint& size );


template <typename T , uint D> inline MultivariablePolynomial<T,D> SMultivariablePolynomial( MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 );
template <typename T , uint D>
MultivariablePolynomial<T,D> SMultivariablePolynomialNoRedundantZero( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 );
template <typename T , uint D>
MultivariablePolynomial<T,D> SMultivariablePolynomialNoRedundantZero( const MultivariablePolynomial<T,D>& f0 , const MultivariablePolynomial<T,D>& f1 , const MultivariablePolynomialIndex<D>& LT0 , const MultivariablePolynomialIndex<D>& LT1 , const T& LC0 , const T& LC1 );


template <typename T , uint D>
vector<MultivariablePolynomial<T,D> > GroebnerBasis( vector<MultivariablePolynomial<T,D> >& F );
template <typename T , uint D>
vector<MultivariablePolynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F );
template <typename T , uint D>
vector<MultivariablePolynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<T>& LC_F , vector<uint>& i_F , vector<uint>& j_F , uint& size );

template <typename T , uint D>
vector<MultivariablePolynomial<T,D> > ReducedGroebnerBasis( vector<MultivariablePolynomial<T,D> >& F );
template <typename T , uint D>
vector<MultivariablePolynomial<T,D> > ReducedGroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F );
template <typename T , uint D>
vector<MultivariablePolynomial<T,D> > ReducedGroebnerBasisNoRedundantZero( const vector<MultivariablePolynomial<T,D> >& F , vector<MultivariablePolynomialIndex<D> >& LT_F , vector<T>& LC_F , uint& size );
