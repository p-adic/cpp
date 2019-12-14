// Position/a_Macro.hpp

#pragma once

#define POSITION __FILE__ , __LINE__ , __PRETTY_FUNCTION__ 
#define CALL( e ) IndicateCall( POSITION , e ) 
#define CALL_P( e , ... ) IndicateCall( POSITION , e , ARGUMENTS( __VA_ARGS__ ) ) 
