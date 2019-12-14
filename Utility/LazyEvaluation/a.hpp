// LazyEvaluation/a.hpp

#pragma once

#include "../SmartPointer/a.hpp"
#include "../../Mathematics/Function/a.hpp"

template <typename T>
class LazyEvaluation
{

private:
  const SmartPointer<T> m_p;

public:
  inline LazyEvaluation();
  inline LazyEvaluation( const T& );
  const LazyEvaluation<T>& operator=( const T& ) const;
  inline void Forget() const;
  inline const T& Get() const;
  inline bool IsInitial() const;

};

template <typename T> inline void Initialise( const LazyEvaluation<T>& );

template <typename T> void Memorise( const LazyEvaluation<T>& , const T& );
template <typename T , typename... Args> inline void Memorise( const LazyEvaluation<T>& , const FunctionType<T,Args...>& , const Args&... );

template <typename T> const T& Load( const LazyEvaluation<T>& );
template <typename T , typename... Args> const T& Load( const LazyEvaluation<T>& , const FunctionType<T,Args...>& , const Args&... );

template <typename T> inline bool CheckInitial( const LazyEvaluation<T>& );
