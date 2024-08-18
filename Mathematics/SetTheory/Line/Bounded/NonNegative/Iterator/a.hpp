// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/NonNegative/Iterator/a.hpp

#pragma once

template <typename INT , template <typename...> typename DATA_STR> class AbstractNonNegativeLineSubset;

template <typename INT , template <typename...> typename DATA_STR>
class IteratorOfNonNegativeLineSubset
{

private:
  const AbstractNonNegativeLineSubset<INT,DATA_STR>* m_p;
  INT m_i;

public:
  inline IteratorOfNonNegativeLineSubset( const AbstractNonNegativeLineSubset<INT,DATA_STR>& S , INT i );

  inline bool operator==( const IteratorOfNonNegativeLineSubset<INT,DATA_STR>& itr ) const noexcept;
  inline bool operator!=( const IteratorOfNonNegativeLineSubset<INT,DATA_STR>& itr ) const noexcept;

  // éQè∆Ç≈Ç»Ç¢Ç±Ç∆Ç…íçà”ÅB
  inline INT operator*() const;
  
  inline IteratorOfNonNegativeLineSubset<INT,DATA_STR>& operator++();
  inline IteratorOfNonNegativeLineSubset<INT,DATA_STR> operator++( int );
  inline IteratorOfNonNegativeLineSubset<INT,DATA_STR>& operator--();
  inline IteratorOfNonNegativeLineSubset<INT,DATA_STR> operator--( int );

  inline void Next();
  inline void Prev();

  inline pair<INT,INT> ConnectedComponent() const;
  
  inline IteratorOfNonNegativeLineSubset<INT,DATA_STR>& erase_from( AbstractNonNegativeLineSubset<INT,DATA_STR>& S );

};
