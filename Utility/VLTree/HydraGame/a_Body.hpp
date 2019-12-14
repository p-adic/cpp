// c:/Users/user/Documents/Programming/Utility/VLTree/HydraGame/a_Body.hpp

#pragma once
#include "../a_Body.hpp"

template <typename T>
void CutHydra( VLSubTree<T>& t , const uint& n )
{

  if( t.IsLeaf() ){

    ERR_CALL;

  }

  VLSubTree<T> t0 = t.RightMostSubTree();

  if( t0.IsLeaf() ){

    t.pop_back();

  } else {

    VLSubTree<T> t1 = t0.RightMostSubTree();

    if( t1.IsLeaf() ){

      t0.pop_back();

      for( uint i = 0 ; i < n ; i++ ){

	t.push_back( t0 );

      }

    } else {

      CutHydra( t0 , n );

    }

  }

  return;

}

template <typename T>
uint KillHydra( VLTree<T>& t , uint& n , const uint& incr )
{

  string s = to_string( t );
  s += "[n]";

  cout << s << endl;

  while( KillHydra_Body( t , n ) ){

    cout << "[" << n << "]" << endl; 
    n += incr;

  }

  return n;

}

template <typename T>
void KillHydra( VLTree<T>& t )
{

  string s = to_string( t );
  s += "[n]";

  cout << s << endl;

  uint n = 0;

  cout << "n = ";
  cin >> n;
  
  while( KillHydra_Body( t , n ) && n != 691){

    cout << "[" << n << "][n]" << endl; 
    cout << "n = ";
    cin >> n;

  }

  return;

}

template <typename T>
bool KillHydra_Body( VLTree<T>& t , const uint& n )
{

  if( t.IsLeaf() ){

    return false;

  }

  CutHydra( t , n );
  cout << to_string( t );

  return true;

}
