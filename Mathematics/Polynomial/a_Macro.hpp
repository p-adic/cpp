// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Macro.hpp

#pragma once

#define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL( TYPE ) \
  template <> Polynomial<TYPE>& Polynomial<TYPE>::operator*=( const Polynomial<TYPE>& f ) \
  {									\
    if( m_size != 0 ){							\
									\
      vector<TYPE> v{};							\
      v.swap( m_f );							\
      TruncatedPolynomial<TYPE> this_copy{ m_size + f.m_size - 1 , move( v ) }; \
      this_copy *= this == &f ? this_copy : f;				\
      m_f = move( this_copy.Polynomial<TYPE>::m_f );			\
      m_size = m_f.size();						\
									\
    }									\
									\
    return *this;							\
									\
  }									\



