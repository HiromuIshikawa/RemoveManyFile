#include <stdio.h>
#include <string.h>

void rm_muda(const char *name) {
  char cmd[strlen(name)+7];
  printf("rm %s...", name);
  sprintf(cmd, "rm -rf %s", name);
  system(cmd);
  printf("complete\n");
}

int main(int argc, char **argv) {
  FILE *fp;
  char path[1000];
  if ((fp = fopen(argv[1],"r")) == NULL) {
    fprintf(stderr,"cannot open FILE: %s", argv[1]);
    exit(1);
  }

  while((fgets(path, 1000, fp)) != NULL) {
    rm_muda(path);
  }

  return 0;
}
