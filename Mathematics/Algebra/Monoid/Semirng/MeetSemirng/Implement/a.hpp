// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/Implement/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/964836

template <typename U> class Trop;

template <typename U>
class ZeroForTrop
{

  friend class Trop<U>;
  
private:
  ZeroForTrop() = delete;
  static U g_zero;

};

// 入力の範囲内で要件
// (1) Uがoperator+=に関して全順序半群である。
// (2) g_zeroが最小元である。
// を満たす場合にのみサポート。
// Uのoperator+=とoperaror<に関する非単位的Maxトロピカル半環に相当する型を得る。
// 行列を使う場合などAbsractTropicalSemrngでは遲いかもしれない場合に用いる。
template <typename U = ll>
class Trop
{

private:
  U m_n;

public:
  inline Trop( const U& n = ZeroForTrop<U>::g_zero );

  inline Trop<U>& operator+=( const Trop<U>& n );
  inline Trop<U>& operator*=( const Trop<U>& n );
  inline Trop<U> operator+( const Trop<U>& n ) const;
  inline Trop<U> operator*( const Trop<U>& n ) const;

  inline void Set( const U& n ) noexcept;
  inline const U& Get() const noexcept;

  static inline void SetZero( const U& zero ) noexcept;;
  
};

template <class Traits , typename U> inline basic_istream<char,Traits>& operator>>( basic_ostream<char,Traits>& is , const Trop<U>& n ) noexcept;
template <class Traits , typename U> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Trop<U>& n ) noexcept;
