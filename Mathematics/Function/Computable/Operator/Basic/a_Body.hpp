// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Basic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Expression/Primitive/a.hpp"
#include "int/a_Body.hpp"
#include "string/a_Body.hpp"
#include "bool/a_Body.hpp"

namespace QpBasic
{

  #include "QpBasic/a_Body.hpp"

}


template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , + , Plus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , + , Plus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( string , + , Plus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( bool , + , Plus );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , - , Minus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , - , Minus );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( bool , - , Minus );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , * , Times );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , * , Times );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( bool , * , Times );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , / , Slash );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , / , Slash );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , % , Mod );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , % , Mod );

template <typename Ret> DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( Ret , ^ , Power );
DEFINITION_OF_TWO_ARY_BASIC_FUNCTION( int , ^ , Power );


inline const ExpressionOfComputableFunction<int>& InftySymbol(){ static const ExpressionOfComputableFunction<int> n = ExpressionOfComputableFunction<int>( infty() ); return n; }


template <typename Ret> inline FunctionSymbol<Ret,Ret> operator^( const FunctionSymbol<Ret,Ret>& f , const PrettyExpression<nat>& n )
{

  return FunctionSymbol<Ret,Ret>
    (

     f.GetNodeString( 2 ) + SupString() + LbraceString() + n.GetNodeString( 2 ) + RbraceString() ,
     GetTypeName<Ret>() ,
     VariableSymbol<Ret>( f.GetNodeString( 4 , 2 , 2 ) )

     );

}

inline RelationSymbol<bool> operator^( const RelationSymbol<bool>& r , const PrettyExpression<nat>& n )
{

  return RelationSymbol<bool>
    (

     r.GetNodeString( 2 ) + SupString() + LbraceString() + n.GetNodeString( 2 ) + RbraceString() ,
     GetTypeName<bool>() ,
     VariableSymbol<bool>( r.GetNodeString( 4 , 2 , 2 ) )

     );

}


template <typename Ret, typename Arg1, typename Arg2> inline FunctionSymbol<Ret,Arg2> CurryingSymbol( const FunctionSymbol<Ret,Arg1,Arg2>& f , const ExpressionOfComputableFunction<Arg1>& x , const string& style )
{

  if( style == EmptyString() ) {
    
    return FunctionSymbol<Ret,Arg2>
      (

       f.GetNodeString( 2 ) + x.GetNodeString( 2 ) ,
       GetTypeName<Ret>() ,
       VariableSymbol<Arg2>( f.GetNodeString( 4 , 3 , 2 ) )

       );

  }

  if( style == SubString() ) {
    
    return FunctionSymbol<Ret,Arg2>
      (

       f.GetNodeString( 2 ) + SubString() + LbraceString() + x.GetNodeString( 2 ) + RbraceString() ,
       GetTypeName<Ret>() ,
       VariableSymbol<Arg2>( f.GetNodeString( 4 , 3 , 2 ) )

       );

  }

  return FunctionSymbol<Ret,Arg2>
    (

     style + LparenString() + f.GetNodeString( 2 ) + CommaString() + x.GetNodeString( 2 ) + RparenString() ,
     GetTypeName<Ret>() ,
     VariableSymbol<Arg2>( f.GetNodeString( 4 , 3 , 2 ) )

     );
 
}

template <typename Arg1, typename Arg2> inline RelationSymbol<Arg2> CurryingSymbol( const RelationSymbol<Arg1,Arg2>& r , const ExpressionOfComputableFunction<Arg1>& x , const string& style )
{

  if( style == EmptyString() ) {
    
    return RelationSymbol<Arg2>
      (

       r.GetNodeString( 2 ) + x.GetNodeString( 2 ) ,
       GetTypeName<bool>() ,
       VariableSymbol<Arg2>( r.GetNodeString( 4 , 3 , 2 ) )

       );

  }

  if( style == SubString() ) {
    
    return RelationSymbol<Arg2>
      (

       r.GetNodeString( 2 ) + SubString() + LbraceString() + x.GetNodeString( 2 ) + RbraceString() ,
       GetTypeName<bool>() ,
       VariableSymbol<Arg2>( r.GetNodeString( 4 , 3 , 2 ) )

       );

  }

  return RelationSymbol<Arg2>
    (

     style + LparenString() + r.GetNodeString( 2 ) + CommaString() + x.GetNodeString( 2 ) + RparenString() ,
     GetTypeName<bool>() ,
     VariableSymbol<Arg2>( r.GetNodeString( 4 , 3 , 2 ) )

     );
 
}


template <typename... Args> inline DEFINITION_OF_BOUNDED_EXISTENCE( Exist , Exist , nat );
template <typename... Args> inline DEFINITION_OF_BOUNDED_EXISTENCE( UniqueExist , UExist , nat );
template <typename... Args> inline DEFINITION_OF_BOUNDED_EXISTENCE( Exist , Exist , string );
template <typename... Args> inline DEFINITION_OF_BOUNDED_EXISTENCE( UniqueExist , UExist , string );

inline PrettyFunction<nat,nat,bool> MinimumSymbol( const PrettyVariable<nat>& n , const ExpressionOfComputableFunction<bool>& b )
{

  return PrettyFunction<nat,nat,bool>
    (

     MinString() ,
     SeparatorOfComputableFunction
     (

      0 ,
      MinString() + SpaceString() +
      EscapeString() + LbraceString() + SpaceString() + EscapeString() + SpaceString() ,
      SpaceString() + InString() + SpaceString() +
      GetTypeString<nat>() + SpaceString() +
      VertString() + SpaceString() ,
      SpaceString() + EscapeString() + SpaceString() + EscapeString() + RbraceString()

      ) ,
     GetTypeName<nat>() ,
     n ,
     VariableSymbol<bool>( b.GetNodeString( 2 ) )

     );

}

inline PrettyFunction<nat,nat,nat,bool> BoundedMaximumSymbol( const PrettyVariable<nat>& n , const PrettyExpression<nat>& bound , const ExpressionOfComputableFunction<bool>& b )
{

  return PrettyFunction<nat,nat,nat,bool>
    (

     MaxString() ,
     SeparatorOfComputableFunction
     (

      0 ,
      MaxString() + SpaceString() +
      EscapeString() + LbraceString() + SpaceString() + EscapeString() + SpaceString() ,
      SpaceString() + LeqString() + SpaceString() ,
      SpaceString() + VertString() + SpaceString() ,
      SpaceString() + EscapeString() + SpaceString() + EscapeString() + RbraceString()

      ) ,
     GetTypeName<nat>() ,
     n ,
     PrettyVariable<nat>( bound.GetNodeString( 2 ) , GetTypeName<nat>() ) ,
     VariableSymbol<bool>( b.GetNodeString( 2 ) )

     );

}
