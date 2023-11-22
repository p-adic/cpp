// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

void AutoCheck( int& exec_mode )
{
  int num = 0;
  int num_temp = 0;
  string reply{};
  vector<string> problems{};
  int problems_size = 0;
  ASK_NUMBER(
	     "提出用ファイルを実行する。" ,
	     "サンプルの合わないファイルをデバッグする。" ,
	     "提出済みファイルをデバッグする。" ,
	     "ライブラリーを探索する。" ,
	     "愚直解で実験する。" ,
	     "愚直解と提出用ファイルを入力の小さいテストケースで比較する。" ,
	     "愚直解と提出用ファイルをランダムテストで比較する。"
	     );
  exec_mode = num;
  if( num == num_temp++ ){
    CERR( "提出用ファイルを実行します。" );
  } else if( num == num_temp++ ){
    CALL_AC( DebugHintWA );
  } else if( num == num_temp++ ){
    CALL_AC( DebugHint );
  } else if( num == num_temp++ ){
    CALL_AC( LibrarySearch );
  } else if( num == num_temp++ ){
    CERR( "愚直解で実験します。" );
  } else if( num == num_temp++ ){
    CERR( "愚直解と提出用ファイルを入力の小さいテストケースで比較します。" );
  } else if( num == num_temp++ ){
    CERR( "愚直解と提出用ファイルをランダムテストで比較します。" );
  }
  CERR( "" );
}

AC( DebugHint )
{
  ASK_NUMBER(
	     "WAのデバッグ" ,
	     "REのデバッグ" ,
	     "TLEのデバッグ" ,
	     "MLEのデバッグ" ,
	     "CEのデバッグ"
	     );
  if( num == num_temp++ ){
    CALL_AC( DebugHintWA );
  } else if( num == num_temp++ ){
    CERR( "- 制約を間違えてassertしていませんか？" );
    CERR( "- 手元の環境ではDEXPRで設定した値が小さくなることを忘れていませんか？" );
    CERR( "- 配列外参照していませんか？" );
    CERR( "  - 座標圧縮畤に圧縮前の添字操作と圧縮後の添字操作を混同していませんか？" );
    CERR( "  - グラフや座標圧縮の操作で存在しない座標-1の場合分けを忘れていませんか？" );
    CERR( "- 二分探索マクロで探索値が存在しない場合にMAXIMUM+1が返ることを忘れていませんか？" );
    CERR( "- イテレータを範囲外まで--/++していませんか？" );
    CERR( "- multisetのcountを使っていませんか？" );
    CERR( "- 0で割っていませんか？" );
  } else if( num == num_temp++ ){
    CERR( "- マルチテストケースでデータ構造の初期化が反復されていませんか？" );
    CERR( "  - 動的配列への置き換え" );
    CERR( "  - 座標圧縮" );
    CERR( "    \\Mathematics\\SetTheory\\DirectProduct\\CoordinateCompress" );
    CERR( "  を検討しましょう。" );
    CERR( "- whileループで添字等の更新忘れによる無限ループはありませんか？" );
    CERR( "- cerrの消し忘れはありませんか？" );
    CERR( "- 重過ぎる定数倍を考慮し忘れてませんか？" );
    CERR( "  - bool値の処理はbit演算による並列化" );
    CERR( "  - 変数の和や積に上限があるグリッド問題は動的配列" );
    CERR( "  を検討しましょう。" );
    CERR( "- 前計算できる処理を繰り返してませんか？" );
    CERR( "  - 各(i,j)ごとにS_ijを構築する代わりに各iごとにS_iを構築してS_iとS_jで" );
    CERR( "    S_ijをO(1)で構築することを検討しましょう。" );
    CERR( "- リアクティブ問題でflushと改行をし忘れていませんか？" );
    CERR( "- 構築可能性の判定問題であれば、時間を計測して打ち切りましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- グラフで辺を持ち過ぎていませんか？" );
    CERR( "- （多重）配列でサイズが10^6を大幅に上回ってませんか？" );
    CERR( "  - データ構造は座標圧縮を検討しましょう。" );
    CERR( "  - 動的計画法は初期化忘れに注意して添字のswapやmodを検討しましょう。" );
    CERR( "- 再帰／非再帰の選択を誤っていませんか？" );
    CERR( "  - 再帰でMLEしていますか？" );
    CERR( "    - 関数の引数や局所変数を再帰呼び出しの後に用いる場合それらをメモリ上に" );
    CERR( "      保持し続ける必要があるのでメモリ使用量が膨れ上がります。" );
    CERR( "    - 同再帰深度での呼び出し回数より最大再帰深度が大きい場合は" );
    CERR( "      軽い処理でも非再帰にした方がメモリ節約できるかもしれません。" );
    CERR( "    - 例えばメモリ上に変数を保持しない簡単な処理は再帰深度10^8でも大丈夫です。" );
    CERR( "  - 非再帰でMLEしていますか？" );
    CERR( "    - 変数を逐一構築する軽め再帰でも再帰深度が10^6以下なら大丈夫です。" );
    CERR( "    - 最大再帰深度より同再帰深度での呼び出し回数が大きい場合は" );
    CERR( "      重い処理でも再帰した方がメモリ節約できるかもしれません。" );
    CERR( "    - 例えば毎回10^5オーダーの配列を構築する再帰でも最大再帰深度が10程度なら" );
    CERR( "      再帰した方がメモリ上の変数の個数を10^6オーダーで抑えられます。" );
    CERR( "- 幅／深さ優先探索の選択を誤っていませんか？" );
    CERR( "  - 出次数が大きい場合、幅優先探索ではMLEするかもしれません。" );
    CERR( "  - 出次数が1の頂点が多い場合、深さ優先探索ではMLEするかもしれません。" );
    CERR( "- 実行時計算のシフト演算子が64周期であることを忘れていませんか？" );
    CERR( "  - 例えば1LL<<-1は-2^{63}になります。" );
    CERR( "  - 例えば1024>>65は512になります。" );
    CERR( "  - コンパイル時計算はそうではないようです。" );
    CERR( "- Python使用畤に変数名の重複による型エラーが起きてませんか？" );
    CERR( "  - rangeのRと[L,R)のRの重複は後者に[l,r)を用いて解消しましょう。" );
    CERR( "  - 素数のPと順列のPの重複は後者にAやQを用いて解消しましょう。" );
    CERR( "- Python使用畤に桁数が大きくなり過ぎていませんか？" );
  } else if( num == num_temp++ ){
    CERR( "- 完全型を使っているつもりでinvalid use of incomplete typeが出ている時は" );
    CERR( "  - クラステンプレートのテンプレート引数を間違えていませんか？" );
    CERR( "  - クラステンプレートのテンプレート引数を部分特殊化してメンバ関数を" );
    CERR( "    定義しようとしていませんか？" );
    CERR( "    - 部分特殊化に対しクラスを完全に宣言し直して他のメンバも定義するか" );
    CERR( "      完全な特殊化をしましょう。" );
  }
  CERR( "" );
  CERR( "提出済みファイルのデバッグは以上です。終了します。" );
}

AC( DebugHintWA )
{
  CERR( "- operator<<()をint型に適用していませんか？" );
  CERR( "- 実行時計算のシフト演算子が64周期であることを忘れていませんか？" );
  CERR( "  - 例えば1LL<<-1は-2^{63}になります。" );
  CERR( "  - 例えば1024>>65は512になります。" );
  CERR( "  - コンパイル時計算はそうではないようです。" );
  CERR( "- イベント管理にsetを使っていませんか？" );
  CERR( "  - keyに狭義全順序を用いる場合、" );
  CERR( "    - 同一keyの処理を同時に行うならばmapを検討しましょう。" );
  CERR( "    - 同一keyの処理を同時に行わないならばmultisetを検討しましょう。" );
  CERR( "  - keyに狭義全順序の積順序を用いる場合、mapの入れ子を検討しましょう。" );
  CERR( "- 動的計画法においてindexのswapやmodを用いてメモリ削減を行う場合、" );
  CERR( "  各ループの最初にdpテーブルの初期化をし忘れていませんか？" );
  CERR( "- 変数名の衝突した局所変数による秘匿化を受けていませんか？" );
  CERR( "- 誤差評価をし忘れていませんか？" );
  CERR( "  - 整数型へのキャスト時の切り捨てが適切かを確認しましょう。" );
  CERR( "  - 二分探索等で厳密値を扱う時は代数方程式を解いて誤差を消しましょう。" );
  CERR( "- 番兵などによる例外処理のミスをしていませんか？" );
  CERR( "  - 単なる定数倍高速化を目的とする例外処理は削除して試してみましょう。" );
  CERR( "  - 実装の高速化を目的とする例外処理は削除せず正当性の証明を再確認しましょう。" );
  CERR( "- 面積計算で格子点の個数と長さを混同していませんか？" );
  CERR( "  - 領域を管理する際は「右下の単位矩形が塗られるか」の情報を各格子点に乗せましょう。" );
  CERR( "  - 座標圧縮する際は「塗る領域の端点」を±1せずに管理しましょう。" );
  CERR( "- マルチテストケースで配列にstaticをつけて値が持ち越されていませんか？" );
  CERR( "- cLay使用畤にsetmod以前に10^9+7より大きい値を代入していませんか？" );
  CERR( "  #define MD 998244353 などを用いましょう。" );
  CERR( "" );
  CERR( "原因に心当たりがない場合はランダムテストを検討しましょう。" );
  CERR( "ランダムテストで引っ掛らない場合は" );
  CERR( "- 大きな入力値でのみ起こるバグ" );
  CERR( "  - 型の指定ミス" );
  CERR( "  - 64bit型のオーバーフロー" );
  CERR( "- メモリの破壊によって起こる環境依存のバグ" );
  CERR( "  - []やsortの範囲指定ミス" );
  CERR( "  - 二重配列で[i][j]と[j][i]の書き間違い" );
  CERR( "を疑いましょう。" );
}

AC( LibrarySearch )
{
  ASK_NUMBER(
	     "明示式の計算問題" ,
	     "最大／最小化問題" ,
	     "数え上げ問題" ,
	     "求解問題" ,
	     "クエリ処理問題" ,
	     "真偽判定問題" ,
	     "構築問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( Maximisation );
  } else if( num == num_temp++ ){
    CALL_AC( Counting );
  } else if( num == num_temp++ ){
    CALL_AC( Solving );
  } else if( num == num_temp++ ){
    CALL_AC( Query );
  } else if( num == num_temp++ ){
    CALL_AC( Decision );
  } else if( num == num_temp++ ){
    CALL_AC( Construction );
  }
  ASK_YES_NO( "マルチテストケースですか？" );
  if( reply == "y" ){
    CERR( "テストケースを跨ぐ前計算が可能か否かを優先的に考察しましょう。" );
    CERR( "" );
    CERR( "テストケース全体でのNの総和に直接上限が与えられている問題では、" );
    CERR( "ライブラリーの使用時は配列の初期化が各テストケースに必要となる場合に" );
    CERR( "TLEとなる可能性が高いです。" );
    CERR( "- 動的配列への置き換え" );
    CERR( "- 座標圧縮" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\CoordinateCompress" );
    CERR( "を検討しましょう。" );
    CERR( "" );
  }
  CERR( "ライブラリー探索は以上です。終了します。" );
}

AC( ExplicitExpression )
{
  ASK_NUMBER(
	     "１変数関数／数列の計算問題" ,
	     "配列を用いた関数の総和の計算問題" ,
	     "順列上の関数の計算問題" ,
	     "木上の関数の総和の計算問題" ,
	     "木以外のグラフ上の関数の計算問題" ,
	     "序数の計算問題" ,
	     "確率／期待値の計算問題" ,
	     "操作回数の計算問題" ,
	     "面積の計算問題" ,
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnary );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArraySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnPermutation );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionFunctionOnNonTreeGraph );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOrder );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionProbability );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArea );
  }
}

AC( ExplicitExpressionUnary )
{
  ASK_NUMBER(
	     "線形漸化式の計算問題" ,
	     "１変数関数の反復合成の計算問題" ,
	     "bit関数と他の関数の合成の計算問題" ,
	     "その他の１変数関数の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryIteration );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionBitwiseFunction );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnaryOther );
  }
}

AC( ExplicitExpressionUnaryLinearRecursion )
{
  CERR( "L項間線形漸化式" );
  CERR( "a_n = sum(i,0,L){c_i a_{n-L+i}} (n>=L)" );
  CERR( "第N項a_Nを法Bで求めます。" );
  CERR( "" );
  CERR( "適宜Z/B Zの型" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\ConstexprModulo" );
  CERR( "\\Mathematics\\Arithmetic\\Mod\\QuotientRing" );
  CERR( "を用いて" );
  CERR( "- O(LN)が間に合いそうならば直近L+1項をメモ化する動的計画法" );
  CERR( "- O(L^2 log N)が間に合いそうならば行列累乗" );
  CERR( "  \\Mathematics\\LinearAlgebra" );
  CERR( "- B=998244353かつ初項L項も漸化式を満たしかつO(N log N)が間に合いそうならば" );
  CERR( "  1/(1-sum(i,0,L){c_i x^i})のN次係数の高速フーリエ変換による計算" );
  CERR( "  \\Mathematics\\Polynomial\\Mod" );
  CERR( "- 係数列(c_i)_iが周期Pを持ちO(PN log N)が間に合いそうならばP個の区間加算BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalAddo" );
  CERR( "- 係数列(c_i)_iが単調でD階差分が定数列でO((N+L)D)が間に合いそうならば" );
  CERR( "  「係数列のd階Δ^d(c_i)_i差分と(a_i)_{i=n-L+d+1}^{n}の内積dp[n][d]」" );
  CERR( "  を管理する動的計画法" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionUnaryIteration )
{
  CERR( "定義域の要素数N、テストケース数T、反復回数の上限Kとします。" );
  CERR( "- O((N + T)log_2 K)が通りそうならばダブリング" );
  CERR( "  \\Mathematics\\Function\\Iteration\\Doubling" );
  CERR( "- O(TN)が通りそうならばループ検出" );
  CERR( "  \\Mathematics\\Function\\Iteration\\LoopDetection" );
  CERR( "- O(N)すら通らなさそうならば関数の規則性を見付けるための実験" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionBitwiseFunction )
{
  CERR( "(M,*)を可換モノイドとします。写像f:N^n->(M,*)がbit準同型とは" );
  CERR( "- (a&b)==0を満たす任意のa,bに対しf(a|b)=f(a)*f(b)" );
  CERR( "を満たすということとします。" );
  CERR( "" );
  CERR( "例えば" );
  CERR( "- 恒等写像:N->(N,+)" );
  CERR( "- 恒等写像:N->(N,|)" );
  CERR( "- 恒等写像:N->(N,^)" );
  CERR( "- 固定の元との2項bit演算:N->(N,+)" );
  CERR( "- 二進法表記:N->(N^{oplus N},+)" );
  CERR( "- 二進法の桁和:N->(N,+)" );
  CERR( "- 二進法表記と加法的準同型の合成:N->(Z,+)" );
  CERR( "- 二進法表記と乗法的準同型の合成:N->(Z,*)" );
  CERR( "- ２つのbit関数f,g:N->(M,*)の各点積fg:N->(M,*)" );
  CERR( "- ２つのbit関数f,g:N->(M,*)の直積の積f*g:N^2->(M,*)" );
  CERR( "- (M,*)が群である場合のbit関数f:N->(M,*)と逆元の合成" );
  CERR( "などがbit準同型です。" );
  ASK_NUMBER(
	     "(Z,+)へのbit準同型" ,
	     "(Z,*)へのbit準同型の線形和"
	     );
  if( num == num_temp++ ){
    CERR( "ノード数nの根付き木上の関数tと引数2のbit演算otimesに対し、" );
    CERR( "多引数化otimes:N^n->Nとbit準同型f:N->(Z,+)の合成に" );
    CERR( "tを代入した値をf(t)と略記します。" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "" );
    CALL_AC( ExplicitExpressionBitFunctionOnTree );
  } else if( num == num_temp++ ){
    CERR( "N^nの部分集合Sとbit準同型f:N^n->(Z,*)に対し、" );
    CERR( "Sの要素aをわたるf(a)の総和は、aの各成分をbitに分解して" );
    CERR( "f(a)を積で表示し、その途中までの積の総和を管理する" );
    CERR( "桁DPを検討しましょう。" );
  }
}

AC( ExplicitExpressionUnaryOther )
{
  CERR( "まずは小さい入力の場合を愚直に計算し、OEISで検索しましょう。" );
  CERR( "https://oeis.org/?language=japanese" );
  CERR( "" );
  CERR( "次に出力の定義と等価な式を考察しましょう。" );
  CERR( "- 単調ならば、冪乗や階乗" );
  CERR( "- 定義にp進法が使われていれば、各種探索アルゴリズム" );
  CERR( "- 入力が素数に近い場合に規則性があれば、p進付値、p進法、" );
  CERR( "  オイラー関数、約数の個数など" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "そして前計算を試みましょう。候補としては" );
  CERR( "- 階乗／逆元／場合の数" );
  CERR( "- 素数列挙" );
  CERR( "- １つまたは複数の整数の約数列挙" );
  CERR( "- オイラー関数の値の列挙" );
  CERR( "- サブゴールとなる関係式を満たす解の列挙" );
  CERR( "があります。特に漸化式による前計算が可能な場合、法または周期を" );
  CERR( "バケット分割してソースコードに埋め込む高速化を検討しましょう。" );
}

AC( ExplicitExpressionArraySum )
{
  ASK_NUMBER(
	     "１つの配列の成分と位置を受け取る関数の総和の計算問題" ,
	     "１つの配列の部分列を受け取る関数の総和の計算問題" ,
	     "配列を受け取る関数の総和の計算問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 和の順序交換" );
    CERR( "- 同じ値になる項の纏め上げ" );
    CERR( "- 2変数関数fと数列(a_i)_iが与えられ、sum_i f(a_i,i)を求める場合、" );
    CERR( "  f(x,i)=sum_k b_{i,k} g_k(x)と表示できれば" );
    CERR( "  (b_{i,k})_iと(g_k(a_i))_iの内積の総和に帰着されます。" );
    CERR( "  内積は片方の添え字を反転させることで畳み込みに帰着させることができます。" );
    CERR( "  配列への操作がシフトである場合は繰り返し内積を求めることになるので、" );
    CERR( "  適当な法での高速フーリエ変換" );
    CERR( "  \\Mathematics\\Arithmetic\\Mod" );
    CERR( "  \\Mathematics\\Polynoial" );
    CERR( "- 2変数関数fと数列(a_i)_iが与えられ、sum_{i,j} f(a_i,a_j)を求める場合、" );
    CERR( "  f(x,y)=sum_k g_k(x) h_k(y)と表示できれば" );
    CERR( "  (g_k(a_i))_iの累積和と(h_k(a_j))_jの積の総和に帰着されます。" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    ASK_NUMBER(
	       "連続部分列への分割に関する関数の総和の計算問題" ,
	       "連続とは限らない部分列への分割に関する関数の総和の計算問題"
	       );
    if( num == num_temp++ ){
      CERR( "配列の添字集合は全順序集合なので、木の分割の問題に一般化されます。" );
      CALL_AC( ExplicitExpressionFunctionOnTree );
      CERR( "" );
      CERR( "更にfが部分列の長さに関する再帰的な構造を持つ場合、全ての連続部分列に" );
      CERR( "対しfの値を前計算することを検討しましょう。" );
    } else if( num == num_temp++ ){
      CERR( "配列の並び換えによって答えが変わらないので、適切にソートしてから" );
      CERR( "計算することを検討しましょう。" );
    }
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArrayCombinatorial );
  }
  CERR( "" );
  CERR( "Nが大きい場合と小さい場合で解法を変える考察を忘れないようにしましょう。" );
}

AC( ExplicitExpressionArrayCombinatorial )
{
  CERR( "二項展開や積の和典型などの組み合わせ論的解釈" );
  CERR( "https://ei1333.hateblo.jp/entry/2021/07/30/144201" );
  CERR( "https://ladywingclover.hatenablog.com/entry/2022/11/24/084524" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionFunctionOnPermutation )
{
  ASK_NUMBER(
	     "１つの順列に関する値の計算問題" ,
	     "順列を受け取る関数の総和の計算問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 符号そのものの計算問題は" );
    CERR( "  - O(N log_2 N)やO(N^2)が間に合いそうなら転倒数の計算" );
    CERR( "  - O(N log_2 N)が間に合わなさそうなら互換表示（O(N)）" );
    CERR( "- 符号と何かの積の和は行列式に帰着させ、" );
    CERR( "  - 行列式そのものなら行基本変形（O(N^3)）" );
    CERR( "  - 余因子展開の途中の値が必要ならメモ化再帰（O(N 2^N)）" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "転倒数は" );
    CERR( "- O(N^2)が通りそうならば愚直な二重ループ" );
    CERR( "- O(N log_2 N)が通りそうならば可換群BIT" );
    CERR( "  \\Mathematics\\Combinatorial\\Permutation" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
    CERR( "で計算しましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArrayCombinatorial );
    CERR( "" );
    CERR( "条件を満たす順列全体をわたる転倒数の総和／期待値は、" );
    CERR( "各i<jごとにそこで転倒が生じる順列の個数を計算し、その総和／期待値を" );
    CERR( "取りましょう。条件が良ければ、転倒が生じる順列の個数は転倒が生じるとは" );
    CERR( "限らない順列の個数の半分となります。" );
  }
}

AC( ExplicitExpressionFunctionOnTree )
{
  CERR( "木を受け取る関数fが与えられているとします。" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "部分木に関する良い遷移関係を探し、（全方位）木DP" );
  CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirstSearch\\Tree" );
  CERR( "を検討しましょう。" );
  ASK_YES_NO( "fがbit演算の多引数化である問題ですか？" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionBitFunctionOnTree );
  }
}

AC( ExplicitExpressionBitFunctionOnTree )
{
  CERR( "「Tの各ノードvを根とする部分木でのj桁目のbit状態sの個数dp[v][s][j]」" );
  CERR( "を管理するv,s,jに関する動的計画法を検討しましょう。" );
  CERR( "" );
  CERR( "これはTが{0,1,...,N-1}に通常の順序の逆順序を入れたものである場合は" );
  CERR( "「第i成分で切った部分列でのj桁目のbitがs（=0,1）である個数dp[i][s][j]」" );
  CERR( "を管理することに他なりません。" );
}

AC( FunctionOnTree )
{
  CERR( "木Tの分割Pに対し、Pの各成分pを渡るf(p)の総和をF(P)と置きます。" );
  CERR( "Tに根を固定し、深さ優先探索でTの頂点にラベルづけをします。" );
  CERR( "" );
  CERR( "Pの各成分pに対しpの各頂点のラベルの最小値をD(p)と置き、" );
  CERR( "Dについて昇順にPを並べます。" );
  CERR( "" );
  CERR( "Pの末尾成分pを削除した分割P'が元の木からpを削除した木の分割であり" );
  CERR( "F(P)=F(P')+f(p)と表せることに注意しましょう。" );
}

AC( ExplicitExpressionFunctionOnNonTreeGraph )
{
  CERR( "- 部分集合上の関数の計算問題は" );
  CERR( "  - O(N 2^N)が間に合いそうなら高速ゼータ変換／メビウス変換" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - O(N^2)が間に合いそうで要素数にのみ依存するならマーラー変換" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
  CERR( "- その他の順序集合上の関数の計算問題はゼータ変換／メビウス変換" );
  CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "- 辺に重みが付けられたグラフ上の２点を結ぶ経路（もしくは頂点の重複のない経路）P" );
  CERR( "  全体をわたってPに沿った辺の重みの総乗f(P)を考えf(P)の下限を計算する問題は" );
  CERR( "  - 重みが「単位元が最小元である等号つき全順序モノイドM個の直積」に値を持ち" );
  CERR( "    O(M(V+E)log V)が間に合いそうならば各直積成分に対するダイクストラ法" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Dijkstra" );
  CERR( "  - 重みが「単位元が最小元であるmeet半束モノイド」に値を持ち" );
  CERR( "    O(V^3)が間に合いそうならばワーシャルフロイド法" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionOrder )
{
  ASK_NUMBER(
	     "与えられた順序集合に関する問題" ,
	     "順序集合を更新する問題"
	     );
  if( num == num_temp++ ){
    CERR( "多重集合Sを何らかの順序でソートした配列aに関する問題を考えます。" );
    ASK_NUMBER(
	       "与えられた要素sに対しs=a[i]を満たすiを求める問題" ,
	       "与えられたiに対するa[i]を求める問題" ,
	       "与えられたiに対するa[0],...,a[i]を全て求める問題"
	       );
    if( num == num_temp++ ){
      ASK_YES_NO( "各iごとにa[i]が高速に求められる問題ですか？" );
      if( reply == "y" ){
	CERR( "iに関する二分探索を検討しましょう。" );
      } else {
	CERR( "s未満のSの項の数え上げを検討しましょう。" );
	ASK_YES_NO( "Sが固定長変数関数の像で与えられますか？" );
	if( reply == "y" ){
	  CERR( "固定長変数関数の逆像の数え上げ問題は、" );
	  CALL_AC( CountingExplicitExpression );
	}
      }
    } else if( num == num_temp++ ){
      CERR( "Sの各要素sごとにs未満のSの項を数え上げてsに関する二分探索を検討しましょう。" );
      ASK_YES_NO( "Sが固定長変数関数の像で与えられますか？" );
      if( reply == "y" ){
	CERR( "固定長変数関数の逆像の数え上げ問題は、" );
	CALL_AC( CountingExplicitExpression );
      }
    } else if( num == num_temp++ ){
      CERR( "- 各iごとにa[i]が高速に求められるならば、a[i]以下のSの要素の全列挙を検討しましょう。" );
      CERR( "- Sが多重集合M個の和集合であるならば、各多重集合をソートしてM個のpriority_queueでイベントソート" );
      CERR( "を検討しましょう。" );
    }
    CERR( "" );
    CERR( "特に辞書式順序でs未満の項の数え上げをする際は、" );
    CERR( "「sとd文字目で初めてズレるl文字の項の総数count[d][l]」" );
    CERR( "のdとlをわたる総和を求めましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  }
}

AC( ExplicitExpressionProbability )
{
  CERR( "- 確率計算は" );
  CERR( "  - 余事象や包除原理（高速ゼータ変換／メビウス変換）" );;
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - 同様に確からしい事象の特定" );
  CERR( "  - ベイズの定理" );
  CERR( "- 期待値計算は" );
  CERR( "  - 上記方法での確率計算" );
  CERR( "  - 対象を独立な和で表して線形性" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionCountingOperation )
{
  CERR( "操作回数を求める際は、操作列を「一斉に処理できる区間」いくつかに分割し、" );
  CERR( "それぞれの区間での処理を計算することを検討しましょう。" );
}

AC( ExplicitExpressionArea )
{
  CERR( "- 三角形の面積は外積" );
  CERR( "  Mathematics\\Geometry\\AffineSpace" );
  CERR( "- 格子点を頂点に持つ多角形の面積はピックの定理" );
  CERR( "  https://en.wikipedia.org/wiki/Pick%27s_theorem" );
  CERR( "- 関数のグラフで囲まれた領域の面積は積分" );
  CERR( "  - 原始関数による計算" );
  CERR( "  - 区分求積法" );
  CERR( "  - モンテカルロ法" );
  CERR( "を検討しましょう。" );
}

AC( Maximisation )
{
  ASK_NUMBER(
	     "低次元アフィン空間上の関数の最大／最小化問題" ,
	     "配列上の関数の最大／最小化問題" ,
	     "配列の隣接成分間関係式を満たす部分列の最長化問題" ,
	     "集合の部分集合の最大化問題" ,
	     "木上の関数の最大／最小化問題" ,
	     "移動コスト最小化問題" ,
	     "文字列のマッチングに関する最大／最長化問題" ,
	     "最大二部マッチング問題" ,
	     "確率／期待値の最大化問題" ,
	     "操作回数の最小化問題" ,
	     "最大化戦略の構築問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationSubsetSize );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationStringMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationBipartiteMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationProbability );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMaximisation );
  }
}

AC( MaximisationFunctionOnAffineSpace )
{
  ASK_NUMBER(
	     "凸関数の最小／最大化問題" ,
	     "可微分関数の最小／最大化問題" ,
	     "絶対値の最小／最大化問題"
	     );
  if( num == num_temp++ ){
    CERR( "三分探索を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "ニュートン法を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "符号を用いて絶対値を外しましょう。" );
    CERR( "- 単調な式に帰着できる場合、二分探索" );
    CERR( "- 最大化問題の場合、符号パターンの全探策" );
    CERR( "- マンハッタン距離などは一次変換" );
    CERR( "を検討しましょう。" );
  }
  CERR( "" );
  CERR( "複数のパラメータを決定すべき場合は、サブゴールの式の値を決め打ちましょう。" );
}

AC( MaximisationFunctionOnArray )
{
  ASK_NUMBER(
	     "問題文または入力で与えられる１つの配列に関する問題" ,
	     "条件を満たす任意の配列に関する問題"
	     );
  if( num == num_temp++ ){
    ASK_NUMBER(
	       "成分を受け取る関数の部分和の最大化問題" ,
	       "配列の変更と配列を受け取る関数の合成の最大化問題"
	       );
    if( num == num_temp++ ){
      CALL_AC( MaximisationSubArraySum );
    } else if( num == num_temp++ ){
      CALL_AC( MaximisationArrayFunction );
    }
  } else if( num == num_temp++ ){
    CERR( "- 取り得る値が少なく関数が長さに関して再帰的構造を持つ場合は、" );
    CERR( "  「長さiの時に可能な値全体または一部の集合dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- 「v以上の値を取り得るか否か」が判定可能である時は" );
    CERR( "  vに関する二分探索" );
    CERR( "を検討しましょう。" );
  }
}

AC( MaximisationSubArraySum )
{

  CERR( "和を取る値を価値と呼ぶことにします。" );
  CERR( "配列の項数N、第i成分の価値A_i、価値の総和v、vの上限Vとします。" );
  CERR( "{0,...,N-1}の部分集合Iであって、" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- その他の条件" );
  CERR( "を満たすものの数え上げを考えます。" );
  ASK_NUMBER(
	     "Iにコスト制約があり重複した選択を許す場合" ,
	     "Iにコスト制約があり重複した選択を許さない場合" ,
	     "Iに追加の制約がない場合"
	     );
  if( num == num_temp++ ){
    CERR( "各選択のコスト上限が存在する場合、その上限以下の項だけを考えましょう。" );
    CERR( "コストの次元をK<=2、n項目のコストをC_nとし、" );
    CERR( "m選択目ではC_n[k_m]<=D_mを満たす項nを選べるとします。" );
    CERR( "" );
    CERR( "項{C_n,n}と選択{k_m,D_m}をそれぞれ辞書式順序でソートし、" );
    CERR( "以下の手順で選択を昇順に決定していきましょう。" );
    CERR( "- K=1の場合、各選択では可能な選択の中で最大のものを採用しましょう。" );
    CERR( "- K=2の場合、各選択では可能な選択の{第2成分,項番号}をsetで管理しつつ" );
    CERR( "  その中で最大のものを採用しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "各選択のコスト上限が存在する場合、その上限以下の項だけを考えましょう。" );
    CERR( "コストの総和上限C<∞とします。" );
    CERR( "- O(C^2)が通りそうならば" );
    CERR( "  「コストcの項の価値の最大値v[c]」" );
    CERR( "  を前計算し" );
    CERR( "  「コストの総和がc以下の時の価値の最大値dp[c]」" );
    CERR( "  を管理するcに関する動的計画法" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- O(2^N)が通りそうならば愚直に全探策" );
    CERR( "- O(N 2^{N/2})が通りそうならば半分全列挙" );
    CERR( "- O(NV)が通りそうならば[v-V,v+V]での実現可能性を" );
    CERR( "  遷移する動的計画法" );
    CERR( "  https://stackoverflow.com/a/18949218" );
    CERR( "- O((N+V)log_2 V)が通りそうでVが10^5オーダーで" );
    CERR( "  プロス素数Pを法とするならば法Pでの高速フーリエ変換による" );
    CERR( "  exp(logの総和)計算" );
    CERR( "  \\Mathematics\\Arithmetic\\Mod" );
    CERR( "  \\Mathematics\\Polynomial" );
    CERR( "を検討しましょう。" );
  }
}

AC( MaximisationArrayFunction )
{
  CERR( "配列を受け取る関数Fが与えられているとします。与えられた配列Aに" );
  CERR( "何らかの処理をして得られる配列Bに対するF(B)の最大化問題は、" );
  CERR( "最大化すべき式のサブゴールfに表れる項xのうち決め打ちやすいものを探しましょう。" );
  CERR( "- 配列の長さをiで打ち切った時のxの候補数をX(i)" );
  CERR( "- 配列の長さをiで打ち切ってxを決め打った時の配列の長さi+1でのxの候補数をdX(i)" );
  CERR( "と置きます。" );
  CERR( "- O(sum_i X(i) dX(i))が通りそうでfがxからO(1)で計算できるならば、" );
  CERR( "  iとxに関する動的計画法" );
  CERR( "- O(N log_2 X(N))が通りそうで" );
  CERR( "  - fがxからO(N)で計算できxに関して単調ならば、xの二分探索" );
  CERR( "  - fがxからO(N/x)で計算できるならば、xの全探索" );
  CERR( "- O(N log_2 N)が通りそうでxを並び替えるとfがxからO(log_2 N)で計算できるならば、" );
  CERR( "  優先度つきキューなどでのxの管理" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationArrayLength )
{
  CERR( "全順序か疎な半順序かで効率的な実装が違います。" );
  CERR( "- 全順序ならば、条件を満たす部分列の長さの最大値をインデックスに持つ" );
  CERR( "  配列を用いて、それらの部分列の末尾である項を記録すること" );
  CERR( "  \\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence" );
  CERR( "- 疎な半順序ならば、条件を満たす部分列の末尾をインデックスに持つ" );
  CERR( "  連想配列を用いて、それら部分列の長さの最大値を記録すること" );
  CERR( "  \\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence\\Subwalk" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationSubsetSize )
{
  CERR( "与えられた集合のサイズをNと置きます。" );
  CERR( "- O(2^N)が間に合いそうならば、bit全探策" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "- O(N2^N)が間に合いそうならば、部分集合の包含対のbit全探策" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "- 極大鎖の計算ならば、後続関数を定義し、極大元から後続関数の逆像のグラフの深さ計算" );
  CERR( "- 極大反鎖の計算ならば、" );
  CERR( "  - Dilworthの定理の証明に基く構築" );
  CERR( "    https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
  CERR( "  - 後続関数を定義し、後続に関する二分探索" );
  CERR( "- 完全代表系の計算ならば、幅優先探索やUnionFindによる連結成分計算" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
  CERR( "  \\Utility\\VLTree\\UnionFindForest" );
  CERR( "  " );
  CERR( "を検討しましょう。" );
}

AC( MaximisationFunctionOnTree )
{
  CERR( "木を受け取る関数fが与えられているとします。" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "「第i頂点までで切った時のF(P)たちの最大値dp[i]」" );
  CERR( "を管理するiに関する動的計画法（O(N^2×fの計算量)）" );
  CERR( "を検討しましょう。" );
}

AC( MinimisationMovingCost )
{
  ASK_NUMBER(
	     "１始点多終点最小コスト移動（迷路）問題" ,
	     "多始点多終点最小コスト移動（被覆）問題" ,
	     "１始点多経由点最小コスト移動（スタンプラリー）問題"
	     );
  if( num == num_temp++ ){
    CERR( "- コストがなくO(V+E)が通りそうならば幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- コストが0か1でO(V+E)が通りそうならば01幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst\\ZeroOne" );
    CERR( "- コスト総和上限をCとしO((V+E)C)が間に合いそうならば" );
    CERR( "  コストも状態に含めたグラフ上での幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- O((V+E)log_2 E)が間に合いそうならばダイクストラ法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
  } else if( num == num_temp++ ){
    CERR( "- コストがなくO(V+E)が通りそうならば、多点幅優先探索か" );
    CERR( "  頂点を１つ追加し各始点に辺を張ったグラフ上での幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst" );
    CERR( "- コストが0か1でO(V+E)が通りそうならば、多点01幅優先探索" );
    CERR( "  頂点を１つ追加し各始点に辺を張ったグラフ上での01幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirst\\ZeroOne" );
    CERR( "- max演算を考えておりO(E(log_2 E + α(V)))が通りそうならば、" );
    CERR( "  重みで辺をソートして素集合データ構造" );
    CERR( "  \\Utility\\VLTree\\UnionFindForest" );
    CERR( "- O((V+E)log_2 E)が通りそうならば、" );
    CERR( "  頂点を１つ追加し各始点に辺を張ったグラフ上でのダイクストラ法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Dijkstra" );
    CERR( "- O(V^3)が通りそうならば、" );
    CERR( "  ワーシャルフロイド法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
  } else if( num == num_temp++ ){
    CERR( "- HeldKarp法" );
    CERR( "- 移動方法を分類するパラメータの全探策" );
  }
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "点の座標と最小化すべきコスト以外の数値xに変化がある場合、最小コスト移動において" );
  CERR( "xの動く範囲を絞って点の座標とxの組を頂点とするグラフを考えましょう。" );
  CERR( "" );
  CERR( "重みが辺ではなく頂点についている場合" );
  CERR( "- 羃等モノイドならば特に頂点は追加せず" );
  CERR( "- 羃等でない可換モノイドならば重みが単位元である始点と終点を追加して" );
  CERR( "各辺の重みを両端の重みに演算を適用したもので定義しましょう。" );
  CERR( "" );
  CERR( "辺集合Eが大き過ぎる場合、十分小さい部分集合E'であって条件" );
  CERR( "「任意の経路pに対し、E'に属す辺のみを通るある経路p'が存在して、" );
  CERR( "  pのコスト>=p'コストである」" );
  CERR( " を満たすものを探すことを検討しましょう。" );
}

AC( MaximisationStringMatching )
{
  CERR( "基本的には丁寧にループを回して解きましょう。" );
  CERR( "- 比較対象が少ない場合、前または後ろから順に探索（貪欲法／動的計画法）" );
  CERR( "- ワイルドカードを含む場合、" );
  CERR( "  - 前または後ろから順に場合分けをしてO(N)で処理できるか" );
  CERR( "  - 可能な代入方法を絞り込んでO(N)種類に落せるか" );
  CERR( "- 比較回数が多い場合、ローリングハッシュ" );
  CERR( "  \\Utility\\String\\RollingHash" );
  CERR( "- 部分回文の最長化をする場合、尺取り法による前計算" );
  CERR( "  \\Utility\\String\\Palindrome" );
  CERR( "- マッチングする部分文字列の最長化をする場合、Zアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- マッチングする文字数の最大化をする場合、文字の種類分の{0,1}値配列に" );
  CERR( "  分けて内積の最大化（添え字を反転させて適当な法での畳み込み）" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod" );
  CERR( "  \\Mathematics\\Polynomial" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationBipartiteMatching )
{
  CERR( "ホップクロフトカープ法や最大流" );
  CERR( "\\Mathematics\\Geometry\\Graph\\HopcroftKarp" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationProbability )
{
  CERR( "操作／戦略を選んで確率／期待値を最大化する場合、" );
  CERR( "被操作対象や可能な操作／戦略のデータなどを状態として定式化し、" );
  CERR( "「sを経由する場合の確率／期待値の最大値dp[s]」" );
  CERR( "を管理するsに関する動的計画法を検討しましょう。" );
}

AC( Counting )
{
  ASK_NUMBER(
	     "固定長変数関数の逆像の数え上げ問題" ,
	     "条件を満たす配列／文字列の数え上げ問題" ,
	     "条件を満たすグラフの数え上げ問題" ,
	     "与えられた配列の部分列の数え上げ問題" ,
	     "与えられた文字列の部分文字列の数え上げ問題" ,
	     "与えられた木の分割の数え上げ問題" ,
	     "与えられた集合の部分集合の数え上げ問題" ,
	     "戦略／操作方法の数え上げ問題" ,
	     "経路の数え上げ問題" ,
	     "操作回数の計算問題" ,
	     "カタラン数の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingExplicitExpression );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPartitionOfTree );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubset );
  } else if( num == num_temp++ ){
    CALL_AC( CountingStrategy );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPath );
  } else if( num == num_temp++ ){
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  }
}

AC( CountingExplicitExpression )
{
  CERR( "- 変数の対称性があれば大小関係を制限した全探策" );
  CERR( "- 何らかの約数となるなど動く範囲が狭い変数があればそれらを決め打った全探策" );
  CERR( "- f(g(x),g(y))=kの形は" );
  CERR( "  - まず各b in im(g)に対しf(a,b) = kを満たすa in im(g)全体を前計算する。" );
  CERR( "  - 次に|dom(g)| = N、max im(g) = Mとしてim(g)を多重集合として" );
  CERR( "    - O(N log_2 N)が間に合いそうならばmap iterator + map::lower_bound" );
  CERR( "    - O(N)が間に合いそうならばunordered_map iterator + unordered_map::[]" );
  CERR( "    - O(M+N)が間に合いそうならば配列全探策 + 配列::[]" );
  CERR( "    - x,yに制限h(x)<h(y)がある場合はh(x)の上限cについてループして" );
  CERR( "      g(x)の集合を更新していき、それと並行してyをc<h(y)の範囲で全探索" );
  CERR( "    により管理する。" );
  CERR( "  - 最後に各yごとにf(a,g(y)) = kを満たす各a in im(g)に対しa = g(x)を満たす" );
  CERR( "    xをim(g)の多重集合構造を使って数え上げる。" );
  CERR( "- f(g(x),g(y))<=kの形でfとgが単調増加する時は" );
  CERR( "  - まず各b in im(g)に対しf(a,b) <= kを満たすaの上限を二分探索で前計算する。" );
  CERR( "  - 次にそうして得られる各aに対しg(x)<=aを満たすxの上限を二分探索で前計算する。" );
  CERR( "  - 最後に各yごとにb = g(y)に対する前計算結果の総和を求める。" );
  CERR( "を検討しましょう。" );
}

AC( CountingArray )
{
  ASK_NUMBER(
	     "配列を受け取る関数の値が固定された配列の数え上げ問題" ,
	     "隣接成分間関係式を満たす配列の数え上げ問題" ,
	     "その他の関係式を満たす配列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CERR( "- 配列の種類が少ない場合は、全ての配列に対する関数の値の前計算" );
    CERR( "- 取り得る値が少なく関数が長さに関して再帰的構造を持つ場合は、" );
    CERR( "  「長さiの時に値vである配列の総数dp[i][v]」" );
    CERR( "  を管理するi,vに関する動的計画法" );
    CERR( "- 関数が区間和などデータ構造で計算できる場合は、" );
    CERR( "  データ構造に翻訳した上での数え上げ" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 半順序での単調性の場合、" );
    CERR( "  - 全順序ならば、数の分割方法などへの翻訳" );
    CERR( "  - 疎な半順序ならば、グラフの前計算" );
    CERR( "- その他の条件の場合は動的計画法で、" );
    CERR( "  - 禁止条件の時は余事象を引く更新" );
    CERR( "  - 複数条件の時は包除原理による更新" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    ASK_NUMBER( "配列への格納順が関係ありますか？" );
    if( reply == "y" ){
      CERR( "半順序を構成しグラフの数え上げに帰着することを検討しましょう。" );
      CALL_AC( CountingGraph );
    } else {
      CERR( "（多重）集合やソートされた配列の数え上げに帰着することを検討しましょう。" );
      CALL_AC( CountingSubset );
    }
  }
}

AC( CountingGraph )
{
  CERR( "- 木はケーリーの公式やその亜種" );
  CERR( "  https://oeis.org/A000272" );
  CERR( "- なもりグラフはサイクルとそれ以外への分割" );
  CERR( "を検討しましょう。" );
}

AC( CountingSubArray )
{
  ASK_NUMBER(
	     "配列の成分を受け取る関数の部分和を固定した部分列の数え上げ問題" ,
	     "配列の隣接成分間関係式を満たす部分列の数え上げ問題" ,
	     "配列のその他の関係式を満たす部分列の数え上げ問題" ,
	     "配列の部分列から取得位置情報を落とした配列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGeneralRelationSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubArrayImageArray );
  }
}

AC( CountingSumFixedSubArray )
{
  CERR( "和を取る値を価値と呼ぶことにします。" );
  CERR( "配列の項数N、第i成分の価値A_i、価値の総和v、vの上限Vとします。" );
  CERR( "{0,...,N-1}の部分集合Iであって、" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- その他の条件" );
  CERR( "を満たすものの数え上げを考えます。" );
  ASK_NUMBER(
	     "Iにコスト制約がある場合" ,
	     "Iが連続部分列に限られる場合" ,
	     "Iに追加の制約がない場合"
	     );
  if( num == num_temp++ ){
    CERR( "O(2^N)が通りそうならば価値とコストを次数とする愚直な２変数多項式乗算" );
    CERR( "  \\Mathematics\\Polynomial\\Multivariable" );
  } else if( num == num_temp++ ){
    CERR( "- O(N^2)が通りそうならば累積和で差の取得" );
    CERR( "- O(N log_2 N)が通りそうでv=0に固定ならば累積和でCountUnitProdRange" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProd" );
  } else if( num == num_temp++ ){
    CERR( "- O(2^N)が通りそうならば愚直な１変数多項式乗算" );
    CERR( "- O(2^{N/2}N)が通りそうでvが１つの値に固定ならば半分ずつ多項式乗算をして" );
    CERR( "  最後にそれらの積のv次係数のみの計算" );
    CERR( "- O((N+V)log_2 V)が通りそうでVが10^5オーダーで" );
    CERR( "  プロス素数Pを法とするならば法Pでの高速フーリエ変換による" );
    CERR( "  exp(logの総和)計算" );
    CERR( "  \\Mathematics\\Arithmetic\\Mod" );
    CERR( "  \\Mathematics\\Polynomial" );
  }
  CERR( "を検討しましょう。" );
}

AC( CountingRestrctedSubArray )
{
  ASK_NUMBER(
	     "連続部分列の数え上げ問題" ,
	     "連続とは限らない部分列の数え上げ問題" ,
	     "部分順列（部分列の並び換え）の数え上げ問題"
	     );
  CERR( "長さNの配列Aと、L+n<=N+1を満たす整数n,Lと" );
  CERR( "- 整数iに関する条件Q(i)" );
  CERR( "- 各0<=l<Lに対するn-tuple(b_0,...,b_{n-1})に関する条件R_l(b_0,...,b_{n-1})" );
  CERR( "が与えられているとし、配列Bの条件P(B)を" );
  CERR( "「Bの長さ|B|がQ(|B|)かつ|B|<L+nを満たし、かつ任意の0<=l<=|B|-nに対し" );
  CERR( "　R_l(B_l,...,B_{l+n-1})が成り立つ。」" );
  CERR( "の論理積として定めます。" );
  CERR( "" );
  CERR( "例えば山型の部分列の数え上げ問題ではN>=3かつ(n,L)=(2,2)で" );
  CERR( "- Q(i)=「i=3」" );
  CERR( "- R_0(b_0,b_1)=「b_0<b_1」" );
  CERR( "- R_1(b_0,b_1)=「b_0>b_1」" );
  CERR( "と表されます。" );
  CERR( "" );
  if( num == num_temp++ ){
    CALL_AC( CountingRestrctedContinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedDiscontinuousSubArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingRestrctedSubPermutation );
  }
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "特にR_l(B)たちがgcdやmaxなどの羃等演算に関する等式で与えられる場合は、" );
  CERR( "不等式の方が扱いやすいのでゼータ変換／メビウス変換" );
  CERR( "\\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "を検討しましょう。" );
}

AC( CountingRestrctedContinuousSubArray )
{
  CERR( "P(B)を満たすAの連続部分列Bの数え上げは、" );
  CERR( "- R_lたちがlに依存しないならば尺取り法O(N)" );
  CERR( "- R_lたちがlに依存する場合、" );
  CERR( "  - O(N^2)が通りそうなら左端を固定した愚直探索" );
  CERR( "  - O(N^2)が通らなさそうならR_lたちの読み替え" );
  CERR( "を検討しましょう。" );
}

AC( CountingRestrctedDiscontinuousSubArray )
{
  CERR( "P(B)を満たすAの連続とは限らない部分列Bの数え上げは、" );
  CERR( "- n-1<=i<=max{j<=N|Q(j)}を満たす各i" );
  CERR( "- (0,1,...,N-1)の長さn-1の各部分列s" );
  CERR( "に対する" );
  CERR( "「長さiで、任意の0<=l<=i-nに対しR_l(B)を満たし、" );
  CERR( "　末尾n-1項がsに対応するAの部分列Bの個数dp[i][s]」" );
  CERR( "を管理するi,sに関する動的計画法" );
  CERR( "\\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence" );
  CERR( "\\Mathematics\\Combinatorial\\Counting\\IncreasingSubsequence\\Subwalk" );
  CERR( "を検討しましょう。" );
}

AC( CountingRestrctedSubPermutation )
{
  CERR( "P(B)を満たすAの部分順列Bの数え上げは、" );
  CERR( "- n-1<=|S|<=max{j<=N|Q(j)}を満たす(0,1,...,N-1)の部分集合S" );
  CERR( "- Sの長さn-1の各部分順列s" );
  CERR( "に対する" );
  CERR( "「任意の0<=l<=|S|-nに対しR_l(B)を満たし、末尾n-1項がsに対応し、」" );
  CERR( "　全体がSに対応するAの部分順列Bの個数dp[S][s]」" );
  CERR( "を管理するS,sに関する動的計画法を検討しましょう。" );
  CERR( "" );
  CERR( "sの網羅は[0,N)^{n-1}の全探策でもS内の順列探索と定数倍しか変わらないので" );
  CERR( "実装の速さを優先しましょう。" );
  CERR( "" );
  CERR( "Nが小さい場合は概算値" );
  CERR( "7! ≒ 5×10^3" );
  CERR( "8! ≒ 4×10^4" );
  CERR( "9! ≒ 4×10^5" );
  CERR( "10! ≒ 4×10^6" );
  CERR( "11! ≒ 4×10^7" );
  CERR( "12! ≒ 5×10^8" );
  CERR( "を参考に順列の全列挙" );
  CERR( "\\Mathematics\\Combinatorial\\Permutation" );
  CERR( "を検討しましょう。" );
}

AC( CountingGeneralRelationSubArray )
{
  ASK_NUMBER( "配列への格納順が関係ありますか？" );
  if( reply == "y" ){
    CERR( "半順序を構成しグラフの数え上げに帰着することを検討しましょう。" );
    CALL_AC( CountingGraph );
  } else {
    CERR( "（多重）集合やソートされた配列の数え上げに帰着することを検討しましょう。" );
    CALL_AC( CountingSubset );
  }
}

AC( CountingSubArrayImageArray )
{
  CERR( "入力で与えられる配列をAと置きます。" );
  CERR( "配列として等しいAの部分列のうち辞書式順序最小のものを数え上げる" );
  CERR( "部分列DPを検討しましょう。具体的には" );
  CERR( "「末尾が第i成分由来で辞書順最小なAの部分列の個数dp[i]」" );
  CERR( "「s=A[j]を満たすj<iの最大値last[i][s]」" );
  CERR( "の２つを管理するiに関する動的計画法を検討しましょう。" );
}

AC( CountingSubString )
{
  ASK_NUMBER(
	     "部分文字列から取得位置情報を落とした文字列全体の数え上げ問題" ,
	     "マッチングに関する性質を満たす部分文字列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CERR( "文字列を文字の配列とみなすことで、配列の問題に帰着させることができます。" );
    CALL_AC( CountingSubArrayImageArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingMatchingSubString );
  }
}

AC( CountingMatchingSubString )
{
  CERR( "- 自分とマッチングする部分文字列の数え上げ問題はZアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- 回文である部分文字列の数え上げ問題は" );
  CERR( "  - O(N^2)が通る場合、尺取り法による前計算" );
  CERR( "    \\Utility\\String\\Palindrome" );
  CERR( "  - O(N^2)が通らない場合、Manacherのアルゴリズムやローリングハッシュで前計算" );
  CERR( "    https://snuke.hatenablog.com/entry/2014/12/02/235837" );
  CERR( "    \\Utility\\String\\RollingHash" );
  CERR( "を検討しましょう。" );
}

AC( CountingPartitionOfTree )
{
  CERR( "木を受け取る関数fが与えられているとします。" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "" );
  CERR( "F(P)が固定された時のPの数え上げ問題は" );
  CERR( "「第i成分までで切った時のF(P)=vを満たすPの個数dp[i][v]」" );
  CERR( "を管理するi,vに関する動的計画法（O(N^2 v_max×fの計算量)）" );
  CERR( "を検討しましょう。" );
}

AC( CountingSubset )
{
  CERR( "与えられた集合のサイズをNと置きます。" );
  CERR( "- O(2^N)が間に合いそうならば、bit全探策" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "- O(N2^N)が間に合いそうならば、部分集合の包含対のbit全探策" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\BreadthFirstSearch\\BitExhausiveSearch" );
  CERR( "を検討しましょう。" );
}

AC( CountingStrategy )
{
  ASK_NUMBER(
	     "半順序集合上の移動経路の数え上げ問題" ,
	     "操作する対象の選択方法の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CERR( "- １つの始点からの移動を考える場合は" );
    CERR( "  「各点iへの移動経路の個数dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- １つの終点への移動を考える場合は" );
    CERR( "  「各点iからの移動経路の個数dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
  } else if( num == num_temp++ ){
    CERR( "操作対象を各非負整数iで適切に番号付けて" );
    CERR( "「i以下の番号の対象のみを考えた時の選択方法の個数dp[i]」" );
    CERR( "を管理するiに関する動的計画法" );
  }
  CERR( "を検討しましょう。" );
  ASK_YES_NO( "線形漸化式に帰着されますか？" );
  if( reply == "y" ){
    CALL_AC( ExplicitExpressionUnaryLinearRecursion );
    CERR( "を検討しましょう。" );
  }
}

AC( CountingPath )
{
  ASK_NUMBER(
	     "格子点上の経路の数え上げ" ,
	     "一般のグラフ上の経路の数え上げ" ,
	     );
  if( num == num_temp++ ){
    CERR( "始点から各点への経路数に関する漸化式を立式しましょう。" );
    CERR( "例えばパスカルの三角形上の経路数は、そのままパスカルの三角形で与えられます。" );
    CERR( "- 経路数がある不変量にのみ依存する場合、不変量ごとに管理して計算量を削減" );
    CERR( "- 領域に対称性がある場合、始点からある点pへの経路数とpの対称点から終点への経路数" );
    CERR( "  の間の関係式を立式" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "適宜カタラン数との関係も検討しましょう。" );
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CERR( "ループの不能な有向グラフは整礎なので、各点pごとに" );
    CERR( "-「pが探索されたか」を表すbool値配列" );
    CERR( "-「pへの辺を持つ未探索点の個数」を表す配列" );
    CERR( "を管理し毎回後者を全探策することでO(|V|^2+|E|)で全ての点を探索できます。" );
  }
}

AC( CountingParenthesisSequence )
{
  CERR( "第nカタラン数Cnは(2n)!/(n+1)!n!です。" );
  CERR( "- n対のカッコ列であって全てのカッコが閉じたもの" );
  CERR( "- 2n成分の総和が0で左端からの始端和が非負な±1列" );
  CERR( "- nノードの二分木" );
  CERR( "- n×n格子で左下から右上まで対角線を跨がず最初に右へ行く最短経路" );
  CERR( "- 2×nの標準ヤング図形（行／列ともに狭義単調増大になるような番号づけ）" );
  CERR( "- 円上のn頂点の多角形分割" );
  CERR( "- 円上のn+2角形の三角形分割" );
  CERR( "- 円上の2n頂点の非交差かつ次数2な無向辺の張り方" );
  CERR( "の数え上げなどがCnと一致します。" );
  CERR( "https://en.wikipedia.org/wiki/Catalan_number#Applications_in_combinatorics" );
}

AC( Solving )
{
  CERR( "- 単調関数は二分探索" );
  CERR( "- 可微分関数はニュートン法" );
  CERR( "- 一次関数は掃き出し法" );
  CERR( "- f(g(x),g(y),...)の形はf,g別々に前計算" );
  CERR( "を検討しましょう。" );
}

AC( Query )
{
  ASK_NUMBER(
	     "配列の範囲更新／取得クエリ問題" ,
	     "グラフの範囲更新／取得クエリ問題" ,
	     "グリッドの範囲更新／取得クエリ問題" ,
	     "文字列の範囲更新／比較クエリ問題" ,
	     "集合の範囲更新／比較クエリ問題" ,
	     "時系列データのクエリ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArray );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGraph );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGrid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryString );
  } else if( num == num_temp++ ){
    CALL_AC( QuerySet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTime );
  }
}

AC( QueryArray )
{
  ASK_NUMBER(
	     "可換群構造+を使う問題" ,
	     "可換羃等モノイド構造∨を使う問題" ,
	     "モノイド構造*を使う問題" ,
	     "非結合的マグマ構造*を使う問題" ,
	     "集合へのマグマ作用(*,\\cdot)を使う問題" ,
	     "モノイドへのマグマ作用(+,\\cdot)を使う問題" ,
	     "序数を扱う問題" ,
	     "一次関数とのmaxを取った値を使う問題" ,
	     "定数とのmaxを取った値の区間演算取得を使う問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArrayAbelianGroup );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayCommutativeIdempotentMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayNonAssociativeMagma );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMagmaSet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMagmaMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxLinearFunction );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxConstant );
  }
}

AC( QueryArrayAbelianGroup )
{
  CERR( "- 加算／全更新後の一点取得のみが必要ならば階差数列" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- 加算／全更新なしで区間取得のみが必要ならば累積積" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "- 区間加算／区間取得が必要ならば通常のBITや可換群BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template" );
  CERR( "- 一点代入／一点加算／区間取得が必要ならば可換群平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayCommutativeIdempotentMonoid )
{
  CERR( "- 一点代入／区間加算／一点取得／区間取得が必要ならば区間maxBITや可換羃等モノイドBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax\\Template" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMonoid )
{
  CERR( "- 一点代入／区間取得が必要ならばモノイドBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Template\\Monoid" );
  CERR( "- 一点加算／区間加算／一点取得／区間取得が必要ならばモノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Monoid" );
  CERR( "- 一点代入／一点取得／区間取得が必要ならばモノイドセグメント木" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayNonAssociativeMagma )
{
  CERR( "- 写像のコード化によるモノイドへの帰着" );
  CERR( "  \\Mathematics\\Function\\Encoder" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "モノイドに対しては" );
  CALL_AC( QueryArrayMonoid );
}

AC( QueryArrayMagmaSet )
{
  CERR( "- 一点作用／区間作用／一点取得が必要ならば双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\Dual" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMagmaMonoid )
{
  CERR( "- 区間代入／区間作用／区間加算／一点取得／区間取得が必要な場合は遅延評価平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Template\\LazyEvaluation" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayOrder )
{
  CERR( "- 一点代入／一点序数取得／全体での序数を実現する点の取得が必要ならば通常のBITで像を管理し" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  - 一点序数取得は平面走査" );
  CERR( "  - 全体での序数を実現する点の取得は平面走査＋二分探索" );
  CERR( "- 一点加算／区間での序数を実現する点の取得が必要ならば区間maxBITや可換羃等モノイドBITで" );
  CERR( "  区間最大／最小値＋二分探索で区間を分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax\\Template" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMaxLinearFunction )
{
  CERR( "- 一次関数による全体max更新／一点取得が必要な場合はConvex Hull Trick" );
  CERR( "  \\Mathematics\\Function\\MaxLinearFunction" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMaxConstant )
{
  CERR( "maxで全体更新をしない場合、つまりただ配列と定数のmaxの区間演算を" );
  CERR( "処理するだけの場合、クエリの順番を入れ替えることで全体更新をする場合に" );
  CERR( "帰着できます。従って以下では全体更新の問題を考えます。" );
  CERR( "" );
  CALL_AC( QueryTimeMax );
}

AC( QueryGraph )
{
  ASK_YES_NO( "代数構造を扱う問題ですか？" );
  if( reply == "yes" ){
    CERR( "- 可換群構造に関する加算／全更新後の一点取得のみが必要ならば階差数列" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\Tree" );
    CERR( "- 木上で可換モノイド構造に関する再帰が必要ならば全域木DP" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree" );
  } else {
    CERR( "深さ優先探索や動的木やUnionFind" );
    CERR( "\\Mathematics\\Geometry\\Graph\\DepthFirst\\Tree" );
    CERR( "\\Utility\\VLTree" );
    CERR( "\\Utility\\VLTree\\UnionFndForest" );
  }
  CERR( "を検討しましょう。" );  
}

AC( QueryGrid )
{
  CERR( "- 可換群構造に関する加算／全更新後の一点取得のみが必要ならば二次元階差数列" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "- 可換群構造に関する加算／全更新なしの矩形取得のみが必要ならば二次元累積和" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CulmulativeProd\\TwoDimentioal" );
  CERR( "- 可換群構造に関する加算／全更新後の矩形取得が必要ならば二次元階差数列／累積和の併用" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CulmulativeProd\\TwoDimentioal" );
  CERR( "を検討しましょう。" );
}

AC( QueryString )
{
  CERR( "文字列の一点更新（一文字更新／結合）／比較はローリングハッシュ" );
  CERR( "\\Utility\\String\\RollingHash" );
  CERR( "を検討しましょう。さらに文字列の範囲更新が必要な場合は" );
  CERR( "- 固定位置の文字のシフトによる一文字更新ならば加算更新" );
  CERR( "- 結合ならば加算更新と乗算による作用更新" );
  CERR( "に対応するデータ構造との併用を検討しましょう。" );
}

AC( QuerySet )
{
  CERR( "集合の一点更新（一要素更新／対称差）／比較はゾブリストハッシュ" );
  CERR( "\\Utility\\Set\\ZobristHash" );
  CERR( "を検討しましょう。さらに集合の範囲更新が必要な場合は" );
  CERR( "- 固定要素の有無の反転による一点更新" );
  CERR( "- 対称差" );
  CERR( "ともに加算更新に対応するデータ構造との併用を検討しましょう。" );
}

AC( QueryTime )
{
  ASK_NUMBER(
	     "maxによる時系列更新" ,
	     "加算による時系列更新"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryTimeMax );
  } else {
    CALL_AC( QueryTimeAddition );
  }
}

AC( QueryTimeMax )
{
  ASK_NUMBER(
	     "全体max更新／区間max取得" ,
	     "範囲max更新／一点取得"
	     );
  if( num == num_temp++ ){
    CERR( "与えられた配列を(A_i)_i、クエリで全体max更新を取る値を(M_q)_q、" );
    CERR( "クエリで区間演算を取る範囲を(I_q)_q、と置きます。" );
    CERR( "- (A_i)_iで初期化された配列(a_i)_i（説明の都合。実際は(A_i)_iを使う）" );
    CERR( "- (A_i,i)_iをソートした配列A'（構築O(N log N)）" );
    CERR( "- 0で初期化された{0,1}値配列(B_i)_i（構築O(N)）" );
    CERR( "- (A_i)_iと(M_q)_qの最小値より小さい値で初期化された整数変数M" );
    CERR( "を用意します。" );
    CERR( "" );
    CERR( "各qごとに、以下の処理を行います：" );
    CERR( "- M < M_qならば、以下の処理を行う：" );
    CERR( "  - MをM_qに変更する。" );
    CERR( "  - A'の先頭(x,i)がx < Mを満たす限り以下の処理を繰り返す：" );
    CERR( "    - a_iを区間演算の単位元に変更する。（クエリ合計O(N log N)）" );
    CERR( "    - B_iを1に変更する。（クエリ合計O(N log N)）" );
    CERR( "    - A'から(x,i)を削除する。（クエリ合計O(N log N)）" );
    CERR( "- 各i in Sに対するmax(A_i,M)を" );
    CERR( "  - 区間和が必要ならばa_i+B_i*M" );
    CERR( "  - 区間積が必要ならばa_i*M^{B_i}" );
    CERR( "  に読み替えてI_qでの区間演算取得をする。（各クエリO(log N)）" );
    CERR( "これにより合計O((N + Q)log N)で処理できます。" );
  } else {
    CERR( "時刻tにおける第i成分をA[t][i]と置きます。" );
    CERR( "A[-][i]が単調増大することに注目してxがA[t][i]>=xを満たす条件を決定し、" );
    CERR( "そのようなxの最大値を明示式で書き下しましょう。" );
    CERR( "" );
    CERR( "A[t][i]の明示式にmaxが現れる場合は場合分けでmaxを外し、" );
    CERR( "それぞれの場合の値を各種データ構造で処理しましょう。" );
  }
}

AC( QueryTimeAddition )
{
  CERR( "第i成分が変化し続ける区間たちの個数をIと置きます。" );
  CERR( "各区間を更に変化の仕方の違いで細分したものの個数をJと置きます。" );
  CERR( "- JがO(N)ならば各細分での変化量を求めましょう。" );
  CERR( "- JがO(N)でなくIがO(N)ならば各区間での変化量を求めましょう。" );
  CERR( "変化量の計算は" );
  CERR( "- 階差数列や累積和やBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "- イベントソート" );
  CERR( "を検討しましょう。" );
}

AC( Decision )
{
  ASK_NUMBER(
	     "0次連結性問題" ,
	     "高次連結性問題" ,
	     "必勝性問題" ,
	     "到達可能性問題" ,
	     "充足可能性問題" ,
	     "一致判定問題" ,
	     "表記可能性問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionHigherConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionSatisfiability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionCoincidence );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  }
}

AC( DecisionConnectedness )
{
  CERR( "幅優先探索やUnionFind" );
  CERR( "\\Mathematics\\Geometry\\Graph\\BreadthFirst" );
  CERR( "\\Utility\\VLTree\\UnionFindForest" );
  CERR( "を検討しましょう。" );
  CERR( "" );
}

AC( DecisionHigherConnectedness )
{
  CERR( "- 強連結性判定は深さ優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\DepthFirst" );
  CERR( "- 高次ホモロジー計算は適当な法での掃き出し法" );
  CERR( "を検討しましょう。" );
}

AC( DecisionGame )
{
  CERR( "ゲームの和に分解できる場合は最小単位で考察をし、グランディ数を実装しましょう。" );
  CERR( "これ以上分解できないゲームには整礎構造を探し、順序数の小さい順に実験をしましょう。" );
  ASK_NUMBER(
	     "操作の継続を目指すゲーム" ,
	     "得点の大小を競うゲーム"
	     );
  if( num == num_temp++ ){
    CERR( "必勝戦略の構築では" );
    CERR( "- 敗北状態を回避するための、何らかの不変量を保つ戦略" );
    CERR( "- 手詰まりを回避するための、を何らかの二部マッチングを実現する戦略" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "２プレイヤーの得点差を１つの点数とみなし、その最大化を行いましょう。" );
    CALL_AC( ConstructionMaximisation );
  }
}

AC( DecisionAccessibility )
{
  CERR( "移動の前後で変化しない値がある場合、その値が等しい点に絞って考えましょう。" );
  ASK_NUMBER(
	     "矩形領域の到達可能性（迷路）問題" ,
	     "グラフ上の到達可能性問題" ,
	     "全点網羅可能性問題"
	     );
  if( num == num_temp++ ){
    CERR( "迷路の攻略可能性は" );
    CERR( "- スタートとゴールが同一の弧状連結成分に属すこと" );
    CERR( "- スタートとゴールを分断する壁のパスの非存在性" );
    CERR( "などに翻訳しグラフ上の最小コスト移動問題に帰着させましょう。" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "グラフ上の最小コスト移動問題に帰着させましょう。" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "移動の前後で変化しない値がある場合、その値が等しい点に絞って考えましょう。" );
    CERR( "- 領域と移動に対称性があるならば、タイリングとマッチング" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\HopcroftKarp" );
    CERR( "- O(N^3)が通りそうで再来訪を許容するならば、ワーシャルフロイド法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\FloydWarshall" );
    CERR( "を検討しましょう。" );
  }
  CERR( "" );
}

AC( DecisionSatisfiability )
{
  ASK_NUMBER(
	     "命題論理の充足性判定問題" ,
	     "二部グラフの充足可能性問題"
	     );
  if( num == num_temp++ ){
    CERR( "各命題変数の真理値を頂点とするグラフを考え連結性判定に帰着させて" );
    CALL_AC( DecisionConnectedness );
    CERR( "" );
    CERR( "区間処理による真理値更新は各種代数的データ構造を用いましょう。" );
    AC( QueryArray );
  } else if( num == num_temp++ ){
    CERR( "完全二部マッチング判定は最大二部マッチングに帰着させて" );
    AC( MaximisationBipartiteMatching );
  }
}

AC( DecisionCoincidence )
{
  CERR( "- 文字列の一致判定はローリングハッシュ" );
  CERR( "  \\Utility\\String\\RollingHash" );
  CERR( "- 部分文字列との一致判定はZアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- 集合の一致判定はゾブリストハッシュ" );
  CERR( "  \\Utility\\Set\\ZobristHash" );
  CERR( "- 多重集合の一致判定は重複度とpairにして集合の一致判定に帰着" );
  CERR( "- 配列の並び換えによる一致判定は" );
  CERR( "  - 各前処理O(長さlog長さ)が間に合いそうならばソートからの文字列一致判定に帰着" );
  CERR( "  - 各前処理O(長さlog文字種類数)が間に合いそうならば多重集合の一致判定に帰着" );
  CERR( "を検討しましょう。" );
}

AC( DecisionPresentability )
{
  CERR( "数／文字列を使って特定の数や文字を表現できるかの判定は" );
  CERR( "- 左結合的に関数／演算を処理する場合は" );
  CERR( "  「第i成分／文字までで打ち切った時に表現できるもの全体の集合dp[i]」" );
  CERR( "  を管理するiに関する動的計画法" );
  CERR( "- 関数／演算の適用方法にも選択がある場合は2項を選んで適用させた" );
  CERR( "  結果得られる数／文字列の再帰的な全探策" );
  CERR( "を検討しましょう。" );
}

AC( Construction )
{
  CERR( "存在定理に帰着できる問題は構成的証明を実装しましょう。" );
  CERR( "リアクティブ問題で質問をする際は" );
  CERR( "- 何らかの順序における極大元に触れる聞き方" );
  CERR( "- なるべく多くの数値に依存する情報に触れる聞き方" );
  CERR( "- N^2個の数値に対するO(N)回の質問では対角線に触れる聞き方" );
  CERR( "を検討しましょう。" );
  ASK_NUMBER(
	     "数や配列や文字列の構築" ,
	     "経路の構築" ,
	     "必勝戦略の構築" ,
	     "最大化戦略の構築" ,
	     "表現可能性の判定" ,
	     "ソースコードの構築"
	     );
  if( num == num_temp++ ){
    CERR( "p進法や階差数列を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "可能な経路の定めるグラフの問題に帰着させましょう。" );
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CERR( "ゲームの問題に帰着させましょう。" );
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMaximisation );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else if( num == num_temp++ ){
    CERR( "正解を出力をするソースコードを提出しましょう。" );
  }
}

AC( ConstructionMaximisation )
{
  CERR( "点数の最大化のためには、戦略の整礎な変形手順であって点数を落さないものを探し" );
  CERR( "その変形を完全に行って得られる戦略のみに絞って考えましょう。" );
}
