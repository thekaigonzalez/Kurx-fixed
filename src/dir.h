// TODO: update for longer paths
#define MAX_PATH 260

#include <dirent.h>
#include <stdio.h>

#ifdef __unix__
#include <unistd.h>
#endif
// definitions for a directory with its name intact

struct dir2d ldir (const char *); /* create a proper directory struct */
void d2dclose (struct dir2d);        /* close dir2d but maintain internal data */
void d2dexpand (struct dir2d);       /* list an entire directory */



struct dir2d
{
  const char *name; //! name of directory (creating a dir2d from scratch could
                    //! lead to segfault)
  DIR *dir;         // the directory pointer
};
