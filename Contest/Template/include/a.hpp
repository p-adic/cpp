// c:/Users/user/Documents/Programming/Contest/Template/include/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "c:/Users/user/Documents/Programming/Utility/Set/a.hpp"
#include "c:/Users/user/Documents/Programming/Utility/Tuple/a.hpp"
#include "c:/Users/user/Documents/Programming/Utility/Vector/a.hpp"
#include "c:/Users/user/Documents/Programming/Utility/Set/Map/a.hpp"
#include "c:/Users/user/Documents/Programming/Utility/StdStream/a.hpp"

#include "c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a.hpp"
#include "c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a.hpp"
#include "c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp"

CEXPR( uint , P , 998244353 );
using MP = Mod<P>;

inline void AlertAbort( int n );
void AutoCheck( int& exec_mode , const bool& use_getline );
inline void Solve();
inline void Experiment();
inline void SmallTest();
inline void RandomTest( const int& test_case_num );
inline void BreakPoint( const int& LINE ) {}
CEXPR( int , solve_mode , 0 );
CEXPR( int , sample_debug_mode , 1 );
CEXPR( int , submission_debug_mode , 2 );
CEXPR( int , library_search_mode , 3 );
CEXPR( int , experiment_mode , 5 );
CEXPR( int , small_test_mode , 6 );
CEXPR( int , random_test_mode , 7 );
#ifdef USE_GETLINE
  CEXPR( bool , use_getline , true );
#else
  CEXPR( bool , use_getline , false );
#endif
int exec_mode = solve_mode;
#ifdef SUBMIT_ONLY
  CEXPR( bool , submit_only , true );
#else
  CEXPR( bool , submit_only , false );
#endif
