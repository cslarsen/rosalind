#include <string>
#include "freq.h"

/*
 * Return GC-content in percent.
 */
double gc_content(const std::string& s)
{
  if ( s.empty() )
    return 0;

  auto f = freq(s);
  size_t sum = f['A'] + f['G'] + f['C'] + f['T'];
  return 100.0*static_cast<double>(f['G'] + f['C'])
    / sum;
}

