// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Type/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename T> inline VLNestedArray<T>::VLNestedArray( const T& t ) : m_t() , m_denestable() { m_t.SetRoot( t ); m_denestable.SetRoot( true ); };
template <typename T> inline VLNestedArray<T>::VLNestedArray( const VLTree<T>& t , const VLTree<bool>& denestable ) : m_t( t ) , m_denestable( denestable ) {};
template <typename T> inline VLNestedArray<T>::VLNestedArray( const VLNestedArray<T>& a ) : VLNestedArray( a.m_t , a.m_denestable ) {};

template <typename T> VLNestedArray<T>::VLNestedArray( const VLArray<T>& t ) : VLNestedArray( VLTree<T>() , VLTree<bool>() )
{

  for( auto itr = t.begin() , end = t.end() ; itr != end ; itr++ ){

    m_t.push_RightMost( *itr );
    m_denestable.push_RightMost( true );

  }

  m_denestable.SetRoot( false );

};


template <typename T> inline VLNestedArray<T>& VLNestedArray<T>::operator=( const VLNestedArray<T>& a ){ m_t = a.m_t; m_denestable = a.m_denestable; return *this; }

template <typename T> inline const bool& VLNestedArray<T>::Denestable() const noexcept { return m_denestable.GetRoot(); }
template <typename T> inline const uint& VLNestedArray<T>::size() const noexcept { return m_t.size(); }


template <typename T> inline string VLNestedArray<T>::Display() const noexcept { return "( " + to_string( m_t ) + " , " + to_string( m_denestable ) + " )"; }


template <typename T> inline VLNestedArray<T> VLNestedArray<T>::GetBranchCopy( const uint& n ) const { return VLNestedArray<T>{ m_t.GetBranchCopy( n ) , m_denestable.GetBranchCopy( n ) }; }
template <typename T> inline const T& VLNestedArray<T>::GetRoot() const noexcept { return m_t.GetRoot(); }


template <typename T> VLNestedArray<T> VLNestedArray<T>::Wrap() const
{

  VLTree<T> t{};
  t.push_RightMost( m_t );
  
  VLTree<bool> denestable{};
  denestable.push_RightMost( m_denestable );
  denestable.SetRoot( false );

  return VLNestedArray<T>{ t , denestable };

}



template <typename T> void VLNestedArray<T>::Concatenate( const VLNestedArray& a )
{

  if( Denestable() || a.Denestable() ){

    ERR_IMPUT( *this , a );

  }
  
  auto itr_t = a.m_t.LeftMostNode();
  auto itr_denestable = a.m_denestable.LeftMostNode();

  while( itr_t.IsValid() ){

    m_t.push_RightMost( a.m_t.GetBranchCopy( itr_t ) );
    m_denestable.push_RightMost( a.m_denestable.GetBranchCopy( itr_denestable ) );
    itr_t++;
    itr_denestable++;

  }

  return;
  
}

template <typename T> inline void VLNestedArray<T>::pop_RightMost(){ m_t.pop_RightMost(); m_denestable.pop_RightMost(); }
template <typename T> inline void VLNestedArray<T>::pop_LeftMost(){ m_t.pop_LeftMost(); m_denestable.pop_LeftMost(); }



inline string WrapInParenthesis( const string& arg ) { return LparenString() + arg + RparenString(); }

template <typename Arg> inline auto ConcatenateWithSeparator( const string& s , const Arg& arg ) -> typename enable_if<is_same<Arg,string>::value,string>::type { return arg; }

template <typename Arg1, typename Arg2, typename... Args> inline auto ConcatenateWithSeparator( const string& s , const Arg1& arg1 , const Arg2& arg2 , const Args&... args ) -> typename enable_if<is_same<Arg1,string>::value && is_same<Arg2,string>::value && conjunction<is_same<Args,string>...>::value,string>::type { return arg1 + " " + s + " " + ConcatenateWithSeparator( s , arg2 , args... ); }


inline string ArgumentString() { return "";}
template <typename Arg, typename... Args> inline string ArgumentString( const Arg& arg , const Args&... args ) { return ConcatenateWithSeparator( CommaString() , CppClassForArgumentString<Arg>::GetString( arg ) , CppClassForArgumentString<Args>::GetString( args )... ); }

template <typename Arg, typename... Args> inline string TypeString() { return ConcatenateWithSeparator( CommaString() , CppClassForTypeString<Arg>::GetString() , CppClassForTypeString<Args>::GetString()... ); }

inline string TypeAndArgumentString() { return ""; }
template <typename Arg, typename... Args> inline string TypeAndArgumentString( const Arg& arg , const Args&... args ) { return ConcatenateWithSeparator( CommaString() , CppClassForTypeAndArgumentString<Arg>::GetString( arg ) , CppClassForTypeAndArgumentString<Args>::GetString( args )... ); }


