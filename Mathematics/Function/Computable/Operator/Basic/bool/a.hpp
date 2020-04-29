// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Basic/bool/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"


inline const FunctionSymbol<bool,bool>& NegSymbol();
inline DECLARATION_OF_LOGICAL_CONNECTIVE( To );
inline DECLARATION_OF_LOGICAL_CONNECTIVE( Equiv );

ConditionOfComputableFunction NegSymbolApplication( const ConditionOfComputableFunction& b );
inline DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( To );
inline DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Ot );
inline DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( Equiv );


inline DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Land );
inline DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( Lor );

inline DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( Land );
template <typename... Args> inline DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( Land );

inline DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( Lor );
template <typename... Args> inline DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( Lor );


template <typename Ret> inline DECLARATION_OF_BASIC_RELATION( Ret , == );
template <typename Ret> inline DECLARATION_OF_BASIC_RELATION( Ret , != );
template <typename Ret> inline DECLARATION_OF_BASIC_RELATION( Ret , <= );
template <typename Ret> inline DECLARATION_OF_BASIC_RELATION( Ret , >= );
template <typename Ret> inline DECLARATION_OF_BASIC_RELATION( Ret , < );
template <typename Ret> inline DECLARATION_OF_BASIC_RELATION( Ret , > );

inline ConditionOfComputableFunction operator!( const ConditionOfComputableFunction& b );
inline DECLARATION_OF_BASIC_RELATION( bool , && );
inline DECLARATION_OF_BASIC_RELATION( bool , || );
inline DECLARATION_OF_BASIC_RELATION( bool , >> );
inline DECLARATION_OF_BASIC_RELATION( bool , ->* );
inline DECLARATION_OF_BASIC_RELATION( bool , << );

