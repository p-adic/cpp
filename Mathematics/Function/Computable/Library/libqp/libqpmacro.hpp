#define CONNECT( S1 , S2 ) SUBSTITUTE_CONNECT( S1 , S2 ) 
#define SUBSTITUTE_CONNECT( S1 , S2 ) S1 ## S2 

#define TO_STRING( ... ) SUBSTITUTE_TO_STRING( __VA_ARGS__ ) 
#define SUBSTITUTE_TO_STRING( ... ) to_string( #__VA_ARGS__ ) 

#define POSITION __FILE__ , __LINE__ , __PRETTY_FUNCTION__ 
#define CALL( e ) IndicateCall( POSITION , e ) 
#define CALL_P( e , ... ) IndicateCall( POSITION , e , ARGUMENTS( __VA_ARGS__ ) ) 

#ifdef DEBUG

  #define MISMATCH( ... ) \
    BREAK; \
    ThrowMismatchType< __VA_ARGS__ >( POSITION ) 

#else

  #define MISMATCH( ... ) ThrowMismatchType< __VA_ARGS__ >( POSITION ) 

#endif

#define g_OCCURRENCE_OF_MISMATCH_TYPE ( *GLOBAL_VARIABLE( bool , OCCURRENCE_OF_MISMATCH_TYPE , false ) ) 
