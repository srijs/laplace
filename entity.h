#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"
#include "atom.h"

typedef struct entity {

  OBJECT_FIELDS;

  struct atom *refs; // array of references to atoms

} entity_t;

#endif
