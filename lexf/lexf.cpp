#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<char> v;

  // read alphabet
  char c;
  while ( cin.get(c) ) {
    if ( c == '\n' || c == '\r' ) break;
    if ( c != ' ' ) v.push_back(c);
  }

  // read length
  size_t len;
  cin >> len;

  // indices into v
  vector<size_t> w(len);

  for (;;) {
    // print permutation
    for ( auto i : w )
      cout << v[i];
    cout << endl;

    // next permutation (reverse-order)
    size_t carry = 1;
    for ( int i=len-1; i>=0; --i ) {
      w[i] += carry;

      if ( w[i] >= v.size() ) {
        w[i] = 0;
        carry = 1;
      } else {
        carry = 0;
        break;
      }
    }

    if ( carry == 1 )
      break;
  }
}
