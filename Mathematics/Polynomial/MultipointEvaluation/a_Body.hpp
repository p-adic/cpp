// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline void SetMultipointEvaluation( const Polynomial<T>& f , const VLArray<T>& point , VLArray<T>& answer ) { VLArray<VLArray<TruncatedPolynomial<T> > > pt{}; SetMultipointEvaluation_Body( point , pt ); SetMultipointEvaluation( f , pt , answer ); }

template <typename T>
void SetMultipointEvaluation( const Polynomial<T>& f , const VLArray<VLArray<TruncatedPolynomial<T> > >& point_tree , VLArray<T>& answer )
{

  const VLArray<TruncatedPolynomial<T> >& prod = point_tree.front();

  if( prod.empty() ){

    return;

  }

  VLArray<Polynomial<T> > residue = {};
  const Polynomial<T>& zero = Polynomial<T>::zero();
  residue.push_back( zero );
  residue.back() = move( f % prod.front() );

  auto itr_tree = point_tree.begin() , end_tree = point_tree.end();
  itr_tree++;

  while( itr_tree != end_tree ){

    auto itr_residue = residue.begin() , end_residue = residue.end();
    auto itr_node = itr_tree->begin() , end_node = itr_tree->end();

    while( itr_residue != end_residue ){

      const TruncatedPolynomial<T>& f = *itr_tree;
      itr_tree++;

      if( itr_tree != end_tree ){
	
	*( residue.insert( itr_residue , zero ) ) = move( *itr_residue % f );
	*itr_residue %= *itr_tree;
	itr_tree++;

      }
      
      itr_residue++;
      
    }

    itr_tree++;

  }

  
  for( auto itr_residue = residue.begin() , end_residue = residue.end() ; itr_residue != end_residue ; itr_residue++ ){

    answer.push_back( ( *itr_residue )[0] );

  }

  return;
  
}

template <typename T>
void SetPointTree( const VLArray<T>& point , VLArray<VLArray<TruncatedPolynomial<T> > >& point_tree )
{

  static const VLArray<TruncatedPolynomial<T> > empty{};
  point_tree.push_front( empty );
  VLArray<TruncatedPolynomial<T> >& linear = point.back();

  for( auto itr = point.begin() , end = point.end() ; itr != end ; itr++ ){

    static const TruncatedPolynomial<T> x{ 2 , 1 , Polynomial<T>::const_one() };
    linear.push_back( x );
    linear.back()[0] -= *itr;

  }

  VLArray<TruncatedPolynomial<T>> *p_node = &( point_tree.back() );
  
  while( p_node->size() > 2 ){

    point_tree.push_front( empty );
    VLArray<TruncatedPolynomial<T> >& node_curr = point.back();

    for( auto itr = p_node->begin() , end = p_node->end() ; itr != end ; itr++ ){

      static const Polynomial<T> null = TruncatedPolynomial<T>();
      node_curr.push_back( null );
      TruncatedPolynomial<T>& f = *itr;
      itr++;

      if( itr != end ){
	
	TruncatedPolynomial<T>& g = *itr;
	const uint size = f.size() + g.size() - 1;
	f.SetTruncation( size );
	g.SetTruncation( size );
	TruncatedPolynomial<T>& fg = node_curr.back();
	fg = move( f * g );

      }

    }

    p_node = &node_curr;

  }

  return;
  
}
