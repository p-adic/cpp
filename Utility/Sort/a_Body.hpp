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

    const uint& cut_length_signed = option[0];

    if( cut_length_signed != 0 ){

      if( cut_length_signed > 0 ){

	NormalSortCut<T>( a , (uint)cut_length_signed , true );

      } else {

	NormalSortCut<T>( a , (uint)( - cut_length_signed ) , false );

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
    auto itr_ins = end0;
    bool changing = false;
    
    while( itr1 != end0 ){

      if( t < *itr1 ){

	if( ! changing ){

	  changing = true;

	}
	
	itr1--;

      } else {

	if( changing ){

	  itr_ins = itr1;

	}

	itr1 = end0;

      }

    }

    if( changing ){

      a.insert_back( itr_ins , t );
      a.erase_back( itr0 );

    } else {
	
      itr0++;

    }

  }

  return;

}

template <typename T>
void NormalSortCut( VLArray<T>& a , const uint& cut_length , const bool& cut_large )
{

  using type = typename VLArray<T>::iterator;
  using incr_type = void( type::* )( int );
  using ins_type = void( VLArray<T>::* )( const type& , const T& );
  using er_type = type( VLArray<T>::* )( type& );
  
  uint length = 0;
  type itr0 = a.end() , end0 = itr0;
  incr_type incr;
  incr_type decr;
  ins_type ins;
  er_type er;

  if( cut_large ){

    itr0 = a.begin();
    incr = &type::operator++;
    decr = &type::operator--;
    ins = &VLArray<T>::insert_back;
    er = &VLArray<T>::erase_back;

  } else {

    itr0--;
    incr = &type::operator--;
    decr = &type::operator++;
    ins = &VLArray<T>::insert_front;
    er = &VLArray<T>::erase_front;

  }

  while( itr0 != end0 ){

    const T& t = *itr0;
    auto itr1 = itr0;
    ( itr1.*decr )( 0 );
    auto itr_ins = end0;
    bool changing = false;
    
    while( itr1 != end0 ){
      
      if( t < *itr1 ){

	if( ! changing ){

	  changing = true;

	}
	
	( itr1.*decr )( 0 );

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
	( itr2.*decr )( 0 );
	( a.*er )( itr2 );

      }

    } else {

      ( itr0.*incr )( 0 );

    }

  }

  return;

}

template <typename T>
void MergeSort( VLArray<T>& a , const VLArray<int>& option )
{

  const uint& size = option.size();
  
  if( size > 0 ){

    const uint& cut_length_signed = option[0];

    if( cut_length_signed != 0 ){

      uint cut_length;
      bool cut_large;

      if( cut_length_signed > 0 ){

	cut_length = (uint)cut_length_signed;
	cut_large = true;

      } else {

	cut_length = (uint)( - cut_length_signed );
	cut_large = false;

      }

      if( size > 1 ){

	const int& normal_method_length = option[1];

	if( normal_method_length > 0 ){

	  MergeSortCut<T>( a , cut_length , cut_large , (uint)( normal_method_length ) );
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

  if( size_a <= 2 ){

    NormalSortNoCut( a );
    return;

  }
  
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
void MergeSortCut( VLArray<T>& a , const uint& cut_length , const bool& cut_large , const uint& normal_method_length )
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

  MergeSortCut<T>( a , cut_length , cut_large , normal_method_length );
  MergeSortCut<T>( b , cut_length , cut_large , normal_method_length  );

  uint i = 0;
  type end = a.end();
  const uint& size_b = b.size();

  using incr_type = void( type::* )( int );
  using front_type = const T&( VLArray<T>::* )() const;
  using ins_type = void( VLArray<T>::* )( const type& , const T& );
  using push_type = void( VLArray<T>::* )( const T& );
  using pop_type = void( VLArray<T>::* )();
  
  incr_type incr;
  front_type fr;
  ins_type ins;
  push_type push;
  pop_type pop_fr;
  pop_type pop_ba;

  if( cut_large ){

    itr = a.begin();
    fr = &VLArray<T>::front;
    incr = &type::operator++;
    ins = &VLArray<T>::insert_front;
    push = &VLArray<T>::push_back;
    pop_fr = &VLArray<T>::pop_front;
    pop_ba = &VLArray<T>::pop_back;

  } else {

    itr = end;
    itr--;
    fr = &VLArray<T>::back;
    incr = &type::operator--;
    ins = &VLArray<T>::insert_back;
    push = &VLArray<T>::push_front;
    pop_fr = &VLArray<T>::pop_back;
    pop_ba = &VLArray<T>::pop_front;

  }

  while( size_b != 0 && i <= cut_length ){

    const T& t = ( b.*fr )();
    bool not_inserted = true;
    
    while( itr != end && not_inserted ){

      if( t < *itr ){

	( a.*ins )( itr , t );
	not_inserted = false;

      } else {

	( itr.*incr )( 0 );

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

