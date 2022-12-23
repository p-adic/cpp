// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename V> inline void SetMultipointEvaluation( const Polynomial<T>& f , const V& point , V& answer ) { VLArray<VLArray<Polynomial<T> > > pt{}; SetPointTree( point , pt ); SetMultipointEvaluation( f , pt , answer ); }

template <typename T , typename V>
void SetMultipointEvaluation( const Polynomial<T>& f , const VLArray<VLArray<Polynomial<T> > >& point_tree , V& answer )
{

  const VLArray<Polynomial<T> >& prod = point_tree.front();

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

      const Polynomial<T>& f = *itr_node;
      itr_node++;

      if( itr_node != end_node ){

	*( residue.insert( itr_residue , zero ) ) = move( *itr_residue % f );
	*itr_residue %= *itr_node;
	itr_node++;

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
void SetProductTree( VLArray<VLArray<T> >& product_tree )
{

  VLArray<T> empty{};
  VLArray<T> *p_node = &( product_tree.back() );
  
  while( p_node->size() > 1 ){

    product_tree.push_front( empty );
    VLArray<T>& node_curr = product_tree.front();

    for( auto itr = p_node->begin() , end = p_node->end() ; itr != end ; itr++ ){

      static const T null{};
      node_curr.push_back( null );
      T& f = *itr;
      itr++;

      if( itr == end ){

	node_curr.back() = f;
	break;
	
      } else {
	
	node_curr.back() = move( f * *itr );

      }

    }

    p_node = &node_curr;

  }

  return;

}

template <typename T , typename V>
void SetPointTree( const V& point , VLArray<VLArray<Polynomial<T> > >& point_tree )
{

  static const VLArray<Polynomial<T> > empty{};
  point_tree.push_front( empty );
  VLArray<Polynomial<T> >& linear = point_tree.front();

  for( auto itr = point.begin() , end = point.end() ; itr != end ; itr++ ){

    static const Polynomial<T> x{ 1 , Polynomial<T>::const_one() };
    linear.push_back( x );
    linear.back()[0] -= *itr;

  }

  SetProductTree( point_tree );
  return;
  
}
