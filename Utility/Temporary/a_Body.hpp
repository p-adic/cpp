// Temporary/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../List/LabeledList/a_Body.hpp"
#include "../../Mathematics/SetTheory/DirectProduct/a_Body.hpp"
#include "../../Mathematics/SetTheory/Singleton/a_Body.hpp"

template <typename Ret , typename... Args>
Temporary<Ret,Args...>::Temporary( const FunctionType<Ret,Args...>& func , const Args&... args ) :
  m_func( func ) , m_args( DirectProduct<const Args*...>( &args... ) ) , m_ret( func( args... ) )
{}

template <typename Ret , typename... Args>
void Temporary<Ret,Args...>::Set( const Args&... args )
{

  m_args = DirectProduct<const Args*...>( &args... );
  m_ret = m_func( args... );
  return;

}

template <typename Ret , typename... Args>
const DirectProduct<const Args*...>& Temporary<Ret,Args...>::GetLastArguments() const
{
  
  return m_args;

}

template <typename Ret , typename... Args>
const Ret& Temporary<Ret,Args...>::GetLastRet() const
{

  return m_ret;

}

template <typename Ret , typename... Args>
bool CheckLastArguments( const Temporary<Ret,Args...>& temp , const Args&... args )
{

  return Equal( LoadLastArguments( temp ) , &args... );

}

template <typename Ret , typename... Args>
const DirectProduct<const Args*...>& LoadLastArguments( const Temporary<Ret,Args...>& temp )
{

  return temp.GetLastArguments();

}

template <typename Ret , typename... Args>
const Ret& LoadLastRet( const Temporary<Ret,Args...>& temp )
{

  return temp.GetLastRet();

}

template <typename Ret , typename... Args>
void SetNewArguments( Temporary<Ret,Args...>& temp , const Args&... args )
{

  if( ! CheckLastArguments( temp , args... ) ){

    temp.Set( args... );
    
  }
  
  return;

}

template <typename Ret , typename... Args>
const Ret& LoadNewRet( Temporary<Ret,Args...>& temp , const Args&... args )
{

  SetNewArguments( temp , args... );  
  return LoadLastRet( temp );

}

template <typename Ret , typename... Args>
const Ret& LoadNewRet( const FunctionType<Ret,Args...>& func , const Args&... args )
{

  static LabeledList<Temporary<Ret,Args...>,FunctionType<Ret,Args...> > temp;

  if( CheckContain( temp , func ) ){
    
    Add( temp , func , Temporary<Ret,Args...>( func , args... ) );

  }
  
  return LoadNewRet( temp( func ) , args... );

}
