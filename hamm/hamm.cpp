#include <iostream>
#include <string>
#include "hamming_distance.h"

using namespace std;

int main()
{
  string s1, s2;
  cin >> s1 >> s2;
  cout << hamming_distance(s1, s2) << endl;
}
