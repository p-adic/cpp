// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/Carmichael/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Prime/Constexpr/a_Body.hpp"

#include "../../CRT/a_Body.hpp"
#include "../../../../Prime/a_Body.hpp"

template <typename PPF , typename INT>
tuple<INT,vector<INT>,vector<INT>,vector<INT>> CarmichaelFunction_Body( PPF ppf , const INT& n )
{
  auto [P,E,Q] = ppf( n );
  INT answer = 1;
  const int size = P.size();

  for( int i = 0 ; i < size ; i++ ){

    const INT& P_i = P[i];
    const INT& Q_i = Q[i];
    answer = LCM( answer , ( Q_i - Q_i / P_i ) );

  }

  return { answer , move( P ) , move( E ) , move( Q ) };

}

template <typename INT> inline tuple<INT,vector<INT>,vector<INT>,vector<INT>> CarmichaelFunction( const INT& n ) { return CarmichaelFunction( PrimePowerFactorisation , n ); }
template <typename INT1 , INT1 val_limit , int length_max> inline tuple<INT2,vector<INT1>,vector<int>,vector<INT1>> CarmichaelFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n ) { return CarmichaelFunction( [&]( const int& i ){ return PrimePowerFactorisation( pe , i ); } , n ); }

template <typename PRIME , typename INT>
vector<INT> CarmichaelTransformation_Body( PRIME prime , const vector<INT>& E )
{

  static_assert( !is_invocable_v<PRIME,const int&> );
  const int size = E.size();
  vector<INT> answer( size );
  
  for( int i = 0 ; i < size ; i++ ){

    const INT& E_i = E[i];

    if( E_i != 0 ){

      auto&& P_i = prime( i );
      INT& answer_i = answer[i];
      answer_i = max( answer_i , E_i - 1 );
      auto new_factor = P_i - 1;

      for( int j = 0 ; j < i ; j++ ){

	auto&& P_j = prime( j );

	if( new_factor % P_j == 0 ){

	  INT new_E = 1;

	  while( ( new_factor /= P_i ) % P_j == 0 ){

	    new_E++;

	  }

	  INT& answer_j = answer[j];
	  answer_j = max( answer_j , new_E );
	  
	}

	if( new_factor == 1 ){

	  break;
	
	}

      }

    }
   
  }

  return answer;

}

template <typename INT> inline vector<INT> CarmichaelTransformation( const vector<INT>& E ) { return CarmichaelTransformation_Body( prime , E ); }
template <typename INT1 , INT1 val_limit , int length_max , typename INT2> inline vector<INT2> CarmichaelFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const vector<INT2>& E ) { return CarmichaelTransformation_Body( [&]( const int& i ){ return pe[i]; } , E ); }
