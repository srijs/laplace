#ifndef ENTITY_H
#define ENTITY_H

#include "uuid.h"
#include "atom.h"

struct entity {

  uuid_t uuid;       // this is the primary identifier

  struct atom *refs; // array of references to atoms

};

#endif
