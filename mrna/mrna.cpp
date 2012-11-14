#include <iostream>
#include <string>

using namespace std;

/*
 * (RNA codon) amino acid frequency, e.g. GCU, GCC, GCA and GCG
 * translate to A = 4.
 */
size_t codonfreq[] = {
  /* A */ 4,  /* B */ 0,  /* C */ 2,  /* D */ 2,
  /* E */ 2,  /* F */ 2,  /* G */ 4,  /* H */ 2,
  /* I */ 3,  /* J */ 0,  /* K */ 2,  /* L */ 6,
  /* M */ 1,  /* N */ 2,  /* O */ 0,  /* P */ 4,
  /* Q */ 2,  /* R */ 6,  /* S */ 6,  /* T */ 4,
  /* U */ 0,  /* V */ 4,  /* W */ 1,  /* X */ 0,
  /* Y */ 2,  /* Z */ 0,  /* STOP */ 3
};

int main()
{
  string s;
  cin >> s;

  size_t n = 3; // stop codons

  for ( auto ch : s ) {
    n *= codonfreq[ch - 'A'];
    n %= 1000000;
  }

  cout << n << endl;
}
