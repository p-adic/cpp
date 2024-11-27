// c:/Users/user/Documents/Programming/Utility/Vector/Debug/a_Macro.hpp

#pragma once

#define DECLARATION_OF_COUT_FOR_VECTOR( V ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg )

#define DEFINITION_OF_COUT_FOR_VECTOR( V , LBRACK , SEPARATOR , RBRACK ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<Arg>& arg ) { os << LBRACK; auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os : os << SEPARATOR << " " ) << *itr; itr++; } return os << RBRACK; }

#define DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , W , LBRACK , SEPARATOR , RBRACK ) template <class Traits , typename Arg> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const V<W<Arg>>& arg ) { os << LBRACK << "\n"; auto begin = arg.begin() , end = arg.end(); auto itr = begin; while( itr != end ){ ( itr == begin ? os << " " : os << SEPARATOR << "\n " ) << *itr; itr++; } return os << "\n" << RBRACK; }

#define DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR( V , LBRACK , SEPARATOR , RBRACK ) \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , vector , LBRACK , SEPARATOR , RBRACK ); \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , list , LBRACK , SEPARATOR , RBRACK ); \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , set , LBRACK , SEPARATOR , RBRACK ); \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , unordered_set , LBRACK , SEPARATOR , RBRACK ); \
  DEFINITION_OF_COUT_FOR_DOUBLE_VECTOR_BODY( V , multiset , LBRACK , SEPARATOR , RBRACK ); \


