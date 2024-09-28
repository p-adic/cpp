// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/SFINAE/a.hpp

#pragma once

template <typename PE> auto CheckPE( const PE& pe ) -> decltype( pe.IsComposite( 0 ) , true_type() );
template <typename...> false_type CheckPE( ... );

template <typename T>
constexpr bool IsPE = decltype( CheckPE( declval<T>() ) )();
