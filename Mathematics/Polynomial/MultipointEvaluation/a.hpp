// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a.hpp

#pragma once
#include "../a.hpp"

template <typename T , typename V> inline void SetMultipointEvaluation( const Polynomial<T>& f , const V& point , V& answer );

template <typename T , typename V>
void SetMultipointEvaluation( const Polynomial<T>& f , const VLArray<VLArray<Polynomial<T> > >& point_tree , V& answer );template <typename T> inline void SetMultipointEvaluation( const Polynomial<T>& f , const VLArray<T>& point , VLArray<T>& answer );

template <typename T>
void SetProductTree( VLArray<VLArray<T> >& product_tree );

template <typename T , typename V>
void SetPointTree( const V& point , VLArray<VLArray<Polynomial<T> > >& point_tree );
