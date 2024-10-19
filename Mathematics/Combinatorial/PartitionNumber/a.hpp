// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/PartitionNumber/a.hpp

#pragma once
// verify:
// PartitionNumber‚Ìpython”Å (https://yukicoder.me/submissions/1021227)
// UpperBoundedPartitionNumber (https://yukicoder.me/submissions/1021223)


// nˆÈ‰º‚Ì”ñ•‰®”i‚ğ³®”‚Ì¸‡˜a‚É•ªŠ„‚·‚éŒÂ”‚ğanswer[i]‚ÉŠi”[‚·‚éBiO(n^2)j
template <typename INT> vector<INT> PartitionNumber( const int& n );
// nˆÈ‰º‚Ì”ñ•‰®”i‚ğjˆÈã‚Ì³®”‚Ì¸‡˜a‚É•ªŠ„‚·‚éŒÂ”‚ğanswer[i][j]‚ÉŠi”[‚·‚éBiO(n^2)j
template <typename INT> vector<vector<INT>> LowerBoundedPartitionNumber( const int& n );
// nˆÈ‰º‚Ì”ñ•‰®”i‚ğjˆÈ‰º‚Ì³®”‚Ì¸‡˜a‚É•ªŠ„‚·‚éŒÂ”‚ğanswer.first[i][j]‚ÉŠi”[‚·‚éBiO(n^2)j
template <typename INT> vector<vector<INT>> UpperBoundedPartitionNumber( const int& n );
// nˆÈ‰º‚Ì”ñ•‰®”i‚ğ”ñ•‰®”jŒÂ‚Ì¸‡˜a‚É•ªŠ„‚·‚éŒÂ”‚â
// nˆÈ‰º‚Ì”ñ•‰®”i‚ğ³®”jŒÂˆÈ‰º‚Ì¸‡˜a‚É•ªŠ„‚·‚éŒÂ”‚Æ‚à“™‚µ‚¢B

