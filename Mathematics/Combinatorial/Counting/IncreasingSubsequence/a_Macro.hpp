// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/IncreasingSubsequence/a_Macro.hpp

#pragma once
#define COUNT_INCREASING_SUBSEQUENCE( INT , PREV , ANSWER , ... )	\
  assert( size <= size_max );						\
  map<T,int> TheAtsu{};							\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    TheAtsu[a[i]];							\
									\
  }									\
									\
  int length = 0;							\
									\
  for( auto itr = TheAtsu.begin() , end = TheAtsu.end() ; itr != end ; itr++ ){	\
									\
    itr->second = length++;						\
									\
  }									\
									\
  BIT<INT,size_max> count{};						\
  const INT one{ __VA_ARGS__ };						\
									\
  for( int i = 0 ; i < size ; i++ ){					\
									\
    const int& n = TheAtsu[a[i]];					\
    count.Add( n , one + count.IntervalSum( 0 , PREV ) );		\
									\
  }									\
									\
  const INT answer = count.IntervalSum( 0 , length - 1 );		\
  return ANSWER								\


#ifdef DEBUG
  #define CERR( MESSAGE ) cerr << MESSAGE << endl;
#else
  #define CERR( MESSAGE ) 
#endif

// ìÒï™íTçıÉeÉìÉvÉåÅ[Ég
// EXPRESSIONÇ™ANSWERÇÃçLã`íPí≤ä÷êîÇÃéûÅAEXPRESSION >= TARGETÇÃêÆêîâÇäiî[ÅB
#define BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , DESIRED_INEQUALITY , TARGET , INEQUALITY_FOR_CHECK , UPDATE_U , UPDATE_L , UPDATE_ANSWER ) \
  static_assert( ! is_same<TYPE_OF( TARGET ),uint>::value && ! is_same<TYPE_OF( TARGET ),ull>::value ); \
  ll ANSWER = MINIMUM;							\
  if( MINIMUM <= MAXIMUM ){						\
    ll VARIABLE_FOR_BINARY_SEARCH_L = MINIMUM;				\
    ll VARIABLE_FOR_BINARY_SEARCH_U = MAXIMUM;				\
    ANSWER = ( VARIABLE_FOR_BINARY_SEARCH_L + VARIABLE_FOR_BINARY_SEARCH_U ) / 2; \
    ll VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH;			\
    while( VARIABLE_FOR_BINARY_SEARCH_L != VARIABLE_FOR_BINARY_SEARCH_U ){ \
      VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH = ( EXPRESSION ) - ( TARGET ); \
      CERR( "ìÒï™íTçıíÜÅF " << VARIABLE_FOR_BINARY_SEARCH_L << "<=" << ANSWER << "<=" << VARIABLE_FOR_BINARY_SEARCH_U << ":" << EXPRESSION << "-" << TARGET << "=" << VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH ); \
      if( VARIABLE_FOR_DIFFERENCE_FOR_BINARY_SEARCH INEQUALITY_FOR_CHECK 0 ){	\
	VARIABLE_FOR_BINARY_SEARCH_U = UPDATE_U;			\
      } else {								\
	VARIABLE_FOR_BINARY_SEARCH_L = UPDATE_L;			\
      }									\
      ANSWER = UPDATE_ANSWER;						\
    }									\
    CERR( "ìÒï™íTçıèIóπÅF " << VARIABLE_FOR_BINARY_SEARCH_L << "<=" << ANSWER << "<=" << VARIABLE_FOR_BINARY_SEARCH_U << ":" << EXPRESSION << ( EXPRESSION > TARGET ? ">" : EXPRESSION < TARGET ? "<" : "=" ) << TARGET ); \
    CERR( ( EXPRESSION DESIRED_INEQUALITY TARGET ? "ìÒï™íTçıê¨å˜" : "ìÒï™íTçıé∏îs" ) ); \
    assert( EXPRESSION DESIRED_INEQUALITY TARGET );			\
  } else {								\
    CERR( "ìÒï™íTçıé∏îsÅF " << MINIMUM << ">" << MAXIMUM );		\
    assert( MINIMUM <= MAXIMUM );					\
  }									\

// íPí≤ëùâ¡ÇÃéûÇ…EXPRESSION >= TARGETÇÃç≈è¨âÇäiî[ÅB
#define BS1( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , TARGET , >= , ANSWER , ANSWER + 1 , ( VARIABLE_FOR_BINARY_SEARCH_L + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \

// íPí≤ëùâ¡ÇÃéûÇ…EXPRESSION <= TARGETÇÃç≈ëÂâÇäiî[ÅB
#define BS2( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , TARGET , > , ANSWER - 1 , ANSWER , ( VARIABLE_FOR_BINARY_SEARCH_L + 1 + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \

// íPí≤å∏è≠ÇÃéûÇ…EXPRESSION >= TARGETÇÃç≈ëÂâÇäiî[ÅB
#define BS3( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , >= , TARGET , < , ANSWER - 1 , ANSWER , ( VARIABLE_FOR_BINARY_SEARCH_L + 1 + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \
    
// íPí≤å∏è≠ÇÃéûÇ…EXPRESSION <= TARGETÇÃç≈è¨âÇäiî[ÅB
#define BS4( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , TARGET )		\
  BS( ANSWER , MINIMUM , MAXIMUM , EXPRESSION , <= , TARGET , <= , ANSWER , ANSWER + 1 , ( VARIABLE_FOR_BINARY_SEARCH_L + VARIABLE_FOR_BINARY_SEARCH_U ) / 2 ) \
