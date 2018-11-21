#ifndef USAGE_H
#define USAGE_H

void error(const char *err, ...);
void die(const char *err, ...);
void warn(const char *err, ...);

void usage(const char *text, ...);

#endif /* USAGE_H */
