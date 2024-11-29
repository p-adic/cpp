// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/ValueMaximisation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a_Body.hpp"

#ifdef DEBUG
  #include "../../../../SetTheory/DirectProduct/CoordinateCompress/Debug/a_Body.hpp"
#else
  #include "../../../../SetTheory/DirectProduct/CoordinateCompress/a_Body.hpp"
#endif


template <typename INT , typename U , typename MONOID>
U AbstractGridValueMaximisation_Body( MONOID M , const INT& W , const multiset<tuple<INT,INT,U>>& S , const bool& skippable , const U& min_U )
{

  IntervalMaxBIT a{ min_U , vector( W , min_U ) };

  if( skippable ){

    for( auto& [i,j,w] : S ){

      a.SetMax( j , M.Product( a.IntervalMax( 0 , j ) , w ) );

    }

  } else {

    for( auto& [i,j,w] : S ){

      a.Set( j , M.Product( a.IntervalMax( 0 , j ) , w ) );

    }

  }

  return a.IntervalMax( 0 , W-1 );

}

template <typename INT , typename U , typename MONOID>
U AbstractGridValueMaximisation( MONOID M , const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable , const U& min_U )
{

  multiset<tuple<INT,INT,U>> S{};

  for( auto& [i,j,w] : v ){

    if( 0 <= i && 0 <= j && j < W ){
      
      S.insert( { i , j , w } );

    }

  }

  return AbstractGridValueMaximisation_Body<INT,U,MONOID>( move( M ) , W , S , skippable , min_U );

}

template <typename INT , typename U> inline U GridValueMaximisation( const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable , const U& min_U ) { return AbstractGridValueMaximisation<INT,U,AdditiveMonoid<U>>( AdditiveMonoid<U>() , W , v , skippable , min_U ); }

template <typename INT , typename U> inline U CompressedGridValueMaximisation( const vector<tuple<INT,INT,U>>& v , const bool& skippable , const U& min_U )
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

      S.insert( { i , cc_result_inv[j] , w } );

    }

  }

  return AbstractGridValueMaximisation_Body<INT,U,AdditiveMonoid<U>>( AdditiveMonoid<U>() , INT( cc_result.size() ) , S , skippable , min_U );

}
