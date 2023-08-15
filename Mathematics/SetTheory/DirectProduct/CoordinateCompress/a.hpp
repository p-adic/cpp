// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a.hpp

#pragma once
#include <map>

template <typename T>
class CoordinateCompress
{

private:
  vector<T> m_a;
  map<T,int> m_enum;
  bool m_compressed;
  int m_size;

public:
  inline CoordinateCompress();
  template <typename U , int length_max> inline CoordinateCompress( const U ( &a )[length_max] , const int& length );
  template <typename U> inline CoordinateCompress( const vector<U>& a );

  inline void Insert( const T& t );
  template <typename U , int length_max> inline void Insert( const U ( &a )[length_max] , const int& length );
  template <typename U> inline void Insert( const vector<U>& a );

  inline const T& GetSmallest( const int& i = 0 );
  inline const T& GetLargest( const int& i = 0 );
  inline int GetOrder( const T& t );
  inline const int& size();

  inline typename map<T,int>::iterator begin();
  inline typename map<T,int>::iterator end();

private:
  inline void Compress();
  
};
