#ifndef INC_PROTEIN_STRING_H
#define INC_PROTEIN_STRING_H

#include <iostream>
#include <string>
#include "u8_rna.h"

static char lookup[256];
static bool lookup_built = false;
static char STOP = '\n';

/*
 * Build RNA codon table using 6 bits for each RNA-triplet.
 */
static void build_lookup()
{
  lookup[u8_rna("UUC ")] = 'F';
  lookup[u8_rna("UUA ")] = 'L';
  lookup[u8_rna("UUU ")] = 'F';
  lookup[u8_rna("CUU ")] = 'L';
  lookup[u8_rna("AUU ")] = 'I';
  lookup[u8_rna("GUU ")] = 'V';
  lookup[u8_rna("UUC ")] = 'F';
  lookup[u8_rna("CUC ")] = 'L';
  lookup[u8_rna("AUC ")] = 'I';
  lookup[u8_rna("GUC ")] = 'V';
  lookup[u8_rna("UUA ")] = 'L';
  lookup[u8_rna("CUA ")] = 'L';
  lookup[u8_rna("AUA ")] = 'I';
  lookup[u8_rna("GUA ")] = 'V';
  lookup[u8_rna("UUG ")] = 'L';
  lookup[u8_rna("CUG ")] = 'L';
  lookup[u8_rna("AUG ")] = 'M';
  lookup[u8_rna("GUG ")] = 'V';
  lookup[u8_rna("UCU ")] = 'S';
  lookup[u8_rna("CCU ")] = 'P';
  lookup[u8_rna("ACU ")] = 'T';
  lookup[u8_rna("GCU ")] = 'A';
  lookup[u8_rna("UCC ")] = 'S';
  lookup[u8_rna("CCC ")] = 'P';
  lookup[u8_rna("ACC ")] = 'T';
  lookup[u8_rna("GCC ")] = 'A';
  lookup[u8_rna("UCA ")] = 'S';
  lookup[u8_rna("CCA ")] = 'P';
  lookup[u8_rna("ACA ")] = 'T';
  lookup[u8_rna("GCA ")] = 'A';
  lookup[u8_rna("UCG ")] = 'S';
  lookup[u8_rna("CCG ")] = 'P';
  lookup[u8_rna("ACG ")] = 'T';
  lookup[u8_rna("GCG ")] = 'A';
  lookup[u8_rna("UAU ")] = 'Y';
  lookup[u8_rna("CAU ")] = 'H';
  lookup[u8_rna("AAU ")] = 'N';
  lookup[u8_rna("GAU ")] = 'D';
  lookup[u8_rna("UAC ")] = 'Y';
  lookup[u8_rna("CAC ")] = 'H';
  lookup[u8_rna("AAC ")] = 'N';
  lookup[u8_rna("GAC ")] = 'D';
  lookup[u8_rna("UAA ")] = STOP;
  lookup[u8_rna("CAA ")] = 'Q';
  lookup[u8_rna("AAA ")] = 'K';
  lookup[u8_rna("GAA ")] = 'E';
  lookup[u8_rna("UAG ")] = STOP;
  lookup[u8_rna("CAG ")] = 'Q';
  lookup[u8_rna("AAG ")] = 'K';
  lookup[u8_rna("GAG ")] = 'E';
  lookup[u8_rna("UGU ")] = 'C';
  lookup[u8_rna("CGU ")] = 'R';
  lookup[u8_rna("AGU ")] = 'S';
  lookup[u8_rna("GGU ")] = 'G';
  lookup[u8_rna("UGC ")] = 'C';
  lookup[u8_rna("CGC ")] = 'R';
  lookup[u8_rna("AGC ")] = 'S';
  lookup[u8_rna("GGC ")] = 'G';
  lookup[u8_rna("UGA ")] = STOP;
  lookup[u8_rna("CGA ")] = 'R';
  lookup[u8_rna("AGA ")] = 'R';
  lookup[u8_rna("GGA ")] = 'G';
  lookup[u8_rna("UGG ")] = 'W';
  lookup[u8_rna("CGG ")] = 'R';
  lookup[u8_rna("AGG ")] = 'R';
  lookup[u8_rna("GGG ")] = 'G';

  lookup_built = true;
}

/*
 * Convert given RNA string to protein string, using the RNA codon table
 * below.
 *
 * UUU F      CUU L      AUU I      GUU V
 * UUC F      CUC L      AUC I      GUC V
 * UUA L      CUA L      AUA I      GUA V
 * UUG L      CUG L      AUG M      GUG V
 * UCU S      CCU P      ACU T      GCU A
 * UCC S      CCC P      ACC T      GCC A
 * UCA S      CCA P      ACA T      GCA A
 * UCG S      CCG P      ACG T      GCG A
 * UAU Y      CAU H      AAU N      GAU D
 * UAC Y      CAC H      AAC N      GAC D
 * UAA Stop   CAA Q      AAA K      GAA E
 * UAG Stop   CAG Q      AAG K      GAG E
 * UGU C      CGU R      AGU S      GGU G
 * UGC C      CGC R      AGC S      GGC G
 * UGA Stop   CGA R      AGA R      GGA G
 * UGG W      CGG R      AGG R      GGG G
 *
 */
std::string protein_string(std::string rna)
{
  std::string r;
  build_lookup();

  while ( rna.size() >= 3 ) {
    r += lookup[u8_rna(rna.substr(0,3))];
    rna.erase(0,3);
  }

  if ( !rna.empty() )
    r += lookup[u8_rna(rna.substr(0,rna.size()).c_str())];

  return r;
}

#endif
