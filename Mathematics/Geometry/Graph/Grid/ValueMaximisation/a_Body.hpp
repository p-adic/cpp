// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/ValueMaximisation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/Group/Module/a_Body.hpp"
#include "../../../../Algebra/Monoid/SemiLattice/a_Body.hpp"
#include "../../../../SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/a_Body.hpp"

#ifdef DEBUG
  #include "../../../../SetTheory/DirectProduct/CoordinateCompress/Debug/a_Body.hpp"
#else
  #include "../../../../SetTheory/DirectProduct/CoordinateCompress/a_Body.hpp"
#endif


template <typename INT , typename U , typename MONOID , template <typename...> typename DATA_STR>
U AbstractGridValueMaximisation_Body( MONOID M , const INT& W , const multiset<tuple<INT,INT,U>>& S , const bool& skippable )
{

  const U& one = M.One();
  DATA_STR a{ RegularRSet{ MaxSemilattice{ one } } , RegularRSet{ MaxSemilattice{ one } } , vector( W , one ) };

  if( skippable ){

    for( auto& [i,j,w] : S ){

      a.IntervalAct( -j , W - 1 , M.Product( a[-j] , w ) );

    }

  } else {

    for( auto& [i,j,w] : S ){

      a.Set( -j , M.Product( a[-j] , w ) );
      a.IntervalAct( -j , W - 1 , a[-j] );

    }

  }

  return a[W-1];

}

template <typename INT , typename U , typename MONOID , template <typename...> typename DATA_STR>
U AbstractGridValueMaximisation( MONOID M , const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable )
{

  multiset<tuple<INT,INT,U>> S{};

  for( auto& [i,j,w] : v ){

    if( 0 <= i && 0 <= j && j < W ){
      
      S.insert( { i , -j , w } );

    }

  }

  return AbstractGridValueMaximisation<INT,U,MONOID,DATA_STR>( move( M ) , W , S , skippable );

}

template <typename INT , typename U> inline U GridValueMaximisation( const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable ) { return AbstractGridValueMaximisation<INT,U,AdditiveMonoid<U>,DualSqrtDecomposition>( AdditiveMonoid<U>() , W , v , skippable ); }

template <typename INT , typename U> inline U CompressedGridValueMaximisation( const vector<tuple<INT,INT,U>>& v , const bool& skippable )
{

  CoordinateCompress<INT> cc{};

  for( auto& [i,j,w] : v ){

    if( 0 <= i && 0 <= j ){
      
      cc.SetR( j );

    }

  }

  auto [cc_result,cc_result_inv] = cc.GetR();
  
  multiset<tuple<INT,INT,U>> S{};

  for( auto& [i,j,w] : v ){

    if( 0 <= i && 0 <= j ){

      S.insert( { i , - cc_result_inv[j] , w } );

    }

  }

  return AbstractGridValueMaximisation_Body<INT,U,AdditiveMonoid<U>,DualSqrtDecomposition>( AdditiveMonoid<U>() , INT( cc_result.size() ) , S , skippable );

}
