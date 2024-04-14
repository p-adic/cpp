// c:/Users/user/Documents/Programming/Mathematics/Game/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../SetTheory/Mex/a_Body.hpp"

template <typename T , template <typename...> typename V , V<T> E(const T&)>
const bool& HasNonZeroGrundyNumber( const T& t , const bool& reset )
{

  if constexpr( is_constructible_v<unordered_map<T,bool>> ){

      static unordered_map<T,bool> g{};
      CHECK_HAS_NON_ZERO_GRUNDY_NUMBER;

    } else {

    static map<T,bool> g{};
    CHECK_HAS_NON_ZERO_GRUNDY_NUMBER;

  }

}

template <typename T , template <typename...> typename V , V<T> E(const T&)>
const int& GrundyNumber( const T& t , const bool& reset )
{

  if constexpr( is_constructible_v<unordered_map<T,int>> ){

      static unordered_map<T,bool> g{};
      COMPUTE_GRUNDY_NUMBER;

    } else {

    static map<T,int> g{};
    COMPUTE_GRUNDY_NUMBER;

  }
  
}
