// c:/Users/user/Documents/Programming/Utility/VLArray/Entry/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline EntryOfVLArray<T>::EntryOfVLArray() : m_t() , m_prev( this ) , m_next( this ) {}
template <typename T> template <typename Arg> inline EntryOfVLArray<T>::EntryOfVLArray( const Arg& t ) : m_t( t ) , m_prev( this ) , m_next( this ) {}
template <typename T> template <typename Arg> inline EntryOfVLArray<T>::EntryOfVLArray( const Arg& t , EntryOfVLArray<T>* const& prev , EntryOfVLArray<T>* const& next ) : m_t( t ) , m_prev( prev ) , m_next( next ) {}

