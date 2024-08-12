// c:/Users/user/Documents/Programming/Utility/Tuple/Hash/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../Set/a.hpp"

template <typename T> DECLARATION_OF_HASH( tuple<T> );
template <typename T , typename U> DECLARATION_OF_HASH( pair<T,U> );
template <typename T , typename U> DECLARATION_OF_HASH( tuple<T,U> );
template <typename T , typename U , typename V> DECLARATION_OF_HASH( tuple<T,U,V> );
template <typename T , typename U , typename V , typename W> DECLARATION_OF_HASH( tuple<T,U,V,W> );

