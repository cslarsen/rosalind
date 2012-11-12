#ifndef INC_FREQ_H
#define INC_FREQ_H

#include <string>
#include <map>

/*
 * Case-insensitive character frequency count.
 */
std::map<char, int> freq(const std::string& s)
{
  std::map<char, int> r;

  for ( size_t i=0, l=s.size(); i<l; ++i ) {
    char c = toupper(s[i]);

    if ( r.find(c) == r.end() )
      r[c] = 0;

    ++r[c];
  }

  return r;
}

#endif
