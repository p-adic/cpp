// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleAnalyser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

// デバッグモードでないと翻訳単位ごとに異なる実装をDynamicModが持ってしまうるので実行時に
// Segmentation Faultとなる。
#include "../../../Mathematics/Arithmetic/Mod/DynamicModulo/Debug/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Mod/Function/DiscreteLog/a_Body.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a_Body.hpp"
#include "../../../Mathematics/LinearAlgebra/Rank/Mod/a_Body.hpp"
#include "../../../Mathematics/Polynomial/LagrangeInterpolation/a_Body.hpp"

AC( SampleAnalyser )
{
  ASK_YES_NO( "出力の法は998244353または0ですか？" );
  int P = 998244353;
  if( reply != "y" ){
    cerr << "出力の法: "; cin >> P;
  }
  DynamicMod::SetModulo( P );
  int sample_count = 3;
  ASK_YES_NO( "サンプルの個数は3個ですか？" );
  if( reply != "y" ){
    cerr << "サンプルの個数: "; cin >> sample_count;
  }
  vector<vector<ll>> input( sample_count );
  vector<DynamicMod> output( sample_count );
  cerr << "サンプル入力中の固定長な数値の個数: "; CIN( int , var );
  CERR( "" );
  bool hand = true;
  if( var == 1 ){
    ASK_NUMBER(
	       "等差数列を入力する。" ,
	       "サンプルごとに入力する。"
	       );
    hand = num == 1;
  }
  if( hand ){
    FOR( sample_num , 0 , sample_count ){
      cerr << "サンプル" << sample_num + 1 << "入力中の固定長な数値: ";
      CIN_A( ll , 0 , var , A );
      input[sample_num] = move( A );
      cerr << "サンプル" << sample_num + 1 << "出力: "; cin >> output[sample_num];
      CERR( "" );
    }
  } else {
    cerr << "初項aと公差d: "; CIN( int , a , d );
    FOR( sample_num , 0 , sample_count ){
      input[sample_num] = { a + d * sample_num };
    }
    cerr << "出力列: "; CIN_A( DynamicMod , 0 , sample_count , A );
    output = move( A );
  }
  const string P_str = to_string( P );
  int scale = 1;
  while( true ){
    PowerAnalysis( sample_count , output , scale , P );
    if( 0 < var && var <= 4 ){
      bool prime = P == 998244353 || P == 1000000007;
      if( !prime && (
		     ( var == 1 && sample_count >= 4 ) ||
		     ( var == 2 && sample_count >= 7 ) ||
		     ( var == 3 && sample_count >= 8 )
		     )
	  ){
	ASK_YES_NO( P_str + "は素数ですか？" );
	prime = reply == "y";
      }
      CERR( "サンプル出力の法" + P_str + "における" + to_string( var ) + "変数多項式補間を試みます。" );
      if( var == 1 ){
	if( sample_count < 4 || ! prime ){
	  InputPolynomialAnalysis1_few( sample_count , input , output , scale , P , P_str );
	} else {
	  InputPolynomialAnalysis1_enough( sample_count , input , output , scale , P , P_str );
	}
      } else if( var == 2 ){
	if( sample_count < 9 || !prime ){
	  InputPolynomialAnalysis2_few( sample_count , input , output , scale , P , P_str );
	} else {
	  InputPolynomialAnalysis2_enough( sample_count , input , output , scale , P , P_str );
	}
      } else if( var == 3 ){
	if( sample_count < 8 || !prime ){
	  InputPolynomialAnalysis3_few( sample_count , input , output , scale , P , P_str );
	} else {
	  InputPolynomialAnalysis3_enough( sample_count , input , output , scale , P , P_str );
	}
      } else {
	assert( var == 4 );
	InputLinearAnalysis4( sample_count , input , output , scale , P , P_str );
      }
      if( var < 3 ){
	CERR( "サンプル出力の法" + P_str + "における指数関数の一次結合による補間を試みます。" );	
	if( var == 1 ){
	  if( sample_count < 5 || ! prime ){
	    InputExponentialAnalysis1_few( sample_count , input , output , scale , P , P_str );
	  } else {
	    InputExponentialAnalysis1_enough( sample_count , input , output , scale , P , P_str );
	  }
	} else {
	  assert( var == 2 );
	  if( sample_count < 7 || !prime ){
	    InputExponentialAnalysis2_few( sample_count , input , output , scale , P , P_str );
	  } else {
	    InputExponentialAnalysis2_enough( sample_count , input , output , scale , P , P_str );
	  }
	}
      }
    }
    ASK_YES_NO( "解析範囲を広げますか？" );
    if( reply == "y" ){
      while( true ){
	int rate = 0;
	CERR( "各係数の探索範囲の拡大倍率: " ); cin >> rate;
	if( rate <= 1 ){
	  CERR( "倍率は2以上の整数にしてください。" );
	} else {
	  scale *= rate;
	  break;
	}
      }
    } else {
      break;
    }
  }
  CERR( "サンプルの解析を終了します。");
}

void PowerAnalysis( const int& sample_count , const vector<DynamicMod>& output , const int& scale , const int& P )
{
  CEXPR( int , diff_bound , 10 );
  const int diff_max = diff_bound * scale;
  const vector bases{2,3,5,6,7};
  int sqrtP = sqrt( P );
  RUN( bases , base ){
    cerr << "サンプル";
    FOR( sample_num , 0 , sample_count ){
      ( sample_num == 0 ? cerr : cerr << ", " ) << sample_num + 1;
    }
    cerr << "の出力の法" << P << "における底" << base << "の離散対数を求めます。\n";
    FOREQ( diff , - diff_max , diff_max ){
      cerr << "出力" << ( diff > 0 ? "+" : "" ) << ( diff == 0 ? "" : to_string( diff ) ) << ": ";
      bool small = true;
      FOR( sample_num , 0 , sample_count ){
	int dl = DiscreteLog( int( output[sample_num].Represent() ) + diff , base , P );
	small &= ( int( output[sample_num].Represent() ) + diff ) % P == 0 || ( 0 <= dl && dl < sqrtP );
	cerr << ( dl < 0 ? "NaN" : to_string( dl ) ) << ( sample_num == sample_count - 1 ? "" : ", " );
      }
      ( small ? cerr << " <- 0または離散対数が有意に小さい値です。" : cerr ) << "\n";
    }
    vector<int> exponent( sqrtP * 2 + 1 , sqrtP );
    DynamicMod base_mod{ base } , power = Power( base_mod , -sqrtP );
    FOREQ( d , -sqrtP , sqrtP ){
      FOR( sample_num , 0 , sample_count ){
	int temp = ( power - output[sample_num] ).Represent();
	if( temp < sqrtP ){
	  exponent[temp + sqrtP] = d;
	} else if( -sqrtP < ( temp -= P ) ){
	  exponent[temp + sqrtP] = d;
	}
      }
    }
    FOREQ( diff , -sqrtP , sqrtP ){
      if( abs( diff ) > diff_max ){
	bool small = true;
	FOR( sample_num , 0 , sample_count ){
	  small &= exponent[diff + sqrtP] < sqrtP;
	}
	if( small ){
	  cerr << "出力" << ( diff > 0 ? "+" : "" ) << ( diff == 0 ? "" : to_string( diff ) ) << ": ";
	}
	FOR( sample_num , 0 , sample_count ){
	  cerr << exponent[diff + sqrtP] << ( sample_num == sample_count - 1 ? " <- 離散対数が有意に小さい値です。" : ", " );;
	}
      }
    }
    CERR( "" );
  }
}

void InputPolynomialAnalysis1_few( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 4 );
  CEXPR( int , length , size ); // 4
  CEXPR( int , denom , 12 );
  CEXPR( int , numer_bound , 50 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "（予想解析時間: " << time / 16000000 << "秒）\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] };
      DynamicMod temp{};
      FOR( i , 0 , size ){
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    FOR( i , 0 , size ){
      cerr << "(" << index[i] << "/" << denom << ") * (引数1)^" << i << ( i == size - 1 ? "\n" : " +\n" );
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputPolynomialAnalysis1_enough( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  vector<DynamicMod> input_copy( sample_count );
  for( int sample_num = 0 ; sample_num < sample_count ; sample_num++ ){
    input_copy[sample_num] = input[sample_num][0];
  }
  auto answer = LagrangeInterpolation( input_copy , output );
  answer.RemoveRedundantZero();
  int size = answer.size();
  if( size < sample_count ){
    CERR( "補間成功（次数が小さいため信頼度は高い）:" );
  } else if( size < 5 ) {
    CERR( "補間成功（サンプルが少なすぎるため信頼度は低い）:" );
  } else {
    CERR( "補間成功（次数が高すぎるため信頼度はほとんどなし）:" );
  }
  FOR( i , 0 , size ){
    cerr << "(" << answer[i] << ") * (引数1)^" << i << ( i == size - 1 ? "\n" : " +\n" );
  }
  CERR( "" );
}

void InputPolynomialAnalysis2_few( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size * size ); // 9
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 3 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "（予想解析時間: " << time / 16000000 << "秒）\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] };
      DynamicMod temp{};
      FOR( dx , 0 , size ){
	DynamicMod xy_power = x_power;
	FOR( dy , 0 , size ){
	  int i = size * dx + dy;
	  temp += DynamicMod( index[i] ) * xy_power;
	  xy_power *= y;
	}
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	int i = size * dx + dy;
	cerr << "(" << index[i] << "/" << 2 * index[i+size*size] - 1 << ") * (引数1)^" << dx << " (引数2)^" << dy << ( dx == size - 1 && dy == size - 1 ? "\n" : " +\n" );
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputPolynomialAnalysis2_enough( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size * size ); // 9
  vector M( sample_count , vector<DynamicMod>( length + 1 ) );
  FOR( sample_num , 0 , sample_count ){  
    DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] };
    FOR( dx , 0 , size ){
      DynamicMod xy_power = x_power;
      FOR( dy , 0 , size ){
	int i = size * dx + dy;
	M[sample_num][i] = xy_power;
	xy_power *= y;
      }
      x_power *= x;
    }
    M[sample_num][length-1] = output[sample_num];
  }
  vector<DynamicMod> index{};
  auto [rank,solvable] = ExtendedReducedRowEchelonForm( M , index );
  if( rank == length ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	int i = size * dx + dy;
	cerr << "(" << index[i] << ") * (引数1)^" << dx << " (引数2)^" << dy << ( i == length - 1 ? "}\n" : "} +\n" );
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERR( "" );
}

void InputPolynomialAnalysis3_few( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 2 );
  CEXPR( int , length , size * size * size ); // 8
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 4 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size * size * size;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "（予想解析時間: " << time / 16000000 << "秒）\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] } , z{ input[sample_num][2] };
      DynamicMod temp{};
      FOR( dx , 0 , size ){
	DynamicMod xy_power = x_power;
	FOR( dy , 0 , size ){
	  DynamicMod xyz_power = xy_power;
	  FOR( dz , 0 , size ){
	    int i = size * size * dx + size * dy + dz;
	    temp += DynamicMod( index[i] ) * xyz_power;
	    xyz_power *= z;
	  }
	  xy_power *= y;
	}
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	FOR( dz , 0 , size ){
	  int i = size * size * dx + size * dy + dz;
	  cerr << "(" << index[i] << "/" << denom << ") * (引数1)^" << dx << " (引数2)^" << dy << " (引数3)^" << dz << ( dx == size - 1 && dy == size - 1 && dz == size - 1 ? "\n" : " +\n" );
	}
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputPolynomialAnalysis3_enough( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 2 );
  CEXPR( int , length , size * size * size ); // 8
  vector M( sample_count , vector<DynamicMod>( length + 1 ) );
  FOR( sample_num , 0 , sample_count ){  
    DynamicMod x_power = DynamicMod::one() , x{ input[sample_num][0] } , y{ input[sample_num][1] } , z{ input[sample_num][1] };
    FOR( dx , 0 , size ){
      DynamicMod xy_power = x_power;
      FOR( dy , 0 , size ){
	DynamicMod xyz_power = xy_power;
	FOR( dz , 0 , size ){
	  int i = size * size * dx + size * dy + dz;
	  M[sample_num][i] = xyz_power;
	  xyz_power *= z;
	}
	xy_power *= y;
      }
      x_power *= x;
    }
    M[sample_num][length-1] = output[sample_num];
  }
  vector<DynamicMod> index{};
  auto [rank,solvable] = ExtendedReducedRowEchelonForm( M , index );
  if( rank == length ){
    CERR( "補間成功:" );
    FOR( dx , 0 , size ){
      FOR( dy , 0 , size ){
	FOR( dz , 0 , size ){
	  int i = size * size * dx + size * dy + dz;
	  cerr << "(" << index[i] << ") * (引数1)^" << dx << " (引数2)^" << dy << " (引数3)^" << dz << ( i == length - 1 ? "}\n" : "} +\n" );
	}
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERR( "" );
}

void InputLinearAnalysis4( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , var , 4 );
  CEXPR( int , length , var + 1 ); // 5
  CEXPR( int , denom , 12 );
  CEXPR( int , numer_bound , 24 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound{ length , numer_max };
  vector<int> index = lower_bound;
  ll time = sample_count * var;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "（予想解析時間: " << time / 16000000 << "秒）\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod temp = index[var];
      FOR( i , 0 , var ){
	temp += DynamicMod( index[i] ) * input[sample_num][i];
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    cerr << "(" << index[var] << "/" << denom << ") +\n";
    FOR( i , 0 , var ){
      cerr << "(" << index[i] << "/" << denom << ") * (引数" << i << ")" << ( i == var - 1 ? "\n" : " +\n" );
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputExponentialAnalysis1_few( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size + 2 ); // 5
  CEXPR( int , denom , 6 );
  CEXPR( int , numer_bound , 18 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * ( size + 2 );
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "（予想解析時間: " << time / 16000000 << "秒）\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x{ input[sample_num][0] } , x_power = Power( x , input[sample_num][0] - 1 );
      DynamicMod temp = DynamicMod( index[length-1] ) + DynamicMod( index[length-2] ) * x;
      FOR( d , 0 , size ){
	int i = d;
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    cerr << "(" << index[length-1] << "/" << denom << ") + " << "(" << index[length-2] << "/" << denom << ") (引数1) + ";
    FOR( d , 0 , size ){
      int i = d , dx = d - 1;
      cerr << "(" << index[i] << "/" << denom << ") * (引数1)^{(引数1)" << ( dx > 0 ? "+" : "" ) << ( dx == 0 ? "" : to_string( dx ) ) << ( d == size - 1 ? "}\n" : "} +\n" );
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputExponentialAnalysis1_enough( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , size , 3 );
  CEXPR( int , length , size + 2 );
  vector M( sample_count , vector<DynamicMod>( length + 1 ) );
  FOR( sample_num , 0 , sample_count ){  
    DynamicMod x{ input[sample_num][0] } , x_power = Power( x , input[sample_num][0] - 1 );
    FOR( d , 0 , size ){
      M[sample_num][d] = x_power;
      x_power *= x;
    }
    M[sample_num][size] = x;
    M[sample_num][size+1] = 1;
    M[sample_num][length] = output[sample_num];
  }
  vector<DynamicMod> index{};
  auto [rank,solvable] = ExtendedReducedRowEchelonForm( M , index );
  if( rank == length ){
    CERR( "補間成功:" );
    cerr << "(" << index[length-1] << ") + " << "(" << index[length-2] << ") (引数1) + ";
    FOR( d , 0 , size ){
      int i = d , dx = d - 1;
      cerr << "(" << index[i] << ") * (引数1)^{(引数1)" << ( dx > 0 ? "+" : "" ) << ( dx == 0 ? "" : to_string( dx ) ) << ( d == size - 1 ? "}\n" : "} +\n" );
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERR( "" );
}

void InputExponentialAnalysis2_few( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "サンプル出力の法" + P_str + "における指数関数の一次結合による補間を試みます。" );
  CEXPR( int , size , 3 );
  CEXPR( int , var , 2 );
  CEXPR( int , length , var * ( var - 1 ) * size + 1 ); // 7
  CEXPR( int , denom , 2 );
  CEXPR( int , numer_bound , 5 );
  const int numer_max = numer_bound * scale;
  vector<int> lower_bound( length , - numer_max );
  vector<int> upper_bound( length , numer_max );
  vector<int> index = lower_bound;
  ll time = sample_count * size * 2;
  REPEAT( length ){
    time *= 2 * numer_max + 1;
  }
  cerr << "（予想解析時間: " << time / 16000000 << "秒）\n";
  START_WATCH;
  bool valid = true;
  bool match = false;
  while( valid && !match ){
    match = true;
    FOR( sample_num , 0 , sample_count ){
      DynamicMod x{ input[sample_num][0] } , y{ input[sample_num][1] } , x_power = Power( x , input[sample_num][1] - 1 ) , y_power = Power( y , input[sample_num][0] - 1 );
      DynamicMod temp = DynamicMod( index[length-1] );
      FOR( d , 0 , size ){
	int i = d;
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      FOR( d , 0 , size ){
	int i = size + d;
	temp += DynamicMod( index[i] ) * y_power;
	y_power *= y;
      }
      if( output[sample_num] * denom != temp ){
	match = false;
	break;
      }
    }
    if( !match ){
      valid = NextLoopEq( length , lower_bound , upper_bound , index );
    }
  }
  if( match ){
    CERR( "補間成功:" );
    cerr << "(" << index[length-1] << "/" << denom << ") +\n";
    FOR( d , 0 , size ){
      int i = d , dy = d - 1;
      cerr << "(" << index[i] << "/" << denom << ") * (引数1)^{(引数2)" << ( dy > 0 ? "+" : "" ) << ( dy == 0 ? "" : to_string( dy ) ) << "} +\n";
    }
    FOR( d , 0 , size ){
      int i = size + d , dx = d - 1;
      cerr << "(" << index[i] << "/" << denom << ") * (引数2)^{(引数1)" << ( dx > 0 ? "+" : "" ) << ( dx == 0 ? "" : to_string( dx ) ) << ( d == size - 1 ? "}\n" : "} +\n" );
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputExponentialAnalysis2_enough( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "サンプル出力の法" + P_str + "における指数関数の一次結合による補間を試みます。" );
  CEXPR( int , size , 3 );
  CEXPR( int , var , 2 );
  CEXPR( int , length , var * ( var - 1 ) * size + 1 ); // 7
  vector M( sample_count , vector<DynamicMod>( length + 1 ) );
  FOR( sample_num , 0 , sample_count ){  
    DynamicMod x{ input[sample_num][0] } , y{ input[sample_num][1] } , x_power = Power( x , input[sample_num][1] - 1 ) , y_power = Power( y , input[sample_num][0] - 1 );
    FOR( d , 0 , size ){
      int i = d;
      M[sample_num][i] = x_power;
      x_power *= x;
    }
    FOR( d , 0 , size ){
      int i = size + d;
      M[sample_num][i] = y_power;
      y_power *= y;
    }
    M[sample_num][var * ( var - 1 ) * size] = 1;
    M[sample_num][length] = output[sample_num];
  }
  vector<DynamicMod> index{};
  auto [rank,solvable] = ExtendedReducedRowEchelonForm( M , index );
  if( rank == length ){
    CERR( "補間成功:" );
    cerr << "(" << index[length-1] << ") +\n";
    FOR( d , 0 , size ){
      int i = d , dy = d - 1;
      cerr << "(" << index[i] << ") * (引数1)^{(引数2)" << ( dy > 0 ? "+" : "" ) << ( dy == 0 ? "" : to_string( dy ) ) << "} +\n";
    }
    FOR( d , 0 , size ){
      int i = size + d , dx = d - 1;
      cerr << "(" << index[i] << ") * (引数2)^{(引数1)" << ( dx > 0 ? "+" : "" ) << ( dx == 0 ? "" : to_string( dx ) ) << ( d == size - 1 ? "}\n" : "} +\n" );
    }
  } else {
    CERR( "補間失敗。" );
  }
  CERR( "" );
}
