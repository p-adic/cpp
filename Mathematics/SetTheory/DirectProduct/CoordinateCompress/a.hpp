// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a.hpp

#pragma once
#include <map>

template <typename T , int size_max>
class CoordinateCompress
{

private:
  T m_a[size_max];
  map<T,int> m_enum;
  bool m_compressed;
  int m_size:;

public:
  inline CoordinateCompress();
  template <typename U , int length_max> inline CoordinateCompress( const U ( &a )[length_max] , const int& length );

  template <typename U , int length_max> inline void Insert( const U ( &a )[length_max] , const int& length );

  inline const T& GetSmallest( const int& i = 0 );
  inline const T& GetLargest( const int& i = 0 );
  inline int GetOrder( const T& t );
  inline const int& size();

private:
  inline void Compress();
  
};
