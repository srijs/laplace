#include "greatest.h"

#include "../uuid.h"

TEST parse_fails_for_wrong_delimiter () {
  uuid_t uuid;
  ASSERT_FALSE(uuid_parse("550e8400-e29b-11d4-a716=446655440000", uuid));
  PASS();
}

SUITE (uuid) {
  RUN_TEST(parse_fails_for_wrong_delimiter);
}
