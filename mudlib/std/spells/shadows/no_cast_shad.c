// glen

#include <security.h>
#include <colors.h>
inherit "/std/spells/shadows/shadow";

string mesg;
int mod, mod2;
object who_shadowed;

int start_shadow(object ob, int duration, string expire_msg) {
    seteuid(UID_SHADOW);
    begin_shadow(ob);
    seteuid(getuid());
    mesg = expire_msg;
    if(!mesg) mesg = "A spell just expired.";
    who_shadowed = ob;
    if(duration)
	call_out("remove",duration,this_object());
    return 1;
}

int query_no_cast(){return 1;}

void remove() {
    message("info", mesg, who_shadowed);
    if(!::remove()) return;
    return;
}


