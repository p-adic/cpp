// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Iterator/a.hpp

#pragma once

template <typename INT , template <typename...> typename DATA_STR> class AbstractBoundedLineSubset;

template <typename INT , template <typename...> typename DATA_STR>
class IteratorOfBoundedLineSubset
{

private:
  AbstractBoundedLineSubset<INT,DATA_STR>* m_p;
  INT m_i;

public:
  inline IteratorOfBoundedLineSubset( AbstractBoundedLineSubset<INT,DATA_STR>& S , INT i );

  inline bool operator==( const IteratorOfBoundedLineSubset<INT,DATA_STR>& itr ) const noexcept;
  inline bool operator!=( const IteratorOfBoundedLineSubset<INT,DATA_STR>& itr ) const noexcept;

  // éQè∆Ç≈Ç»Ç¢Ç±Ç∆Ç…íçà”ÅB
  inline INT operator*() const;
  
  inline IteratorOfBoundedLineSubset<INT,DATA_STR>& operator++();
  inline IteratorOfBoundedLineSubset<INT,DATA_STR> operator++( int );
  inline IteratorOfBoundedLineSubset<INT,DATA_STR>& operator--();
  inline IteratorOfBoundedLineSubset<INT,DATA_STR> operator--( int );

  inline void Next();
  inline void Prev();

  inline pair<INT,INT> ConnectedComponent() const;
  
  inline IteratorOfBoundedLineSubset<INT,DATA_STR>& erase_from( AbstractBoundedLineSubset<INT,DATA_STR>& S );

};
