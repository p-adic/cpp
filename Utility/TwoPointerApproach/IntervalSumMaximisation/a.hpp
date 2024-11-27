// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/IntervalSumMaximisation/a.hpp

#pragma once
#include "a_Macro.hpp"

// FUNCは写像funct:Z->Zに相当する型。
// answer[i]に[i_start,i_final]の長さlength_min+iの連続部分列におけるfuncの値の総和の
// lim未満の最大値および対応する区間の左端を格納する。
// - ただし長さが0の場合は左端をi_startとする。
// - ただしlim未満の総和を持つ部分列が存在しない場合は{exceptional,i_start-1}を格納する。
// （O((i_final-i_start+2-length_min)(length_max - length_min+1))）

// template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMaximisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );
DECLARAIION_OF_INTERVAL_SUM_MAX( Max );

// template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMinimisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );
DECLARAIION_OF_INTERVAL_SUM_MAX( Min );
