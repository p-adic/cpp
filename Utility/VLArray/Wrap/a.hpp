// c:/Users/user/Documents/Programming/Utility/VLArray/Wrap/a.hpp

#pragma once

template <typename Arg>
class WrapForVLArray
{

private:
  const Arg m_t;

public:
  template <typename... ARGS> inline WrapForVLArray( const ARGS&... args );
  inline const Arg& Get() const noexcept;

};
