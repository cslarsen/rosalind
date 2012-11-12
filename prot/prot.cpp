#include <iostream>
#include <string>
#include "protein_string.h"

using namespace std;

int main()
{
  string rna;
  cin >> rna;
  cout << protein_string(rna) << endl;
}
