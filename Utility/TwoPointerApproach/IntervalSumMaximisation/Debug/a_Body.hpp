// c:/Users/user/Documents/Programming/Utility/TwoPointerApproach/IntervalSumMaximisation/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT1 , typename INT2 , typename FUNC>
vector<pair<INT1,INT2>> IntervalSumMaximisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min , INT2 length_max )
{

  static_assert( is_invocable_r_v<INT1,FUNC,const INT1&> );
  ofs_err << "IntervalSumMaximisationをデバッグモードで実行します。" << endl;
  ofs_err << "成分が[" << i_start << "," << i_final << "]の範囲、長さが[" << length_min << "," << length_max << "]の範囲で" << endl;
  ofs_err << lim << "未満の最大値を求めます。" << endl;

  if( length_max == -1 ){

    length_max = i_final - i_start + 1;

  }

  assert( length_min <= length_max );
  vector<pair<INT1,INT2>> answer( length_max - length_min + 1 , { lim , i_start - 1 } );
  INT1 iss{};

  for( INT2 L = 1 ; L < length_min ; L++ ){

    iss += func( i_start + L - 1 );

  }

  if( length_min == 0){

    ofs_err << "長さ" << 0 << ": ";

    if( 0 >= lim ){

      ofs_err << lim << "未満の値は見付かりませんでした。" << endl;

    } else {

      answer[0] = { 0 , i_start };
      ofs_err << 0 << "が最大値で、便宜上の左端を" << i_start << "に設定しました。" << endl;

    }

  }

  for( INT2 L = max( INT2( 1 ) , length_min ) ; L <= length_max ; L++ ){

    INT1 temp = iss += func( i_start + L - 1 );
    pair<INT1,INT2>& answer_L = answer[L - length_min];

    for( INT2 i = i_start + L - 1 ; i <= i_final ; i++ ){

      if( ( answer_L.first == lim || answer_L.first < temp ) && temp < lim ){

	answer_L = { temp , i - L + 1 };

      }

      if( i < i_final ){

	temp += func( i + 1 ) - func( i - L + 1 );

      }

    }

    ofs_err << "長さ" << L << ": ";

    if( answer_L.first == lim ){

      ofs_err << lim << "未満の値は見付かりませんでした。" << endl;

    } else {

      ofs_err << answer_L.first << "が最大値で、その時の左端の最小値は" << answer_L.second << "です。" << endl;

    }

  }

  ofs_err << endl;
  return answer;

}

template <typename INT1 , typename INT2 , typename FUNC>
vector<pair<INT1,INT2>> IntervalSumMinimisation( const FUNC& func , const INT1& lim, const INT2& i_start , const INT2& i_final , const INT2& length_min , INT2 length_max )
{

  static_assert( is_invocable_r_v<INT1,FUNC,const INT1&> );
  ofs_err << "IntervalSumMinimisationをデバッグモードで実行します。" << endl;
  ofs_err << "成分が[" << i_start << "," << i_final << "]の範囲、長さが[" << length_min << "," << length_max << "]の範囲で" << endl;
  ofs_err << lim << "より大きい最小値を求めます。" << endl;

  if( length_max == -1 ){

    length_max = i_final - i_start + 1;

  }

  assert( length_min <= length_max );
  vector<pair<INT1,INT2>> answer( length_max - length_min + 1 , { lim , i_start - 1 } );
  INT1 iss{};

  for( INT2 L = 1 ; L < length_min ; L++ ){

    iss += func( i_start + L - 1 );

  }

  if( length_min == 0){

    ofs_err << "長さ" << 0 << ": ";

    if( 0 <= lim ){

      ofs_err << lim << "より大きい値は見付かりませんでした。" << endl;

    } else {

      answer[0] = { 0 , i_start };
      ofs_err << 0 << "が最小値で、便宜上の左端を" << i_start << "に設定しました。" << endl;

    }

  }
  
  for( INT2 L = max( INT2( 1 ) , length_min ) ; L <= length_max ; L++ ){

    INT1 temp = iss += func( i_start + L - 1 );
    pair<INT1,INT2>& answer_L = answer[L - length_min];

    for( INT2 i = i_start + L - 1 ; i <= i_final ; i++ ){

      if( ( answer_L.first == lim || answer_L.first > temp ) && temp > lim ){

	answer_L = { temp , i - L + 1 };

      }

      if( i < i_final ){

	temp += func( i + 1 ) - func( i - L + 1 );

      }

    }

    ofs_err << "長さ" << L << ": ";

    if( answer_L.first == lim ){

      ofs_err << lim << "より大きい値は見付かりませんでした。" << endl;

    } else {

      ofs_err << answer_L.first << "が最小値で、その時の左端の最小値は" << answer_L.second << "です。" << endl;

    }
    
  }

  ofs_err << endl;
  return answer;

}

