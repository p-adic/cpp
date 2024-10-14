// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a_Macro.hpp

#pragma once
#ifndef SET
  #ifdef USE_GETLINE
    #define SET_SEPARATE( SEPARATOR , ... ) VariadicGetline( cin , SEPARATOR , __VA_ARGS__ )
    #define SET( ... ) SET_SEPARATE( '\n' , __VA_ARGS__ )
  #else
    #define SET( ... ) VariadicCin( cin , __VA_ARGS__ )
  #endif
#endif

#define SET_GRID H_minus = H - 1; W_minus = W - 1; HW = ll( H ) * W
#define SET_HW( h , w ) H = h; W = w; SET_GRID
#define CIN_HW SET( H , W ); SET_GRID
