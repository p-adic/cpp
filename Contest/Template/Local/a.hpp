// c:/Users/user/Documents/Programming/Contest/Template/Local/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/Set/a.hpp"
#include "../../../Utility/Tuple/a.hpp"
#include "../../../Utility/Vector/a.hpp"
#include "../../../Utility/Set/Map/a.hpp"
#include "../../../Utility/StdStream/a.hpp"
#include "../../../Utility/String/a.hpp"
#include "../../../Utility/String/ToArray/a.hpp"
#include "../../../Utility/BinarySearch/Debug/a.hpp"
#include "../../../Utility/TwoPointerApproach/Debug/a.hpp"

#include "../../../Mathematics/Algebra/Monoid/Group/Module/a.hpp"
#include "../../../Mathematics/Geometry/Graph/Grid/a.hpp"
#include "../../../Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp"
#include "../../../Mathematics/Combinatorial/Loop/a.hpp"

CEXPR( uint , P , 998244353 );
using MP = Mod<P>;

inline void AlertAbort( int n );
void AutoCheck( int& exec_mode , const bool& use_getline , const bool& sample_check , const string& problem_order );
void Solve();
void SampleCheck( const string& sample_path , const string& input_path , const string& output_path , const string& problem_order , const int& test_case_num_bound , ifstream& ifs , ofstream& ofs );
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

ifstream ifs{};
ofstream ofs{};
const string sample_path = "C:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/Sample/";

#ifdef SAMPLE_CHECK
  static_assert( TO_CHAR( SAMPLE_CHECK )[0] != 'd'  );
  constexpr bool sample_check = true;
  const string problem_order = TO_STRING( SAMPLE_CHECK );
  const string input_path = sample_path + problem_order + "/input/sample";
  const string output_path = sample_path + problem_order + "/output/exec";
  ofstream ofs_err{ "C:/Users/user/Documents/Programming/Contest/AutoCheck/SampleMemoriser/cerr.txt" , ios::trunc };
#else
  constexpr bool sample_check = false;
  const string problem_order = "dummy";
  const string input_path = "dummy.txt";
  const string output_path = "dummy.txt";
#endif

