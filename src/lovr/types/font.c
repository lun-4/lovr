#include "lovr/types/font.h"

const luaL_Reg lovrFont[] = {
  { "getWidth", l_lovrFontGetWidth },
  { "getHeight", l_lovrFontGetHeight },
  { "getAscent", l_lovrFontGetAscent },
  { "getDescent", l_lovrFontGetDescent },
  { "getBaseline", l_lovrFontGetBaseline },
  { "getLineHeight", l_lovrFontGetLineHeight },
  { "setLineHeight", l_lovrFontSetLineHeight },
  { NULL, NULL }
};

int l_lovrFontGetWidth(lua_State* L) {
  Font* font = luax_checktype(L, 1, Font);
  const char* str = luaL_checkstring(L, 2);
  lua_pushinteger(L, lovrFontGetWidth(font, str));
  return 1;
}

int l_lovrFontGetHeight(lua_State* L) {
  Font* font = luax_checktype(L, 1, Font);
  lua_pushinteger(L, lovrFontGetHeight(font));
  return 1;
}

int l_lovrFontGetAscent(lua_State* L) {
  Font* font = luax_checktype(L, 1, Font);
  lua_pushinteger(L, lovrFontGetAscent(font));
  return 1;
}

int l_lovrFontGetDescent(lua_State* L) {
  Font* font = luax_checktype(L, 1, Font);
  lua_pushinteger(L, lovrFontGetDescent(font));
  return 1;
}

int l_lovrFontGetBaseline(lua_State* L) {
  Font* font = luax_checktype(L, 1, Font);
  lua_pushinteger(L, lovrFontGetBaseline(font));
  return 1;
}

int l_lovrFontGetLineHeight(lua_State* L) {
  Font* font = luax_checktype(L, 1, Font);
  lua_pushinteger(L, lovrFontGetLineHeight(font));
  return 1;
}

int l_lovrFontSetLineHeight(lua_State* L) {
  Font* font = luax_checktype(L, 1, Font);
  float lineHeight = luaL_checknumber(L, 2);
  lovrFontSetLineHeight(font, lineHeight);
  return 0;
}
