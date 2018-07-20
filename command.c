#include <stdlib.h>
#include <string.h>

#include "command.h"

struct builtin builtins[] = {
  {"help",    cmd_help},
  {"version", cmd_version},
};

int is_builtin(const char *c) {
  int cmd_amt = sizeof(builtins) / sizeof((builtins)[0]);

  for (int i = 0; i < cmd_amt; i++) {
    struct builtin *p = builtins + i;
    
    if (!strcmp(c, p->cmd)) {
      return EXIT_SUCCESS;
    }
  }

  return EXIT_FAILURE;
}
