// c:/Users/user/Documents/Programming/Utility/Sort/VLArray/a.hpp

#pragma once
#include "../../VLArray/a.hpp"

template <typename T>
void Sort( VLArray<T>& a , const string& method = "normal" , const VLArray<int>& option = VLArray<int>() );


template <typename T>
void NormalSort( VLArray<T>& a , const VLArray<int>& option = VLArray<int>() );

template <typename T>
void NormalSortNoCut( VLArray<T>& a );

template <typename T>
void NormalSortCut( VLArray<T>& a , const uint& cut_length , const bool& cut_large );


template <typename T>
void MergeSort( VLArray<T>& a , const VLArray<int>& option = VLArray<int>() );

template <typename T>
void MergeSortNoCut( VLArray<T>& a );

template <typename T>
void MergeSortCut( VLArray<T>& a , const uint& cut_length , const bool& cut_large , const uint& normal_method_length = 2 );
