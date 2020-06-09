// c:/Users/user/Documents/Programming/Music/Haichi/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../OnMei/Pitch/a_Body.hpp"
#include "../Chou/a_Body.hpp"

#include "../OnMei/Pitch/OnDo/a_Body.hpp"

inline Haichi::Haichi( const OnMei& bas_onmei , const Octave& bas_octave , const OnMei& ten_onmei , const Octave& ten_octave , const OnMei& alt_onmei , const Octave& alt_octave , const OnMei& sop_onmei , const Octave& sop_octave ) noexcept :
  m_sop( sop_onmei , sop_octave ) ,
  m_alt( alt_onmei , alt_octave ) ,
  m_ten( ten_onmei , ten_octave ) ,
  m_bas( bas_onmei , bas_octave )
{}


inline bool Haichi::IsNaturallyOrdered() const noexcept { return CheckOrderedWithinRange( m_bas.GetNoteNumber() , m_ten.GetNoteNumber() , m_alt.GetNoteNumber() , m_sop.GetNoteNumber() ) && HasNaturalOnDo(); }

inline bool Haichi::CheckHasDoubleDaiSanOn( const uint& bas_num , const uint& ten_num , const uint& alt_num , const uint& sop_num ) noexcept { return ( bas_num * ten_num * alt_num * sop_num ) % 9 == 0; }

inline bool Haichi::CheckHasDaiGoOn( const uint& bas_num , const uint& ten_num , const uint& alt_num , const uint& sop_num ) noexcept { return ( bas_num * ten_num * alt_num * sop_num ) % 5 == 0; }

inline bool Haichi::CheckOrderedWithinRange( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept { return CheckOrdered( bas , ten , alt , sop ) && CheckWithinRange( bas , ten , alt , sop ); }
inline bool Haichi::CheckOrdered( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept { return bas <= ten && ten <= alt && alt <= sop; }
inline bool Haichi::CheckWithinRange( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept { return CheckWithinBasRange( bas ) && CheckWithinTenRange( ten ) && CheckWithinAltRange( alt ) && CheckWithinBasRange( sop ); }
inline bool Haichi::CheckWithinSopRange( const NoteNumber& sop ) noexcept { return NoteNumberOfTi3() <= sop && sop <= NoteNumberOfDo6(); }
inline bool Haichi::CheckWithinAltRange( const NoteNumber& alt ) noexcept { return NoteNumberOfFa3() <= alt && alt <= NoteNumberOfFa5(); }
inline bool Haichi::CheckWithinTenRange( const NoteNumber& ten ) noexcept { return NoteNumberOfLa2() <= ten && ten <= NoteNumberOfLa4(); }
inline bool Haichi::CheckWithinBasRange( const NoteNumber& bas ) noexcept { return NoteNumberOfMi2() <= bas && bas <= NoteNumberOfFa4(); }

inline DEFINITION_OF_NOTE_NUMBER( Do , 6 );
inline DEFINITION_OF_NOTE_NUMBER( Ti , 3 );

inline DEFINITION_OF_NOTE_NUMBER( Fa , 5 );
inline DEFINITION_OF_NOTE_NUMBER( Fa , 3 );

inline DEFINITION_OF_NOTE_NUMBER( La , 4 );
inline DEFINITION_OF_NOTE_NUMBER( La , 2 );

inline DEFINITION_OF_NOTE_NUMBER( Fa , 4 );
inline DEFINITION_OF_NOTE_NUMBER( Mi , 2 );

inline bool Haichi::HasNaturalOnDo() const noexcept { return OnDo( m_bas , m_ten ).GetDoSuu() <= 12 && OnDo( m_ten , m_alt ).GetDoSuu() <= 8 && OnDo( m_alt , m_sop ).GetDoSuu() <= 8; }

inline string Haichi::Display() const noexcept { return "(" + m_bas.Display() + "," + m_ten.Display() + "," + m_alt.Display() + "," + m_sop.Display() + ")"; }

inline const Pitch& Haichi::GetPitch( const int& i ) const noexcept
{

  const Pitch* table[4] = { &m_bas , &m_ten , &m_alt , &m_sop };
  return *( table[i] );

}


inline bool operator!=( const Haichi& C1 , const Haichi& C2 ) noexcept { return !( C1 == C2 ); }
