// c:/Users/user/Documents/Programming/Contest/Template/include/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "c:/Users/user/Documents/Programming/Utility/Set/a.hpp"
#include "c:/Users/user/Documents/Programming/Utility/Tuple/a.hpp"
#include "c:/Users/user/Documents/Programming/Utility/Vector/a.hpp"
#include "c:/Users/user/Documents/Programming/Utility/StdStream/a.hpp"

#include "c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a.hpp"
#include "c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/a.hpp"
#include "c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp"

CEXPR( uint , P , 998244353 );
using MP = Mod<P>;

inline void AlertAbort( int n ) { CERR( "abort関数が呼ばれました。assertマクロのメッセージが出力されていない場合はオーバーフローの有無を確認をしてください。" ); }
void AutoCheck( int& exec_mode , const bool& use_getline );
inline void Solve();
inline void Experiment();
inline void SmallTest();
inline void RandomTest();
inline void BreakPoint( const int& LINE ) {}
int exec_mode;
CEXPR( int , solve_mode , 0 );
CEXPR( int , sample_debug_mode , 1 );
CEXPR( int , submission_debug_mode , 2 );
CEXPR( int , library_search_mode , 3 );
CEXPR( int , experiment_mode , 4 );
CEXPR( int , small_test_mode , 5 );
CEXPR( int , random_test_mode , 6 );
#ifdef USE_GETLINE
  CEXPR( bool , use_getline , true );
#else
  CEXPR( bool , use_getline , false );
#endif
