// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/SubType/a.Macro

#pragma once

#define SPEC( TYPE_NAME , VARIABLE , REL )				\
									\
  class TYPE_NAME :							\
    public TypeOfComputableFunction					\
  {									\
									\
  public:								\
    using type = decay_t<decltype( VARIABLE )>::type;			\
									\
  public:								\
    static inline const string& GetName() { return GetSyntax().GetNodeString( 2 ); }; \
    static inline const SyntaxOfComputableFunction& GetSyntax() noexcept { static const SyntaxOfComputableFunction t{ TypeString() , SubTypeString() , TO_STRING( TYPE_NAME ) , ( VARIABLE ).Get() , GetRelation().Get() }; return t; }; \
    static inline const VariableSymbol<type>& GetVariable() noexcept { return VARIABLE ; }; \
    static inline const RelationSymbol<type>& GetRelation() noexcept { static const RelationSymbol<type> CONNECT( REL , _copy ) = REL; return r; }; \
									\
									\
  };									\
									\

