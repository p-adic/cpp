// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/a_Macro.hpp

#pragma once

#define DEFINITION_OF_LIST_OF_LINES( RET )				\
  template <typename... Rets> inline LineOfDefinitionOfComputableFunction< RET >::LineOfDefinitionOfComputableFunction( const Dummy<Rets...>& dummy , const Rets&... lines ) : SyntaxOfComputableFunction( LineString() , ListString() , lines.Get()... ) {} \


#define DEFINITION_OF_IF_LINE( RET )					\
  inline LineOfDefinitionOfComputableFunction< RET >::LineOfDefinitionOfComputableFunction( const int& dummy , const ConditionOfComputableFunction& condition , const LineOfDefinitionOfComputableFunction< RET >& line ) : SyntaxOfComputableFunction( LineString() , IfString() , condition.Get() , line.Get() ) {} \
									\

#define DEFINITION_OF_SUPPOSE_LINE( RET )				\
  template <typename Ret1 , typename Ret2 , typename... Rets> inline LineOfDefinitionOfComputableFunction< RET >::LineOfDefinitionOfComputableFunction( const Dummy<Ret1,Ret2,Rets...>& dummy , const ConditionOfComputableFunction& condition , const Ret1& line1 , const Ret2& line2 , const Rets&... lines ) : LineOfDefinitionOfComputableFunction( dummy , condition , LineOfDefinitionOfComputableFunction< RET >( dummy , line1 , line2 , lines... ) ) {} \
									\


