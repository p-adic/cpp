// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/a_Macro.hpp

#pragma once

#define IF( CONDITION , ... ) LineOfDefinitionOfComputableFunction( 0 , CONDITION , __VA_ARGS__ ) 
#define RETURN( VALUE ) LineOfDefinitionOfComputableFunction( VALUE ) 


#define DEFINITION_OF_LIST( RET )					\
  template <typename... ARGS> inline LineOfDefinitionOfComputableFunction< RET >::LineOfDefinitionOfComputableFunction( const LineOfDefinitionOfComputableFunction< RET >& line1 , const LineOfDefinitionOfComputableFunction< RET >& line2 , const LineOfDefinitionOfComputableFunction<ARGS>&... args ) : SyntaxOfComputableFunction( "line" , "list" , line1.Get() , line2.Get() , args.Get()... ) {} \


#define DEFINITION_OF_IF( RET )						\
  inline LineOfDefinitionOfComputableFunction< RET >::LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const LineOfDefinitionOfComputableFunction< RET >& line ) : SyntaxOfComputableFunction( "line" , "if" , condition.Get() , line.Get() ) {} \
									\

#define DEFINITION_OF_SUPPOSE( RET )					\
  template <typename Ret1 , typename Ret2 , typename... ARGS> inline LineOfDefinitionOfComputableFunction< RET >::LineOfDefinitionOfComputableFunction( const Dummy<Ret1,Ret2,ARGS...>& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const ARGS&... lines ) : LineOfDefinitionOfComputableFunction( dummy , condition , LineOfDefinitionOfComputableFunction< RET >( line1 , line2 , lines... ) ) {} \
									\


