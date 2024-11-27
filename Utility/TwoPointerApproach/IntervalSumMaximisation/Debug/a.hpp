// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/IntervalSumMaximisation/Debug/a.hpp

#pragma once

// デバッグ用にマクロを展開してデバッグ出力を追加したもの。

template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMaximisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );
template <typename INT1 , typename INT2 , typename FUNC> vector<pair<INT1,INT2>> IntervalSumMinimisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min = 0 , INT2 length_max = -1 );
