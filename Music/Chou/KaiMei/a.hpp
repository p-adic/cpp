// c:/Users/user/Documents/Programming/Music/Chou/KaiMei/a.hpp

#pragma once
#include "../../../Mathematics/Function/a.hpp"
#include "../../../Mathematics/Arithmetic/Mod/a.hpp"

class KaiMei :
  public Mod<7>
{

  string m_s;

public:
  inline KaiMei( const int& n ) noexcept;

  inline const string& Display() const noexcept;

  static inline const KaiMei& I() noexcept;
  static inline const KaiMei& II() noexcept;
  static inline const KaiMei& III() noexcept;
  static inline const KaiMei& IV() noexcept;
  static inline const KaiMei& V() noexcept;
  static inline const KaiMei& VI() noexcept;
  static inline const KaiMei& VII() noexcept;

private:
  static string SymbolTable( const int& n ) noexcept;

};

const KaiMei& operator+( const KaiMei& n1 , const int& n2 ) noexcept;
