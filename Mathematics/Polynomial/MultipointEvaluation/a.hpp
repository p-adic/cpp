// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/937654（多点評価）

// 以下、次数をDとし、次数打ち切り評価点の個数をMとする。

// SetPartialFractionDecompositionで空でない多項式列に多点評価の値をpush_backするので
// SetMultipointEvaluationはvector<T>を返す関数にしない。

// pointの各成分pに対するf(p)の値をanswerに格納する。（O((D log D)+(M(log M)^2))）
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> inline void SetMultipointEvaluation( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer );

// 各pに対する（順序なし）差積Π_{p' in point-{p}}(p-p')を計算する。（O(M(log M)^2)）
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> void SetDifferenceProduct( const V1<T>& point , V2<T>& answer );

// pointに重複がなくかつD<Mである場合にf(x)/Π(x-p)の部分分数分解の1/(x-p)の係数を
// answerに格納する。（O((D log D)+(M(log M)^2)) = O(M(log M)^2)）
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> void SetPartialFractionDecomposition( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer );
// pointに重複がない場合にf(x) ≡ h(x)/Π(x-p) mod x^{M+1}かつdeg(h(x)) <= Mを満たす唯一の
// 多項式h(x)に対するh(x)/Π(x-p)の部分分数分解の定数項と1/(x-p)の係数をanswerに格納する。
// （O(D + M(log M)^2)）
template <typename T , template <typename...> typename V1 , template <typename...> typename V2> void SetPartialFractionDecomposition( const uint& N , Polynomial<T> f , const V1<T>& point , V2<T>& answer );
