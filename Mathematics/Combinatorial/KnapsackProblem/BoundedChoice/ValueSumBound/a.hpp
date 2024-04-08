// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/ValueSumBound/a.hpp

#pragma once


// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してU1の全順序N加群構造である。
// を満たす場合にのみサポート。
// 計算量O(N)で
// 各iに対し項目iをchoice_num_bound[i]回まで重複選択できるとして、各コストが1以上である場合に
// コストの総和cost_sum_bound以下における価値の総和の上界を求める。
template <typename U , typename N_MODULE , typename INT1 , typename INT2>
U AbstractValueBoundedChoiceValueSumBound( N_MODULE M , const vector<U>& value , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename INT1 , typename INT2 , typename INT3> inline INT1 BoundedChoiceValueSumBound( const vector<INT1>& value , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
