#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

struct fasta {
  string name, data;
};

int main()
{
  vector<fasta> v;

  // ugly, UGLY reader loop
  while ( !cin.eof() ) {
    char c;
    cin.get(c);
    if ( c == '>' ) {
NEXT:
      fasta f;
      cin >> f.name;
      while ( cin.get(c) && c!='>' )
        if ( isprint(c) ) f.data += c;
      v.push_back(f);
      if ( c == '>' )
        goto NEXT;
    }
  }

  // find overlap graph O_k where k=3
  size_t k = 3;

  for ( auto i : v )
  for ( auto j : v ) {
    if ( i.data == j.data )
      continue;

    string suffix = i.data.substr(i.data.length()-k,k);
    string prefix = j.data.substr(0,k);

    if ( suffix == prefix )
      cout << i.name << " " << j.name << endl;
  }
}
