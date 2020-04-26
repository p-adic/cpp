// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/SubType/a.Macro

#pragma once

#define SPEC( TYPE_NAME , VARIABLE , REL )				\
									\
  class TYPE_NAME :							\
    public TypeOfComputableFunction ,					\
    public EmptySet							\
  {									\
									\
  public:								\
    using type = decay_t<decltype( VARIABLE )>::type;			\
									\
  public:								\
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
	  GetRelation().Get()						\
									\
	  };								\
									\
      return t;								\
									\
    };									\
									\
    static inline const VariableSymbol<type>& GetVariable() noexcept	\
    {									\
									\
      static const VariableSymbol<type> CONNECT( VARIABLE_FOR_ , TYPE_NANE ){ VARIABLE }; \
      return CONNECT( VARIABLE_FOR_ , TYPE_NANE );			\
									\
    };									\
									\
    static inline const RelationSymbol<type>& GetRelation() noexcept	\
    {									\
									\
      static const RelationSymbol<type> CONNECT( RELATION_FOR , TYPE_NANE ){ REL }; \
      return CONNECT( RELATION_FOR , TYPE_NANE );			\
									\
    };									\
									\
    static inline const TypeOfComputableFunction& GetType() noexcept	\
    {									\
									\
      static const TypeOfComputableFunction CONNECT( TYPE_FOR_ , TYPE_NAME ) \
      {									\
									\
	TO_STRING( TYPE_NAME ) ,					\
	  LbraceString() +						\
	  VspaceString() +						\
	  GetVariable().GetNodeString( 2 ) +				\
	  InString() +							\
	  SpaceString() +						\
	  VertString() +						\
	  SpaceString() +						\
	  GetRelation()( GetVariable() ).GetNodeString( 2 ) +		\
	  VspaceString() +						\
	  RbraceString()						\
									\
	  };								\
									\
      return CONNECT( TYPE_FOR_ , TYPE_NAME );				\
									\
    };									\
									\
  };									\
									\
  static const TypeOfComputableFunction& CONNECT( __DEFINITION_OF__ , TYPE_NAME ) = TYPE_NAME ::GetType(); \
  static constexpr const int CONNECT( __SYMBOL_OF_ , TYPE_NAME ) = 0;		\
									\
  class CONNECT( DUMMY_CLASS_TO_USE_ , CONNECT( __SYMBOL_OF_ , TYPE_NAME ) ) : \
    public EmptySet							\
  {									\
									\
  private:								\
    const TypeOfComputableFunction& m_dummy_type = CONNECT( __DEFINITION_OF__ , TYPE_NAME ); \
    const int& m_dummy_int = CONNECT( __SYMBOL_OF_ , TYPE_NAME );	\
									\
  };									\
									\


