// c:/Users/user/Documents/Programming/Error/Warning/a_Macro.hpp

#pragma once

#ifdef DEBUG

  #define WARNING( body ) BREAK( "WARNING" , body ); IndicateWarning( POSITION , body ) 
  #define MESSAGE( body ) BREAK( "MESSAGE" , body ); IndicateMessage( POSITION , body ) 

#else

  #define WARNING( body ) IndicateWarning( POSITION , body ) 
  #define MESSAGE( body ) IndicateMessage( POSITION , body ) 

#endif
