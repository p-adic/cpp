// c:/Users/user/Documents/Programming/Music/Haichi/a_Body.hpp

#pragma once
#include "a.hpp"

#include "SanWaOn/KyouWaOn/a_Body.hpp"
#include "YonWaOn/Seventh/a_Body.hpp"

inline Haichi::Haichi( const OnMei& bas_onmei , const Octave& bas_octave , const OnMei& ten_onmei , const Octave& ten_octave , const OnMei& alt_onmei , const Octave& alt_octave , const OnMei& sop_onmei , const Octave& sop_octave ) noexcept : m_sop( sop_onmei , sop_octave ) , m_alt( alt_onmei , alt_octave ) , m_ten( ten_onmei , ten_octave ) , m_bas( bas_onmei , bas_octave ) {}


inline bool Haichi::IsOrderedWithInRange() noexcept { return CheckOrderedWithinRange( m_bas.GetNoteNumber() , m_ten.GetNoteNumber() , m_alt.GetNoteNumber() , m_sop.GetNoteNumber() ); }

inline bool Haichi::CheckOrderedWithInRange( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept { return CheckOrdered( bas , ten , alt , sop ) ) && CheckWithinRange( bas , ten , alt , sop ); }
inline bool Haichi::CheckOrdered( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept { return bas <= ten && ten <= alt && alt <= sop; }
inline bool Haichi::CheckWithinRange( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept { return CheckWithinBasRange( bas ) && CheckWithinTenRange( ten ) && CheckWithinAltRange( alt ) && CheckWithinBasRange( sop ); }
inline bool Haichi::CheckWithinSopRange( const NoteNumber& sop ) noexcept { return NoteNumberOfSi3() <= sop && sop <= NoteNumberOfDo6(); }
inline bool Haichi::CheckWithinAltRange( const NoteNumber& alt ) noexcept { return NoteNumberOfFa3() <= alt && alt <= NoteNumberOfFa5(); }
inline bool Haichi::CheckWithinTenRange( const NoteNumber& ten ) noexcept { return NoteNumberOfLa2() <= ten && ten <= NoteNumberOfLa4(); }
inline bool Haichi::CheckWithinBasRange( const NoteNumber& bas ) noexcept { return NoteNumberOfMi2() <= bas && bas <= NoteNumberOfFa4(); }

inline DEFINITION_OF_NOTE_NUMBER( Do , 6 ) noexcept;
inline DEFINITION_OF_NOTE_NUMBER( Si , 3 ) noexcept;

inline DEFINITION_OF_NOTE_NUMBER( Fa , 5 ) noexcept;
inline DEFINITION_OF_NOTE_NUMBER( Fa , 3 ) noexcept;

inline DEFINITION_OF_NOTE_NUMBER( La , 4 ) noexcept;
inline DEFINITION_OF_NOTE_NUMBER( La , 2 ) noexcept;

inline DEFINITION_OF_NOTE_NUMBER( Fa , 4 ) noexcept;
inline DEFINITION_OF_NOTE_NUMBER( Mi , 2 ) noexcept;

inline string Haichi::Display() const noexcept { return "(" + m_bas.Display() + "," + m_ten.Display() + "," + m_alt.Display() + "," + m_sop.Display() + ")"; }

inline const Pitch& Haichi::GetPitch( const int& i ) const noexcept
{

  const Pitch* table[4] = { &m_bas , &m_ten , &m_alt , &m_sop };
  return *( table[i] );

}

inline bool operator==( const Haichi& C1 , const Haichi& C2 ) noexcept { return C1.GetPitch( 0 ) == C2.GetPitch( 0 ) && C1.GetPitch( 1 ) == C2.GetPitch( 1 ) && C1.GetPitch( 2 ) == C2.GetPitch( 2 ) && C1.GetPitch( 3 ) == C2.GetPitch( 3 ); }
inline bool operator!=( const Haichi& C1 , const Haichi& C2 ) noexcept { return !( C1 == C2 ); }
