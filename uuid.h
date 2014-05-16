#ifndef UUID_H
#define UUID_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t uuid_t[16];

bool uuid_parse (char *grouped, uuid_t uuid);

int uuid_snprintf (char *restrict buffer, int buf_size, uuid_t uuid);

#endif
