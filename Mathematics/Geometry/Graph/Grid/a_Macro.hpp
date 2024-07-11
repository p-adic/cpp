// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a_Macro.hpp

#pragma once

#define SET_GRID H_minus = H - 1; W_minus = W - 1; HW = ll( H ) * W
#define SET_HW( h , w ) H = h; W = w; SET_GRID
#define CIN_HW cin >> H >> W; SET_GRID
