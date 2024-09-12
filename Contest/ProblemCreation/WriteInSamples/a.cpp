// c:/Users/user/Documents/Programming/Contest/ProblemCreation/WriteInSamples/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../../../Utility/FileStream/a_Body.hpp"
#include "../../../Utility/Time/a_Body.hpp"

void WriteInSamples( const string& directory_name , VLArray<string>& file_names )
{

  ifstream ifs_output_list;
  ifstream ifs_output_list_copy;
  ifstream ifs_input_list;
  const string output_file_list_name = "/" + directory_name + "/サンプル出力/一覧.txt";
  const string input_file_list_name = "/" + directory_name + "/サンプル入力/一覧.txt";
  SEARCH_SAMPLE_LIST_DIRECTORY( ifs , ios::in , WRITE_IN_MESSAGE_FOR_SEARCH_SAMPLE_LIST_DIRECTORY );
  
  if ( ! ifs_output_list ) {

    cout << "サンプル出力一覧ファイルディレクトリ: " << star + directory_name + "/サンプル出力/" << endl;
    cout << "サンプル出力一覧ファイルが開けませんでした。" << endl;
    return;

  }

  StartWatch( "一覧ファイル読み込み" );
  VLArray<string> input_samples{};
  VLArray<string> output_samples{};
  string s_current;
  string s_sum = "";
  getline( ifs_output_list_copy , s_current );
  const bool with_output = ! ifs_output_list_copy.eof();

  if( with_output ){

    cout << "出力ファイルが空でないので入力ファイルと出力ファイル両方の書き込みをします。" << endl;
    bool searching_input = true;

    while( ! ifs_output_list.eof() ){
    
      if( searching_input ){

	getline( ifs_input_list , s_current );

	if( s_current == "" ){

	  if( s_sum != "" ){

	    PushBackSample( input_samples , s_sum );

	  }

	  searching_input = false;

	} else {

	  AddCurrentSample( s_sum , s_current );
	  getline( ifs_output_list , s_current );

	}

      } else {

	getline( ifs_output_list , s_current );

	if( s_current == "" ){

	  if( s_sum != "" ){

	    PushBackSample( output_samples , s_sum );
	    searching_input = true;

	  }

	} else {

	  AddCurrentSample( s_sum , s_current );

	}

      }

    }

    if( s_current != "" ){

      if( s_sum != "" ){

	PushBackSample( output_samples , s_sum );

      }

    }

  } else {

    cout << "出力ファイルが空なので入力ファイルのみの書き込みをします。" << endl;

    while( ! ifs_input_list.eof() ){
    
      getline( ifs_input_list , s_current );

      if( s_current == "" ){

	if( s_sum != "" ){

	  PushBackSample( input_samples , s_sum );

	}

      } else {

	AddCurrentSample( s_sum , s_current );

      }

    }

    if( s_current != "" ){

      if( s_sum != "" ){

	PushBackSample( input_samples , s_sum );

      }

    }
    
  }

  StopWatch();
  cout << "読み込みが完了しました。" << endl;

  const uint& input_sample_size = input_samples.size();
  const uint& output_sample_size = output_samples.size();
  const uint& file_name_size = file_names.size();

  if( with_output ){

    if( input_sample_size < output_sample_size ){

      cout << "入力サンプル数が不足しています。出力サンプルファイルの末尾に余計な空行がないことや、出力ファイルの削除し忘れがないかを確認してください。" << endl;
      cout << "input_sample_size: " << input_sample_size << endl;
      cout << "output_sample_size: " << output_sample_size << endl;
      cout << "どのファイルが欠けているかの情報を得るためにこのエラーを無視して続行します。" << endl;

    } else if(  input_sample_size > output_sample_size ){

      cout << "出力サンプル数が不足しています。出力サンプルファイルの末尾に必要な空行が足りていることや、出力ファイルの削除し忘れがないかを確認してください。" << endl;
      cout << "input_sample_size: " << input_sample_size << endl;
      cout << "output_sample_size: " << output_sample_size << endl;
      cout << "どのファイルが欠けているかの情報を得るためにこのエラーを無視して続行します。" << endl;

    }

  }

  if( input_sample_size < file_name_size ){

    cout << "入力サンプル数が不足しています。ファイル数を間違えていないことや、出力ファイルの削除し忘れがないかを確認してください。" << endl;
    cout << "input_sample_size: " << input_sample_size << endl;
    cout << "file_name_size: " << file_name_size << endl;
    cout << "どのファイルが欠けているかの情報を得るためにこのエラーを無視して続行します。" << endl;

  } else if(  input_sample_size > file_name_size ){

    cout << "ファイル数が不足しています。ファイル数を間違えていないことや、出力ファイルの削除し忘れがないかを確認してください。" << endl;
    cout << "input_sample_size: " << input_sample_size << endl;
    cout << "file_name_size: " << file_name_size << endl;
    cout << "どのファイルが欠けているかの情報を得るためにこのエラーを無視して続行します。" << endl;

    for( uint i = file_name_size ; i < input_sample_size ; i++ ){

      file_names.push_back( "zzz_" + to_string( i + 100 ).substr( 1 ) );

    }

  }
  
  auto itr_file = file_names.begin();
  
  string input_file_name;
  string output_file_name;
  const string file_name_list_file_name = star + directory_name + "/サンプル出力/ファイル名.txt";
  DeleteContents( file_name_list_file_name );
  
  auto itr_input_sample = input_samples.begin();
  auto itr_output_sample = output_samples.begin();

  StartWatch( "一覧ファイル書き出し" );

  for( uint i = 0 ; i < input_sample_size ; i++ ){

    if( *itr_file == "" ){

      cout << "空白のファイル名を無視しました。出力一覧に実際のファイル名より多くのサンプルが含まれていないことを確認してください。" << endl;
      cout << "input_sample_size: " << input_sample_size << endl;
      cout << "file_name_size: " << file_name_size << endl;
      return;

    }

    input_file_name = star + directory_name + "/サンプル入力/" + *itr_file + ".txt";
    DeleteContents( input_file_name );
    WriteIn( input_file_name , *itr_input_sample );
    itr_input_sample++;

    if( with_output ){

      output_file_name = star + directory_name + "/サンプル出力/" + *itr_file + ".txt";
      DeleteContents( output_file_name );
      WriteIn( output_file_name , *itr_output_sample );
      itr_output_sample++;

    }

    WriteIn( file_name_list_file_name , "\"" + *itr_file + "\" ," );
    itr_file++;

  }

  StopWatch();
  cout << "書き込みが完了しました。" << endl;
  return;

}

void WriteInSamples( const string& directory_name )
{

  cout << "個々のサンプルを格納するファイルを作成します。" << endl;
  VLArray<string> file_prefix;;
  VLArray<int> file_num;
  WriteInSamples_Body( file_prefix , file_num );
  const int prefix_size = file_prefix.size();
  const int num_size = file_num.size();
 
  if( prefix_size != num_size ){

    cout << "ファイル接頭辞の数があっていません。" << endl;
    cout << "file_prefix.size(): " << prefix_size << endl;
    cout << "file_num.size(): " << num_size << endl;
    cout << "ファイル接頭辞のコメントアウトを間違っている可能性があるため、書き込みを終了します。" << endl;
    return;
    
  }
  
  VLArray<string> file_names{};

  for( int i = 0 ; i < prefix_size ; i++ ){

    const string& prefix = file_prefix[i];
    const int& num = file_num[i];

    for( int j = 0 ; j < num ; j++ ){

      file_names.push_back( prefix + to_string( j + 100 ).substr( 1 ) );

    }

    cout << prefix << "00 ～ " << to_string( num - 1 + 100 ).substr( 1 ) << "\n";

  }

  string reply = "";

  while( reply != "y" && reply != "n" ){

    cout << "上記のファイル構成で正しいですか？[y/n]" << endl;

    cin >> reply;

    if( reply != "y" && reply != "n" ){

      cout << "回答は[y/n]のいずれかでお願いします。" << endl;

    }

  }

  if( reply == "y" ){

    WriteInSamples( directory_name , file_names );

  } else {

    cout << "中断します。" << endl;

  }

  return;

}
