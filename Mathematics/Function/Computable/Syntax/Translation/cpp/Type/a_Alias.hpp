// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Syntax/Translation/cpp/Type/a_Alias.hpp

#pragma once

// Argument
template <typename T> class CppClassForArgumentString;

// int, bool
// template <>
// class CppClassForArgumentString<T> :
//   public EmptySet
// {

// public:
//   static inline string GetString( const T& t ) { return to_string( t ); };

// };

DEFINITION_OF_PRIMITIVE_CPP_CLASS_FOR_ARGUMENT_STRING( int );
DEFINITION_OF_PRIMITIVE_CPP_CLASS_FOR_ARGUMENT_STRING( bool );

// string
template <>
class CppClassForArgumentString<string> :
  public EmptySet
{

public:
  static inline string GetString( const string& t ) { return "\"" + t + "\""; };

};

template <uint N>
class CppClassForArgumentString<char[N]> :
  public CppClassForArgumentString<string>
{};

// variadic variable
template <typename Ret>
class CppClassForArgumentString<VariadicVariableSymbol<Ret> > :
  public EmptySet
{

public:
  static inline string GetString( const VariadicVariableSymbol<Ret>& t ) { return "__" + GetTypeString<Ret>() + "_args__..."; };

};

// variable, function, relation
template <>
class CppClassForArgumentString<CppClassForString> :
  public EmptySet
{

public:
  static inline string GetString( const CppClassForString& t ) { return t.GetTermString(); };

};


// Type
template <typename Arg, typename... Args> inline string TypeString();

// primitive
template <typename T>
class CppClassForTypeString :
  public EmptySet
{

public:
  static inline string GetString() { return to_string( typeid( T ) ); };

};

// array
template <typename Ret>
class CppClassForTypeString<ArrayTypeOfComputableFunction<Ret> > :
  public EmptySet
{

public:
  static inline string GetString() { return "VLArray< " + TypeString<Ret>() + " >"; };

};

// nested array
template <typename Ret>
class CppClassForTypeString<NestedArrayTypeOfComputableFunction<Ret> > :
  public EmptySet
{

public:
  static inline string GetString() { return "VLNestedArray< " + TypeString<Ret>() + " >"; };

};

// direct product
template <typename... Args>
class CppClassForTypeString<DirectProductTypeOfComputableFunction<Args...> > :
  public EmptySet
{

public:
  static inline string GetString() { return "DirectProduct< " + TypeString<Args...>() + " >"; };

};


// TypeAndArgument
// constant
template <typename T>
class CppClassForTypeAndArgumentString :
  public EmptySet
{

public:
  static inline string GetString( const T& t ) { return "const " + TypeString<T>() + "& " + to_string( t ); };

};

// variadic variable
template <typename Ret>
class CppClassForTypeAndArgumentString<VariadicVariableSymbol<Ret> > :
  public EmptySet
{

public:
  static inline string GetString( const VariadicVariableSymbol<Ret>& t ) { return "const " + TypeString<Ret>() + "&... __" + GetTypeString<Ret>() + "_args__"; };

};

// variable, function, relation
template <>
class CppClassForTypeAndArgumentString<CppClassForString> :
  public EmptySet
{

public:
  static inline string GetString( const CppClassForString& t ) { return "const " + t.GetTypeString() + "& " + t.GetTermString(); };

};

