// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/SubType/a.Macro

#pragma once

#define SPEC( TYPE_NAME , VARIABLE , REL )				\
									\
									\
  class TYPE_NAME :							\
    public TypeOfComputableFunction					\
  {									\
									\
  public:								\
    using base_type = decay_t<decltype( VARIABLE )>::type;			\
									\
  public:								\
    inline TYPE_NAME () noexcept :					\
      TypeOfComputableFunction						\
      (									\
									\
       TO_STRING( TYPE_NAME ) ,						\
									\
       EscapeString() + LbraceString() + SpaceString() +		\
       EscapeString() + SpaceString() +					\
       GetVariable().GetNodeString( 2 ) + SpaceString() +		\
       InString() + SpaceString() +					\
       ( GetVariable() ).GetNodeString( 3 , 2 ) + SpaceString() +	\
       VertString() + SpaceString() +					\
       GetRelation()( GetVariable() ).GetNodeString( 2 ) + SpaceString() + \
       EscapeString() + SpaceString() +					\
       EscapeString() + RbraceString()					\
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
    static inline const VariableSymbol<base_type>& GetVariable() noexcept	\
    {									\
									\
      static const VariableSymbol<base_type> CONNECT( VARIABLE_FOR_ , TYPE_NANE ){ VARIABLE }; \
      return CONNECT( VARIABLE_FOR_ , TYPE_NANE );			\
									\
    };									\
									\
    static inline const RelationSymbol<base_type>& GetRelation() noexcept	\
    {									\
									\
      static const RelationSymbol<base_type> CONNECT( RELATION_FOR , TYPE_NANE ){ REL }; \
      return CONNECT( RELATION_FOR , TYPE_NANE );			\
									\
    };									\
									\
  };									\
									\
  static const TYPE_NAME CONNECT( CONNECT( __DEFINITION_OF__ , TYPE_NAME ) , __ ){}; \
  static const TYPE_NAME & CONNECT( CONNECT( __SYMBOL_OF_ , TYPE_NAME ) , __ ) = CONNECT( CONNECT( __DEFINITION_OF__ , TYPE_NAME ) , __ ); \
									\
  class CONNECT( DUMMY_CLASS_TO_USE_ , CONNECT( CONNECT( __SYMBOL_OF_ , TYPE_NAME ) , __ ) ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    const TypeOfComputableFunction& m_dummy = CONNECT( CONNECT( __SYMBOL_OF_ , TYPE_NAME ) , __ ); \
									\
  };									\
									\


