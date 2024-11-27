// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/964722
// https://yukicoder.me/submissions/964718
// https://yukicoder.me/submissions/964721

// 例えば長さNの非負整数値配列Aで極大な正値区間とそこでの総和を取得したい場合
// auto update_L = [&]( int& i_L , auto& i_info ){ i_info -= A[i_L++]; };
// auto update_R = [&]( int& i_R , auto& i_info ){ if( ++i_R < N ){ i_info += A[i_R]; } };
// TPA( interval , i , 0 , i_R < N , update_L( i_L , i_info ) , update_R( i_R , i_info ) , A[i_L] > 0 && A[i_R] > 0 , ll( A[0] ) );
// とすればtuple<int,int,ll>値配列intervalに{左端,右端,総和}の列が格納される。

// i_infoもintervalにコピーされるので、setやvectorなどのコピーのコストが大きいデータを
// 用いてon,off判定する時はTPAより前に宣言して使う。
