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
  int cmd_argc;
  char cmd_argv[argc];


 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <string.h>

#include "command.h"

int main(int argc, const char **argv) {
  const char *cmd; 

  if (argc == 1) {
    cmd = "help";

  } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    cmd = "help";
    argv++;
    argc--;

  } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
    cmd = "version";
    argv++;
    argc--;

  } else if (argv[1][0] == '-') {
    cmd = "help";

  } else {
    cmd = argv[1];
    argv++;
    argc--;
  }

  argv[0] = cmd;

  if (is_builtin(cmd) == 0) {
    printf("its a builtin!\n"); 
    exit(EXIT_SUCCESS); 

  } else {
    printf("its not a builtin!\n"); 
    exit(EXIT_FAILURE); 
  }
}
