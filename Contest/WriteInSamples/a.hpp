// c:/Users/user/Documents/Programming/Contest/WriteInSamples/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../Utility/VLArray/a.hpp"

inline void AddCurrentSample( string& s_sum , const string& s_current );
inline void PushBackSample( VLArray<string>& input_samples , string& s_sum );

void WriteInSamples( const string& directory_name , VLArray<string>& file_names );
