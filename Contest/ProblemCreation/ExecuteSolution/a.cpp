// c:/Users/user/Documents/Programming/Contest/ProblemCreation/ExecuteSolution/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

void ExecuteSolution( const string& directory_name )
{
  cout << directory_name << "の想定解を何回実行しますか？" << endl;
  CIN_ASSERT( how_many_times , 1 , 100 );
  cout << how_many_times << "回実行します。" << endl;

  if( how_many_times > 1 ){

    cout << "グラフなどを使う際にmain関数の外で初期化する変数がある場合、" << endl;
    cout << "この実行機能では変数の値が残ったまま実行が繰り返されることに" << endl;
    cout << "注意してください。" << endl;

  }

  REPEAT( how_many_times ){

    ExecuteSolution_Body();

  }

  return;

}

