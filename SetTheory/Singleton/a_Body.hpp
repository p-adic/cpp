// Singleton/a_Body.hpp

#pragma once
#include "a.hpp"

#include <typeinfo>

#include "../../../Error/IllegalImput/a_Body.hpp"

template <typename T>
T& SingletonType<T>::GetUniqueObject()
{

    static T t;
    return t;

}

template <typename T>
T& Object()
{

  if( ! is_base_of<SingletonType<T>,T>::value ){

    ERR_IMPUT( typeid( T ) );
    
  }

  return T::GetUniqueObject();

}
