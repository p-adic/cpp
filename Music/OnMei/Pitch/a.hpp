// c:/Users/user/Documents/Programming/Music/OnMei/Pitch/a.hpp

#pragma once
#include "../a.hpp"

class Pitch
{

private:
  OnMei m_N;
  int m_octave;

  static constexpr const int g_La4_octave = 45;
  static constexpr const double g_La4_shuuhasuu = 440.0;

public:
  inline Pitch( const OnMei& N , const int& octave ) noexcept;

  Pitch& operator++() noexcept;
  Pitch& operator--() noexcept;

  inline int GetNum() const noexcept;
  inline const OnMei& GetOnMei() const noexcept;
  inline const int& GetOctave() const noexcept;
  inline double GetShuuhasuu() const noexcept;
  inline PitchClass GetPitchClass() const noexcept;
  
  inline string Display() const noexcept;
  
};

inline bool operator==( const Pitch& N1 , const Pitch& N2 ) noexcept;
inline bool operator!=( const Pitch& N1 , const Pitch& N2 ) noexcept;
