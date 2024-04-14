// c:/Users/user/Documents/Programming/Utility/StdStream/a_Macro.hpp

#pragma once

#ifndef CERR
  #ifdef DEBUG
    #define CERR( ... ) VariadicCout( cerr , __VA_ARGS__ ) << endl
    #define COUT( ... ) VariadicCout( cout << "出力： " , __VA_ARGS__ ) << endl
    #define CERR_A( A , N ) OUTPUT_ARRAY( cerr , A , N ) << endl
    #define COUT_A( A , N ) cout << "出力： "; OUTPUT_ARRAY( cout , A , N ) << endl
    #define CERR_ITR( A ) OUTPUT_ITR( cerr , A ) << endl
    #define COUT_ITR( A ) cout << "出力： "; OUTPUT_ITR( cout , A ) << endl
  #else
    #define CERR( ... ) 
    #define COUT( ... ) VariadicCout( cout , __VA_ARGS__ ) << ENDL
    #define CERR_A( A , N ) 
    #define COUT_A( A , N ) OUTPUT_ARRAY( cout , A , N ) << ENDL
    #define CERR_ITR( A ) 
    #define COUT_ITR( A ) OUTPUT_ITR( cout , A ) << ENDL
  #endif
#endif

#define DECLARATION_OF_COUT_FOR_VECTOR( V ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg )
#define DEFINITION_OF_COUT_FOR_VECTOR( V ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg ) { auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os : os << " " ) << *itr; itr++; } return os; }
