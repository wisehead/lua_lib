#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

//µ÷uaÖµÄddº¯Ê
int call_lua_add(lua_State *L)
{
    lua_getglobal(L, "add"); //»ñddº¯Ê
    lua_pushnumber(L, 123); //µÚ»¸ö÷ë
    lua_pushnumber(L, 456); //µڶþ¸ö÷ë
    lua_pcall(L, 2, 1, 0); //µ÷¯Ê£¬2¸öý·µ»Øµ
    int sum = (int)lua_tonumber(L, -1); //»ñ»¶¥ԪË£¨½á£©
    lua_pop(L, 1); //ջ¶¥ԪË³ö    return sum;
}

int main()
{
    lua_State *L = luaL_newstate(); //Ð½¨lua½âÆ
    luaL_openlibs(L); //ÔÈluaËÓº¯Ê¿â   luaL_dofile(L, "Test.lua"); //ִÐ"Test.lua"Î¼þÖµĴú   printf("%d\n", call_lua_add(L));
    lua_close(L); //Ê·Å    return 0;
}
