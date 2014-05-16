#ifndef ATOM_H
#define ATOM_H

#include "uuid.h"

struct atom {

  uuid_t uuid; // this is the primary identifier

  unsigned int refcount; // entity reference count

  unsigned int hash_len;  // length of hash data
  char        *hash;      // arbitrary data can be stored here
  struct atom *hash_next; // next atom in the hash table

};

#endif
