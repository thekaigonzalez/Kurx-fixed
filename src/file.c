#include "file.h"

#include <stdio.h>
#include <stdlib.h>

int
copy (const char *_origin, const char *_dest)
{
  FILE *first;

  char buffer[1000];

  first = fopen (_origin, "rb");

  if (!first)
    {
      printf("[C]: copy(): can not continue because file does not exist!\n");
      return -1;
    }

  fseek (first, 0, SEEK_END);

  long fsize = ftell (first);

  fseek (first, 0, SEEK_SET);

  char *string = malloc (fsize + 1);

  fread (string, fsize, 1, first);

  FILE *next;

  next = fopen (_dest, "wb");

  fwrite (string, fsize, 1, next);

  fclose (first);

  fclose (next);

  return (0);
}