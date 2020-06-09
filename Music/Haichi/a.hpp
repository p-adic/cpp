// c:/Users/user/Documents/Programming/Music/Haichi/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../OnMei/OnMei/Pitch/a.hpp"
#include "../Chou/a.hpp"

class Haichi
{

private:
  Pitch m_sop;
  Pitch m_alt;
  Pitch m_ten;
  Pitch m_bas;
  
public:
  inline Haichi( const OnMei& bas_onmei , const Octave& bas_octave , const OnMei& ten_onmei , const Octave& ten_octave , const OnMei& alt_onmei , const Octave& alt_octave , const OnMei& sop_onmei , const Octave& sop_octave ) noexcept;

  inline bool IsNaturallyOrdered() const noexcept;
  uint GetNumberOfOnMei() const noexcept;
  static bool CheckValidKaiMei( const Chou& N , const KaiMei& n ) const noexcept;
  static inline bool CheckHasDoubleDaiSanOn( const uint& bas_num , const uint& ten_num , const uint& alt_num , const uint& sop_num ) const noexcept;
  static inline bool CheckHasDaiGoOn( const uint& bas_num , const uint& ten_num , const uint& alt_num , const uint& sop_num ) const noexcept;

  inline string Display() const noexcept;

  inline const Pitch& GetPitch( const int& i ) const noexcept;

private:
  static inline bool CheckOrderedWithInRange( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept;

  static inline bool CheckOrdered( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept;
  
  
  static inline bool CheckWithinRange( const NoteNumber& bas , const NoteNumber& ten , const NoteNumber& alt , const NoteNumber& sop ) noexcept;
  static inline bool CheckWithinSopRange( const NoteNumber& sop ) noexcept;
  static inline bool CheckWithinAltRange( const NoteNumber& alt ) noexcept;
  static inline bool CheckWithinTenRange( const NoteNumber& ten ) noexcept;
  static inline bool CheckWithinBasRange( const NoteNumber& bas ) noexcept;

  static inline const NoteNumber& NoteNumberOfDo6() noexcept;
  static inline const NoteNumber& NoteNumberOfSi3() noexcept;

  static inline const NoteNumber& NoteNumberOfFa5() noexcept;
  static inline const NoteNumber& NoteNumberOfFa3() noexcept;

  static inline const NoteNumber& NoteNumberOfLa4() noexcept;
  static inline const NoteNumber& NoteNumberOfLa2() noexcept;

  static inline const NoteNumber& NoteNumberOfFa4() noexcept;
  static inline const NoteNumber& NoteNumberOfMi2() noexcept;


  inline bool Haichi::HasNaturalOnDo() const noexcept;

};

bool operator==( const Haichi& C1 , const Haichi& C2 ) noexcept;
inline bool operator!=( const Haichi& C1 , const Haichi& C2 ) noexcept;
