// c:/Users/user/Documents/Programming/Mathematics/Game/Nim/Acyclic/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/972037ÅiAcyclicBoundedNimÅj

template <typename GRAPH , typename VALUE> ret_t<VALUE,inner_t<GRAPH>> AcyclicNim( GRAPH& G , VALUE&& a );
template <typename GRAPH , typename VALUE , typename INT> inline ret_t<VALUE,inner_t<GRAPH>> AcyclicBoundedNim( GRAPH& G , VALUE&& a , INT bound );
