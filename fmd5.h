#ifndef FMD5_H
#define FMD5_H

#include <stdint.h>

void md5_compress(uint32_t state[4], const uint8_t block[64]);

#endif /* FMD5_H */
