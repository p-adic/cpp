#include "../Header.hpp"
#include "a_Body.hpp"

IllegalAccess::~IllegalAccess()
{

  g_OCCURRENCE_OF_ILLEGAL_ACCESS = false;

}

void IndicateNullAccess_Body( const string& FUNC )
{

  cout << "illegal access to a null pointer in the function `" << FUNC << "'" << endl;
  return;

}

void IndicateUninitialisedAccess_Body( const string& FUNC )
{

  cout << "illegal access to an uninitialised pointer in the function `" << FUNC << "'" << endl;
  return;

}
