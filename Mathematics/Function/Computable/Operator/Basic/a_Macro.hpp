// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a_Macro.hpp

#pragma once

// 2-ary
#define DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( RET , OPERATOR )		\
									\
  inline ExpressionOfComputableFunction< RET > operator OPERATOR ( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \


#define DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( RET , OPERATOR , SYMB )	\
									\
  DECLARATION_OF_TWO_ARY_BASIC_FUNCTION( RET , OPERATOR ){ return CONNECT( SYMB , SymbolApplication )( e1 , e2 ); } \
  

#define DECLARATION_OF_BOUNDED_EXISTENCE( RET )				\
									\
  PrettyRelation< RET ,Args...> ExistenceSymbol( const PrettyVariable< RET >& n , const RelationSymbol<BaseTypeOf< RET >::type,Args...>& r ) \
    
#define DEFINITION_OF_BOUNDED_EXISTENCE( RET )				\
									\
  DECLARATION_OF_BOUNDED_EXISTENCE( RET )				\
  {									\
									\
    PrettyRelation< RET ,Args...> r_copy{ r };				\
									\
    VLTree<string>& t_r = r_copy.Ref();					\
    auto itr_r = t_r.LeftMostNode();					\
    itr_r++;								\
    itr_r++;								\
    itr_r++;								\
    itr_r[2];								\
    const string x_copy = *itr_r;					\
    const string& n_copy = n.GetNodeString( 2 );			\
    *itr_r = n_copy;							\
									\
    const string quantifier						\
    {									\
									\
      "\\exists" + SpaceString() +					\
	x_copy + SpaceString() +					\
	LeqString() + SpaceString() +					\
	n_copy + CommaString() + SpaceString()				\
									\
	};								\
									\
    SeparatorOfComputableFunction separator_copy = r_copy.GetSeparator(); \
    VLTree<string>& t_sep = separator_copy.Ref();			\
    auto itr_sep = t_sep.LeftMostNode();				\
    const string symb = *itr_sep;					\
    t_sep.erase( itr_sep );						\
    *itr_sep = quantifier + symb + x_copy + *itr_sep;			\
									\
    r_copy.SetSymbol( quantifier + r_copy.GetNodeString( 2 ) );		\
    r_copy.SetSeparator( separator_copy );				\
    r_copy.SetTotality( Recursiveness() );				\
									\
    return r_copy;							\
									\
  }									\
  

