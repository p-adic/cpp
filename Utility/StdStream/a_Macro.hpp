// c:/Users/user/Documents/Programming/Utility/StdStream/a_Macro.hpp

#pragma once

#define DECLARATION_OF_COUT_FOR_VECTOR( V ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg )
#define DEFINITION_OF_COUT_FOR_VECTOR( V ) DECLARATION_OF_COUT_FOR_VECTOR( V ) { auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os : os << " " ) << *itr; itr++; } return os; }
