#pragma once

#include <stdint.h>
#include <stdio.h>

static inline void
print_word(uint32_t word)
{
    uint8_t *itr = (uint8_t *)&word;
    printf("%02x%02x%02x%02x", itr[0], itr[1], itr[2], itr[3]);
}

void
keyExpansion(uint32_t *key, size_t keySize, uint32_t *expantionRes, size_t resSize);
