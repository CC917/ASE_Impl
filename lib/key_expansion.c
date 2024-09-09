#include <stddef.h>
#include <stdint.h>

#include "helper.h"

#define NR_128_128  10
#define NK  4
#define NR  4

static uint32_t rcon[1 + NR_128_128] = {0xff, 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};

static inline uint32_t
rotWord(uint32_t input)
{
    uint8_t *itr = (uint8_t *)&input;
    uint8_t tmp = itr[0];
    itr[0] = itr[1];
    itr[1] = itr[2];
    itr[2] = itr[3];
    itr[3] = tmp;
    return input;
}

static inline uint32_t
SubWord(uint32_t input)
{
    uint8_t *itr = (uint8_t *)&input;
    int i = 0;
    while (i < 4) {
        uint8_t tmp = itr[i];
        uint8_t high = (tmp & 0xf0) >> 4;
        uint8_t low = tmp & 0x0f;
        itr[i++] = sBox[high * 16 + low];
    }
    return input;
}

void
keyExpansion(uint32_t *key, size_t keySize, uint32_t *expantionRes, size_t resSize)
{
    if (keySize != NK || resSize != (NR_128_128 + 1) * NK) {
        return;
    }

    int i = 0;
    while (i < NK) {
        expantionRes[i] = key[i];
        i++;
    }

    // i equal to NK(4)
    while (i < (NR_128_128 + 1) * NK) {
        uint32_t temp = expantionRes[i - 1];
        if (i % NK == 0) {
            temp = SubWord(rotWord(temp)) ^ rcon[i / NK];
        }
        expantionRes[i] = expantionRes[i - NK] ^ temp;
        i++;
    }
}
