// c:/Users/user/Documents/Programming/Music/HaiChi/a_Macro.hpp

#pragma once
#include "../../Utility/String/a_Macro.hpp"

#define DEFINITION_OF_NOTE_NUMBER( ONMEI , OCTAVE )			\
									\
  const NoteNumber& CONNECT( HaiChi::NoteNumberOf , CONNECT( ONMEI , OCTAVE ) )() noexcept { static const NoteNumber n = Pitch( ( ONMEI )() , OCTAVE ).GetNoteNumber(); return n; } \
  
