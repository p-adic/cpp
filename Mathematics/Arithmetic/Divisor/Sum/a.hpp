// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Sum/a.hpp

#pragma once

// n_maxˆÈ‰º‚ÌŠe³®”n‚É‘Î‚µAanswer[n]‚Éd_maxˆÈ‰º‚Ì³‚Ì–ñ”‚Ìexponentialæ‚Ì‘˜a‚ğ
// Ši”[‚µ‚Ä•Ô‚·B(O(min(n_max,d_max) log exponent + n_max log min(n_max,d_max)))
template <typename INT> vector<INT> DivisorSum( const INT& n_max , const INT& d_max , const int& exponent = 1 );
