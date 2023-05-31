// c:/Users/user/Documents/Programming/Utility/Search/BreadthFirst/a.hpp

#pragma once

template <int V_max,list<int> E(const int&)>
class BreadthFirstSearch
{

private:
  int m_V;
  int m_init;
  list<int> m_next;
  bool m_found[V_max];

public:
  inline BreadthFirstSearch( const int& V );
  inline BreadthFirstSearch( const int& V , const int& init );

  // m_found‚à‰Šú‰»
  inline void Reset( const int& init );
  // m_found‚Í”ñ‰Šú‰»
  inline void Shift( const int& init );
  

  bool& Found( const int& i );  
  int Next();

};
