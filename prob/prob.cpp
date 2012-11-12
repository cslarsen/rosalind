#include <iostream>

using namespace std;

/*
 * Given a DNA-string with the specified GC-content, return the probability
 * that two randomly chosen symbols are the same.
 */
static double P(double gc)
{
  const double CG = gc/2.0;
  const double AT = (1.0-gc)/2.0;
  return 2.0 * (CG*CG + AT*AT);
}

int main()
{
  double gc;

  while ( !cin.eof() ) {
    cin >> gc;
    cout << P(gc) << " ";
  }

  cout << endl;
}
