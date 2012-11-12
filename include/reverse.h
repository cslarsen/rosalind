#include <string>

/*
 * Returns reversed string.
 */
std::string reverse(const std::string& s)
{
  return std::string(s.rbegin(), s.rend());
}
