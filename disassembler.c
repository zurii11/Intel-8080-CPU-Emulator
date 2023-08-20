#include "stdio.h"
#include "stdlib.h"

int disassemble8080(FILE *fp, unsigned char *buffer, int pc)
{
  unsigned char *code = &buffer[pc];

  int opbytes = 1;
  printf("opbytes: %i\n", opbytes);

  switch (*code) {
    //cases
    case 0x00:
      fputs("NOP\n", fp); 
      break;
    case 0x01:
      fputs("LXI B,D16\n", fp);
      break;
    case 0x02:
      fputs("STAX B\n", fp);
      break;

    default:
      fputs("Unknown instruction\n", fp);
      return -1;
  }

  printf("\n");

  return opbytes;
}

int main (int argc, char *argv[])
{
  FILE *f = fopen(argv[1], "rb"); // open a file in a binary filestream
  FILE *fp = fopen("output.txt", "w+");
  if(f==NULL) {
    printf("Couldn't open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  fseek(f, 0L, SEEK_END); // put the file iposition indicator at the end of the filestream
  int fsize = ftell(f);   // gets the file position indicator of the filestream, 
                          // which is at the end of it, so it's a size of a filestream too
  fseek(f, 0L, SEEK_SET); // return the file position indicator at the start of the filestream

  unsigned char *buffer = malloc(fsize); // allocate memory of size 'fsize' to load filestream into

  fread(buffer, fsize, 1, f);
  fclose(f);

  int pc = 0;
  int retInt = 0;

  while(pc < fsize) {
    
    retInt = disassemble8080(fp,buffer, pc);
    if(retInt < 0) {
      printf("Unknown instruction\n");
      exit(1);
    } else {
      pc += retInt;
    }
  }

  return 0;
}
