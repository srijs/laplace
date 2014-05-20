#ifndef OBJECT_H
#define OBJECT_H

#include "uuid.h"

enum object_type {
  TYPE_ENTITY,
  TYPE_ATOM
};

#define OBJECT_FIELDS struct { \
  enum object_type type;       \
  uuid_t uuid;                 \
}

typedef struct object {
  OBJECT_FIELDS;
} object_t;

#endif
