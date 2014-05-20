#include "greatest.h"

#include "../uuid.h"

TEST parse_fails_for_wrong_delimiter () {
  uuid_t uuid;
  ASSERT_FALSE(uuid_parse("550e8400-e29b-11d4-a716=446655440000", uuid));
  PASS();
}

TEST parse_fails_for_wrong_hex () {
  uuid_t uuid;
  ASSERT_FALSE(uuid_parse("550e8400-e29b-11d4-a716-44665544hh00", uuid));
  PASS();
}

TEST parse_works_correctly () {
  uuid_t uuid, bytes = (uuid_t){
    0x55,0x0e,0x84,0x00,0xe2,0x9b,0x11,0xd4,0xa7,0x16,0x44,0x66,0x55,0x44,0x00,0x00
  };
  ASSERT(NULL != uuid_parse("550e8400-e29b-11d4-a716-446655440000", uuid));
  ASSERT(0 == memcmp(uuid, bytes, 5));
  PASS();
}

TEST eq_returns_true_for_equal_uuids () {
  uuid_t a, b;
  ASSERT(uuid_eq(uuid_parse("550e8400-e29b-11d4-a716-446655440000", a),
                 uuid_parse("550e8400-e29b-11d4-a716-446655440000", b)));
  PASS();
}

TEST eq_returns_false_for_unequal_uuids () {
  uuid_t a, b;
  ASSERT_FALSE(uuid_eq(uuid_parse("550e8400-e29b-11d4-a716-446655440000", a),
                       uuid_parse("550e8400-e29b-11d4-a716-446655430000", b)));
  PASS();
}

TEST eq_returns_false_for_null_uuids () {
  ASSERT_FALSE(uuid_eq(NULL, NULL));
  PASS();
}

TEST snprint_works_correctly () {
  char str[37] = "550e8400-e29b-11d4-a716-446655440000";
  uuid_t uuid;
  uuid_parse(str, uuid);
  char buf[37];
  uuid_snprint(buf, 37, uuid);
  ASSERT(0 == strcmp(str, buf));
  PASS();
}

SUITE (uuid) {
  RUN_TEST(parse_fails_for_wrong_delimiter);
  RUN_TEST(parse_fails_for_wrong_hex);
  RUN_TEST(parse_works_correctly);
  RUN_TEST(eq_returns_true_for_equal_uuids);
  RUN_TEST(eq_returns_false_for_unequal_uuids);
  RUN_TEST(eq_returns_false_for_null_uuids);
  RUN_TEST(snprint_works_correctly);
}
