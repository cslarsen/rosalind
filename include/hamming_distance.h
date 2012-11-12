#ifndef INC_HAMMING_H
#define INC_HAMMING_H

#include <string>
#include <algorithm>
#include <ctype.h>

/*
 * Returns Hamming distance between s1 and s2.
 *
 * The strings should have equal length (this function
 * simply ignores extraneous characters).
 */
size_t hamming_distance(const std::string& s1,
                        const std::string& s2)
{
  size_t r = 0;

  for ( size_t n=0, l=std::min(s1.size(), s2.size());
        n < l; ++n )
  {
    if ( toupper(s1[n]) != toupper(s2[n]) )
      ++r;
  }

  return r;
}

#endif
