// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/OnDo/SetTouJi/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../../Utility/String/a.hpp"

#include "a_Alias.hpp"

class SetTouJiOfOnDo
{

private:
  string m_s;

public:
  inline SetTouJiOfOnDo( const string& s ) noexcept;

  inline const string& Get() const noexcept;

  static const SetTouJiOfOnDo& Compute( const ZeroIndexedDoSuu& D , const PitchDifference& d ) noexcept;

  static const SetTouJiOfOnDo& KanZen() noexcept;
  static const SetTouJiOfOnDo& Chou() noexcept;
  static const SetTouJiOfOnDo& Tan() noexcept;
  static const SetTouJiOfOnDo& Zou() noexcept;
  static const SetTouJiOfOnDo& Gen() noexcept;
  static const SetTouJiOfOnDo& JuuZou() noexcept;
  static const SetTouJiOfOnDo& JuuGen() noexcept;

};

inline operator==( const SetTouJiOfOnDo& s1 , const SetTouJiOfOnDo& s2 ) noexcept;
inline operator!=( const SetTouJiOfOnDo& s1 , const SetTouJiOfOnDo& s2 ) noexcept;
