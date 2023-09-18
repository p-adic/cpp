// c:/Users/user/Documents/Programming/Contest/Problem/WriteInSamples/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/VLArray/a_Body.hpp"

inline void AddCurrentSample( string& s_sum , const string& s_current )
{

  if( s_sum != "" ){

    s_sum += "\n";

  }
	  
  s_sum += s_current;
  return;

}

inline void PushBackSample( VLArray<string>& input_samples , string& s_sum )
{

  input_samples.push_back( move( s_sum ) );
  s_sum = "";
  return;

}
