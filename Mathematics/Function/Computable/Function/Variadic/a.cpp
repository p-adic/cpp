// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Variadic/a.cpp

#include "../../Header.hpp"
#include "a_Body.hpp"

DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( int , Plus , Symbol<int> , 0 , infty() );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( string , Plus , Symbol<string> , EmptyString() , to_string( infty() ) );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , Plus , Symbol<bool> , false , true );

DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( int , Times , Symbol<int> , 1 , 0 );
DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_TWO( bool , Times , Symbol<bool> , true , false );

DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( Land , true , false );
DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_TWO( Lor , false , true );
