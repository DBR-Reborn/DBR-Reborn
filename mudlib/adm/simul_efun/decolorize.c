/*
 * New decolorize function. Hopefully a bit more efficient...
 *
 * Stavros@SWMud
 * 8 May 2010
 */

#include <daemons.h>

string decolorize(string str) {
  string *colors, *parts, *ret;
  if (!str || strsrch(str,"%^") == -1)
    return str;
  colors = keys(TERMINAL_D->query_term_info("unknown"));
  parts = explode(str,"%^");
  ret = filter_array(parts,"match_not_color",this_object(),colors);
  return implode(ret,"");
}

int match_not_color(string str, string *colors) {
  return (member_array(str,colors)==-1);
}

