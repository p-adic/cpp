// c:/Users/user/Documents/Programming/Utility/Extended_ull/a_Macro.hpp

#pragma once
#define SFINAE_FOR_EXTENDED_ULL( DEFAULT )				\
  typename T , enable_if_t<is_constructible<UINT,decay_t<T> >::value>* DEFAULT \

#define STATIC_ASSERT_FOR_EXTENDED_ULL					\
  static_assert( !is_same<UINT,ull>::value || digit == 64 );		\
  if constexpr( !is_same<UINT,ull>::value ){				\
    static_assert( !is_same<typename UINT::base,ull>::value || digit == 128 ); \
    if constexpr( !is_same<typename UINT::base,ull>::value ){		\
	static_assert( is_same<UINT,Extended_ull<typename UINT::base,digit/2> >::value ); \
    }									\
  }								\
  
