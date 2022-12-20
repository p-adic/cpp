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

  VLArray<Polynomial<T> > node = {};
  const Polynomial<T>& zero = Polynomial<T>::zero();
  node.push_back( zero );
  node.back() = move( f % prod.front() );

  auto itr_tree = point_tree.begin() , end_tree = point_tree.end();
  itr_tree++;

  while( itr_tree != end_tree ){

    auto itr_node = node.begin() , end_node = node.end();
    auto itr_node = itr_tree->begin() , end_node = itr_tree->end();

    while( itr_node != end_node ){

      const TruncatedPolynomial<T>& f = *itr_tree;
      itr_tree++;

      if( itr_tree != end_tree ){
	
	*( node.insert( itr_node , zero ) ) = move( *itr_node % f );
	*itr_node %= *itr_tree;
	itr_tree++;

      }
      
      itr_node++;
      
    }

    itr_tree++;

  }

  
  for( auto itr_node = node.begin() , end_node = node.end() ; itr_node != end_node ; itr_node++ ){

    answer.push_back( ( *itr_node )[0] );

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
