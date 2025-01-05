#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string e_message;
int light;

void create() {
	seteuid(getuid());
	return;
}

int start_shadow(object ob, int dur, string mesg) {
    if(!objectp(ob)) return 0;
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    who_shadowed = ob;
    e_message = mesg;
    if(dur)
      call_out("expire_peace", dur, this_object());
    return 1;
}

mixed query_property(string what) {
  if(what != "no attack") 
      return next_shadow()->query_property(what);
  return 1;
}

void expire_peace(object me) {
  if(me != this_object()) {
    next_shadow()->expire_lite(me);
    return;
  }
  message("info", e_message, who_shadowed);
  remove();
  return;
}


