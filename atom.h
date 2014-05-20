#ifndef ATOM_H
#define ATOM_H

#include "object.h"

typedef struct atom {

  OBJECT_FIELDS;

  unsigned int refcount; // entity reference count

  unsigned int hash_len;  // length of hash data
  char        *hash;      // arbitrary data can be stored here

} atom_t;

atom_t atom_new (uuid_t uuid);

#endif
