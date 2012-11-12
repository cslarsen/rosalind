#include <iostream>
#include <string>
#include <iomanip>
#include "freq.h"
#include "fasta.h"
#include "gc.h"

using namespace std;

int main()
{
  fasta best;

  while ( !cin.eof() ) {
    fasta f;
    cin >> f;
    if ( !f.empty() ) {
      double gc = gc_content(f.data);
      if ( gc > gc_content(best.data) )
        best = f;
    }
  }

  double gc = gc_content(best.data);
  size_t prec = gc>=100.0? 9 : 8;

  cout << best.name << endl;
  cout << setprecision(prec) << gc << "%" << endl;
}
