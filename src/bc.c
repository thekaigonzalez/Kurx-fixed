/* bootchooser */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <lua5.1/lauxlib.h>
#include <lua5.1/lua.h>
#include <lua5.1/lualib.h>

#define PROGNAME "bc"

#define error(_err)                                                           \
  printf ("%s:(%d): %s\n", __FILE__, __LINE__, _err);                         \
  exit (-1)

main ()
{
  struct stat s;

  lua_State *L = luaL_newstate ();
  luaL_openlibs (L);

  if (stat ("usr/init.lua", &s) == -1)
    {
      // printf("%s: note: no init.lua\n", PROGNAME);
      if (luaL_dofile (L, "setup.lua"))
        {
          error (lua_tostring (L, -1));
        }
    } else {
      if (luaL_dofile (L, "usr/init.lua"))
        {
          error (lua_tostring (L, -1));
        }
    }
}
