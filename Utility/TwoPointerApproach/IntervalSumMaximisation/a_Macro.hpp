// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/IntervalSumMaximisation/a_Macro.hpp

#pragma once

#define DECLARAIION_OF_INTERVAL_SUM_MAX( MAX ) template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSum ## MAX ## imisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );

#define DEFINIION_OF_INTERVAL_SUM_MAX( MAX , INEQ )			\
  template <typename INT1 , typename INT2 , typename FUNC>		\
  vector<pair<INT1,INT2>> IntervalSum ## MAX ## imisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min , INT2 length_max ) \
  {									\
									\
    static_assert( is_invocable_r_v<INT1,FUNC,const INT1&> );		\
									\
    if( length_max == -1 ){						\
									\
      length_max = i_final - i_start + 1;				\
									\
    }									\
									\
    assert( length_min <= length_max );					\
    vector<pair<INT1,INT2>> answer( length_max - length_min + 1 , { lim , i_start - 1 } ); \
    INT1 iss{};								\
									\
    for( INT2 L = 1 ; L < length_min ; L++ ){				\
									\
      iss += func( i_start + L - 1 );					\
									\
    }									\
									\
    if( length_min == 0 && 0 INEQ lim ){				\
									\
      answer[0] = { 0 , i_start };					\
									\
    }									\
									\
    for( INT2 L = max( INT2( 1 ) , length_min ) ; L <= length_max ; L++ ){ \
									\
      INT1 temp = iss += func( i_start + L - 1 );			\
      pair<INT1,INT2>& answer_L = answer[L - length_min];		\
									\
      for( INT2 i = i_start + L - 1 ; i <= i_final ; i++ ){		\
									\
	if( ( answer_L.first == lim || answer_L.first INEQ temp ) && temp INEQ lim ){ \
									\
	  answer_L = { temp , i - L + 1 };				\
									\
	}								\
									\
	if( i < i_final ){						\
									\
	  temp += func( i + 1 ) - func( i - L + 1 );			\
									\
	}								\
									\
      }									\
									\
    }									\
									\
    return answer;							\
									\
  }									\

