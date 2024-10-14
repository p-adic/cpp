// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Least/a.hpp

#pragma once

// val_limit = 1e4：コンパイル時間18,371 [ms]
// val_limit = 1e5：コンパイル時間30,000 [ms]オーバー。
// val_limit = 1e6だとコンパイル時ループ回数上限262144オーバー

template <int val_limit>
class LeastDivisor
{

private:
  int m_val[val_limit];

public:
  // O(val_limit log log val_limit)
  inline constexpr LeastDivisor() noexcept;

  inline const int& operator[]( const int& i ) const;
  inline constexpr const int& Get( const int& i ) const;
  inline constexpr int length() const noexcept;

};

