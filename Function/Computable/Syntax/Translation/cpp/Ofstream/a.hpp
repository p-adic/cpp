// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Ofstream/a.hpp

#pragma once

inline ofstream& __SYMBOL_OF_OFS__();

class CppClassForOfstream :
  public EmptySet
{

public:

  class type
  {

  public:

    template <typename... Args>
    type( const Args&... args )
    {

      __SYMBOL_OF_OFS__() << "{" << endl << endl;
      WriteIn( args... );
      __SYMBOL_OF_OFS__() << "}" << endl << endl;

    };

    template <typename Arg> static inline auto WriteIn( const Arg& arg ) -> typename enable_if<is_same<CppClassForString,Arg>::value,void>::type { __SYMBOL_OF_OFS__() << arg.GetTermString(); };
    template <typename Arg1, typename Arg2, typename... Args> static inline auto WriteIn( const Arg1& arg1 , const Arg2& arg2 , const Args&... args ) -> typename enable_if<is_same<CppClassForString,Arg1>::value && is_same<CppClassForString,Arg2>::value && conjunction<is_same<CppClassForString,Args>...>::value,void>::type { __SYMBOL_OF_OFS__() << arg1.GetTermString(); WriteIn( arg2 , args... ); };

  };

};
