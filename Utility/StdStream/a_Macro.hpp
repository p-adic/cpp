// c:/Users/user/Documents/Programming/Utility/StdStream/a_Macro.hpp

#pragma once

#define SFINAE_FOR_STD_STREAM( TYPE , DEFAULT ) \
  typename T , enable_if_t<is_same<T,TYPE>::value>* DEFAULT	\

#define DECLARATION_OF_SCAN( TYPE ) \
  template <SFINAE_FOR_STD_STREAM( TYPE , = nullptr )> static inline void Scan( T& t ) \

#define DEFINITION_OF_SCAN_FOR_SIGNED_INT_TYPE( TYPE ) \
  template <SFINAE_FOR_STD_STREAM( TYPE , )> inline void StdStream::Scan( T& t ) { t = 0; if( g_head == g_length ){ Load(); } while( g_c == g_space || g_c == g_new_line ){ ShiftHead(); } bool negative = false; if( g_c == g_minus ){ negative = true; ShiftHead(); } while( !( g_c == g_space || g_c == g_new_line ) ){ ( t *= 10 ) += ( g_c - g_zero ); ShiftHead(); } if( negative ){ t *= -1; } } \

#define DEFINITION_OF_SCAN_FOR_UNSIGNED_INT_TYPE( TYPE ) \
  template <SFINAE_FOR_STD_STREAM( TYPE , )> inline void StdStream::Scan( T& t ) { t = 0; if( g_head == g_length ){ Load(); } while( g_c == g_space || g_c == g_new_line ){ ShiftHead(); } while( !( g_c == g_space || g_c == g_new_line ) ){ ( t *= 10 ) += ( g_c - g_zero ); ShiftHead(); } } \

#define DEFINITION_OF_SCAN_FOR_STRING_TYPE( TYPE ) \
  template <SFINAE_FOR_STD_STREAM( TYPE , )> inline void StdStream::Scan( T& t ) { t = ""; if( g_head == g_length ){ Load(); } while( g_c == g_space || g_c == g_new_line ){ ShiftHead(); } while( !( g_c == g_space || g_c == g_new_line ) ){ t += g_c; ShiftHead(); } } \

