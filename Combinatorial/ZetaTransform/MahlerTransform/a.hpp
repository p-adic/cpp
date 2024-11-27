// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/MahlerTransform/a.hpp

#pragma once

// N_max > 0の場合のみサポート。
template <int N_max>
class MahlerTransform
{
private:
  const int m_p;
  ll m_fact[N_max];
  ll m_fact_inv[N_max];
  ll m_inv[N_max];

public:
  // pがN_max以上の素数である場合のみサポート。
  // O(N_max)で前計算値を格納する。
  inline MahlerTransform( const int& p );

  // 0 <= i_start <= i_final < N_maxの場合のみサポート。
  // O((i_final-i_start)^2)で(f[i_start],...,f[i_final])のマーラー変換を法pで計算し
  // (a[i_start],...,a[i_final])に格納する。
  // 要素数のみに依存する包除原理を法pで解くことに対応。
  void Convert( const ll ( &f )[N_max] , ll ( &a )[N_max] , const int& i_start , const int& i_final );
  // O((i_final-i_start)^2)で(a[i_start],...,a[i_final])の逆マーラー変換を法pで計算し
  // (f[i_start],...,f[i_final])に格納する。
  // 要素数0,1,...,nのデータ群から要素数n以下のデータを得ることに対応。
  void InverseConvert( const ll ( &a )[N_max] , ll ( &f )[N_max] , const int& i_start , const int& i_final );

  // 0 <= n < N_maxである場合のみサポート。
  // 前計算された値をO(1)で参照する。
  inline ll Combination( const int& n , const int& i ) const;
  inline const ll& Factorial( const int& n ) const;
  inline const ll& FactorialInverse( const int& n ) const;
  // 0 < n < N_maxである場合のみサポート。
  inline const ll& Inverse( const int& n ) const;

};
