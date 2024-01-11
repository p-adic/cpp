// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/FloydWarshall/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942861（経路復元なし）

// weightに値を格納する関係で、dを関数テンプレートで置き換えてもメモリ削減は見込めない。

// M_Tは乗算m_T:T \times T->Tに相当する型。
// A_Tはmeet a_T:T \times T->Tに相当する型。

// 入力の範囲内で要件
// (1) (T,a_T:T^2->T)がmeet半束（可換羃等半群）である。
//     （以下a_Tの定める等号つき半順序を<=と置く）
// (2) (T,m_T:T^2->T)が半群である。
// (3) m_Tがa_T上分配的、つまり
//     - Tの任意の要素s,t,uに対し
//       - m_T(u,a_T(s,t)) = a_T(m_T(u,s),m_T(u,t)) 
//       - m_T(a_T(s,t),u) = a_T(m_T(s,u),m_T(t,u))
//     である。
// (4) inftyでないdの値はnon-negative、つまり
//     - Tの任意の要素sとinftyでないdの任意の値tに対し
//       - s<=m_T(s,t) 
//       - s<=m_T(t,s)
//     である。
// (5) inftyでないdの値size_max個以下のm_Tに関する積でinftyが表せない。
// が成り立つ場合にのみサポート。

// ただし<=が等号つき全順序である場合、(3)は
// (3)' m_Tが<=に関する半順序半群演算、つまり
//     - Tの任意の要素s,t,uに対しs<=tならば
//       - m_T(u,s) <= m_T(u,t) 
//       - m_T(s,u) <= m_T(t,u)
//     である。
// と同値であることに注意。

// O(size_max^3)で全経路の重み（edgeごとの重みのm_Tに関する積）の
// a_Tに関する下限（多変数化したa_Tへの適用値）を計算。
template <typename T , typename M_T , typename A_T>
void FloydWarshall( M_T m_T , A_T a_T , const vector<vector<T>>& d , vector<vector<T>>& weight , const T& infty );


// 入力の範囲内で要件
// (1)' bool operator<(const T&,const T&)が全順序である。
//     （以下<の定める等号つき全順序を<=と置く）
// (2) (T,m_T:T^2->T)が半群である。
// (3)' m_Tが<=に関する半順序半群演算、つまり
//     - Tの任意の要素s,t,uに対しs<=tならば
//       - m_T(u,s) <= m_T(u,t) 
//       - m_T(s,u) <= m_T(t,u)
//     である。
// (4) inftyでないdの値はnon-negative、つまり
//     - Tの任意の要素sとinftyでないdの任意の値tに対し
//       - s<=m_T(s,t) 
//       - s<=m_T(t,s)
//     である。
// (5) inftyでないdの値size_max個以下のm_Tに関する積でinftyが表せない。
// が成り立つ場合にのみサポート。

// O(size_max^3)で各２点間の最短経路を１つずつ計算。path[i][j]には、
// 固定した最短経路i->jで経由する１点があればその値、なければ-1を格納。
template <typename T , typename M_T>
void FloydWarshall( M_T m_T , const vector<vector<T>>& d , vector<vector<T>>& weight , const T& infty , vector<vector<int>>& path );

