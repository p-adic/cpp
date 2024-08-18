// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Iterator/a.hpp

#pragma once

template <typename INT>
class IteratorOfLineSubset
{

private:
  const map<INT,INT>* m_p;
  typename map<INT,INT>::iterator m_itr;
  INT m_n;

public:
  inline IteratorOfLineSubset( const map<INT,INT>& l , typename map<INT,INT>::iterator itr , INT n );

  inline bool operator==( const IteratorOfLineSubset<INT>& itr ) const noexcept;
  inline bool operator!=( const IteratorOfLineSubset<INT>& itr ) const noexcept;

  // éQè∆Ç≈Ç»Ç¢Ç±Ç∆Ç…íçà”ÅB
  inline INT operator*() const;
  
  inline IteratorOfLineSubset<INT>& operator++();
  inline IteratorOfLineSubset<INT> operator++( int );
  inline IteratorOfLineSubset<INT>& operator--();
  inline IteratorOfLineSubset<INT> operator--( int );

  inline void Next();
  inline void Prev();

  inline pair<INT,INT> ConnectedComponent() const;
  
  inline IteratorOfLineSubset<INT>& erase_from( map<INT,INT>& l );

};
