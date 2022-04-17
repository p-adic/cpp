// c:/Users/user/Documents/Programming/Error/a.cpp

#include "Header.hpp"
#include "a_Body.hpp"

#include "Debug/a_Macro.hpp"

#include "BreakPoint/a_Body.hpp"
#include "../Utility/GlobalVariable/a_Body.hpp"
#include "../Utility/SmartPointer/a_Body.hpp"

ErrorType::ErrorType() noexcept :
  m_count( 0 ) , m_number( 1u )
{

  static uint count = 0;

  m_count += count;  
  count++;
  BREAK;
  
}

ErrorType::~ErrorType()
{
  
  g_OCCURRENCE_OF_ERR = false;
  g_ALLIANCE_OF_OVERLAPPING = false;

  cout << endl;

  if( *m_number == 1 ){
    
    cout << "Error #" << m_count << " has successfuly been solved." << endl;

  } else {

    *m_number -= 1u;   

  }

  if( g_CHECK_OVERLAPPING == true ){

    cout << "However, there is some error ignored at " << endl;
    IndicatePosition( g_MEMORISE_FILE , g_MEMORISE_LINE , g_MEMORISE_FUNC );
    g_CHECK_OVERLAPPING = false;
    
  }

  cout << endl;
  
}

void IndicateError_Body( const char* const FILE , const int& LINE , const char* const FUNC )
{

  if( g_OCCURRENCE_OF_ERR == true && g_ALLIANCE_OF_OVERLAPPING == false ){

    ThrowFaultInCoding( FILE , LINE , FUNC );

  }

  if( ! CheckError( FILE , LINE , FUNC ) ){
    
    g_OCCURRENCE_OF_ERR = true;

    static int count = -1;
    count++;

    cout << endl;
  
    cout << "Error #" << count << " indicated at" << endl;
    IndicatePosition( FILE , LINE , FUNC );

  }
  
  return;

}

void IndicateError( const char* const FILE , const int& LINE , const char* const FUNC )
{

  IndicateError_Body( FILE , LINE , FUNC );
  cout << endl;
  
  return;

}

bool CheckError( const char* const FILE , const int& LINE , const char* const FUNC ) noexcept
{

  g_MEMORISE_FILE = to_string( FILE );
  g_MEMORISE_LINE = LINE;
  g_MEMORISE_FUNC = to_string( FUNC );

  if( g_OCCURRENCE_OF_ERR == true ){

    g_CHECK_OVERLAPPING = true;
    return true;

  }

  return false;

}
