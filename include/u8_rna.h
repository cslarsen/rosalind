#ifndef INC_RNA_TO_BYTE
#define INC_RNA_TO_BYTE

#include <string>
#include <inttypes.h>
#include <ctype.h>

uint8_t single_rna_to_byte(const char RNA)
{
  /*
   * NOTE: This mapping is completely arbitrary, I don't know if there is
   * any official bitmapping for RNA (?).
   */
  switch ( toupper(RNA) ) {
  case 'A': return 0x00;
  case 'C': return 0x01;
  case 'G': return 0x02;
  case 'U': return 0x03;
  default: return 0; // error
  }
}

/*
 * Convert up to 4 RNA characters to 8-bit representation (string must be 4
 * bytes, though, so encapsulate with spaces).
 */
uint8_t u8_rna(const std::string& RNA)
{
  uint8_t r = 0;

  switch ( RNA.size() ) {
  case 4:        r |= single_rna_to_byte(RNA[3]);
  case 3: r <<= 2; r |= single_rna_to_byte(RNA[2]);
  case 2: r <<= 2; r |= single_rna_to_byte(RNA[1]);
  case 1: r <<= 2; r |= single_rna_to_byte(RNA[0]);
  default: break;
  }

  return r;
}

#endif
