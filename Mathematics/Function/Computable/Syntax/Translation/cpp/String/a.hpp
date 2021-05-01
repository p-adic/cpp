// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/String/a.hpp

#pragma once
#include "a_Macro.hpp"

class CppClassForString
{

private:
  const VLTree<string> m_t;

public:
  template <typename Arg> inline CppClassForString( const Arg& term_name ) : CppClassForString( EmptyString() , to_string( term_name ) ) {};
  inline CppClassForString( const char* const & term_name ) : CppClassForString( EmptyString() , "\"" + to_string( term_name ) + "\"" ) {};
  inline CppClassForString( const string& type_name , const string& term_name ) : m_t( type_name , term_name ) {};
  inline const string& GetTypeString() const noexcept { return m_t.GetNode( 1 ); };
  inline const string& GetTermString() const noexcept { return m_t.GetNode( 2 ); };

};

inline CppClassForString operator+( const CppClassForString& arg1 , const CppClassForString& arg2 );

inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( - );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( * );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( / );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( % );

inline CppClassForString operator^( const CppClassForString& arg1 , const CppClassForString& arg2 );

inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( == );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( != );

inline CppClassForString operator<=( const CppClassForString& arg1 , const CppClassForString& arg2 );
inline CppClassForString operator>=( const CppClassForString& arg1 , const CppClassForString& arg2 );

inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( < );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( > );

inline CppClassForString operator!( const CppClassForString& arg );

inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( && );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( || );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( ->* );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( >> );
inline DECLARATION_OF_OPERATOR_OF_CPP_CLASS_FOR_STRING( << );

