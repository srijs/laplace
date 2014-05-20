#ifndef UUID_H
#define UUID_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t uuid_t[16];
typedef uint8_t *uuid_ptr_t;

uuid_ptr_t uuid_parse (char *grouped, uuid_t uuid);

bool uuid_eq (uuid_t a, uuid_t b);

int uuid_snprint (char *buffer, int buf_size, uuid_t uuid);

#endif
