#ifndef COMMAND_H 
#define COMMAND_H

/* builtin declarations */
extern int cmd_help(int argc, const char **argv);
extern int cmd_version(int argc, const char **argv);

struct builtin {
	const char *cmd;
  int (*fn)(int, const char **);
};

extern struct builtin builtins[]; 

int is_builtin(const char *c);

#endif /* COMMAND_H */
