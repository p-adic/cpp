// c:/Users/user/Documents/Programming/Contest/Template/include/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/Set/a.hpp"
#include "../../../Utility/Tuple/a.hpp"
#include "../../../Utility/Vector/a.hpp"
#include "../../../Utility/Set/Map/a.hpp"
#include "../../../Utility/StdStream/a.hpp"
#include "../../../Utility/String/a.hpp"

#include "../../../Mathematics/Algebra/Monoid/Group/Module/a.hpp"
#include "../../../Mathematics/Geometry/Graph/Grid/a.hpp"
#include "../../../Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp"

CEXPR( uint , P , 998244353 );
using MP = Mod<P>;

inline void AlertAbort( int n );
void AutoCheck( int& exec_mode , const bool& use_getline );
inline void Solve();
inline void Experiment();
inline void SmallTest();
inline void RandomTest( const int& test_case_num );
inline void BreakPoint( const int& LINE ) {}

#ifdef USE_GETLINE
  CEXPR( bool , use_getline , true );
#else
  CEXPR( bool , use_getline , false );
#endif

int exec_mode;

#ifdef SUBMIT_ONLY
  CEXPR( bool , submit_only , true );
#else
  CEXPR( bool , submit_only , false );
#endif

void CompareAnswer( const string& sample_path , const string& problem_order , const string& sample_num );
ifstream ifs{ "dummy.txt" };
ofstream ofs{ "dummy.txt" };
const string sample_path = "C:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/Sample/";
string sample_num;

#ifdef SAMPLE_CHECK
  constexpr bool sample_check = true;
  const string problem_order = TO_STRING( SAMPLE_CHECK );
  const string input_path = sample_path + problem_order + "/input/sample";
  const string output_path = sample_path + problem_order + "/output/exec";
#else
  constexpr bool sample_check = false;
  string problem_order = "dummy";
  string input_path = "dummy.txt";
  string output_path = "dummy.txt";
#endif

ifstream sample_count{ sample_path + problem_order + "/count.txt" };

