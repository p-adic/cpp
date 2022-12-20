// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a.hpp

#pragma once
#include "../a.hpp"

template <typename T> inline void SetMultipointEvaluation( const Polynomial<T>& f , const VLArray<T>& point , VLArray<T>& answer );

template <typename T>
void SetMultipointEvaluation_Body( const Polynomial<T>& f , const VLArray<VLArray<Polynomial<T> > >& point_tree , VLArray<T>& answer );

template <typename T>
void SetPointTree( const VLArray<T>& point , VLArray<VLArray<Polynomial<T> > >& point_tree );
