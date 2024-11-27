// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Optimisation/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../Sqrt/a.hpp"

// FUNCは写像N->Uに相当する型。

// 入力の範囲内で要件
// (1) operator<(const U&,const U&)は全順序である。
// を満たす場合にのみサポート。

// funcの最小値の候補をO(N^{1/2})で求める。
// 例えばU=Zでfuncが近似的に単調な関数の絶対値である場合に精度がよくなる。
class SqrtDecompositionOptimisation :
  public SqrtDecompositionCoordinate
{

private:
  vector<int> m_rand;
  
public:
  template <typename...Args> inline SqrtDecompositionOptimisation( const int& N = 0 , const Args&... args );
  
  template <typename...Args> inline void Initialise( const Args&... args );

  template <typename FUNC> int Minimise( FUNC& func );
  
};
