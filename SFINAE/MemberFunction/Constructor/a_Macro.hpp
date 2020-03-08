// c:/Users/user/Documents/Programming/SFINAE/MemberFunction/Constructor/a_Macro.hpp

#pragma once

#define VALUE_CONSTRUCTOR_VALID \
  ( callable_Constructor<T,Args...> ::value ) 

#define VALUE_CONSTRUCTOR_INVALID \
  ( ! VALUE_CONSTRUCTOR_VALID ) 

#define TYPE_OF_CONSTRUCTOR_VALID \
  typename Valid_Construct<T,Args...>::type 

#define TYPE_OF_CONSTRUCTOR_INVALID \
  typename Invalid_Construct<T,Args...>::type 
