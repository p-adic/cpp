// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Sqrt/a.hpp

#pragma once

class SqrtDecompositionCoordinate
{

protected:
  int m_N;
  int m_N_sqrt;
  // m_N / m_N_sqrt ˆÈã‚Å‚ ‚éÅ¬‚Ì®”B
  int m_N_d;
  // m_N ˆÈã‚Å‚ ‚éÅ¬‚Ì m_N_sqrt ‚Ì”{”B
  int m_N_m;

public:
  inline SqrtDecompositionCoordinate( const int& N = 0 );
  inline SqrtDecompositionCoordinate( const int& N , const int& N_sqrt );

  // 2æ‚ªNˆÈã‚Å‚ ‚éÅ¬‚Ì³®”‚ğ•Ô‚·B
  static inline int Sqrt( const int& N ) noexcept;

};
