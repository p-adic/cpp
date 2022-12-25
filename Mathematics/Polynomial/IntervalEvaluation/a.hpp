// c:/Users/user/Documents/Programming/Mathematics/Polynomial/IntervalEvaluation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// deg < eval.size()の時のみサポート
// f(0),f(1),...,f(deg)がeval[0],eval[1],...,eval[deg]に等しいdeg次以下の多項式fに対し、
// f(t_start),f(t_start+1)...,f(t_start+length-1)をevalに格納し直す。
template <typename T>
void SetIntervalEvaluation( const uint& deg , const T& t_start , const uint& length , vector<T>& eval );

// deg < sample.size()の時のみサポート
// M(0),M(1),...,M(deg)がsample[0],sample[1],...,sample[deg]に等しいdeg次以下の多項式係数行列Mに対し、
// M(t_start),M(t_start+1)...,M(t_start+length-1)をevalに格納する。
template <uint Y , uint X , typename T>
void SetIntervalEvaluation( const uint& deg , const T& t_start , const uint& length , const vector<Matrix<Y,X,T> >& sample , vector<Matrix<Y,X,T> >& eval );

// Tがlength以下の正整数を可逆にする体である場合のみサポート
// M(length-1) ... M(1) M(0) vの計算結果をvに格納し直す。
template <uint Y , typename T>
void SetPRecursiveMatrixAction( const Matrix<Y,Y,Polynomial<T> >& M , Matrix<Y,1,T>& v , const uint& length );
