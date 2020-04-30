// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Totality/a.hpp

#pragma once

class TotalityOfComputableFunction
{

public:
  string m_totality;

public:
  inline TotalityOfComputableFunction( const string& totality ) noexcept;
  
  inline const string& Get() const noexcept;

};

inline bool operator==( const TotalityOfComputableFunction& t1 , const TotalityOfComputableFunction& t2 ) noexcept;
inline bool operator!=( const TotalityOfComputableFunction& t1 , const TotalityOfComputableFunction& t2 ) noexcept;


inline const TotalityOfComputableFunction& Recursiveness();
inline const TotalityOfComputableFunction& Partiality();
inline const TotalityOfComputableFunction& Totality();
inline const TotalityOfComputableFunction& Primitivity();
