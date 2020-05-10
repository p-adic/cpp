// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/SubType/a.Macro

#pragma once

#define SUBSET( VARIABLE , RELATION )					\
									\
  EscapeString() + LbraceString() + SpaceString() +			\
  EscapeString() + SpaceString() +					\
  ( VARIABLE ).GetNodeString( 2 ) + SpaceString() +			\
  InString() + SpaceString() +						\
  ( VARIABLE ).GetNodeString( 3 , 2 ) + SpaceString() +			\
  VertString() + SpaceString() +					\
  ( RELATION ( VARIABLE ) ).GetNodeString( 2 ) + SpaceString() +	\
  EscapeString() + SpaceString() +					\
  EscapeString() + RbraceString()					\


#define SPEC_BODY( CLASS_NAME , TYPE_NAME , VARIABLE , REL )		\
									\
									\
  class CLASS_NAME :							\
    public TypeOfComputableFunction					\
  {									\
									\
  public:								\
    using base_type = decay_t<decltype( VARIABLE )>::type;		\
									\
  public:								\
    inline CLASS_NAME () noexcept :					\
      TypeOfComputableFunction						\
      (									\
									\
       TO_STRING( TYPE_NAME ) ,						\
       SubTypeString() ,						\
       SUBSET( GetVariable() , GetRelation() )				\
									\
									) \
    {};									\
									\
    static inline const string& GetName() { return GetSyntax().GetNodeString( 2 ); }; \
									\
    static inline const SyntaxOfComputableFunction& GetSyntax() noexcept \
    {									\
									\
      static const SyntaxOfComputableFunction t				\
      {									\
									\
	TypeString() ,							\
	  SubTypeString() ,						\
	  TO_STRING( TYPE_NAME ) ,					\
	  ( VARIABLE ).Get() ,						\
	  ( VARIABLE ).GetSubTree( 2 ) ,				\
	  GetRelation().Get()						\
									\
	  };								\
									\
      return t;								\
									\
    };									\
									\
  private:								\
    static inline const VariableSymbol<base_type>& GetVariable() noexcept \
    {									\
									\
      static const VariableSymbol<base_type> CONNECT( VARIABLE_FOR_ , TYPE_NANE ){ VARIABLE }; \
      return CONNECT( VARIABLE_FOR_ , TYPE_NANE );			\
									\
    };									\
									\
    static inline const RelationSymbol<base_type>& GetRelation() noexcept \
    {									\
									\
      static const RelationSymbol<base_type> CONNECT( RELATION_FOR , TYPE_NANE ){ REL }; \
      return CONNECT( RELATION_FOR , TYPE_NANE );			\
									\
    };									\
									\
  };									\
									\
  DEFINITION_OF_DUMMY_CLASS( CLASS_NAME )				\
  									\
  

#define SPEC( TYPE_NAME , VARIABLE , REL ) SPEC_BODY( TYPE_NAME , TYPE_NAME , VARIABLE , REL ) 
