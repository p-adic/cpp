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

// ios::out 上書き
// ios::in 読み取り専用
// ios::app 末尾に書き込み
// ios::trunc 上書き（outと同じ）
ofstream& ToOfstream( const string& filename , const ios_base::openmode& open_mode = ios::app );

inline void DeleteContents( const string& filename );

// iso::appで末尾に書き込みする。
// 上書きしたい時はDeleteContentsと併用する。
template <typename T>
void WriteIn( const string& filename , const T& t , const bool& insert_endl = true );
