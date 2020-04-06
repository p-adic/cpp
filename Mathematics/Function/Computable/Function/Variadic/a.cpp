// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

template <> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( string , Plus , Frown );

template <> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( int , Plus , Symbol<int> , 0 , infty() );
template <> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( string , Plus , Symbol<string> , EmptyString() , to_string( infty() ) );
template <> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , Plus , Symbol<bool> , false , true );

template <> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( int , Times , Symbol<int> , 1 , 0 );
template <> DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , Times , Symbol<bool> , true , false );

DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( Land , true , false );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( Lor , false , true );
