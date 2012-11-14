#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<string> all_substrings(const string& s)
{
  vector<string> v;

  for ( size_t i=0; i<s.size(); ++i )
    for ( size_t j=1; j<=(s.size()-i); ++j )
      v.push_back(s.substr(i,j));

  return v;
}

int main()
{
  vector<string> v;

  // Read from stdin
  string s;
  while ( cin >> s )
    v.push_back(s);

  /*
   * Warning: Super-slow brute-force
   */
  string best;
  for ( auto t : all_substrings(v[0]) ) {
    for ( auto u : v )
      if ( u.find(t) == string::npos )
        goto NEXT_T;

    if ( t.length() > best.length() )
      best = t;

NEXT_T:
    continue;
  }

  cout << best << endl;
}
