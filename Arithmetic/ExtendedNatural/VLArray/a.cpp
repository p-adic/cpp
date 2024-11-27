// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Dimension/VLArray/a.cpp

#pragma once
#include "../../../Header.hpp"
#include "a_Body.hpp"

dim Sum( const VLArray<dim>& a ) noexcept
{

  dim d = 0;
  
  for( auto itr = a.begin() ; itr != a.end() ; itr++ ){

    if( *itr == *infty() ){

      return *infty();

    } else {
	
      d += *itr;

    }

  }

  return d;

}

dim Prod( const VLArray<dim>& a )
{

  dim d = 1;
  
  for( auto itr = a.begin() , end = a.end() ; itr != end ; itr++ ){

    d *= *itr;

  }
  
  return d; 

}
