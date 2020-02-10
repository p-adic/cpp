// c:/Users/user/Documents/Programming/Error/FaultInCoding/a.cpp

#include "../Header.hpp"
#include "a.hpp"

#include "../a_Body.hpp"

void IndicateFaultInCoding( const char* const FILE , const int& LINE , const char* const FUNC )
{

  IndicateError( FILE , LINE , FUNC );
  cout << "There seems to be some mistake in the coding." << endl;
  cout << endl;

  return;

}

void ThrowFaultInCoding( const char* const FILE , const int& LINE , const char* const FUNC )
{

  g_ALLIANCE_OF_OVERLAPPING = true;
  
  IndicateFaultInCoding( FILE , LINE , FUNC );
    
  throw FaultInCoding();

  return;

}
