// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/a_Macro.hpp

#pragma once

#define PARTIAL_SPECIALISATION_FOR_FFT( MOD , LENGTH , BORDER , PR , IPR ) \
  static_assert( ( Mod<MOD>::Derepresent( PR ) *= Mod<MOD>::Derepresent( IPR ) ) == Mod<MOD>::Derepresent( 1 ) ); \
  template <> inline constexpr const uint LimitOfPowerForFFT<Mod<MOD> > = LENGTH - 1; \
  template <> inline constexpr const uint LimitOfPowerForFFT<Montgomery<MOD> > = LimitOfPowerForFFT<Mod<MOD> >; \
  template <> inline constexpr const uint BorderForFFT<Mod<MOD> > = BORDER; \
  template <> inline constexpr const uint BorderForFFT<Montgomery<MOD> > = BorderForFFT<Mod<MOD> >; \
  template <> inline const Mod<MOD> ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Mod<MOD> >] { static constexpr Power3Power_constexpr<Mod<MOD>,LimitOfPowerForFFT<Mod<MOD> > > PRT{ PR }; static_assert( PRT.m_val[0] == Mod<MOD>::Derepresent( 1 ) ); return PRT.Get(); } \
  template <> inline const Mod<MOD> ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Mod<MOD> >] { static constexpr Power3Power_constexpr<Mod<MOD>,LimitOfPowerForFFT<Mod<MOD> > > IPRT{ IPR }; static_assert( IPRT.m_val[0] == Mod<MOD>::Derepresent( 1 ) && ( Mod<MOD>::Derepresent( PR ) *= Mod<MOD>::Derepresent( IPR ) ) == Mod<MOD>::Derepresent( 1 ) ); return IPRT.Get(); } \
  template <> inline const Montgomery<MOD> ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Montgomery<MOD> >] { static constexpr Power3Power_constexpr<Montgomery<MOD>,LimitOfPowerForFFT<Montgomery<MOD> > > PRT{ PR }; return PRT.Get(); } \
  template <> inline const Montgomery<MOD> ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Montgomery<MOD> >] { static constexpr Power3Power_constexpr<Montgomery<MOD>,LimitOfPowerForFFT<Montgomery<MOD> > > IPRT{ IPR }; return IPRT.Get(); } \

