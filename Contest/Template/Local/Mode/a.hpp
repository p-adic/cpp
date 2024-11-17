// c:/Users/user/Documents/Programming/Contest/Template/Local/Mode/a.hpp

#pragma once

constexpr int solve_mode = 0;
constexpr int sample_check_mode = solve_mode + 1;
constexpr int sample_debug_mode = sample_check_mode + 1;
constexpr int submission_debug_mode = sample_debug_mode + 1;
constexpr int library_search_mode = submission_debug_mode + 1;
constexpr int sample_analysis_mode = library_search_mode + 1;
constexpr int experiment_mode = sample_analysis_mode + 1;
constexpr int small_test_mode = experiment_mode + 1;
constexpr int random_test_mode = small_test_mode + 1;
constexpr int quit_mode = random_test_mode + 1;

