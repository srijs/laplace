#include "atom.h"

atom_t atom_new (uuid_t uuid) {
  atom_t a = (atom_t){.type = TYPE_ATOM};
  uuid_copy(a.uuid, uuid);
  return a;
}
