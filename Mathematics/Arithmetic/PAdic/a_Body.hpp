// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/PAdic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/VLArray/a_Body.hpp"

#include "../Mod/Residue/a_Body.hpp"

template <INT_TYPE_FOR_ADIC_INT P , INT_TYPE_FOR_ADIC_INT LENGTH> inline AdicInt<P,LENGTH>::AdicInt( const INT_TYPE_FOR_ADIC_INT& n ) noexcept : m_expansion( Expand( n ) ) , m_n( n ) {}

template <INT_TYPE_FOR_ADIC_INT P , INT_TYPE_FOR_ADIC_INT LENGTH> inline const VLArray<INT_TYPE_FOR_ADIC_INT>& AdicInt<P,LENGTH>::GetExpansion() const noexcept { return m_expansion; }
template <INT_TYPE_FOR_ADIC_INT P , INT_TYPE_FOR_ADIC_INT LENGTH> inline const INT_TYPE_FOR_ADIC_INT& AdicInt<P,LENGTH>::GetValue() const noexcept { return m_n; }

template <INT_TYPE_FOR_ADIC_INT P , INT_TYPE_FOR_ADIC_INT LENGTH>
const VLArray<INT_TYPE_FOR_ADIC_INT>& AdicInt<P,LENGTH>::Expand( const INT_TYPE_FOR_ADIC_INT& n ) noexcept
{

  static VLArray<INT_TYPE_FOR_ADIC_INT> memory_n{};
  static VLArray<VLArray<INT_TYPE_FOR_ADIC_INT> > memory_answer{};

  if( P == 0 ){

    // É_É~Å[
    return memory_n;

  }

  auto itr_n = memory_n.begin() , end_n = memory_n.end();
  auto itr_answer = memory_answer.begin();

  while( itr_n != end_n ){

    if( *itr_n == n ){

      return *itr_answer;

    }

    itr_n++;
    itr_answer++;

  }

  INT_TYPE_FOR_ADIC_INT n_copy = n;
  VLArray<INT_TYPE_FOR_ADIC_INT> answer{};

  if( LENGTH == 0 ){
  
    for( INT_TYPE_FOR_ADIC_INT i = 0 ; n_copy != 0 ; i++ ){

      const INT_TYPE_FOR_ADIC_INT d = Residue<INT_TYPE_FOR_ADIC_INT>( P , n_copy );
      answer.push_back( d );
      n_copy -= d;
      n_copy /= P;

    }

  } else {

    for( INT_TYPE_FOR_ADIC_INT i = 0 ; i < LENGTH && n_copy != 0 ; i++ ){

      const INT_TYPE_FOR_ADIC_INT d = Residue<INT_TYPE_FOR_ADIC_INT>( P , n_copy );
      answer.push_back( d );
      n_copy -= d;
      n_copy /= P;

    }

  }

  memory_n.push_back( n );
  memory_answer.push_back( answer );
  return memory_answer.back();

}
