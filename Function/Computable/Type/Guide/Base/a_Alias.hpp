// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Base/a_Alias.hpp

#pragma once

template <typename T> class IsValidType;

class BaseTypeOf_Body :
  public EmptySet
{

public:
  template <typename T> static auto GetType( const WrappedTypes<T>& ) -> typename enable_if<is_base_of<TypeOfComputableFunction,T>::value, typename T::base_type>::type;
  
  template <typename T> static auto GetType( const WrappedTypes<T>& ) -> typename enable_if<! is_base_of<TypeOfComputableFunction,T>::value && IsValidType<T>::value,T>::type;

  template <typename T> static auto GetType( const WrappedTypes<T>& ) -> typename enable_if<! is_base_of<TypeOfComputableFunction,T>::value && ! IsValidType<T>::value,void>::type;

};
