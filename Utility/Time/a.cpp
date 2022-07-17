// c:/Users/user/Documents/Programming/Utility/Time/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"
#include <chrono>

void StopWatch( const int& how_many_times , const string& process_name )
{

  static bool off = true;
  static chrono::system_clock::time_point watch;
  static count;

  if( off ){

    off = false;
    count = 0;
    
    if( process_name == "nothing" ){

      cout << "Start watching execution time: ";

    } else {

      cout << "Start watching execution time of " << process_name << ": ";

    }
    
    watch = chrono::system_clock::now();

  } else {

    count++;

    if( count == how_many_times ){

      const double time = static_cast<double>( chrono::duration_cast<chrono::microseconds>( chrono::system_clock::now() - watch ).count() / 1000.0 );
      cout << time << " [ms]" << endl;
      off = true;

    }
    
  }

  return;

}
