// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/a_Macro.hpp

#pragma once

#define DEFINITION_OF_DUMMY_CLASS( CLASS_NAME )				\
									\
  static const CLASS_NAME CONNECT( CONNECT( __DEFINITION_OF__ , CLASS_NAME ) , __ ){}; \
  static const CLASS_NAME & CONNECT( CONNECT( __SYMBOL_OF_ , CLASS_NAME ) , __ ) = CONNECT( CONNECT( __DEFINITION_OF__ , CLASS_NAME ) , __ ); \
									\
  class CONNECT( DUMMY_CLASS_TO_USE_ , CONNECT( CONNECT( __SYMBOL_OF_ , CLASS_NAME ) , __ ) ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    const TypeOfComputableFunction& m_dummy = CONNECT( CONNECT( __SYMBOL_OF_ , CLASS_NAME ) , __ ); \
									\
  };									\
									\

