// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/FloydWarshall/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/a.hpp"

// verify:
// https://yukicoder.me/submissions/946106（経路復元なし）

// weightに値を格納する関係で、dを関数テンプレートで置き換えてもメモリ削減は見込めない。

// 入力の範囲内で要件
// (1) RはUの非単位的半環構造で加法が冪等的なもの。つまり
//   (1-1)加法∧についてmeet半束（可換羃等半群）である。
//   (1-2)乗法*について半群である。
//   (1-3)乗法が加法に対し分配的である。
//   を満たす。以下∧の定める等号つき半順序を<=と置き、∧に関する単位元をinftyと置く。
// (2) dの値はRの乗法に関してnon-negative、つまり
//     - Uの任意の要素sとdの任意の値tに対し
//       - s<=s*t
//       - s<=t*s
//     である。
// (3) inftyでないdの値size個以下のRに関する積でinftyが表せない。
// が成り立つ場合にのみサポート。

// ただし<=が等号つき全順序である場合、(1-3)は
// (1-3)' *が<=に関する半順序半群演算、つまり
//     - Uの任意の要素s,t,uに対しs<=tならば
//       - u*s <= u*t
//       - s*u <= t*u
//     である。
// と同値であることに注意。

// O(size^3)で全経路の乗法的重み（edgeごとの重みのRに関する積）の
// ∧に関する下限（多変数化した∧への適用値）を計算。
template <typename U , typename IDEMPOTENT_SEMIRNG>
void FloydWarshall( IDEMPOTENT_SEMIRNG R , const vector<vector<U>>& d , vector<vector<U>>& weight );

// 入力の範囲内で要件
// (1)' Rはbool operator<(const U&,const U&)に関するminトロピカル非単位的半環である。つまり
//   (1-1)' <が最大元inftyを持つ全順序である。
//     （以下<の定める等号つき全順序を<=と置く）
//   (1-2)' Rの乗法*が半群演算である。
//   (1-3)' *が<=に関する半順序半群演算、つまり
//     - Uの任意の要素s,t,uに対しs<=tならば
//       - u*s <= u*t
//       - s*u <= t*u
//   である。
// (2) dの値はRの乗法に関してnon-negative、つまり
//     - Uの任意の要素sとdの任意の値tに対し
//       - s<=s*t
//       - s<=t*s
//     である。
// (3) inftyでないdの値size個以下のRに関する積でinftyが表せない。
// が成り立つ場合にのみサポート。

// O(size^3)で各２点間の最短経路を１つずつ計算。path[i][j]には、
// 固定した最短経路i->jで経由する１点があればその値、なければ-1を格納。
template <typename U , typename TROPICAL_SEMIRNG>
void FloydWarshall( TROPICAL_SEMIRNG R , const vector<vector<U>>& d , vector<vector<U>>& weight , vector<vector<int>>& path );
