#include <iostream>
#include <string>

using namespace std;

string reverse(const string& s)
{
  return string(s.rbegin(), s.rend());
}

string complement(string s)
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

int main()
{
  string s;
  cin >> s;
  cout << reverse(complement(s)) << endl;
}
