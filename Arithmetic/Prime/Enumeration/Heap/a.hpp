// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/Heap/a.hpp

#pragma once

class HeapPrimeEnumeration
{

private:
  int m_val_limit;
  vector<bool> m_is_composite;
  vector<int> m_val;
  int m_length;

public:
  inline HeapPrimeEnumeration( const int& val_limit );

  // 1+nŒÂ–Ú‚Ì‘f”‚ğ•Ô‚·B
  inline const int& operator[]( const int& i ) const;
  inline const int& Get( const int& i ) const;

  // val_limit–¢–‚Ì‘f”‚Ü‚Å‚ÅŠ„‚èØ‚ê‚é‡¬”‚Å‚ ‚é‚©”Û‚©‚ğ”»’è‚·‚éB
  inline bool IsComposite( const int& n ) const;

  // val_limit–¢–‚Ì‘f”‚ÌŒÂ”Pi(val_limit)‚ğ•Ô‚·B
  inline const int& length() const noexcept;

};
