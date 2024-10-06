// c:/Users/user/Documents/Programming/Contest/AutoCheck/LibrarySearch/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

#include "../SampleAnalyser/a_Body.hpp"

AC( LibrarySearch )
{
  ASK_NUMBER(
	     "明示式の計算問題" ,
	     "最大／最小化問題" ,
	     "数え上げ問題" ,
	     "求解問題" ,
	     "クエリ処理問題" ,
	     "ゲーム問題" ,
	     "真偽判定問題" ,
	     "構築問題" ,
	     "推定問題"
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
    CALL_AC( Game );
  } else if( num == num_temp++ ){
    CALL_AC( Decision );
  } else if( num == num_temp++ ){
    CALL_AC( Construction );
  } else if( num == num_temp++ ){
    CALL_AC( Deduction );
  }
  CERR( "" );
  CERR( "ライブラリー探索は以上です。終了します。" );
}

AC( ExplicitExpression )
{
  ASK_NUMBER(
	     "１変数関数／数列の計算問題" ,
	     "配列を用いた関数の総和の計算問題" ,
	     "二重和や二重積などの計算問題" ,
	     "順列上の関数の計算問題" ,
	     "木上の関数の総和の計算問題" ,
	     "木以外のグラフ上の関数の計算問題" ,
	     "序数の計算問題" ,
	     "確率／期待値の計算問題" ,
	     "操作回数の計算問題" ,
	     "始／終切片和や畳み込みの計算問題" ,
	     "面積の計算問題" ,
	     "極限の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionUnary );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArraySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionDoubleSum );
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
    CALL_AC( ExplicitExpressionConvolution );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArea );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionLimit );
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
  CERR( "  \\Mathematics\\Polynomial\\Truncate" );
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
	     "１つの配列の成分を受け取る関数の総和の計算問題" ,
	     "２つの配列の内積の計算問題" ,
	     "１つの配列の部分列を受け取る関数の総和の計算問題" ,
	     "配列を受け取る関数の配列をわたる総和の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOneArrayEntrySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionInnerProduct );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionOneArraySubArraySum );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionArrayCombinatorial );
  }
}

AC( ExplicitExpressionOneArrayEntrySum )
{
  CERR( "1変数関数f(x)と配列(a_i)_{i=0}^{N-1}に対するsum_i f(a_i)などを考える" );
  CERR( "とします。必要ならば(a_i)_iをソートして広義単調増大とします。" );
  CERR( "- f(a_{i+1}) - f(a_i)がO(1)で計算できO(N)が間に合いそうならば、" );
  CERR( "  f(a_i)の差分計算による高速化" );
  CERR( "- f(a_i)がiに関する等比数列K個の和で表せO(K log N)が間に合いそうならば" );
  CERR( "  等比数列の総和の公式" );
  CERR( "  \\Mathematics\\Arithmetic\\Power\\GeometricProgression" );
  CERR( "- f(a_i)がK次正方行列AとK次元ベクトルvを用いて(A^i v)[0]と表せ" );
  CERR( "  - A-Eが正則でO(K^3 log N)が間に合いそうならば、等比数列の総和の公式" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "    \\Mathematics\\Arithmetic\\Power\\GeometricProgression" );
  CERR( "  - A-Eが正則とは限らずO(K^3 log N)が間に合いそうならば、vにf(a_i)の" );
  CERR( "    累積和を末尾挿入し、行列累乗" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "- #im(f)が小さくf(a_)の各点逆像が計算しやすいならば" );
  CERR( "  fの各点逆像による纏め上げ" );
  CERR( "  sum_i f(a_i)=sum_y #f(a_)^{-1}(y) y" );
  CERR( "- #im(f)が小さくfが非負でf(a_)の始切片逆像が計算しやすいならば" );
  CERR( "  fの始切片逆像による纏め上げ" );
  CERR( "  sum_i f(a_i)=sum_{y>=1} #f(a_)^{-1}([y,∞))" );
  CERR( "- #dom(f)が小さく(a_)の逆像が計算しやすいならば" );
  CERR( "  (a_)の各点逆像による纏め上げ" );
  CERR( "  sum_i f(a_i)=sum_x #(a_)^{-1}(x) f(x)" );
  CERR( "- i%j = i - floor(i/j)jを用いて剰余を商に帰着" );
  CERR( "  - iに関する和はfloor_sum" );
  CERR( "    \\Mathematics\\Combinatorial\\FloorSum" );
  CERR( "  - jに関する和は平方分割" );
  CERR( "    \\Mathematics\\Combinatorial\\ResidueSum" );
  CERR( "- Nが大きい場合と小さい場合で解法の折衷" );
  CERR( "を検討しましょう。" );
  CERR( "" );
}

AC( ExplicitExpressionInnerProduct )
{
  CERR( "数列(a_i)_iと(b_i)_iが与えられるとします。" );
  CERR( "f(X) = sum_{i=0}^{N-1} a_i X^i" );
  CERR( "g(X) = sum_{i=0}^{N-1} b_{N-i-1} X^i" );
  CERR( "と置きます。" );
  ASK_NUMBER(
             "(sum_{i=0}^{N-i-j} a_i b_{i+j})_{j=0}^{N-1}の計算"
             "(sum_{i=0}^{N-1} a_i b_{i+j})_{j=0}^{N-1}の計算"
             );
  if( num == num_temp++ ){
    CERR( "f(X)g(X)mod X^N = sum_{i=0}^{N-1} c_i X^i" );
    CERR( "と置くと" );
    CERR( "(c_{N-1-j})_{j=0}^{N-1}" );
    CERR( "が答えです。" );
  } else if( num == num_temp++ ){
    CERR( "f(X)g(X) = sum_{i=0}^{2N-2} c_i X^i" );
    CERR( "と置くと" );
    CERR( "(sum_{k \equiv -1-j mod N}c_k)_{j=0}^{N-1}" );
    CERR( "が答えです。" );
  }
  CERR( "\\Mathematics\\Polynoial\\Truncate" );
}

AC( ExplicitExpressionOneArraySubArraySum )
{
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
}

AC( ExplicitExpressionArrayCombinatorial )
{
  CERR( "長さNの配列の有限集合Sと、Sを定義域に持つ関数fが与えられているとして、" );
  CERR( "sum_{A in S} f(A)を求めます。" );
  CERR( "- 任意のA in Sに対し" );
  CERR( "  f(A) = sum_{i=0}^{N-1} g(A,i)" );
  CERR( "  を満たす関数gが存在するならば、" );
  CERR( "  sum_{A in S} f(A) = sum_{A in S} sum_{i=0}^{N-1} g(A,i)" );
  CERR( "                    = sum_{i=0}^{N-1} sum_{A in S} g(A,i)" );
  CERR( "  によりg(-,i)の逆像の数え上げ問題に帰着" );
  CERR( "- 任意のA in Sに対し" );
  CERR( "  f(A) = #{i in [0,N)|P(A,i)} " );
  CERR( "  を満たす関係Pが存在するならば、Pの特性関数をgと置けば任意のA in Sに対し" );
  CERR( "  f(A) = sum_{i=0}^{N-1} g(A,i)" );
  CERR( "  が成り立つので上の場合に帰着" );
  CERR( "- 任意のA in Sに対し" );
  CERR( "  f(A) = prod_{i=0}^{N-1} g(A,i)" );
  CERR( "  を満たす関数gが存在するならば、積の和典型などの組み合わせ論的解釈" );
  CERR( "  https://ei1333.hateblo.jp/entry/2021/07/30/144201" );
  CERR( "  https://ladywingclover.hatenablog.com/entry/2022/11/24/084524" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionDoubleSum )
{
  CERR( "2変数関数f(x,y)と配列(a_i)_{i=0}^{N-1}, (b_j)_{j=0}^{M-1}に対する" );
  CERR( "二重和sum_i sum_j f(a_i,b_j)などを考えるとします。" );
  CERR( "必要ならば(a_i)_iと(b_j)をソートしてともに広義単調増大とします。" );
  CERR( "- sum_i f(a_i,b_j)の計算量をO(g(N))としてO(g(N)M)が間に合いそうならば、" );
  CERR( "  和の順序交換sum_i sum_j f(a_i,b_j) = sum_j sum_i f(a_i,b_j)" );
  CERR( "- sum_j (f(a_i,b_{j+1}) - f(a_i,b_j))の計算量をO(g(N))としてO(g(N)M)が" );
  CERR( "  間に合いそうならば、sum_j f(a_i,b_j)の差分計算による高速化" );
  CERR( "- f(x,y)=sum_k g_k(x) h_k(y)と表示できO(K(N+M))が間に合いそうならば" );
  CERR( "  変数分離sum_{i,j} f(a_i,b_j)=sum_k(sum_i g_k(a_i))(sum_j h_k(b_j))" );
  CERR( "- #im(f)が小さくf(a_,b_)の各点逆像が計算しやすいならば" );
  CERR( "  fの各点逆像による纏め上げ" );
  CERR( "  sum_{i,j} f(a_i,b_j)=sum_z #f(a_,b_)^{-1}(z) z" );
  CERR( "- #im(f)が小さくfが非負でf(a_,b_)の始切片逆像が計算しやすいならば" );
  CERR( "  fの始切片逆像による纏め上げ" );
  CERR( "  sum_{i,j} f(a_i,b_j)=sum_{z>0} #f(a_,b_)^{-1}([z,∞))" );
  CERR( "- #dom(f)が小さく(a_,b_)の各点逆像が計算しやすいならば" );
  CERR( "  (a_,b_)の各点逆像による纏め上げ" );
  CERR( "  sum_{i,j} f(a_i,b_j)=sum_v #(a_,b_)^{-1}(v) f(v)" );
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
  ASK_NUMBER(
	     "木を受け取る関数の計算問題" ,
	     "木上の関数の総和の計算問題" ,
	     "構文木の計算問題"
	     );
  if( num == num_temp++ ){
    CERR( "木を受け取る関数fが与えられているとします。" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "- 各ノード（またはその近傍）の寄与に分解できる時はノードごとの計算" );
    CERR( "- 部分木に関する良い遷移関係があれば（全方位）木DP" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch\\Tree" );
    CERR( "を検討しましょう。" );
    ASK_YES_NO( "fがbit演算の多引数化である問題ですか？" );
    if( reply == "y" ){
      CALL_AC( ExplicitExpressionBitFunctionOnTree );
    }
  } else if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CERR( "構文解析は言語の再帰式に沿って再帰関数で実装しましょう。" );
    CERR( "例えば式Sを左から順に読み、" );
    CERR( "Expression(S,読んでいる位置i,式番号v,構文木T)を" );
    CERR( "「S[i]を演算子または始端とする式eに番号vを振り、" );
    CERR( " Tにeの部分式の式番号へ有向辺を張り、iとvを増やす」" );
    CERR( "という処理を式の再帰式に従っていくつかの関数に分けて" );
    CERR( "再帰すると良いです。" );
    CERR( "https://qiita.com/kazuki_tamaribuchi/items/77a4b4e6214646a079ed" );
    CERR( "" );
    CERR( "構文木に沿った計算は、演算を１つ以外の引数を固定した１変数関数とみなし" );
    CERR( "合成として処理し、分割統治とcompress+rakeを組み合わせてO(N(log N)^3)で" );
    CERR( "処理することを検討しましょう。" );
    CERR( "https://en.wikipedia.org/wiki/Tree_contraction#Expression_Evaluation" );
    CERR( "https://yukicoder.me/submissions/940108" );
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
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "  - 重みが「単位元が最小元であるmeet半束モノイド」に値を持ち" );
  CERR( "    O(V^3)が間に合いそうならばワーシャルフロイド法" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
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
      CALL_AC( ExplicitExpressionOrderOfElement );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionRandomAccess );
    } else if( num == num_temp++ ){
      CALL_AC( ExplicitExpressionTotalAccess );
    }
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  }
}

AC( ExplicitExpressionOrderOfElement )
{
  ASK_YES_NO( "各iごとにa[i]が高速に求められる問題ですか？" );
  if( reply == "y" ){
    CERR( "iに関する二分探索を検討しましょう。" );
  } else {
    CERR( "s未満のSの項の数え上げを検討しましょう。" );
    CALL_AC( CountingArrayBoundedTotal );
    ASK_YES_NO( "Sが固定長変数関数の像で与えられますか？" );
    if( reply == "y" ){
      CERR( "固定長変数関数の逆像の数え上げ問題は、" );
      CALL_AC( CountingExplicitExpression );
    }
  }
}

AC( ExplicitExpressionRandomAccess )
{
  CERR( "Sの各要素sごとにs未満のSの項を数え上げ問題を考えて、" );
  CERR( "sに関する二分探索を検討しましょう。" );
  CALL_AC( CountingArrayBoundedTotal );
  ASK_YES_NO( "Sが固定長変数関数の像で与えられますか？" );
  if( reply == "y" ){
    CERR( "固定長変数関数の逆像の数え上げ問題は、" );
    CALL_AC( CountingExplicitExpression );
  }
}

AC( ExplicitExpressionTotalAccess )
{
  CERR( "- 各iごとにa[i]が高速に求められるならば、a[i]以下のSの要素の全列挙" );
  CERR( "- Sが多重集合M個の和集合であるならば、各多重集合をソートしてM個のpriority_queueでイベントソート" );
}

AC( ExplicitExpressionProbability )
{
  CERR( "- 確率計算は" );
  CERR( "  - 事象を全探策してそれぞれの確率を計算" );;
  CERR( "  - 余事象や包除原理（高速ゼータ変換／メビウス変換）" );
  CERR( "    \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "  - 対象を独立変数の積で表して乗法性" );
  CERR( "    - グリッドのマスなどの直積集合の要素が矩形領域に属すか否かの確率は" );
  CERR( "      成分ごとの確率の積に帰着" );
  CERR( "  - 同様に確からしい事象の特定" );
  CERR( "  - ベイズの定理" );
  CERR( "- 期待値計算は" );
  CERR( "  - 確率を用いた愚直な計算" );
  CERR( "  - 対象を和で表して線形性" );
  CERR( "    - 転倒数やグリッドの黒マスの個数など部分集合の要素数の期待値は" );
  CERR( "      各要素が部分集合に属す確率の和に帰着" );
  CERR( "    - 単位時間に高々1回起こる事象の起きた回数は、各時刻tごとに" );
  CERR( "      +1の起こる確率p(t)の総和" );
  CERR( "    - 裏が出るまでのコイン投げ回数ならn回以上表が出る確率p(n)の総和" );
  CERR( "  - 操作／遷移回数なら期待値間の関係式を求め行列累乗やボスタン森法" );
  CERR( "    \\Mathematics\\LinearAlgebra" );
  CERR( "    \\Mathematics\\Polynomial\\BostanMori" );
  CERR( "  - グリッドの塗り潰しならベルヌーイ数前計算による冪乗関数の総和を用いた明示式" );
  CERR( "    \\Mathematics\\Polynomial\\Cumulative\\GridStampCoveringExpectation" );
  CERR( "を検討しましょう。" );
}

AC( ExplicitExpressionCountingOperation )
{
  CALL_AC( ReducingOperation );
  CERR( "その上で選択の余地のない操作回数を求める際は、" );
  CERR( "- 操作列をイベントとみなし時系列に並べ、「一斉に処理できる区間」いくつか" );
  CERR( "  に分割し、それぞれの区間での処理をまとめて計算" );
  CERR( "- 操作対象が操作優先度つきで複数ある場合は、各操作対象の操作回数に関する動的計画法" );
  CERR( "- 操作がいくつかの対象群に同時に行われるならば、各対象群ごとに回数計算" );
  CERR( "- 操作が辺の削除ならば、逆向きに処理して各連結成分ごとに操作回数を記録" );
  CERR( "を検討しましょう。" );
}

AC( ReducingOperation )
{
  CERR( "操作対象を何らかの不変量で分類し、操作を不変量間の遷移とみなすことで" );
  CERR( "なるべく簡単な問題に帰着させましょう。" );
  CERR( "- 操作で階差数列の奇数成分が減るならば、その総和に注目" );
  CERR( "- 操作で累積和の最大値と最小値の差が減るならば、その差に注目" );
  CERR( "- 操作で隣接成分との大小が変わるならば、その大小関係を管理する01列に注目" );
}

AC( ExplicitExpressionConvolution )
{
  ASK_NUMBER(
	     "多項式に関する計算" ,
	     "cup/capに関する計算"
	     "gcd/lcmに関する計算"
	     "その他のjoin半束上の計算"
	     );
  if( num == num_temp++ ){
    CERR( "- 次数の大きな多項式と小さな多項式の積は愚直乗算" );
    CERR( "  Mathematics\\Polynomial\\a.hpp" );
    CERR( "- 通常の積は高速フーリエ変換と中国剰余定理" );
    CERR( "  Mathematics\\Polynomial\\Truncate" );
    CERR( "- 冪乗の積は高速フーリエ変換とexpとlog" );
    CERR( "  Mathematics\\Polynomial\\Truncate" );
    CERR( "- f mod gの逆元計算は" );
    CERR( "  - deg(g)が小さいならば拡張ユークリッドの互助法" );
    CERR( "    Mathematics\\Polynomial\\Mod" );
    CERR( "  - deg(f)が小さいならば1から(g mod f)^{-1}の代表元とg%fの積を引いて" );
    CERR( "    得られるfの倍元をfで割った商" );
    CERR( "- f/gの係数計算はボスタン森法" );
    CERR( "  Mathematics\\Polynomial\\BostanMori" );
  } else if( num == num_temp++ ){
    CERR( "- 部分集合の各部分集合を渡る総和は高速ゼータ変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- 関数値が要素数に依存する場合の畳み込みは高速ゼータ変換／高速メビウス変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- 関数値が要素数に依存しない場合の畳み込みはマーラー変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\MahlerTransform" );
  } else if( num == num_temp++ ){
    CERR( "- Nの各約数を渡る総和は約数列挙で総和計算" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
    CERR( "- [1,N]上の関数の畳み込みは約数ゼータ変換／約数メビウス変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform\\Divisor" );
    CERR( "- Nの約数上の関数の畳み込みはNを素因数分解した上で約数ゼータ変換の" );
    CERR( "  N/無閉包数での値のみを式変形で計算し各点乗算をして" );
    CERR( "  無閉包数の素因数の個数を使ったメビウス関数で高速メビウス変換の計算" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\Divisor" );
  } else if( num == num_temp++ ){
    CERR( "- 要素sの終切片での総和は隣接代数上のゼータ変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
    CERR( "- joinに関する畳み込みは隣接代数上のゼータ変換／メビウス変換" );
    CERR( "  Mathematics\\Combinatorial\\ZetaTransform" );
  }
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "複数回の乗算は分割統治" );
  CERR( "Mathematics\\Arithmetic\\a.hpp" );
  CERR( "を検討しましょう。" );
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

AC( ExplicitExpressionLimit )
{
  CERR( "- lim_{T->infty} \frac{1}{T} sum_{t=1}^{T} a_tの形の計算は" );
  CERR( "  - a_tが収束するならばその値の計算" );
  CERR( "  - a_tが収束しないが周期的ならば周期をPとして" );
  CERR( "    lim_{T->infty} \frac{1}{P} sum_{t=T+1}^{T+P} a_tの計算" );
  CERR( "    - 周期が短い場合は実際にシミュレーションにより計算" );
  CERR( "    - 鳩の巣原理などで周期的であることは分かってもその具体的な振る舞いが" );
  CERR( "      分からない場合は小さいケースで実験" );
  CERR( "- lim_{N->infty} \frac{1}{N} sum_{i=1}^{N} f(i/N)の形の計算は" );
  CERR( "  区分求積法" );
  CERR( "  - 法P計算ならば微積分学の基本定理を用いて原始関数の計算に帰着" );
  CERR( "  - 誤差問題ならばモンテカルロ法を用いて近似計算" );
  CERR( "を検討しましょう。" );
}

AC( Maximisation )
{
  ASK_NUMBER(
	     "移動コストの最小化問題" ,
	     "移動長の最大化問題" ,
	     "ナップサック問題" ,
	     "配列上の関数に関する最大／最小化問題" ,
	     "配列の隣接成分間関係式を満たす部分列の最長化問題" ,
	     "低次元アフィン空間上の関数の最大／最小化問題" ,
	     "集合の部分集合に関する最大／最小化問題" ,
	     "グラフの経路に関する最大／最小化問題" ,
	     "木上の関数に関する最大／最小化問題" ,
	     "文字列のマッチングに関する最大／最長化問題" ,
	     "確率／期待値の最大化問題" ,
	     "操作コストの最小化問題" ,
	     "操作回数の最大化問題" ,
	     "被覆半径の最小化問題" ,
	     "描画サイズ／個数の最大／最小化問題" ,
	     "最小値の最大化問題" ,
	     "部分和の最小化問題" ,
	     "2人ゲームの最終的な不変量の最大／最小化問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMovingDistance );
  } else if( num == num_temp++ ){
    CALL_AC( Knapsack );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnArray );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationArrayLength );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnAffineSpace );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationSubsetSize );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationGraph );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationFunctionOnTree );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationStringMatching );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationProbability );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationOperationCost );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationCountingOperation );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationCoveringSize );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationDrawingImage );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationMinimum );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSubsetSum );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationGame );
  }
}

AC( MinimisationMovingCost )
{
  CERR( "マルチクエリの場合は、個々のクエリ単位で次の質問に答えてください。" );
  ASK_NUMBER(
	     "１始点多終点コスト最小化（迷路）問題" ,
	     "１始点多中間点１終点コスト最小化（二段階迷路）問題" ,
	     "１始点多経由点多終点コスト最小化（スタンプラリー）問題" ,
	     "多始点１終点コスト最小化（競争）問題" ,
	     "多始点多終点コスト最大値最小化（開被覆）問題" ,
	     "多プレイヤーコスト総和最小化（最小費用流）問題" ,
	     "最近接点問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CERR( "始点から各中間点への最短経路問題と、終点から各中間点への最短径路問題" );
    CERR( "を解くことで１始点多終点コスト最小化（迷路）問題に帰着されます。" );
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CERR( "- 経由点の経由順序が指定されているならば、グラフの線形グラフに対する" );
    CERR( "  分割統治ダイクストラ法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double\\Errand" );
    CERR( "- 経由点の経由順序が指定されておらずかつ経由点が頂点全体ならば、HeldKarp法" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "- 最短経路の始点の特定が不要ならば、始点を１つ追加して元の始点へコスト0の" );
    CERR( "  有向辺を追加" );
    CERR( "- 最短経路の始点の特定が必要ならば、辺を反転" );
    CERR( "により１始点多終点コスト最小コスト化（迷路）問題に帰着されます。" );
    CALL_AC( MinimisationSolvingMaze );
  } else if( num == num_temp++ ){
    CALL_AC( MinimisationSolvingOpenCovering );
  } else if( num == num_temp++ ){
    CERR( "各終点tjをゴールとして良い人数の上限をNjと置いて" );
    CERR( "- 各辺の容量を∞に設定" );
    CERR( "- 各始点siへ容量1コスト0の辺を持つ頂点Sを追加" );
    CERR( "- 各終点tjから容量Njコスト0の辺を持つ頂点Tを追加" );
    CERR( "とすることで得られる有無向グラフに対しPrimal-Dual法を適用しましょう。" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Potentialised\\MinimumCostFlow" );
  } else if( num == num_temp++ ){
    CERR( "D次元ユークリッド空間内のN点を考えます。" );
    CERR( "- L^p距離に関する最近点対問題でかつO(N log N)が間に合いそうならば" );
    CERR( "  空間を２分する分割統治でマージ時に枝刈り" );
    CERR( "  https://people.csail.mit.edu/indyk/6.838-old/handouts/lec17.pdf" );
    CERR( "- D=1で１点から点群への距離の最小化問題でかつO(log N)が間に合いそうならば" );
    CERR( "  set上の２分探索" );
    CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance" );
    CERR( "- D=1で点群から点群への距離の最小化問題でかつO(N log N)が間に合いそうならば" );
    CERR( "  ソートして左右から踏査" );
    CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance" );
    CERR( "- D=2でx軸上の点群から点群へのL^1距離の最小化問題でかつO(N log N)が" );
    CERR( "  間に合いそうならばx座標でソートして左右から累積min計算" );
    CERR( "  \\Mathematics\\Geometry\\AffineSpace\\Distance\\Li" );
    CERR( "- ハイブリッド距離ならば距離の変化点で場合分けをして、それぞれに対する" );
    CERR( "  最小化問題に帰着" );
    CERR( "- グラフにより与えられる距離で経路上に（N点の外にあるかもしれない）経由点群" );
    CERR( "  が存在するならば経由点群からの距離の最小化問題に帰着" );
    CERR( "を検討しましょう。" );
  }
  CERR( "" );
  CERR( "点の座標と最小化すべきコスト以外の数値xに変化がある場合、最小コスト移動に" );
  CERR( "おいてxの動く範囲を絞って点の座標とxの組を頂点とするグラフを考えましょう。" );
  CERR( "" );
  CERR( "重みが辺ではなく頂点についている場合" );
  CERR( "- 羃等モノイドならば特に頂点は追加せず" );
  CERR( "- 羃等でない可換モノイドならば重みが単位元である始点と終点を追加して" );
  CERR( "各辺の重みを両端の重みに演算を適用したもので定義しましょう。" );
}

AC( MinimisationSolvingMaze )
{
  ASK_YES_NO( "特定の辺群の合計使用回数に制限がありますか？" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeBoundedChoice );
  } else {
    ASK_YES_NO( "|E|が10^8オーダーで抑えられますか？" );
    if( reply == "y" ){
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
    } else {
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceManyEdges );
    }
  }
}

AC( MinimisationSolvingMazeBoundedChoice )
{
  CERR( "合計使用回数に制限のない辺たちをE_0、制限のある辺たちをE_1、" );
  CERR( "使用回数の上限をCと置きます。" );
  ASK_YES_NO( "|E_0|*(C+1)+|E_1|*Cが10^8オーダーで抑えられますか？" );
  if( reply == "y" ){
    CERR( "使用回数ごとに頂点を複製して、|V|頂点|E_0|辺の無向グラフ|C+1|個の" );
    CERR( "非輪状グラフを構成することで、合計使用回数制限のない問題に帰着できます。" );
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
  } else {
    ASK_YES_NO( "C=1かつ一終点ですか？" );
    if( reply == "y" ){
      CERR( "(V,E_0)に対し始点と終点からの一始点多終点最短経路問題を解き、" );
      CERR( "各2点間をE_1で結んだ時の最短経路を2重ループやそのデータ構造高速化で" );
      CERR( "計算することで合計使用回数制限のない問題に帰着できます。" );
      CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdges );
    } else {
      CERR( "(V,E_0)に対し多始点多終点最短経路問題を解き、各2点間を１回だけE_1で" );
      CERR( "結んだ時の最短経路を2重ループやそのデータ構造高速化で計算します。" );
      CERR( "その後、その結果をMinTropicalSemirng上の|V|次正方行列に格納し、" );
      CERR( "0乗からC乗までの総minをO(V^3 C)で計算することで" );
      CERR( "合計使用回数制限のない問題に帰着できます。" );
      CALL_AC( MinimisationSolvingOpenCovering );
    }
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdges )
{
  ASK_YES_NO( "演算は羃等的ですか？" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesIdempotent );
  } else {
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotent );
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesIdempotent )
{
  CERR( "コスト上限をCと置きます。" );
  ASK_YES_NO( "マルチクエリですか？" );
  if( reply == "y" ){
    CERR( "クエリ回数をQと置きます。" );
    CERR( "- O(E log_2 E + (V + (E + Q)α(V) + min(C,Q log_2 Q))log_2 E)" );
    CERR( "  が間に合いそうならばコストで辺をソートしてUnionFind並列二分探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind\\ParallelBinarySearch" );
    CERR( "- そうでなく始点が共通ならば、シングルクエリの解法で多終点並列計算" );
    CERR( "- そうでないならば、シングルクエリの解法をQ回反復" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "以下、シングルクエリの解法を説明します。" );
  }
  CERR( "- O(min(V^2,(V+E)log_2 E))が間に合いそうならばダイクストラ法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "- O((V+E)C)が間に合いそうならばコスト最大値も状態に含めたグラフ上での" );
  CERR( "  幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearchSearch" );
  CERR( "- O(V + E(log E + α(V)))が間に合いそうならば" );
  CERR( "  コストで辺をソートしてUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind" );
  CERR( "- O(V + Eα(V + log_2 E)))が間に合いそうならば" );
  CERR( "  クラスカル法で最小全域木まで辺を削減してBFS/DFS＋経路復元" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFind\\Kruscal" );
  CERR( "- Gがグラフの非輪状グラフならば" );
  CERR( "  - O(min(sum_i V_i^2,sum_i((V_i+E_i)log_2 E_i))が間に合いそうならば" );
  CERR( "    分割統治ダイクストラ法" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double" );
  CERR( "  - 間に合わなさそうならば分割統治を動的計画法で書き直しデータ構造高速化" );
  CERR( "- 辺のコストのうちK番目に大きい値の最小化でO((V+E)log C)が間に合いそう" );
  CERR( "  ならば、コストcを決め打って辺の新たな重みとして「コストがcより大きい」の" );
  CERR( "  真偽を考えて01幅優先探索を行い、経路の重みの総和の最小値がK未満である" );
  CERR( "  ようなcの最小値を二分探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BFS\\01" );
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotent )
{
  ASK_YES_NO( "コストは負になりえますか？" );
  if( reply == "y" ){
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNegative );
  } else {
    CALL_AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNonNegative );
  }
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNegative )
{
  CERR( "- O(VE)が間に合いそうならば、ベルマンフォード法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BellmanFord" );
  CERR( "- マルチクエリで辺の削除を行いO(VE+Q(V+E)log_2 E)が間に合いそうならば" );
  CERR( "  ベルマンフォード法によるポテンシャル前計算＋ポテンシャル付きダイクストラ法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Potentialised\\BellmanFord" );
}

AC( MinimisationSolvingMazeUnboundedChoiceFewEdgesNonIdempotentNonNegative )
{
  ASK_YES_NO( "マルチクエリですか？" );
  if( reply == "y" ){
    CERR( "クエリ回数をQと置きます。" );
    CERR( "- O(V^3 + Q)が間に合いそうならばワーシャルフロイド法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
    CERR( "- そうでなく始点が共通ならば、シングルクエリの解法で多終点並列計算" );
    CERR( "- そうでないならば、シングルクエリの解法をQ回反復" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "以下、シングルクエリの解法を説明します。" );
  }
  CERR( "- コストが1のみかつO(V+E)が通りそうならば、幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- そうでなくコストが{0,1}値かつO(V+E)が通りそうならば、01幅優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\ZeroOne" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "- そうでないならばコスト総和上限をCとし、" );
  CERR( "  - O(min(V^2,(V+E)log_2 E))が間に合いそうならばダイクストラ法" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "  - O((V+E)C)が間に合いそうならば、コスト総和も状態に含めたグラフ上" );
  CERR( "    での幅優先探索" );
  CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearchSearch" );
  CERR( "  - Gがグラフの非輪状グラフならば" );
  CERR( "    - O(min(sum_i V_i^2,sum_i((V_i+E_i)log_2 E_i))が間に合いそう" );
  CERR( "      ならば分割統治ダイクストラ法" );
  CERR( "      \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra\\Double" );
  CERR( "    - 間に合わなさそうならば、分割統治を動的計画法で書き直しデータ構造高速化" );
}

AC( MinimisationSolvingMazeUnboundedChoiceManyEdges )
{
  CERR( "配列の書き換え問題やLightsOut問題のようにEが非常に大きいならば、" );
  CERR( "各操作をデータ構造に翻訳することでシンプルな最小化問題に帰着させましょう。" );
  CERR( "- 区間加算ならば、階差数列の２点加算に翻訳" );
  CERR( "- 部分木の白黒反転ならば、木上の階差数列の１点更新に翻訳" );
  CERR( "- 無向グラフと非輪状有向グラフの合成ならば、有向グラフの有向辺に沿った" );
  CERR( "  動的計画法のデータ構造高速化" );
  CERR( "その上で、操作を" );
  CERR( "- 選択部分（どこを操作するか、など）" );
  CERR( "- 決定的遷移（選択部分を決めたら最小コストを実現するために" );
  CERR( "  自動的に決まる部分）" );
  CERR( "に分けて考えられないか検討し、選択部分の全探索や半分全列挙などを" );
  CERR( "検討しましょう。例えば各成分高々１回しか操作しないのが最適であれば、" );
  CERR( "どの成分を操作するかに対応する部分集合の探索問題となります。" );
  CERR( "" );
  CERR( "操作前後で不変な値（総和や白黒の個数差mod2など）があれば、" );
  CERR( "操作を何らかの零化問題に翻訳できるかもしれません。" );
  CERR( "なるべくコストを簡単で等価な値に翻訳し、その翻訳に則って操作も更に翻訳し、" );
  CERR( "よりシンプルな（例えば貪欲法が適用可能な）零化問題への帰着を試みましょう。" );
  CERR( "例えば経路を摂動する方法であってコストが大きくならないものを特定し、" );
  CERR( "摂動可能でない経路のみに絞ることでEを減らしましょう。" );
}

AC( MinimisationSolvingOpenCovering )
{
  ASK_YES_NO( "始点（被覆中心）が定まっているか、またはEが小さいですか？" );
  if( reply == "y" ){
    CERR( "- コストがなくO(V+E)が通りそうならば、多点幅優先探索か" );
    CERR( "  頂点を１つ追加し各始点に辺を張ったグラフ上での幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
    CERR( "- コストが0か1でO(V+E)が通りそうならば、多点01幅優先探索" );
    CERR( "  頂点を１つ追加し各始点に辺を張ったグラフ上での01幅優先探索" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\ZeroOne" );
    CERR( "- max演算を考えておりO(E(log_2 E + α(V)))が通りそうならば、" );
    CERR( "  重みで辺をソートして素集合データ構造" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
    CERR( "- O((V+E)log_2 E)が通りそうならば、" );
    CERR( "  頂点を１つ追加し各始点に辺を張ったグラフ上でのダイクストラ法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
    CERR( "- O(V^3)が通りそうならば、" );
    CERR( "  ワーシャルフロイド法" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\FloydWarshall" );
    CERR( "を検討しましょう。" );
  } else {
    CALL_AC( MinimisationSolvingOpenCoveringUnknownCentres );
  }
}

AC( MinimisationSolvingOpenCoveringUnknownCentres )
{
  CERR( "被覆半径Lを二分探索しましょう。例えば始点（被覆中心または被覆端点）の" );
  CERR( "候補を絞った上で始点を１つ固定してその始点から距離L以内の点を削除し、" );
  CERR( "残りの点群に対して再帰的に問題を解くことを検討しましょう。" );
}

AC( MaximisationMovingDistance )
{
  ASK_NUMBER(
	     "１始点多終点距離最長化（最遠点探索）問題" ,
	     "多始点多終点距離最長化（最長歩道探索）問題" ,
	     );
  if( num == num_temp++ ){
    CALL_AC( MaximisationMovingDistanceSingleStart );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "閉路を持たない有向グラフですか？" );
    if( reply == "y" ){
      CERR( "トポロジカルソートによる動的計画法" );
      CERR( "\\Mathematics\\Geometry\\Graph\\TopologicalSort" );
    } else {
      CERR( "始点を全探策することで、１始点多終点コスト最大化問題に帰着されます。" );
      CALL_AC( MaximisationMovingDistanceSingleStart );
    }
  }
  CERR( "を検討しましょう。" );
}

AC( MaximisationMovingDistanceSingleStart )
{
  CERR( "- コストが非正でO((V+E)log_2 E)が間に合いそうならば-1倍してダイクストラ法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\Dijkstra" );
  CERR( "- コストが正になりえてO(VE)が間に合いそうならば1倍してベルマンフォード法" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BellmanFord" );
  CERR( "- コストが1で無向グラフとして完全な有向グラフでO(V log V)が間に合いそうならば" );
  CERR( "  Vに関する再帰的構成" );
  CERR( "  https://yukicoder.me/submissions/916203" );
}

AC( MaximisationFunctionOnArray )
{
  ASK_NUMBER(
	     "問題文または入力で与えられる１つの配列に関する問題" ,
	     "条件を満たす任意の配列に関する問題"
	     );
  if( num == num_temp++ ){
    CERR( "ソートしても答えが変わらないならば適宜ソートしましょう。" );
    ASK_NUMBER(
	       "成分を受け取る関数の部分和の最大化問題" ,
	       "成分を受け取る関数の部分和と別の関数の補部分和の和の最大化問題" ,
	       "成分を受け取る関数の部分和と補部分和の差の最小化問題" ,
	       "0/1倍以外の配列の変更と配列を受け取る関数の合成の最大／最小化問題"
	       );
    if( num == num_temp++ ){
      CALL_AC( Knapsack );
    } else if( num == num_temp++ ){
      CERR( "関数をfとgとした時、" );
      CERR( "- fとgに代入する項数に制限がないならば、max(f(i),g(i))の総和" );
      CERR( "- fに代入する項数がKで固定ならば、f(i)-g(i)を大きい順にK個" );
      CERR( "  足したものとgの総和の和" );
      CERR( "が求める最大値です" );
    } else if( num == num_temp++ ){
      CERR( "部分和と総和の半分の差の最小化を行いましょう。" );
      CERR( "これは小さい方を考えることで上限付き部分和の最大化問題となります。" );
      CALL_AC( Knapsack );
    } else if( num == num_temp++ ){
      CALL_AC( MaximisationArrayFunction );
    }
  } else if( num == num_temp++ ){
    CERR( "- 取り得る値が少なく関数が長さに関して再帰的構造を持つ場合は、" );
    CERR( "  「長さiの時に可能な値全体または一部の集合dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- 「v以上の値を取り得るか否か」が判定可能である時は" );
    CERR( "  vに関する二分探索" );
    CERR( "- 「v以上の値を取り得るか否か」が判定可能である時は" );
    CERR( "  vに関する二分探索" );
    CERR( "を検討しましょう。" );
  }
}

AC( Knapsack )
{
  CERR( "総和を取る値を価値と呼ぶことにします。" );
  CERR( "配列の項数N、第i成分の価値A_i、価値の総和の上限Vとします。" );
  CERR( "{0,...,N-1}の部分集合または集合として含まれる多重集合Iであって、" );
  CERR( "- sum(i in I){A_i} = v" );
  CERR( "- その他の条件" );
  CERR( "を満たすものが存在するv <= Vの最大化を考えます。" );
  CERR( "" );
  CERR( "コストの総和上限Cとします。コストの半順序モノイドにおけるC以下の元" );
  CERR( "全体の集合の要素数を|C|と置きます。" );
  ASK_NUMBER(
	     "Iを始切片に限る場合" ,
	     "そうでなくIを区間に限る場合" ,
	     "そうでなくIの連結成分長に上限がある場合" ,
	     "そうでない場合"
	     );
  if( num == num_temp++ ){
    CALL_AC( KnapsackInitialSegment );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackInterval );
  } else if( num == num_temp++ ){
    CALL_AC( KnapsackBoundedIntervalLength );
  } else {
    ASK_YES_NO( "各項目が複数回選択できますか？" );
    if( reply == "y" ){
      CALL_AC( KnapsackMultipleChoice );
    } else {
      ASK_YES_NO( "何個目に選ばれたかによって項目のコストが変動しますか？" );
      if( reply == "y" ){
	CALL_AC( KnapsackOrdered );
      } else {
	ASK_YES_NO( "ナップサックは１つですか？" );
	if( reply == "y" ){
	  CALL_AC( SingleKnapsack );
	} else {
	  CALL_AC( MultipleKnapsack );
	}
      }
    }
  }
}

AC( KnapsackInitialSegment )
{
  CERR( "価値が非負ならば、先頭から何項選べるかだけが重要であるため" );
  CERR( "価値とコストの組を価値とみなし直すことでコストのないナップサック問題とみなせます。" );
  CERR( "価値(A_i)_iの部分和で表せない価値全体の集合が有限の上限Lを持つとします。" );
  ASK_YES_NO( "ナップサックは１つですか？" );
  if( reply == "y" ){
    CERR( "V>Lの場合はVが答えになるので場合分けでV<=Lの場合に帰着し、" );
    CERR( "後は愚直に求めるか式変形で解きましょう。" );
  } else {
    CERR( "ナップサックが２つであるとし、それらの価値上限をそれぞれV_1 <= V_2と置き、" );
    CERR( "必要ならばソートして(A_i)_iが昇順であるとし、各非負整数nに対し" );
    CERR( "s_n := sum_{i=0}^{n} A_i" );
    CERR( "と置き、A_n > 2Lを満たす最小のnをN_1と置き、s_n > V_1を満たす" );
    CERR( "最大のnをN_2と置き、A_n > V_1を満たす最大のnをN_3と置きます。" );
    CERR( "選択する項目全体の集合が始切片でなければならないならば、" );
    CERR( "- N_1 <= N_2ならばmax(V_1-s_n,s_{n+1}-V_1) > Lなのでn+1までの" );
    CERR( "  項目をうまく組み合わせてV_1が表せるため価値上限V = V_1 + V_2の" );
    CERR( "  場合に帰着" );
    CERR( "- N_1 > N_2ならば、N_3未満の各iに対し[0,i]までの選択可能性及び" );
    CERR( "  選択可能時のナップサック１のみの価値の最大値をV_1'とすると、" );
    CERR( "  N_3未満の制約を外してもV_1より大きい値はナップサック１に入らない" );
    CERR( "  ため価値上限V = V_1' + V_2の場合に帰着" );
    CERR( "を検討しましょう。" );
  }
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree\\InitialSegment" );
}

AC( KnapsackInterval )
{
  ASK_YES_NO( "区間長は固定ですか？" );
  if( reply == "y" ){
    CERR( "区間をスライドしていき、両端の更新値を用いて最大値を管理しましょう。" );
  } else {
    CERR( "- 区間に属すべき点が与えられているならば、その点の両側で始切片和と終切片和の" );
    CERR( "  最小値の総和を求め全体の総和から引けばよいので、始切片和の始切片最大値と" );
    CERR( "  終切片和の終切片最大値を前計算しましょう。" );
    CERR( "- そうでないならば、尺取り法で区間を伸ばし両端の更新値を用いて最大値を管理しましょう。" );
    CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Interval" );
  }
}

AC( KnapsackBoundedIntervalLength )
{
  CERR( "Iの各連結成分の長さの上限がLであるとします。選択する項目の価値総和の最大化は" );
  CERR( "選択しない価値総和の最小化に帰着されるので、N未満の各iに対し、" );
  CERR( "dp[i] = 「[0,i)で選択しない項目の価値総和の最小値」" );
  CERR( "と定め、漸化式" );
  CERR( "dp[i+L] = (min_{j=i}^{i+L-1} dp[j]) + A[i+L]" );
  CERR( "を" );
  CERR( "- O(N log N)が間に合いそうならば、IntervalMinBITによる一点min更新と" );
  CERR( "  区間min取得" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "- O(N log L)が間に合いそうならば、map<値,個数>による直近L個の管理" );
  CERR( "で高速化することでiに関する動的計画法を処理しましょう。" );
}

AC( KnapsackMultipleChoice )
{
  ASK_YES_NO( "各項目が無制限に選択できますか？" );
  if( reply == "y" ){
    CALL_AC( KnapsackUnboundedChoice );
  } else {
    CERR( "各項の選択回数の上限をHと置きます。" );
    ASK_YES_NO( "負の価値も許容されますか？" );
    if( reply == "y" ){
      CALL_AC( KnapsackBoundedChoiceNegativeValue );
    } else {
      ASK_YES_NO( "コストがありますか？" );
      if( reply == "y" ){
	CALL_AC( KnapsackBoundedChoiceUnstable );
      } else {
	CALL_AC( KnapsackBoundedChoiceCostfree );
      }
    }
  }
}

AC( KnapsackUnboundedChoice )
{
  CERR( "S回目の選択以降コストが定数になるとして、" );
  CERR( "O(N S |C|)が通りそうならば" );
  CERR( " 「i個目までの項を使ってコストの総和がc以下の時の価値の最大値dp[i][c]」" );
  CERR( "  を管理するi,cに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Unstable" );
  CERR( "を検討しましょう。" );
}

AC( KnapsackUnboundedChoiceStable )
{
  CERR( "コストから選択回数上限を設定することで選択回数上限つきの問題に" );
  CERR( "帰着されられます。それで解けなければ、" );
  CERR( "- O(N + V^2)が通りそうでコストがないならば、" );
  CERR( " 「i個目までの項を使って価値の総和がvの時のコストの最小値dp[i][v]」" );
  CERR( "  を管理するi,vに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\UnboundedChoice\\Costfree" );
  CERR( "- O(N + |C|^2)が通りそうならば、" );
  CERR( " 「コストcの項の価値の最大値v[c]」" );
  CERR( "  を前計算し" );
  CERR( " 「コストの総和がc以下の時の価値の最大値dp[c]」" );
  CERR( "  を管理するcに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\UnboundedChoice\\NegativeValue" );
  CERR( "を検討しましょう。" );
}

AC( KnapsackBoundedChoiceNegativeValue )
{
  CERR( "- O(N min(|C|,H 2^{N/2}) log_2 H)が通りそうならば" );
  CERR( "  重複回数を二進法で分解してまとめ、重複がない場合に帰着させましょう、" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Boundedchoice\\NegativeValue" );
  CALL_AC( SingleKnapsack );
}

AC( KnapsackBoundedChoiceUnstable )
{
  CERR( "S回目の選択以降コストが定数になるとして、" );
  CERR( "O(N S |C|)が通りそうならば" );
  CERR( " 「i個目までの項を使ってコストの総和がc以下の時の価値の最大値dp[i][c]」" );
  CERR( "  を管理するi,cに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Unstable" );
  CERR( "を検討しましょう。" );
}

AC( KnapsackBoundedChoiceCostfree )
{
  CERR( "価値をコストとみなしてコストがある場合に帰着させましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\BoundedChoice\\Costfree" );
}

AC( KnapsackOrdered )
{
  ASK_YES_NO( "何回目に選ばれたかによって項目のコストが変動しますか？" );
  if( reply == "y" ){
    CALL_AC( KnapsackOrderedUnstable );
  } else {
    CALL_AC( KnapsackOrderedStable );
  }
}

AC( KnapsackOrderedUnstable )
{
  CERR( "1 <= m <= M個目の選択におけるコスト上限をD_mとし、" );
  CERR( "項iのコストが取りうる値をC_{i,1},C_{i,2}の2通りとし、" );
  CERR( "全体でm回目の選択における項iのコストがiに依存しない数1 <= k_m <= Kを用いて" );
  CERR( "C_{i,k_m}と表せるとします。つまりC_{i,k_m}<=D_mが項iの選択制約です。" );
  CERR( "ただしk_1 = 1としても一般性を失いません。" );
  CERR( "" );
  CERR( "O((N log_2 N)+M)が間に合いそうならば、(C_{i,k},i)_iの辞書順ソートを" );
  CERR( "sC(k)と置き、(k_m,D_m,m)_mの辞書順ソートを(k_{m_j},D_{m_j},m_j)_jと置き、" );
  CERR( "1 <= j <= Mを小さい順に探索し、sC(k_{m_j})を用いて選択可能な項iに対する" );
  CERR( "{A_i,C_{i,2},i}をsetで管理し、その中で最大の要素を採用し、集合から削除することで" );
  CERR( "m_j個目の選択を決定しましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Ordered" );
}

AC( KnapsackOrderedStable )
{
  CERR( "1 <= m <= M個目の選択におけるコスト上限をD_mとし、" );
  CERR( "項iのコストをC_iとします。つまりC_i<=D_mが項iの選択制約です。" );
  CERR( "" );
  CERR( "O((N log_2 N)+M)が間に合いそうならば、(C_i,i)_iの辞書順ソートをsC、" );
  CERR( "(D_m)_mの辞書順ソートを(D_{m_j})_jと置き、" );
  CERR( "1 <= j <= Mを小さい順に探索し、sCを用いて選択可能な項iに対する{A_i,i}を" );
  CERR( "setで管理し、その中で最大の要素を採用し、集合から削除することで" );
  CERR( "m_j個目の選択を決定しましょう。" );
  CERR( "\\Mathematics\\Combinatorial\\KnapsackProblem\\Ordered" );
}

AC( SingleKnapsack )
{
  ASK_YES_NO( "コストがありますか？" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackWithCost );
  } else {
    CALL_AC( SingleKnapsackCostfree );
  }
}

AC( SingleKnapsackWithCost )
{
  ASK_YES_NO( "コストが１次元ですか？" );
  CERR( "- O(N 2^{N/2})が通りそうならば半分全列挙" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative" );
  CERR( "- O(N |C|)が通りそうかつコストが非負ならば、" );
  CERR( "  「i番目の項まで使ってコストの総和がcの時の価値の最大値dp[i][c]」" );
  CERR( "  を管理するi,cに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Value" );
  CERR( "- O(N 2^N)が通りそうかつコストの動く範囲が遷移途中も制限されているならば、" );
  CERR( "  bit全探策" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Restrictive" );
  if( reply == "y" ){
    CALL_AC( SingleKnapsackWithLinearCost );
  } else {
    CALL_AC( SingleKnapsackWithMultiCost );
  }
}

AC( SingleKnapsackWithLinearCost )
{
  CERR( "- O(N V)が通りそうかつ価値が非負ならば、" );
  CERR( "  「i番目の項まで使って価値の総和がvの時のコストの最小値dp[i][c]」" );
  CERR( "  を管理するi,vに関する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Cost" );
  CERR( "を検討しましょう。" );
}

AC( SingleKnapsackWithMultiCost )
{
  CERR( "- C=[0,W]^DでO(N W + W^{D-1}(D + log(1+W)))が通りそうかつ" );
  CERR( "  各コストが１つしか非自明成分を持たないならば、" );
  CERR( "  １つしか非自明成分を持たないコストごとに価値の最大値を求めて区間MaxBIT" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Value\\Multicost" );
  CERR( "を検討しましょう。" );
}

AC( SingleKnapsackCostfree )
{
  CERR( "- O(N 2^{N/2})が通りそうならば半分全列挙" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree" );
  CERR( "- O(N v_max)が通りそうかつ非負ならば[V-v_max,V+v_max]での実現可能性を" );
  CERR( "  管理する動的計画法" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Costfree" );
  CERR( "- O(N^4)が間に合いそうかつ選択に負価値の要素と非負価値の要素間で一方向の" );
  CERR( "  制約があるならば、制約を容量∞の有向辺に対応させ選択するか否かを" );
  CERR( "  二部マッチングに翻訳し最小カット（最大流）計算" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\MaximumFlow" );
  CERR( "- O((N+V)log_2 V)が通りそうかつ非負かつVが10^5オーダーでプロス素数Pを" );
  CERR( "  法とするならば法Pでの高速フーリエ変換によるexp(logの総和)計算" );
  CERR( "  \\Mathematics\\Polynomial\\Truncate" );
  CERR( "を検討しましょう。" );
}

AC( MultipleKnapsack )
{
  CERR( "ナップサックの個数をKと置きます。" );
  CERR( "- O(K(N 2^N + K^N))が通りそうならば、高速ゼータ変換" );
  CERR( "  \\Mathematics\\Combinatorial\\KnapsackProblem\\Negative\\Subsetwise\\Multiknapsack" );
  CERR( "- 各ナップサックの容量が非常に小さいならば、コストの大きさで項目を分けて" );
  CERR( "  コストの大きい順にそれらの選択数を全探策または二分探索" );
  CERR( "  参考：https://yukicoder.me/problems/no/2617/editorial" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationArrayFunction )
{
  CERR( "配列を受け取る関数Fが与えられているとします。与えられた配列Aに" );
  CERR( "何らかの処理をして得られる配列Bに対するF(B)の最大化問題を考えます。" );
  CERR( "最小化問題は-1倍すれば良いです。" );
  CERR( "" );
  CERR( "AのサイズNが小さい場合、操作の全探策を検討しましょう。" );
  CERR( "" );
  CERR( "Fの終域Mの有限順序半群構造(|,R)が" );
  CERR( "(1) Rは<を含意しかつ<に関する最大元がRに関する最大元でもある。" );
  CERR( "(2) 任意のm,n in Mに対しm = m|nまたはm R m|nである。" );
  CERR( "(3) Fが|に関する総和関数である。" );
  CERR( "(4) 配列のサイズNがRの最長昇鎖列長L以下ならば、Bの|に関する累積和が" );
  CERR( "    Rに関して狭義単調増加するようにBを構成できる" );
  CERR( "を満たすならば、N>=Lの場合に求める<に関する最大値が<に関する最大元と" );
  CERR( "一致するので、N<Lの場合に帰着されます。" );
  ASK_YES_NO( "操作は成分を成分の一次結合で置き換えるものですか？" );
  if( reply == "y" ){
    CALL_AC( MaximisationArrayFunctionLinearCombination );
  } else {
    CALL_AC( MaximisationArrayFunctionGeneralOperation );
  }
}

AC( MaximisationArrayFunctionLinearCombination )
{
  CERR( "成分の生成するイデアルや成分の差が生成するイデアルに注目して" );
  CERR( "gcdを計算しましょう。" );
}

AC( MaximisationArrayFunctionGeneralOperation )
{
  CERR( "最大化すべき式のサブゴールfに表れる項xのうち決め打ちやすいものを探しましょう。" );
  CERR( "配列の長さをiで打ち切った時のxの候補数をX(i)、" );
  CERR( "配列の長さをiで打ち切ってxを決め打った時の配列の長さi+1でのxの候補数をdX(i)" );
  CERR( "と置きます。" );
  CERR( "- O(sum_i X(i) dX(i))が通りそうでfがxからO(1)で計算できるならば、" );
  CERR( "  iとxに関する動的計画法" );
  CERR( "- O(N log_2 X(N))が通りそうで" );
  CERR( "  - fがxからO(N)で計算できxに関して単調ならば、xの二分探索" );
  CERR( "  - fがxからO(N/x)で計算できるならば、xの全探索" );
  CERR( "- O(N log_2 N)が通りそうでxを並び替えるとfがxからO(log_2 N)で計算できる" );
  CERR( "  ならば、優先度つきキューなどでのxの管理" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationArrayLength )
{
  CERR( "配列のサイズをN、配列の各成分の下界の要素数の総和をE、順序集合の要素数をCと置きます。" );
  CERR( "- 全順序でO(N log_2 N)が間に合いそうならば、条件を満たす部分列の長さの最大値を" );
  CERR( "  インデックスに持つBITを用いて、それらの部分列の末尾である項を記録" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "- 疎な半順序でO(E log_2 N)が間に合いそうならば、条件を満たす部分列の末尾を" );
  CERR( "  インデックスに持つ連想配列を用いて、それら部分列の長さの最大値を記録" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "- O(N + C^2 N^{1/2})が間に合いそうならば、順序集合の各要素c < dに対する" );
  CERR( "  「始端の値がc、終端の値がd以下である単調増大部分列の長さ」を管理する" );
  CERR( "  C次上半行列を載せたモノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
  CERR( "を検討しましょう。" );
}

AC( MaximisationFunctionOnAffineSpace )
{
  ASK_NUMBER(
	     "凸関数の最小／最大化問題" ,
	     "可微分関数の最小／最大化問題" ,
	     "距離の最小／最大化問題" ,
	     "被覆半径の最小化問題"
	     );
  if( num == num_temp++ ){
    CERR( "三分探索を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "ニュートン法を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "マンハッタン距離（l^1）は一次変換でl^∞に帰着させた上で、" );
    CERR( "- 単調な式に帰着できる場合、二分探索" );
    CERR( "- 最大化問題の場合、絶対値を外す符号パターンの全探策" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "マンハッタン距離（l^1）は一次変換でl^∞に帰着させた上で、" );
    CALL_AC( MinimisationSolvingOpenCoveringUnknownCentres );
  }
  CERR( "" );
  CERR( "複数のパラメータを決定すべき場合は、サブゴールの式の値を決め打ちましょう。" );
}

AC( MaximisationSubsetSize )
{
  ASK_NUMBER(
	     "部分集合の要素数の最大化問題" ,
	     "その他の部分集合の価値最大化問題" ,
	     "部分集合への分割の最小化問題"
	     );
  if( num == num_temp++ ){
    CERR( "与えられた集合のサイズをNと置きます。" );
    CERR( "- O(2^N)が間に合いそうならば、bit全探策" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- O(N2^N)が間に合いそうならば、部分集合の包含対のbit全探策" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- 半順序の極大鎖ならば、後続関数を定義してその逆像を辺とする非輪状有向グラフ" );
    CERR( "  を構築し、極大元からの最長歩道計算" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\LongestWalk\\a.hpp" );
    CERR( "- 半順序の極大反鎖ならば、" );
    CERR( "  - 鎖への極小な分割が求まるならば、Dilworthの定理の証明に基く構築" );
    CERR( "    https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
    CERR( "  - トポロジカルソートされているならば、始切片としてNに埋め込み、" );
    CERR( "    半順序と整合的な後続関数S:N->Nを定義して、Sの値が元の集合に入らない" );
    CERR( "    要素全体の集合をSの単調性を用いて二分探索で計算" );
    CERR( "- 半開区間の極大排他的集合ならば、区間スケジューリング" );
    CERR( "  \\Mathematics\\Combinatorial\\IntervalScheduling\\a.hpp" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "コストなしのナップサック問題に他なりません。" );
    CALL_AC( SingleKnapsackCostfree );
  } else {
    CERR( "- 鎖への分割の最小化ならば、極大反鎖からDilworthの定理の証明に基く構築" );
    CERR( "  https://en.wikipedia.org/wiki/Dilworth%27s_theorem#Inductive_proof" );
    CERR( "- 完全代表系の計算ならば、幅優先探索やUnionFindによる連結成分計算" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  }
}

AC( MinimisationGraph )
{

  ASK_NUMBER(
             "コストの最小化問題" ,
             "価値の最大化問題"
             );
  if( num == num_temp++ ){
    CALL_AC( MinimisationGraphCost );
  } else {
    CALL_AC( MaximisationGraphValue );
  }
}

AC( MinimisationGraphCost )
{
  ASK_NUMBER(
	     "全域森のコスト最小化問題" ,
	     "パスのコスト最小化問題"
	     );
  if( num == num_temp++ ){
    CERR( "クラスカル法" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
    CERR( "を検討しましょう。" );
  } else if( num == num_temp++ ){
    CERR( "これは最短経路問題そのものです。" );
    AC( MinimisationMovingCost );
  }
}

AC( MaximisationGraphValue )
{
  ASK_NUMBER(
	     "辺の価値最大化問題" ,
	     "頂点の価値最大化問題"
	     );
  if( num == num_temp++ ){
    CERR( "価値を-1倍したコストを考えることで辺のコスト最小化問題に帰着されます。" );
    CALL_AC( MinimisationGraphCost );
  } else {
    ASK_NUMBER(
               "非輪状グリッドグラフに埋め込み可能なグラフ" ,
               "その他のグラフ"
               );
    if( num == num_temp++ ){
      CERR( "非輪状グリッドグラフに埋め込み、平面走査と区間max更新" );
      CERR( "\\Mathematics\\Geometry\\Graph\\Grid\\ValueMaximisation" );
      CERR( "を検討しましょう。" );
    } else {
      CERR( "- 演算が加法ならば、始端の重み*(始点?2:1)と終端の重み*(終点?2:1)" );
      CERR( "  の和の-1倍を各辺の重みとして辺のコスト最小化問題に帰着" );
      CERR( "- 演算がmaxならば、始端の重みと終端の重みの最大値を" );
      CERR( "  各辺の-1倍の重みとして辺のコスト最小化問題に帰着" );
      CERR( "を検討しましょう。" );
      CALL_AC( MinimisationGraphCost );
    }
  }
}

AC( MaximisationFunctionOnTree )
{
  ASK_NUMBER(
	     "木上の関数の特定の部分集合上での最大／最小値計算問題" ,
	     "木の分割ごとに定まる値の最大／最小化問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CERR( "木を受け取る関数fが与えられているとします。" );
    CERR( "" );
    CALL_AC( FunctionOnTree );
    CERR( "「第i頂点までで切った時のF(P)たちの最大値dp[i]」" );
    CERR( "を管理するiに関する動的計画法（O(N^2×fの計算量)）" );
    CERR( "を検討しましょう。" );
  }
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

AC( MaximisationProbability )
{
  CERR( "操作／戦略を選んで確率／期待値を最大化する場合、" );
  CERR( "被操作対象や可能な操作／戦略のデータなどを状態として定式化し、" );
  CERR( "「sを経由する場合の確率／期待値の最大値dp[s]」" );
  CERR( "を管理するsに関する動的計画法を検討しましょう。" );
}

AC( MinimisationOperationCost )
{
  CERR( "操作コストの最小化は、操作による状態遷移を有向グラフ上の移動とみなすことで" );
  CERR( "最短経路問題に帰着させることが可能です。" );
  CALL_AC( MinimisationMovingCost );
}

AC( MaximisationCountingOperation )
{
  CALL_AC( ReducingOperation );
  ASK_YES_NO( "その上で状態が10^6オーダーですか？" );
  if( reply == "y" ){
    CERR( "状態の遷移をグラフ上の移動とみなし、最長経路問題に帰着させましょう。" );
    CALL_AC( MaximisationMovingDistance );
  } else {
    CERR( "操作方法の探索には" );
    CERR( "- 操作によって不変量が減る量が最小になるような操作の反復" );
    CERR( "- ほとんど同じ操作の反復" );
    CERR( "- 操作対象が複数あるならば" );
    CERR( "  - 対象に操作優先度があるならば、各対象の操作回数最大値に関する" );
    CERR( "    動的計画法" );
    CERR( "  - 操作順に意味がなく各対象に高々１回しか操作しないならば、" );
    CERR( "    操作する対象全体のなす部分集合の全探策や半分全列挙" );
    CERR( "を検討しましょう。" );
  }
}

AC( MinimisationCoveringSize )
{
  CERR( "サイズを決め打った二分探索で被覆可能性判定をしましょう。" );
  ASK_YES_NO( "被覆中心は固定ですか？" );
  if( reply == "y" ){
    CERR( "被覆可能性を描画図形の一致判定に翻訳しましょう。" );
    CALL_AC( DecisionImageCoincidence );
  } else {
    CERR( "被覆可能性を描画可能性に翻訳しましょう。" );
    CALL_AC( DecisionDrawability );
  }
}

AC( MaximisationDrawingImage )
{
  CERR( "描画個数の最大／最小化は描画サイズの最小／最大化に帰着させましょう。" );
  CERR( "描画サイズの最大／最小化問題はサイズを決め打った二分探索や各点でのサイズの最大化" );
  CERR( "などを行い描画可能性判定に帰着させましょう。" );
  CALL_AC( DecisionDrawability );
}

AC( MaximisationMinimum )
{
  CERR( "全てを-1倍することで最大値を演算とする総和の最小化問題に帰着させます。" );
  CALL_AC( MinimisationSubsetSum );
}

AC( MinimisationSubsetSum )
{
  ASK_NUMBER(
	     "グラフの辺集合E上の関数の部分和の最小化問題" ,
	     "一般の集合上の関数の部分和の最小化問題"
	     );
  if( num == num_temp++ ){
    CERR( "最短経路問題に帰着させましょう。" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "部分和を固定して部分集合の存在を判定する" );
    CERR( "二分探索を検討しましょう。" );
  }
}

AC( MaximisationGame )
{
  ASK_YES_NO( "整礎なゲームですか？" );
  if( reply == "y" ){
    CERR( "数列や多重集合から成分や要素である項を交互に削除していき、項iを" );
    CERR( "先行が削除した場合は先行にA[i]点、後行が削除した場合は後行にB[i]点" );
    CERR( "が与えられるとし、先行の総得点をX、後行の総得点をYと置きます。" );
    CERR( "- 先行がX-Yの最大化を、後行がX-Yの最小化を目指す問題ならば、" );
    CERR( "  双方がA[i]+B[i]の大きい順に貪欲に選ぶ場合が双方の最善です。" );
    CERR( "- 先行がX-Yの最小化を、後行がX-Yの最大化を目指す問題ならば、" );
    CERR( "  双方がA[i]+B[i]の小さい順に貪欲に選ぶ場合が双方の最善です。" );
    CERR( "- 先行がX+Yの最大化を、後行がX+Yの最小化を目指す問題ならば、" );
    CERR( "  双方がA[i]-B[i]の大きい順に貪欲に選ぶ場合が双方の最善です。" );
    CERR( "- 先行がX+Yの最小化を、後行がX+Yの最大化を目指す問題ならば、" );
    CERR( "  双方がA[i]-B[i]の小さい順に貪欲に選ぶ場合が双方の最善です。" );
    CERR( "これに従って配列の和／差をソートして実際に操作を実行しましょう。" );
  } else {
    CERR( "局面を反復可能なゲームは反復戦略を取ることで初期局面に帰着されます。" );
    CERR( "- 先行が最終着手を行う場合、初手での最大化問題に帰着し" );
    CERR( "  初手のうち無駄がないものを全探策" );
    CERR( "- 後行が最終着手を行う場合、２手目での最小値の最大化問題に帰着し" );
    CERR( "  初手のうち無駄がないものを固定するごとに２手目の最小値を計算" );
    CERR( "- 最終的な不変量の下界を決め打った時にそれ以上の不変量を得ることが" );
    CERR( "  実現可能な必要十分条件が決定できる場合、それによる最大値の計算" );
    CERR( "を検討しましょう。" );
    CERR( "" );
    CERR( "数値を置き換えるゲームは頻度表を用いて数値を移動するゲームに" );
    CERR( "翻訳できることがありますが、その場合は数値の移動が結果的に" );
    CERR( "起こらない操作も許されるか否かに注意しましょう。" );
  }
}

AC( Counting )
{
  CERR( "動的計画法で計算量が大きい場合、" );
  CERR( "- dp[i]の代わりに" );
  CERR( "  - sum_{j<=i}dp[j]を考える。" );
  CERR( "  - i番目の状態をdp[i+1]への寄与C(k)が等しい状態kへ細分してdp[i][k]を考える。" );
  CERR( "  - i番目の状態をdp[i+1]への寄与がcである状態の和集合へ細分してdp[i][c]を考える。" );
  CERR( "- dp[i][k]の代わりにdp[i][0]のみに注目してBITなどで高速化。" );
  CERR( "を検討しましょう。" );
  ASK_NUMBER(
	     "数の数え上げ問題" ,
	     "配列の数え上げ問題" ,
	     "文字列の数え上げ問題" ,
	     "グラフの数え上げ問題" ,
	     "部分集合の数え上げ問題" ,
	     "戦略／操作方法の数え上げ問題" ,
	     "経路の数え上げ問題" ,
	     "タイリング／塗り分けの数え上げ問題" ,
	     "ヤング図形の数え上げ問題" ,
	     "カタラン数の計算問題" ,
	     "操作回数の計算問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingNumber );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingGraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingSubset );
  } else if( num == num_temp++ ){
    CALL_AC( CountingStrategy );
  } else if( num == num_temp++ ){
    CALL_AC( CountingPath );
  } else if( num == num_temp++ ){
    CALL_AC( CountingTiling );
  } else if( num == num_temp++ ){
    CALL_AC( CountingYoundDiagram );
  } else if( num == num_temp++ ){
    CALL_AC( ExplicitExpressionCountingOperation );
  }
  ASK_YES_NO( "サンプルを解析しますか？" );
  if( reply == "y" ){
    CALL_AC( SampleAnalyser );
  }
}

AC( CountingNumber )
{
  CERR( "何らかの条件を満たす数の数え上げ問題を考えます。" );
  ASK_NUMBER(
	     "固定長変数関数の値に関する条件" ,
	     "各桁の数字に関する条件" ,
	     "その他の条件"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingExplicitExpression );
  } else if( num == num_temp++ ){
    CERR( "数を十進法などで文字列とみなします。" );
    CALL_AC( CountingArray );    
  } else {
    CERR( "条件P(n)を満たすN以下の非負整数nの数え上げは、関数f(n) = P(n)?1:0などの" );
    CERR( "総和の計算問題に帰着されます。" );
    CALL_AC( ExplicitExpressionOneArrayEntrySum );
  }
}

AC( CountingExplicitExpression )
{
  CERR( "- 変数の対称性があれば大小関係を制限した全探策" );
  CERR( "- 何らかの約数となるなど動く範囲が狭い変数があればそれらを決め打った全探策" );
  CERR( "- 半順序集合への特定の写像の逆像ならばゼータ変換／メビウス変換" );
  CERR( "  \\Mathematics\\Combinatorial\\ZetaTransform" );
  CERR( "- gcd(n,x)=1かつ1<=x<=nを満たすxの数え上げはオイラー関数" );
  CERR( "  \\Mathematics\\Arithmetic\\Mod\\Function\\Euler" );
  CERR( "- f(g(x),g(y))=cの形ならば" );
  CERR( "  - まず各b in im(g)に対しf(a,b) = cを満たすa in im(g)全体を前計算する。" );
  CERR( "  - 次に|dom(g)| = N、max im(g) = Mとして、各y in im(g)に対する" );
  CERR( "    逆像の濃度|g^{-1}(y)|を管理するg_inv[y]を" );
  CERR( "    - O(N)が間に合いそうならばunordered_map::g_inv[g[x]]++" );
  CERR( "    - O(M+N)が間に合いそうならば配列::g_inv[g[x]]++" );
  CERR( "    - x,yに制限h(x)<h(y)がある場合はh(x)の上限cについてループして" );
  CERR( "      g_inv[g(x)]++していき、それと並行してyをc<h(y)の範囲で全探索" );
  CERR( "    により管理する。" );
  CERR( "  - 最後に各yごとにf(a,g(y)) = cを満たす各a in im(g)に対しa = g(x)を満たす" );
  CERR( "    xをg_inv[a]で数え上げる。" );
  CERR( "- f(g(x),g(y))<=cの形かつfとgが単調増加するならば" );
  CERR( "  - まず各b in im(g)に対しf(a,b) <= cを満たすaの上限を二分探索で前計算する。" );
  CERR( "  - 次にそうして得られる各aに対しg(x)<=aを満たすxの上限を二分探索で前計算する。" );
  CERR( "  - 最後に各yごとにb = g(y)に対する前計算結果の総和を求める。" );
  CERR( "- 平方数の和ならばヤコビの二平方定理" );
  CERR( "  https://ja.wikipedia.org/wiki/ヤコビの二平方定理" );
  CERR( "を検討しましょう。" );
}

AC( CountingArray )
{
  ASK_NUMBER(
             "条件を満たす配列の数え上げ問題" ,
             "与えられた配列の部分列の数え上げ問題"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingArrayConditional );
  } else {
    CALL_AC( CountingSubArray );
  }
}

AC( CountingArrayConditional )
{
  ASK_NUMBER(
	     "配列を受け取る関数の値が固定された配列の数え上げ問題" ,
	     "隣接成分間関係式を満たす配列の数え上げ問題" ,
	     "辞書式順序などで固定長の部分文字列に上限が与えられた配列の数え上げ問題" ,
             "閉じたカッコ列の数え上げ問題" ,
	     "その他の関係式を満たす配列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingArrayInverseImage );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayAdjacentRelation );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayBounded );
  } else if( num == num_temp++ ){
    CALL_AC( CountingParenthesisSequence );
  } else if( num == num_temp++ ){
    CALL_AC( CountingArrayOtherRelation );
  }
}

AC( CountingArrayInverseImage )
{
  CERR( "配列の長さをN、成分の取りえる値の個数をK、配列を受け取る関数をf、" );
  CERR( "fの取る値のうち考慮すべき個数をVとします。" );
  CERR( "- O(K^N)が間に合いそうならば、全ての配列に対する関数の値の前計算" );
  CERR( "- O(NV)が間に合いそうでかつfがNに関して再帰的構造を持つならば、" );
  CERR( "  「長さiの時に値vである配列の総数dp[i][v]」" );
  CERR( "  を管理するi,vに関する動的計画法" );
  CERR( "  - 特に非負整数値関数gを用いてf(A)=sum_i g(A[i])と表せるならば、" );
  CERR( "    gの頻度表を前計算して頻度で重み付けてdp更新" );
  CERR( "  - 特に非負有理数値関数gを用いてf(A)=sum_i g(A[i])と表せるならば、" );
  CERR( "    gの値の分母が大きな素数になる成分だけ別個に考えてgの値の分母の" );
  CERR( "    最小公倍数が小さい場合に帰着させ、通分して整数値の場合に帰着" );
  CERR( "- 配列が有界整数列で関数が非零整数係数ベクトルBによる内積であるならば、" );
  CERR( "  「長さiの時に値vである配列の総数dp[i][v]」" );
  CERR( "  が漸化式dp[i+1][v] = sum_{j<=v/B[i+1]} dp[i][v-j*B[i+1]]を" );
  CERR( "  満たすことからf_i(x,v)=dp[i][v-x*B[i+1]]と置いてその累積和を" );
  CERR( "  S(f_i,v)(x)と置いて得られる漸化式" );
  CERR( "  f_{i+1}(x,v) = S(f_i,v)((v-x*B[i+2])/B[i+1])" );
  CERR( "  を平行移動で処理" );
  CERR( "  \\Mathematics\\Polynomial\\ParallelTranslation" );
  CERR( "  \\Mathematics\\Polynomial\\CumulativeSum" );
  CERR( "- 関数が区間和などデータ構造で計算できる値で表せるならば、" );
  CERR( "  データ構造に翻訳した上での数え上げ" );
  CERR( "を検討しましょう。" );
}

AC( CountingArrayAdjacentRelation )
{
  CERR( "- 半順序での単調性の場合、" );
  CERR( "  - 全順序ならば、数の分割方法などへの翻訳" );
  CERR( "  - 疎な半順序ならば、グラフの前計算" );
  CERR( "- その他の条件の場合は動的計画法で、" );
  CERR( "  - 禁止条件の時は余事象を引く更新" );
  CERR( "  - 複数条件の時は包除原理による更新" );
  CERR( "  - 特定の部分列（例えばaba）を含むという条件の時は" );
  CERR( "    (1) 長さiかつabaを含まないかつ末尾がaなものの個数dpa[i]" );
  CERR( "    (2) 長さiかつabaを含まないかつ末尾がabなものの個数dpab[i]" );
  CERR( "    (3) 長さiかつabaを含むものの個数dpaba[i]" );
  CERR( "    を再帰式" );
  CERR( "    (1) dpa[i] = (26^{i-1}-dpaba[i-1]-dpab[i-1])*1" );
  CERR( "    (2) dpab[i] = (26^{i-2}-dpaba[i-2]*26 + dpab[i-2])*1" );
  CERR( "    (3) dpaba[i] = dpaba[i-1]*26 + dpab[i-1]*1" );
  CERR( "    を用いてiに関する動的計画法で計算" );
  CERR( "を検討しましょう。" );
}

AC( CountingArrayBounded )
{
  CERR( "上限をsと置き、sの長さをL、数え上げる文字列の長さをNと置き、" );
  CERR( "数え上げる文字列の属す集合をSと置きます。" );
  ASK_YES_NO( "L == Nですか？" );
  if( reply == "y" ){
    CALL_AC( CountingArrayBoundedTotal );
  } else {
    CALL_AC( CountingArrayBoundedSub );
  }
}

AC( CountingArrayBoundedTotal )
{
  CERR( "文字列集合S内でs未満の項の数え上げをする際は、" );
  CERR( "長さや文字種類数などの状態を考えて" );
  CERR( "dp[d][n] = 「Sと先頭d文字目で初めてズレる状態nの項の総数」" );
  CERR( "をdとnに関する動的計画法で求めましょう。" );
}

AC( CountingArrayBoundedSub )
{
  CERR( "長さLの全ての部分文字列がs未満であるという条件を、Sの定義を用いて" );
  CERR( "簡単な条件に翻訳しましょう。" );
  CERR( "そのためにはLが小さい具体的なsに対して実験し、法則や上限を見付けましょう。" );
  CERR( "この際に辞書式順序と積順序を混同しないように注意しましょう。" );
}

AC( CountingArrayOtherRelation )
{
  ASK_YES_NO( "配列への格納順が関係ありますか？" );
  if( reply == "y" ){
    ASK_YES_NO( "総和が0で左端からの始端和が非負な±1列ですか？" );
    if( reply == "y" ){
      CERR( "長さ2Nの閉じたカッコ列に対応します。" );
      CALL_AC( CountingParenthesisSequence );
    } else {
      CERR( "添字に半順序を構成しグラフの数え上げに帰着することを検討しましょう。" );
      CALL_AC( CountingGraph );
    }
  } else {
    CERR( "（多重）集合やソートされた配列の数え上げに帰着することを検討しましょう。" );
    CALL_AC( CountingSubset );
  }
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
    CERR( "  \\Mathematics\\Polynomial\\Truncate" );
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
  CERR( "- 全順序でO(N log_2 N)が間に合いそうならば、通常の配列で二分探索" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence" );
  CERR( "- 疎な半順序でO((N+E)log_2 N)が間に合いそうならば、連想配列" );
  CERR( "  \\Mathematics\\Combinatorial\\IncreasingSubsequence\\Subwalk" );
  CERR( "- O(N + C^2 N^{1/2})が間に合いそうならば、順序集合の各要素c < dに対する" );
  CERR( "  「始端の値がc、終端の値がd以下である単調増大部分列の個数」を管理する" );
  CERR( "  C次上半行列を載せたモノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid" );
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
  CERR( "" );
  CERR( "適宜ヤング図形との関係も検討しましょう。" );
  CALL_AC( CountingYoundDiagram );
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

AC( CountingString )
{
  ASK_NUMBER(
	     "条件を満たす文字列の数え上げ問題" ,
	     "与えられた文字列の部分文字列の数え上げ問題"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingStringConditional );
  } else {
    CALL_AC( CountingSubString );
  }
}

AC( CountingStringConditional )
{
  CERR( "文字列は文字の配列とみなします。" );
  CALL_AC( CountingArray );
}

AC( CountingSubString )
{
  ASK_NUMBER(
	     "部分文字列から取得位置情報を落とした文字列全体の数え上げ問題" ,
	     "文字列一致に関する性質を満たす部分文字列の数え上げ問題" ,
	     "文字配置に関する性質を満たす部分文字列の数え上げ問題"
	     );
  if( num == num_temp++ ){
    CERR( "文字列を文字の配列とみなすことで、配列の問題に帰着させることができます。" );
    CALL_AC( CountingSubArrayImageArray );
  } else if( num == num_temp++ ){
    CALL_AC( CountingMatchingSubString );
  } else if( num == num_temp++ ){
    CALL_AC( CountingShapedSubString );
  }
}

AC( CountingMatchingSubString )
{
  CERR( "- 自分とマッチングする部分文字列の数え上げ問題はZアルゴリズム" );
  CERR( "  \\Utility\\String\\Z-Algorithm" );
  CERR( "- 回文である部分文字列の数え上げ問題は" );
  CERR( "  - O(N^2)が通りそうならば、尺取り法による前計算" );
  CERR( "    \\Utility\\String\\Palindrome" );
  CERR( "  - O(N^2)が通らなさそうならば、マナチャーのアルゴリズムや" );
  CERR( "    ローリングハッシュで前計算" );
  CERR( "    https://snuke.hatenablog.com/entry/2014/12/02/235837" );
  CERR( "    \\Utility\\String\\RollingHash" );
  CERR( "を検討しましょう。" );
}

AC( CountingShapedSubString )
{
  CERR( "ABC（３文字が異なる）やAAB（先頭２文字が一致し３文字目が異なる）など" );
  CERR( "文字配置が指定された長さLの部分文字列の数え上げは" );
  CERR( "- O(26^L N)が通りそうならば山型配列と同様に" );
  CERR( "  「i文字目までに長さL以下の各文字列sが部分文字列として出現する個数dp[i][s]」" );
  CERR( "  を管理するiに関する動的計画法" );
  CERR( "- O(L 26^L log_2 N)が通りそうならば" );
  CERR( "  「各2羃区間Iに長さL以下の各文字列sが部分文字列として出現する個数dp[I][s]」" );
  CERR( "  を管理するIに関する分割統治法" );
  CERR( "を検討しましょう。" );
  CERR( "" );
  CERR( "分割統治法で用いるdp[I]は文字列全体のなすモノイドのモノイド環を" );
  CERR( "文字列配置の不適切な文字列やなくても復元可能な文字列全体の生成するイデアルで" );
  CERR( "割って得られる非可換環の空文字列係数が1であるもの全体のなす非可換乗法モノイドに" );
  CERR( "値を取るため、非可換モノイドで抽象化可能なBITやセグメント木を用いることも可能です。" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Monoid" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SegmentTree" );
}

AC( CountingGraph )
{
  ASK_NUMBER(
             "条件を満たす無向グラフの数え上げ問題" ,
             "条件を満たす有向グラフの数え上げ問題" ,
	     "与えられた木の分割の数え上げ問題"
             );
  if( num == num_temp++ ){
    CALL_AC( CountingUndirectedGraph );
  } else if( num == num_temp++ ){
    CALL_AC( CountingDirectedGraph );
  } else {
    CALL_AC( CountingPartitionOfTree );
  }
}

AC( CountingUndirectedGraph )
{
  CERR( "- ラベル付き無向木はケーリーの公式N^{N-2}" );
  CERR( "  https://oeis.org/A000272" );
  CERR( "- 各ノードの枝に左右の区別があるNノードN+1葉の二分木や" );
  CERR( "  円上の2N頂点に非交差かつ次数2な無向辺を張って得られる無向グラフは" );
  CERR( "  第Nカタラン数C(N)=(2N)!/((N+1)!N!)" );
  CERR( "  https://ja.wikipedia.org/wiki/カタラン数#カタラン数の意味" );
  CERR( "- なもりグラフはサイクル（N!/(N-C)!）とそれ以外への分割（C^{N-C}）" );
  CERR( "を検討しましょう。" );
}

AC( CountingDirectedGraph )
{
  CERR( "- ラベル付き有向木（根付き木）はケーリーの公式の亜種N^{N-1}" );
  CERR( "  https://oeis.org/A000169" );
  CERR( "- K個のサイクルの和は第1種スターリング数s(N,K)" );
  CERR( "  https://スターリング数#組み合わせ数学における意味" );
  CERR( "を検討しましょう。" );
}

AC( CountingPartitionOfTree )
{
  CERR( "木を受け取る関数fが与えられているとします。" );
  CERR( "" );
  CALL_AC( FunctionOnTree );
  CERR( "F(P)が固定された時のPの数え上げ問題は" );
  CERR( "「第i成分までで切った時のF(P)=vを満たすPの個数dp[i][v]」" );
  CERR( "を管理するi,vに関する動的計画法（O(N^2 v_max×fの計算量)）" );
  CERR( "を検討しましょう。" );
}

AC( CountingSubset )
{
  ASK_NUMBER(
             "要素を受け取る関数の部分和を固定した部分集合の数え上げ問題" ,
             "その他の部分集合の数え上げ問題" ,
             "部分集合への分割の数え上げ問題"
             );
  if( num == num_temp++ ){
    CERR( "要素に番号を振り、集合を配列とみなして部分和問題に帰着させましょう。" );
    CALL_AC( CountingSumFixedSubArray );
  } else if( num == num_temp++ ){
    CERR( "与えられた集合のサイズをNと置きます。" );
    CERR( "- O(2^N)が間に合いそうならば、bit全探策" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "- O(N2^N)が間に合いそうならば、部分集合の包含対のbit全探策" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch\\BitExhausiveSearch" );
    CERR( "を検討しましょう。" );
  } else {
    CERR( "- 任意有限個の部分集合への排他的分割ならばベル数B(N)" );
    CERR( "  https://ja.wikipedia.org/wiki/ベル数" );
    CERR( "- 任意有限個の部分集合への非公差分割や、円上のN頂点の多角形分割や" );
    CERR( "  円上のN+2角形の三角形分割ならば第Nカタラン数C(N)=(2N)!/((N+1)!N!)" );
    CERR( "  https://ja.wikipedia.org/wiki/カタラン数" );
    CERR( "  https://ja.wikipedia.org/wiki/非交差分割" );
    CERR( "- K個の部分集合への排他的分割ならば第2種スターリング数s(N,K)" );
    CERR( "  \\Mathematics\\Combinatorial\\StirlingNumber\\SecondKind" );
    CERR( "  https://ja.wikipedia.org/wiki/スターリング数#組み合わせ数学における意味_2" );
  CERR( "を検討しましょう。" );
  };
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
    CERR( "領域から外に出る経路の数え上げは、出る直前の経路に帰着させましょう。" );
    CERR( "適宜カタラン数やヤング図形との関係も検討しましょう。例えば" );
    CERR( "N×N格子で左下から右上まで対角線を跨がず最初に右へ行く最短経路の個数は" );
    CERR( "第Nカタラン数C(N)=(2N)!/((N+1)!N!)です。" );
    CALL_AC( CountingYoundDiagram );
  } else if( num == num_temp++ ){
    CERR( "ループの不能な有向グラフは整礎なので、各点pごとに" );
    CERR( "-「pが探索されたか」を表すbool値配列" );
    CERR( "-「pへの辺を持つ未探索点の個数」を表す配列" );
    CERR( "を管理し毎回後者を全探策することでO(|V|^2+|E|)で全ての点を探索できます。" );
  }
}

AC( CountingTiling )
{
  ASK_NUMBER(
	     "隣接成分と異なる色で塗り分ける問題" ,
	     "与えられた図形で描画可能になるように塗り分ける問題" ,
	     "与えられた条件に従って塗り分け可能になるように図形で描画する問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( CountingColouringDistinct );
  } else if( num == num_temp++ ){
    CALL_AC( CountingColouringDrawable );
  } else if( num == num_temp++ ){
    CALL_AC( CountingTilingPaintable );
  }
}

AC( CountingColouringDistinct )
{
  CALL_AC( CountingColouring );
  CERR( "- 群の作用による同一視があるならば、コーシー・フロベニウスの補題" );
  CERR( "  https://ja.wikipedia.org/wiki/コーシー・フロベニウスの補題" );
  CERR( "を検討しましょう。" );
}

AC( CountingColouring )
{
  CERR( "- 塗り分ける図形群の外周や頂点に位置する図形やの個数が少ないか" );
  CERR( "  色の種類数が少ないならば、外周や頂点の図形群の塗り分けを固定することで" );
  CERR( "  一廻り小さい図形群に対する数え上げとの関係式を導出し、" );
  CERR( "  サイズに関する動的計画法" );
}

AC( CountingColouringDrawable )
{
  CERR( "描画可能性を簡単な条件に翻訳し、その条件を満たす塗り分けを" );
  CERR( "数え上げましょう。" );
  ASK_YES_NO( "重なりを許して図形を置く描画方法ですか？" );
  if( reply == "y" ){
    CALL_AC( DecisionDrawabilitySameSizeOverdrawn );
  } else {
    CALL_AC( DecisionDrawabilitySameSizeUnoverdrawn );
  }
}

AC( CountingTilingPaintable )
{
  CERR( "塗り分けごとに図形の描画方法が一意に定まるならば、" );
  CERR( "塗り分け方法の同値類として描画方法を数え上げをましょう。" );
  CERR( "- 同値類の要素数が一定ならば単純な商" );
  CERR( "- 群の作用による同一視があるならば、コーシー・フロベニウスの補題" );
  CERR( "  https://ja.wikipedia.org/wiki/コーシー・フロベニウスの補題" );
  CERR( "で商集合を計算しましょう。条件つきの塗り分けは" );
  CERR( "- グリッドの部分集合のマスや辺の塗り分けは、左下から単純な2重ループ" );
  CALL_AC( CountingColouring );
  CERR( "を検討しましょう。" );
}

AC( CountingYoundDiagram )
{
  CERR( "標準ヤングタブローの個数はフック長公式で計算できます。" );
  CERR( "\\Mathematics\\Combinatorial\\YoungDiagram\\a.hpp" );
  CERR( "- 2×Nの標準ヤングタブロー（行／列ともに狭義単調増大になるような番号づけ）" );
  CERR( "  の個数=第Nカタラン数C(N)=(2N)!/((N+1)!N!)" );
  CERR( "- RS対応（型の等しいヤングタブローと順列の対応）" );
  CERR( "  https://en.wikipedia.org/wiki/Robinson%E2%80%93Schensted_correspondence" );
  CERR( "- 半標準ヤングタブローと非交叉なパスの組との対応" );
  CERR( "を検討しましょう。" );
}

AC( CountingParenthesisSequence )
{
  CERR( "2N文字の閉じたカッコ列の個数は第Nカタラン数C(N)=(2N)!/((N+1)!N!)です。" );
}

AC( Solving )
{
  ASK_NUMBER(
	     "１つの方程式f(x,y,...) = c" ,
	     "M個の方程式f(x[a[i]],C^{d[i]}x[b[i]]) = c[i]" ,
	     "M個の方程式sum_{j=a[i]}^{b[i]} C^{j-a[i]} x[j] = c[i]" ,
	     "その他の方程式"
	     );
  if( num == num_temp++ ){
    CERR( "- 楕円型の不定方程式ならば、" );
    CERR( "  - 有界な領域を全探策" );
    CERR( "  - 片方の変数を固定して整数の範囲で実数根の近傍計算" );
    CERR( "- 放物型の不定方程式ならば、平方完成で変数変換して得られる2変数を" );
    CERR( "  掃き出し、１変数ごとに決定" );
    CERR( "- 双曲型の不定方程式ならば、" );
    CERR( "  - 非零定数倍と移項で変数を含む積=定数の形になれば定数の約数列挙" );
    CERR( "  - ならなければペル方程式に帰着" );
    ASK_YES_NO( "f(x,y,...) = h(g(x),g(y),...)の形ですか？" );
    if( reply == "y" ){
      CERR( "f,gを別々に以下の手順で前計算" );
      CERR( "- まず各b in im(g)に対しf(a,b) = cを満たすa in im(g)全体を前計算する。" );
      CERR( "- 次に|dom(g)| = N、max im(g) = Mとして、各y in im(g)に対する" );
      CERR( "  逆像の代表元を管理するg_inv[y]を" );
      CERR( "  - O(N)が間に合いそうならばunordered_map::g_inv[g[x]]=x" );
      CERR( "  - O(M+N)が間に合いそうならば配列::g_inv[g[x]]=x" );
      CERR( "  - x,yに制限h(x)<h(y)がある場合はh(x)の上限cについてループして" );
      CERR( "    g_inv[g(x)]=xしていき、それと並行してyをc<h(y)の範囲で全探索" );
      CERR( "  により管理する。" );
      CERR( "- 最後に各yごとにf(a,g(y)) = cを満たす各a in im(g)に対しa = g(x)を満たす" );
      CERR( "  xをg_inv[a]として与える。" );
      CERR( "を検討しましょう。" );
    }
  } else if( num == num_temp++ ){
    CALL_AC( SolvingBinaryEquations );
  } else if( num == num_temp++ ){
    CERR( "累積和sum_{j=i}^{N} C^{j-i} x[j]を新たに変数X[i]と置くことで" );
    CERR( "M個の方程式X[a[i]]-C^{b[i]-a[i]+1}X[b[i]+1] = c[i]" );
    CERR( "に帰着されます。これはf(x,y)=x-yと置くと" );
    CERR( "M個の方程式f(X[a[i]],d^{b[i]-a[i]+1}X[b[i]+1]) = c[i]" );
    CERR( "に他なりません。" );
    CALL_AC( SolvingBinaryEquations );
  } else if( num == num_temp++ ){
    CERR( "- 単調関数は二分探索" );
    CERR( "- 可微分関数はニュートン法" );
    CERR( "- 連立一次方程式は掃き出し法" );
    CERR( "- 変数の依存関係が閉路を持たないならば逆順に決定" );
    CERR( "を検討しましょう。" );
  }
}

AC( SolvingBinaryEquations )
{
  CERR( "f(x,C^j -)かf(-,C^j y)が単射であるとします。" );
  CERR( "- O(BMf(BN) + BN log B)が間に合いそうならば素集合データ構造" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- O(BM + BN log B)が間に合いそうならば幅／深さ優先探索" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirstSearch" );
  CERR( "- O(Mf(N) + N)が間に合いそうでf(x,y)=x-yかつC=1ならば" );
  CERR( "  ポテンシャル付き素集合データ構造" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "を検討しましょう。" );
}

AC( Query )
{
  ASK_NUMBER(
	     "配列の範囲更新／取得クエリ問題" ,
	     "木の範囲更新／取得クエリ問題" ,
	     "グリッドの範囲更新／取得クエリ問題" ,
	     "一般のグラフの範囲更新／取得クエリ問題" ,
	     "文字列の範囲更新／比較クエリ問題" ,
	     "集合の範囲更新／比較クエリ問題" ,
	     "2変数関数の計算クエリ問題" ,
	     "時系列データのクエリ問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( QueryArray );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTree );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGrid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryGraph );
  } else if( num == num_temp++ ){
    CALL_AC( QueryString );
  } else if( num == num_temp++ ){
    CALL_AC( QuerySet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTwoAryFunction );
  } else if( num == num_temp++ ){
    CALL_AC( QueryTime );
  }
}

AC( QueryArray )
{
  CERR( "配列上のクエリと整合的な代数構造を見付けるためには、" );
  CERR( "区間取得クエリを２つの区間のデータから計算し、必要なデータを特定して" );
  CERR( "それらの演算を計算しましょう。" );
  ASK_NUMBER(
	     "可換群構造+を使う問題" ,
	     "可換羃等モノイド構造∨を使う問題" ,
	     "モノイド構造*を使う問題" ,
	     "非結合的マグマ構造*を使う問題" ,
	     "集合へのマグマ作用(*,\\cdot)を使う問題" ,
	     "集合への可換マグマ作用(*,\\cdot)を使う問題" ,
	     "モノイドへのマグマ作用(+,\\cdot)を使う問題" ,
	     "序数を扱う問題" ,
	     "区間の像の要素数を扱う問題" ,
	     "区間と逆像の共通部分の要素数を扱う問題" ,
	     "2引数関数による区間max／min更新を使う問題" ,
	     "距離関数と定数の和による区間min更新を使う問題" ,
	     "定数とのmaxを取った値の区間演算取得を使う問題" ,
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
    CALL_AC( QueryArrayCommutativeMagmaSet );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMagmaMonoid );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayOrder );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayImageSize );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayInverseImageSize );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxLinearFunction );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMinDistance );
  } else if( num == num_temp++ ){
    CALL_AC( QueryArrayMaxConstant );
  }
}

AC( QueryArrayAbelianGroup )
{
  CERR( "- 加算／全更新後の一点取得O(1)のみが必要ならば階差数列" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- 加算／全更新なしで区間取得O(1)のみが必要ならば累積積" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "- 一点加算O(log N)／一点代入O(log N)／区間取得O(log N)が必要ならばBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "- 区間加算O(log N)／一点代入O(log N)／区間取得O(log N)が必要ならば" );
  CERR( "  区間加算BIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\InteralAdd" );
  CERR( "- 一点加算O(1)／一点代入O(√N)／区間取得O(√N)が必要ならば平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition" );
  CERR( "- 一点加算O(1)／区間加算O(√N)／一点代入O(1)／一点取得O(1)が必要ならば" );
  CERR( "  可換双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "- 一点加算O(1)／区間加算O(√N)／一点代入O(1)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば区間加算平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\IntervalAdd" );
  CERR( "- 区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば区間代入モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "- 区間加算O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば" );
  CERR( "  区間乗算遅延平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation\\IntervalMultiply" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayCommutativeIdempotentMonoid )
{
  CERR( "- 一点乗算O(log N)／一点代入O((log N)^2)／区間取得O(log N)が必要ならば" );
  CERR( "  区間maxBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "- 一点乗算O(1)／区間乗算O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば" );
  CERR( "  可換双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMonoid )
{
  CERR( "- 一点代入O((log N)^2)／区間取得O(log N)が必要ならばモノイドBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\Monoid" );
  CERR( "- 区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば区間代入モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "- 一点乗算O(1)／一点代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば" );
  CERR( "  可換モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\Commutative" );
  CERR( "- 一点乗算O(1)／区間乗算O(√N)／一点代入O(√N)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば区間乗算可換モノイド平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Monoid\\Commutative\\IntervalMultiply" );
  CERR( "- 一点代入O(log N)／区間取得O(log N)が必要ならばセグメント木" );
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
  CERR( "- 区間作用O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayCommutativeMagmaSet )
{
  CERR( "- 区間作用O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual" );
  CERR( "- 一点作用O(1)／区間作用O(√N)／一点代入O(√N)／一点取得O(1)が必要ならば" );
  CERR( "  可換双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\Dual\\Commutative" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMagmaMonoid )
{
  CERR( "- 区間作用O(√N)／区間乗算O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば遅延評価平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayCommutativeMagmaMonoid )
{
  CERR( "- 区間作用O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)が必要ならば" );
  CERR( "  遅延評価平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "- 区間作用O(√N)／区間乗算O(√N)／区間代入O(√N)／一点取得O(1)／区間取得O(√N)" );
  CERR( "  が必要ならば区間乗算遅延評価平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\SqrtDecomposition\\LazyEvaluation" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayOrder )
{
  CERR( "- 始切片内での一点序数取得O(log N)／序数実現値取得O(log N)が必要ならば" );
  CERR( "  右端の大きさでクエリをソートしてBITで像を管理し" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "  - 一点序数取得は平面走査" );
  CERR( "  - 序数実現値取得は平面走査＋二分探索" );
  CERR( "- 区間での序数実現点取得O(ord log N)が必要ならば区間maxBITで" );
  CERR( "  区間最大／最小値＋二分探索で区間を分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\IntervalMax" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayImageSize )
{
  CERR( "区間の像の要素数取得が必要ならば莫のアルゴリズム" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayInverseImageSize )
{
  CERR( "q番目のクエリで共通部分を取る集合をS_qと置きます。" );
  CERR( "- 各iに対するA_iを各qに対するS_qの特性関数たちの値の連想配列で管理し直して、" );
  CERR( "  オフライン累積積で個数取得または莫のアルゴリズムで連想配列の累積和計算" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativePrpdict\\Offline" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "- 各qごとにvector I_qを用意して、各iに対しA_iがS_qに属すなら" );
  CERR( "  I_qにiをpush_backし、I_qと区間の共通部分を二分探索で計算");
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMaxLinearFunction )
{
  CERR( "- 最小値を最大値に帰着させるには、二分探索が不要であればReversed<T>を、" );
  CERR( "  二分探索が不要であれば-1倍を合成しましょう。" );
  CERR( "  \\Utility\\Reverse" );
  CERR( "- 一次関数や支配関係を満たすより一般の2パラメータ関数階層による" );
  CERR( "  全体max更新O(log N)／一点取得O(log N)が必要ならばConvex Hull Trick" );
  CERR( "  \\Mathematics\\Function\\MaxTwoAryHierarchy" );
  CERR( "- 傾きの候補がC個の一次関数による区間min更新O(N^{1/2})／一点取得O(C)が" );
  CERR( "  必要ならば等比数列min更新双対平方分割" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Dual\\GeometricProgressionMin" );
  CERR( "を検討しましょう。" );
}

AC( QueryArrayMinDistance )
{
  CERR( "距離関数と定数の和による区間min更新は傾き±1の一次関数による区間min更新" );
  CERR( "に他なりません。" );
  CALL_AC( QueryArrayMaxLinearFunction );
}

AC( QueryArrayMaxConstant )
{
  CERR( "maxで全体更新をしない場合、つまりただ配列と定数のmaxの区間演算を" );
  CERR( "処理するだけの場合、クエリの順番を入れ替えることで全体更新をする場合に" );
  CERR( "帰着できます。従って以下では全体更新の問題を考えます。" );
  CERR( "" );
  CALL_AC( QueryTimeMax );
}

AC( QueryTree )
{
  CERR( "- 可換群構造に関する加算O(1)／全更新後の一点取得O(1)が必要ならば階差数列" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "- 可換群構造に関する範囲取得O(1)のみが必要ならば累積和" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\Tree" );
  CERR( "- 可換モノイド構造に関する部分木での総乗O(N)が必要ならば全域木DP" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirst\\Tree" );
  CERR( "- モノイド構造に関するパスでの総乗O(log N)が必要ならば重み付きLCA" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirst\\Tree\\Weighted" );
  CERR( "を検討しましょう。" );  
}

AC( QueryGrid )
{
  CERR( "- 可換群構造に関する加算O(1)／全更新後の一点取得O(1)が必要ならば二次元階差数列" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "- 可換群構造に関する加算O(1)／全更新なしの矩形取得O(1)が必要ならば二次元累積和" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\TwoDimentioal" );
  CERR( "- 可換群構造に関する加算O(1)／全更新後の矩形取得O(1)が必要ならば二次元階差数列と" );
  CERR( "  二次元累積和の併用" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence\\TwoDimentioal" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct\\TwoDimentioal" );
  CERR( "- 差分計算が高速に可能ならば莫のアルゴリズム" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "を検討しましょう。" );
}

AC( QueryGraph )
{
  CERR( "グラフの頂点数をV、辺の本数をE、クエリ数をQと置きます。" );
  CERR( "- 辺の追加でO(V+(E+Q)α(V))が間に合いそうならばUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- 辺の削除でO(V+Eα(V))が間に合いそうならばクエリ逆読みのUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- 特定の辺を含む最小全域森取得でO((V+Q)log V + E log E)が間に合いそうならば" );
  CERR( "  全体に対する最小全域森をクラスカル法で前計算し重み付きLCAによる" );
  CERR( "  最大コスト辺計算" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\DepthFirst\\Tree\\Weighted" );
  CERR( "- 辺集合の彩色を変えた最小全域森取得でO(V + E log E + Qα(V))が間に合いそう" );
  CERR( "  ならば全体に対する辺のソートを前計算しクラスカル法の反復" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest\\Kruscal" );
  CERR( "を検討しましょう。" );  
}

AC( QueryString )
{
  CERR( "文字列の一点更新（一文字更新）／結合／比較はローリングハッシュ" );
  CERR( "\\Utility\\String\\RollingHash" );
  CERR( "でコード化し、追加で更新クエリ／取得クエリを" );
  CERR( "- 左端からの連続部分文字列も管理する場合の一点更新は文字列の累積コードを" );
  CERR( "  区間加算BITに乗せて終切片加算と始切片和取得（O(log N)/O(log N)）で処理" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\IntervalAdd" );
  CERR( "- 連続部分文字列も管理する場合、" );
  CERR( "  - ハッシュと公比の冪乗は可換群" );
  CERR( "  - コードは非可換群" );
  CERR( "  を用いることに注意して" );
  CERR( "  - 一点更新のみが必要ならば" );
  CERR( "    - 文字列の各文字のハッシュと公比の冪乗の積を" );
  CERR( "      - BITに乗せて一点更新と区間和取得（O(log N)/O(log N)）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT" );
  CERR( "      - セグメント木に乗せて一点更新と区間和取得（O(log N)/O(log N)）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SegmentTree" );
  CERR( "      - 平方分割に乗せて一点更新と区間和取得（O(1)/O(N^{1/2})）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition" );
  CERR( "      で処理" );
  CERR( "    - 文字列の各文字のコードを" );
  CERR( "      - セグメント木に乗せて一点更新と区間積取得（O(log N)/O(log N)）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SegmentTree" );
  CERR( "      - モノイド平方分割に乗せて一点更新と区間積取得（O(1)/O(N^{1/2})）" );
  CERR( "        \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Monoid" );
  CERR( "      で処理" );
  CERR( "  - 区間代入更新も必要ならば文字列の各文字のコードを" );
  CERR( "    - 遅延セグメント木に乗せて区間代入更新と区間積取得（O(log N)/O(log N)）" );
  CERR( "    - 区間代入モノイド平方分割に乗せて区間代入更新と区間積取得（O(N^{1/2})/O(N^{1/2})）" );
  CERR( "      \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Monoid\\IntervalSet" );
  CERR( "    で処理" );
  CERR( "を検討しましょう。" );
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

AC( QueryTwoAryFunction )
{
  CERR( "- 可換群に値を持つ配列の範囲取得は累積積" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProduct" );
  CERR( "- 片側差分がO(1)で計算できる2変数関数の計算は莫のアルゴリズム" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
  CERR( "を検討しましょう。" );
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
	     "全体max更新／区間和取得" ,
	     "範囲max更新／一点取得"
	     );
  if( num == num_temp++ ){
    CERR( "全体max更新クエリと区間和取得クエリを時系列順に並べ番号を振ります。" );
    CERR( "これにより配列の特定時刻での区間和を求める問題に帰着され、" );
    CERR( "合計O((N + Q)log N + Q log Q)で処理できます。" );
    CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\BIT\\TimeSeriesSetMax" );
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
  CERR( "各成分を時刻の関数とみなした時、グラフがO(N)個の単純なパーツに分かれるとします。" );
  CERR( "各パーツでの変化量の累積値を" );
  CERR( "- 階差数列や累積和やBIT" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\DifferenceSeqeuence" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\CumulativeProd" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT" );
  CERR( "- イベントソート" );
  CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\BIT\\TimeSeriesAdd" );
  CERR( "で計算しましょう。" );
}

AC( Game )
{
  ASK_NUMBER(
	     "勝敗を決める2人ゲーム" ,
	     "最終的な不変量の最大化と最小化を先行と後行が目指す2人ゲーム"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( MaximisationGame );
  }
}

AC( Decision )
{
  CERR( "場合分けの複雑な問題は証明の概略をコメントしないとバグを倦めやすいです。" );
  CERR( "なるべくコメントを書くようにしましょう。" );
  ASK_NUMBER(
	     "必勝性問題" ,
	     "連結性問題" ,
	     "到達可能性問題" ,
	     "描画可能性問題" ,
	     "存在判定問題" ,
	     "充足可能性問題" ,
	     "一致判定問題" ,
	     "表示可能性問題"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionConnectedness );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionDrawability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionExistence );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionSatisfiability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionCoincidence );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  }
}

AC( DecisionGame )
{
  ASK_NUMBER(
	     "操作の継続を目指すゲーム" ,
	     "最終局面での不変量の偶奇を指定するゲーム" ,
	     "得点の大小を競うゲーム"
	     );
  if( num == num_temp++ ){
    CALL_AC( DecisionContinuingGame );
    CALL_AC( DecisionContinuingGameCheck );
  } else if( num == num_temp++ ){
    CERR( "dp[t] = 初期状態tから確実に最終局面での不変量の値にできる数値の全体集合" );
    CERR( "と定めてtに関する動的計画法を検討し、必要ならばその実験結果から" );
    CERR( "規則を見付けたりデータ構造高速化を行いましょう。" );
    CERR( "\\Mathematics\\Game" );
    CALL_AC( DecisionContinuingGameCheck );
  } else if( num == num_temp++ ){
    ASK_YES_NO( "操作回数が少なく勝敗がつきそうですか？" );
    if( reply == "y" ){
      CERR( "局面の対称性などに注目して同値な局面を同一視し、" );
      CERR( "それぞれについてしらみ潰しに勝敗を考察してみましょう。" );
    } else {
      CERR( "２プレイヤーの得点差を１つの不変量とみなし、その最大化を行って" );
      CERR( "正負を判定しましょう。" );
      CALL_AC( MaximisationGame );
    }
  }
}

AC( DecisionContinuingGame )
{
  CERR( "ゲーム問題ライブラリとOEISの活用を忘れないように気を付けましょう。" );
  CERR( "\\Mathematics\\Game" );
  CERR( "https://oeis.org/?language=japanese" );
  ASK_YES_NO( "入力の個数は一定ですか？" );
  if( reply == "y" ){
    CERR( "まず愚直解を動的計画法で書いて実験し、勝敗の規則を見付けましょう。" );
    CERR( "デバッグモードで勝敗を計算する際は実験の出力と混ざらないように" );
    CERR( "勝敗を配列に格納してから配列を出力しましょう。" );
    CERR( "" );
    CERR( "規則性が見付からない時は、" );
    CERR( "- 連続して選択できない操作は複数ターンまとめて処理することで" );
    CERR( "  変数の少ない動的計画法に翻訳" );
    CERR( "- 愚直解またはその少変数化における動的計画法のデータ構造高速化" );
    CERR( "- 必勝状態に対応する変数列のOEIS検索やサンプル解析" );
  } else {
    CERR( "まずゲームをなるべく簡単な設定に同値変形しましょう。" );
    CERR( "- 単調増大列は階差を取りましょう。" );
    CERR( "- 数列で１成分を更新したり末尾追加したりするだけなら和に分解しましょう。" );
    CERR( "- 良い不変量を探し、不変量を変えないような応酬が可能な操作を無視することで" );
    CERR( "  不変量の推移のみを観察しましょう。例えば以下の不変量に注目しましょう。" );
    CERR( "  - 何らかの数値の適当な法での値" );
    CERR( "  - 特定の二部マッチング上での各組内での何らかの数値（到達個数など）の偶奇" );
    CERR( "    - グリッドで、１回の移動で移り合える２マスの組によるタイリング" );
    CERR( "    - 配列で、１回の操作で影響を受ける成分が常に２個ならば、そのような" );
    CERR( "      ２成分ずつによるタイリング" );
    CERR( "  - ある成分を無視する同値関係での剰余類" );
    CERR( "  - 既に得られている不変量を変えない操作で応酬できる操作を無視する同値関係" );
    CERR( "その後、ゲームの性質に注目して典型考察に帰着させましょう。" );
  }
  CERR( "- ゲームの和に分解できるならばグランディ数を計算、" );
  CERR( "  できないならば必勝状態判定" );
  CERR( "  - 状態数や遷移回数上限が少ないならば、グランディ数や必勝状態判定を再帰で" );
  CERR( "    計算しましょう" );
  CERR( "  - ゲームの状態遷移の全探策が自動化できそうならば、" );
  CERR( "    整礎構造を探して順序数の小さい順に実験をし、" );
  CERR( "    OEISを用いてグランディ数や必勝状態判定を推測しましょう。" );
  CERR( "  - ゲームの状態遷移の全探索が自動化できなさそうならば、手計算での実験だと" );
  CERR( "    考察漏れが生じやすいので他の考察を優先しましょう。" );
  CERR( "- 先手しか可能でない遷移であって他のどの遷移へも経由できるものがあるならば" );
  CERR( "  strategy-stealing argument" );
  CERR( "  https://en.wikipedia.org/wiki/Strategy-stealing_argument" );
  CERR( "- 後手が先手の選択を反復できるならば、反復戦略" );
  CERR( "- ゲームの状態に全順序構造があり勝敗が十分長い区間で一定ならば、" );
  CERR( "  勝敗で区間を連結成分に分解" );
  CERR( "を検討しましょう。" );
}

AC( DecisionContinuingGameCheck )
{
  CERR( "実装ミスだけでなく考察ミスもしやすいので、サンプルが通ってもWAとなったら" );
  CERR( "即座に愚直解との比較を試みましょう。" );
}

AC( DecisionConnectedness )
{
  CERR( "- 無向グラフの弧状連結性は幅優先探索やUnionFind" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\BreadthFirstSearch" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\UnionFindForest" );
  CERR( "- 有向グラフの強連結性は深さ優先探索による強連結成分分解" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\StrongConnectedComponent" );
  CERR( "- 無向グラフの高次ホモロジー計算は実数や適当な法での掃き出し法" );
  CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Mod" );
  CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\Real" );
  CERR( "を検討しましょう。" );
}

AC( DecisionAccessibility )
{
  CERR( "移動の前後で変化しない値がある場合、その値が等しい点に絞って考えましょう。" );
  CERR( "コストのパリティに制限がある場合は往復による調整を検討しましょう。" );
  ASK_NUMBER(
	     "矩形領域の到達可能性（迷路）問題" ,
	     "グラフ上の到達可能性問題" ,
	     "全頂点訪問可能性問題"
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
    CERR( "- 再来訪を許容しないならば、" );
    CERR( "  - 非輪状有向グラフでかつO(V+E)が間に合いそうならば、" );
    CERR( "    トポロジカルソートして始点が先頭にあるかとソート順に遷移可能かで判定" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Acyclic\\HamiltonPath" );
    CERR( "  - 領域と移動に対称性があるならば、タイリングと二部マッチングによる反復戦略" );
    CERR( "  - O(V^2 2^V)が間に合いそうならば、ヘルドカープ法" );
    CERR( "    \\Mathematics\\Geometry\\Graph\\Algorithm\\HeldKarp" );
    CERR( "- 再来訪を許容しO(V+E)が間に合いそうならば、強連結成分分解して" );
    CERR( "  非輪状有向グラフで再来訪を許容しない場合に帰着" );
    CERR( "  \\Mathematics\\Geometry\\Graph\\Acyclic\\StrongConnectedComponent\\HamiltonWalk" );
    CERR( "を検討しましょう。" );
  }
  CERR( "" );
}

AC( DecisionDrawability )
{
  CERR( "まずは描画領域内にどのように図形を置くかを決定しましょう。" );
  ASK_YES_NO( "図形を置く際に重なりを許しますか？" );
  if( reply == "y" ){
    ASK_NUMBER(
	       "平行移動のみを除いて単一の図形を置く問題" ,
	       "平行移動とサイズ変更のみを除いて単一の図形を置く問題" ,
	       "複数種類の同一サイズの図形を許して置く問題"
	       );
    if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilityUnique );
    } else if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilityExtension );
    } else if( num == num_temp++ ){
      CALL_AC( DecisionDrawabilitySameSizeOverdrawn );
    }
  } else {
    CALL_AC( DecisionDrawabilitySameSizeUnoverdrawn );
  }
}

AC( DecisionDrawabilityUnique )
{
  CERR( "図形を必要ならば回転させた上で、図形をいくつかの矩形領域の和集合に分解し" );
  CERR( "描画領域内に図形を置けるか否かを図形の位置ごとに２次元累積和や" );
  CERR( "２次元高階階差数列などで判定しましょう。" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\CumulativeProduct\\TwoDimensional" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DifferenceSequence\\TwoDimensional" );
  CERR( "" );
  CALL_AC( DecisionImageCoincidence );
}

AC( DecisionDrawabilityExtension )
{
  CERR( "描画領域内に図形を置けるサイズの最大値を図形の位置ごとに尺取り法などで" );
  CERR( "前計算し、最大サイズで置くことを考えましょう。" );
  CERR( "" );
  CALL_AC( DecisionImageCoincidence );
}

AC( DecisionDrawabilitySameSizeOverdrawn )
{
  CERR( "正整数Bと描画領域の同値関係であって以下の2条件を満たすものを探しましょう。" );
  CERR( "- どのように図形を置いてもその図形がmod Bで等サイズの図形に分割される。" );
  CERR( "- 商の配色ベクトルmod Bを管理することで得られる必要条件が十分条件でもある。" );
}

AC( DecisionDrawabilitySameSizeUnoverdrawn )
{
  CERR( "可換モノイドGと描画領域の商集合Xとモノイド準同型f:N^X->Gであって" );
  CERR( "どのように図形を置いてもその図形の商の濃度ベクトルのfでの値が" );
  CERR( "一定値cであるものを探しましょう。" );
  CERR( "するとXの濃度ベクトルのfでの値Cが(図形を置く個数)cで表せることが" );
  CERR( "必要条件となります。例えば" );
  CERR( "- Gが群かつC=0かつ(図形を置ける個数)がcの位数の倍数になりえない。" );
  CERR( "- GがNかつ(図形を置ける個数の最大値)cがC未満である。" );
  CERR( "- GがNかつ(図形を置ける個数の最小値)cがCより大きい。" );
  CERR( "などの場合はこの必要条件が成り立たないので塗り分け不可能です。" );
}

AC( DecisionImageCoincidence )
{
  CERR( "描画領域内にどのように図形を置くかを決めた後は２次元階差数列などで" );
  CERR( "実際に描画をし、描画したい図形と一致するかを判定しましょう。" );
  CERR( "\\Mathematics\\SetTheory\\DirectProduct\\AffineSpace\\DifferenceSequence\\TwoDimensional" );
}

AC( DecisionExistence )
{
  ASK_NUMBER(
	     "数の方程式の解の存在" ,
	     "F_2上の方程式の解の存在" ,
	     "単純な条件を満たす数や配列や文字列の存在" ,
	     "動く範囲の狭い変数の組み合わせで表せる概念の存在" ,
	     "経路の存在" ,
	     "描画方法の存在" ,
	     "数やベクトルの表示方法の存在" ,
	     "集合の分割方法の存在"
	     );
  if( num == num_temp++ ){
    CALL_AC( Solving );
    CERR( "" );
    CERR( "方程式の数が足りない代わりに変域に制限がある場合、確定しない変数xを用いて" );
    CERR( "他の変数を表し、各方程式をxの不等式に翻訳して変域の非空判定をしましょう。" );
  } else if( num == num_temp++ ){
    CERR( "bool値の方程式は命題の充足可能性に帰着させましょう。" );
    CALL_AC( DecisionSatisfiability );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionArray );
  } else if( num == num_temp++ ){
    CERR( "変数の組み合わせで表して全探策を検討しましょう。" );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionAccessibility );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionDrawability );
  } else if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionPartition );
  }
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
    CERR( "ホップクロフトカープ法や最大流" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\HopcroftKarp" );
    CERR( "\\Mathematics\\Geometry\\Graph\\Algorithm\\MaximumFlow" );
    CERR( "を検討しましょう。" );
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
  ASK_NUMBER(
	     "単一の演算による表示可能性（生成部分マグマ問題）" ,
	     "複数の演算による表示可能性（テンパズル問題）"
	     );
  if( num == num_temp++ ){
    CERR( "半群の要素は、加素元からなる極小生成系の要素の和で表せます。" );
    CERR( "- 加素元の和で表すならば、半群が方程式の解空間で与えられる場合には" );
    CERR( "  Qの直和に埋め込めば解の1/nも解であることに着目し、整数の範囲での商を" );
    CERR( "  うまく端数を揃えて解を構成できるかもしれません。" );
    CERR( "- 数を素数の和で表すならば、Klove数列で必要な素数の個数を見積りましょう。" );
    CERR( "  Mathematics\\Arithmetic\\Prime\\KloveSequence\\a.hpp" );
    CERR( "- 数を多角数の和で表すならば、二平方定理などを参考にしましょう。" );
    CERR( "  https://ja.wikipedia.org/wiki/二個の平方数の和#素数についての証明" );
    CERR( "  https://ja.wikipedia.org/wiki/三個の平方数の和#証明" );
    CERR( "  https://ja.wikipedia.org/wiki/四平方定理#ラグランジュの四平方定理の証明" );
    CERR( "  https://ja.wikipedia.org/wiki/多角数定理#証明" );
    CERR( "- 数をXORで表すならば、" );
    CERR( "  - 一般の数を表すならば拡大係数行列の簡約化" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\BitSet" );
    CERR( "  - 0を非自明なXORで表すならば一次独立性判定" );
    CERR( "  \\Mathematics\\LinearAlgebra\\Rank\\BitSet" );
  } else if( num == num_temp++ ){
    CERR( "- 左結合的に関数／演算を処理する場合は" );
    CERR( "  「第i成分／文字までで打ち切った時に表現できるもの全体の集合dp[i]」" );
    CERR( "  を管理するiに関する動的計画法" );
    CERR( "- 関数／演算の適用方法にも選択がある場合は2項を選んで適用させた" );
    CERR( "  結果得られる数／文字列の再帰的な全探策" );
  }
  CERR( "を検討しましょう。" );
}

AC( Construction )
{
  CERR( "存在定理に帰着できる問題は構成的証明を実装しましょう。" );
  CERR( "入力に関して再帰的に構築する方法を探すために、入力制約より一般化して" );
  CERR( "（例えば多変数化して）考察し、小さいケースの実験をしましょう。" );
  ASK_NUMBER(
	     "数やベクトルに関する構築" ,
	     "配列や文字列に関する構築" ,
	     "写像の構築" ,
             "グラフ上の操作の構築" ,
	     "戦略の構築" ,
             "集合に関する構築" ,
	     "ソースコードの構築"
	     );
  if( num == num_temp++ ){
    CALL_AC( ConstructionNumber );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionArray );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionMap );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionOperationOnGraph );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionStrategy );
  } else if( num == num_temp++ ){
    CALL_AC( ConstructionSet );
  } else if( num == num_temp++ ){
    CERR( "正解を出力をするソースコードを提出しましょう。" );
  }
}

AC( ConstructionNumber )
{
  ASK_NUMBER(
	     "数や固定長ベクトルの表示方法の構築" ,
	     "方程式の解の構築"
             );
  if( num == num_temp++ ){
    CALL_AC( DecisionPresentability );
  } else {
    CALL_AC( Solving );
  }
}

AC( ConstructionArray )
{
  ASK_NUMBER(
	     "条件を満たす配列や文字列の構築" ,
	     "与えられた配列や文字列の条件を満たす部分列の構築"
             );
  if( num == num_temp++ ){
    CERR( "- １つの配列の構成は、p進法や階差数列への翻訳を検討しましょう。" );
    CERR( "- 何らかの関数値が一致する２つの配列の構成は、鳩の巣原理をもとに" );
    CERR( "  動かすパラメータを設定し、全探策を検討しましょう。" );
  } else {
    CALL_AC( ConstructionPartition );
  }
}

AC( ConstructionMap )
{
  CERR( "- 単射の構築にはHallの結婚定理" );
  CERR( "  https://ja.wikipedia.org/wiki/ホールの定理" );
  CERR( "- 全単射の構築にはホップクロフトカープ法やカントールベルンシュタインの定理" );
  CERR( "  \\Mathematics\\Geometry\\Graph\\Algorithm\\HopcroftKarp" );
  CERR( "  https://ja.wikipedia.org/wiki/ベルンシュタインの定理#証明" );
  CERR( "- 全射の構築には部分集合を制限して全単射の構築の反復" );
  CERR( "を検討しましょう。" );
}

AC( ConstructionOperationOnGraph )
{
  ASK_NUMBER(
	     "最短経路の構築" ,
	     "最長経路の構築" ,
	     "グリッド操作の構築"
	     );
  if( num == num_temp++ ){
    CERR( "最短経路探索アルゴリズムで経路復元をしましょう。" );
    CALL_AC( MinimisationMovingCost );
  } else if( num == num_temp++ ){
    CERR( "最長経路探索アルゴリズムで経路復元をしましょう。" );
    CALL_AC( MaximisationMovingDistanceSingleStart );
  } else {
    CERR( "- HWが小さいケースを手作業または全探策で求めて、" );
    CERR( "  一般のHWは小さいケースの反復" );
    CERR( "- 規則的な操作を(mod H,mod W)し、適宜unordered_set<T2<int>>で" );
    CERR( "  重複管理し重複時にはずらす" );
    CERR( "- グリッド上の巡回セールスマン問題に対するヒューリスティック解の構築は" );
    CERR( "  莫のアルゴリズムによるソート" );
    CERR( "  \\Mathematics\\SetTheory\\DirectProduct\\AfineSpace\\SqrtDecomposition\\Mo" );
    CERR( "を検討しましょう。" );
  }
}

AC( ConstructionStrategy )
{
  ASK_NUMBER(
	     "必勝戦略の構築" ,
	     "最大化戦略の構築"
             );
  if( num == num_temp++ ){
    CALL_AC( DecisionGame );
  } else {
    CALL_AC( ConstructionMaximisation );
  }
}

AC( ConstructionMaximisation )
{
  CERR( "最終的な不変量を最大化するためには、操作の整礎な変形手順であって" );
  CERR( "値を減らさないものを探し、その変形を完全に行って得られる操作のみに" );
  CERR( "絞って考えましょう。その変形によって貪欲な操作が可能であれば" );
  CERR( "貪欲法で解くことが可能です。" );
  CERR( "" );
  CALL_AC( Maximisation );
}

AC( ConstructionSet )
{
  ASK_NUMBER(
	     "与えられた二部グラフの部分集合の構築" ,
	     "与えられた集合の分割方法の構築"
             );
  if( num == num_temp++ ){
    CALL_AC( ConstructionSubset );
  } else {
    CALL_AC( ConstructionPartition );
  }
}

AC( ConstructionSubset )
{
  CERR( "連結二部グラフ(S,T)と、s in SとTの部分集合T0に関する条件P(s,T0)であって" );
  CERR( "- 任意のs in SとTの部分集合T0とd(s,t)=1を満たすt in T0に対し、" );
  CERR( "  P(s,T0)<=>!P(s,T0-{t})である。" );
  CERR( "を満たすものが与えられているとして、" );
  CERR( "- 任意のs in U cap Sに対し、P(s,U cap T)である。" );
  CERR( "を満たすS cup Tの部分集合Uで濃度が補集合以上であるものの構築を考えます。" );
  CERR( "" );
  CERR( "Tを整列させ、各s in Sに対しd(s,t)=1を満たす最大のt in Tをf(s)と置きます。" );
  CERR( "Uを{}で初期化してt in Tの小さい順に" );
  CERR( "- {s in f^{-1}(t)|P(s,U cap T)}" );
  CERR( "- {s in f^{-1}(t)|P(s,(U cap T) cup {t})} cup {t}" );
  CERR( "のうち濃度が小さくない方の各要素をUに追加します。fの逆像はSの排他的被覆を" );
  CERR( "与えるので、最終的なUの濃度は補集合以上になります。" );
}

AC( ConstructionPartition )
{
  CERR( "集合や文字列や配列の分割は写像の一種です。" );
  AC( ConstructionMap );
}

AC( Deduction )
{
  CERR( "リアクティブ問題で質問をする際は" );
  CERR( "- 何らかの順序における極大元に触れる聞き方" );
  CERR( "- なるべく多くの数値に依存する情報に触れる聞き方" );
  CERR( "- N^2個の数値に対するO(N)回の質問では対角線に触れる聞き方" );
  CERR( "を検討しましょう。" );
}

