// c:/Users/user/Documents/Programming/Utility/Sort/a.hpp

#pragma once
#include "../VLArray/a.hpp"

template <typename T>
void Sort( VLArray<T>& a , const string& method = "normal" , const VLArray<int>& option = VLArray<int>() );


template <typename T>
void NormalSort( VLArray<T>& a , const VLArray<int>& option = VLArray<int>() );

template <typename T>
void NormalSortNoCut( VLArray<T>& a );

template <typename T>
void NormalSortCut( VLArray<T>& a , const int& cut_length , const bool& cut_large );


template <typename T>
void MergeSort( VLArray<T>& a , const VLArray<int>& option = VLArray<int>() );

template <typename T>
void MergeSortNoCut( VLArray<T>& a );

template <typename T>
void MergeSortCut( VLArray<T>& a , const int& cut_length , const bool& cut_large );

template <typename T>
void MergeSortCutNormal( VLArray<T>& a , const int& cut_length , const bool& cut_large , const int& noral_method_length );
