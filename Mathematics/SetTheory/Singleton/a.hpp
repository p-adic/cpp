// Singleton/a.hpp

#pragma once

template <typename T>
class SingletonType
{

protected:
  SingletonType() = default;
  SingletonType( const SingletonType& ) = default;
  virtual ~SingletonType() = default;
  SingletonType& operator=( const SingletonType& ) = default;

public:
  static T& GetUniqueObject();
  
};

template <typename T>
class SingletonOf :
  public SingletonType<SingletonOf<T> >
{

  friend SingletonType<SingletonOf<T> >;

private:
  SingletonOf() = default;
  SingletonOf( const SingletonOf& ) = default;
  ~SingletonOf() = default;
  SingletonOf& operator=( const SingletonOf& ) = default;

public:
  using type = T;

};

// Replace TYPE_NAME by a suitable typename.
/*
class TYPE_NAME :
  public SingletonType<TYPE_NAME>
{

  friend SingletonType<TYPE_NAME>;

private:
  TYPE_NAME() = default;
  TYPE_NAME( const TYPE_NAME& ) = default;
  ~TYPE_NAME() = default;
  TYPE_NAME& operator=( const TYPE_NAME& ) = default;

};
*/

template <typename T> T& Object();
