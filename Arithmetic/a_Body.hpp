// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , template <typename...> typename V , T m_T(const T&,const T&) , const T& e_T()>
T& MonoidalProd( V<T>& f )
{

  DEFIINTION_OF_PROD( MonoidalProd , e_T() , t = m_T( t , *itr ) );

}

template <typename T , template <typename...> typename V>
T& Sum( V<T>& f )
{

  DEFIINTION_OF_PROD( Sum , T( 0 ) , t += *itr );

}

template <typename T , template <typename...> typename V>
T& Prod( V<T>& f )
{

  DEFIINTION_OF_PROD( Prod , T( 1 ) , t *= *itr );

}
