// c:/Users/user/Documents/Programming/Utility/StdStream/a_Macro.hpp

#pragma once

#ifndef CERR
  #ifdef DEBUG
    #define COUT( ... ) VariadicCout( cout << "出力：" , __VA_ARGS__ ) << endl
    #define COUTNS( ... ) VariadicCoutNonSep( cout , __VA_ARGS__ ) << flush
    #define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
    #define CERRNS( ... ) VariadicCout( cerr , __VA_ARGS__ ) << flush
    #define COUT_A( A , N ) OUTPUT_ARRAY( cout << "出力："  , A , N ) << endl
    #define CERR_A( A , N ) OUTPUT_ARRAY( cerr , A , N ) << endl
  #else
    #define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
    #define COUTNS( ... ) VariadicCoutNonSep( cout , __VA_ARGS__ )
    #define CERR( ... ) 
    #define CERRNS( ... ) 
    #define COUT_A( A , N ) OUTPUT_ARRAY( cout , A , N ) << ENDL
    #define CERR_A( A , N ) 
  #endif
#endif

