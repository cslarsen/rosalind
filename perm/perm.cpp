#include <iostream>
#include <algorithm>

using namespace std;

static size_t fact(size_t n)
{
  size_t r = 1;
  while ( n ) r *= n--;
  return r;
}

int main()
{
  size_t n = 0;
  cin >> n;

  cout << fact(n) << endl;;
  int v[] = {1,2,3,4,5,6,7,8,9};

  do {
    for ( size_t i=0; i<n; ++i )
      cout << v[i] << (i+1<n? " " : "");
    cout << endl;
  } while ( next_permutation(v, v+n) );

  return 0;
}
