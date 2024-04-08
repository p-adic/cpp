// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/Constexpr/a.hpp

#pragma once

// val_limit = 1e4：コンパイル時間18,371 [ms]
// val_limit = 1e5：コンパイル時間30,000 [ms]オーバー。
// val_limit = 1e6だとコンパイル時ループ回数上限262144オーバー

template <typename INT , INT val_limit>
class LeastDivisor
{

private:
  INT m_val[val_limit];

public:
  // O(val_limit log log val_limit)
  inline constexpr LeastDivisor() noexcept;

  inline const INT& operator[]( const int& i ) const;
  inline constexpr const INT& Get( const int& i ) const;

};

