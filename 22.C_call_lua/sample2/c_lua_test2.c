#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

lua_State *L = NULL;

double f(double x, double y)
{
    double z;
    lua_getglobal(L, "f");    
    lua_pushnumber(L, x);    
    lua_pushnumber(L, y);

    if(lua_pcall(L, 2, 1, 0) != 0)
        error(L, "error running function 'f': %s", lua_tostring(L, -1));

    if(!lua_isnumber(L, -1))
        error(L, "function 'f' must return a number");
    z = lua_tonumber(L, -1);
    lua_pop(L, 1);
    return z;
}

int main(void)
{
    //L = lua_open();
    L = luaL_newstate();
    luaL_openlibs(L);

    if(luaL_loadfile(L, "/home/mysql/mycode/lua/sample2/functest.lua") || lua_pcall(L, 0, 0, 0))
        error(L, "cannot run configuration file: %s", lua_tostring(L, -1));
    printf("%f\n", f(1.0, 2.0));

    return 0;
}
