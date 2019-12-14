// Temporary/a.hpp

#pragma once

#include "../List/LabeledList/a.hpp"
#include "../../Mathematics/Function/a.hpp"
#include "../../Mathematics/SetTheory/DisjointUnion/a.hpp"
#include "../../Mathematics/SetTheory/Singleton/a.hpp"

template <typename Ret , typename... Args>
class Temporary
{

private:
  FunctionType<Ret,Args...>* m_func;
  DirectProduct<const Args*...> m_args;
  Ret m_ret;

public:
  Temporary( const FunctionType<Ret,Args...>& , const Args&... );
  void Set( const Args&... );
  const DirectProduct<const Args*...>& GetLastArguments() const;
  const Ret& GetLastRet() const;

};

template <typename Ret , typename... Args> bool CheckLastArguments( const Temporary<Ret,Args...>& , const Args&... );
template <typename Ret , typename... Args> const DirectProduct<const Args*...>& LoadLastArguments( const Temporary<Ret,Args...>& );
template <typename Ret , typename... Args> const Ret& LoadLastRet( const Temporary<Ret,Args...>& );
template <typename Ret , typename... Args> void MemoriseNewArguments( const Temporary<Ret,Args...>& , const Args&... );
template <typename Ret , typename... Args> const Ret& LoadNewRet( const Temporary<Ret,Args...>& , const Args&... );
template <typename Ret , typename... Args> const Ret& LoadNewRet( const FunctionType<Ret,Args...>& , const Args&... );
