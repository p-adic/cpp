// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Totality/a_Body.hpp

#pragma once
#include "a.hpp"

inline TotalityOfComputableFunction::TotalityOfComputableFunction( const string& totality ) noexcept : m_totality( totality ) {}

inline const string& TotalityOfComputableFunction::Get() const noexcept { return m_totality; }

inline bool operator==( const TotalityOfComputableFunction& t1 , const TotalityOfComputableFunction& t2 ) noexcept { return t1.Get() == t2.Get(); }
inline bool operator!=( const TotalityOfComputableFunction& t1 , const TotalityOfComputableFunction& t2 ) noexcept { return !( t1 == t2 ); }

inline const TotalityOfComputableFunction& Recursiveness() { static const TotalityOfComputableFunction& t{ RecursiveString() }; return t; }
inline const TotalityOfComputableFunction& Partiality() { static const TotalityOfComputableFunction& t{ PartialString() }; return t; }
inline const TotalityOfComputableFunction& Totality() { static const TotalityOfComputableFunction& t{ TotalString() }; return t; }
inline const TotalityOfComputableFunction& Primitivity() { static const TotalityOfComputableFunction& t{ PrimitiveString() }; return t; }
