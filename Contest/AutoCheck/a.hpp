// c:/Users/user/Documents/Programming/Contest/AutoCheck/a.hpp

#pragma once
#include "a_Macro.hpp"

void AutoCheck( int& exec_mode , const bool& use_getline );
AC( DebugHintWA );
AC( DebugHint );

constexpr int solve_mode = 0;
constexpr int sample_debug_mode = solve_mode + 1;
constexpr int submission_debug_mode = sample_debug_mode + 1;
constexpr int library_search_mode = submission_debug_mode + 1;
constexpr int sample_analysis_mode = library_search_mode + 1;
constexpr int experiment_mode = sample_analysis_mode + 1;
constexpr int small_test_mode = experiment_mode + 1;
constexpr int random_test_mode = small_test_mode + 1;
constexpr int quit_mode = random_test_mode + 1;
