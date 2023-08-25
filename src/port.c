#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>
#include <lua5.1/lualib.h>

#include "http.h"
#include "file.h"
#include "dir.h"

int savesite(lua_State* L) {
  save(luaL_checkstring(L, 1), luaL_checkstring(L, 2));
  return(1);
}

int _copy(lua_State *L) {
  copy(luaL_checkstring(L, 1), luaL_checkstring(L, 2));
  return(1);
}

int luaopen_port(lua_State* L) {
  lua_register(L, "save", savesite);
  lua_register(L, "copy", _copy);
  return (1);
}
