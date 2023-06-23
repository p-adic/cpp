// c:/Users/user/Documents/Programming/Utility/String/RollingHash/a.hpp

#pragma once

template <ll p , ll r , int length_max = 1000000>
class RollingHash
{
  
private:
  ll m_power[length_max + 1];
  ll m_p_inv;

public:
  inline constexpr RollingHash();

  tuple<ll,ll,int> Encode( const string& s ) const;
  inline tuple<ll,ll,int> Concatenate( const tuple<ll,ll,int>& code0 , const tuple<ll,ll,int>& code1 ) const;
  // sにcodeでコードされる文字列が連続部分列として含む個数の推定値を返す。
  int CountContain( const string& s , const tuple<ll,ll,int>& code ) const;

};
