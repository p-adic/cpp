// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/a_Macro.hpp

#pragma once

#define PARTIAL_SPECIALISATION_FOR_FFT( MOD , LENGTH , BORDER , PR , IPR ) \
  template <> inline constexpr const uint LimitOfPowerForFFT<Mod<MOD> > = LENGTH; \
  template <> inline constexpr const uint LimitOfPowerForFFT<Montgomery<MOD> > = LimitOfPowerForFFT<Mod<MOD> >; \
  template <> inline constexpr const uint BorderForFFT<Mod<MOD> > = BORDER; \
  template <> inline constexpr const uint BorderForFFT<Montgomery<MOD> > = BorderForFFT<Mod<MOD> >; \
  template <> inline const Mod<MOD> ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Mod<MOD> >] { static const Power_constexpr<Mod<MOD>,LimitOfPowerForFFT<Mod<MOD> > > PRT{ PR }; return PRT.Get(); } \
  template <> inline const Mod<MOD> ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Mod<MOD> >] { static const Power_constexpr<Mod<MOD>,LimitOfPowerForFFT<Mod<MOD> > > IPRT{ IPR }; return IPRT.Get(); } \
  template <> inline const Montgomery<MOD> ( &PrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Montgomery<MOD> >] { static const Power_constexpr<Montgomery<MOD>,LimitOfPowerForFFT<Montgomery<MOD> > > PRT{ PR }; return PRT.Get(); } \
  template <> inline const Montgomery<MOD> ( &InversePrimitiveRootOfTwoForFFT() noexcept )[LimitOfPowerForFFT<Montgomery<MOD> >] { static const Power_constexpr<Montgomery<MOD>,LimitOfPowerForFFT<Montgomery<MOD> > > IPRT{ IPR }; return IPRT.Get(); } \

