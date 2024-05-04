// c:/Users/user/Documents/Programming/Utility/Set/a_Macro.hpp

#pragma once

#define DECLARATION_OF_HASH( ... )				\
  struct hash<__VA_ARGS__>					\
  {								\
								\
    inline size_t operator()( const __VA_ARGS__& n ) const;	\
								\
  };								\

