// Analysis/a.hpp

#pragma once

// GLOBALCONSTANTマクロの仕様でによりconstexprにできない
template <typename T> inline const T& pi();

template <typename T> inline T Distance( const T& a , const ll& b );
