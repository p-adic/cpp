// c:/Users/user/Documents/Programming/Utility/FileStream/a.hpp

#pragma once
#include "../../Mathematics/SetTheory/Singleton/a.hpp"
#include "../List/LabeledList/a.hpp"
#include "../SmartPointer/a.hpp"
#include <fstream>

class FileHolder :
  public SingletonType<FileHolder>
{

  friend SingletonType<FileHolder>;

private:
  FileHolder() = default;
  FileHolder( const FileHolder& ) = default;
  ~FileHolder() = default;
  FileHolder& operator=( const FileHolder& ) = default;

public:
  void LoadFile( const string& filename , const ios_base::openmode& open_mode = ios::app );
  inline ofstream& operator()( const string& filename ) const;
  inline bool Contain( const string& filename ) const;

private:
  static inline LabeledList<SmartPointer<ofstream>,string>& OfstreamTable();

};

ofstream& ToOfstream( const string& filename , const ios_base::openmode& open_mode = ios::app );

inline void DeleteContents( const string& filename );
template <typename T> inline void WriteIn( const string& filename , const T& t );
