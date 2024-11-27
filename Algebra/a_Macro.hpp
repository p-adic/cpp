// c:/Users/user/Documents/Programming/Mathematics/Algebra/a_Macro.hpp

#pragma once
#define DECLARATION_OF_CPOINT( POINT ) inline const U& POINT() const noexcept
#define DECLARATION_OF_POINT( POINT ) inline U& POINT() noexcept
#define DEFINITION_OF_CPOINT( POINT ) template <typename U> inline const U& VirtualPointedSet<U>::POINT() const noexcept { return Point(); }
#define DEFINITION_OF_POINT( POINT ) template <typename U> inline U& VirtualPointedSet<U>::POINT() noexcept { return Point(); }
