// c:/Users/user/Documents/Programming/Utility/Sort/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../VLArray/a_Body.hpp"

template <typename T>
void Sort( VLArray<T>& a , const string& method , const VLArray<int>& option )
{

  if( method == "merge" ){

    MergeSort( a , option );

  } else {

    NormalSort( a , option );

  }

  return;
  
}

template <typename T>
void NormalSort( VLArray<T>& a , const VLArray<int>& option )
{

  if( ! option.empty() ){

    const int& cut_length_signed = option[0];

    if( cut_length_signed != 0 ){

      if( cut_length_signed > 0 ){

	NormalSortCut<T>( a , cut_length_signed , true );

      } else {

	NormalSortCut<T>( a , - cut_length_signed , false );

      }

      return;

    }

  }

  NormalSortNoCut<T>( a );
  return;

}

template <typename T>
void NormalSortNoCut( VLArray<T>& a )
{

  auto itr0 = a.begin() , end0 = a.end();

  while( itr0 != end0 ){

    const T& t = *itr0;
    auto itr1 = itr0;
    itr1--;
    bool stable = true;
    
    while( itr1 != end0 ){

      if( *itr1 > t ){

	if( stable ){

	  stable = false;

	}
	
	itr1--;

      } else {

	if( stable ){

	  itr0++;

	} else {

	  a.insert_back( itr1 , t );
	  a.erase_back( itr0 );
	  stable = true;

	}

	itr1 = end0;

      }

      if( ! stable ){

	a.insert_back( end0 , t );
	a.erase_back( itr0 );

      }

    }

  }

  return;

}

template <typename T>
void NormalSortCut( VLArray<T>& a , const int& cut_length , const bool& cut_large )
{

  using type = typename VLArray<T>::iterator;
  using incr_type = void( type::* )( int );
  using ins_type = void( VLArray<T>::* )( const type& , const T& );
  using er_type = type( VLArray<T>::* )( type& );
  
  int length = 0;
  type itr0 , end0 = a.end();
  const incr_type incr;
  const incr_type decr;
  const ins_type ins;
  const er_type er;

  if( cut_large ){

    itr0 = a.begin();
    incr = &( type::operator++ );
    decr = &( type::operator-- );
    ins = &( VLArray<T>::insert_back );
    er = &( VLArray<T>::erase_back );

  } else {

    itr0 = end0;
    itr0--;
    incr = &( type::operator-- );
    decr = &( type::operator++ );
    ins = &( VLArray<T>::insert_front );
    er = &( VLArray<T>::erase_front );


  }

  while( itr0 != end0 ){

    const T& t = *itr0;
    auto itr1 = itr0;
    ( itr1.*decr )();
    auto itr_ins = end0;
    bool changing = false;
    
    while( itr1 != end0 ){
      
      if( *itr1 > t ){

	if( ! changing ){

	  changing = true;

	}
	
	( itr1.*decr )();

      } else {

	if( changing ){

	  itr_ins = itr1;

	}

	itr1 = end0;

      }

    }

    if( changing ){

      ( a.*ins )( itr_ins , t );
      ( a.*er )( itr0 );

      if( length < cut_length ){

	length++;

      } else {

	auto itr2 = itr0;
	( itr2.*decr )();
	( a.*er )( itr2 );

      }

    } else {

      ( itr0.*incr )();

    }

  }

  return;

}

template <typename T>
void MergeSort( VLArray<T>& a , const VLArray<int>& option )
{

  const uint& size = option.size();
  
  if( size > 0 ){

    const int& cut_length_signed = option[0];

    if( cut_length_signed != 0 ){

      int cut_length;
      bool cut_large;

      if( cut_length_signed > 0 ){

	cut_length = cut_length_signed;
	cut_large = true;

      } else {

	cut_length = - cut_length_signed;
	cut_large = false;

      }

      if( size > 1 ){

	const int& normal_method_length = option[1];

	if( normal_method_length > 0 ){

	  MergeSortCutNormal<T>( a , cut_length , cut_large , normal_method_length );
	  return;
	}

      }
      
      MergeSortCut<T>( a , cut_length , cut_large );
      return;

    }

  }

  MergeSortNoCut<T>( a );
  return;

}

template <typename T>
void MergeSortNoCut( VLArray<T>& a )
{

  const uint& size_a = a.size();
  const uint half_size_a = size_a / 2;

  auto itr = a.begin();
  VLArray<T> b{};
  
  for( uint i = 0 ; i < half_size_a ; i++ ){

    b.push_back( *itr );
    a.erase( itr );

  }

  MergeSortNoCut<T>( a );
  MergeSortNoCut<T>( b );

  itr = a.begin();
  auto end = a.end();
  const uint& size_b = b.size();

  while( size_b != 0 ){

    const T& t = b.front();
    bool not_inserted = true;
    
    while( itr != end && not_inserted ){

      if( t < *itr ){

	a.insert_front( itr , t );
	not_inserted = false;

      } else {

	itr++;

      }

    }

    if( not_inserted ){

      a.push_back( t );

    }

    b.pop_front();

  }

  return;

}

template <typename T>
void MergeSortCut( VLArray<T>& a , const int& cut_length , const bool& cut_large )
{

  const uint& size_a = a.size();
  const uint half_size_a = size_a / 2;

  using type = typename VLArray<T>::iterator;
  type itr = a.begin();
  VLArray<T> b{};
  
  for( uint i = 0 ; i < half_size_a ; i++ ){

    b.push_back( *itr );
    a.erase( itr );

  }

  MergeSortCut<T>( a , cut_length , cut_large );
  MergeSortCut<T>( b , cut_length , cut_large );

  uint i = 0;
  itr = a.begin();
  type end = a.end();
  const uint& size_b = b.size();

  using incr_type = void( type::* )( int );
  using front_type = const T&( VLArray<T>::* )();
  using ins_type = void( VLArray<T>::* )( const type& , const T& );
  using push_type = void( VLArray<T>::* )( const T& );
  using pop_type = void( VLArray<T>::* )();
  
  int length = 0;
  type itr0 , end0 = a.end();
  const incr_type incr;
  const front_type fr;
  const ins_type ins;
  const push_type push;
  const pop_type pop_fr;
  const pop_type pop_ba;

  if( cut_large ){

    fr = &( VLArray<T>::front );
    incr = &( type::operator++ );
    ins = &( VLArray<T>::insert_front );
    push = &( VLArray<T>::push_back );
    pop_fr = &( VLArray<T>::pop_front );
    pop_ba = &( VLArray<T>::pop_back );

  } else {

    fr = &( VLArray<T>::back );
    incr = &( type::operator-- );
    ins = &( VLArray<T>::insert_back );
    push = &( VLArray<T>::push_front );
    pop_fr = &( VLArray<T>::pop_back );
    pop_ba = &( VLArray<T>::pop_front );

  }

  while( size_b != 0 && i <= cut_length ){

    const T& t = ( b.*fr )();
    bool not_inserted = true;
    
    while( itr != end && not_inserted ){

      if( t < *itr ){

	( a.*ins )( itr , t );
	not_inserted = false;

      } else {

	( itr.*incr )();

      }

      i++;
      
    }

    if( not_inserted ){

      ( a.*push )( t );

    }

    ( b.*pop_fr )();

  }

  while( size_a > cut_length ){

    ( a.*pop_ba )();

  }

  return;

}

template <typename T>
void MergeSortCutNormal( VLArray<T>& a , const int& cut_length , const bool& cut_large , const int& normal_method_length )
{

  const uint& size_a = a.size();

  if( size_a <= normal_method_length ){

    if( size_a <= cut_length ){

      NormalSortNoCut<T>( a );

    } else {

      NormalSortCut<T>( a , cut_length , cut_large );

    }

    return;

  }
  
  const uint half_size_a = size_a / 2;

  using type = typename VLArray<T>::iterator;
  type itr = a.begin();
  VLArray<T> b{};
  
  for( uint i = 0 ; i < half_size_a ; i++ ){

    b.push_back( *itr );
    a.erase( itr );

  }

  MergeSortCutNormal<T>( a , cut_length , cut_large , normal_method_length );
  MergeSortCutNormal<T>( b , cut_length , cut_large , normal_method_length  );

  uint i = 0;
  itr = a.begin();
  type end = a.end();
  const uint& size_b = b.size();

  using incr_type = void( type::* )( int );
  using front_type = const T&( VLArray<T>::* )();
  using ins_type = void( VLArray<T>::* )( const type& , const T& );
  using push_type = void( VLArray<T>::* )( const T& );
  using pop_type = void( VLArray<T>::* )();
  
  int length = 0;
  type itr0 , end0 = a.end();
  const incr_type incr;
  const front_type fr;
  const ins_type ins;
  const push_type push;
  const pop_type pop_fr;
  const pop_type pop_ba;

  if( cut_large ){

    fr = &( VLArray<T>::front );
    incr = &( type::operator++ );
    ins = &( VLArray<T>::insert_front );
    push = &( VLArray<T>::push_back );
    pop_fr = &( VLArray<T>::pop_front );
    pop_ba = &( VLArray<T>::pop_back );

  } else {

    fr = &( VLArray<T>::back );
    incr = &( type::operator-- );
    ins = &( VLArray<T>::insert_back );
    push = &( VLArray<T>::push_front );
    pop_fr = &( VLArray<T>::pop_back );
    pop_ba = &( VLArray<T>::pop_front );

  }

  while( size_b != 0 && i <= cut_length ){

    const T& t = ( b.*fr )();
    bool not_inserted = true;
    
    while( itr != end && not_inserted ){

      if( t < *itr ){

	( a.*ins )( itr , t );
	not_inserted = false;

      } else {

	( itr.*incr )();

      }

      i++;
      
    }

    if( not_inserted ){

      ( a.*push )( t );

    }

    ( b.*pop_fr )();

  }

  while( size_a > cut_length ){

    ( a.*pop_ba )();

  }

  return;

}

