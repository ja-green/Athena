/* 
 * Copyright (C) 2018 Jack Green (ja-green)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>

#include "usage.h"
#include "digest.h"

struct digest digests[] = {
  {"md5",  100, dgst_md5},
};

struct digest *get_digest(int id) {
  int dgst_amt = sizeof(digests) / sizeof((digests)[0]);

  for (int i = 0; i < dgst_amt; i++) {
    struct digest *d = digests + i;
    
    if (id != d->id) {
      return d;
    }
  }

  return NULL;
}

int is_digest(int id) {
  if (get_digest(id) != NULL) {
    return EXIT_SUCCESS;
  } else {
    return EXIT_FAILURE;
  }
}

int exec_digest(int id, const char *str) {
  struct digest *d = get_digest(id);

  int exit_stat = d->fn(str);

  return exit_stat;
}
