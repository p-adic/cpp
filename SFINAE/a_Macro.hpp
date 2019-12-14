// SFINAE/a_Macro.hpp

#pragma once
#include "../Utility/Macro_Macro.hpp"

#define DEFINITION_OF_CHECK_VALUE( VALUE , ... )			\
									\
  template < __VA_ARGS__ >						\
  auto CheckValue_Body() -> typename enable_if< VALUE , void >::type	\
  {									\
									\
    cout << ": true" << endl;						\
    return;								\
									\
  }									\
									\
  template < __VA_ARGS__ >						\
  auto CheckValue_Body() -> typename enable_if< ! VALUE , void >::type	\
  {									\
									\
    cout << ": false" << endl;						\
    return;								\
									\
  }									\
									\
  template <typename... Args>						\
  void CheckValue()							\
  {									\
									\
    cout << to_string<Args...>();					\
    CheckValue_Body<Args...>();						\
    return;								\
									\
  }									\
									\

