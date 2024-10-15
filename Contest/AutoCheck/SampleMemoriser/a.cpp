// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

void Solve();

void SampleCheck( const string& sample_path , const string& input_path , const string& output_path , const string& problem_order , const int& test_case_num_bound , ifstream& ifs , ofstream& ofs )
{

  ifstream sample_count{ sample_path + problem_order + "/count.txt" };
  int sample_repetition_num; sample_count >> sample_repetition_num;

  for( int sample_num = 1 ; sample_num <= sample_repetition_num ; sample_num++ ){

    string sample_num_str; sample_count >> sample_num_str;
    assert( sample_num == stoi( sample_num_str ) );
    CERRNS( "サンプル" , sample_num , "を実行します。\n" );
    CERR( "" );
    ifs = ifstream{ input_path + sample_num_str + ".txt" };
    ofs = ofstream{ output_path + sample_num_str + ".txt" , ios::trunc };
    int test_case_num = 1;

    if( test_case_num_bound > 1 ){

      ifs >> test_case_num;
      assert( 1 <= test_case_num && test_case_num <= test_case_num_bound );
        
    }

    for( int t = 0 ; t < test_case_num ; t++ ){

      Solve();

    }

    CompareAnswer( sample_path , problem_order , sample_num_str );
    CERRNS( "サンプル" , sample_num , "の実行を終了しました。\n" );
    CERR( "" );
    
  }

}

void CompareAnswer( const string& sample_path , const string& problem_order , const string& sample_num )
{

  ifstream prepared_answer{ sample_path + problem_order + "/output/sample" + sample_num + ".txt" };
  ifstream submitted_answer{ sample_path + problem_order + "/output/exec" + sample_num + ".txt" };
  int count = 0;
  const string formatted_sample_num = to_string( stoi( sample_num ) );
  bool correct = true;
  
  while( !prepared_answer.eof() && !submitted_answer.eof() ){

    count++;
    string line0 , line1;
    getline( prepared_answer , line0 );
    getline( submitted_answer , line1 );

    if( line0 != line1 ){

      correct = false;
      CERR( "サンプル" , formatted_sample_num , "に対する出力の" , count , "行目は" );
      CERR( line0 );

      if( line1 == "" ){

        CERR( "となる想定ですが、何も出力されませんでした。" );

      } else {
        
        CERR( "となる想定ですが、" );
        CERR( line1 );
        CERR( "となりました。" );

      }

      CERR( "" );

    }

  }

  if( !prepared_answer.eof() ){

    CERR( "サンプル" , formatted_sample_num , "に対する出力は" , count - 1 , "行より多い想定で、不足しています。" );

  } else if( !submitted_answer.eof() ){

    CERR( "サンプル" , formatted_sample_num , "に対する出力は" , count - 1 , "行の想定で、余計な出力をしています。" );

  } else if( correct ){

    CERR( "サンプル" , formatted_sample_num , "は正解です。" );

  }

  CERR( "" );
  return;

}
