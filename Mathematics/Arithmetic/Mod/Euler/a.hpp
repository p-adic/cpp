// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a.hpp

#pragma once

template <typename INT> inline INT EulerFunction( const INT& n );

// ๑ฎnฬf๖๐Pษi[ตAf๖ฬw๐exponentษi[ท้B
template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent );

template <typename INT> inline INT CarmichaelFunction( const INT& n );

// ๑ฎnฬf๖๐Pษi[ตAf๖ฬw๐exponentษi[ตAf๖ฬwๆ๐P_powerษi[ท้B
template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power );

void CarmichaelTransformation( vector<uint>& exponent );
