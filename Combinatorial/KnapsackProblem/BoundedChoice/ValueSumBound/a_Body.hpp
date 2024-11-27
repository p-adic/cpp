// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/ValueSumBound/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/Group/Module/a_Body.hpp"

template <typename U , typename N_MODULE , typename INT1 , typename INT2>
U AbstractValueBoundedChoiceValueSumBound( N_MODULE M , const vector<U>& value , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound )
{

  const int N = value.size();
  U answer0 = M.One() , answer1 = answer0;

  for( int i = 0 ; i < N ; i++ ){

    answer0 = max( answer0 , value[i] );
    answer1 = M.Product( move( answer1 ) , M.Power( value[i] , int( choice_num_bound[i] ) ) );

  }

  return max( M.Power( move( answer0 ) , int( cost_sum_bound ) ) , answer1 );

}

template <typename INT1 , typename INT2 , typename INT3> inline INT1 BoundedChoiceValueSumBound( const vector<INT1>& value , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound ) { return AbstractValueBoundedChoiceValueSumBound( Module<int,INT1>() , value , cost_sum_bound , choice_num_bound ); }
