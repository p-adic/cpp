// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/a_Macro.hpp

#pragma once

#define CONVERT_CPP( FILE , OPEN_MODE )					\
									\
  inline ofstream& __SYMBOL_OF_OFS_PREPARATION__()			\
  {									\
									\
    static ofstream ofs( TO_STRING( FILE ) , OPEN_MODE );		\
    ofs << "#include \"Mathematics/Function/Computable/Library/cpp/a.hpp\"" << endl << endl; \
    return ofs;								\
									\
  }									\
									\
  inline ofstream& __SYMBOL_OF_OFS__()					\
  {									\
									\
    static ofstream& ofs = __SYMBOL_OF_OFS_PREPARATION__();		\
    return ofs;								\
									\
  }									\
									\


