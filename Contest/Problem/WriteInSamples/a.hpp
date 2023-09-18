// c:/Users/user/Documents/Programming/Contest/Problem/WriteInSamples/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/VLArray/a.hpp"

inline void AddCurrentSample( string& s_sum , const string& s_current );
inline void PushBackSample( VLArray<string>& input_samples , string& s_sum );

void WriteInSamples( const string& directory_name , VLArray<string>& file_names );
void WriteInSamples( const string& directory_name );
void WriteInSamples_Body( VLArray<string>& file_prefix , VLArray<int>& file_num );
