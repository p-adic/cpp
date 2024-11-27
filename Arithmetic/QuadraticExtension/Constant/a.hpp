// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/Constant/a.hpp

#pragma once

template <typename INT , int NUM> class QuadraticExtensions;

template <typename INT , int NUM>
class ConstantsForQuadraticExtensions
{

  friend class QuadraticExtensions<INT,NUM>;
  
private:
  ConstantsForQuadraticExtensions() = delete;
  static INT g_D;

};
