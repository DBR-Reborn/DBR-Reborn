
#include <security.h>

inherit "/std/spells/shadows/shadow";

object who_shadowed;
string e_message;
int retval;

int query_xp_mod() { return 1;}

void set_return_val(int x){ retval = x; }

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
      call_out("expire_shad", dur, this_object());
    return 1;
}

mixed query_property(string what) {
  if(what != "xp mod") 
      return next_shadow()->query_property(what);
  return retval;
}

void expire_shad(object me) {
  if(me != this_object()) {
    next_shadow()->expire_shad(me);
    return;
  }
  message("info", e_message, who_shadowed);
  remove();
  return;
}


