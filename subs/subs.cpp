#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;

  size_t i = -1;

  while ( (i = s.find(t, i+1)) != string::npos )
    cout << i+1 << " ";

  cout << endl;
}
