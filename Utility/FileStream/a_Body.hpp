// c:/Users/user/Documents/Programming/Utility/FileStream/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Mathematics/SetTheory/Singleton/a_Body.hpp"
#include "../List/Labeled/a_Body.hpp"
#include "../SmartPointer/a_Body.hpp"

inline ofstream& FileHolder::operator()( const string& filename ) const { return *( OfstreamTable()( filename ) ); }
inline bool FileHolder::Contain( const string& filename ) const { return OfstreamTable().Contain( filename ); }

inline LabeledList<SmartPointer<ofstream>,string>& FileHolder::OfstreamTable() { static auto list = LabeledList<SmartPointer<ofstream>,string>( WrappedType<DirectProduct<DirectProduct<string>,SmartPointer<ofstream> > >( DirectProduct<string>( " " ) , SmartPointer<ofstream>( "dummy file name for OfstreamTable" , ios::in ) ) ); return list; }

inline void DeleteContents( const string& filename ) { ToOfstream( filename , ios::trunc ); }

template <typename T>
void WriteIn( const string& filename , const T& t , const bool& insert_endl )
{

  ofstream& ofs = ToOfstream( filename );
  ofs << to_string( t );

  if( insert_endl ){

    ofs << endl;

  }

  return;

}
