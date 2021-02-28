// c:/Users/user/Documents/Programming/Utility/FileStream/a.cpp

#include "../Header.hpp"
#include "a_Body.hpp"

void FileHolder::LoadFile( const string& filename , const ios_base::openmode& open_mode )
{

  const SmartPointer<ofstream> p_ofs{ filename , open_mode };

  if( !( *p_ofs ) ){

    ERR_IMPUT( filename );

  }
  
  OfstreamTable().Insert( filename , p_ofs );

  return;

}

ofstream& ToOfstream( const string& filename , const ios_base::openmode& open_mode )
{

  if( ! Object<FileHolder>().Contain( filename ) ){

    Object<FileHolder>().LoadFile( filename , open_mode );

  }

  return Object<FileHolder>()( filename );

}
