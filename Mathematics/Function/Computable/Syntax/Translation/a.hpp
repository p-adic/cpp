// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/a.hpp

#pragma once
#include "../../../../../Utility/VLTree/a.hpp"
#include <fstream>

void DisplayTreeStructureOfDefinition( const string& function_name , const string& language );
void DisplayWritingTranslationOfDefinition( const string& function_name , const string& filename , const string& language );
void DisplayFileOpenError( const string& language );
void DisplayFinishedWriting( const string& language );

void InputDefinitionOfRecursiveSet( ofstream& ofs , const string& type_name , const string& definition , const string& language , const string& style );

void DisplayTreeStructure( const string& name , const string& language );
void InputTotality( ofstream& ofs , const string& totality , const string& language , const string& style );
void InputFunctionSignature( ofstream& ofs , const string& function_name , const string& argument_type_name , const string& argument_name , const string& return_type_name , const string& function_expression_name , const string& language , const string& style );
void InputRecursiveWay( ofstream& ofs , const string& language , const string& style );

void InputIndent( ofstream& ofs , const uint depth , string& language , const string& style );

// line
void InputLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style );
void InputListLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style );
void InputNonListLine( ofstream& ofs , const string& function_expression_name , const string& line_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style );

// If
void InputIfLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style );
void InputIfListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , string& language , const string& style );
void InputIfNonListLine( ofstream& ofs , const string& function_expression_name , const string& condition_name , VLTree<string>::const_iterator& itr_line , string& language , const string& style );

// Put
void InputPutLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style );
void InputPutConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_cond , const string& variable_name , string& language , const string& style );
void InputPutConditionLine_Body( ofstream& ofs , const string& b , const string& variable_name , string& language , const string& style );
inline void InputPutNonConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_e , const string& variable_name , const string& variable_type_name , string& language , const string& style );
void InputPutNonConditionLine_Body( ofstream& ofs , const string& e , const string& variable_name , const string& variable_type_name , string& language , const string& style );

// Characterisation
void InputCharacterisationLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const uint& depth , string& language , const string& style );

void InputUniqueExistenceLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style );
void InputUniqueExistenceNaturalNumberLine( ofstream& ofs , const string& local_variable , const string& bound , const string& condition , const string& variable_name , const string& variable_type_name , string& language , const string& style );
void InputUniqueExistenceStringLine( ofstream& ofs , const string& local_variable , const string& bound , const string& condition , const string& variable_name , const string& variable_type_name , string& language , const string& style );

void InputMinimumLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style );
void InputMinimumLine_Body( ofstream& ofs , const string& condition , const string& local_variable , const string& variable_name , const string& variable_type_name , string& language , const string& style );
void InputMaximumLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , const string& variable_name , const string& variable_type_name , string& language , const string& style );
void InputMaximumLine_Body( ofstream& ofs , const string& condition , const string& bound , const string& local_variable , const string& variable_name , const string& variable_type_name , string& language , const string& style );

// Print
inline void InputPrintLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , string& language , const string& style );
void InputPrintLine_Body( ofstream& ofs , const string& variable_name , string& language , const string& style );

//Exit
void InputExitLine( ofstream& ofs , const string& function_expression_name , string& language , const string& style );

// Return
inline void InputReturnLine( ofstream& ofs ,const string& function_expression_name , VLTree<string>::const_iterator& itr_line , string& language , const string& style );
void InputReturnLine_Body( ofstream& ofs , const string& function_expression_name , const string& return_name , string& language , const string& style );


const string& SyntaxToString( VLTree<string>::const_iterator& itr , const int& n );
string ListSyntaxToString( VLTree<VLTree<string>::const_iterator>& t , const int& n );

// 条件のイテレータitrから条件の文字列を構築
string ConditionToString( VLTree<string>::const_iterator& itr , bool& complicated , string& language , const string& style );

string NegationToString( VLTree<string>::const_iterator& itr , string& language , const string& style );
string NegationToString_Body( const string& b , string& language , const string& style );

string ImplicationToString( VLTree<string>::const_iterator& itr , string& language , const string& style );
string ImplicationToString_Body( const string& b0 , const string& b1 , string& language , const string& style );

string EquivalenceToString( VLTree<string>::const_iterator& itr , string& language , const string& style );
string EquivalenceToString_Body( const string& b0 , const string& b1 , string& language , const string& style );

string LogicalConnectiveToString( VLTree<string>::const_iterator& itr , const string& connective , string& language , const string& style );
inline string LogicalAndToString( VLTree<string>::const_iterator& itr , string& language , const string& style );
inline string LogicalOrToString( VLTree<string>::const_iterator& itr , string& language , const string& style );
void AddCommaForLogicalConnective( string& b , const string& connective ,  bool& second , const VLTree<string>::const_iterator& itr , string& language , const string& style );
string LogicalConnectiveSymbolToString( const string& connective , string& language , const string& style );


void PutWrap( string& s , const string& language );
inline void PutKagi( string& s ) noexcept;
inline void PutParenthesis( string& s ) noexcept;

