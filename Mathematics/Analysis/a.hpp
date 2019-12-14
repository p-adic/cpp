// Analysis/a.hpp

#pragma once

// GLOBALCONSTANTマクロの仕様でによりconstexprにできない
template <typename T> inline const T& pi();
