#include "tests/greatest.h"

extern SUITE(uuid);

/* Add all the definitions that need to be in the test runner's main file. */
GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN(); /* command-line arguments, initialization. */
  RUN_SUITE(uuid);
  GREATEST_MAIN_END(); /* display results */
}
