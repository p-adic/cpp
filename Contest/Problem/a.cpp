// 作問用
#include "../Header.hpp"
#include "a_Body.hpp"

#include "../Random/a_Body.hpp"

int main()
{
  const string directory_name = "問題名をここに入れる";
  COUT( "どれを選択しますか？" );
  COUT( "0:" , directory_name , "の想定解を実行する。" );
  COUT( "1:" , directory_name , "のサンプルを生成する。" );
  COUT( "2:" , directory_name , "のサンプルを格納するファイルを作成する。" );
  COUT( "3:" , directory_name , "のサンプルのフォーマットを変更する。" );
  CIN_ASSERT( branch , 0 , 3 );
  int branch_temp = 0;
  if( branch == branch_temp++ ){
    ExecuteSolution( directory_name );
  } else if( branch == branch_temp++ ){
    GenerateSamples( directory_name );
  } else if( branch == branch_temp++ ){
    WriteInSamples( directory_name );
  } else if( branch == branch_temp++ ){
    RearrangeSamples( directory_name );
  }
  QUIT;
}

int MAIN()
{
  // 想定解をここに入れる。
}

void GenerateSamples_Body( ofstream& ofs_input_list )
{
  // ジェネレータコードをここに入れる。
}

void WriteInSamples_Body( VLArray<string>& file_prefix , VLArray<int>& file_num )
{
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" };
  VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" , "Sugoi_" };
  // VLArray<string> prefix{ "Chiisai_" , "Kyoukai_" , "Ookii_" , "Sugoi_" , "Tester_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" , "Sugoi_" };
  // VLArray<string> prefix{ "Chiisai_" , "Ookii_" , "Sugoi_" , "evil_" };
  // VLArray<string> prefix{ "Sampuru_" };
  VLArray<int> num{ 10 , 5 , 5 , 8 };
  file_prefix = prefix;
  file_num = num;
  return;
}

// 出力一覧ファイルがある場合、それを削除しないと正しくファイル書き込みができないことに注意。
void RearrangeSamples_Body( ifstream& ifs_input_list , ofstream& ofs_input_list )
{
  REPEAT( 28 ){
    // フォーマット変更コードをここに入れる。
    OFS( "" );
  }
  IFS( string , check_redundant );
  assert( check_redundant == "" );
  assert( ! ifs_input_list );
  cout << "書き込みが完了しました。" << endl;
  return;
}
