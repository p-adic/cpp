// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateStack/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/904183

class CoordinateStack
{

private:
  vector<int> m_length;
  int m_size;
  
public:
  inline CoordinateStack( const int& size = 0 );

  inline int& length( const int& n );
  inline const int& size() const noexcept;

  inline void push_back( const int& length );
  inline void pop_back();
  inline void resize( const int& size );

  inline int GetOrder( const int& n , const int& i ) const;
  inline pair<int,int> GetOrder( const int& n , const int& i , const int& j ) const;

};
