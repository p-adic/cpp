// c:/Users/user/Documents/Programming/Utility/String/ToArray/a.hpp

#pragma once

template <typename INT = int> inline char IntToChar( const INT& i , const bool& capital = false );
template <typename INT = int> inline INT CharToInt( const char& i );

template <typename INT = int> string ArrayToString( const vector<INT>& A , const bool& capital = false );
template <typename INT = int> vector<INT> StringToArray( const string& S );

