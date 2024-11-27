// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Term/a_Macro.hpp

#pragma once

#define DEFINITION_OF_PRIMITIVE_CPP_CLASS_FOR_TERM( T )	\
									\
  template <>								\
  class CppClassForTerm< T >						\
  {									\
									\
  private:								\
    T m_t;								\
									\
  public:								\
    inline CppClassForTerm( const T & t ) : m_t( t ) {};		\
									\
    inline const T & Get() const noexcept { return m_t; };		\
    inline void Set( const T & t ) { m_t = t; };			\
									\
  }									\
									\


