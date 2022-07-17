// c:/Users/user/Documents/Programming/Utility/Time/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"
#include <chrono>

void StopWatch( const string& process_name )
{

  static bool off = true;
  static chrono::system_clock::time_point watch;

  if( off ){

    if( process_name == "nothing" ){

      cout << "Start watching execution time: ";

    } else {

      cout << "Start watching execution time of " << process_name << ": ";

    }
    
    watch = chrono::system_clock::now();

  } else {

    watch = chrono::system_clock::now() - watch;

    const double time = static_cast<double>( chrono::duration_cast<chrono::microseconds>( watch ).count() / 1000.0);
    cout << time << " [ms]" << endl;

  }

  return;

}
