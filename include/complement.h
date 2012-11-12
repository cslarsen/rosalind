#include <string>
#include <ctype.h>

/*
 * Returns the complement of the DNA-string
 * (A becomes T, T becomse A, and same for C and G).
 */
std::string complement(string s)
{
  char map[256];
  map['A'] = 'T';
  map['T'] = 'A';
  map['C'] = 'G';
  map['G'] = 'C';

  for ( int i=0, l=s.size(); i<l; ++i )
    s[i] = map[toupper(s[i])];

  return s;
}
