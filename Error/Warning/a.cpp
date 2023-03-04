// c:/Users/user/Documents/Programming/Error/Warning/a.cpp

#include "../Header.hpp"
#include "a.hpp"

#include "../Position/a.hpp"

void IndicateWarning( const char* FILE , const int& LINE , const char* FUNC  , const string& body )
{

  cout << endl;
  
  cout << "Warning at" << endl;
  IndicatePosition( FILE , LINE , FUNC );

  cout << "invalid input of argument(s):" << endl;
  cout << endl;

  cout << body << endl;
  cout << endl;

  return;

}

void IndicateMessage( const char* FILE , const int& LINE , const char* FUNC , const string& body )
{

  cout << endl;

  cout << "Message at" << endl;
  IndicatePosition( FILE , LINE , FUNC );

  cout << body << endl;
  cout << endl;

  return;

}
