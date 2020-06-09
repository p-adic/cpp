// c:/Users/user/Documents/Programming/Music/Haichi/a_Macro.hpp

#pragma once
#include "../../Utility/Macro_Macro.hpp"

#define DEFINITION_OF_NOTE_NUMBER( ONMEI , OCTAVE )			\
									\
  const NoteNumber& CONNECT( Haichi::NoteNumberOf , CONNECT( ONMEI , OCTAVE ) )() noexcept { static const NoteNumber n = Pitch( ( ONMEI )() , OCTAVE ).GetNoteNumber(); return n; } \
  
