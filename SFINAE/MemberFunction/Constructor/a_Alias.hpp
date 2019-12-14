// Constructor/a_Alias.hpp

template <typename T, typename... Args>
class callable_Constructor :
  public EmptySet
{
  
private:
  template <typename U , typename... A>
  static auto Check( A&&... a ) -> decltype( U( a... ) , true_type() );

  template <typename U , typename... A>
  static false_type Check( ... );

public:
  static const bool value = decltype( Check<T,Args...>( declval<Args>()... ) )::value;
  
};

template <typename T , typename... Args>
class imply_TypeOf_Constructor :
  public EmptySet
{
  
public:
  using type = T;
  
};

template <typename T , typename... Args>
using Valid_Construct = enable_if< VALUE_CONSTRUCTOR_VALID , typename imply_TypeOf_Constructor<T,Args...> ::type >;

template <typename T , typename... Args>
using Invalid_Construct = enable_if< VALUE_CONSTRUCTOR_INVALID , typename imply_TypeOf_Constructor<T,Args...> ::type >;
