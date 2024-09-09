/* Test case from Appendix A - Key Expansion Examples
    A.1 Expansion of a 128-bit Cipher Key  */

#include "aesapi.h"

#include <stdint.h>
#include <stdio.h>

static uint8_t key[16] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 
                            0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

static uint32_t expansionRes[44];

/* Except result */
/*
2b7e1516 28aed2a6 abf71588 09cf4f3c
a0fafe17 88542cb1 23a33939 2a6c7605
f2c295f2 7a96b943 5935807a 7359f67f
3d80477d 4716fe3e 1e237e44 6d7a883b
ef44a541 a8525b7f b671253b db0bad00
d4d1c6f8 7c839d87 caf2b8bc 11f915bc
6d88a37a 110b3efd dbf98641 ca0093fd
4e54f70e 5f5fc9f3 84a64fb2 4ea6dc4f
ead27321 b58dbad2 312bf560 7f8d292f
ac7766f3 19fadc21 28d12941 575c006e
d014f9a8 c9ee2589 e13f0cc8 b6630ca6
*/

int
main(int argc, char **argv)
{
    uint32_t *key_ptr = (uint32_t *)&key;
    keyExpansion(key_ptr, 4, expansionRes, 44);
    for (unsigned i = 0; i < 44; i++) {
        print_word(expansionRes[i]);
        printf(" ");
        if ((i + 1) % 4 == 0)
            printf("\n");
    }
    return 0;
}
