#include <stdio.h>
#include "uuid.h"

static int _uuid_parse_hex_char (char c) {

  if (c >= '0' && c <= '9') {
    return c - '0';
  }

  if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  }

  if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  }

  return -1;

}

static bool _uuid_parse_hex_octed (char *in, uint8_t *out) {

  int hi = _uuid_parse_hex_char(in[0]);
  int lo = _uuid_parse_hex_char(in[1]);

  if (hi < 0 || lo < 0) {
    return false;
  }

  *out = ((hi << 4) & 0xf0) | (lo & 0x0f);
  return true;

}

static bool _uuid_parse_hex_group (int len, char *grouped, uint8_t *out) {

  if (len % 2 != 0) {
    return false;
  }

  int i, o;

  for (i = 0; i < len; i += 2) {
    if (!_uuid_parse_hex_octed(&grouped[i], &out[i / 2])) {
      return false;
    } 
  }

  return true;

}

uuid_ptr_t uuid_parse (char *grouped, uuid_t uuid) {
  
  if (grouped[8]  != '-' || grouped[13] != '-' ||
      grouped[18] != '-' || grouped[23] != '-') {
    return NULL;
  }

  if (!_uuid_parse_hex_group(8, &grouped[0], &uuid[0])) {
    return NULL;
  }
 
  if (!_uuid_parse_hex_group(4, &grouped[9], &uuid[4])) {
    return NULL;
  }
 
  if (!_uuid_parse_hex_group(4, &grouped[14], &uuid[6])) {
    return NULL;
  }
 
  if (!_uuid_parse_hex_group(4, &grouped[19], &uuid[8])) {
    return NULL;
  }
 
  if (!_uuid_parse_hex_group(12, &grouped[24], &uuid[10])) {
    return NULL;
  }
 
  return uuid; 

}

bool uuid_eq (uuid_t a, uuid_t b) {

  return 0[(uint64_t *)a] == 0[(uint64_t *)b] &&
         1[(uint64_t *)a] == 1[(uint64_t *)b];

}

int uuid_snprint (char * buffer, int buf_size, uuid_t uuid) {

  return snprintf(buffer, buf_size, "%02x%02x%02x%02x-"
                                    "%02x%02x-%02x%02x-%02x%02x-"
                                    "%02x%02x%02x%02x%02x%02x",
                                    uuid[0],  uuid[1],  uuid[2],  uuid[3],
                                    uuid[4],  uuid[5],  uuid[6],  uuid[7],
                                    uuid[8],  uuid[9],  uuid[10], uuid[11],
                                    uuid[12], uuid[13], uuid[14], uuid[15]);

}
