// c:/Users/user/Documents/Programming/Utility/Set/a_Alias.hpp

#pragma once

template <typename T>
using Set = conditional_t<is_constructible_v<unordered_set<T>>,unordered_set<T>,conditional_t<is_ordered::value<T>,set<T>,void>>;

template <typename T , typename U>
using Map = conditional_t<is_constructible_v<unordered_map<T,int>>,unordered_map<T,U>,conditional_t<is_ordered::value<T>,map<T,U>,void>>;
