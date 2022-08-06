// c:/Users/user/Documents/Programming/Utility/FileStream/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Mathematics/SetTheory/Singleton/a_Body.hpp"
#include "../List/LabeledList/a_Body.hpp"
#include "../SmartPointer/a_Body.hpp"

inline ofstream& FileHolder::operator()( const string& filename ) const { return *( OfstreamTable()( filename ) ); }
inline bool FileHolder::Contain( const string& filename ) const { return OfstreamTable().Contain( filename ); }

inline LabeledList<SmartPointer<ofstream>,string>& FileHolder::OfstreamTable() { static auto list = LabeledList<SmartPointer<ofstream>,string>( WrappedType<DirectProduct<string> >( "" ) , WrappedType<SmartPointer<ofstream> >( "dummy file name for OfstreamTable" , ios::in ) ); return list; }

inline void DeleteContents( const string& filename ) { ToOfstream( filename , ios::trunc ); }

template <typename... T> inline void WriteIn( const string& filename , const T&... t ) { ToOfstream( filename ) << to_string_Normalised( t... ) << endl;  }
