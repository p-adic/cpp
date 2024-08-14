// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleAnalyser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

// デバッグモードでないと翻訳単位ごとに異なる実装をDynamicModが持ってしまうるので実行時に
// Segmentation Faultとなる。
#include "../../../Mathematics/Arithmetic/Mod/DynamicModulo/Debug/a_Body.hpp"
#include "../../../Mathematics/Arithmetic/Mod/Function/DiscreteLog/a_Body.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a_Body.hpp"

AC( SampleAnalyser )
{
  ASK_YES_NO( "数え上げの法は998244353ですか？" );
  int P = 998244353;
  if( reply != "y" ){
    cerr << "数え上げの法: "; cin >> P;
  }
  DynamicMod::SetModulo( P );
  int sample_count = 3;
  ASK_YES_NO( "サンプルの個数は3個ですか？" );
  if( reply != "y" ){
    cerr << "サンプルの個数: "; cin >> sample_count;
  }
  vector<vector<ll>> input( sample_count );
  vector<DynamicMod> output( sample_count );
  int var = 0;
  bool const_var = false;
  ASK_YES_NO( "サンプル入力中の数値の個数は一定ですか？" );
  if( reply == "y" ){
    cerr << "サンプル入力中の数値の個数: "; cin >> var;
    CERR( "" );
    const_var = true;
  }
  FOR( sample_num , 0 , sample_count ){
    const string sample_num_str = to_string( sample_num + 1 );
    if( !const_var ){
      cerr << "サンプル" << sample_num_str << "の入力中の数値の個数: "; cin >> var;
    }
    cerr << "サンプル" << sample_num_str << "の入力中の数値: ";
    CIN_A( ll , 0 , var , A );
    input[sample_num] = move( A );
    cerr << "サンプル" + sample_num_str + "出力: "; cin >> output[sample_num];
    CERR( "" );
  }
  const string P_str = to_string( P );
  int scale = 1;
  while( true ){
    PowerAnalysis( sample_count , output , scale , P , P_str );
    if( const_var && 0 < var && var <= 4 ){
      if( var == 1 ){
	InputPolynomialAnalysis1( sample_count , input , output , scale , P , P_str );
      } else if( var == 2 ){
	InputPolynomialAnalysis2( sample_count , input , output , scale , P , P_str );
	InputExponentialAnalysis2( sample_count , input , output , scale , P , P_str );
      } else if( var == 3 ){
	InputPolynomialAnalysis3( sample_count , input , output , scale , P , P_str );
      } else {
	assert( var == 4 );
	InputLinearAnalysis4( sample_count , input , output , scale , P , P_str );
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

void PowerAnalysis( const int& sample_count , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CEXPR( int , diff_bound , 10 );
  const int diff_max = diff_bound * scale;
  const vector bases{2,3,5,6,7};
  RUN( bases , base ){
    cerr << "サンプル";
    FOR( sample_num , 0 , sample_count ){
      ( sample_num == 0 ? cerr : cerr << ", " ) << sample_num + 1;
    }
    cerr << "の出力の法" + P_str + "における底" + to_string( base ) + "の離散対数を求めます。\n";
    FOREQ( diff , - diff_max , diff_max ){
      cerr << "出力" << ( diff > 0 ? "+" : "" ) << ( diff == 0 ? "" : to_string( diff ) ) << ": ";
      bool small = true;
      FOR( sample_num , 0 , sample_count ){
	int dl = DiscreteLog( int( output[sample_num].Represent() ) + diff , base , P );
	small &= 0 <= dl && ll( dl ) * dl < P;  
	cerr << ( dl < 0 ? "NaN" : to_string( dl ) ) << ( sample_num == sample_count - 1 ? "" : ", " );
      }
      ( small ? cerr << " <- 有意に小さい値です。" : cerr ) << "\n";
    }
    CERR( "" );
  }
}

void InputPolynomialAnalysis1( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "サンプル出力の法" + P_str + "における1変数多項式補間を試みます。" );
  CEXPR( int , size , 4 );
  CEXPR( int , length , size );
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
      cerr << "(" << index[i] << "/" << denom << ") (引数1)^" << i << ( i == size - 1 ? "\n" : " + " );
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputPolynomialAnalysis2( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "サンプル出力の法" + P_str + "における2変数多項式補間を試みます。" );
  CEXPR( int , size , 3 );
  CEXPR( int , length , size * size );
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
	cerr << "(" << index[i] << "/" << 2 * index[i+size*size] - 1 << ") (引数1)^" << dx << " (引数2)^" << dy << ( dx == size - 1 && dy == size - 1 ? "\n" : " + " );
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputPolynomialAnalysis3( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "サンプル出力の法" + P_str + "における3変数多項式補間を試みます。" );
  CEXPR( int , size , 2 );
  CEXPR( int , length , size * size * size );
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
	  cerr << "(" << index[i] << "/" << denom << ") (引数1)^" << dx << " (引数2)^" << dy << " (引数3)^" << dz << ( dx == size - 1 && dy == size - 1 && dz == size - 1 ? "\n" : " + " );
	}
      }
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputLinearAnalysis4( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "サンプル出力の法" + P_str + "における4変数線形補間を試みます。" );
  CEXPR( int , var , 4 );
  CEXPR( int , length , var + 1 );
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
    cerr << "(" << index[var] << "/" << denom << ") + ";
    FOR( i , 0 , var ){
      cerr << "(" << index[i] << "/" << denom << ") (引数" << i << ")" << ( i == var - 1 ? "\n" : " + " );
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}

void InputExponentialAnalysis2( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str )
{
  CERR( "サンプル出力の法" + P_str + "における指数関数の一次結合による補間を試みます。" );
  CEXPR( int , size , 3 );
  CEXPR( int , var , 2 );
  CEXPR( int , length , var * ( var - 1 ) * size + 1 );
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
      FOR( dy , 0 , size ){
	int i = dy;
	temp += DynamicMod( index[i] ) * x_power;
	x_power *= x;
      }
      FOR( dx , 0 , size ){
	int i = size + dx;
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
      cerr << "(" << index[length-1] << "/" << denom << ") + ";
    FOR( dy , 0 , size ){
      int i = dy;
      cerr << "(" << index[i] << "/" << denom << ") (引数1)^{(引数2)" << ( dy > 0 ? "+" : "" ) << ( dy == 0 ? "" : to_string( dy ) ) << "} + ";
    }
    FOR( dx , 0 , size ){
      int i = size + dx;
      cerr << "(" << index[i] << "/" << denom << ") (引数2)^{(引数1)" << ( dx > 0 ? "+" : "" ) << ( dx == 0 ? "" : to_string( dx ) ) << ( dx == size - 1 ? "}" : "} + " );
    }
  } else {
    CERR( "補間失敗。" );
  }
  cerr << "解析時間: " << int( CURRENT_TIME / 1000 ) << "秒\n";
  CERR( "" );
}
