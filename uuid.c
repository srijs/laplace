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

static int _uuid_parse_hex_octed (char h, char l) {

  int hi = _uuid_parse_hex_char(h);
  int li = _uuid_parse_hex_char(l);

  if (hi < 0 || li < 0) {
    return -1;
  }

  return ((hi << 4) & 0xf0) | (li & 0x0f);

}

static bool _uuid_parse_hex_group (int len, char *grouped, uint8_t *out) {

  if (len % 2 != 0) {
    return false;
  }

  int i, o;

  for (i = 0; i < len; i += 2) {
    o = _uuid_parse_hex_octed(grouped[i], grouped[i + 1]);
    if (o < 0) {
      return false;
    } else {
      out[i / 2] = o;
    } 
  }

  return true;

}

bool uuid_parse (char *grouped, uuid_t uuid) {
  
  if (grouped[8]  != '-' || grouped[13] != '-' ||
      grouped[18] != '-' || grouped[23] != '-') {
    return false;
  }

  if (!_uuid_parse_hex_group(8, &grouped[0], &uuid[0])) {
    return false;
  }
 
  if (!_uuid_parse_hex_group(4, &grouped[9], &uuid[4])) {
    return false;
  }
 
  if (!_uuid_parse_hex_group(4, &grouped[14], &uuid[6])) {
    return false;
  }
 
  if (!_uuid_parse_hex_group(4, &grouped[19], &uuid[8])) {
    return false;
  }
 
  if (!_uuid_parse_hex_group(12, &grouped[24], &uuid[10])) {
    return false;
  }
 
  return true; 

}

int uuid_snprintf (char *restrict buffer, int buf_size, uuid_t uuid) {

  return snprintf(buffer, buf_size, "%02x%02x%02x%02x-"
                                    "%02x%02x-%02x%02x-%02x%02x-"
                                    "%02x%02x%02x%02x%02x%02x",
                                    uuid[0],  uuid[1],  uuid[2],  uuid[3],
                                    uuid[4],  uuid[5],  uuid[6],  uuid[7],
                                    uuid[8],  uuid[9],  uuid[10], uuid[11],
                                    uuid[12], uuid[13], uuid[14], uuid[15]);

}
