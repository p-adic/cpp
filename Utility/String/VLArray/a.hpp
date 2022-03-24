// c:/Users/user/Documents/Programming/Utility/String/VLArray/a.hpp

#pragma once
#include "../../VLArray/a.hpp"

VLArray<string> ToArrayOfLetters( const string& s );
void Separate( const string& s , const string& separator , VLArray<string>& a_front , VLArray<string>& a_back );
