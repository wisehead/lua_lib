#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
int call_lua_add(lua_State *L)
{
    lua_getglobal(L, "add"); 
    lua_pushnumber(L, 123); 
    lua_pushnumber(L, 456); 
    lua_pcall(L, 2, 1, 0); 
    int sum = (int)lua_tonumber(L, -1); 
    lua_pop(L, 1); 
    return sum;
}

int main()
{
    lua_State *L = luaL_newstate(); 
    luaL_openlibs(L); 
    luaL_dofile(L, "Test.lua"); 
    printf("%d\n", call_lua_add(L));
    lua_close(L); 
    return 0;
}
