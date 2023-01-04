// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Macro.hpp

#pragma once

#define SFINAE_FOR_POLYNOMIAL( DEFAULT )				\
  typename Arg , enable_if_t<is_constructible<T,decay_t<Arg> >::value>* DEFAULT \

#define DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL( TYPE , ARG , RHS ) \
  template <> Polynomial<TYPE>& Polynomial<TYPE>::operator*=( ARG f )	\
  {									\
									\
    if( m_size != 0 ){							\
									\
      vector<TYPE> v{};							\
      v.swap( m_f );							\
      TruncatedPolynomial<TYPE> this_copy{ m_size + f.m_size - 1 , move( v ) }; \
      this_copy *= RHS;							\
      m_f = move( this_copy.Polynomial<TYPE>::m_f );			\
      m_size = m_f.size();						\
									\
    }									\
									\
    return *this;							\
									\
  }									\
  

#define DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL( TYPE ) \
  DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL( TYPE , const Polynomial<TYPE>& , this == &f ? this_copy : f ); \
  DEFINITION_BODY_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL( TYPE , Polynomial<TYPE>&& , move( f ) ); \


