#include <stdio.h>
#include <errno.h>
#include <fcntl.h>

int journal_open_write (const char *filepath) {
  return open(filepath, O_WRONLY | O_CREAT | O_APPEND | O_SYNC, S_IRUSR | S_IWUSR);
}

int journal_open_read (const char *filepath) {
  return open(filepath, O_RDONLY);
}

int main (int argc, char **argv) {

  int fd = journal_open_write("./journal");

  if (fd == -1) {
    printf("An error occured. Shutting down...");
    return errno;
  }

  return 0;

}
