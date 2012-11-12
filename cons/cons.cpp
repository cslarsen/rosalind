#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Returns length of shortest string.
 */
static size_t minlen(const std::vector<std::string>& v)
{
  size_t minlen = -1;

  for ( auto s : v )
    if ( s.length() < minlen )
      minlen = s.length();

  return minlen;
}

typedef std::unordered_map<char, std::vector<size_t>> profile_matrix_t;

profile_matrix_t profile_matrix(const std::vector<std::string>& v)
{
  profile_matrix_t r;

  size_t mlen = minlen(v);

  for ( size_t i=0; i<mlen; ++i ) {
    r['A'].push_back(0);
    r['C'].push_back(0);
    r['G'].push_back(0);
    r['T'].push_back(0);

    for ( auto s : v ) {
      switch ( toupper(s[i]) ) {
      case 'A': ++r['A'][i]; break;
      case 'C': ++r['C'][i]; break;
      case 'G': ++r['G'][i]; break;
      case 'T': ++r['T'][i]; break;
      }
    }
  }

  return r;
}

/*
 * Returns the consensus string of the given DNA sequences.
 *
 * The length of the returned string will be the length of the SHORTEST
 * input string.
 *
 */
std::string consensus_string(profile_matrix_t& m)
{
  std::string r;

  const size_t len = m['A'].size();

  for ( size_t i=0; i<len; ++i ) {
    size_t A = m['A'][i],
           T = m['T'][i],
           C = m['C'][i],
           G = m['G'][i];

    /*
     * There are many possibilities; we'll just choose the one with
     * lexicographically lowest value.
     */
    if ( A>=T && A>=C && A>=G ) r += 'A';
    else if ( T>=A && T>=C && T>=G ) r += 'T';
    else if ( C>=A && C>=T && C>=G ) r += 'C';
    else r += 'G';
  }

  return r;
}

std::ostream& operator<<(std::ostream& o, profile_matrix_t& m)
{
  for ( auto ch : {'A', 'C', 'G', 'T'} ) {
    o << ch << ": ";

    for ( size_t count : m[ch] )
      o << count << " ";

    o << endl;
  }

  return o;
}

int main()
{
  vector<string> v;
  string s;

  while ( cin >> s )
    v.push_back(s);

  profile_matrix_t m = profile_matrix(v);
  cout << consensus_string(m) << endl;
  cout << m << endl;
}
