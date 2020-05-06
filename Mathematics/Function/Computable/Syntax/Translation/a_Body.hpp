// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Utility/VLTree/a_Body.hpp"

inline void InputPutNonConditionLine( ofstream& ofs , VLTree<string>::const_iterator& itr_e , const string& variable_name , const string& variable_type_name , string& language , const string& style ) { TRY_CATCH( InputPutNonConditionLine_Body( ofs , ExpressionToString( itr_e ) , variable_name , variable_type_name , language , style ), const ErrorType& e , CALL( e ) ); }

inline void InputPrintLine( ofstream& ofs , VLTree<string>::const_iterator& itr_line , string& language , const string& style ) { TRY_CATCH( InputPrintLine_Body( ofs , SyntaxToString( itr_line , 2 ) , language , style ) , const ErrorType& e , CALL( e ) ); }

inline void InputReturnLine( ofstream& ofs , const string& function_expression_name , VLTree<string>::const_iterator& itr_line , string& language , const string& style ) { TRY_CATCH( InputReturnLine_Body( ofs , function_expression_name , SyntaxToString( itr_line , 2 ) , language , style ) , const ErrorType& e , CALL( e ) ); }


inline string LogicalAndToString( VLTree<string>::const_iterator& itr , string& language , const string& style ) { return LogicalConnectiveToString( itr , LandString() , language , style ); }

inline string LogicalOrToString( VLTree<string>::const_iterator& itr , string& language , const string& style ) { return LogicalConnectiveToString( itr , LorString() , language , style ); }


inline void PutKagi( string& s ) noexcept { s = "Åu" + s + "Åv"; }
inline void PutParenthesis( string& s ) noexcept { s = "( " + s + " )"; }
