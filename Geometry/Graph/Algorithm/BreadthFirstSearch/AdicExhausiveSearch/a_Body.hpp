// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/AdicExhausiveSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif

#include "../../../../../Combinatorial/Loop/a_Body.hpp"

inline vector<int> AdicExhausiveEdge::operator()( const int& t ) { vector<int> answer{}; int t_copy = t , N_power = 1 , temp; if( m_reversed ){ while( t_copy > 0 ){ if( ( temp = t - N_power ) >= 0 && t_copy % *m_p_N > 0 ){ answer.push_back( temp ); } t_copy /= *m_p_N; N_power *= *m_p_N; } } else { while( t_copy > 0 ){ if( ( temp = t + N_power ) < *m_p_V && t_copy % *m_p_N < *m_p_N_minus ){ answer.push_back( temp ); } t_copy /= *m_p_N; N_power *= *m_p_N; } } return answer; }

inline AdicExhausiveSearch::AdicExhausiveSearch( const int& N , const int& V , const bool& reversed ) : BreadthFirstSearch<int,Graph<AdicExhausiveEdge>>( m_G , -1 ) , m_G( V , AdicExhausiveEdge() ) , m_p_V( &( m_G.size() ) ) , m_N( N ) , m_N_minus( m_N - 1 ) , m_digit( 0 ) , m_N_power( 1 , 1 ) , m_valuation() { auto& edge = m_G.edge(); edge.m_p_V = m_p_V; edge.m_p_N = &m_N; edge.m_p_N_minus = &m_N_minus; edge.m_reversed = reversed; while( V > m_N_power.back() ){ m_digit++; m_N_power.push_back( m_N_power.back() * m_N ); } }
inline AdicExhausiveSearch::AdicExhausiveSearch( const int& N , const int& digit , const int& dummy , const bool& reversed ) : AdicExhausiveSearch( N , Power( N , digit ) , reversed ) {}

inline vector<int> AdicExhausiveSearch::to_vec( int t ) { assert( 0 <= t && t < *m_p_V ); vector<int> answer( m_digit ); for( int d = 0 ; d < m_digit ; d++ ){ answer[d] = t % m_N; t /= m_N; } return answer; }
inline int AdicExhausiveSearch::to_int( const vector<int>& a ) { int answer = 0; const int size = a.size(); assert( size <= m_digit ); for( int d = 0 ; d < size ; d++ ){ answer += a[d] * m_N_power[d]; } return answer; }

inline vector<int> AdicExhausiveSearch::UnreachedAdjacentUpperboundOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); vector<int> answer{}; int t_copy = t , temp; for( int d = 0 ; t_copy < 0 && d < m_digit && ( temp = t + m_N_power[d] ) < *m_p_V ; d++ ){ if( ! this->found( temp ) && t_copy % m_N < m_N_minus ){ answer.push_back( temp ); } t_copy /= m_N; } return answer; }
inline vector<int> AdicExhausiveSearch::UnreachedProperUpperboundOf( const int& t ) { vector<int> answer{}; auto index = to_vec( t ) , lower_bound = index , upper_limit = vector( m_digit , m_N ); int temp; while( NextLoop( m_digit , lower_bound , upper_limit , index ) ){ if( ! this->found( temp = to_int( index ) ) ){ answer.push_back( temp ); } } return answer; }

inline vector<int> AdicExhausiveSearch::UnreachedAdjacentLowerboundOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); vector<int> answer{}; int t_copy = t , temp; for( int d = 0 ; t_copy < 0 && d < m_digit && ( temp = t - m_N_power[d] ) >= 0 ; d++ ){ if( ! this->found( temp ) && t_copy % m_N > 0 ){ answer.push_back( temp ); } t_copy /= m_N; } return answer; }
inline vector<int> AdicExhausiveSearch::UnreachedProperLowerboundOf( const int& t ) { vector<int> answer{ 0 }; auto index = vector( m_digit , 0 ) , lower_bound = index , upper_limit = to_vec( t ); int temp; for( int d = 0 ; d < m_digit ; d++ ){ upper_limit[d]++; } while( NextLoop( m_digit , lower_bound , upper_limit , index ) ){ if( ! this->found( temp = to_int( index ) ) ){ answer.push_back( temp ); } } answer.pop_back(); return answer; }

inline vector<int> AdicExhausiveSearch::AdjacentUpperboundOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); vector<int> answer{}; int t_copy = t , temp; for( int d = 0 ; t_copy < 0 && d < m_digit && ( temp = t + m_N_power[d] ) < *m_p_V ; d++ ){ if( t_copy % m_N < m_N_minus ){ answer.push_back( temp ); } t_copy /= m_N; } return answer; }
inline vector<int> AdicExhausiveSearch::ProperUpperboundOf( const int& t ) { vector<int> answer{}; auto index = to_vec( t ) , lower_bound = index , upper_limit = vector( m_digit , m_N ); while( NextLoop( m_digit , lower_bound , upper_limit , index ) ){ answer.push_back( to_int( index ) ); } return answer; }
inline vector<int> AdicExhausiveSearch::AdjacentLowerboundOf( const int& t ) { assert( 0 <= t ); vector<int> answer{}; int t_copy = t , temp; for( int d = 0 ; t_copy < 0 && d < m_digit && ( temp = t - m_N_power[d] ) >= 0 ; d++ ){ if( t_copy % m_N > 0 ){ answer.push_back( temp ); } t_copy /= m_N; } return answer; }
inline vector<int> AdicExhausiveSearch::ProperLowerboundOf( const int& t ) { vector<int> answer{ 0 }; auto index = vector( m_digit , 0 ) , lower_bound = index , upper_limit = to_vec( t ); for( int d = 0 ; d < m_digit ; d++ ){ upper_limit[d]++; } while( NextLoop( m_digit , lower_bound , upper_limit , index ) ){ answer.push_back( to_int( index ) ); } answer.pop_back(); return answer; }

inline bool AdicExhausiveSearch::NextPermutation( int& t ) { auto S = to_vec( t ); return prev_permutation( S.begin() , S.end() ) ? ( t = to_int( S ) ) < *m_p_V : false; }
inline bool AdicExhausiveSearch::NextPermutation( vector<int>& S ) { return prev_permutation( S.begin() , S.end() ) ? to_int( S ) < *m_p_V : false; }

inline int AdicExhausiveSearch::DigitOf( const int& t ) { assert( 0 <= t && t < *m_p_V ); int d = 0 , N_power = 1; while( t >= N_power ){ d++; N_power *= m_N; } return d; }

inline const int& AdicExhausiveSearch::ValuationOf( const int& t )
{

  static unordered_map<int,int> g_v;
  static int length = 0;

  while( g_v.count( t ) == 0 ){

    assert( length <= m_digit && t >= m_N_power[length] );
    g_v[m_N_power[length]] = length;
    length++;

  }

  return g_v[t];
  
}
inline const int& AdicExhausiveSearch::Power( const int& digit ) const { assert( 0 <= digit && digit <= m_digit ); return m_N_power[digit]; }

inline int AdicExhausiveSearch::Power( int N , int digit ) { return digit == 0 ? 1 : digit == 1 ? N : Power( N * N , digit >> 1 ) * ( ( digit & 1 ) == 1 ? N : 1 ); }
