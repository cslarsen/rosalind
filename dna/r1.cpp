#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin >> s;

  int count[4] = {0,0,0,0};

  for ( size_t i=0, l=s.size(); i<l; ++i )
    switch ( toupper(s[i]) ) {
    case 'A': ++count[0]; break;
    case 'C': ++count[1]; break;
    case 'G': ++count[2]; break;
    case 'T': ++count[3]; break;
    default:
      break;
    }

  cout << count[0] << " ";
  cout << count[1] << " ";
  cout << count[2] << " ";
  cout << count[3] << endl;
}
