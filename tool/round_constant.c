/// This program will generate round constant array defined in 
/// 5.2 Key Expansion

#include <stdint.h>
#include <stdio.h>

#define GENERATE_NUM 15

static uint32_t rcon[GENERATE_NUM];

int
main(void) {
    rcon[0] = 0xffffffff;
    rcon[1] = 1;
    for (unsigned i = 2; i < GENERATE_NUM; i++) {
        rcon[i] = rcon[i-1] << 1;
        if (rcon[i] > 0xff) {
            rcon[i] ^= 0x11B;
        }
    }
    printf("{");
    for (unsigned i = 1; i < GENERATE_NUM; i++) {
        printf("0x%x", rcon[i]);
        if (i != GENERATE_NUM - 1) {
            printf(", ");
        }
    }
    printf("};\n");
    return 0;
}
