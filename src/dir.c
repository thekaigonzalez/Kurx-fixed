#include "dir.h"

// create a dir2d
struct dir2d
ldir (const char *n)
{
  struct dir2d d;

  d.name = n;
  d.dir = opendir (n);

  return d;
}

void
d2dexpand (struct dir2d _d)
{
  struct dirent *de;
  while ((de = readdir (_d.dir)) != NULL)
    {
      if (de->d_name[0]
          == '.') /* ensure there's no `.` directories being listed*/
        continue;
      printf ("%s\n", de->d_name); // TODO: change this to an object
    }
}

void
d2dclose (struct dir2d _d)
{
  closedir (_d.dir);
}
