#ifndef MD5_H
#define MD5_H
 
#include <stdint.h>
#include <stdlib.h>

void dgst_md5(const uint8_t *initial_msg, size_t initial_len, uint8_t *digest);

#endif /* MD5_H */
