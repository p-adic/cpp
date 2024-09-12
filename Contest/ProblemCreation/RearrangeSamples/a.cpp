// c:/Users/user/Documents/Programming/Contest/ProblemCreation/RearrangeSamples/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../WriteInSamples/a_Body.hpp"

void RearrangeSamples( const string& directory_name )
{

  ifstream ifs_input_list;
  const string input_file_list_name = "/" + directory_name + "/サンプル入力/一覧.txt";
  cout << "サンプル変更コードでサンプルの形式を変更します。" << endl;
  SEARCH_SAMPLE_LIST_DIRECTORY( ifs , ios::app , cout << "a.txtに上書き書き込みをします。" << endl );
  ofstream ofs_input_list( "a.txt" , ios::trunc );
  RearrangeSamples_Body( ifs_input_list , ofs_input_list );
  return;

}
