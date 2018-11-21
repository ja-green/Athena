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

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

#include "usage.h"
#include "md5.h"

static const char *hash_string_usage =
  "athena hash-string [options] <string>";

static struct option long_options[] = {
  {"help", no_argument, 	NULL, 	'h' },
};

int cmd_hash_string(int argc, const char **argv) {
  int c, show_hlp;

  while ((c = getopt_long(argc, argv, "h", long_options, NULL)) != -1) {
    switch (c) {
      case 'h':	show_hlp = 1; break;
    }
  }

  if (show_hlp == 1) {
    usage(hash_string_usage);
  }

  if (argv[1] == NULL) {
    die("no input string specified");
  } else {
    size_t len = strlen(argv[1]);
    uint8_t digest[16];

    md5(argv[1], len, digest);

    for (int i = 0; i < 16; i++) {
      printf("%2.2x", digest[i]);
    }

    printf("\n");
  }

  return EXIT_SUCCESS;
}
