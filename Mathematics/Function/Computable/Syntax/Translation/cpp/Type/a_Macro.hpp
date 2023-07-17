// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Type/a_Macro.hpp

#pragma once

#define DEFINITION_OF_PRIMITIVE_CPP_CLASS_FOR_ARGUMENT_STRING( TYPENAME ) \
									\
  template <>								\
  class CppClassForArgumentString< TYPENAME > :				\
    public EmptySet							\
  {									\
									\
  public:								\
    static inline string GetString( const TYPENAME & t ) { return to_string( t ); }; \
									\
  };									\
									\


