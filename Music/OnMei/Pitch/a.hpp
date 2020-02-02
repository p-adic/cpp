// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/a.hpp

#pragma once
#include "../a.hpp"

#include "a_Alias.hpp"

class Pitch
{

private:
  OnMei m_N;
  Octave m_octave;

  static constexpr const Octave g_La4_notenumber = 69;
  static constexpr const double g_La4_shuuhasuu = 440.0;

public:
  inline Pitch( const OnMei& N , const Octave& octave ) noexcept;

  Pitch& operator++() noexcept;
  Pitch& operator--() noexcept;

  inline NoteNumber GetNoteNumber() const noexcept;
  inline const OnMei& GetOnMei() const noexcept;
  inline const Octave& GetOctave() const noexcept;
  inline double GetShuuhasuu() const noexcept;
  inline PitchClass GetPitchClass() const noexcept;
  
  inline string Display() const noexcept;
  
};

inline bool operator==( const Pitch& N1 , const Pitch& N2 ) noexcept;
inline bool operator!=( const Pitch& N1 , const Pitch& N2 ) noexcept;
