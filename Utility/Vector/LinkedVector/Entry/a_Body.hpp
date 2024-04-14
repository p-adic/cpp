// c:/Users/user/Documents/Programming/Utility/Vector/Linked/Entry/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline EntryOfLinkedVector<T>::EntryOfLinkedVector() : m_t() , m_prev_entry( 0 ) , m_next_entry( 0 ) {}
template <typename T> inline EntryOfLinkedVector<T>::EntryOfLinkedVector( const uint& prev_entry , const uint& next_entry ) : m_t() , m_prev_entry( prev_entry ) , m_next_entry( next_entry ) {}

template <typename T> inline EntryOfLinkedVector<T>::EntryOfLinkedVector( EntryOfLinkedVector<T>&& e ) : m_t( move( e.m_t ) ) , m_prev_entry( move( e.m_prev_entry ) ) , m_next_entry( move( e.m_next_entry ) ) {}
