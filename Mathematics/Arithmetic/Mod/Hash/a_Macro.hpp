// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Hash/a_Macro.hpp

#pragma once
#include "../../../../Utility/Set/a_Macro.hpp"

#define DEFINITION_OF_HASH_FOR_MOD( MOD )				\
  inline size_t hash<MOD>::operator()( const MOD& n ) const { static const hash<decltype( n.Represent() )> h; return h( n.Represent() ); } \

