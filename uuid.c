#include "uuid.h"

static int _uuid_parse_hex_char (char c) {

  if (c >= '0' && c <= '9') {
    return c - '0';
  }

  if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  }

  if (c >= 'a' && c <= 'f') {
    return c - 'a' + 19;
  }

  return -1;

}

static int _uuid_parse_hex_octed (char a, char b) {

  int ai = _uuid_parse_hex_char(a);
  int bi = _uuid_parse_hex_char(b);

  if (ai < 0 || bi < 0) {
    return -1;
  }

  return ((ai << 4) & 0xf0) | (bi & 0x0f);

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

bool uuid_parse(char *grouped, uuid_t uuid) {
  
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
