// c:/Users/user/Documents/Programming/Utility/StdStream/a_Body.hpp

#pragma once
#include "a.hpp"

int StdStream::g_length = 0;
int StdStream::g_head = 0;
basic_streambuf<StdStream::CharT>::int_type StdStream::g_code = 0;
StdStream::CharT StdStream::g_c = StdStream::g_space;
StdStream::CharT StdStream::g_buffer[StdStream::g_length_lim] = {};

inline void StdStream::Load() { g_length = read( 0 , g_buffer , g_length_max ); g_head = -1; g_c = g_space; }
inline void StdStream::ShiftHead() { if( ++g_head == g_length ){ Load(); ++g_head; } ReadHead(); }
inline void StdStream::ReadHead() { g_c = ( g_head == g_length ) ? g_new_line : g_buffer[g_head]; }

DEFINITION_OF_SCAN_FOR_SIGNED_INT_TYPE( int );
DEFINITION_OF_SCAN_FOR_SIGNED_INT_TYPE( ll );
DEFINITION_OF_SCAN_FOR_UNSIGNED_INT_TYPE( uint );
DEFINITION_OF_SCAN_FOR_UNSIGNED_INT_TYPE( ull );
DEFINITION_OF_SCAN_FOR_STRING_TYPE( string );
