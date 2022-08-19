// c:/Users/user/Documents/Programming/Mathematics/Polynomial/GroebnerBasis/a.hpp

#pragma once
#include "../a.hpp"

template <typename T , uint D>
void DevideNoRedundantZero( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F );
template <typename T , uint D>
void DevideNoRedundantZero( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F , const vector<PolynomialIndex<D> >& LT_F , const vector<T>& LC_F );
template <typename T , uint D>
void DevideNoRedundantZero( Polynomial<T,D>& f , const vector<Polynomial<T,D> >& F , const vector<PolynomialIndex<D> >& LT_F , const vector<T>& LC_F , const vector<uint>& use );


template <typename T , uint D> inline auto LeadingTerm( Polynomial<T,D>& f ) -> typename enable_if< equal_to<uint>()( 0 , D ) , PolynomialIndex<D> >::type;
template <typename T , uint D> inline auto LeadingTerm( Polynomial<T,D>& f ) -> typename enable_if< less_equal<uint>()( 1 , D ) , PolynomialIndex<D> >::type;
template <typename T , uint D> inline auto LeadingTermNoRedundantZero( const Polynomial<T,D>& f ) -> typename enable_if< equal_to<uint>()( 0 , D ) , PolynomialIndex<D> >::type;
template <typename T , uint D> inline auto LeadingTermNoRedundantZero( const Polynomial<T,D>& f ) -> typename enable_if< less_equal<uint>()( 1 , D ) , PolynomialIndex<D> >::type;


template <typename T , uint D> inline Polynomial<T,D> SPolynomial( Polynomial<T,D>& f0 , const Polynomial<T,D>& f1 );
template <typename T , uint D>
Polynomial<T,D> SPolynomialNoRedundantZero( const Polynomial<T,D>& f0 , const Polynomial<T,D>& f1 );
template <typename T , uint D>
Polynomial<T,D> SPolynomialNoRedundantZero( const Polynomial<T,D>& f0 , const Polynomial<T,D>& f1 , const PolynomialIndex<D>& LT0 , const PolynomialIndex<D>& LT1 , const T& LC0 , const T& LC1 );


template <typename T , uint D>
vector<Polynomial<T,D> > GroebnerBasis( vector<Polynomial<T,D> >& F );
template <typename T , uint D>
vector<Polynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<Polynomial<T,D> >& F );
template <typename T , uint D>
vector<Polynomial<T,D> > GroebnerBasisNoRedundantZero( const vector<Polynomial<T,D> >& F , vector<PolynomialIndex<D> >& LT_F , vector<T>& LC_F , vector<uint>& i_F , vector<uint>& j_F , uint& size );

template <typename T , uint D>
vector<Polynomial<T,D> > ReducedGroebnerBasis( vector<Polynomial<T,D> >& F );
template <typename T , uint D>
vector<Polynomial<T,D> > ReducedGroebnerBasisNoRedundantZero( const vector<Polynomial<T,D> >& F );

