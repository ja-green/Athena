#ifndef DIGEST_H 
#define DIGEST_H

/* digest function declarations */
extern int dgst_md5(const char *str);

struct digest {
  const char *name;
  int id;
  int (*fn)(const char *);
};

extern struct digest digests[];

struct digest *get_digest(int id);

int is_digest(int id);

int exec_digest(int id, const char *str);

#endif /* DIGEST_H */
