// c:/Users/user/Documents/Programming/Contest/AutoCheck/SampleAnalyser/a.hpp

#pragma once
#include "../a_Macro.hpp"
#include "a_Macro.hpp"

// デバッグモードでないと翻訳単位ごとに異なる実装をDynamicModが持ってしまうるので実行時に
// Segmentation Faultとなる。
#include "../../../Mathematics/Arithmetic/Mod/DynamicModulo/Debug/a.hpp"

AC( SampleAnalyser );
void PowerAnalysis( const int& sample_count , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str );
void InputPolynomialAnalysis1( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str );
void InputPolynomialAnalysis2( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str );
void InputPolynomialAnalysis3( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str );
void InputLinearAnalysis4( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str );
void InputExponentialAnalysis1( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str );
void InputExponentialAnalysis2( const int& sample_count , const vector<vector<ll>>& input , const vector<DynamicMod>& output , const int& scale , const int& P , const string& P_str );
