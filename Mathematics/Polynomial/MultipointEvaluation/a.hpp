// c:/Users/user/Documents/Programming/Mathematics/Polynomial/MultipointEvaluation/a.hpp

#pragma once
#include "../a.hpp"

template <typename T , template <typename> typename V1 , template <typename> typename V2> inline void SetMultipointEvaluation( const Polynomial<T>& f , const V1<T>& point , V2<T>& answer );

template <typename T , template <typename> typename V1 , template <typename> typename V2 , template <typename> typename V3>
void SetPointTreeEvaluation( const Polynomial<T>& f , const V1<V2<Polynomial<T> > >& point_tree , V3<T>& answer );

// beginで総乗にアクセスできるようにするためV1はpush_frontを持つ必要がある。
template <typename T , template <typename> typename V1 , template <typename> typename V2 >
void SetProductTree( V1<V2<T> >& product_tree );

// SetProductTreeの要件からV2はpush_frontを持つ必要がある。
template <typename T , template <typename> typename V1 , template <typename> typename V2 , template <typename> typename V3>
void SetPointTree( const V1<T>& point , V2<V3<Polynomial<T> > >& point_tree );
