// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

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
      CERR( "サンプル" + formatted_sample_num + "に対する出力の" + to_string( count ) + "行目は" );
      CERR( line0 );
      CERR( "となる想定ですが、" );
      CERR( line1 );
      CERR( "となりました。" );
      CERR( "" );

    }

  }

  if( !prepared_answer.eof() ){

    CERR( "サンプル" + formatted_sample_num + "に対する出力は" + to_string( count - 1 ) + "行より多い想定で、不足しています。" );

  } else if( !submitted_answer.eof() ){

    CERR( "サンプル" + formatted_sample_num + "に対する出力は" + to_string( count - 1 ) + "行の想定で、余計な出力をしています。" );

  } else if( correct ){

    CERR( "サンプル" + formatted_sample_num + "は正解です。" );

  }

  CERR( "" );
  return;

}
