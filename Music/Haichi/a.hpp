// c:/Users/user/Documents/Programming/Music/Haichi/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "SanWaOn/KyouWaOn/a.hpp"
#include "YonWaOn/Seventh/a.hpp"

#include "a_Alias.hpp"

class Haichi
{

private:
  Pitch m_sop;
  Pitch m_alt;
  Pitch m_ten;
  Pitch m_bas;

  Chou m_N;
  KaiMei m_n;
  
public:
  inline Haichi( const OnMei& bas_onmei , const Octave& bas_octave , const OnMei& ten_onmei , const Octave& ten_octave , const OnMei& alt_onmei , const Octave& alt_octave , const OnMei& sop_onmei , const Octave& sop_octave ) noexcept;

  inline bool IsOrderedWithInRange() const noexcept;
  inline uint GetNumberOfOnMei() const noexcept;
  bool HasValidKaiMei() const noexcept;

  inline string Display() const noexcept;

  inline const Pitch& GetPitch( const int& i ) const noexcept;

protected:
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

};




class HaichiOfKyoWaOn :
  public KyoWaOn , public Haichi
{

private:
  bool m_valid;
  uint m_goodness;

public:
  inline HaichiOfKyoWaOn( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept;

  void SetValidity( const Chou& N , const KaiMei& n , const uint& bas_num , const uint& bas_octave , const uint& ten_num , const uint& ten_octave , const uint& alt_num , const uint& alt_octave , const uint& sop_num , const uint& sop_octave ) noexcept;

  inline const OnMei& GetOnMei( const uint& i ) const noexcept;

};

inline bool operator==( const Haichi& C1 , const Haichi& C2 ) noexcept;
inline bool operator!=( const Haichi& C1 , const Haichi& C2 ) noexcept;
