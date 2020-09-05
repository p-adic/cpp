// c:/Users/user/Documents/Programming/Utility/WrappedType/a.hpp

#pragma once

template <typename Arg>
class WrappedType
{

private:
  Arg m_t;

public:
  template <typename... ARGS> inline WrappedType( const ARGS&... args );
  inline void Set( const Arg& t );
  inline const Arg& Get() const noexcept;

};

template <typename... Types>
class WrappedTypes
{};
