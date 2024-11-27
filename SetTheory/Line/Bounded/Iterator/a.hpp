// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Iterator/a.hpp

#pragma once

template <typename BLS , typename INT>
class IteratorOfBoundedLineSubset
{

private:
  BLS* m_p;
  INT m_i;

public:
  inline IteratorOfBoundedLineSubset( BLS& S , INT i );

  inline bool operator==( const IteratorOfBoundedLineSubset<BLS,INT>& itr ) const noexcept;
  inline bool operator!=( const IteratorOfBoundedLineSubset<BLS,INT>& itr ) const noexcept;

  // éQè∆Ç≈Ç»Ç¢Ç±Ç∆Ç…íçà”ÅB
  inline INT operator*() const;
  
  inline IteratorOfBoundedLineSubset<BLS,INT>& operator++();
  inline IteratorOfBoundedLineSubset<BLS,INT> operator++( int );
  inline IteratorOfBoundedLineSubset<BLS,INT>& operator--();
  inline IteratorOfBoundedLineSubset<BLS,INT> operator--( int );

  inline void Next();
  inline void Prev();

  inline pair<INT,INT> ConnectedComponent() const;
  
  inline IteratorOfBoundedLineSubset<BLS,INT>& erase_from( BLS& S );

};
