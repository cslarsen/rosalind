#include <iostream>
#include <string>

using namespace std;

/*
 * Amino acid frequency in RNA codon table.
 *
 * E.g., GCU, GCC, GCA and GCG gives A = 4.
 *
 * Range is from 'A' to 'Z'
 */
size_t codon_freq[] = {
  4, 0, 2, 2, 2, 2, 4, 2, 3, 0, 2, 6, 1,
  2, 0, 4, 2, 6, 6, 4, 0, 4, 1, 0, 2, 0
};

int main()
{
  string s;
  cin >> s;

  // Initialize with the three stop codons
  size_t n = 3;

  for ( auto c : s ) {
    n *= codon_freq[c - 'A'];
    n %= 1000000;
  }

  cout << n << endl;
}
