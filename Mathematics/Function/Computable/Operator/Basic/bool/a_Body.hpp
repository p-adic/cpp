// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Basic/bool/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"


template <> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( bool , Plus , Lor );
template <> inline DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( bool , Times , Land );

inline const FunctionSymbol<bool,bool>& NegSymbol() { static const FunctionSymbol<bool,bool> f( NegString() , GetTypeName<bool>() , VariableSymbol<bool>( "x" ) ); return f; }
inline DEFINITION_OF_LOGICAL_CONNECTIVE( To );
inline DEFINITION_OF_LOGICAL_CONNECTIVE( Equiv );

inline DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
inline DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Ot ){ return ToSymbolApplication( e2 , e1 ); }
inline DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );


inline DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( Land );
inline DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( Lor );

inline DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( Land );
template <typename... Args> inline DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( Land );

inline DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( Lor );
template <typename... Args> inline DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( Lor );


template <typename Ret> inline DEFINITION_OF_BASIC_RELATION( Ret , == , Eq );
inline DEFINITION_OF_BASIC_RELATION( int , == , Eq );
inline DEFINITION_OF_BASIC_RELATION( string , == , Eq );
inline DEFINITION_OF_BASIC_RELATION( bool , == , Equiv );


template <typename Ret> inline DEFINITION_OF_BASIC_RELATION( Ret , != , Neq );
inline DEFINITION_OF_BASIC_RELATION( int , != , Neq );
inline DEFINITION_OF_BASIC_RELATION( string , != , Neq );
inline DECLARATION_OF_BASIC_RELATION( bool , != ){ return NegSymbolApplication( EquivSymbolApplication( e1 , e2 ) ); }


template <typename Ret> inline DEFINITION_OF_BASIC_RELATION( Ret , <= , Leq );
inline DEFINITION_OF_BASIC_RELATION( int , <= , Leq );

template <typename Ret> inline DEFINITION_OF_BASIC_RELATION( Ret , >= , Geq );
inline DEFINITION_OF_BASIC_RELATION( int , >= , Geq );

template <typename Ret> inline DEFINITION_OF_BASIC_RELATION( Ret , < , Lneq );
inline DEFINITION_OF_BASIC_RELATION( int , < , Lneq );

template <typename Ret> inline DEFINITION_OF_BASIC_RELATION( Ret , > , Gneq );
inline DEFINITION_OF_BASIC_RELATION( int , > , Gneq );


inline ConditionOfComputableFunction operator!( const ConditionOfComputableFunction& b ){ return NegSymbolApplication( b ); }
inline DEFINITION_OF_BASIC_RELATION( bool , && , Land );
inline DEFINITION_OF_BASIC_RELATION( bool , || , Lor );
inline DEFINITION_OF_BASIC_RELATION( bool , >> , To );
inline DEFINITION_OF_BASIC_RELATION( bool , ->* , To );
inline DEFINITION_OF_BASIC_RELATION( bool , << , Ot );
