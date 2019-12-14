#include "../Header.hpp"
#include "a_Body.hpp"

void IndicatePosition( const char* const FILE , const int& LINE , const char* const FUNC ) noexcept
{
  
  IndicatePosition( to_string( FILE ) , LINE , to_string( FUNC ) );
  return;

}

void IndicatePosition( const string& FILE , const int& LINE , const string& FUNC ) noexcept
{
  
  cout << "  " << FILE << ":" << LINE << " in the call of" << endl;
  cout << "    the function `" << FUNC << "'" << endl;
  return;

}

void IndicateCall_Body( const string& FILE , const int& LINE , const string& FUNC ) noexcept
{

  cout << "called arround " << FILE << ":" << LINE << " in the call of" << endl;
  cout << "  the function `" << FUNC << "'" << endl;
  return;

}

void IndicateCall( const string& FILE , const int& LINE , const string& FUNC , const ErrorType& e )
{

  IndicateCall_Body( to_string( FILE ) , LINE , to_string( FUNC ) );
  
  throw e;
  
  return;

}
