/*******************************************************************************
 *      file name: functest.c                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/03/29-12:20:28                              
 *  modified time: 2019/03/29-12:20:28                              
 *******************************************************************************/
#include <stdio.h>
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

lua_State* L = NULL;

// 内部调用lua函数
double f(double x, double y)
{
    double z;
    lua_getglobal(L, "f");    // 获取lua函数f
    lua_pushnumber(L, x);    // 压入参数x和y
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
    L = lua_open();
    luaL_openlibs(L);

    if(luaL_loadfile(L, "/Users/chenhui13/github/lua_lib/22.C_call_lua/functest.lua") || lua_pcall(L, 0, 0, 0))
        error(L, "cannot run configuration file: %s", lua_tostring(L, -1));
    printf("%f\n", f(1.0, 2.0));

    return 0;
}
