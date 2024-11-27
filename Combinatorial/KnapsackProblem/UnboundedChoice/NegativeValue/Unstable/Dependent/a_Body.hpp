// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/NegativeValue/Unstable/Dependent/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"

// AbstractNegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsackÇ…égÇ§ÅB
#include "../a_Body.hpp"

template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename INT2 , typename INT3> inline DependentItemData<U,N_MODULE,VALUE1,VALUE2,INT1,INT2,INT3>::DependentItemData( N_MODULE M , int N1 , VALUE1 value1 , VALUE2 value2 , const vector<INT1>& choice_stability_num1 , const vector<INT2>& dependence , const vector<INT3>& init , const vector<INT3>& diff ) : m_M( move( M ) ) , m_N1( move( N1 ) ) , m_value1( move( value1 ) ) , m_value2( move( value2 ) ) , m_p_choice_stability_num1( &choice_stability_num1 ) , m_p_dependence( &dependence ) , m_p_init( &init ) , m_p_diff( &diff ) { static_assert( is_invocable_r_v<U,VALUE1,const int&,const ll&> && is_invocable_r_v<U,VALUE2,const int&,const ll&> ); const int N2 = m_p_dependence->size(); assert( N2 == int( m_p_dependence->size() ) && N2 == int( m_p_init->size() ) && N2 == int( m_p_diff->size() ) ); for( int i = 0 ; i < N2 ; i++ ){ assert( 0 <= dependence[i] && dependence[i] < m_N1 && init[i] >= 0 && diff[i] >= 1 ); } }

template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename INT2 , typename INT3>
U DependentItemData<U,N_MODULE,VALUE1,VALUE2,INT1,INT2,INT3>::operator()( const int& i , const ll& m )
{

  if( i < m_N1 ){

    return m_value1( i , m );

  }

  const int N2 = m_p_init->size();
  const int i_shifted = i - m_N1;
  assert( i_shifted < N2 );
  const int& j = ( *m_p_dependence )[i_shifted];
  const INT2& choice_stability_num1_j = ( *m_p_choice_stability_num1 )[j];
  const INT3& init_i = ( *m_p_init )[i_shifted];
  const INT3& diff_i = ( *m_p_diff )[i_shifted];
  const ll n_min = m == 0 ? 0 : init_i + ( m - 1 ) * diff_i;
  const ll n_max = init_i + m * diff_i - 1;
  const ll n_mid = min( max( n_min , ll( choice_stability_num1_j ) ) , n_max + 1 );
  U answer = m_M.Product( m_value2( i_shifted , m ) , m_M.Power( m_value1( j , choice_stability_num1_j ) , n_max - n_mid + 1 ) );

  for( ll n = n_min ; n < n_mid ; n++ ){

    answer = m_M.Product( move( answer ) , m_value1( j , n ) );

  }

  return answer;
  
}

template <typename N_MODULE , typename VALUE1 , typename VALUE2 , typename COST1 , typename COST2 , typename INT1 , typename INT2 , typename INT3>
pair<DependentItemData<ret_t<VALUE1,int,ll>,N_MODULE,VALUE1,VALUE2,INT1,INT2,INT3>,DependentItemData<ret_t<COST1,int,ll>,Module<ll,ret_t<COST1,int,ll>>,COST1,COST2,INT1,INT2,INT3>> GetDependentItemData( N_MODULE M , VALUE1 value1 , VALUE2 value2 , COST1 cost1 , COST2 cost2 , vector<INT1>& choice_stability_num1 , const vector<INT1>& choice_stability_num2 , const vector<INT2>& dependence , const vector<INT3>& init , const vector<INT3>& diff )
{

  const int N1 = choice_stability_num1.size();
  const int N2 = choice_stability_num2.size();
  using U = ret_t<VALUE1,int,ll>;
  using INT = ret_t<COST1,int,ll>;
  static_assert( !is_same_v<INT,int> && !is_same_v<INT,uint> );
  DependentItemData<U,N_MODULE,VALUE1,VALUE2,INT1,INT2,INT3> value{ move( M ) , N1 , move( value1 ) , move( value2 ) , choice_stability_num1 , dependence , init , diff };
  DependentItemData<INT,Module<ll,INT>,COST1,COST2,INT1,INT2,INT3> cost{ Module<ll,INT>() , N1 , move( cost1 ) , move( cost2 ) , choice_stability_num1 , dependence , init , diff };

  for( int i = 0 ; i < N2 ; i++ ){

    choice_stability_num1.push_back( max( ( choice_stability_num1[dependence[i]] - init[i] + diff[i] - 1 ) / diff[i] + 1 , choice_stability_num2[i] ) );

  }
  
  return { move( value ) , move( cost ) };

}

template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename COST1 , typename COST2 , typename INT2 , typename INT3 , typename INT4> inline vector<U> AbstractNegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( N_MODULE M , VALUE1 value1 , VALUE2 value2 , const U& exceptional , COST1 cost1 , COST2 cost2 , const INT1& cost_sum_bound , vector<INT2>& choice_stability_num1 , const vector<INT2>& choice_stability_num2 , const vector<INT3>& dependence , const vector<INT4>& init , const vector<INT4>& diff ) { auto [value,cost] = GetDependentItemData( M , move( value1 ) , move( value2 ) , move( cost1 ) , move( cost2 ) , choice_stability_num1 , choice_stability_num2 , dependence , init , diff ); return AbstractNegativeValueUnboundedChoiceUnstableCostwiseKnapsack( move( M ) , move( value ) , exceptional , move( cost ) , cost_sum_bound , choice_stability_num1 ); }
template <typename INT1 , typename VALUE1 , typename VALUE2 , typename INT2 , typename COST1 , typename COST2 , typename INT3, typename INT4 , typename INT5> inline vector<INT1> NegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( VALUE1 value1 , VALUE2 value2 , const INT1& exceptional , COST1 cost1 , COST2 cost2 , const INT2& cost_sum_bound , vector<INT3>& choice_stability_num1 , const vector<INT3>& choice_stability_num2 , const vector<INT4>& dependence , const vector<INT5>& init , const vector<INT5>& diff ) { return AbstractNegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( Module<ll,ret_t<VALUE1,int,ll>>() , move( value1 ) , move( value2 ) , exceptional , move( cost1 ) , move( cost2 ) , cost_sum_bound , choice_stability_num1 , choice_stability_num2 , dependence , init , diff ); }
template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename COST1 , typename COST2 , typename INT2 , typename INT3 , typename INT4> inline pair<U,INT1> AbstractNegativeValueUnboundedChoiceUnstableDependentKnapsack( N_MODULE M , VALUE1 value1 , VALUE2 value2 , const U& exceptional , COST1 cost1 , COST2 cost2 , const INT1& cost_sum_bound , vector<INT2>& choice_stability_num1 , const vector<INT2>& choice_stability_num2 , const vector<INT3>& dependence , const vector<INT4>& init , const vector<INT4>& diff ) { pair<U,INT1> answer = { M.One() , 0 }; auto value_max = AbstractNegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( move( M ) , move( value1 ) , move( value2 ) , exceptional , move( cost1 ) , move( cost2 ) , cost_sum_bound , choice_stability_num1 , choice_stability_num2 , dependence , init , diff ); for( INT1 c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && answer.first < v_c ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename INT1 , typename VALUE1 , typename VALUE2 , typename INT2 , typename COST1 , typename COST2 , typename INT3, typename INT4 , typename INT5> inline pair<INT1,INT2> NegativeValueUnboundedChoiceUnstableDependentKnapsack( VALUE1 value1 , VALUE2 value2 , const INT1& exceptional , COST1 cost1 , COST2 cost2 , const INT2& cost_sum_bound , vector<INT3>& choice_stability_num1 , const vector<INT3>& choice_stability_num2 , const vector<INT4>& dependence , const vector<INT5>& init , const vector<INT5>& diff ) { return AbstractNegativeValueUnboundedChoiceUnstableDependentKnapsack( Module<ll,ret_t<VALUE1,int,ll>>() , move( value1 ) , move( value2 ) , exceptional , move( cost1 ) , move( cost2 ) , cost_sum_bound , choice_stability_num1 , choice_stability_num2 , dependence , init , diff ); }

